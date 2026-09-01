---
title: "Course State — Where We Are"
document_id: STATE
version: 1.26
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "End of every working session, and after every chapter is published"
---

# 📍 CourseState.md

> **This is the single source of truth for course progress.**
> If you return after a long break, read this file first, then
> [`CompactContext.md`](CompactContext.md). Together they take ~3 minutes and restore full context.

---

## 1. At a glance

| Field | Value |
|-------|-------|
| **Course** | QNX Zero to Hero |
| **Repository** | https://github.com/Tyrostir/qnx-zero-to-hero |
| **Learner** | Tyrostir — starting-level embedded engineer (C/C++ solid, Python strong) |
| **Active path** | 🚶 **Path B — Self-Learner** *(confirmed 2026-08-25; Paths A and C authored in full for future readers — ADR-008)* |
| **Current phase** | **Phase 2 — writing chapters** |
| **Plan status** | ✅ **Approved** by the learner, 2026-08-25 |
| **Chapters published** | **11 / 34** — Parts 0 and 1 complete; **Part 2 in progress** |
| **Setup guides published** | **3 / 5** — **all three ✅ verified end to end**, zero `[UNVERIFIED]` markers |
| **Labs published** | **4 / 21** compiled — Lab 01.2 (V6), **⭐ L08** (V13), Lab 09.2 (V14), Lab 10.1 (V15) · plus non-compiled labs in every published chapter |
| **QNX licence** | ✅ **Deployed** 2026-08-26 |
| **QNX software installed?** | ✅ **SDP 8.0 at `~/qnx800`** — cross-compile proven |
| **QNX VM booting?** | ✅ **YES** — QNX 8.0.0, 31 processes, IP `192.168.122.46` 🎉 |
| **Blocked on** | **Nothing.** Setup Guide 03 awaits its first real run (block V5). |
| **Last session** | 2026-09-01 (Session 024) |

### Progress bar

```text
Part 0  Orientation        [████████████████████] 100 %   (4/4 chapters) 🎉
Part 1  Environment        [████████████████████] 100 %   (5/5 chapters) 🎉
Part 2  Microkernel Core   [█████               ]  29 %   (2/7 chapters)
Part 3  Resource Managers  [                    ]   0 %   (0/5 chapters)
Part 4  System Building    [                    ]   0 %   (0/4 chapters)
Part 5  Debug & Safety     [                    ]   0 %   (0/6 chapters)
Part 6  Hardware & Beyond  [                    ]   0 %   (0/4 chapters)
────────────────────────────────────────────────────────────────────────
OVERALL                    [██████              ]  32 %   (11/34)
```

---

## 2. ➡️ Next action

| Who | Action |
|-----|--------|
| 👤 **You — do next** | 📕 **Read [Chapter 10](../chapters/Chapter10_ProcessesAndThreads.md)** (~90 min) and run **Lab 10.1** — 45 min. ⭐ **V15.1 is the priority**: it decides whether Chapter 10 §5.4's claim that `pidin` names a contended mutex's *owner* is true, and Chapters 12 and 25 both depend on it. **T-030** (retry the `attach`) and the rest of V13 remain open. |
| 🤖 **Me — next turn** | **Chapter 11 — Scheduling & Real-Time Priorities** (T-130c). 256 priorities, FIFO / round-robin / sporadic, and **priority inheritance** — the mechanism that makes QNX real-time rather than merely fast. |

> 💡 **Why this order.** The QNX Everywhere licence request has unknown latency (Risk R1). Submitting
> it today costs 15 minutes and removes the only real blocker in the course. Everything in Part 0
> (Chapters 00–03) then fills the waiting time productively — it requires no software at all.

> ⚠️ **One correction from Session 001.** Your `/dev/kvm` exists but is **not writable by your user**.
> Without fixing this, your QNX VM would run 10–50× slower under software emulation. Setup Guide 01
> §8 fixes it: `sudo usermod -aG kvm $USER`, then `wsl --shutdown` from Windows.

---

## 3. Environment snapshot (verified 2026-08-25)

| Item | Value | OK? |
|------|-------|-----|
| Host OS | Ubuntu 26.04 LTS ("Resolute Raccoon") | ✅ |
| Kernel | 6.18.33.2-microsoft-standard-WSL2 | ✅ |
| Environment | **WSL2** on Windows | ✅ |
| CPU | Intel Core i7-11850H, 16 logical CPUs, VT-x | ✅ |
| Nested virtualization | `/dev/kvm` **present** | ✅ |
| KVM group membership | ✅ **Fixed 2026-08-25** — `/dev/kvm` present and accessible | ✅ |
| RAM | 23 GiB total, ~21 GiB free | ✅ |
| Disk | 1007 GB volume, **908 GB free**. `~/qnx800` measures **79 GB**; budget **~85 GB** | ✅ |
| Git | `git 2.53.0` | ✅ |
| curl | `curl 8.18.0` | ✅ |
| tar / ssh | GNU tar 1.35 / OpenSSH 10.2p1 | ✅ |
| `build-essential` (gcc, make) | ✅ GCC 15.2.0 · GNU Make 4.4.1 | ✅ |
| Java runtime | ✅ OpenJDK 25.0.4 | ✅ |
| QEMU | ✅ 10.2.1 (qemu-system-x86_64 + qemu-img) | ✅ |
| QNX SDP 8.0 | ✅ `~/qnx800` — cross-compiler **GCC 12.2.0**, targets `x86_64` + `aarch64le` | ✅ |
| QNX licence | ✅ **requested, accepted and deployed** (2026-08-26) | ✅ |
| VS Code + QNX Toolkit | **not installed** | ⬜ Setup 04 |
| Pandoc / TeX (PDF) | **not installed** | ⬜ PDF_Export |

**Latest check (2026-08-26, after Setup Guide 02):** `24 passed · 3 warnings · **0 failed**` ✅
The three remaining warnings are the optional PDF toolchain (`pandoc`, `xelatex`, `mmdc`).
Progression: `13·9·3` → `19·6·0` → **`24·3·0`**.

> Re-run the environment check any time:
>
> ```bash
> host$ ./tools/check-environment.sh
> ```

---

## 4. Chapter status board

**Status key:** 📄 Planned · 📙 Drafting · 📕 Published · ✅ Read by learner · 🧪 Labs done

### Part 0 — Orientation

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 00 | How To Use This Course | 📕 | — | v1.0. Sets the template for all 34 chapters. |
| 01 | What Is a Real-Time System? | 📕 | — | v1.0. Ships `labs/lab01_timing/`. |
| 02 | What Is QNX? | 📕 | — | v1.0. History verified against QNX's own account. |
| 03 | Why & Where QNX Is Used | 📕 | — | v1.0. Market figures verified. Closes Part 0. |

### Part 1 — Environment

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 04 | QNX Licensing & QNX Everywhere | 📕 | — | v1.0. Terms verified; corrected a published error. |
| 05 | Installing QNX SDP 8.0 | 📕 | — | v1.0. The host/target split as the organising idea. |
| 06 | Your First QNX VM on QEMU ⭐ | 📕 | — | v1.0. Contains **core lab L06**. |
| 07 | First Contact — The QNX Shell | 📕 | — | v1.0. `pidin` and blocking states, properly. |
| 08 | The Toolchain & Deployment ⭐ | 📕 | — | v1.0. **Core lab L08.** Remote debugging. |

