---
chapter: 07
title: "First Contact — The QNX Shell"
part: "Part 1 — Getting Your Environment"
paths: ["🐣 A", "🚶 B", "🏃 C"]
est_time: "75 minutes reading · 40 minutes labs"
prereqs: "Chapter 06. A booting VM."
status: Published
version: 1.1
created: 2026-08-26
last_updated: 2026-08-26
sdp_version: "QNX SDP 8.0"
target_verified_on: "QNX 8.0.0, kernel build 2026/02/27-11:02:56EST, x86_64 under QEMU/KVM"
---

# Chapter 07 — First Contact: The QNX Shell

> **By the end of this chapter you will** be able to work inside a QNX system with intent rather than
> by analogy — reading `pidin` fluently, navigating a filesystem that is not quite Unix, and
> understanding why *everything* here is a path.

---

## 🏃 Fast-Track Summary

> **🏃 Path C reads only this box**, then goes to
> [Chapter 08](Chapter08_ToolchainAndDeployment.md) — your next `⭐ core` lab.

**The shell is `ksh`** — the Korn shell, not `bash`. POSIX-compatible, so your muscle memory works;
`bash` also exists on this image (`/etc/passwd` gives `qnxuser` `/bin/bash`).

**`pidin` is the command that matters.** QNX's `ps`, but it lists **threads** with their **blocking
state** — the column `ps` has no equivalent for.

| `pidin` invocation | Shows |
|--------------------|-------|
| `pidin` | Every thread: pid, tid, name, priority, **STATE**, Blocked |
| `pidin info` | Version, uptime, free memory, CPU count |
| `pidin -p <name>` | One process |
| `pidin mem` | Memory per process |
| `pidin fds` | Open file descriptors — **which server each is connected to** |
| `pidin arg` · `pidin env` | Command lines · environments |

**Read the `prio` column as `<number><policy>`:** `f` FIFO, `r` round-robin. Range **0–255**;
`0f` is idle, `254i`/`255i` are the kernel's interrupt threads.

**The states you must recognise:**

| State | Means |
|-------|-------|
| `RUNNING` · `READY` | On a CPU · runnable, waiting for one |
| **`RECEIVE`** | Blocked waiting for a **message**. Normal for an idle server |
| **`REPLY`** | Blocked waiting for a **reply** — `Blocked` names the **PID** it waits on |
| `SIGWAITINFO` · `NANOSLEEP` · `CONDVAR` · `SEM` · `MUTEX` | Waiting for a signal · sleeping · condvar · semaphore · mutex |
| `INTR` | Waiting for an interrupt |
| `DEAD` | Terminated, not yet reaped |

**The filesystem is POSIX with two QNX additions:** **`/proc/boot`** is `ifs.bin` mounted (Ch 06), and
**`/dev`** entries are **processes that registered a path**, not device nodes.

**Everything is a path.** A service claims a name; clients `open()` it; `read()`/`write()` become
messages. That is why adding a driver on QNX means adding a *process*, not a kernel module (Ch 16–17).

