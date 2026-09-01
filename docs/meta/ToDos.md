---
title: "ToDos — Open Work Items"
document_id: TODO
version: 1.2
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








| T-028 | 🟠 | **Run block V14** — the kernel's real API surface, fault locality, and ⭐ whether a client is woken with `ESRCH` | ⬜ | — | V14.3 tests Chapter 09's central claim; V14.4 finds the core-dump location Chapter 25 needs. |
| T-029 | 🟡 | Paste `ls -ld /data /data/home /data/home/qnxuser` and `id` | ⬜ | — | Confirms [D-015](Doubts.md#d-015)'s inference with the actual modes. |
| T-027 | 🔴 | ⭐ **Run block V13** — ⚠️ `git pull` first; the Makefile's `DEST` was corrected — core lab L08: build, deploy, and **debug a target process from your host** | ⬜ | — | **The most consequential block since V5.** Every chapter from 09 onwards assumes this loop works. |
| T-026 | 🟠 | **Run block V12** — the healthy-system baseline (`pidin` state census, `fds`, `NANOSLEEP` vs `REPLY`) | ⬜ | — | Target only, 30 min. Feeds Chapter 25's `⭐ L25` diagnostic lab. |
| T-025 | 🔴 | **Run block V11** — ⭐ **especially V11.2**: paste `output/build/ifs.build` and `disk.layout` | ⬜ | — | **The most valuable outstanding request in the course.** It turns Chapter 21 from documentation into a walkthrough of the system you booted. V11.3 tests Ch 06 §3.3's central claim. |
| T-024 | 🟠 | **Run block V10** — SDP layout, disk breakdown, `qcc -v` paths, and three deliberate failures | ⬜ | — | **Host only**, ~25 min; folds into a V9 session. V10.2 tests Chapter 05 §5.1's central claim. |
| T-023 | 🟠 | **Run block V9** — read your licence file, test whether `qcc` is licence-gated, and **read the agreement** | ⬜ | — | **Host only, no VM.** V9.3 is the valuable one: the course already had one licensing fact backwards. |
| T-022 | 🟡 | **Run block V8** — 5 minutes, confirms the security-policy files are in the image | ⬜ | — | Folds into a V7 session. |
| T-021 | 🟠 | **Run block V7** — Chapter 02's labs: kill and restart `vncserv`, then try to `slay procnto` | ⬜ | — | **No compiler needed**, so independent of V6. V7.2 tests a claim the chapter only predicts. |
| T-020 | 🔴 | **Run block V6** — build `labs/lab01_timing/` with `qcc`, deploy, run, and do the loaded/priority comparison | ⬜ | — | Verifies the **lab mechanism** all 33 remaining chapters depend on. V6.3 tests Chapter 01's central claim; if it does not reproduce, the chapter is wrong. |
| T-017 | 🔵 | *When convenient:* paste `cat ~/qnx800/images/qemu/README.md` | ⬜ | — | 394 bytes; may contain QNX's own notes on the image. |
| T-202 | 🟡 | **Report the exact SDP build number** — try `-listInstalledRoots` *(partially answered: the kernel reports build `2026/02/27-11:02:56EST`)* — `~/qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt -listInstalled` | ⬜ | — | Every chapter's front matter must record the SDP build it was written against (`PLAN.md` §5, Risk R5). No chapter can state it today. |
| T-014 | 🔵 | *When convenient:* the QSC install route (graphical vs. headless), licence approval latency, and the real portal button labels | ⬜ | — | Non-blocking. Setup 02 §8 currently offers two routes as equals; it should name the one that works. |

| T-013 | 🟠 | `git pull` before each work session | ⬜ | — | The authoring side moves between your sessions. |
| T-006 | 🔵 | Decide whether to buy a Raspberry Pi 4/5 for the hardware track | ⬜ | Ch 31 | Not needed until Part 6 |
| T-007 | 🔵 | Tell me your realistic weekly time budget (P-06) | ⬜ | — | Lets me calibrate chapter size. Default assumption: ~5 h/week |

---

## 2. 🤖 My action items

### 2.1 Immediate (next session, on approval)

| ID | Pri | Task | Status | Notes |
|----|-----|------|--------|-------|
| T-144 | ✅ | Clear the Setup **02** markers | ✅ | Done — Setup 02 → v2.0, 3 guide bugs fixed |
| T-140 | ✅ | Create `docs/internal/` tier: `CLAUDE-MEMORY.md`, `NewAgentOnboardingGuide.md`, `NewAgentOnboardingPrompts.md`, `VerificationRuns.md` | ✅ | Done, Session 003 |
| T-141 | ✅ | Clear the `[UNVERIFIED]` markers | ✅ | **All three published setup guides verified end to end.** Zero markers remain in the course. |
| T-130b | 🔴 | Write `Chapter10_ProcessesAndThreads.md` | ⬜ | **Next.** Process model, address spaces, thread lifecycle, `pthread_*` → `ThreadCreate`, and why QNX schedules *threads*. |

| T-112 | ✅ | Write `Setup_03_QEMU_VM.md` (QSTI route) + `tools/qemu/qnx-vm.sh` | ✅ | Done 2026-08-26. All steps `[UNVERIFIED]` pending block V5. |
| T-114 | 🟡 | Start `Setup_05_Troubleshooting.md` | ⬜ | Seed it from QNX's official QSTI-for-QEMU troubleshooting page |
| T-105 | ✅ | Commit and push the scaffolding | ✅ | Done, Session 001 |

### 2.2 Short term (Part 0 + Part 1)

| ID | Pri | Task | Status | Notes |
|----|-----|------|--------|-------|



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
| T-148 | 🟠 | Clear Lab 01.2's `[UNVERIFIED]` markers from the V6 output | ⏸️ | Blocked on T-020. Real numbers replace the illustrative `expected_output.txt`. |

| T-138 | 🟡 | Populate `Glossary.md` as terms are introduced | 🔄 |
| T-139 | 🔵 | Part-review mini-projects (6 of them) | ⬜ |

---

## 3. ⏸️ Blocked / waiting

| ID | Item | Blocked by | Unblocks when |
|----|------|-----------|---------------|
| ~~T-200~~ | ✅ **Closed 2026-08-26.** Setup Guides 01 and 02 verified end to end; blocks V1–V4 complete | — | — |
| T-201 | Verify every lab's expected output | No VM yet | Setup 03 completes |
| ~~T-202~~ | Moved to §1 — SDP is installed; only the build number is still unreported | — | — |
| T-203 | Test `build-pdf.sh` end to end | Needs real chapters + Pandoc/TeX installed | T-102/T-103 + PDF deps |

> ⚠️ **Important honesty note.** Until T-200/T-201 clear, install commands and expected outputs in
> the guides are marked **`[UNVERIFIED]`**. Every one of them gets re-tested **on your machine, by
> you** — the author cannot run them (ADR-024) — and the marker is then removed and replaced with
> the real output. Nothing stays in this course that we haven't actually run.
>
> This now includes **Setup Guide 01**, whose install steps were never executed either, despite an
> earlier front-matter claim to the contrary. Corrected 2026-08-26.

---

## 4. ✅ Completed

| ID | Task | Completed | Session |
|----|------|-----------|---------|
| T-140 | Create the `docs/internal/` tier (4 documents) | 2026-08-26 | 003 |
| T-142 | Absorb full project context at author handover and report back | 2026-08-26 | 003 |
| T-143 | Create `PROMPTS.md` and establish the prompt+response logging rule (ADR-023) | 2026-08-26 | 003 |
| T-003 | Request the QNX Everywhere licence | 2026-08-26 | 004 |
| T-010 | Accept **and deploy** the licence | 2026-08-26 | 004 |
| T-146 | Clear Setup Guide 02 §§3–5 markers (Part A confirmed) | 2026-08-26 | 004 |
| T-011 | Install QNX Software Center + SDP 8.0 | 2026-08-26 | 005 |
| T-012 | Report verification output for blocks V1–V4 | 2026-08-26 | 005 |
| T-141 | Clear the `[UNVERIFIED]` markers (both guides) | 2026-08-26 | 005 |
| T-144 | Clear Setup Guide 02 Part B markers → v2.0 | 2026-08-26 | 005 |
| T-200 | Verify every install command actually works | 2026-08-26 | 005 |
| T-130 | Write `Chapter09_MicrokernelArchitecture.md` + `labs/lab09_faultisolation/` — **Part 2 begins** | 2026-08-26 | 021 |
| T-115e | Write `Chapter08_ToolchainAndDeployment.md` ⭐ + `labs/lab08_devloop/` — **Part 1 complete** | 2026-08-26 | 020 |
| T-115d | Write `Chapter07_FirstContactTheQNXShell.md` | 2026-08-26 | 019 |
| T-016 | Measure the SDP's real disk usage — **79 GB**, image not sparse (D-008) | 2026-08-26 | 019 |
| T-151 | Correct the disk budget across PLAN, both setup guides, Ch 05/06 and `check-environment.sh` | 2026-08-26 | 019 |
| T-115c | Write `Chapter06_FirstQNXVMOnQEMU.md` ⭐ (core lab L06) | 2026-08-26 | 018 |
| T-115b | Write `Chapter05_InstallingQNXSDP.md` | 2026-08-26 | 017 |
| T-115 | Write `Chapter04_LicensingAndQNXEverywhere.md` | 2026-08-26 | 016 |
| T-150 | Correct the licensing error in Setup Guide 02 §2 (customer demos are permitted) | 2026-08-26 | 016 |
| T-111 | Write `Chapter03_WhyAndWhereQNXIsUsed.md` — **Part 0 complete** | 2026-08-26 | 015 |
| T-110 | Write `Chapter02_WhatIsQNX.md` | 2026-08-26 | 014 |
| T-149 | Audit published chapters for unexplained library calls (found 5 in Ch 01; all fixed) | 2026-08-26 | 013 |
| T-103 | Write `Chapter01_WhatIsARealTimeSystem.md` + `labs/lab01_timing/` | 2026-08-26 | 012 |
| T-019 | Learner read Chapter 00 | 2026-08-26 | 012 |
| T-102 | Write `Chapter00_HowToUseThisCourse.md` | 2026-08-26 | 011 |
| T-015 | Run Setup Guide 03 end to end (block V5) — **milestone M2** | 2026-08-26 | 010 |
| T-018 | Confirm the SSH account name and `sshd_config` | 2026-08-26 | 010 |
| T-147 | Clear Setup Guide 03's `[UNVERIFIED]` markers → v2.0 | 2026-08-26 | 010 |
| T-008 | Add the user to the `kvm` group | 2026-08-25 | 003 |
| T-009 | Complete Setup Guide 01 on the host | 2026-08-25 | 003 |
| T-145 | Clear the Setup Guide 01 `[UNVERIFIED]` markers with real output → v2.0 | 2026-08-26 | 003 |
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
| 1.21 | 2026-08-26 | D-015: deploy path corrected across four chapters and both lab Makefiles. T-029 added. |
| 1.20 | 2026-08-26 | **Chapter 09 published — Part 2 begins.** T-130 closed; T-130b (Chapter 10) promoted; T-028 added (block V14). |
| 1.19 | 2026-08-26 | ⭐ **Chapter 08 published — Part 1 complete.** T-115e closed; T-130 (Chapter 09, Part 2) promoted; T-027 added (block V13). |
| 1.18 | 2026-08-26 | **Chapter 07 published**; T-016 and T-151 closed (disk figures corrected). T-115d closed; T-115e (Chapter 08 ⭐) promoted; T-026 added (block V12). |
| 1.17 | 2026-08-26 | ⭐ **Chapter 06 published** with core lab L06. T-115c closed; T-115d (Chapter 07) promoted; T-025 added (block V11). |
| 1.16 | 2026-08-26 | **Chapter 05 published.** T-115b closed; T-115c (Chapter 06 ⭐) promoted; T-024 added (block V10). |
| 1.15 | 2026-08-26 | **Chapter 04 published**, and a licensing error in Setup Guide 02 corrected (T-150). T-115 closed; T-115b (Chapter 05) promoted; T-023 added (block V9). |
| 1.14 | 2026-08-26 | **Chapter 03 published — Part 0 complete.** T-111 closed; T-115 (Chapter 04) promoted; T-022 added (block V8). |
| 1.13 | 2026-08-26 | **Chapter 02 published.** T-110 closed; T-111 (Chapter 03) promoted; T-021 added (run block V7). |
| 1.12 | 2026-08-26 | D-014 answered; T-149 added and closed the same session (audit published chapters against the new library-function rule). |
| 1.11 | 2026-08-26 | **Chapter 01 published** with the course's first compiled lab. T-103 and T-019 closed; T-110 (Chapter 02) promoted; T-020 (run block V6) and T-148 (clear the lab's markers) added. |
| 1.10 | 2026-08-26 | **Chapter 00 published.** T-102 closed; T-103 (Chapter 01) promoted to 🔴; T-019 added (learner reads Chapter 00). |
| 1.9 | 2026-08-26 | **Block V5 complete.** T-015, T-018, T-147 closed. All three setup guides verified; zero `[UNVERIFIED]` markers remain. **T-102 (Chapter 00) is the next action.** |
| 1.8 | 2026-08-26 | **M2 reached.** T-015 re-scoped to V5.6–V5.7; T-018 added (confirm the SSH account); T-202 downgraded — the kernel build date is now known. |
| 1.7 | 2026-08-26 | **V5.1–V5.2 passed, V5.3 blocked and fixed.** T-015 re-scoped to the retry; T-016 (sparse-file measurement) and T-017 (image README) added. |
| 1.6 | 2026-08-26 | **Setup Guide 03 published.** T-112 closed. New learner item T-015 (run block V5) and author item T-147 (clear its markers). |
| 1.5 | 2026-08-26 | **Blocks V3 and V4 complete — all verification done.** T-011, T-012, T-141, T-144, T-200 closed. T-202 promoted to a learner item (SDP build number still unreported). T-112 (Setup Guide 03) unblocked and 🔴. **T-102 Chapter 00 off hold.** |
| 1.4 | 2026-08-26 | **Block V2 complete.** T-003, T-010 and T-146 closed; Risk R1 closed. T-011 promoted to 🔴 and unblocked. T-014 added (optional licence-flow detail for Chapter 04). |
| 1.3 | 2026-08-26 | **Block V1 verified.** T-008 and T-009 closed; T-145 added and closed (Setup Guide 01 → v2.0). T-013 re-scoped to every session. T-144 added for Setup Guide 02. |
| 1.2 | 2026-08-26 | Session 003: author handover. T-140/142/143 closed. New learner items T-012 (rewritten) and T-013. New author item T-141 (clear the markers). **T-102 Chapter 00 put on hold** by learner instruction until onboarding and verification are complete. T-200 re-scoped to ADR-024. |
| 1.1 | 2026-08-25 | Session 002: plan approved; T-001/002/004/005/100/101/104 closed. New learner items T-008…T-012 (KVM group, Setup 01, licence request/accept/deploy, SDP install, verification feedback). Next author item: Chapter 00. |
| 1.0 | 2026-08-25 | Created. 7 learner items, 26 author items, 4 blocked, 9 completed. |