### Part 2 — Microkernel Core

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 09 | Microkernel Architecture & procnto | 📕 | — | v1.0. Opens Part 2. Fault isolation, mechanically. |
| 10 | Processes and Threads | 📕 | — | v1.0. Container vs worker. ⭐ §5.4: reading a deadlock out of `pidin`'s `Blocked` column. |
| 11 | Scheduling & Real-Time Priorities | 📄 | — | |
| 12 | Synchronization Primitives | 📄 | — | |
| 13 | Message Passing I ⭐ | 📄 | — | |
| 14 | Message Passing II ⭐ | 📄 | — | |
| 15 | Memory Management | 📄 | — | |

### Part 3 — Resource Managers & Drivers

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 16 | The Pathname Space | 📄 | — | |
| 17 | Your First Resource Manager ⭐ | 📄 | — | |
| 18 | Resource Manager Deep Dive | 📄 | — | |
| 19 | Interrupts & Hardware Access | 📄 | — | |
| 20 | Device Drivers & Filesystems | 📄 | — | |

### Part 4 — Building the System

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 21 | Boot Process & the IFS ⭐ | 📄 | — | |
| 22 | Board Support Packages | 📄 | — | |
| 23 | Networking on QNX | 📄 | — | |
| 24 | PPS, Logging & Persistence | 📄 | — | |

### Part 5 — Debug, Performance, Safety, Production

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 25 | Debugging Toolbox ⭐ | 📄 | — | |
| 26 | Tracing & Performance Analysis | 📄 | — | |
| 27 | Adaptive Partitioning & HA | 📄 | — | |
| 28 | Security on QNX | 📄 | — | |
| 29 | Functional Safety | 📄 | — | |
| 30 | QNX Hypervisor | 📄 | — | |

### Part 6 — Hardware, Capstone & Beyond

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 31 | Running QNX on Real Hardware | 📄 | — | |
| 32 | Bringing Up a Custom Board | 📄 | — | |
| 33 | Capstone Project | 📄 | — | |
| 34 | Ecosystem, Career & Next Steps | 📄 | — | |

### Guides

| Guide | Doc status | Notes |
|-------|-----------|-------|
| Setup 01 — Prerequisites | 📕 **Published ✅ verified** | v2.0 — executed end to end on the host. All expected output is real. Risk R9 did not materialise. |
| Setup 02 — Account, Licence, SDP | 📕 **Published ✅ verified** | v2.0 — executed end to end. Three real bugs found and fixed. Disk cost corrected to ~43 GB. |
| Setup 03 — QEMU VM ⭐ | 📕 **Published ✅ verified** | v2.0 — executed end to end against QNX 8.0.0. Cost 5 bugs and 2 wrong predictions to get right. |
| Setup 04 — IDE & Tooling | 📄 | |
| Setup 05 — Troubleshooting | 📄 | Grows continuously |
| Hardware 01 — Public Boards | 📄 | |
| Hardware 02 — Custom Board | 📄 | |
| PDF Export | 📙 Drafted | Untested until chapters exist (T-203) |

---

## 5. Milestone tracker

| Milestone | Definition | Status | Date reached |
|-----------|-----------|--------|--------------|
| **M0** Plan approved | `PLAN.md` status = Approved | ⬜ In progress | — |
| **M1** "I get it" | Ch 00–03 read | 🎉 **All four published** — reached when the learner finishes Ch 03 | 2026-08-26 |
| **M2** "It boots" 🎉 | QNX VM boots to a shell; hello-world runs | ✅ 🎉 **COMPLETE** — and Parts 0+1 are now written | 2026-08-26 |
| **M3** "I speak QNX" | Ch 09–15 + labs done | ⬜ | — |
| **M4** "I can extend the OS" | Resource manager written and working | ⬜ | — |
| **M5** "I own the image" | Custom IFS boots | ⬜ | — |
| **M6** "I can ship it" | Ch 25–30 + debugging review passed | ⬜ | — |
| **M7** "Hero" 🏆 | Capstone complete | ⬜ | — |

---

## 6. Session log

*Newest first. One entry per working session.*

### Session 025 — 2026-09-01 🔧 **D-017: what is, and is not, in the SDP's target tree**

| | |
|---|---|
| **Goal** | Unblock the learner at Lab 08.1 step 5b, where `$QNX_TARGET/usr/bin` did not exist. |
| **Done** | ⚠️ **`$QNX_TARGET` is two things stacked in one directory**, and Chapter 08 never said so at the point of use. `$QNX_TARGET/usr/` is the **architecture-independent** development side — `include/`, `lib/`, `help/`, `share/`; every file that *runs on QNX* is one level down under `x86_64/` or `aarch64le/`<br>• The course printed `$QNX_TARGET/x86_64/usr/bin/sleep` **correctly** in both §3.4 and step 5b, and never flagged that the `x86_64/` was load-bearing — in a line already containing `x86_64` twice, it reads as noise<br>• Chapter 05 §2.1–2.2 explains the layout properly; **Chapter 08 is where the reader types it**, five chapters later<br>• **Chapter 08 → v1.3:** §3.4 and step 5b both gain the ⚠️ note, an `ls` check *before* opening `gdb`, and the `scp`-off-the-target fallback; troubleshooting table gains the literal `cd: bin: No such file or directory`; cheat sheet's `set sysroot` row notes the architecture level<br>• 💡 **The fallback is the better lesson:** `gdb` needs *a local file whose symbols match* — where it came from is irrelevant, and copying it off the running target is the only route that **cannot** mismatch<br>• **D-017** written; 📋 one sub-question left open — whether the SDP ships `sleep` at all, or whether it is a `toybox` link. **V13.3c** added |
| **Learner decisions** | — |
| **Questions logged** | **D-017** — *both halves* |
| **Then, on the learner's follow-up** | ✅ **The SDP does not ship `sleep` at all.** `$QNX_TARGET/x86_64/usr/bin/sleep` is absent while `/usr/bin/sleep` runs on the target — the directory exists, the file does not<br>• **Why:** the base userland is **`toybox`**, one multi-call binary answering to many names. `ls`, `grep`, `sed`, `sleep` are **links**, not programs, so there is nothing for the SDP to ship<br>• ⚠️ **This corrects Chapter 05 §2.2**, which called the target tree *"a faithful image of a real QNX filesystem"*. It is not a superset of a running system. **Chapter 05 → v1.1**: *laid out like*, plus the optional-vs-base distinction, plus the illustrative listing marked `[UNVERIFIED]`<br>• **Chapter 08 → v1.4:** `scp` off the running target is now the **primary** route for debugging a target utility, not a fallback — and it is the only route that *cannot* produce a symbol mismatch, which also makes it the safe answer to the 💥 exercise<br>• ⭐ **Hazard H-17, and it lands on Chapter 21:** an image built only from `$QNX_TARGET/x86_64/` boots with **no `ls`**. `toybox` has to be put in deliberately. **T-036** raised so Ch 21 cannot forget<br>• Glossary's `toybox` entry sharpened; **V13.3c closed**, V13.3d added for the listing Ch 21 needs |
| **Blockers** | None |
| **Next session** | **Chapter 11 — Scheduling & Real-Time Priorities** |

