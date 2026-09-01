---
lab: "10.1"
chapter: 10
title: "Thread lifecycle and pidin observation"
paths: ["🚶 B", "🏃 C"]
core: false
est_time: "35 minutes"
status: "[UNVERIFIED] — written and syntax-checked; not yet built with qcc or run on the target"
---

# Lab 10.1 — The thread zoo

> **Objective.** Make one process show **five threads in five different blocking states**, then read
> the whole thing out of `pidin`. By the end you will never again confuse a process with a thread.
>
> 📖 [Chapter 10 §3](../../docs/chapters/Chapter10_ProcessesAndThreads.md)

> 📌 **`[UNVERIFIED]`** — block **V15**.

---

## What it does

`threadzoo` creates four threads and then parks every one of them, deliberately, somewhere different:

| Thread | Does | `pidin` should show |
|--------|------|---------------------|
| `main` | `pthread_join` on the sleeper | `JOIN` |
| `sleeper` | `nanosleep(3600)` forever | `NANOSLEEP` |
| `waiter` | `pthread_cond_wait` on a condition nothing signals | `CONDVAR` |
| `holder` | Locks a mutex, then sleeps forever **still holding it** | `NANOSLEEP` |
| `contender` | Tries to lock that same mutex | `MUTEX` |

**One pid. Five tids. One address space.** That listing is the lab.

---

## Use

```bash
host$ source ~/qnx800/qnxsdp-env.sh
host$ export TGT=$(cd ~/qnx800/images/qemu/qemu && mkqnximage --getip)
host$ cd ~/exercises/qnx-zero-to-hero/labs/lab10_threads
host$ make TGT=$TGT run
```

`threadzoo` **does not exit** — that is intentional; it has to stay alive for you to look at it. Open
a **second** target session and run:

```bash
qnx$ pidin -p threadzoo
```

Stop it with `Ctrl-C` in the first session, or `slay threadzoo` from the second.

**Build your own version instead of the reference one:**

```bash
host$ make SRC=skeleton/threadzoo.c TGT=$TGT run
```

---

## The library functions this lab uses

Every one of these is in **libc on QNX 8** — there is no separate `-lpthread` to link, unlike Linux.

| Function | Header | Purpose | Arguments | Returns |
|----------|--------|---------|-----------|---------|
| `pthread_create` | `<pthread.h>` | Start a new thread **in this process** | `&tid`, attributes (`NULL` = defaults), the function to run, one `void *` argument | **`0` on success, an error *number* on failure — it does *not* set `errno`** |
| `pthread_join` | `<pthread.h>` | Block until a thread finishes, and collect its return value | thread id, `void **` for the result (`NULL` to discard) | `0`, or an error number |
| `pthread_detach` | `<pthread.h>` | Say "nobody will join this one" so its resources are freed at exit | thread id | `0`, or an error number |
| `pthread_self` | `<pthread.h>` | The calling thread's own id | none | `pthread_t` |
| `pthread_mutex_lock` / `_unlock` | `<pthread.h>` | Take / release a mutex | `&mutex` | `0`, or an error number |
| `pthread_cond_wait` | `<pthread.h>` | Release a mutex and sleep until signalled, then re-take it | `&cond`, `&mutex` | `0`, or an error number |
| `nanosleep` | `<time.h>` | Sleep for a precise interval | `&requested`, `&remaining` (`NULL` to ignore) | `0`, or `-1` with `errno` |
| `getpid` | `<unistd.h>` | This **process's** id | none | `pid_t` |
| `strerror` | `<string.h>` | Turn an error number into text | the number | `char *` — do not free it |
| `fflush` | `<stdio.h>` | Push buffered output out now | the stream | `0`, or `EOF` |

> ⚠️ **The `pthread_*` return convention catches everyone once.** They return the error **as the
> return value** and leave `errno` alone. So `if (rc != 0) perror(...)` is wrong;
> `strerror(rc)` is right.

---

## Questions

