---
lab: "01.2"
chapter: 01
title: "Measure jitter on your own machine"
paths: ["🚶 B", "🏃 C"]
core: false
est_time: "20 minutes"
status: "[UNVERIFIED] — written and syntax-checked, not yet built with qcc or run on the target"
---

# Lab 01.2 — Measure jitter

> **Objective.** Produce real latency numbers on your own QNX target, and see the gap between the
> mean and the worst case with your own data.
>
> 📖 Chapter: [Chapter 01 — What Is a Real-Time System?](../../docs/chapters/Chapter01_WhatIsARealTimeSystem.md)

> 📌 **`[UNVERIFIED]`.** The source compiles cleanly under `gcc -Wall -Wextra` and the logic is
> straightforward POSIX, but **it has not yet been built with `qcc` or run on the target.** Report
> what you actually get — including build errors. *(ADR-024; verification block V6.)*

---

## What it does

Asks to sleep for exactly **1 ms**, ten thousand times, and measures how long each sleep *actually*
took. The difference between what you asked for and what you got **is** jitter.

Nothing in the program is QNX-specific — it is plain POSIX. That is deliberate: build it for Linux
too and compare the tails.

---

## Files

```text
lab01_timing/
├── README.md            ← you are here
├── Makefile             plain qcc, no magic (ADR-007)
├── skeleton/jitter.c    🚶 four TODOs to fill in
├── solution/jitter.c    🏃 complete, annotated
├── prebuilt/            🐣 (empty — see note below)
└── expected_output.txt  the shape of a correct run
```

> 🐣 **Path A note.** `prebuilt/` is empty because binaries are built by whoever has the toolchain,
> and this course does not ship compiled artefacts it cannot verify. **Chapter 01 gives Path A a
> different activity** that needs no binary at all — five systems to classify and a timing budget to
> compute on paper. See the chapter's *🐣 Path A Activity*.

---

## The library functions this lab uses

> 🐣 **Read this if you have not met these before.** Four functions do all the work, and **none of
> them is QNX-specific** — that is the point. Three come from the **C standard library** and two from
> **POSIX**; the same code compiles on Linux, macOS and QNX.

### Where they come from

| Function | Standard | Header | Since |
|----------|----------|--------|-------|
| `qsort` | **ISO C** (the C language standard itself) | `<stdlib.h>` | C89 |
| `perror` | **ISO C** | `<stdio.h>` | C89 |
| `nanosleep` | **POSIX.1b** (the *real-time extensions*) | `<time.h>` | POSIX 1993 |
| `clock_gettime` | **POSIX.1b** | `<time.h>` | POSIX 1993 |

| | |
|---|---|
| **Are they C++?** | No — they are **C**. C++ inherits the entire C library, so you *can* call them from C++ (spelled `<cstdlib>`, `<cstdio>`, `<ctime>`), but they are not C++ features. |
| **Are they QNX inventions?** | **No.** Not one. This is what "QNX is POSIX-compliant" means in practice: your existing C knowledge transfers unchanged. QNX adds its own calls — `MsgSend`, `ChannelCreate`, `InterruptAttach` — in `<sys/neutrino.h>`, and you will meet those from Chapter 13. |
| **Which two are the real-time ones?** | `nanosleep` and `clock_gettime`. They came from **POSIX.1b**, the 1993 real-time extensions — written for exactly the kind of system this course is about. |

### Where they physically live

| | |
|---|---|
| **Declarations** (what the compiler reads) | `$QNX_TARGET/usr/include/time.h`, `stdio.h`, `stdlib.h` |
| **Code** (what runs) | **`libc.so.6`** on the target — which you have already seen: it is one of the ~80 files in `/proc/boot` |

You can look at both yourself:

```bash
host$ grep -n "nanosleep" $QNX_TARGET/usr/include/time.h
qnx#  ls /proc/boot/libc.so.6
```

> 💡 **`libc.so.6` sitting in `/proc/boot` is worth a moment.** The C library is loaded before any
> disk is mounted, because nothing — not even the shell — can run without it. It sits beside
> `ldqnx-64.so.2`, the dynamic linker that finds it.

---

### `clock_gettime` — what time is it, precisely?

```c
#include <time.h>
int clock_gettime(clockid_t clock_id, struct timespec *tp);
```

| | |
|---|---|
| **Does** | Writes the current value of clock `clock_id` into `*tp`, with nanosecond resolution |
| **`clock_id`** | Which clock to read (see below) |
| **`tp`** | **Output parameter** — you supply a `struct timespec`; the function fills it in |
| **Returns** | `0` on success · `-1` on failure, with `errno` set (`EINVAL` for an unknown clock) |

```c
struct timespec {
    time_t tv_sec;    /* whole seconds                  */
    long   tv_nsec;   /* nanoseconds, 0 .. 999,999,999  */
};
```