### Session 024 — 2026-09-01 📕 **Chapter 10 — Processes and Threads (11/34)**

| | |
|---|---|
| **Goal** | Write Chapter 10 and its lab. |
| **Done** | 📕 **Chapter 10 published** (1090 lines) — the container/worker distinction, the per-process vs per-thread table, and the three rows that carry consequence: **priority, blocking state and `errno` are per-thread**<br>• §2.2 derives the `pthread_*` return convention from `errno` being a per-thread macro — the single most-repeated beginner error, explained by mechanism rather than by rule<br>• §3.4 makes **join-or-detach** a rule and names the failure it prevents: a leak that presents as *"the system slows down after a few months"*<br>• §3.5 warns that **`return` from `main` calls `exit()`** and kills every other thread mid-instruction<br>• §4 argues for `posix_spawn` over `fork` from three independent directions — the other threads, unpredictable cost, and the MMU assumption — and then **explicitly refuses to guess** what QNX 8 does with `fork()` in a multi-threaded process. The 💥 lab finds out<br>• ⭐ **§5.3–§5.4 is the chapter's real contribution:** `pidin`'s `Blocked` column names a **tid** for `MUTEX`/`JOIN` and a **pid** for `REPLY`, so a deadlock is readable in one line. Marked as the claim most worth verifying<br>• Ships **`labs/lab10_threads/`** — `threadzoo` (five threads, five blocking states), `forktest` (the `fork` experiment), `stacksize` (measures what §3.2 declines to guess), plus a four-TODO skeleton<br>• **Block V15** written: V15.1 decides whether §5.4 survives<br>• Glossary +6 terms; **every letter section re-sorted**, which surfaced **18 duplicate entries** — 🌱 placeholders later superseded by full entries, now removed |
| **Learner decisions** | — |
| **Questions logged** | — |
| **Blockers** | None |
| **Next session** | **Chapter 11 — Scheduling & Real-Time Priorities** |

### Session 023 — 2026-08-26 ✅ **D-016: Chapter 08's centre, verified — by a failure**

| | |
|---|---|
| **Goal** | Unblock the learner at Lab 08.1 step 5, where `attach <pid>` failed. |
| **Done** | ✅ **First direct verification of Chapter 08's central mechanism.** `target qnx <ip>:8000` connects to `qconn` and `info pidlist` lists the target's processes (`path - pid/tid`) — both had been asserted from reasoning alone since the chapter was written<br>❌ `attach 1540128` → `usr/bin/sleep: No such file or directory` — **not a bug.** `gdb` reads symbols on the **host** and had no local copy of the binary; `info pidlist` reports *target* paths, which mean nothing locally<br>💡 **The failure proves §3.4 better than a success would have** — control, the process list and full memory access all crossed the network; **meaning did not**<br>🆕 **`target qnx <ip>` without the port *hangs*** rather than erroring — the worst failure mode a documented command can have<br>• **Fix:** start `gdb` *with* the binary. Own program → `ntox86_64-gdb avg`. Target utility → `ntox86_64-gdb $QNX_TARGET/x86_64/usr/bin/sleep`, which turns Chapter 05 §2.2's *"a faithful image of a QNX filesystem"* from a description into a tool<br>• **Lab 08.1 step 5 split** into **5a** (your own program — the realistic case) and **5b** (`sleep`, kept precisely because it forces the `$QNX_TARGET` question). The failure is explained, not engineered away<br>• **Chapter 08 → v1.2**: §3.4, §4.4 (`set sysroot`), Fast-Track, troubleshooting table, recap and cheat sheet<br>• **D-016** written in full; hazard **H-15**; Glossary `qconn` + *Sysroot* sharpened; **V13.3 recorded as partially verified**, V13.3b added for the retry |
| **Learner decisions** | — |
| **Questions logged** | **D-016** |
| **Blockers** | None — T-030 is the retry, T-031 finishes V13.2 |
| **Next session** | **Chapter 10 — Processes and Threads** |

### Session 022 — 2026-08-26 🔧 **D-015: the deploy path was wrong**

| | |
|---|---|
| **Goal** | Unblock the learner at core lab L08, and fix what the failure exposed. |
| **Done** | ⚠️ **The course had told readers to deploy to `/data` for four chapters.** `/data` is the writable *partition*, but **its root directory is owned by `root`** — `scp` as `qnxuser` fails with `Permission denied`, as does `mkdir`<br>• **Fix:** deploy to `~` = `/data/home/qnxuser`, which is on the same partition and is the user's own<br>• The learner's own `mkdir` in `/data` was good diagnosis — it ruled out SSH, `scp` and the network in one command<br>• **Corrected:** Chapter 06 → v1.2, Chapter 07 → v1.1, Chapter 08 → v1.1, Chapter 09 → v1.1, both lab Makefiles (`DEST ?= /data/home/$(USER)`), both lab READMEs, and the Glossary<br>• Chapter 08's troubleshooting table gains the exact error text so the next reader finds it by searching<br>• **D-015** written in full, with the general lesson: *"the partition is writable"* and *"you can write there"* are different claims — **Unix permissions apply normally on QNX**, and the exotic parts of the filesystem are only `/proc/boot` and the read-only system partition<br>• Hazard **H-14** recorded |
| **Learner decisions** | — |
| **Questions logged** | **D-015** |
| **Blockers** | None — `make TGT=$TGT run` should now work unchanged |
| **Next session** | **Chapter 10 — Processes and Threads** |

### Session 021 — 2026-08-26 📕 **Chapter 09 — Part 2 begins**

| | |
|---|---|
| **Goal** | Open Part 2 with the chapter everything else in it rests on. |
| **Done** | 📕 **Chapter 09 — Microkernel Architecture & `procnto`** published (1004 lines)<br>• Enumerates the **eight things** `procnto` provides, and what is deliberately outside — including the distinction between interrupt *plumbing* (kernel) and interrupt *handling* (your driver, your process)<br>• Introduces the **kernel-call families** and their CamelCase naming, with the note that the header is authoritative for the reader's build<br>• ⭐ Establishes **POSIX on top, messages underneath** as Part 2's central idea: `read()` becomes `MsgSend` to a user-space process and your source is unchanged — which is why Linux code compiles, and why writing a driver means writing a *program*<br>• §3 explains fault isolation **mechanically** — page tables, the fault path, and `procnto`'s seven-step teardown — culminating in the step that matters: **clients blocked on a dying server are woken with `ESRCH`**<br>• §3.3 and §4.3 give **equal weight to what is not survivable**: `procnto` faulting, a driver misusing hardware it legitimately controls, and — the honest one — **deadlock, which fails silently and defeats every protection in the chapter**<br>• §5 traces a NULL dereference end to end, and argues the kernel's real contribution is *converting another process's catastrophe into the client's `errno`* — after which robustness is the client's error handling<br>• 🔬 Deep dive on why first-generation microkernels lost the throughput argument and QNX did not<br>• Ships **`labs/lab09_faultisolation/`**; Glossary +4; **block V14** added, whose V14.3 tests the chapter's central mechanical claim and V14.4 finds the core-dump location Chapter 25 needs |
| **Learner decisions** | "Proceed to chapter 09" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 10 — Processes and Threads** |

