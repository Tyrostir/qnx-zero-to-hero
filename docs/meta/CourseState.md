---
title: "Course State — Where We Are"
document_id: STATE
version: 1.2
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
| **Current phase** | **Phase 1 — Environment setup** *(host + toolchain done; VM remaining)* |
| **Plan status** | ✅ **Approved** by the learner, 2026-08-25 |
| **Chapters published** | **0 / 34** |
| **Setup guides published** | **3 / 5** — 01, 02 ✅ verified · 03 §§4–9 ✅ verified, §§10–11 pending |
| **Labs completed** | **0 / 21** |
| **QNX licence** | ✅ **Deployed** 2026-08-26 |
| **QNX software installed?** | ✅ **SDP 8.0 at `~/qnx800`** — cross-compile proven |
| **QNX VM booting?** | ✅ **YES** — QNX 8.0.0, 31 processes, IP `192.168.122.46` 🎉 |
| **Blocked on** | **Nothing.** Setup Guide 03 awaits its first real run (block V5). |
| **Last session** | 2026-08-26 (Session 004) |

### Progress bar

```text
Part 0  Orientation        [                    ]   0 %   (0/4 chapters)
Part 1  Environment        [                    ]   0 %   (0/5 chapters)
Part 2  Microkernel Core   [                    ]   0 %   (0/7 chapters)
Part 3  Resource Managers  [                    ]   0 %   (0/5 chapters)
Part 4  System Building    [                    ]   0 %   (0/4 chapters)
Part 5  Debug & Safety     [                    ]   0 %   (0/6 chapters)
Part 6  Hardware & Beyond  [                    ]   0 %   (0/4 chapters)
────────────────────────────────────────────────────────────────────────
OVERALL                    [                    ]   0 %   (0/34)
```

---

## 2. ➡️ Next action

| Who | Action |
|-----|--------|
| 👤 **You — do next** | **V5.6:** `ssh qnxuser@192.168.122.46` *(not `root` — [D-009](Doubts.md#d-009))*, then `scp` and run `hello_qnx` on the target. Then V5.7 and shut down. |
| 🤖 **Me — next turn** | Clear Setup Guide 03 §§10–11 from your V5.6–V5.7 output, then **Chapter 00**. |

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
| Disk | 1007 GB volume, **952 GB free** (need ~25 GB) | ✅ |
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
| 00 | How To Use This Course | 📄 | — | |
| 01 | What Is a Real-Time System? | 📄 | — | |
| 02 | What Is QNX? | 📄 | — | |
| 03 | Why & Where QNX Is Used | 📄 | — | |

### Part 1 — Environment

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 04 | QNX Licensing & QNX Everywhere | 📄 | — | |
| 05 | Installing QNX SDP 8.0 | 📄 | — | |
| 06 | Your First QNX VM on QEMU ⭐ | 📄 | — | |
| 07 | First Contact — The QNX Shell | 📄 | — | |
| 08 | The Toolchain & Deployment ⭐ | 📄 | — | |

### Part 2 — Microkernel Core

| # | Chapter | Doc status | Learner status | Notes |
|---|---------|-----------|----------------|-------|
| 09 | Microkernel Architecture & procnto | 📄 | — | |
| 10 | Processes and Threads | 📄 | — | |
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
| Setup 03 — QEMU VM ⭐ | 📕 **Published** | v1.2 — §§4–9 ✅ verified against QNX 8.0.0. Real boot log, `pidin`, `ifconfig`. §§10–11 pending V5.6. |
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
| **M1** "I get it" | Ch 00–03 read | ⬜ | — |
| **M2** "It boots" 🎉 | QNX VM boots to a shell; hello-world runs | 🎉 **VM BOOTS** — hello-world pending V5.6 | 2026-08-26 |
| **M3** "I speak QNX" | Ch 09–15 + labs done | ⬜ | — |
| **M4** "I can extend the OS" | Resource manager written and working | ⬜ | — |
| **M5** "I own the image" | Custom IFS boots | ⬜ | — |
| **M6** "I can ship it" | Ch 25–30 + debugging review passed | ⬜ | — |
| **M7** "Hero" 🏆 | Capstone complete | ⬜ | — |

---

## 6. Session log

*Newest first. One entry per working session.*

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
| 1.8 | 2026-08-26 | Session 009: **M2 reached — the VM boots.** Setup Guide 03 §§4–9 verified; D-009/D-010; H-9 closed. |
| 1.7 | 2026-08-26 | Session 008: V5.3 diagnosed and fixed; three bugs corrected; D-006/007/008 logged; ADR-025. |
| 1.6 | 2026-08-26 | Session 007: Setup Guide 03 published; block V5 defined; next action is booting the VM. |
| 1.5 | 2026-08-26 | Session 006: blocks V3/V4 verified, SDP installed, Setup Guide 02 → v2.0, all markers cleared, Chapter 00 off hold. |
| 1.4 | 2026-08-26 | Session 005: licence deployed, Block V2 complete, Risk R1 closed, V3 is the next action. |
| 1.3 | 2026-08-26 | Session 004: Block V1 verified. Environment snapshot now all-green. Setup Guide 01 marked verified. Repo path corrected. |
| 1.2 | 2026-08-26 | Session 003: author handover. Next action rewritten around `VerificationRuns.md`. Setup Guide 01 status corrected. Chapter 00 marked on hold. |
| 1.0 | 2026-08-25 | Created. Phase 0, 0/34 chapters, environment verified. |