**Useful QNX-specific commands:** `pidin` · `slay` · `on -p N cmd` (run at a priority) · `slog2info`
(the system log) · `use cmd` (QNX's built-in help) · `hogs` (top CPU consumers).

**🏃 Skip to:** [Chapter 08](Chapter08_ToolchainAndDeployment.md). §3.2 on reading blocking states
is the half-page that pays off most in Chapters 13 and 25.

---

## 🎯 Learning Objectives

By the end of this chapter you will be able to:

- [ ] **Read** a `pidin` listing fluently — priority, policy, state and blocking partner.
- [ ] **Diagnose** a stuck system from blocking states alone.
- [ ] **Navigate** the QNX filesystem and say which parts came from the image and which from disk.
- [ ] **Explain** what a `/dev` entry actually is on QNX.
- [ ] **Use** `slog2info`, `hogs`, `on` and `use` without looking them up.
- [ ] **Find** which server a process is talking to, and what it has open.
- [ ] **Recognise** where QNX's shell environment differs from Linux, and adapt.

---

## 🧭 Prerequisites

| Need | Why |
|------|-----|
| [Chapter 06](Chapter06_FirstQNXVMOnQEMU.md) ⭐ | The boot chain, `/proc/boot`, and what persists |
| A booting VM | Every lab here runs on the target |
| Basic shell familiarity | `cd`, `ls`, pipes. Not QNX-specific |

---

## 🗺️ Mental model

A QNX system, seen from the shell, is **a set of processes connected by messages, addressed by
paths**.

```mermaid
flowchart LR
    YOU["👤 you<br/>at the shell"] -->|"open(\"/dev/ser1\")"| PS["🗂️ pathname space<br/><i>maintained by procnto</i>"]
    PS -->|"who owns<br/>this path?"| DRV["🔧 devc-ser8250<br/><i>an ordinary process</i>"]
    YOU -.->|"then read()/write()<br/>= <b>messages</b>"| DRV
    PID["🔍 pidin"] -.->|"shows every thread's<br/><b>blocking state</b>"| DRV
    style PS fill:#e1f5ff,stroke:#0277bd
    style DRV fill:#c8e6c9,stroke:#2e7d32
```

*Diagram: opening a path asks the kernel's pathname space which process owns it; subsequent reads and
writes are messages to that process, and `pidin` shows the resulting blocking states.*

> 💡 **Two ordinary-looking commands hide the whole architecture.** `ls /dev` looks like Linux. But
> those entries are **running processes that claimed a name**, and `pidin` is how you see the
> conversation between them. Chapter 16 formalises this; this chapter has you *watch* it.

---

## 1. The Problem

### 1.1 Familiarity is a trap here

You log in and everything looks like Unix. `ls`, `cd`, `cat`, `grep`, pipes — all present, all
behaving. POSIX compliance means your existing skills transfer, and that is genuinely most of the
value.

**The trap is that the resemblance stops at exactly the point where QNX gets interesting.** Three
things look familiar and are not:

| Looks like | Actually is |
|-----------|-------------|
| `/dev/ser1` — a device node | A **process** that registered that path |
| `ps`-style output from `pidin` | A **thread** listing, with blocking states `ps` cannot show |
| `/proc/boot` — a proc filesystem | A **20 MB file**, mounted (Ch 06) |

### 1.2 The skill this chapter is really teaching

When a QNX system misbehaves, the question is almost never *"which process is using the CPU?"* — the
tools for that are the same as anywhere. It is:

> **"What is everything waiting for, and is anyone waiting on someone who will never answer?"**

That question is answered by one column of `pidin` output. Learning to read it now — while the system
is healthy and you can compare against a known-good state — is far easier than learning it at 2 a.m.
against a wedged target.

> 💡 **Chapter 25 is the debugging chapter, and its core lab (`⭐ L25`) is "diagnose a hung system with
> `pidin`".** Everything here is preparation for that.

---

## 2. The Concept — the shell, and what is around it

### 2.1 `ksh`, and what you get

QNX's default shell is **`ksh`**, the Korn shell. It is POSIX-compliant, so the constructs you know
work: pipes, redirection, `for`/`while`, `$(...)`, globbing, job control.

Your image also has **`bash`** — `/etc/passwd` gives both `root` and `qnxuser` `/bin/bash`
([D-011](../meta/Doubts.md#d-011)).

| | |
|---|---|
| **What transfers** | Essentially all everyday shell usage |
| **What may not** | `bash`-only syntax if you land in `ksh` — arrays, `[[ ]]` extensions, `${var,,}` |
| **What is missing** | Much of the GNU userland's convenience. QNX ships **`toybox`** (in `/proc/boot`), a compact multi-call binary providing many standard tools |

> 🐧 **In Linux this would be…** the same shell experience with a fuller toolbox. `toybox` implements
> the commonly used subset, so `ls`, `grep`, `sed` and friends exist — sometimes with fewer options
> than the GNU versions. If a familiar flag is rejected, that is usually why, not a QNX quirk.

> 💡 **`use` is the QNX help command**, and it is better than it sounds:
>
> ```bash
> qnx# use pidin
> ```
>
> QNX binaries embed their own usage message, which `use` extracts. It works offline, on the target,
> for the exact build you are running — which is more than can be said for a web search.

### 2.2 The filesystem

From the verified system:

```text
bin   data  etc   lib  proc  sbin  system  usr  x86_64
boot  dev   home  opt  root  sys   tmp     var
```

| Path | What it is | From |
|------|-----------|------|
| `/proc/boot` | ⭐ **`ifs.bin`, mounted** — ~80 files | The image, in RAM |
| `/dev` | **Processes that registered paths** | Live services |
| `/proc` | Process and system information | `procnto` |
| **`/data`** | ⭐ **The writable, persistent partition** — but its root is root-owned; write to `/data/home/<you>` ([D-015](../meta/Doubts.md#d-015)) | The data partition |
| `/tmp` | Scratch | RAM |
| `/bin`, `/usr`, `/lib`, `/sbin` | The familiar POSIX layout | The disk |
| `/system` | QNX system files | The disk |
| `/x86_64` | Architecture-specific tree — mirrors `$QNX_TARGET/x86_64` | The disk |
| `/etc` | Configuration ⚠️ **may not survive a reboot** (Ch 06 §3.3) | The disk |

> 💡 **`/x86_64` is the one that surprises people.** It mirrors the layout you browsed on the *host*
> in Chapter 05 (`$QNX_TARGET/x86_64/`). The same organising idea — architecture-tagged trees — appears
> on both sides of the cross-development boundary.

### 2.3 `/dev` is not what you think

```bash
qnx# ls /dev
```

On Linux, `/dev` entries are **device nodes**: filesystem objects carrying a major/minor number that
the kernel maps to a driver *inside itself*.

On QNX they are **names in a pathname space**, claimed by **processes**.

| | 🐧 Linux | 🔷 QNX |
|---|---|---|
| `/dev/ser1` is | A node with major/minor numbers | A **path a process registered** |
| The driver is | Kernel code | **A process with a PID** |
| `open("/dev/ser1")` | Enters the kernel, dispatches by number | **Asks `procnto` who owns that path**, then connects you to that process |
| `read()` afterwards | A kernel call | **A message to that process** |
| To replace the driver | Rebuild or reload a module | **`slay` it and start another** |

> 💡 **This is Chapter 02's microkernel argument, arrived at from the shell.** You can *see* the
> correspondence: for every interesting entry in `/dev` there is a process in `pidin`. `devc-ser8250`
> owns the serial paths; `io-sock` owns the networking ones. **The filesystem is a directory of
> running services**, which is what "everything is a path" actually means (Chapter 16).

### 📦 Analogy — the telephone directory

> ☎️ **The pathname space is a telephone directory**, and `procnto` is the operator.
>
> `open("/dev/ser1")` is looking up a name and asking the operator to connect you. The operator does
> not *handle your call* — they know **who** does, and they put you through. After that you are
> talking directly to `devc-ser8250`.
>
> **`pidin` is being able to see every call in progress**, and — this is the part with no telephone
> equivalent — **who is waiting for whom to speak.** That is the `REPLY` state, and it is how you find
> the one participant who has stopped answering.

---

## 3. The Mechanism — reading a live system

### 3.1 `pidin`, properly

```bash
qnx# pidin
```

```text
     pid tid name                         prio STATE          Blocked
       1   1 /proc/boot/procnto-smp-instr   0f RUNNING
       1  11 /proc/boot/procnto-smp-instr 255i INTR
   32773   1 proc/boot/devb-eide           10r SIGWAITINFO
   32773   3 proc/boot/devb-eide          254i INTR
   81931   1 system/bin/io-sock            21r SIGWAITINFO
  249881  13 system/bin/screen             10r REPLY          184343
  397328   1 system/bin/fullscreen-winmgr  10r REPLY          249881
```

| Column | Meaning |
|--------|---------|
| `pid` | Process ID. **Large and non-sequential** — they are IPC endpoints ([D-013](../meta/Doubts.md#d-013)) |
| `tid` | **Thread** ID within that process. QNX schedules threads |
| `name` | The executable |
| `prio` | Priority **0–255**, plus a policy letter: `f` FIFO, `r` round-robin |
| **`STATE`** | ⭐ **What the thread is doing — or waiting for** |
| `Blocked` | Who or what it is waiting on |

### 3.2 The blocking states — the half-page that matters ⭐

> 📖 **Blocking state.** The precise reason a thread is not running. QNX distinguishes many, and the
> distinction is the diagnostic.

| State | The thread is… | Normal? |
|-------|----------------|---------|
| `RUNNING` | On a CPU now | ✅ |
| `READY` | Runnable, waiting for a CPU | ✅ |
| **`RECEIVE`** | **Waiting for a message.** An idle server. `Blocked` = channel id | ✅ **Very** |
| **`REPLY`** | **Waiting for a reply.** `Blocked` = **the PID it is waiting on** | ✅ briefly · ⚠️ **if stuck** |
| `SEND` | Waiting for the server to receive its message | ⚠️ if persistent |
| `SIGWAITINFO` | Waiting for a signal | ✅ |
| `NANOSLEEP` | Sleeping for a fixed time | ✅ |
| `CONDVAR` · `SEM` · `MUTEX` | On a condition variable · semaphore · mutex | ✅ · ⚠️ if stuck |
| `INTR` | Waiting for an interrupt | ✅ — drivers do this |
| `DEAD` | Terminated, not yet reaped | ✅ transiently |

> 💡 **`RECEIVE` is what a healthy QNX system mostly looks like.** Servers block waiting for work and
> consume **no CPU at all**. A listing full of `RECEIVE` is not a stalled system — it is an idle,
> correctly-written one.

**The diagnostic pattern, and it is genuinely this simple:**

```text
397328  fullscreen-winmgr  REPLY  249881   ← waiting on 249881
249881  screen             REPLY  184343   ← which waits on 184343
184343  io-hid             RECEIVE         ← which is idle, waiting for input
```

**Follow the chain.** Each `REPLY` names a PID; look that PID up; repeat. You either reach a thread
doing real work — fine, the system is busy — or you reach one that is stuck, and **that** is your
culprit.

> ⚠️ **The pathology to look for is a cycle.** If A waits on B and B waits on A, nothing will ever
> move. That is deadlock, and `pidin` shows it directly rather than requiring you to infer it. On
> Linux the equivalent investigation involves kernel stacks and considerably more effort.
>
> 💡 **This chain was already in your Chapter 00 output**, on a system nobody had instrumented. You
> have been looking at live message passing since your first lab.

### 3.3 The other `pidin` views

| Command | Shows | Use it when |
|---------|-------|-------------|
| `pidin info` | Version, uptime, free memory, CPUs | Orientation |
| `pidin -p <name>` | One process only | Focus |
| `pidin mem` | Memory per process | Suspecting a leak |
| **`pidin fds`** | Open file descriptors, **and which server each connects to** | *"What is this process talking to?"* |
| `pidin arg` | Full command lines | *"How was this started?"* |
| `pidin env` | Environments | Configuration problems |
| `pidin times` | CPU time per thread | *"What is burning CPU?"* |

> 💡 **`pidin fds` is the underrated one.** On QNX an open file descriptor is a **connection to a
> process**, so `fds` shows you the system's communication graph — who is connected to whom. There is
> no single Linux command that gives you quite that.

### 3.4 Beyond `pidin`

| Command | Does | Notes |
|---------|------|-------|
| **`slog2info`** | Read the **system log** | QNX's structured, low-overhead logger. Chapter 24 |
| **`hogs`** | Top CPU consumers | Roughly `top`, sampled |
| **`on -p N cmd`** | Run `cmd` at priority `N` | Chapter 01's break-it used this |
| **`slay name`** | Terminate by name | Chapter 02's Lab 02.2 |
| `use cmd` | Built-in usage for any QNX command | ⭐ Works offline, for your exact build |
| `shutdown` | Shut the target down cleanly | |

> 💡 **`slog2info` is where the boot messages went.** The four benign warnings from Chapter 06 were
> emitted before the logger started; everything after `slm` starts `slog2` is captured properly, with
> severity and timestamps. Chapter 24 covers the logging system; for now, know that
> **`slog2info` is the first command to run when something misbehaved and you missed the console.**

### 🔬 Deep dive — why `/proc` is small, and where the information lives

<details>
<summary>Optional. Interesting if you are used to Linux's enormous `/proc`.</summary>

Linux's `/proc` is vast: `/proc/cpuinfo`, `/proc/meminfo`, `/proc/<pid>/status`, `/proc/sys/...` — a
sprawling text-file API to the kernel, grown organically over decades.

QNX's is comparatively spare, and the reason is architectural: **most of what Linux exposes through
`/proc` is not in the QNX kernel to expose.** Network statistics belong to `io-sock`, a process. Disk
information belongs to `devb-eide`. There is no single kernel to interrogate, so there is no single
place to interrogate it.

Instead:

| Want | Ask |
|------|-----|
| Processes and threads | `pidin` (which reads `/proc`) |
| System summary | `pidin info` |
| Network | `ifconfig`, `netstat` — served by `io-sock` |
| The boot image contents | `ls /proc/boot` |
| The log | `slog2info` |

> 💡 **This is the microkernel showing through the diagnostics.** A monolithic kernel can offer one
> comprehensive introspection interface because it *is* one program. A microkernel's state is
> distributed across the processes that own it, so its tooling is too. That is a genuine cost — there
> is no single `cat` that tells you everything — and the compensation is that each owner can be
> queried, restarted, or replaced independently.

</details>


---

## 4. The Command Reference

> Chapters that teach an API use §4 for signatures. Here it is the working set — the commands you will
> use daily from now on.

### 4.1 `pidin`

| Invocation | Shows |
|------------|-------|
| `pidin` | All threads: pid, tid, name, prio, **STATE**, Blocked |
| `pidin info` | Version, uptime, free memory, CPU count |
| `pidin -p <name>` | One process |
| `pidin mem` | Memory per process |
| `pidin fds` | Open descriptors and **which server each connects to** |
| `pidin arg` · `pidin env` | Command lines · environments |
| `pidin times` | CPU time per thread |
| `pidin \| grep <x>` | Filter — the most common everyday form |

**The `prio` column:** `<number><policy>` — `f` FIFO, `r` round-robin. `0f` idle · `10r` typical
service · `21r`/`25r` drivers · `254i`/`255i` kernel interrupt threads.

### 4.2 States, at a glance

| Healthy | Investigate if persistent |
|---------|---------------------------|
| `RUNNING` · `READY` · `RECEIVE` · `SIGWAITINFO` · `NANOSLEEP` · `INTR` | **`REPLY`** · `SEND` · `MUTEX` · `CONDVAR` · `SEM` |

**`REPLY`'s `Blocked` column is a PID.** Follow the chain.

### 4.3 The rest of the working set

| Command | Does |
|---------|------|
| `slog2info` | Read the system log ⭐ *first stop after a problem* |
| `hogs` | Top CPU consumers |
| `on -p N cmd` | Run at priority `N` |
| `slay name` | Terminate by name |
| `use cmd` | Built-in usage for a QNX command |
| `ifconfig` | Network interfaces (Ch 23) |
| `shutdown` | Clean shutdown |
| `ls /proc/boot` | What came from the boot image |

### 4.4 Where things are

| Want | Path |
|------|------|
| The boot image contents | `/proc/boot` |
| **Writable, persistent storage** | **`~`** = `/data/home/<you>` |
| Services' registered names | `/dev` |
| Your home | `/data/home/<user>` |
| `slm`'s configuration | `/proc/boot/slm.cfg` |
| Scratch | `/tmp` *(RAM — lost on reboot)* |

### 4.5 Three habits worth forming now

| Habit | Why |
|-------|-----|
| **`pidin` before and after** any change | You cannot spot an abnormal state without knowing the normal one |
| **`slog2info` first** when something broke | The console scrolls; the log does not |
| **`use <cmd>`** before searching the web | Correct for *your* build, and offline |

---

## 5. Worked Example — diagnosing a system you did not start

Suppose you inherit a QNX target and are told *"the display is frozen."* No source, no documentation.
Here is the method, using only this chapter.

### 5.1 Establish what is running

```bash
qnx# pidin info
qnx# pidin | wc -l
```

Version, uptime, free memory, thread count. **Uptime matters:** freshly booted and already frozen is a
different problem from frozen after six days.

### 5.2 Look for the abnormal state

```bash
qnx# pidin | grep -v RECEIVE | grep -v SIGWAITINFO | grep -v NANOSLEEP
```

| Command | Does |
|---------|------|
| `grep -v pat` | Print lines **not** matching — invert the match |

**Filter out the healthy idle states** and see what is left. On a working system this leaves very
little: `RUNNING`, some `INTR`, and any genuinely busy thread.

> 💡 **This one line is most of the technique.** A QNX system at rest is overwhelmingly `RECEIVE` and
> `SIGWAITINFO`. Removing those makes the exceptions visible immediately — far faster than reading two
> hundred lines.

### 5.3 Follow the `REPLY` chain

Suppose the filtered output shows:

```text
397328   1 system/bin/fullscreen-winmgr  10r REPLY   249881
249881  13 system/bin/screen             10r REPLY   184343
184343   6 system/bin/io-hid            254i INTR
```

**Read it as a sentence:** the window manager is waiting on `screen`, which is waiting on `io-hid`,
which is waiting for a hardware interrupt.

**Verdict: nothing is wrong.** This is an idle graphical stack, waiting for input. The frozen display
is not a hung process — it is a system with nothing to do.

> ⚠️ **This is the most valuable outcome to be able to reach confidently**: *"the system is fine, the
> problem is elsewhere."* Without the blocking states you would be guessing, and the temptation is
> always to restart something and hope.

### 5.4 What a genuine hang looks like

```text
 20001   1 my_client   10r REPLY    20002
 20002   1 my_server   10r REPLY    20001
```

**A cycle.** Each waits for the other. Neither will ever proceed.

| Sign | Reading |
|------|---------|
| Two `REPLY`s pointing at each other | **Deadlock** |
| A `REPLY` naming a PID that is not in the listing | The server **died**, and the client will wait forever |
| Many clients in `REPLY` on one server | That server is **stuck or overloaded** — start there |

> 💡 **The third row is the everyday one.** A single wedged server with twenty clients queued behind it
> looks, from the outside, like "the whole system is slow". `pidin` shows you it is one process, and
> names it.

### 5.5 Check the log, then act

```bash
qnx# slog2info | tail -40
```

The console shows only what was printed while you were watching. `slog2info` has the whole record,
with severity and timestamps — and if a driver failed, it very likely said so.

**Then, and only then, act:**

```bash
qnx# slay -f my_server
qnx# pidin | grep my_
```

> 💡 **Chapter 02's Lab 02.2 was practice for this.** On QNX you can kill and restart a wedged service
> — including a driver — without rebooting, because it is a process. Chapter 27 automates it: `slm`
> can be told to restart a component that dies, which is what high availability actually means here.

### 5.6 The method, compressed

| # | Step | Command |
|---|------|---------|
| 1 | What is running, and for how long? | `pidin info` |
| 2 | Hide the healthy idle states | `pidin \| grep -v RECEIVE \| grep -v SIGWAITINFO` |
| 3 | Follow every `REPLY` chain to its end | `pidin \| grep <pid>` |
| 4 | Look for cycles, dead servers, queues | *reading* |
| 5 | Read the log | `slog2info` |
| 6 | Restart the culprit | `slay`, then restart |

**Five commands and one skill.** The skill is step 4, and it is what `⭐ L25` in Chapter 25 examines.


---

## 🧪 Labs

> All on the target. **No compiler needed.**
> `cd ~/qnx800/images/qemu/qemu && mkqnximage --run`, then log in as `root`/`root`.

### Lab 07.1 — Take a baseline  [🐣🚶🏃]

> **Objective.** Record what *healthy* looks like, so you can recognise unhealthy later.
> **Time.** 15 minutes. 📌 `[UNVERIFIED]` — block **V12**.

```bash
qnx# pidin info
qnx# pidin | wc -l
qnx# pidin | awk '{print $5}' | sort | uniq -c | sort -rn
```

| Command | Standard | Does |
|---------|----------|------|
| `awk '{print $5}'` | POSIX | Print the 5th whitespace-separated field — here, `STATE` |
| `sort` · `sort -rn` | POSIX | Sort; `-r` reverse, `-n` numeric |
| `uniq -c` | POSIX | Collapse **adjacent** duplicates and count them — hence the `sort` first |

That pipeline gives a **census of blocking states**: how many threads are in each.

**Then filter to the exceptions:**

```bash
qnx# pidin | grep -v RECEIVE | grep -v SIGWAITINFO | grep -v NANOSLEEP
```

**Answer from your own output:**

1. Which state is most common, and what does that tell you about a healthy QNX system?
2. How many threads are `RUNNING` versus waiting?
3. In the filtered listing, follow one `REPLY` chain to its end. What is at the bottom?
4. Any thread at priority **255**? What is it, and why is it that high?

<details>
<summary>Answers</summary>

1. **`RECEIVE`** should dominate. Servers block waiting for work and use **no CPU**. A listing full of
   `RECEIVE` is a correctly-written idle system, not a stalled one.
2. Very few running; almost everything waiting. On an 8-CPU idle system that is exactly right.
3. Typically `fullscreen-winmgr` → `screen` → `io-hid`, ending in `INTR` or `RECEIVE` — an idle
   graphical stack waiting for input (§5.3).
4. `procnto`'s **interrupt threads**, `255i`. Nothing may delay them — Chapter 01's latency
   component ①, visible in a process listing.

</details>

📋 **Paste the state census and the filtered listing.** They become this course's documented picture
of a healthy system, which every later diagnostic chapter can compare against.

---

### Lab 07.2 — Follow the paths  [🚶🏃]

> **Objective.** Establish, from the shell, that `/dev` entries are processes.
> **Time.** 15 minutes. 📌 `[UNVERIFIED]` — block **V12**.

```bash
qnx# ls /dev
qnx# ls -l /dev/ser1 2>/dev/null || ls /dev | head -20
qnx# pidin | grep devc
qnx# pidin fds | head -40
qnx# pidin -p io-sock
```

| Command | Does |
|---------|------|
| `2>/dev/null` | Discard error output — used here because the path may not exist |
| `cmd1 \|\| cmd2` | Run `cmd2` only if `cmd1` fails |

**Questions:**

1. Find a serial entry in `/dev`. Now find the **process** that owns it. What is it called?
2. Run `pidin fds`. Pick a process — what is it connected to?
3. `io-sock` owns the networking paths. How many **threads** does it have? Why so many?
4. Compare `ls /dev` with `ls /proc/boot`. Why do some names appear in both?

<details>
<summary>Answers</summary>

1. **`devc-ser8250`** — `devc` = *device, character*; `ser8250` = the classic UART. The `/dev` entry
   is a name that process registered.
2. `fds` shows each descriptor and the server behind it — **the system's communication graph.** There
   is no single Linux command with quite this meaning, because on Linux a descriptor usually leads
   into the kernel rather than to another process.
3. Dozens — the verified run showed **over 50**. A network stack handles many concurrent connections,
   and QNX servers use thread pools so one blocked request never stalls the others (Chapter 18).
4. `/proc/boot` holds the **binaries** that came from `ifs.bin`; `/dev` holds the **names those
   running programs registered**. `devc-ser8250` appears in both because the program is in the image
   *and* is currently running and has claimed a path.

</details>

---

### 💥 Break It — make something block, and watch it  [🚶🏃]

> **Objective.** Create a `REPLY` state deliberately, and read it.
> **Time.** 10 minutes. 📌 `[UNVERIFIED]` — block **V12**.

> ⚠️ **Harmless.** You will start a command that waits, look at it from a second session, and stop it.

**Step 1 — open a second session.** SSH in from the host:

```bash
host$ ssh qnxuser@<ip>
```

*(`mkqnximage --getip` gives the address. **`qnxuser`, not root** — [D-009](../meta/Doubts.md#d-009).)*

**Step 2 — in the *first* session, block on something.**

```bash
qnx# sleep 300
```

**Step 3 — in the *second* session, look at it.**

```bash
qnx$ pidin | grep sleep
```

**Predict first:** which state will `sleep` be in?

**Step 4 — now block on input instead.** `Ctrl+C` the sleep, then:

```bash
qnx# cat
```

*(`cat` with no argument reads standard input and waits.)*

From the second session:

```bash
qnx$ pidin | grep cat
qnx$ pidin -p cat
```

**Step 5 — clean up.** `Ctrl+C` in the first session.

<details>
<summary>What you should see, and why the difference matters</summary>

| Command | Expected state | Why |
|---------|----------------|-----|
| `sleep 300` | **`NANOSLEEP`** | Waiting for a *timer*. Nobody needs to do anything for it to resume |
| `cat` *(no args)* | **`REPLY`** or `RECEIVE`-adjacent | Waiting for a **read to be answered** by the terminal driver — a *message* to another process |

**The distinction is the whole point.** Both look like "hung" from outside. But:

- `NANOSLEEP` will resolve **on its own**, at a known time.
- **`REPLY` will only resolve when another process acts** — and the `Blocked` column names it.

> 💡 **That is why QNX distinguishes so many blocking states rather than lumping them into "sleeping"
> as `ps` does.** *"Waiting for time to pass"* and *"waiting for process 20002"* are completely
> different diagnoses, and only the second can deadlock.

📋 **Report both states.** The course predicts `NANOSLEEP` and a `REPLY`-family state respectively;
neither has been observed.

</details>

---

### 🐣 Path A Activity — read a system from its listing  [🐣]

> **Objective.** Diagnose from `pidin` output alone. **No VM required.**
> **Time.** 15 minutes.

**Part 1.** Here is a listing from a system reported as *"completely frozen"*.

```text
     pid tid name                    prio STATE          Blocked
       1   1 procnto-smp-instr         0f RUNNING
   20001   1 sensor_reader            15r REPLY          20002
   20002   1 data_logger              12r REPLY          20003
   20003   1 storage_mgr              10r REPLY          20001
   20010   1 display_app              10r REPLY          20001
   20011   1 heartbeat                20r NANOSLEEP
```

1. What is wrong?
2. Which processes are victims rather than causes?
3. `heartbeat` is `NANOSLEEP`. Will it recover on its own?
4. What would you do first?

<details>
<summary>Answers</summary>

1. **A deadlock cycle**: `sensor_reader` → `data_logger` → `storage_mgr` → **back to `sensor_reader`**.
   Three processes each waiting on the next, in a ring. None will ever proceed.
2. **`display_app`** — it is waiting on `sensor_reader`, which is stuck in the cycle. It is doing
   nothing wrong. **Restarting it would achieve nothing**, which is exactly the mistake the listing
   protects you from.
3. **Yes** — `NANOSLEEP` resolves on a timer, with nobody's help. But `heartbeat` will keep waking,
   find the system broken, and (if it is a watchdog) may eventually reset the machine.
4. **Break the cycle**, then find out why it formed. `slay` one of the three — `storage_mgr` is the
   usual choice, being furthest from the sensor — and watch whether the others unblock. Then
   `slog2info` to find what led to it.

   **The real fix is a design one**: a cycle of synchronous message sends is an architectural fault,
   not a bug to be patched. Chapter 13 covers how to avoid creating one.

</details>

**Part 2.** For each state, say whether it is normal, and what would make it worrying.

| State | Normal? | Worrying when? |
|-------|---------|----------------|
| `RECEIVE` | ? | ? |
| `REPLY` | ? | ? |
| `INTR` | ? | ? |
| `DEAD` | ? | ? |

<details>
<summary>Answers</summary>

| State | Normal? | Worrying when |
|-------|---------|---------------|
| `RECEIVE` | ✅ **The most common state on a healthy system** | Almost never. A server waiting for work is correct |
| `REPLY` | ✅ briefly | **Persistently** — especially if the named PID is missing from the listing, or a cycle exists |
| `INTR` | ✅ Drivers do this constantly | Rarely. If a device is dead its driver may wait forever, but it costs nothing |
| `DEAD` | ✅ transiently | **Persistently** — a terminated thread not being reaped suggests its parent is itself stuck |

</details>

> 💡 **You just diagnosed a deadlock from six lines of text, with no debugger and no source code.**
> That is the skill this chapter exists to build, and it is the reason `pidin` is worth learning
> properly rather than treating as `ps` with a different name.


---

## ✅ Mastery Check

**1.** *(Recall)* What does `pidin` show that `ps` cannot, and why does QNX need it?

<details><summary>Answer</summary>

**The blocking state** — the precise reason each thread is not running, and *who it is waiting on*.

QNX needs it because the system is built from processes exchanging **synchronous messages**. "Waiting"
is not one condition: waiting for a timer, for a message, for a reply from PID 20002, or for an
interrupt are different diagnoses. Only the reply case can deadlock, and only `pidin` names the
partner.

</details>

**2.** *(Recall)* You run `pidin` and most threads are `RECEIVE`. Is the system stuck?

<details><summary>Answer</summary>

**No — that is what a healthy idle QNX system looks like.** Servers block waiting for work and consume
**no CPU**. `RECEIVE` is the most common state on a correctly-written system.

The states to look at are **`REPLY`** (waiting on a specific PID) and persistent `MUTEX`, `CONDVAR` or
`SEM`.

</details>

**3.** *(Apply)* A process sits in `REPLY` with `Blocked` showing `20002`, but no PID `20002` appears
anywhere in `pidin`. What happened, and what will you do?

<details><summary>Answer</summary>

**The server died** while the client was waiting for its reply. The client is blocked on a process
that no longer exists, and will wait indefinitely.

**Do:** `slog2info` to find out why the server died — that is the real problem. Then restart it; on
QNX that is possible without rebooting because it is a process. If it should never have died,
Chapter 27's `slm` restart configuration is the durable answer.

**And note what this reveals about robust design:** a client that blocks forever on a dead server was
written without a timeout. Chapter 13 covers `MsgSend` and how to avoid this.

</details>

**4.** *(Apply)* `ls /dev` shows `ser1`. Explain what that entry *is*, and what happens when a program
calls `open("/dev/ser1")`.

<details><summary>Answer</summary>

It is a **name in the pathname space, registered by a process** — `devc-ser8250` — not a device node
with major/minor numbers.

`open("/dev/ser1")` asks **`procnto`** which process owns that path, and returns a **connection** to
it. Subsequent `read()` and `write()` calls are **messages** to `devc-ser8250`.

**The consequence:** you can `slay` that driver and start another claiming the same path, and clients
that reopen it will reach the new one. Adding a driver on QNX means adding a *process*, not a kernel
module (Chapters 16–17).

</details>

**5.** *(Design)* You are handed a QNX target running unfamiliar software, reported as "slow". Write
the first five commands you would run, and say what each rules in or out.

<details><summary>Answer</summary>

| # | Command | Rules in / out |
|---|---------|----------------|
| 1 | `pidin info` | Uptime, free memory, CPU count. **Rules out** memory exhaustion; slow-after-six-days differs from slow-at-boot |
| 2 | `pidin \| grep -v RECEIVE \| grep -v SIGWAITINFO` | Hides the healthy idle majority. **Everything interesting is in what remains** |
| 3 | `hogs` | Is something *burning* CPU? **Distinguishes "busy" from "blocked"** — a completely different investigation |
| 4 | `pidin \| grep REPLY` | Are many clients queued on one server? **Names the bottleneck** |
| 5 | `slog2info \| tail -50` | Did anything already report an error? **Often answers the question outright** |

**The reasoning behind the order:** steps 1–2 establish the shape cheaply; step 3 forks the
investigation into "busy" versus "blocked", which need different techniques; step 4 finds the
bottleneck if it is blocked; step 5 is checked before doing anything invasive, because the system may
already have told you.

**What is deliberately *not* first:** restarting anything. In the Path A activity, restarting
`display_app` — the obvious suspect, since it is the visible symptom — would have achieved nothing.

</details>

---

## 🧠 Concept Recap

- The shell is **`ksh`** (with `bash` present); POSIX means your skills transfer. `toybox` supplies a
  compact core userland.
- **`pidin` is the command that matters.** It lists **threads**, with **priority**, **policy** and
  **blocking state**.
- **`prio` is `<number><policy>`:** `f` FIFO, `r` round-robin, over **0–255**.
- **`RECEIVE` dominates a healthy system** — servers idle at zero CPU cost.
- **`REPLY`'s `Blocked` column is a PID.** Follow the chain; look for **cycles**, **dead servers**, and
  **queues on one server**.
- **`/dev` entries are processes that registered paths**, not device nodes. `open()` asks `procnto`
  who owns the path; `read()`/`write()` are messages.
- **`pidin fds`** shows the system's communication graph — who is connected to whom.
- **`slog2info` is the first command after a problem**; the console scrolls, the log does not.
- **`use <cmd>`** gives correct usage for *your* build, offline.
- QNX's `/proc` is small **because the information is not in the kernel to expose** — it belongs to the
  processes that own it.
- **The one-line technique:** `pidin | grep -v RECEIVE | grep -v SIGWAITINFO` makes the exceptions
  visible immediately.

---

## 📎 Cheat Sheet

**`pidin`**

| Invocation | Shows |
|------------|-------|
| `pidin` | All threads |
| `pidin info` | Version, uptime, memory, CPUs |
| `pidin -p <name>` | One process |
| `pidin mem` · `times` | Memory · CPU time |
| **`pidin fds`** | Descriptors **and the server behind each** |
| `pidin arg` · `env` | Command lines · environments |

**States**

| Healthy | Investigate if persistent |
|---------|---------------------------|
| `RUNNING` `READY` `RECEIVE` `SIGWAITINFO` `NANOSLEEP` `INTR` | **`REPLY`** `SEND` `MUTEX` `CONDVAR` `SEM` `DEAD` |

**Priorities:** `0f` idle · `10r` services · `21r`/`25r` drivers · `254i`/`255i` kernel interrupts.

**The diagnostic sequence**

```bash
qnx# pidin info
qnx# pidin | grep -v RECEIVE | grep -v SIGWAITINFO
qnx# hogs
qnx# pidin | grep REPLY
qnx# slog2info | tail -50
```

**Other commands**

| Command | Does |
|---------|------|
| `slog2info` | System log |
| `hogs` | Top CPU consumers |
| `on -p N cmd` | Run at priority N |
| `slay name` | Terminate by name |
| `use cmd` | Built-in usage |
| `shutdown` | Clean shutdown |

**Filesystem**

| Path | Is |
|------|----|
| `/proc/boot` | `ifs.bin`, mounted — read-only |
| `/dev` | **Processes that registered paths** |
| **`/data/home/<you>`** | **Your persistent writable area** (`/data`'s root is root-owned) |
| `/tmp` | RAM |
| `/etc` | ⚠️ may not survive a reboot |

**Shell commands introduced**

| Command | Standard | Does |
|---------|----------|------|
| `awk '{print $N}'` | POSIX | Print field N |
| `sort` · `sort -rn` | POSIX | Sort; reverse, numeric |
| `uniq -c` | POSIX | Count **adjacent** duplicates |
| `grep -v` | POSIX | Invert the match |
| `2>/dev/null` | POSIX shell | Discard errors |
| `a \|\| b` | POSIX shell | Run `b` only if `a` fails |

---

## 🔗 Further Reading

| Resource | Why |
|----------|-----|
| `use pidin` **on the target** | ⭐ Authoritative for your exact build, offline |
| [QNX 8.0 Utilities Reference](https://www.qnx.com/developers/docs/8.0/) | Every command in full |
| [QNX 8.0 System Architecture](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.neutrino.sys_arch/topic/about.html) | The pathname space and message passing, properly |
| [`Glossary.md`](../reference/Glossary.md) | Every blocking state, defined |
| [D-013](../meta/Doubts.md#d-013) | Why QNX PIDs are large — they are IPC endpoints |

---

## ➡️ What's Next

**[Chapter 08 — The Toolchain & Deployment](Chapter08_ToolchainAndDeployment.md)** ⭐

Your next **`⭐ core` lab**, and the one that makes you productive. Cross-compiling in earnest, QNX's
recursive Makefiles, `scp` deployment done properly — and **remote debugging**: `gdb` on your host,
attached over the network to a process running on the target through `qconn`, which you have seen in
`slm`'s component list since Chapter 06.

After Chapter 08 you have the complete development loop, and **Part 2 begins the microkernel itself**.

> 🏃 **Path C:** Chapter 08 is a core lab. Do not skip it.
> 🐣 **Path A:** the concepts carry; the lab has an observe-only variant.

---

## 📝 Chapter Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.1 | 2026-08-26 | Filesystem tables corrected: `/data`'s root is root-owned, so the writable location for an unprivileged user is `/data/home/<user>` ([D-015](../meta/Doubts.md#d-015)). |
| 1.0 | 2026-08-26 | Created. `pidin` taught properly — threads, priority, policy and above all **blocking states**, with the `REPLY`-chain technique and the `grep -v RECEIVE` filter that makes exceptions visible. Establishes that `/dev` entries are **processes that registered paths**, not device nodes, and that QNX's `/proc` is small because the information belongs to the processes that own it. §5 diagnoses an unfamiliar system in six steps; the Path A activity has the reader find a **three-process deadlock cycle** from six lines of output. Labs `[UNVERIFIED]` pending block **V12**. |