⚠️ **Two fields, not one.** This is why the lab's `elapsed_us()` combines both — subtracting `tv_nsec`
alone is wrong the moment an interval crosses a second boundary. That is **TODO 1** in the skeleton,
and it is the mistake almost everyone makes once.

**The clocks you care about:**

| `clock_id` | What it measures | Can it jump? |
|-----------|------------------|--------------|
| `CLOCK_REALTIME` | Wall-clock time — "what a calendar says" | ⚠️ **Yes.** NTP or an administrator can step it forwards *or backwards* |
| **`CLOCK_MONOTONIC`** | Time since an arbitrary fixed point, usually boot | ✅ **No.** Only ever moves forward |
| `CLOCK_PROCESS_CPUTIME_ID` | CPU time consumed by this process | — |
| `CLOCK_THREAD_CPUTIME_ID` | CPU time consumed by this thread | — |

> ⚠️ **Never measure a duration with a clock that can be set.** If NTP steps `CLOCK_REALTIME`
> backwards by 200 ms mid-measurement, your interval comes out negative — and your "worst case"
> analysis quietly acquires nonsense. **`CLOCK_MONOTONIC` exists for exactly this**, and that is why
> the lab uses it.
>
> 💡 The last two rows are a preview of Chapter 01's `R` versus `C` distinction: `CLOCK_MONOTONIC`
> measures **response time** (wall-clock, including preemption), while `CLOCK_THREAD_CPUTIME_ID`
> measures **execution time** (CPU actually used). Deadlines apply to the first.

*(QNX also offers `CLOCK_SOFTTIME`, a QNX-specific clock. You will not need it here; the QNX C Library
Reference documents it.)*

---

### `nanosleep` — sleep for at least this long

```c
#include <time.h>
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
```

| | |
|---|---|
| **Does** | Suspends the calling **thread** for at least the interval in `*rqtp` |
| **`rqtp`** | **R**e**q**uested **t**ime — how long to sleep. `const`, so it is only read |
| **`rmtp`** | **R**e**m**aining **t**ime — if a signal cuts the sleep short, what was left is written here. Pass `NULL` (as the lab does) if you do not care |
| **Returns** | `0` if the full interval elapsed · `-1` with `errno = EINTR` if a signal interrupted it · `-1` with `EINVAL` if `tv_nsec` is outside `0…999999999` |

> ⚠️ **"At least" is a guarantee, and it is the one the lab tests.** `nanosleep` may sleep *longer*
> than you asked — because the clock ticks in discrete steps, and because a higher-priority thread may
> be running when your time is up. It may **never** sleep *less*.
>
> That is why the first sanity check on your output is **`min ≥ 1000 µs`**. A smaller value does not
> mean the sleep was short; it means the measurement is wrong.

> 🐧 **In Linux this would be…** identical. Also compare `sleep()` (whole seconds) and `usleep()`
> (microseconds, and deprecated). `nanosleep` is the one POSIX standardised for real-time work, and
> the only one of the three that reports how much time was left.

---

### `perror` — print why the last call failed

```c
#include <stdio.h>
void perror(const char *s);
```

| | |
|---|---|
| **Does** | Prints `s`, then `": "`, then a human-readable description of the current `errno`, to **stderr** |
| **`s`** | Your prefix — conventionally the name of the call that failed |
| **Returns** | **Nothing.** It is a reporting function, not a test |

```c
if (clock_gettime(CLOCK_MONOTONIC, &before) != 0) {
    perror("clock_gettime");     /* → "clock_gettime: Invalid argument" */
    return 1;
}
```

> 📖 **`errno`** is a per-thread integer that library calls set when they fail. It is only meaningful
> **immediately after** a call that reported failure — a *successful* call may leave any value in it.
> So always test the return value first, then read `errno`. `perror` and `strerror()` turn its number
> into text.

> 🐣 **Why check at all, when it "cannot fail"?** Because "cannot fail" is an assumption, and
> assumptions are what break at 3 a.m. Checking costs three lines and turns a silent wrong answer
> into a clear message.

---

### `qsort` — sort an array of anything