### Session 020 — 2026-08-26 🎉 **Part 1 complete**

| | |
|---|---|
| **Goal** | Write Chapter 08, closing Part 1. |
| **Done** | ⭐ **Chapter 08 — The Toolchain & Deployment** published (1177 lines), containing **core lab L08**. **Parts 0 and 1 are now complete: 9/34 chapters.**<br>• The chapter's centre is **remote debugging through `qconn`** — and specifically the split that makes it work: **symbols stay on the host**, only addresses and raw memory cross the network. That is why a stripped target binary is still fully debuggable, and the same split as Chapter 05's `.sym` files<br>• Its one hazard given equal weight: **mismatched host and target builds produce confident nonsense**, with no warning. The 💥 exercise reproduces it deliberately, because in the wild it is genuinely disorienting<br>• The structural fix stated repeatedly — never deploy by hand; make `run` and `debug` depend on `deploy`, which depends on the build<br>• §3.2 walks ADR-007's build-system progression (raw `qcc` → plain Makefile → QNX recursive → CMake) and says why each hides the last<br>• §5 finds an off-by-one buffer overrun with the debugger, and argues why `printf` debugging is actively harmful on a real-time system: it changes timing, and therefore the bug<br>• 🐣 Path A reads a debugging session rather than running one — so the chapter's TOC tag gains 🐣<br>• Ships **`labs/lab08_devloop/`**, which inverts the usual roles: `skeleton/` is a complete, compiling, **subtly wrong** program and `solution/` is the fix, because the exercise is *debugging* rather than filling in `TODO`s<br>• The Makefile's `file` check catches Chapter 05 §5.3's silent failure at build time<br>• Glossary +5; **block V13** added — the most consequential since V5 |
| **Learner decisions** | "Proceed to next" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Part 2 begins — Chapter 09: Microkernel Architecture & `procnto`** |

### Session 019 — 2026-08-26 📕 **Chapter 07 · disk figures corrected**

| | |
|---|---|
| **Goal** | Apply the learner's `du` measurement, then write Chapter 07. |
| **Done** | ⚠️ **Corrected published disk figures across six documents and the check script.** `du -sh ~/qnx800` = **79 GB** (`images/` 53 GB · `target/` 23 GB · `host/` 2.7 GB · `bsp/` 1.1 GB), not the ~43 GB previously published<br>• **D-008 answered definitively: the virtual disk is *not* sparse.** The earlier speculation is retracted<br>• The 43 GB and 79 GB figures **reconciled rather than one replacing the other** — the first was a `df` delta covering more than one directory and predating the image; the second is `du` on one directory. *`df` measures the filesystem over time; `du` measures a directory now*<br>• **`bsp/` (1.1 GB) discovered** — Chapter 22's subject, already on disk; the third time later-chapter material has turned out to be present from the start<br>• `check-environment.sh` thresholds corrected — it would have passed a machine with 30 GB free<br>• 📕 **Chapter 07 — First Contact: The QNX Shell** published (992 lines): `pidin` taught properly, with **blocking states** as the centre; the `REPLY`-chain technique; the `grep -v RECEIVE` filter; `/dev` entries as **processes that registered paths**; and why QNX's `/proc` is small<br>• §5 diagnoses an unfamiliar system in six steps; the 🐣 activity has the reader find a **three-process deadlock cycle** from six lines<br>• Glossary +6 with a new **K** section and **blocking state** de-seeded; **block V12** added |
| **Learner decisions** | Supplied the `du` measurement; asked for Chapter 07 |
| **Questions logged** | None new *(D-008 answered)* |
| **Blockers** | None |
| **Next session** | ⭐ **Chapter 08 — The Toolchain & Deployment** (closes Part 1) |

### Session 018 — 2026-08-26 ⭐ **Chapter 06 — the first core chapter**

| | |
|---|---|
| **Goal** | Write Chapter 06, containing core lab **L06**. |
| **Done** | 📕 **Chapter 06 — Your First QNX VM on QEMU** published (1087 lines)<br>• The **full boot chain** — SeaBIOS → iPXE → `startup-*` → `procnto` → `slm` → `login` — with **`Startup complete`** identified as the BSP/system boundary and *"the single most useful line in a QNX boot log"*<br>• The **syspage** explained as what makes `procnto` board-independent, and therefore what a BSP fundamentally provides<br>• **`ifs.bin` versus the disk**: 20 MB mounted in RAM, permanently, read-only, appearing as `/proc/boot` — and the observation that a QNX system can boot with **no disk at all**, which is how many embedded devices ship<br>• `slm`'s 22 components read as a **dependency argument** rather than a list: logger first, bus before disk, disk before mount, network before `ssh`<br>• §3.3 on **what persists** — only `/data` — and why permanent configuration belongs in the *image*<br>• §3.4 shows `option_files/` and `snippets/` as **CTI already on disk**, the middle stage of ADR-004's QSTI → CTI → `mkifs`<br>• §5 places **every line of the verified boot log**, including why the four benign warnings appear exactly where they do<br>• Labs open `output/build/` — Chapter 21's source material, fifteen chapters early — and the 💥 exercise tests what survives a reboot rather than asserting it<br>• Glossary +5 terms with **build file** promoted from a stub; **block V11** added, whose V11.2 is the highest-value outstanding request in the course |
| **Learner decisions** | "Proceed to chapter 06" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 07 — First Contact: The QNX Shell** |

### Session 017 — 2026-08-26 📕 **Chapter 05**

