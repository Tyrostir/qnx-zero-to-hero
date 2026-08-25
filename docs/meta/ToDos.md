---
title: "ToDos — Open Work Items"
document_id: TODO
version: 1.0
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "Continuously"
---

# ✅ ToDos.md

> Every open work item for this course. Items are never deleted — they move to
> [§4 Completed](#4-completed).

**Priority:** 🔴 Blocker · 🟠 High · 🟡 Normal · 🔵 Low · ⚪ Someday
**Owner:** 👤 You (learner) · 🤖 Me (author) · 🤝 Both
**Status:** ⬜ Open · 🔄 In progress · ⏸️ Blocked · ✅ Done

---

## 1. 👤 Your action items

| ID | Pri | Task | Status | Depends on | Notes |
|----|-----|------|--------|-----------|-------|
| T-008 | 🔴 | **Add yourself to the `kvm` group** — `sudo usermod -aG kvm $USER`, then `wsl --shutdown` from Windows | ⬜ | — | Without this the VM runs 10–50× slower. [Setup 01 §8](../guides/Setup_01_Prerequisites.md#8-step-6--enable-kvm-hardware-acceleration-) |
| T-009 | 🔴 | **Do [Setup Guide 01](../guides/Setup_01_Prerequisites.md)** — install QEMU, build tools, Java (~40 min) | ⬜ | — | Nothing needs a QNX account. Do it now. |
| T-003 | 🔴 | **Create a myQNX account and REQUEST the QNX Everywhere licence** | ⬜ | — | ⚠️ **Highest priority.** [Setup 02 Part A](../guides/Setup_02_QNX_Account_And_License.md#part-a--get-the-licence). Approval latency is Risk R1. |
| T-010 | 🟠 | **Accept AND deploy** the licence in the myQNX License Manager | ⬜ | T-003 | The step everyone misses — [Setup 02 §5](../guides/Setup_02_QNX_Account_And_License.md#5-step-3--accept-and-deploy-the-licence-) |
| T-011 | 🟠 | Install QNX Software Center + SDP 8.0 (~10 GB) | ⬜ | T-010 | [Setup 02 Part B](../guides/Setup_02_QNX_Account_And_License.md#part-b--install-the-software) |
| T-012 | 🟡 | Report back which `[UNVERIFIED]` steps worked / didn't | ⬜ | T-011 | Lets me remove the markers and paste real output |
| T-006 | 🔵 | Decide whether to buy a Raspberry Pi 4/5 for the hardware track | ⬜ | Ch 31 | Not needed until Part 6 |
| T-007 | 🔵 | Tell me your realistic weekly time budget (P-06) | ⬜ | — | Lets me calibrate chapter size. Default assumption: ~5 h/week |

---

## 2. 🤖 My action items

### 2.1 Immediate (next session, on approval)

| ID | Pri | Task | Status | Notes |
|----|-----|------|--------|-------|
| T-102 | 🔴 | Write `Chapter00_HowToUseThisCourse.md` | ⬜ | **Next turn.** Conventions, symbols, lab mechanics, path selection |
| T-103 | 🟠 | Write `Chapter01_WhatIsARealTimeSystem.md` | ⬜ | Hard/soft real-time, determinism, latency, jitter, WCET |
| T-112 | 🟠 | Write `Setup_03_QEMU_VM.md` (QSTI route) + `tools/qemu/` scripts | ⬜ | ⭐ Critical. Blocked until T-011 gives us a real SDP to test against |
| T-114 | 🟡 | Start `Setup_05_Troubleshooting.md` | ⬜ | Seed it from QNX's official QSTI-for-QEMU troubleshooting page |
| T-105 | ✅ | Commit and push the scaffolding | ✅ | Done, Session 001 |

### 2.2 Short term (Part 0 + Part 1)

| ID | Pri | Task | Status | Notes |
|----|-----|------|--------|-------|
| T-110 | 🟠 | `Chapter02_WhatIsQNX.md` | ⬜ | History 1980→2026, microkernel bet, product family |
| T-111 | 🟠 | `Chapter03_WhyAndWhereQNXIsUsed.md` | ⬜ | Automotive, medical, rail, nuclear, robotics; vs Linux/FreeRTOS/VxWorks |
| T-112 | 🟠 | `Setup_03_QEMU_VM.md` + `tools/qemu/` scripts | ⬜ | ⭐ The critical enabling document |
| T-113 | 🟡 | `Setup_04_IDE_And_Tooling.md` | ⬜ | VS Code QNX Toolkit, Momentics, qconn, remote gdb |
| T-114 | 🟡 | `Setup_05_Troubleshooting.md` | ⬜ | Starts small, grows with every failure we hit |
| T-115 | 🟡 | Chapters 04–08 | ⬜ | |
| T-116 | 🟡 | Labs L06.1, L08.1, L08.2 + `labs/common/` | ⬜ | |

### 2.3 Infrastructure

| ID | Pri | Task | Status | Notes |
|----|-----|------|--------|-------|
| T-120 | 🟠 | `tools/build-pdf.sh` — working Pandoc pipeline | 🔄 | Scaffold written; needs testing once chapters exist |
| T-121 | 🟡 | `docs/guides/PDF_Export.md` — dependency install instructions | 🔄 | Scaffold written |
| T-122 | 🟡 | `tools/pdf/eisvogel.latex` + `metadata.yaml` + custom CSS | ⬜ | Download template during first PDF build |
| T-123 | 🔵 | GitHub Actions: lint Markdown + build PDF on push | ⬜ | Nice-to-have; adds automatic quality gate |
| T-124 | 🔵 | Path-filtered PDFs (A / B / C editions) | ⬜ | Stretch goal from `PLAN.md` §11.2 |
| T-125 | 🔵 | `tools/new-chapter.sh` — scaffold a chapter from the template | ⬜ | Enforces `PLAN.md` §5 mechanically |

### 2.4 Content backlog (later parts)

| ID | Pri | Task | Status |
|----|-----|------|--------|
| T-130 | 🟡 | Chapters 09–15 (Microkernel core) + labs | ⬜ |
| T-131 | 🟡 | Chapters 16–20 (Resource managers) + labs | ⬜ |
| T-132 | 🟡 | Chapters 21–24 (System building) + labs | ⬜ |
| T-133 | 🟡 | Chapters 25–30 (Production) + labs | ⬜ |
| T-134 | 🟡 | Chapters 31–34 (Hardware + capstone) | ⬜ |
| T-135 | 🟠 | `Hardware_01_Public_Boards.md` | ⬜ |
| T-136 | 🟠 | `Hardware_02_Custom_Board.md` | ⬜ |
| T-137 | 🟡 | All 7 cheat sheets | ⬜ |
| T-138 | 🟡 | Populate `Glossary.md` as terms are introduced | 🔄 |
| T-139 | 🔵 | Part-review mini-projects (6 of them) | ⬜ |

---

## 3. ⏸️ Blocked / waiting

| ID | Item | Blocked by | Unblocks when |
|----|------|-----------|---------------|
| T-200 | Verify every install command actually works | No QNX licence yet | T-003 completes |
| T-201 | Verify every lab's expected output | No VM yet | Setup 03 completes |
| T-202 | Record exact SDP 8.0 build number in chapter front matter | SDP not installed | T-003 → Setup 02 |
| T-203 | Test `build-pdf.sh` end to end | Needs real chapters + Pandoc/TeX installed | T-102/T-103 + PDF deps |

> ⚠️ **Important honesty note.** Until T-200/T-201 clear, install commands and expected outputs in
> the guides are marked **`[UNVERIFIED]`**. Every one of them gets re-tested on your machine and the
> marker removed — nothing stays in this course that we haven't actually run.

---

## 4. ✅ Completed

| ID | Task | Completed | Session |
|----|------|-----------|---------|
| T-001 | Learner read and **approved** `PLAN.md` | 2026-08-25 | 002 |
| T-002 | Learner confirmed the chapter list | 2026-08-25 | 002 |
| T-004 | Pending decisions P-01…P-05 resolved | 2026-08-25 | 002 |
| T-005 | Learning path confirmed: 🚶 **Path B** | 2026-08-25 | 002 |
| T-100 | Write `Setup_01_Prerequisites.md` | 2026-08-25 | 002 |
| T-101 | Write `Setup_02_QNX_Account_And_License.md` | 2026-08-25 | 002 |
| T-104 | Write `tools/check-environment.sh` (and run it) | 2026-08-25 | 002 |
| T-910 | Discover QSTI/CTI; revise ADR-004 | 2026-08-25 | 002 |
| T-900 | Verify host environment (OS, CPU, KVM, RAM, disk) | 2026-08-25 | 001 |
| T-901 | Research current QNX product/licensing state (post-rebrand) | 2026-08-25 | 001 |
| T-902 | Create GitHub repo `Tyrostir/qnx-zero-to-hero` | 2026-08-25 | 001 |
| T-903 | Write `README.md` | 2026-08-25 | 001 |
| T-904 | Write `PLAN.md` | 2026-08-25 | 001 |
| T-905 | Write `TableOfContents.md` (+ alias) | 2026-08-25 | 001 |
| T-906 | Create all six `docs/meta/` living documents | 2026-08-25 | 001 |
| T-907 | Create `docs/reference/` documents | 2026-08-25 | 001 |
| T-908 | Create folder structure, `.gitignore`, `LICENSE` | 2026-08-25 | 001 |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.1 | 2026-08-25 | Session 002: plan approved; T-001/002/004/005/100/101/104 closed. New learner items T-008…T-012 (KVM group, Setup 01, licence request/accept/deploy, SDP install, verification feedback). Next author item: Chapter 00. |
| 1.0 | 2026-08-25 | Created. 7 learner items, 26 author items, 4 blocked, 9 completed. |