```c
#include <stdlib.h>
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

| | |
|---|---|
| **Does** | Sorts `nmemb` elements of `size` bytes each, starting at `base`, **in place** |
| **`base`** | Pointer to the first element |
| **`nmemb`** | **N**u**mb**er of **m**embers |
| **`size`** | Bytes per element — `sizeof sample[0]` |
| **`compar`** | **A function *you* write**, which qsort calls to compare two elements |
| **Returns** | **Nothing.** The array is modified in place |

The comparator must return a negative number if `a < b`, zero if equal, positive if `a > b`:

```c
static int cmp_long(const void *x, const void *y)
{
    long a = *(const long *)x, b = *(const long *)y;
    return (a > b) - (a < b);      /* -1, 0 or +1, with no overflow */
}
```

> 💡 **Why `(a > b) - (a < b)` and not `a - b`?** The obvious version overflows. If `a` is very
> negative and `b` very positive, `a - b` can wrap around and return the *wrong sign* — and your array
> comes back subtly mis-sorted, with no error anywhere. The comparison form has no arithmetic to
> overflow. This is a classic C trap worth carrying with you.

> ⚠️ **`qsort` is not necessarily quicksort, and its worst case is unspecified by the standard.**
> That makes it exactly the kind of call Chapter 01 §3.2 warns about — **unbounded computation** —
> and it is why the lab sorts **after** the measurement loop rather than inside it.
>
> 💡 **Notice what that means in general.** Nothing is wrong with `qsort`; it is a fine function. What
> matters is *where* you call it. Real-time discipline is less about forbidden functions than about
> keeping unbounded work off the deadline path. Reach for the sorted statistics *after* the stopwatch
> has stopped.

---

### How to look any of this up yourself

| Where | How |
|-------|-----|
| **The header** — always authoritative for your version | `grep -n "nanosleep" $QNX_TARGET/usr/include/time.h` |
| **QNX C Library Reference** | [qnx.com/developers/docs/8.0](https://www.qnx.com/developers/docs/8.0/) → *C Library Reference*, alphabetical |
| **On your host** | `man 3 nanosleep`, `man 2 clock_gettime`. These are the Linux man-pages, but both calls are POSIX, so the description matches — check QNX's own docs for anything version-specific |
| **The POSIX standard itself** | [pubs.opengroup.org/onlinepubs/9699919799](https://pubs.opengroup.org/onlinepubs/9699919799/) — free to read, and the final word on argument and return semantics |

> 💡 **A habit worth forming now.** When you meet an unfamiliar call in this course, read the
> **header** first. It tells you the exact signature *for the version you are compiling against*,
> which no web page can promise.

---

## Build

On the **host** (the SDP environment must be loaded):

```bash
host$ source ~/qnx800/qnxsdp-env.sh          # if $QNX_HOST is empty
host$ cd ~/exercises/qnx-zero-to-hero/labs/lab01_timing
host$ make
```

Builds `solution/jitter`. To build your own attempt instead:

```bash
host$ make skeleton
```

**Confirm it is a QNX binary, not a host one:**

```bash
host$ file solution/jitter
```

Look for `interpreter /usr/lib/ldqnx-64.so.2` — the tell described in
[Setup Guide 02 §11.3](../../docs/guides/Setup_02_QNX_Account_And_License.md).

---

## Run

```bash
host$ scp solution/jitter qnxuser@<ip>:/tmp/
host$ ssh qnxuser@<ip>
qnx$ /tmp/jitter
```

> ⚠️ **`qnxuser`, never `root`** — the target refuses root over SSH ([D-009](../../docs/meta/Doubts.md#d-009)).
> Find the IP with `mkqnximage --getip` from `~/qnx800/images/qemu/qemu`.

Takes about **10 seconds** (10 000 × 1 ms).

---

## Expected output

See [`expected_output.txt`](expected_output.txt). The **shape** matters, not the exact numbers:

- `min` should be **≥ 1000 µs** — `nanosleep` guarantees *at least* the requested time
- `mean` slightly above 1000 µs
- `max` noticeably higher — often 2× or more
- `jitter` = `max − min`

---

## Troubleshooting

| Symptom | Cause and fix |
|---------|---------------|
| `qcc: command not found` | `source ~/qnx800/qnxsdp-env.sh` |
| `cannot execute: required file not found` on the **host** | ✅ Correct — it is a QNX binary. Run it on the target |
| `Permission denied` from `scp` | Use `qnxuser@`, not `root@` ([D-009](../../docs/meta/Doubts.md#d-009)) |
| `min` below 1000 µs | The measurement is wrong, not the sleep. Check `elapsed_us()` handles the `tv_sec` rollover |
| All samples identical | Suspicious — check you are reading the clock *inside* the loop |
| Build fails | **Report it.** The lab is `[UNVERIFIED]`; a build error is a genuine finding |

---

## Going further

- Run it **loaded** — Chapter 01's 💥 *Break It* exercise. Watch `max` move while `mean` barely does.
- Run it at priority: `on -p 63 /tmp/jitter`, and see what fixed-priority scheduling buys you.
- Build the same source for Linux (`gcc -O2 -o jitter_linux solution/jitter.c`) and compare the tails.
- Change `INTERVAL_US` to 10000 (10 ms). Does jitter scale with the interval, or stay roughly constant?
  What does the answer tell you about where it comes from?

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.1 | 2026-08-26 | Added **The library functions this lab uses** — `clock_gettime`, `nanosleep`, `perror`, `qsort`: where each comes from (ISO C vs POSIX.1b, none QNX-specific), header, signature, arguments, return values, and where the code physically lives. Closes the course-rule-#4 gap reported in [D-014](../../docs/meta/Doubts.md#d-014). |
| 1.0 | 2026-08-26 | Created for Chapter 01. `[UNVERIFIED]` pending block V6. |
