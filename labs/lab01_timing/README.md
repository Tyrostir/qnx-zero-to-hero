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
| 1.0 | 2026-08-26 | Created for Chapter 01. `[UNVERIFIED]` pending block V6. |