| | |
|---|---|
| **Goal** | Write Chapter 05 — the SDP installation, explained after the fact. |
| **Done** | 📕 **Chapter 05 — Installing QNX SDP 8.0** published (1026 lines)<br>• Organised around **one idea**: `~/qnx800` holds two operating systems' worth of files, and the test for which tree anything belongs to is *"which CPU and OS actually executes this file?"*<br>• `qcc` **runs from the host tree and reads the target tree** — that crossing is where build errors live, and §4.3 shows all four common failures are the same bug seen from four angles<br>• Explains `source` vs `./` (the most common Unix "I followed the instructions and nothing happened"), and why the environment affects one terminal only<br>• **QSC's four nouns** — installation, profile, baseline, package — with **verified** CLT options from the `-help` output captured in [D-007](Doubts.md#d-007), and a repeated warning that `-listAvailablePackages` does not exist<br>• `.sym` files explained as separated debug symbols, and why Chapter 25's debugging depends on them<br>• 🔬 Deep dive on where **~43 GB** goes: two complete architectures plus debug symbols<br>• §5 traces one `qcc` invocation to the exact tree each piece came from, ending at `interpreter /usr/lib/ldqnx-64.so.2` — and names **the silent failure**: plain `gcc` produces a *working binary for the wrong OS*, with no error at all<br>• 💥 Break It produces §4.3's three failures deliberately, so they are recognised at speed<br>• Glossary +8 terms; **block V10** added — V10.2 tests the chapter's central mechanism, which has only ever been reasoned about |
| **Learner decisions** | "Proceed to chapter 05" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | ⭐ **Chapter 06 — Your First QNX VM on QEMU** (first core chapter) |

### Session 016 — 2026-08-26 📕 **Chapter 04 — and a published error corrected**

| | |
|---|---|
| **Goal** | Write Chapter 04 and open Part 1. |
| **Done** | 📕 **Chapter 04 — QNX Licensing & QNX Everywhere** published (835 lines)<br>• ⚠️ **Found and corrected a licensing error already published in the course.** [Setup Guide 02 §2](../guides/Setup_02_QNX_Account_And_License.md) listed *"demo to existing or potential customers"* as **forbidden**; QNX's licensing page lists it as **explicitly permitted** (*"e.g. as part of a product roadmap"*). Setup Guide 02 → **v2.2**; `CompactContext` and `CLAUDE-MEMORY` corrected; hazard **H-13** recorded<br>• Terms **verified verbatim** against `qnx.software/…/qnx-everywhere/licensing` rather than restated from the course's earlier notes<br>• The chapter's thesis: **the boundary is production and distribution, not whether money is involved** — which is wrong in *both* directions, since hobby/maker *products*, paid training material and customer demos are all permitted, while a free internal test rig is plausibly production use<br>• The **two-licence structure**: a commercial development licence does not permit shipping; distribution is separate<br>• 🐧 The GPL contrast — open-source experience trains you to think the licence matters only at release, which is precisely wrong for a *development* licence<br>• §5 decides four scenarios including **this course itself**, and notes that never shipping QNX binaries was an architectural decision made for licensing reasons<br>• 💥 Break It removes the licence file and finds the toolchain still builds — *"the tool let me" is not "the licence allows it"*<br>• **Filename aligned to the TOC** (`Chapter04_LicensingAndQNXEverywhere.md`) and all cross-chapter links verified; forward references now match the planned filenames for 05 and 06<br>• Glossary +3 terms, **QNX Everywhere** corrected; **block V9** added |
| **Learner decisions** | "Proceed to chapter 04" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 05 — Installing QNX SDP 8.0** |

### Session 015 — 2026-08-26 🎉 **Part 0 complete**

| | |
|---|---|
| **Goal** | Write Chapter 03 and close Part 0. |
| **Done** | 📕 **Chapter 03 — Why & Where QNX Is Used** published (946 lines). **Part 0 is complete: 4/4 chapters, milestone M1.**<br>• Built on one claim: **certification, not latency, is usually the deciding factor.** Latency has many solutions; evidence has few<br>• A **three-question test** and an **eight-step decision framework** designed to be taken into a meeting, with the cost columns nobody fills in — certification evidence, tool qualification, and **schedule risk**, the one that kills projects<br>• Deployment by industry with the **distinct reason in each**: automotive for consolidation + ASIL D, medical for schedule and evidence, rail for SIL 3 with *loose* deadlines, robotics for mixed criticality<br>• Competitive comparison across QNX, Linux + `PREEMPT_RT`, FreeRTOS, Zephyr, VxWorks and INTEGRITY — including that **FreeRTOS is a scheduler, not an OS**, and that "QNX or Linux" is often a false choice since the scaled answer is a hypervisor running both<br>• §5 decides three projects and **one answer is Linux**, stated as strongly as the others<br>• 💥 The break-it exercise asks the reader to **argue the wrong side** — the only way to test judgement rather than recall<br>• 🐣 The Path A memo is also the **Part 0 review**, with a worked example of what a falsifiable "what would change my mind" looks like<br>• **Figures verified** against BlackBerry's 15 October 2024 announcement: 255 million vehicles (+20M YoY, +80M since 2020) and the certification list (IEC 61508 SIL 3, ISO 26262 ASIL D, IEC 62304 Class C, EN 50128/50657 SIL 3)<br>• Glossary +15 terms with **ASIL** promoted from a stub; **block V8** added |
| **Learner decisions** | "Completed Chapter 02, proceed to Chapter 03" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Part 1 — Chapter 04: QNX Licensing & QNX Everywhere** |

### Session 014 — 2026-08-26 📕 **Chapter 02**

| | |
|---|---|
| **Goal** | Write Chapter 02 — What Is QNX? |
| **Done** | 📕 **Chapter 02 published** (935 lines)<br>• The **microkernel bet** stated as one architectural decision, with **its costs given honestly** — messages instead of calls, more context switches, an unfamiliar driver model, and a plain statement that QNX is *not a better Linux*<br>• §1.3 argues the real payoff is **evidence, not reliability**: isolation you can point at is what makes ASIL D tractable, which is why the design outlived its performance rationale where Mach did not<br>• §4 adapts into **The Product & Version Map**, including **four reliable signals for spotting stale QNX material** (`blackberry.qnx.com`, "Neutrino" in a product name, `io-pkt` vs `io-sock`, the version segment in a doc URL) and the rule that concepts age well while commands age badly<br>• §5 decodes the learner's own system: `procnto-smp-instr` component by component, the `uname` fields, and `/proc/boot` as the microkernel bet *expressed as a directory listing* — one kernel file in about eighty<br>• **History verified against primary sources** rather than memory: QNX's own "A little history" page (1980 founding, the AT&T letter, QNX 4 ~1991, Neutrino 1995) and BlackBerry's announcement of **SDP 8.0 GA on 21 March 2024**<br>• Labs: identify your system · **kill `vncserv` and restart it** · 💥 try to `slay procnto` · 🐣 a paper exercise dating five documentation snippets<br>• **The §17 library-function audit was applied at authoring time** — `MsgSend`/`MsgReply` and `open`/`read`/`write` explained on first use, every shell command tabled with its standard<br>• Glossary +10 terms, and **POSIX** promoted from a planning stub; verification block **V7** added |
| **Learner decisions** | "Done with Chapter 01, go ahead with Chapter 02" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 03 — Why & Where QNX Is Used** (closes Part 0) |

### Session 013 — 2026-08-26 🔧 **A rule gap closed**

| | |
|---|---|
| **Goal** | Answer the learner's question about Lab 01.2's library functions, and fix the rule that let it happen. |
| **Done** | • **D-014** answers `clock_gettime`, `nanosleep`, `perror` and `qsort` in full: none is C++, **none is QNX-specific** — two are ISO C, two are POSIX.1b real-time extensions; declarations in `<time.h>`/`<stdio.h>`/`<stdlib.h>`, code in `libc.so.6`, which the learner had already seen in `/proc/boot`<br>• `labs/lab01_timing/README.md` → **v1.1**: a new *"The library functions this lab uses"* section with signatures, arguments, return values, headers, and how to look any function up (read the header first)<br>• Two traps documented that are not style: `(a>b)-(a<b)` instead of `a-b` in a comparator, because the obvious form **overflows** and mis-sorts silently; and sorting *after* the measurement, because `qsort`'s worst case is unspecified — Chapter 01 §3.2's *unbounded computation*, in the lab that teaches it<br>• Chapter 01 → v1.1: Lab 01.2 now points at that section before the build step<br>• **The rule itself was the bug.** `PLAN.md` §2 rule 1 said "define every *term*", which technically excused four unexplained function calls. Extended to library functions, with a matching checkbox in the §17 Definition of Done<br>• **Audited the published chapters under the new rule** and found five more unexplained calls **in Chapter 01 itself**: `InterruptDisable`/`InterruptEnable` (QNX-specific), `qsort` in §3.2, and the three `pthread_*` calls in §5.3 — now all explained, including the trap that the `pthread_*` family returns an error number rather than setting `errno`. Chapter 01 → v1.2<br>• Glossary +6 terms; hazard **H-12** recorded |
| **Learner decisions** | — |
| **Questions logged** | **D-014** |
| **Blockers** | None |
| **Next session** | **Chapter 02 — What Is QNX?** (block V6 still with the learner) |

### Session 012 — 2026-08-26 📕 **Chapter 01 + the first lab**

| | |
|---|---|
| **Goal** | Write Chapter 01 and establish the lab mechanism. |
| **Done** | 📕 **Chapter 01 — What Is a Real-Time System?** published (1024 lines)<br>• Defines real-time without the word "fast"; hard/firm/soft by **consequence, not tightness**; determinism as *bounded and knowable*, illustrated with an ASCII latency histogram<br>• The **four latency components** — three of which belong to the OS — and the **five classic unbounds**, each with its QNX answer and forward chapter reference<br>• **Mars Pathfinder** as the worked illustration of priority inversion<br>• §4 adapts "The API" into **The Vocabulary**: eight quantities with units, the `R` vs `C` trap, utilisation and the **≈69 % rate-monotonic bound**, and the five things a testable timing requirement must name<br>• §5 budgets a 1 kHz control loop to 205 µs/32 % margin, then derives a priority-inversion failure from three individually correct components and fixes it with one `pthread_mutexattr_setprotocol` line<br>• 🔬 Deep dive on why WCET is genuinely hard (measurement gives a *lower* bound)<br>• **First compiled lab:** `labs/lab01_timing/` — Makefile calling `qcc` directly (ADR-007), skeleton with 4 TODOs, annotated solution, `expected_output.txt`. Source is clean under `gcc -Wall -Wextra`<br>• 💥 Break It measures the tail growing under load, then recovers it with `on -p 63`<br>• 🐣 Path A activity is paper-only — five systems to classify, one budget to compute — because no verified binary exists to ship<br>• Glossary +13 terms; **verification block V6** added |
| **Learner decisions** | "Proceed to write Chapter 01" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 02 — What Is QNX?** |

### Session 011 — 2026-08-26 📕 **First chapter published**

| | |
|---|---|
| **Goal** | Write Chapter 00 and establish the template every later chapter follows. |
| **Done** | 📕 **Chapter 00 — How To Use This Course** published (897 lines), the first of 34<br>• Follows `PLAN.md` §5 exactly: promise → 🏃 Fast-Track Summary → objectives → prerequisites → mental model → problem → concept → mechanism → notation → worked example → labs → mastery check → recap → cheat sheet<br>• **Three labs, all runnable on the now-verified VM:** ⭐ Lab 00.1 (prove the environment, meet `uname`/`pidin`/`pidin info`/`ls /proc/boot`), Lab 00.2 (working habits: two terminals, SSH keys, `CourseState.md`), and a **💥 Break It** that runs `mkqnximage` from the wrong directory to teach reading an error rather than reaching for `--force`<br>• 🐣 **Path A activity** reads a live `pidin` listing — no coding, no compiler<br>• Every expected output is real, from the verified target<br>• §4 is a **notation reference** — the chapter's "API" is the course's own conventions<br>• §5 walks through a sample chapter section and explains *why* each element is there<br>• Glossary +10 terms; sections L and U added and kept alphabetical<br>• Style audit clean: one H1, no heading skips, no GitHub-only syntax, 2 Mermaid diagrams each with a text description |
| **Learner decisions** | "Go ahead and write Chapter 00" |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | **Chapter 01 — What Is a Real-Time System?** |

### Session 010 — 2026-08-26 ✅ **Phase 1 complete**

| | |
|---|---|
| **Goal** | Close block V5 and finish the environment phase. |
| **Done** | 🎉 **`Hello from QNX!` ran on the target** — PID 14032920. The full **edit → cross-compile → deploy → run** loop is closed<br>• **Block V5 complete** · **Milestone M2 complete** · **Phase 1 complete**<br>• Setup Guide 03 → **v2.0**, verified end to end. **Zero `[UNVERIFIED]` markers remain anywhere in the course**<br>• ✏️ **Corrected D-009:** the image ships **`PermitRootLogin no`**, not `prohibit-password`. Keys do not help root either — §9.5 had claimed they would<br>• SSH confirmed: `qnxuser`/`qnxuser`, `sudo` password the same<br>• `/etc/passwd` read into the guide: homes on the writable `/data` partition, `sshd` privilege-separated, and a warning that every credential on the image is a published default while `qnxuser` holds full `sudo`<br>• **+D-011** (reading `/etc/passwd` and `sshd_config`, including the trap of grepping comments), **+D-012** (the apparent `ssh root@` success — the transcript shows it failing), **+D-013** (why QNX PIDs are large: they are message-passing endpoints) |
| **Learner decisions** | Attested block V5 complete |
| **Questions logged** | **D-011, D-012, D-013** |
| **Blockers** | None |
| **Next session** | ⭐ **Chapter 00 — How To Use This Course** |

### Session 009 — 2026-08-26 🎉 **Milestone M2**

| | |
|---|---|
| **Goal** | Get the VM booting and unblock the learner at V5.5. |
| **Done** | 🎉 **THE VM BOOTS.** QNX 8.0.0, kernel build `2026/02/27-11:02:56EST`, 31 processes / 207 threads / 8 CPUs<br>• **Hazard H-9 did not materialise** — bridged `virbr0` networking worked on WSL2 first try, `192.168.122.46` on a virtio `vtnet0`<br>• **Diagnosed V5.5's blocker:** `sshd` refuses *password* auth for root (`PermitRootLogin prohibit-password`, the OpenSSH default). The password was never wrong. Fix: `ssh qnxuser@<ip>` → **D-009**<br>• Explained the four alarming-but-benign boot warnings → **D-010**<br>• Setup Guide 03 → **v1.2**, §§4–9 now ✅ verified with real output throughout<br>• §8 rewritten around real `pidin`: the STATE column, the 256-priority scale in use, drivers as user-space processes, and **live message passing visible in the `REPLY` column** (`fullscreen-winmgr` → `screen` → `io-hid`)<br>• `/proc/boot` listing shows **`ldqnx-64.so.2`** — the exact file Linux could not find in Setup Guide 02<br>• `slm`'s 22 components documented as the QNX answer to `systemd`<br>• Partial answer to T-202: the kernel build date is now known |
| **Learner decisions** | — |
| **Questions logged** | **D-009, D-010** |
| **Blockers** | None — V5.6 just needs `qnxuser` instead of `root` |
| **Next session** | V5.6–V5.7 output, then **Chapter 00** |

### Session 008 — 2026-08-26

| | |
|---|---|
| **Goal** | Unblock the learner at V5.3 and fix what the first real run of Setup Guide 03 exposed. |
| **Done** | • Diagnosed the V5.3 failure: `unpack_qemu_image.sh` extracts into a **nested `qemu/`**, so the image is at `~/qnx800/images/qemu/qemu`. `mkqnximage` was run one level too high → **D-006**<br>• Warned explicitly against the `--force` the error message suggests — it would build a *new* image and ignore the unpacked one<br>• **`-listAvailablePackages` does not exist** — a bug carried in the course since Setup Guide 02. Replaced everywhere with `-listAccessible` and the real option table → **D-007**<br>• Documented the 47 GB `disk-qemu`, sparse files, and the risk of expanding one by copying it → **D-008**<br>• Recorded what the unpacked tree contains: the **`mkifs` build files** (Chapter 21's source material) and the **instrumented SMP kernel** symbols (Chapter 26)<br>• Setup Guide 03 → v1.1; Setup Guide 02 → v2.1; `tools/qemu/qnx-vm.sh` path corrected<br>• **ADR-025** — `/btw` marks an aside that must become a `D-NNN` entry |
| **Learner decisions** | — |
| **Questions logged** | **D-006, D-007, D-008** |
| **Blockers** | None — the fix is a one-line `cd` |
| **Next session** | V5.3–V5.7 retry output, then **Chapter 00** |

### Session 007 — 2026-08-26

| | |
|---|---|
| **Goal** | Write Setup Guide 03 — the QEMU VM — so the learner can reach a `#` prompt. |
| **Done** | • Read QNX's official **QSTI for QEMU** documentation directly (about, getting started, additional specs, troubleshooting)<br>• **Key finding:** QSTI and `mkqnximage` are not alternatives — QSTI supplies the image, `mkqnximage --run` launches it. ADR-004's two-stage plan is unaffected, but the mechanics differ from what was assumed<br>• Published **Setup Guide 03** (729 lines): QSTI install → `unpack_qemu_image.sh` → `mkqnximage --run` → login → `pidin` → SSH → **run the Setup Guide 02 binary on the target** → clean shutdown<br>• Documented the underlying QEMU configuration flag by flag, per course rule #4<br>• Predicted and documented **three WSL2 failure modes**: the `virbr0` bridge needing systemd/libvirt, `sdl,gl=on` under WSLg, and the >32 GB RAM graphics issue<br>• Wrote `tools/qemu/qnx-vm.sh` — a thin, commented wrapper (run/stop/ip/ssh/status) that degrades gracefully<br>• Added verification block **V5** (7 checkpoints); V5.1 also closes T-202<br>• Noted that Ubuntu 26.04's QEMU 10.2.1 skips the build-from-source step QNX prescribes for 22.04/24.04 — Risk R9 working in our favour |
| **Learner decisions** | Setup Guide 03 before Chapter 00 |
| **Questions logged** | None new |
| **Blockers** | None |
| **Next session** | Clear Setup Guide 03's markers from the V5 output, then **Chapter 00** |

### Session 006 — 2026-08-26

| | |
|---|---|
| **Goal** | Verify the SDP install and the cross-compile toolchain; finish the setup guides. |
| **Done** | • Learner completed **blocks V3 and V4** and reported the output<br>• **QNX SDP 8.0 installed** at `~/qnx800`; licence file at `~/.qnx/license/licenses`<br>• `check-environment.sh`: **24 passed · 3 warnings · 0 failed** (from 19/6/0)<br>• **Cross-compile proven** — binary built, `file` confirms the `ldqnx-64.so.2` interpreter, and Linux refuses to run it exactly as predicted<br>• Cross-compiler is **GCC 12.2.0** with six targets across `x86_64` and `aarch64le`<br>• Setup Guide 02 → **v2.0**, all `[UNVERIFIED]` markers cleared<br>• **Three real bugs found and fixed** in Setup Guide 02: a missing `#include <unistd.h>`, a false claim that `file` prints "QNX", and a disk estimate off by ~4×<br>• `PLAN.md` disk budget corrected: ~25 GB → **~50 GB**<br>• **Risk R2 closed**<br>• Learner pushed commits to GitHub manually |
| **Learner decisions** | — |
| **Questions logged** | None new |
| **Blockers** | **None.** Chapter 00 off hold; Setup Guide 03 unblocked. |
| **Open detail** | T-202 SDP build number · T-014 QSC install route, licence latency, portal button labels |
| **Next session** | Learner's choice: **Chapter 00** or **Setup Guide 03 (the QEMU VM)** |

### Session 005 — 2026-08-26

| | |
|---|---|
| **Goal** | Record the licence as obtained and unblock the SDP install. |
| **Done** | • Learner confirmed the QNX Everywhere licence is **requested, accepted and deployed**<br>• **Blocks V2.1–V2.3 complete** — T-003 and T-010 closed<br>• 🎉 **Risk R1 closed.** Licence latency was the only unquantified blocker in the project; nothing external gates the course any more<br>• Setup Guide 02 → v1.1: `[UNVERIFIED]` cleared from §§3–5 (Part A confirmed by a real run) and now scoped to Part B only<br>• **Block V3 unblocked** and promoted to the next action<br>• Git author name spelling corrected to **Kasivishwanathan**; the unpushed commit re-authored |
| **Learner decisions** | Name spelling correction; licence steps attested complete |
| **Questions logged** | None new |
| **Blockers** | None external. Chapter 00 remains on hold by SI-8 until Part B clears. |
| **Next session** | Clear Setup Guide 02 Part B from the V3/V4 output, then **Chapter 00** |

### Session 004 — 2026-08-26

| | |
|---|---|
| **Goal** | Turn Setup Guide 01 from a researched guess into a verified document. |
| **Done** | • Learner executed **Block V1** on the host and reported the output<br>• `check-environment.sh`: **19 passed · 6 warnings · 0 failed** (was 13/9/3)<br>• **T-008 cleared** — `/dev/kvm` now present *and* accessible<br>• **T-009 cleared** — Setup Guide 01 complete<br>• **Risk R9 did not materialise** — every documented package installed under its documented name on Ubuntu 26.04<br>• Setup Guide 01 → **v2.0**: `[UNVERIFIED]` removed, all expected-output blocks replaced with real observed output<br>• §9.2 rewritten around the command actually run, with the SeaBIOS → iPXE → *"No bootable device"* trace explained as the pass<br>• **Corrected the repo path** everywhere: `~/exercises/qnx/qnx-zero-to-hero` → `~/exercises/qnx-zero-to-hero`<br>• Real host toolchain versions recorded for chapter front matter |
| **Learner decisions** | Git identity updated |
| **Questions logged** | None new |
| **Blockers** | 🔴 **V2.1** — the QNX licence has still not been requested. Everything downstream waits on it. |
| **Next session** | Blocks V2–V4 once the licence is deployed; then Setup Guide 02's markers; then Chapter 00 |

### Session 003 — 2026-08-26

| | |
|---|---|
| **Goal** | Hand the project over to a new author without losing context, and make the next handover cheap. |
| **Done** | • New author absorbed the full repository and reported back its understanding<br>• Found that Session 002's final instruction was never carried out — the three onboarding documents did not exist<br>• Established **three document tiers** (ADR-022): course · bookkeeping · internal<br>• Created `docs/internal/`: `CLAUDE-MEMORY.md`, `NewAgentOnboardingGuide.md`, `NewAgentOnboardingPrompts.md`, `VerificationRuns.md`<br>• Created `PROMPTS.md` and the rule that **both prompts and full responses** are logged (ADR-023)<br>• Established that the author **cannot verify anything** — only learner-run output clears an `[UNVERIFIED]` marker (ADR-024)<br>• **Corrected Setup Guide 01's front matter**: it claimed verification it had not earned |
| **Learner decisions** | Log responses as well as prompts · document tiers as above · Chapter 00 held until verification is complete · one deferral recorded |
| **Questions logged** | None new |
| **Blockers** | ⏸️ Chapter 00, by design, pending `[UNVERIFIED]` clearance |
| **Next session** | Clear the markers from the learner's reported output, then Chapter 00 |

### Session 002 — 2026-08-25

| | |
|---|---|
| **Goal** | Get the plan approved and unblock the learner's licence request. |
| **Done** | • Ran `check-environment.sh` against the real host → found `/dev/kvm` **not writable** (T-008)<br>• Researched the QNX Everywhere doc set → **discovered QSTI and CTI official target images**, the QNX Porting Guide, and the DDK Guide<br>• **Plan approved** by the learner, with two amendments<br>• Revised ADR-004 (`mkqnximage` → QSTI → CTI → `mkifs`)<br>• Strengthened ADR-008 (all three paths authored in full)<br>• Added ADR-019 (three capstone flavours), ADR-020 (one chapter/turn, auto-push), ADR-021 (`getqnx` → request/accept/**deploy**)<br>• Published **Setup Guide 01** and **Setup Guide 02**<br>• +15 verified reference links; risks R9, R10 registered |
| **Learner decisions** | Path **B**; all three paths must be authored; all three capstone flavours; auto-push; one chapter per turn |
| **Questions logged** | None new (D-001…D-005 already answered) |
| **Blockers** | None |
| **Next session** | **Chapter 00 — How To Use This Course** |

### Session 001 — 2026-08-25

| | |
|---|---|
| **Duration** | Initial setup |
| **Goal** | Establish the course: repository, plan, structure. |
| **Done** | • Verified host environment (WSL2/Ubuntu 26.04, KVM ✅, 952 GB free)<br>• Created GitHub repo `Tyrostir/qnx-zero-to-hero`<br>• Researched current QNX licensing/product state (QNX Everywhere, SDP 8.0, `qnx.software` rebrand)<br>• Wrote `README.md`, `PLAN.md`, `TableOfContents.md`<br>• Created all meta documents (`CourseState`, `Decisions`, `DecisionsLog`, `CompactContext`, `ToDos`, `Doubts`)<br>• Created reference documents (`ReferenceLinks`, `ResourcesMeta`, `Glossary`)<br>• Set up folder structure, `.gitignore`, PDF toolchain scaffold |
| **Decisions made** | ADR-001 … ADR-014 (see [`Decisions.md`](Decisions.md)) |
| **Questions logged** | None yet |
| **Blockers** | None |
| **Next session** | Plan approval → Setup Guides 01–02 → Chapters 00–01 |

---

## 7. How to update this file

At the end of each session, update:

1. §1 **At a glance** — counts, phase, blockers, last-session date
2. §1 **Progress bar** — recompute
3. §2 **Next action**
4. §4 **Chapter status board** — flip statuses
5. §5 **Milestone tracker** — if a milestone was reached
6. §6 **Session log** — prepend a new session entry
7. Then regenerate [`CompactContext.md`](CompactContext.md)

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.21 | 2026-08-26 | Session 022: D-015 — the deploy path corrected across four chapters and both lab Makefiles. |
| 1.20 | 2026-08-26 | Session 021: **Chapter 09 published — Part 2 begins** (10/34). Block V14 added. |
| 1.19 | 2026-08-26 | Session 020: ⭐ **Chapter 08 published — Parts 0 and 1 complete (9/34)**. Core lab L08 and `labs/lab08_devloop/`. Block V13 added. |
| 1.18 | 2026-08-26 | Session 019: disk figures corrected from measurement; **Chapter 07 published** (8/34). Block V12 added. |
| 1.17 | 2026-08-26 | Session 018: ⭐ **Chapter 06 published** (7/34) with core lab L06. Block V11 added. |
| 1.16 | 2026-08-26 | Session 017: **Chapter 05 published** (6/34). Block V10 added. |
| 1.15 | 2026-08-26 | Session 016: **Chapter 04 published** (5/34, Part 1 begun) and a published licensing error corrected. Block V9 added. |
| 1.14 | 2026-08-26 | Session 015: **Chapter 03 published — Part 0 complete (4/34), milestone M1.** Block V8 added. |
| 1.13 | 2026-08-26 | Session 014: **Chapter 02 published** — 3/34. Block V7 added. |
| 1.12 | 2026-08-26 | Session 013: D-014 answered; the writing rules extended to library functions. |
| 1.11 | 2026-08-26 | Session 012: **Chapter 01 published** — 2/34 — plus the course's first compiled lab and block V6. |
| 1.10 | 2026-08-26 | Session 011: **Chapter 00 published** — 1/34. Phase 2 begins. |
| 1.9 | 2026-08-26 | Session 010: **Phase 1 complete.** Block V5 done, Setup Guide 03 → v2.0, D-009 corrected, doubts to D-013. Next: Chapter 00. |
| 1.8 | 2026-08-26 | Session 009: **M2 reached — the VM boots.** Setup Guide 03 §§4–9 verified; D-009/D-010; H-9 closed. |
| 1.7 | 2026-08-26 | Session 008: V5.3 diagnosed and fixed; three bugs corrected; D-006/007/008 logged; ADR-025. |
| 1.6 | 2026-08-26 | Session 007: Setup Guide 03 published; block V5 defined; next action is booting the VM. |
| 1.5 | 2026-08-26 | Session 006: blocks V3/V4 verified, SDP installed, Setup Guide 02 → v2.0, all markers cleared, Chapter 00 off hold. |
| 1.4 | 2026-08-26 | Session 005: licence deployed, Block V2 complete, Risk R1 closed, V3 is the next action. |
| 1.3 | 2026-08-26 | Session 004: Block V1 verified. Environment snapshot now all-green. Setup Guide 01 marked verified. Repo path corrected. |
| 1.2 | 2026-08-26 | Session 003: author handover. Next action rewritten around `VerificationRuns.md`. Setup Guide 01 status corrected. Chapter 00 marked on hold. |
| 1.0 | 2026-08-25 | Created. Phase 0, 0/34 chapters, environment verified. |
