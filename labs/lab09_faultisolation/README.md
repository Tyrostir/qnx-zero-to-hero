---
lab: "09.2"
chapter: 09
title: "Watch a fault stay local"
paths: ["🚶 B", "🏃 C"]
core: false
est_time: "20 minutes"
status: "[UNVERIFIED] — written and syntax-checked; not yet built with qcc or run on the target"
---

# Lab 09.2 — Watch a fault stay local

> **Objective.** Crash a process on purpose, and account for every consequence.
>
> 📖 [Chapter 09 §5.2](../../docs/chapters/Chapter09_MicrokernelArchitecture.md)

> 📌 **`[UNVERIFIED]`** — block **V14**.

---

## What it does

`faulter` prints its PID, flushes, and then writes through a NULL pointer. **It crashes. That is the
point.**

The finding is not the crash — it is what you see afterwards: **nothing else changed.** Same uptime,
same other processes, one fewer line in `pidin`.

---

## Use

```bash
host$ source ~/qnx800/qnxsdp-env.sh
host$ export TGT=$(cd ~/qnx800/images/qemu/qemu && mkqnximage --getip)
host$ make TGT=$TGT deploy
```

Then, in **two** target sessions:

```bash
# session 2 — baseline
qnx$ pidin info
qnx$ pidin | wc -l

# session 1 — crash it
qnx$ /data/faulter

# session 2 — immediately after
qnx$ pidin info
qnx$ pidin | wc -l
qnx$ slog2info | tail -20
```

---

## What to look for

| Observation | Expected |
|-------------|----------|
| Output before the crash | `faulter: pid <n>, about to dereference NULL` |
| Output after | **Nothing.** `never reached` is never reached |
| Process count | Back to baseline — `procnto` freed everything |
| Everything else in `pidin info` | **Unchanged.** *This non-event is the result* |
| `slog2info` | Should record the fault 📋 *unverified — report what you see* |

> 💡 **Why `fflush` is in the source.** `stdout` is block-buffered when redirected, and a process that
> dies with data in its buffer never prints it. Without the flush you would be debugging a program
> that appears to produce **no output at all** — a real trap, not a detail of this example.

---

## Going further

- **Crash it while something is blocked on it.** Chapter 09's 💥 exercise does this with `vncserv`,
  and it is the more interesting half: what does the *client* see? (§5.4)
- **Look for a core dump.** `dumper` is in `slm`'s component list, so it is running. Where does it
  write? 📋 The course does not know — see block V14.
- **Try it under `gdb`** (Chapter 08). A debugger catches the `SIGSEGV` *before* the process dies, so
  you can inspect the state that caused it. That is Chapter 25's subject.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-26 | Created for Chapter 09. `[UNVERIFIED]` pending block V14. |
