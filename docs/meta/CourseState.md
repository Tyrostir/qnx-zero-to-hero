---
title: "Course State — Where We Are"
document_id: STATE
version: 1.0
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
| **Active path** | 🚶 **Path B — Self-Learner** *(default; change any time)* |
| **Current phase** | **Phase 0 — Planning & scaffolding** |
| **Chapters published** | **0 / 34** |
| **Setup guides published** | **0 / 5** |
| **Labs completed** | **0 / 21** |
| **QNX software installed?** | ❌ Not yet |
| **QNX VM booting?** | ❌ Not yet |
| **Blocked on** | Nothing — awaiting plan approval |
| **Last session** | 2026-08-25 |

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
| 👤 **You** | Read [`PLAN.md`](../PLAN.md) and [`TableOfContents.md`](../TableOfContents.md). Approve, or request changes. |
| 🤖 **Me (on approval)** | Write, in this order: `Setup_01_Prerequisites.md` → `Setup_02_QNX_Account_And_License.md` → `Chapter00` → `Chapter01`. |

> 💡 **Why setup guides come first:** the QNX Everywhere licence request can take time to be
> processed. Starting that request on day 1 means you are never blocked. Meanwhile you read Part 0,
> which needs no software at all.

---

## 3. Environment snapshot (verified 2026-08-25)

| Item | Value | OK? |
|------|-------|-----|
| Host OS | Ubuntu 26.04 LTS ("Resolute Raccoon") | ✅ |
| Kernel | 6.18.33.2-microsoft-standard-WSL2 | ✅ |
| Environment | **WSL2** on Windows | ✅ |
| CPU | Intel Core i7-11850H, 16 logical CPUs, VT-x | ✅ |
| Nested virtualization | `/dev/kvm` **present** | ✅ |
| KVM group membership | User is **not** in the `kvm` group — device not writable | ⚠️ Setup 01 (T-008) |
| RAM | 23 GiB total, ~21 GiB free | ✅ |
| Disk | 1007 GB volume, **952 GB free** (need ~25 GB) | ✅ |
| Git | `git 2.53.0` | ✅ |
| curl | `curl 8.18.0` | ✅ |
| tar / ssh | GNU tar 1.35 / OpenSSH 10.2p1 | ✅ |
| `build-essential` (gcc, make) | **not installed** | ⬜ Setup 01 |
| Java runtime | **not installed** (QNX Software Center may need it) | ⬜ Setup 02 |
| QEMU | **not installed** | ⬜ Setup 01 |
| QNX SDP 8.0 | **not installed** | ⬜ Setup 02 |
| QNX licence | **not requested** | ⬜ Setup 02 |
| VS Code + QNX Toolkit | **not installed** | ⬜ Setup 04 |
| Pandoc / TeX (PDF) | **not installed** | ⬜ PDF_Export |

**Latest check (2026-08-25):** `13 passed · 9 warnings · 3 failed`
Failures are all expected at this stage: `gcc`, `make`, `qemu-system-x86_64` — installed in Setup Guide 01.

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
| Setup 01 — Prerequisites | 📄 | Written first after approval |
| Setup 02 — Account, Licence, SDP | 📄 | Written first after approval |
| Setup 03 — QEMU VM ⭐ | 📄 | |
| Setup 04 — IDE & Tooling | 📄 | |
| Setup 05 — Troubleshooting | 📄 | Grows continuously |
| Hardware 01 — Public Boards | 📄 | |
| Hardware 02 — Custom Board | 📄 | |
| PDF Export | 📄 | |

---

## 5. Milestone tracker

| Milestone | Definition | Status | Date reached |
|-----------|-----------|--------|--------------|
| **M0** Plan approved | `PLAN.md` status = Approved | ⬜ In progress | — |
| **M1** "I get it" | Ch 00–03 read | ⬜ | — |
| **M2** "It boots" 🎉 | QNX VM boots to a shell; hello-world runs | ⬜ | — |
| **M3** "I speak QNX" | Ch 09–15 + labs done | ⬜ | — |
| **M4** "I can extend the OS" | Resource manager written and working | ⬜ | — |
| **M5** "I own the image" | Custom IFS boots | ⬜ | — |
| **M6** "I can ship it" | Ch 25–30 + debugging review passed | ⬜ | — |
| **M7** "Hero" 🏆 | Capstone complete | ⬜ | — |

---

## 6. Session log

*Newest first. One entry per working session.*

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
| 1.0 | 2026-08-25 | Created. Phase 0, 0/34 chapters, environment verified. |
