---
lab: "08.1"
chapter: 08
title: "The development loop, with a debugger"
paths: ["🚶 B", "🏃 C"]
core: true
est_time: "40 minutes"
status: "[UNVERIFIED] — written and syntax-checked; not yet built with qcc or run on the target"
---

# Lab 08.1 ⭐ — The development loop

> **Objective.** Build, deploy, run and **debug a target process from a debugger on your host** — then
> find a real bug without editing the source.
>
> ⭐ **Core lab L08.** Every coding path does this one, including 🏃 Path C.
>
> 📖 Chapter: [Chapter 08 — The Toolchain & Deployment](../../docs/chapters/Chapter08_ToolchainAndDeployment.md)

> 📌 **`[UNVERIFIED]`.** The C compiles cleanly under `gcc -Wall -Wextra` and the Makefile's syntax is
> checked, but **nothing here has been built with `qcc` or run on a target.** Report what you actually
> get, including failures. *(ADR-024; verification block V13.)*

---

## Files

```text
lab08_devloop/
├── README.md            ← you are here
├── Makefile             build · deploy · run · debug · release
├── skeleton/avg.c       ⭐ THE BUGGY PROGRAM — the one you debug
├── solution/avg.c       the corrected version — read it afterwards
└── prebuilt/            (empty — see the note below)
```

> ⚠️ **This lab inverts the usual skeleton/solution roles.** Normally `skeleton/` has `TODO`s to fill
> in. Here the exercise is **debugging**, so `skeleton/` holds a *complete, compiling, subtly wrong*
> program and `solution/` holds the fix. **Do not read `solution/` first** — the whole point is to
> find the bug with `gdb`.

> 🐣 **Path A note.** `prebuilt/` is empty because this course does not ship binaries it cannot verify
> ([D-008 rationale, Ch 04 §5.1](../../docs/chapters/Chapter04_LicensingAndQNXEverywhere.md)).
> Chapter 08's 🐣 activity is a **read-a-debugging-session** exercise needing no binary at all.

---

## Setup

```bash
host$ source ~/qnx800/qnxsdp-env.sh
host$ export TGT=$(cd ~/qnx800/images/qemu/qemu && mkqnximage --getip)
host$ ssh qnxuser@$TGT 'echo ok'
```

⚠️ **`qnxuser`, not `root`** — the target refuses root over SSH
([D-009](../../docs/meta/Doubts.md#d-009)).

---

## Use

| Command | Does |
|---------|------|
| `make` | Build the **buggy** program, and check it really is a QNX x86_64 binary |
| `make TGT=$TGT run` | Build → deploy → run on the target |
| `make TGT=$TGT DEST=/tmp run` | Same, but to `/tmp` — writable by anyone, **lost on reboot** |
| `make TGT=$TGT debug` | Build → deploy → launch `gdb` connected to `qconn` |
| `make SRC=solution/avg.c TGT=$TGT run` | The same, with the **fixed** program |
| `make release` | Optimised, stripped build — compare the sizes |
| `make clean` | Remove build output |

> 💡 **`run` depends on `deploy`, which depends on the build.** That chain makes running a **stale
> binary structurally impossible** — the single most common failure in a cross-development loop
> (Chapter 08 §4.3).

---

## The bug

`sum_readings()` loops `for (int i = 0; i <= count; i++)` over a 4-element array. Valid indices are
`0`–`3`; `i == 4` reads **past the end**.

**`-Wall -Wextra` does not catch it**, because the compiler cannot know `count`'s value at the call
site. It is undefined behaviour that *usually* looks fine — which is precisely why it is worth
finding with a debugger rather than by reading.

**Find it like this:**

```bash
host$ make TGT=$TGT debug
(gdb) break sum_readings
(gdb) run
(gdb) info args
(gdb) next          # repeat until i reaches 4
(gdb) print i
(gdb) print count
(gdb) print r[4]    ← the moment
(gdb) print r[3]    ← for comparison
```

`r[3]` is 40. `r[4]` is whatever happened to be in that memory.

---

## Expected output

| Program | Output |
|---------|--------|
| `skeleton/avg.c` *(buggy)* | `sum` and `average` are **unpredictable**. Sometimes 100/25, sometimes not, sometimes a crash. **The variability is the finding** |
| `solution/avg.c` *(fixed)* | `sum = 100`, `average = 25` — every time |

---

## Troubleshooting

| Symptom | Fix |
|---------|-----|
| `qcc: command not found` | `source ~/qnx800/qnxsdp-env.sh` |
| `WARNING: not a QNX x86_64 binary` | Check `-V` and `$QNX_TARGET` (Ch 05 §4.3) |
| `Permission denied` on `scp` | Use `qnxuser@`, not `root@` |
| `scp: dest open "/data/x": Permission denied` | **`/data`'s root is owned by root.** Deploy into your home — the Makefile now defaults to `/data/home/$(USER)` ([D-015](../../docs/meta/Doubts.md#d-015)) |
| `gdb` cannot connect to `:8000` | Is the VM running? `pidin \| grep qconn` on the target |
| Changes have no effect | You deployed by hand. Use `make run` |
| `gdb` names functions that are not running | **Symbol mismatch** — rebuild *and* redeploy together (Ch 08 💥) |

---

## Going further

- **Attach to a running process:** start `gdb` **with the binary**, then `info pidlist` and
  `attach <pid>`. ⚠️ `attach` alone fails with `…: No such file or directory` — `gdb` reads symbols on
  the *host* and needs a local copy. Your own program: `ntox86_64-gdb avg`. A target utility:
  `ntox86_64-gdb $QNX_TARGET/x86_64/usr/bin/sleep`. See D-016.
- ⚠️ **`target qnx <ip>` without `:8000` hangs** rather than erroring. Always give the port.
  in `gdb`. `gdbserver` cannot do this; `qconn` can.
- **Compare `make` and `make release`** sizes. That difference is why Chapter 05's `.sym` files exist.
- **Build the same source with `-O2 -g`** and try stepping through it. Expect `<optimized out>` — and
  now you know why the course says *debug with `-O0`*.
- **Break the target flag** on purpose (`-Vgcc_ntoaarch64le`) and see whether the Makefile's `file`
  check catches it. 📋 If it does not, that is a genuine finding — report it.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-26 | Created for Chapter 08's core lab L08. `[UNVERIFIED]` pending block V13. |