1. How many **pids** does `pidin -p threadzoo` show? How many **tids**?
2. Do the tids `threadzoo` printed match `pidin`'s `tid` column?
3. Which tid does `main`'s `JOIN` name in the `Blocked` column? Which does `contender`'s `MUTEX` name?
4. `arrivals` is incremented by four threads with no lock at all. What did it print, and why is the
   fact that it printed `4` **not** evidence that the code is correct?
5. Run `pidin -p threadzoo mem`. How many address spaces are there?

<details>
<summary>Answers</summary>

1. **One pid, five tids.** That is the whole point: threads are not processes.
2. They should — on QNX a `pthread_t` **is** the thread id, so `pthread_self()` and `pidin`'s `tid`
   are the same number. 📋 **Report if they differ**; the course asserts this and has not run it.
3. Prediction: `JOIN` names **2** (the sleeper), `MUTEX` names **4** (the mutex's owner).
   📋 **This is the claim worth checking.** If `pidin` really names the *owning thread* of a
   contended mutex, you can resolve a real deadlock from one line of output.
4. It almost certainly printed `4` — and it means nothing. `arrivals++` is a read, an add and a write;
   two threads can interleave and lose an update. With four threads a second apart the race
   essentially never fires. **A race that does not fire is still a race** — Chapter 12 fixes it, and
   this is why "it worked when I tested it" is not an argument about concurrency.
5. **One.** Threads share the address space; that is the definition.

</details>

---

## 💥 Break It — `fork()` in a multi-threaded process

```bash
host$ make SRC=solution/forktest.c BIN=forktest TGT=$TGT run
```

`forktest` forks **three** times and reports each outcome:

1. `fork()` while single-threaded — expected to work
2. `fork()` after creating a thread — **the experiment**
3. `posix_spawn()` while multi-threaded — the way QNX wants you to do it

There is **no correct output**. The output *is* the result, and the course does not know it: whether
QNX 8 fails the second `fork()`, succeeds with only the calling thread, or succeeds fully is
`[UNVERIFIED]`. 📋 **Please paste all three.**

> 💡 **Why this is not a trick question.** `fork()` must decide what to do about the *other* threads —
> and every possible answer is bad. Duplicate them, and they are duplicated mid-operation, holding
> mutexes that will never be unlocked. Drop them, and the child wakes up in a process whose invariants
> assumed they existed. POSIX chose "drop them, and now you may call only async-signal-safe
> functions", which is a very small list that does not include `printf` or `malloc`.
> **`posix_spawn()` sidesteps the whole problem** by never duplicating anything.

---

## Troubleshooting

| Symptom | Cause | Fix |
|---------|-------|-----|
| `qcc: not found` | SDP environment not sourced | `source ~/qnx800/qnxsdp-env.sh` |
| `cannot find -lpthread` | You added `-lpthread` | Remove it — on QNX 8 the pthread functions are in libc |
| `Permission denied` on `scp` | Deploying to `/data` | Deploy to `~` ([D-015](../../docs/meta/Doubts.md#d-015)) |
| `pidin -p threadzoo` shows nothing | It already exited, or you are on the wrong session | It should not exit; check the first session for a crash |
| Fewer than five tids | A `pthread_create` failed silently | It cannot — the program checks every one. Paste the output |

---

## Lab 10.3 — measure the default stack

```bash
host$ make SRC=solution/stacksize.c BIN=stacksize TGT=$TGT run
```

Prints the default thread stack size, `PTHREAD_STACK_MIN`, and what 200 threads would cost. Chapter 10
§3.2 says the stack is what a thread costs and then declines to name a figure, because the course does
not know one. 📋 **Report the number.**

---

## Files

```text
lab10_threads/
├── Makefile
├── README.md               ← you are here
├── expected_output.txt     ← [UNVERIFIED] prediction, not a recording
├── skeleton/threadzoo.c    🚶 four TODOs
├── solution/threadzoo.c    🏃 reference
├── solution/forktest.c     💥 the fork experiment
└── solution/stacksize.c    📏 the default stack size
```
