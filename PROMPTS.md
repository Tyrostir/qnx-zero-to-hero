---
title: "PROMPTS.md — Learner Prompt & Response Log (Claude sessions)"
document_id: PROMPTS
version: 2.20
status: Active (living document)
created: 2026-08-26
last_updated: 2026-08-26
audience: "The learner and the AI author only (Tier 3 — internal, per ADR-022)"
update_trigger: "Every prompt the learner sends, and every response the author gives"
---

# 💬 PROMPTS.md — Learner Prompt & Response Log

> ⛔ **Tier 3 — internal working document.** Not part of the QNX course, not linked from the Table of
> Contents, and never included in the PDF book (ADR-022).

---

## 📏 THE RULE (ADR-023)

> **Every prompt the learner sends is recorded here verbatim.
> Every response the author gives is recorded here in full, immediately beneath it.
> Both halves. Every time. No exceptions.**

| | What gets logged | Where |
|---|---|---|
| 📥 | The learner's prompt, **verbatim** — wording, typos and all | `### Prompt (verbatim)` |
| 📤 | The author's **complete** response, not a summary | `### Response (full)` |
| 🎯 | Any permanent instruction extracted from the prompt | `### Standing instructions` |
| ⚙️ | What actually changed on disk | `### Artefacts changed` |

**Why both halves.** A prompt without its response records what was *asked* but not what was
*decided, explained or promised*. Reasoning that lives only in a chat window dies with the session —
and this project has already lost one author mid-task. Requested directly by the learner in
[PROMPT#2](#prompt2).

**Companion documents**

| File | Records |
|------|---------|
| [`COPILOT_PROMPT_HISTORY.md`](COPILOT_PROMPT_HISTORY.md) | The GitHub Copilot era — Sessions 001–002 |
| [`docs/meta/Doubts.md`](docs/meta/Doubts.md) | *Technical questions* and their full answers (`D-NNN`) |
| [`docs/meta/DecisionsLog.md`](docs/meta/DecisionsLog.md) | *Decisions*, with rationale and history (`ADR-NNN`) |
| [`docs/internal/CLAUDE-MEMORY.md`](docs/internal/CLAUDE-MEMORY.md) | The author's distilled working memory |

> 💡 **This file vs. `Doubts.md`.** This file is the **narrative**: what was asked and what was said.
> `Doubts.md` is the **reference**: reusable technical answers, indexed and searchable. One prompt
> may produce zero, one, or several `D-NNN` entries.

---

## Index

| # | Date | Agent | Summary | Outcome |
|---|------|-------|---------|---------|
| [PROMPT#1](#prompt1) | 2026-08-26 | Claude (Opus 5) | Handover from Copilot: absorb all prior context, report understanding (what/why/where/how), start logging prompts | ✅ Handover report delivered · `PROMPTS.md` created |
| [PROMPT#2](#prompt2) | 2026-08-26 | Claude (Opus 5) | Six instructions: log responses too · leave the token · write the 3 onboarding docs · hide the two-machine split from readers · list the verification to-dos · hold Chapter 00 | ✅ All six done · ADR-022/023/024 · `docs/internal/` created |
| [PROMPT#3](#prompt3) | 2026-08-26 | Claude (Opus 5) | Block V1 output delivered in `toAgent/1.BlockV1Output.md`; update the Git identity | ✅ Block V1 verified · Setup Guide 01 → v2.0 · repo path corrected · identity set |
| [PROMPT#4](#prompt4) | 2026-08-26 | Claude (Opus 5) | Correct the name spelling; licence already deployed — mark V2.1–V2.3 complete | ✅ Block V2 complete · **Risk R1 closed** · Setup Guide 02 → v1.1 · V3 unblocked |
| [PROMPT#5](#prompt5) | 2026-08-26 | Claude (Opus 5) | Commits pushed manually; blocks V2–V4 complete, output in `toAgent/2.BlockV2V3V4Output.md` | ✅ **All verification done** · Setup Guide 02 → v2.0 · 3 guide bugs fixed · R2 closed · Chapter 00 off hold |
| [PROMPT#6](#prompt6) | 2026-08-26 | Claude (Opus 5) | "Go for B" — write Setup Guide 03, the QEMU VM | ✅ **Setup Guide 03 published** (729 lines) · `tools/qemu/qnx-vm.sh` · block V5 defined |
| [PROMPT#7](#prompt7) | 2026-08-26 | Claude (Opus 5) | Stuck at V5.3; log in `toAgent/3.BlockV5.1V5.3-StuckAtV5.3.md`; document the `/btw` questions | ✅ Diagnosed: nested `qemu/` directory · 3 bugs fixed · **D-006/007/008** · **ADR-025** (`/btw`) |
| [PROMPT#8](#prompt8) | 2026-08-26 | Claude (Opus 5) | V5.3–V5.5 done, stuck at V5.5 (SSH) | 🎉 **M2 — the VM boots** · SSH fix: use `qnxuser` (**D-009**) · boot warnings benign (**D-010**) · **H-9 closed** · Setup 03 → v1.2 |
| [PROMPT#9](#prompt9) | 2026-08-26 | Claude (Opus 5) | V5.6–V5.7 done; V5 complete; three observations to explain | ✅ **Phase 1 complete** · `Hello from QNX!` ran on target · Setup 03 → v2.0 · **D-009 corrected** · +D-011/012/013 |
| [PROMPT#10](#prompt10) | 2026-08-26 | Claude (Opus 5) | "Go ahead and write Chapter 00" | 📕 **Chapter 00 published** (1/34) — the template's reference implementation · 3 labs · Glossary +10 |
| [PROMPT#11](#prompt11) | 2026-08-26 | Claude (Opus 5) | Chapter 00 read; write Chapter 01 | 📕 **Chapter 01 published** (2/34) + **the first compiled lab** `lab01_timing` · block V6 · Glossary +13 |
| [PROMPT#12](#prompt12) | 2026-08-26 | Claude (Opus 5) | What are `clock_gettime`, `nanosleep`, `perror`, `qsort` — C++ or QNX? Which files? | ✅ **D-014** · lab README → v1.1 · **`PLAN.md` rule 1 extended to library functions** · audit found 5 more in Ch 01 |
| [PROMPT#13](#prompt13) | 2026-08-26 | Claude (Opus 5) | Chapter 01 done; write Chapter 02 | 📕 **Chapter 02 published** (3/34) · history verified from primary sources · block V7 · Glossary +10 |
| [PROMPT#14](#prompt14) | 2026-08-26 | Claude (Opus 5) | Chapter 02 done; write Chapter 03 | 🎉 **Chapter 03 published — Part 0 complete (4/34), milestone M1** · decision framework · block V8 · Glossary +15 |
| [PROMPT#15](#prompt15) | 2026-08-26 | Claude (Opus 5) | Write Chapter 04 | 📕 **Chapter 04 published** (5/34, Part 1 begins) · ⚠️ **corrected a published licensing error** · Setup 02 → v2.2 · block V9 |
| [PROMPT#16](#prompt16) | 2026-08-26 | Claude (Opus 5) | Write Chapter 05 | 📕 **Chapter 05 published** (6/34) · the host/target split · block V10 · Glossary +8 |
| [PROMPT#17](#prompt17) | 2026-08-26 | Claude (Opus 5) | Write Chapter 06 | ⭐ **Chapter 06 published** (7/34) — first core chapter, lab L06 · block V11 · Glossary +5 |
| [PROMPT#18](#prompt18) | 2026-08-26 | Claude (Opus 5) | `du` measurement supplied; write Chapter 07 | ⚠️ **Disk figures corrected across 6 docs + the check script** (79 GB; not sparse) · 📕 **Chapter 07 published** (8/34) · block V12 |
| [PROMPT#19](#prompt19) | 2026-08-26 | Claude (Opus 5) | "proceed to next" | 🎉 **Chapter 08 published — Parts 0 and 1 complete (9/34)** · core lab L08 · `labs/lab08_devloop/` · block V13 |
| [PROMPT#20](#prompt20) | 2026-08-26 | Claude (Opus 5) | Write Chapter 09 | 📕 **Chapter 09 published — Part 2 begins** (10/34) · fault isolation, mechanically · `labs/lab09_faultisolation/` · block V14 |
| [PROMPT#21](#prompt21) | 2026-08-26 | Claude (Opus 5) | `scp` to `/data` fails with Permission denied in lab 08 | ⚠️ **Course error — `/data`'s root is root-owned.** **D-015** · deploy path corrected in 4 chapters + both lab Makefiles |

---

## PROMPT#1

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 003 (first Claude session) |
| **Context** | Handover. GitHub Copilot credit limit reached on the office laptop; the project source now lives on a separate authoring machine. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Note: I am running this session from an ubuntu os running on termux app powered by android phone.
>
> Note: I want you to take over this project with an assumption that, I am going to workout this project in my laptop while keeping the project source (files) here in ubuntu on termux on android phone environment.
>
> Note: This environment is very limited in terms of MEMORY, RAM and ComputingPower. So strictly you should not run any long running tasks/commands here in this environment. More over I expect you to guide me to execute/workout this project step by step manually on my laptop.
>
> Originally I have created this project using copilot from my office laptop. But since the copilot credit limit is reached, I could not continue this project with copilot on my laptop. So I want you to go through all the COPILOT_PROMPT_HISTORY.md file and then all the complete documentations in this repository and build yourself a detailed understanding and report to me of your understanding of what? why? where? How? questions.
>
> I expect you to document all my prompts to you in this PROMPTS.md file as we go in a proper formatting (including this first prompt).

### Standing instructions

| # | Instruction | Consequence |
|---|-------------|-------------|
| SI-1 | The **authoring environment** is Ubuntu-in-Termux on an Android phone (aarch64, ~7 GB RAM, ~18 GB free). | This box is a **writing desk only**. It holds the Markdown source and Git. |
| SI-2 | The **execution environment** is the learner's **laptop**. | Every install/lab/VM step is written to be performed *there*, by hand, by the learner. |
| SI-3 | **No long-running or heavy commands** may be run in the authoring environment. | No QEMU, no SDP install, no PDF/TeX build, no large downloads or clones. |
| SI-4 | The author must **guide the learner step by step, manually**. | Guides stay literal and copy-pasteable; the author never assumes it can run the step itself. |
| SI-5 | Every learner prompt is logged **verbatim** in this file. | This document. |

### Work performed

1. Read [`COPILOT_PROMPT_HISTORY.md`](COPILOT_PROMPT_HISTORY.md) in full (Sessions 001–002).
2. Read the complete documentation set: `README.md`, `docs/PLAN.md`, `docs/TableOfContents.md`, all
   six `docs/meta/` living documents, the `docs/reference/` set, both published setup guides, and
   the `tools/` scripts.
3. Verified the repository state: 2 commits, 0/34 chapters, 2/5 setup guides, 21 ADRs, 5 answered
   doubts.
4. Created this file.

### Response (full)

> *Reproduced as delivered.*

---

Read everything. `PROMPTS.md` now logs PROMPT#1 in full, and I've stored the standing constraints so they survive future sessions.

---

# 📋 Handover Report — Claude taking over `qnx-zero-to-hero`

## 🔷 WHAT — what this project is

**A book you can execute.** *QNX: Zero to Hero* — a self-paced course teaching QNX from absolute first principles to shipping-engineer competence, written as version-controlled Markdown with runnable labs.

| Dimension | Scope |
|---|---|
| Structure | **6 parts · 34 chapters · ~21 labs · 1 capstone** |
| Learner | Starting-level embedded engineer. C/C++ solid, Python strong, **OS internals and RTOS assumed zero** |
| Paths | 🐣 A Absolute Beginner (no coding, ~4 mo) · 🚶 B Self-Learner (**your path**, ~6 mo) · 🏃 C Fast-Track Pro (~1 week) — all three markers live in **one file per chapter** |
| Lab platform | QNX SDP 8.0 on **QEMU + KVM**, x86_64 target — zero hardware, zero cost |
| Output | Markdown on GitHub **plus** Pandoc→XeLaTeX PDF (per-chapter and one bound book) |
| Licence | Content CC BY-SA 4.0, lab code MIT |

The critical path is **Ch 05 → 06 → 08 → 13 → 17 → 21**: install SDP, boot the VM, get the cross-compile/debug loop working, learn message passing, write a resource manager, build your own boot image. Everything else orbits those six.

**Current state: Phase 1, 0/34 chapters, 2/5 setup guides published.** Two commits exist. The plan is approved and the scaffolding is genuinely complete — 613 lines of ADRs, 371 lines of answered doubts, 224 verified reference links. This is not empty stubs.

## 🔶 WHY — why it exists, and why each big choice was made

You wanted QNX taught properly — *what/why/where/how*, nothing assumed, everything documented, every question logged permanently. The documentation system exists because **an AI course author has no memory**; `CompactContext.md` + `CourseState.md` restore full working context in ~3 minutes. That design is exactly why this handover is cheap — and it just proved itself.

The decisions that shape everything (21 ADRs):

- **ADR-009 — message passing is the centre of gravity.** Synchronous `MsgSend`/`MsgReceive`/`MsgReply` is *the* thing that makes QNX QNX. Chapters 13/14 are the course's spine; resource managers (Ch 17) are just message passing wearing a filesystem costume.
- **ADR-004 (revised) — QSTI → CTI → raw `mkifs`.** Copilot originally planned `mkqnximage`, then found QNX's official pre-built **Quick Start Target Image**. Boot fast on day one, then strip away one layer of magic at a time.
- **ADR-008 (strengthened, by your request) — all three paths written in full**, every chapter, even though you only walk Path B. A path that's only a marker is a broken promise to the next reader. Costs ~20–30% more effort per chapter (Risk R10) — accepted deliberately.
- **ADR-015 — no GitHub-only Markdown.** No `> [!NOTE]`, no raw HTML beyond `<details>`, relative links only. This exists *purely* so PDF export never breaks. Violating it now means rewriting 34 chapters later.
- **ADR-014 — every question becomes a permanent `D-NNN`.** Five already logged and answered.

## 🌍 WHERE — the environment, and the split that now defines this project

This is the part your handover changed most.

```text
┌─────────────────────────────────┐        ┌──────────────────────────────────┐
│ 📱 PHONE — Ubuntu/Termux        │  git   │ 💻 LAPTOP — Ubuntu 26.04 / WSL2  │
│    /root/claude/qnx-zero-to-hero│ ◄────► │    ~/exercises/qnx/...           │
│    aarch64 · 7 GB RAM · 18 GB   │        │    i7-11850H · 23 GB · 952 GB    │
│                                 │        │                                  │
│    ✍️  WRITING DESK ONLY        │        │    ⚙️  ALL EXECUTION             │
│    Markdown + Git. Nothing runs.│        │    SDP · QEMU/KVM · labs · PDF   │
└─────────────────────────────────┘        └──────────────────────────────────┘
```

**This split is not a compromise — it's forced and correct.** QNX SDP 8.0 supports **x86-64 Linux/Windows hosts only; no ARM, no macOS**. The phone is aarch64. It could never run QNX even with infinite RAM. So authoring here and executing there is the only shape this project can have.

*Where QNX itself is used* (course subject matter): cars (~255 M vehicles), medical devices, rail signalling, nuclear plant control, industrial robotics, aerospace — anywhere a missed deadline is a safety event, and where IEC 61508 SIL3 / ISO 26262 ASIL D certification is required.

## ⚙️ HOW — how the work gets done from here

**Authoring loop (ADR-016/020):** one chapter per turn → write chapter + labs → update `CourseState`, `Glossary`, `ReferenceLinks`, `ToDos` → one commit, pushed → you read and do the labs → your questions become `D-NNN` entries and patch the chapter.

**Every chapter follows a mandatory template:** 🏃 Fast-Track Summary → objectives → mental-model diagram → **The Problem → The Concept → The Mechanism → The API → Worked Example** → labs (🚶 skeleton, 🏃 solution, 🐣 prebuilt, 💥 break-it) → mastery check → cheat sheet → changelog. Seven writing rules govern the prose; the sharpest are *"why before how"*, *"every QNX concept gets a 🐧 In-Linux box"*, and *"nothing is a black box — explain every flag."*

**How you get QNX** — the single most failure-prone step, and Setup 02 is built around it:

> ⚠️ The licence has **three verbs: request → accept → DEPLOY.** Skipping *deploy* leaves QNX Software Center showing zero installable products, with an error that never mentions why. Entry point: `qnx.com/getqnx`.

---

## 🚩 Four things I need to flag

**1. 🔴 Your GitHub PAT is sitting in plaintext in `.git/config`** — embedded in the remote URL, on a phone. It isn't committed (I checked every tracked file), but I can read it, and so can anything else on this device. **Rotate it**, then set the remote to a bare `https://github.com/tyrostir/qnx-zero-to-hero.git` and use a credential helper or `GITHUB_TOKEN` at push time.

**2. 🟠 Copilot's last instruction was never carried out.** Its final prompt asked for `NewAgentOnboardingGuide.md`, `NewAgentOnboardingPrompts.md`, and `CLAUDE-MEMORY.md` — the session ended mid-task. **None of the three exist.** Given you're now doing exactly the agent-handover they were meant to smooth, they're worth writing properly rather than reconstructing later.

**3. 🟡 Two working copies now exist**, and `CompactContext.md` still records only the laptop path. Nothing in the docs describes the phone↔laptop↔GitHub sync discipline — that needs to become a documented rule, not a habit.

**4. 🟡 The docs assume the author can run things.** `ToDos.md` blocks T-200/T-201 on "verify every install command on the machine" — written when Copilot shared a shell with your SDP install. I can't verify anything now, so the `[UNVERIFIED]` markers in Setup 01/02 can only be cleared by **you** running the steps and reporting back. That's a real workflow change worth writing into the plan.

---

**Suggested next move:** rotate the token, then let me write the three missing onboarding/memory documents and record the two-machine split as an ADR — that closes the handover cleanly. After that, Chapter 00 is queued and needs no software, so you can read it while your QNX licence request processes.

Want me to start with the onboarding documents, or go straight to Chapter 00?

---

### Artefacts changed

| File | Change |
|------|--------|
| `PROMPTS.md` | Created |

---

## PROMPT#2

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 003 |
| **Context** | Immediately after the handover report of [PROMPT#1](#prompt1). |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> 1. I expect all of this entire message from you (your response) for my first prompt also to be documented in PROMPTS.md file and to be continued same way for my every command, every time. Please do it and update this as a rule. 2. No need to rotate the token. Leave the token as it is. We handle this later, not immediately. 3. write 3 missing onboarding/memory documents. 4. The end reader (who is going to read this repo book project) need not know the two-machine split setup. Only me and you (the agent) and any future agent should know it and act accordingly. In end readers perpective, only laptop with wsl2 exist. Not the mobile environment. This mobile environment is just a writing desk only. Think about it and update the appropriate documents accordingly. 5. Regarding "[UNVERIFIED] markers", list down the todos I need to perform and wait for me to report back. (If I face any issues, you should help me resolving) 6. Do not start Chapter 00 until we are done with onboarding and completing [UNVERIFIED] markers thing.

### Standing instructions

| # | Instruction | Recorded as |
|---|-------------|-------------|
| SI-5 *(extended)* | Log **every agent response in full**, immediately below its prompt, every time. | **ADR-023** |
| SI-6 | The **end reader must never learn about the two-machine split.** From their perspective one laptop exists. | **ADR-022** |
| SI-7 | The GitHub PAT in `.git/config` is **deliberately left in place.** Do not rotate it, do not scrub it, do not raise it again unprompted. | Deferral logged in `DecisionsLog.md`; hazard **H-1** |
| SI-8 | **Do not begin Chapter 00** until onboarding and `[UNVERIFIED]` clearance are complete. | `ToDos.md` T-102 set to ⏸️ |

### Response (full)

> *Reproduced as delivered.*

---

All six done. Here's what changed and what's now waiting on you.

## 1️⃣ The logging rule is now permanent — ADR-023

`PROMPTS.md` opens with it in a box that's hard to miss:

> **Every prompt the learner sends is recorded here verbatim. Every response the author gives is recorded here in full, immediately beneath it. Both halves. Every time. No exceptions.**

Your PROMPT#1 response is now in there verbatim, and this response is too. Each entry carries four sections: the verbatim prompt, any **standing instructions** extracted from it, the **full response**, and **artefacts changed**. `Doubts.md` stays what it was — the searchable technical reference; `PROMPTS.md` is the narrative.

## 2️⃣ Token left alone

Untouched, and recorded as a **deliberate deferral** in `DecisionsLog.md` rather than an oversight — so no future agent "helpfully" flags it at you again. It's logged as hazard **H-1** with an explicit *do not raise* note.

## 3️⃣ + 4️⃣ The three documents — and the tier system that keeps them invisible

Point 4 turned out to be the interesting one. The onboarding documents *must* describe the two-machine split (an agent that doesn't know it will run QEMU on the writing desk), but the reader must never see it. So I gave the repository an explicit structure — **ADR-022, three document tiers**:

| Tier | Where | Who reads it | In the PDF book? |
|---|---|---|---|
| 📗 **1 — Course** | `README`, `PLAN`, `TOC`, `chapters/`, `guides/`, `reference/` | The end reader | ✅ |
| 📘 **2 — Bookkeeping** | `docs/meta/` | Learner + curious readers | ✅ |
| 🔒 **3 — Internal** | `docs/internal/` + root `PROMPTS.md`, `COPILOT_PROMPT_HISTORY.md` | You and the agent only | ❌ |

**Tier 1 and Tier 2 describe exactly one machine: your Ubuntu 26.04 / WSL2 laptop.** The split lives only in Tier 3.

Three enforcement points, so this doesn't decay:

- **`tools/build-pdf.sh`** enumerates Tier 1 and 2 by explicit path and never globs `docs/internal/` — Tier 3 is excluded from the book automatically. I annotated the script so no future agent adds it.
- **A prohibited-vocabulary list** in the onboarding guide: never write *"the authoring machine"*, *"Termux"*, *"the phone"*. Always *"your host machine"*, *"your laptop"*.
- **A leak scan** across every Tier 1 and Tier 2 file. Result: **clean.** The only hit was the word "Android" in a legitimate teaching sentence in Setup 01 comparing QNX to other embedded platforms.

**The four new documents, in `docs/internal/`:**

| File | What it does |
|---|---|
| **`CLAUDE-MEMORY.md`** (340 ln) | The agent's brain in one file: the split and why it's permanent, who you are, the course shape, all 24 ADRs, standing instructions SI-1…SI-8, the verified QNX facts, the session history, and 7 known hazards. |
| **`NewAgentOnboardingGuide.md`** (287 ln) | How a cold agent takes over: a 9-step reading order, hard constraints, the turn protocol as a flowchart, an **8-question self-check with collapsed answers**, and a table of the 11 ways a new agent typically gets this wrong. |
| **`NewAgentOnboardingPrompts.md`** (208 ln) | **For you.** Six copy-paste prompts: cold start, minimal cold start, resume-after-a-gap, verify-the-agent-actually-read-it, wind-down-the-outgoing-agent, and correct-a-drifting-agent. Plus a fallback for chat-only agents with no file access. |
| **`VerificationRuns.md`** (428 ln) | Your `[UNVERIFIED]` checklist — see below. |

Plus `docs/internal/README.md` explaining the tiers.

## 5️⃣ Your verification to-do list

**`docs/internal/VerificationRuns.md`** — 18 checkpoints in four blocks. For each: the exact command, what to paste back, and *why* the answer matters.

| Block | What | Time | Gated on |
|---|---|---|---|
| 🔴 **V2.1** | **Request the QNX licence** at `qnx.com/getqnx` | 15 min | — |
| **V1** | Host prep: build tools · Java · QEMU · **KVM group fix** · KVM proof · workspace | ~45 min | nothing |
| **V2** | Licence: approval → accept → **DEPLOY** | wait | V2.1 |
| **V3** | QNX Software Center + SDP 8.0 (~10 GB) | 60–90 min | V2.3 |
| **V4** | Cross-compile proof — build a QNX binary, watch Linux refuse to run it | 10 min | V3.3 |

**Do V2.1 today.** Approval latency is the only true blocker in this course (Risk R1), and it costs fifteen minutes. Then work through V1 while it processes — V1 needs no QNX account at all.

Three things to know before you start:

- **`git pull` first.** Your laptop checkout is behind — it doesn't have any of today's changes.
- **Paste actual output, not summaries.** "It worked" isn't evidence; the text is. And **errors are as valuable as successes** — a failure means the guide is wrong for a real Ubuntu 26.04 machine, which is exactly Risk R9 (QNX documents 22.04/24.04). Paste it and I'll fix the guide and log a `D-NNN`.
- **V1.4, the KVM group fix, matters more than it looks.** Skip it and your VM runs 10–50× slower under software emulation.

**A correction while writing this:** Setup Guide 01's front matter claimed `verified_on: "Ubuntu 26.04 LTS on WSL2, Intel i7-11850H, 2026-08-25"`. That was **not earned** — only `check-environment.sh` was ever run against your machine; none of the install commands were. I corrected the front matter and added the same `[UNVERIFIED]` notice Setup 02 carries. That's now **ADR-024**: the author cannot verify anything, and only your pasted output clears a marker.

## 6️⃣ Chapter 00 is on hold

`ToDos.md` T-102 is ⏸️, `CourseState.md` shows it as deliberately blocked, and the reason is recorded so it reads as your decision rather than a stall.

---

### What changed on disk

**New:** `docs/internal/` — `README.md`, `CLAUDE-MEMORY.md`, `NewAgentOnboardingGuide.md`, `NewAgentOnboardingPrompts.md`, `VerificationRuns.md`

**Updated:** `PROMPTS.md` (rule + both entries) · `Decisions.md` (+ADR-022/023/024) · `DecisionsLog.md` (Session 003) · `CourseState.md` · `CompactContext.md` · `ToDos.md` · `Setup_01_Prerequisites.md` (correction) · `guides/README.md` · `build-pdf.sh` (tier guardrail)

Committed locally. **Not pushed** — say the word and I'll push, since that's an outward action and the remote carries your token.

---

👉 **Over to you: request the licence, then run Block V1 and paste the output back.** Anything that errors, send it as-is — I'll diagnose it, fix the guide, and log it.

### Artefacts changed

| File | Change |
|------|--------|
| `docs/internal/README.md` | **Created** — the three-tier system |
| `docs/internal/CLAUDE-MEMORY.md` | **Created** — the author's working memory (340 lines) |
| `docs/internal/NewAgentOnboardingGuide.md` | **Created** — cold-start guide for a new agent (287 lines) |
| `docs/internal/NewAgentOnboardingPrompts.md` | **Created** — six copy-paste prompts for the learner (208 lines) |
| `docs/internal/VerificationRuns.md` | **Created** — `[UNVERIFIED]` clearance protocol, blocks V1–V4 (428 lines) |
| `PROMPTS.md` | Rewritten to v2.0: the ADR-023 rule, PROMPT#1 with its full response, PROMPT#2 |
| `docs/meta/Decisions.md` | +ADR-022, +ADR-023, +ADR-024 |
| `docs/meta/DecisionsLog.md` | Session 003 appended: 2 verifications, 3 decisions, 1 deferral |
| `docs/meta/CourseState.md` | Session 003 log · next actions rewritten · Chapter 00 on hold · guide statuses corrected |
| `docs/meta/CompactContext.md` | Regenerated (kept Tier-2 safe) |
| `docs/meta/ToDos.md` | T-012 rewritten · +T-013, +T-140, +T-141 · T-102 → ⏸️ · T-200 re-scoped |
| `docs/guides/Setup_01_Prerequisites.md` | **Correction:** unearned `verified_on` claim fixed; `[UNVERIFIED]` notice added |
| `docs/guides/README.md` | `[UNVERIFIED]` explanation updated for ADR-024 |
| `tools/build-pdf.sh` | Annotated: Tier 3 must never be added to the book |

---

## PROMPT#3

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 004 |
| **Context** | The learner executed verification Block V1 on the host and dropped the output into the repository. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I have executed Block V1 and pasted the output at toAgent/1.BlockV1Output.md file. Please read it. And I want to update one info. Please user.name as "Karthikeyan Kasvishwanathan" and user.email as Karthikeyan.KLU@gmail.com

### Standing instructions

| # | Instruction | Recorded as |
|---|-------------|-------------|
| SI-9 | Git commit identity is **`Karthikeyan Kasvishwanathan <Karthikeyan.KLU@gmail.com>`**. History is not rewritten; earlier commits stay under `Tyrostir`. | `git config --local`; logged in `DecisionsLog.md` |
| SI-10 | The learner drops captured host output into **`toAgent/<n>.<WhatItIs>.md`**. Treat it as the evidence that clears `[UNVERIFIED]` markers (ADR-024). | `toAgent/README.md` |

### Response (full)

> *Reproduced as delivered.*

---

Read it. **Block V1 passed clean — `19 passed · 6 warnings · 0 failed`**, up from 13/9/3. Identity updated.

## ✅ What your output proved

| Checkpoint | Result |
|---|---|
| **V1.1** build tools | GCC **15.2.0** · GNU Make **4.4.1** |
| **V1.2** Java | OpenJDK **25.0.4** |
| **V1.3** QEMU | **10.2.1** (`qemu-system-x86_64` + `qemu-img`) |
| **V1.4** KVM group ⚡ | `/dev/kvm` **present and accessible** — T-008 cleared |
| **V1.5** KVM proof | Booted, no KVM error — **Risk R3 closed** |
| **V1.6** workspace + re-check | 4 directories created · **0 failures** |

**Two risks are now dead, not just mitigated:**

- **R9 — Ubuntu 26.04 vs. QNX's documented 22.04/24.04.** This was the one I most expected to bite. **Every package installed under its documented name**, no substitutions, no "Unable to locate package". The guide is now *proven* on 26.04 rather than believed to work there.
- **R3 — KVM under nested virtualization.** Confirmed working inside WSL2.

**Your V1.5 output is genuinely nice**, and I've promoted it into the guide as the documented expected result:

```text
SeaBIOS → Booting from Hard Disk... failed
        → Booting from DVD/CD... failed
        → iPXE... net0: 10.0.2.15/255.255.255.0 gw 10.0.2.2
        → Nothing to boot
        → Booting from Floppy... failed
        → No bootable device.
```

That is a complete virtual machine coming up, trying every boot device in order — including pulling a **DHCP lease from QEMU's built-in NAT** — and finding nothing. It's a preview of the whole course: in Setup Guide 03 you hand that same machine a QNX image, and *"No bootable device"* becomes a `qnx#` prompt.

## 🔧 Two corrections your output caught

**1. The documented repo path was wrong.** Every guide said `~/exercises/qnx/qnx-zero-to-hero`. Your prompt shows the truth: **`~/exercises/qnx-zero-to-hero`** — no intermediate `qnx/` directory. That's a first-line copy-paste failure in every verification block, now fixed across Setup 01, Setup 02, `CompactContext.md` and `VerificationRuns.md`. (`COPILOT_PROMPT_HISTORY.md` keeps the old path — it's a historical transcript, not a live instruction.)

**2. Setup 01 §9.2 documented a command that was never run.** It specified `-kernel /dev/null` and predicted a kernel-loading error. You ran the plain form from `VerificationRuns.md` and got the firmware boot trace instead. I've rewritten the section around the command actually executed, with your real output and an explanation of why that failure is the pass — plus the `Ctrl+A`, `X` exit sequence, which was missing.

## 📕 Setup Guide 01 is now v2.0 — verified

`[UNVERIFIED]` removed. Every expected-output block now carries **real observed output**, not illustrative versions. The front matter says so plainly:

> `verified_on: "✅ Fully executed on Ubuntu 26.04 LTS / WSL2, Intel i7-11850H, 2026-08-25."`

I also recorded your real toolchain versions in `VerificationRuns.md` as a reference table — chapter front matter has to state the exact toolchain each chapter was written against, and now it can.

## 👤 Git identity updated

```text
user.name  = Karthikeyan Kasvishwanathan
user.email = Karthikeyan.KLU@gmail.com
```

Set locally on this repository, applied from this commit onward. The two earlier commits stay under `Tyrostir` — rewriting history would break the published GitHub commits for no benefit.

> ⚠️ **One thing worth a second look before this goes public.** You wrote **"Kasvishwanathan"**, but your account email is `karthikeyankasi**vi**shwanathan@` — which suggests **"Kasivishwanathan"**, with an `i` after `Kas`. I've set exactly what you typed. Say the word if it should be the other spelling and I'll correct it before you push.

## 📥 `toAgent/` is now a documented convention

Dropping output in a file rather than pasting into chat is better — it's faithful, and it's version-controlled evidence. I gave it a `README.md` marking it **Tier 3** (internal, excluded from the book), a naming convention (`<n>.<WhatItIs>.md`), and an index. Your Block V1 drop is entry 1.

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_01_Prerequisites.md` | → **v2.0 verified.** Markers cleared; real output throughout; §9.2 rewritten; path corrected |
| `docs/internal/VerificationRuns.md` | V1.0–V1.6 → ✅; real-versions reference table; results log entry |
| `docs/meta/DecisionsLog.md` | Session 004: 4 verifications (guide executed, R9 closed, R3 closed, path corrected) + Git identity |
| `docs/meta/CourseState.md` | Session 004 log; environment snapshot all-green; M2 in progress; next action rewritten |
| `docs/meta/CompactContext.md` | Regenerated: real versions, 0 failures, R3/R9 closed |
| `docs/meta/ToDos.md` | T-008, T-009, T-145 closed; T-144 added |
| `docs/internal/CLAUDE-MEMORY.md` | Session 004 row; hazards H-3/H-4/H-5 updated; identity recorded |
| `toAgent/README.md` | **Created** — Tier 3 drop convention and index |
| `docs/internal/README.md`, `NewAgentOnboardingGuide.md`, `tools/build-pdf.sh` | `toAgent/` added to the Tier 3 map |
| `docs/guides/Setup_02_*.md` | Repo path corrected |

Leak scan across Tier 1 and Tier 2: **clean**.

---

## 🔴 One thing is now blocking everything

**The QNX licence request — V2.1 — has still not been submitted.**

Your host is completely ready. There is nothing else to prepare, and nothing further I can verify. Setup Guide 02 blocks V2–V4 all sit behind licence approval, whose latency is unknown (**Risk R1**) and is now the *only* live risk in the project.

👉 **https://www.qnx.com/getqnx** — fifteen minutes. Then send me:

- what the form actually asked for
- **how long approval took** (this turns R1 from unknown into documented)
- the real button labels for **accept** and **deploy** — that's the step that silently breaks everyone's install

Once it's deployed, blocks V3 and V4 will clear Setup Guide 02, and Chapter 00 comes off hold.

### Artefacts changed

*(See the table above.)*

---

## PROMPT#4

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 005 |
| **Context** | Immediately after the Block V1 verification of [PROMPT#3](#prompt3). |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> 1. "Karthikeyan Kasivishwanathan" is correct, need 'i' after "Kas". 2. I have already deployed the license with my mail id. You can consider V2.1, V2.2, V2.3 are complete.

### Standing instructions

| # | Instruction | Recorded as |
|---|-------------|-------------|
| SI-9 *(corrected)* | Git commit identity is **`Karthikeyan Kasivishwanathan <Karthikeyan.KLU@gmail.com>`** — note the **`i` after `Kas`**. | `git config --local`; `DecisionsLog.md` Session 005 |
| SI-11 | The learner may **attest** that a verification block is complete without pasting output. Treat the attestation as clearing the block, while being explicit in the documents about which detail was and was not captured. | `VerificationRuns.md` V2; `Setup_02` §§3–5 |

### Response (full)

> *Reproduced as delivered.*

---

Both done. **Risk R1 is closed — and that was the last external blocker in the entire project.**

## 1️⃣ Spelling corrected, including in history

```text
user.name  = Karthikeyan Kasivishwanathan
user.email = Karthikeyan.KLU@gmail.com
```

The commit carrying the misspelling was still unpushed, so I re-authored it in place rather than leaving it wrong:

```text
348f17f  Karthikeyan Kasivishwanathan <Karthikeyan.KLU@gmail.com>   ← corrected
afc583b  Tyrostir <19234119+...>
79029c2  Tyrostir <19234119+...>
```

The two `Tyrostir` commits are already on GitHub and stay as they are — rewriting published history would break their links for no benefit.

## 2️⃣ Block V2 complete — and the project just changed shape

| Checkpoint | State |
|---|---|
| **V2.1** request | ✅ |
| **V2.2** approval | ✅ |
| **V2.3** accept **and deploy** | ✅ **deployed** |

**T-003 and T-010 closed. Risk R1 closed.**

That last one matters more than it looks. R1 was the only risk in the project rated *Blocking*, and it was the reason the whole course was sequenced around waiting — Part 0 was deliberately placed first *because* it needs no software, and the plan's timeline budgeted dead time for licence approval. **That constraint is gone.** Every remaining step is under our own control.

Three of the four highest risks are now closed:

| Risk | Status |
|---|---|
| ~~R1 licence latency~~ | ✅ closed (this session) |
| ~~R3 KVM under WSL2~~ | ✅ closed (Session 004) |
| ~~R9 Ubuntu 26.04 package drift~~ | ✅ closed (Session 004) |
| **R2 — QSC install on WSL2** | 👉 next to be tested, in block V3 |

## 📕 Setup Guide 02 → v1.1

`[UNVERIFIED]` cleared from **§§3–5** (account → request → accept → deploy). The header notice now scopes the remaining markers precisely to **Part B**, §§7–11: Software Center, SDP install, environment setup, verification.

I kept the clearance honest rather than overstating it:

> ✅ **Confirmed by a real run (2026-08-26).** The flow documented here is accurate. Exact on-screen wording is not transcribed — QNX changes portal copy without notice, so follow the *meaning* of each step rather than hunting for an exact button label.

**Two details you didn't capture, and neither blocks you:**

- **How long approval took.** Chapter 04 currently cannot tell a reader whether to expect minutes or a week — the honest answer is "we don't know". Your data point is the only way to fix that.
- **The real button labels for accept and deploy.** This is the step that silently breaks everyone's install; if §5's wording doesn't match what you actually saw, tell me and I'll correct it.

Logged as **T-014**, priority 🔵 — answer whenever, or never.

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_02_QNX_Account_And_License.md` | → **v1.1.** §§3–5 confirmed; header notice re-scoped to Part B |
| `docs/internal/VerificationRuns.md` | V2.1–V2.3 → ✅; §3 rewritten as a status board; V3 unblocked; results log entry |
| `docs/meta/DecisionsLog.md` | Session 005: licence flow verified · **R1 closed** · identity spelling revised |
| `docs/meta/CourseState.md` | Session 005 log; licence row ✅; next action → V3; no external blockers |
| `docs/meta/CompactContext.md` | Regenerated: R1/R3/R9 struck through, R2 now the live risk |
| `docs/meta/ToDos.md` | T-003, T-010, T-146 closed; T-011 promoted to 🔴 and unblocked; T-014 added |
| `docs/internal/CLAUDE-MEMORY.md` | Session 005 row; H-5 closed; H-3 narrowed to Part B; identity spelling noted |

Leak scan across Tier 1 and Tier 2: **clean**.

---

## 👉 Next: Block V3 — install the SDP

Nothing gates it. [Setup Guide 02 Part B](docs/guides/Setup_02_QNX_Account_And_License.md#part-b--install-the-software) — roughly 60–90 minutes, ~10 GB download.

**The one command I most want back** is this, from V3.3:

```bash
host$ cd ~/qnx/qnxsoftwarecenter
host$ ./qnxsoftwarecenter_clt -listAvailablePackages
```

It does triple duty: it proves the licence deployed correctly, it gives us the exact **SDP build number** that every chapter's front matter has to record (T-202), and if it comes back **empty** it means the deploy didn't take — in which case we go back to the dashboard rather than fighting the installer.

Then **V4** — ten minutes — cross-compiles a binary and watches Linux refuse to run it. That failure is the proof, and it's the moment the course becomes real.

**Watch out for R2 on the way:** QNX Software Center is an Eclipse app, and the GUI under WSL2 is the most likely thing to misbehave. If the graphical installer doesn't open, §8.3 has the headless route (`./qnx-setup-*.run -- --unattended`). Either way, tell me which one you needed — that's exactly the kind of thing the guide should state as fact rather than offer as two options.

Once V3 and V4 land, Part B's markers clear and **Chapter 00 comes off hold**.

### Artefacts changed

*(See the table above.)*

---

## PROMPT#5

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 006 |
| **Context** | The learner completed the remaining verification blocks and pushed the repository to GitHub. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> FYI: I manually pushed the commits. I have completed Block V2, V3, and V4. You can check toAgent/2.BlockV2V3V4Output.md file for confirmation.

### Standing instructions

| # | Instruction | Consequence |
|---|-------------|-------------|
| SI-12 | The learner pushes to GitHub themselves. The author commits; it does not push. | History is published from commit `79029c2` onward — **do not rewrite it.** |

### Response (full)

> *Reproduced as delivered.*

---

Read it. **All four verification blocks are done, both setup guides are verified end to end, and the course now has zero `[UNVERIFIED]` markers.**

`check-environment.sh`: **24 passed · 3 warnings · 0 failed** — and the three warnings are just the optional PDF toolchain.

```text
13 · 9 · 3   →   19 · 6 · 0   →   24 · 3 · 0
   start        after Setup 01     now
```

## ✅ What you proved

| | |
|---|---|
| **SDP 8.0** | `~/qnx800` · licence at `~/.qnx/license/licenses` |
| `$QNX_HOST` | `~/qnx800/host/linux/x86_64` |
| `$QNX_TARGET` | `~/qnx800/target/qnx` |
| **Cross-compiler** | **GCC 12.2.0** — not your host's 15.2.0; a completely separate compiler |
| **Targets** | `gcc_ntox86_64` *(default)*, `_gpp`, `_cxx` · `gcc_ntoaarch64le`, `_gpp`, `_cxx` |
| **The proof** | Binary built → `file` shows `interpreter /usr/lib/ldqnx-64.so.2` → Linux refuses: `cannot execute: required file not found` |

**That last line is the whole point of the setup.** You built a program your own computer cannot run. It needs `ldqnx-64.so.2`, QNX's dynamic linker, which doesn't exist on Linux. It will run the moment you have a QNX target — which is Setup Guide 03.

Your `qcc -V` output was more informative than I'd predicted, so I expanded §11.1 around it: **only two architectures exist** in QNX 8.0 (`x86_64`, `aarch64le`), and the `_gpp`/`_cxx` suffixes are the two C++ front ends. That's the entire target world of the OS, visible in six lines.

## 🐛 Running the guide found three real bugs

This is the `[UNVERIFIED]` protocol earning its keep. All three were plausible, sourced from official documentation, and **wrong** — no amount of further reading would have caught them.

**1. My sample program was broken.** §11.2 called `getpid()` with no `#include <unistd.h>`, and the guide claimed the expected output was *"nothing at all"*. You got:

```text
warning: implicit declaration of function 'getpid' [-Wimplicit-function-declaration]
```

Fixed — and I turned it into a lesson worth having early, because it's a misconception that costs QNX beginners real time:

> `<sys/neutrino.h>` is the **QNX-specific** header — `MsgSend`, `ChannelCreate`, `InterruptAttach`. Ordinary POSIX calls like `getpid`, `read`, `write` and `sleep` live in the **standard** POSIX headers, exactly where they do on Linux. QNX is POSIX-compliant; reach for `<sys/neutrino.h>` only when you want something Linux doesn't have.

**2. I told you to look for the word "QNX" in `file` output. It never prints it.** QNX uses the System V ELF ABI, so `file` says `SYSV` — the same as Linux. The *only* difference `file` can see is the interpreter path. Corrected, and I added the two other details your output revealed: `pie executable` (that's what makes ASLR possible — Chapter 28) and `with debug_info, not stripped` (that's why you'll be able to set breakpoints by function name in Chapter 08 without rebuilding).

**3. The disk estimate was off by about 4×.** Documented as 8–12 GB; you went from **951 GB free to 908 GB — about 43 GB**. A full SDP pulls both target architectures plus debug symbols for everything. New §12.1 in Setup Guide 02, and `PLAN.md`'s total budget corrected from ~25 GB to **~50 GB**.

## 🎉 Risk register — four of five closed

| Risk | Status |
|---|---|
| ~~R1 licence latency~~ | ✅ closed |
| ~~R2 QSC install on WSL2~~ | ✅ **closed this session** |
| ~~R3 KVM under WSL2~~ | ✅ closed |
| ~~R9 Ubuntu 26.04 package drift~~ | ✅ closed |
| **R5 version drift** | ⬜ open — needs the SDP build number |

**No risk in this project has an external dependency any more.**

## 📌 Two things you didn't capture

Neither blocks anything, both are worth a minute when convenient.

**1. The SDP build number — T-202, and this one has teeth.** `PLAN.md` §5 requires every chapter's front matter to record the exact SDP build it was written against; that's the entire mitigation for Risk R5. Right now no chapter can state it.

```bash
host$ ~/qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt -listAvailablePackages
```

**2. Did QNX Software Center install graphically or headlessly?** §8 still offers both routes as equals. It should state the one that actually works under WSLg and keep the other as a fallback. (Same item: how long licence approval took, and the real accept/deploy button labels.)

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_02_QNX_Account_And_License.md` | → **v2.0 verified.** All markers cleared; real output throughout; 3 bugs fixed; new §12.1 on disk cost |
| `docs/PLAN.md` | → v1.2. Disk budget ~25 GB → **~50 GB** |
| `docs/internal/VerificationRuns.md` | V3/V4 → ✅; SDP toolchain reference table; the three bugs recorded |
| `docs/meta/DecisionsLog.md` | Session 006: SDP verified · 3 bugs · **R2 closed** · T-202 opened · history published |
| `docs/meta/CourseState.md` | Session 006 log; SDP row ✅; both guides verified; nothing blocking |
| `docs/meta/CompactContext.md` | Regenerated with the full SDP toolchain block |
| `docs/meta/ToDos.md` | T-011, T-012, T-141, T-144, T-200 closed · T-202 promoted · **T-102 off hold** · T-112 unblocked |
| `docs/internal/CLAUDE-MEMORY.md` | Session 006 row; H-3 closed; **H-8 added** (SDP build number) |
| `toAgent/README.md` | Drop 2 indexed |

Leak scan across Tier 1 and Tier 2: **clean**.

---

## 👉 Your call — Chapter 00 or Setup Guide 03?

The gate you set in PROMPT#2 is satisfied: onboarding is done, and every `[UNVERIFIED]` marker is cleared. **Chapter 00 is off hold.** Setup Guide 03 is also unblocked — it was waiting for exactly this, a real SDP to test against.

| | | |
|---|---|---|
| **A** | 📕 **Chapter 00 — How To Use This Course** | The planned next step. Conventions, symbols, how labs work, how to pick a path. No software needed, and it sets the template every later chapter follows. |
| **B** | ⭐ **Setup Guide 03 — The QEMU VM** | The shortest path to a `qnx#` prompt. It's the critical-path document (T-112, ⭐ core lab L06) and turns your `No bootable device` from Block V1 into a booting QNX system. |

**My recommendation: B, Setup Guide 03.** You have momentum, a fully working toolchain, and a binary sitting there that nothing can run yet. Booting the VM closes that loop and reaches milestone **M2 "It boots" 🎉**. Chapter 00 is short, needs nothing, and reads better once you've actually seen the system it describes.

Say the word — or "A" if you'd rather have the map before the territory.

### Artefacts changed

*(See the table above.)*

---

## PROMPT#6

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 007 |
| **Context** | Offered a choice between Chapter 00 and Setup Guide 03 at the end of [PROMPT#5](#prompt5). |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Go for B now

### Standing instructions

*(None new — this selects option B, Setup Guide 03, from the two offered.)*

### Response (full)

> *Reproduced as delivered.*

---

**Setup Guide 03 is published** — 729 lines, written from QNX's official *QSTI for QEMU* documentation, which I read live rather than reconstructing from memory. It ends where it should: with the binary you built in Setup Guide 02 running on a QNX target.

## 🔍 The finding that changed the guide

**QSTI and `mkqnximage` are not alternatives.** ADR-004 reads as though QSTI replaced `mkqnximage`. It didn't:

| | |
|---|---|
| **QSTI** | The **image** — a pre-built QNX system. QSC package `com.qnx.qnx800.quickstart.qemu` → `~/qnx800/images/qemu` → `./unpack_qemu_image.sh` → `output/ifs.bin` + `output/disk-qemu.vmdk` |
| **`mkqnximage`** | The **launcher** — `--run`, `--stop`, `--getip`. It's how QNX's own QSTI guide starts the image. |

ADR-004's strategy is unchanged — QSTI → CTI → raw `mkifs` still stands — but the mechanics differ from what was assumed. I logged this explicitly so no future author "corrects" the guide into avoiding `mkqnximage`.

## 📕 What the guide covers

**The path:** install the QSTI package → unpack → understand the launch command → boot → log in (`root`/`root`) → look around with `pidin` → get an IP and SSH in → **`scp` your binary across and run it** → shut down cleanly.

Per course rule #4, §6 documents what `mkqnximage --run` actually starts, flag by flag:

| Setting | Default |
|---|---|
| Kernel / disk | `ifs.bin` · `disk-qemu.vmdk` (IDE) |
| CPUs / RAM | 8 · 4 GB — ⚠️ QNX warns **above 16 GB may misbehave** |
| Network | `bridge,br=virbr0` |
| Display | `sdl,gl=on`, default `1280 × 768 @ 60` |
| Serial | `mon:stdio` — which is *why* `Ctrl+A` `X` quits |

§8 turns the first five commands into teaching rather than typing. `pidin` gets a 🐧 In-Linux box explaining what it shows that `ps` cannot — each thread's blocking state (`REPLY`, `RECEIVE`, `SEND`), the column you'll live in from Chapter 13. And listing the processes *is* the microkernel argument: filesystem and network drivers appear there as ordinary user-space processes, not kernel code.

§10 is the payoff, and I wrote it as a moment rather than a step:

> You wrote C on Linux, compiled it into a binary your own machine physically cannot execute, moved it across a virtual network into a different operating system, and ran it there. That is the complete embedded development loop — **edit → cross-compile → deploy → run**.

## ⚠️ Three WSL2 problems I've predicted, not observed

§12 documents them honestly as predictions. The first is the one I'd bet on:

**Networking — the `virbr0` bridge.** QSTI defaults to bridged networking via `virbr0`, which **libvirt** creates as a **systemd** service. WSL2 doesn't enable systemd by default, so the bridge may never exist and the VM may boot with no IP.

Three fallbacks, in order: enable systemd via `/etc/wsl.conf`; start the network by hand (`sudo virsh net-start default`); or drop to QEMU user-mode NAT with port forwarding — which you've already seen working, since that's where `10.0.2.15` came from in Block V1. Note port **8000** in that fallback: that's `qconn`, the remote-debug agent you'll need in Chapter 08.

The other two: `sdl,gl=on` under WSLg may fall back to software or fail (harmless — every lab is text), and hosts with **>32 GB RAM** hit a graphics failure needing `host-phys-bits-limit=39`. You have 23 GB, so that one shouldn't apply.

## 🎁 One piece of good news

QNX supports **Ubuntu 22.04/24.04** and tells those users to **build QEMU 10 from source**. You're on 26.04 with **QEMU 10.2.1 from `apt`** — you skip that entire ordeal. Risk R9, being ahead of the documented platform, working in your favour for once. §2.2 says so explicitly so you don't go hunting for a build step you don't need.

## 🛠️ Also shipped: `tools/qemu/qnx-vm.sh`

`run` · `stop` · `ip` · `ssh` · `status`. Deliberately thin — it does nothing `mkqnximage` can't. It exists to fail with a useful message instead of `command not found`, source the SDP environment if you forgot, and remember the image directory.

**§7.2 tells you to use the real commands first.** A wrapper introduced before you understand what it wraps is exactly the black box this course promises not to create.

---

## 👉 Your next run: Block V5 — 7 checkpoints

Everything in Setup Guide 03 is `[UNVERIFIED]`. Given that Setup Guide 02 yielded three real bugs, and this guide touches networking, graphics *and* nested virtualization on an undocumented host — **expect at least one thing here to be wrong.**

| | | |
|---|---|---|
| **V5.1** | Install the QSTI package | Also gives us the **SDP build number** — closes T-202 |
| **V5.2** | Unpack | Confirms the real archive and output names |
| **V5.3** | **Boot** 🎉 | 📋 **Paste the entire boot log** — the single most valuable artefact in this block |
| **V5.4** | `pidin`, `/proc/boot` | Becomes course material for Chapters 09 and 21 |
| **V5.5** | Networking + SSH ⚠️ | **The predicted trouble spot.** Tell me which route worked |
| **V5.6** | **Run `hello_qnx`** 🎉 | Proves the whole loop end to end |
| **V5.7** | Graphics + shutdown | Did an SDL window open under WSLg? |

**V5.3 is milestone M2 — "It boots" 🎉.**

The full block with exact commands is in `docs/internal/VerificationRuns.md` §7a. Anything that errors, send it as-is — I'll diagnose it, fix the guide, and log a `D-NNN`.

Once V5 lands, Setup Guide 03's markers clear and **Chapter 00 is next**.

### Artefacts changed

| File | Change |
|------|--------|
| `docs/guides/Setup_03_QEMU_VM.md` | **Created** — 729 lines, 15 sections, v1.0 |
| `tools/qemu/qnx-vm.sh` | **Created** — thin `mkqnximage` wrapper, syntax-checked and smoke-tested |
| `docs/internal/VerificationRuns.md` | **Block V5 added** — 7 checkpoints; status board and §3 updated |
| `docs/meta/DecisionsLog.md` | Session 007: QSTI/`mkqnximage` distinction · QSTI's QEMU defaults · the 26.04 advantage · predicted bridge failure · the wrapper convention |
| `docs/meta/CourseState.md` | Session 007 log; 3/5 guides published; next action → V5 |
| `docs/meta/CompactContext.md` | QSTI mechanics recorded for future sessions |
| `docs/meta/ToDos.md` | T-112 closed; T-015 (run V5) and T-147 (clear its markers) added |
| `docs/internal/CLAUDE-MEMORY.md` | Session 007 row; **H-9** added (the `virbr0` prediction) |
| `docs/reference/ReferenceLinks.md` | QSTI links re-verified 2026-08-26 with findings |
| `docs/TableOfContents.md` | Setup Guide 03 → 📕 Published |

---

## PROMPT#7

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 008 |
| **Context** | The learner ran verification block V5 and was blocked at V5.3, the first boot attempt. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I have tried to execute V5 and I am stuck at V5.3. Can you see the log from toAgent/3.BlockV5.1V5.3-StuckAtV5.3.md file? (Try to document the "/btw" questions as well)

### Standing instructions

| # | Instruction | Recorded as |
|---|-------------|-------------|
| SI-13 | A question prefixed **`/btw`** — in a message or on its own line in a `toAgent/` drop — becomes a `D-NNN` entry in `Doubts.md`, however small or tangential. | **ADR-025** |

> ⚠️ **Note.** The drop file contained no `/btw` lines. The convention has been established and
> documented in `Doubts.md` and `toAgent/README.md`; the three technical questions the run raised
> were logged as D-006/007/008 regardless, under ADR-014.

### Response (full)

> *Reproduced as delivered.*

---

Found it. **Nothing is broken — you're one directory too high.**

## 🎯 The fix

```bash
host$ cd ~/qnx800/images/qemu/qemu     # ← "qemu" twice
host$ ls                                # you should see:  local  output
host$ mkqnximage --run
```

`unpack_qemu_image.sh` doesn't extract into the current directory — every path it wrote begins `qemu/`. So your image is at `~/qnx800/images/qemu/qemu`, and you ran `mkqnximage` from its parent.

`mkqnximage` identifies an image directory by finding `local/` and `output/` in it. From one level up it saw two archives and a shell script — not an image, not empty — so it stopped and asked.

## 🚨 Do not use `--force`, even though the error tells you to

This is the part worth reading twice.

`--force` doesn't mean *"run anyway"*. It means **"yes, create a brand-new virtual image in this unusual location"**. It would have started building a fresh image beside your archives and ignored the 47 GB one you'd just unpacked — a long wait ending in the wrong result.

> An error message tells you what the program *believes*, and offers the escape hatch for the case where the program is wrong. Here the program was right and your working directory was wrong. Reach for the suggested flag only once you understand why the tool objected.

## 🐛 Your run found three bugs

**1. The nested `qemu/` directory — D-006.** QNX's docs say to unpack and then run `mkqnximage --run` "from the qemu folder", never mentioning the script *creates* a nested `qemu/`. From the documentation alone the instruction looks complete. §5 now carries a tree diagram, and §7 quotes your exact error with the `--force` warning.

**2. `-listAvailablePackages` doesn't exist — D-007.** My error, and an old one: it was written into Setup Guide 02, carried into Setup Guide 03, and quoted in three tracking documents as the command that would close T-202. It never would have. Verified against CLT `2.0.4:v202501021438`, the real options are:

| Option | Lists |
|---|---|
| `-list` | Everything |
| `-listAccessible` | What your licence entitles you to ⭐ |
| `-listInstalled` / `-listInstalledRoots` | What you already have |
| `-listQuery <query>` · `-listUpdates` | Search · updates |

Also: `-installPackage` is for one package; `-installBaseline` is for a whole SDP.

**3. The 47 GB `disk-qemu` was undocumented — D-008.** That's the VM's virtual disk, and 47 GB is its *apparent* size. It's very likely **sparse** — `ls -lh` shows what the guest thinks it has, `du -sh` shows what your disk actually lost. Worth knowing: copying a sparse file with a naive tool expands every hole into real zeros. If you ever move it, use `cp --sparse=always` or `rsync -S`.

## 💡 What your listing revealed — this is the good part

Your `ls -lh qemu/output/` is more interesting than a directory listing has any right to be:

| File | Why it matters |
|---|---|
| `procnto-smp-instr.sym` | The kernel's name tells you the variant: **SMP** and **instrumented** — the build that supports kernel event tracing. That's what makes Chapter 26's System Analysis Toolkit work. You're not running a cut-down kernel. |
| `output/build/` | ⭐ `ifs.build`, `system.build`, `disk.layout`, `startup.sh` — **the actual `mkifs` build files that produced this image**. Chapter 21's source material, already sitting on your disk. |
| `option_files/` | `opt_valgrind`, `opt_secpol`, `opt_python`, `opt_graphics`… — the CTI feature switches. This is the "build your own image" machinery ADR-004 promised. |

Take one look inside `build/` when you're there. It'll mean little now; in Chapter 21 you'll write one yourself, and knowing this image was made the same way is the point.

**One more thing:** the QSTI package was **already installed** with SDP 8.0 — the archives were dated from your V3 run. The whole Software Center detour was unnecessary. §4.2 now says to check `~/qnx800/images/qemu` first.

## 💬 About the `/btw` questions

**There were no `/btw` lines in the file** — nothing was lost, but if you meant to include some, they didn't make it.

I've made the convention real regardless. Put `/btw <question>` on its own line — in a message, or anywhere inside a `toAgent/` drop — and it becomes a permanent `D-NNN` entry, however small. That's now **ADR-025**, documented in both `Doubts.md` and `toAgent/README.md`.

> **Why a marker at all?** Every question is logged anyway (ADR-014). The prefix removes ambiguity: it says *this is a question, and I want it in the record* — for the ones asked in passing, mid-task, that otherwise read as rhetorical asides. Those are exactly the ones that get lost.

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_03_QEMU_VM.md` | → **v1.1.** §§4–5 marked ✅ verified: real listings, the nested-directory tree, what each artefact is; §7 `cd`s correctly and carries the error + `--force` warning |
| `docs/guides/Setup_02_QNX_Account_And_License.md` | → v2.1. `-listAvailablePackages` corrected |
| `docs/meta/Doubts.md` | **+D-006, D-007, D-008** — full answers · **`/btw` convention documented** |
| `docs/meta/Decisions.md` | **+ADR-025** |
| `docs/meta/DecisionsLog.md` | Session 008: the nested-directory trap · the bogus option · the image contents · ADR-025 · open disk-budget revision |
| `docs/internal/VerificationRuns.md` | V5.1–V5.2 ✅, V5.3 blocked→fixed, results logged |
| `docs/meta/CourseState.md`, `CompactContext.md`, `ToDos.md` | Session 008; T-015 re-scoped to the retry; T-016, T-017 added |
| `docs/internal/CLAUDE-MEMORY.md` | Session 008 row; **H-10** — check CLT option names against `-help`, never assume |
| `tools/qemu/qnx-vm.sh` | Default image path corrected to the nested `qemu/qemu` |
| `toAgent/README.md` | Drop 3 indexed; `/btw` documented |

---

## 👉 Retry V5.3

```bash
host$ cd ~/qnx800/images/qemu/qemu
host$ mkqnximage --run
```

Log in with `root` / `root`. **Paste the entire boot log** — it's the most valuable artefact in this block, and Chapters 09 and 21 dissect it line by line.

Then keep going through V5.4 (`pidin`, `/proc/boot`), V5.5 (networking — the `virbr0` bridge is still my predicted trouble spot), V5.6 (**run `hello_qnx` on the target** 🎉) and V5.7.

Two small extras while you're in there:

```bash
host$ du -sh ~/qnx800/images/qemu/qemu/output/disk-qemu   # is it sparse?  (T-016)
host$ df -h ~
host$ cat ~/qnx800/images/qemu/README.md                  # 394 bytes  (T-017)
```

**Reaching that `#` prompt is milestone M2 — "It boots" 🎉.**

---

## PROMPT#8

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 009 |
| **Context** | The learner retried V5.3 with the D-006 fix, reached a booting VM, and was blocked at V5.5 (SSH). |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I executed V5.3 to V5.5 and I am stuck at V5.5. Please refer  toAgent/5.BlockV5.3V5.5-StuckAtV5.5.md file

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 🎉 Milestone M2 — QNX boots

```text
QNX qnxqemu 8.0.0 2026/02/27-11:02:56EST x86pc x86_64
Processes: 31, Threads: 207    FreeMem: 3659MB/4095MB    8 processors
vtnet0: inet 192.168.122.46
```

The `#` prompt in that log is a real QNX microkernel system running on your laptop. Everything from Chapter 06 onwards is now executable.

## 🎯 Your blocker: `sshd` refuses root — use `qnxuser`

```bash
host$ ssh qnxuser@192.168.122.46
qnx$  sudo -i
```

**Your password was never wrong.** `root`/`root` works at the console because `login` checks the shadow file. SSH fails because **`sshd` rejects root before the password is even considered**.

Since OpenSSH 7.0 the shipped default is `PermitRootLogin prohibit-password`: root may authenticate with a **key**, never with a password. Your error message says so, if you read it precisely —

```text
Permission denied (publickey,password).
```

— that lists the methods the *server* offered. Password was on offer, just not for root.

**Why `qnxuser`?** Your own login banner gave it away three times: the VNC server's default password is `qnxuser`, the image ships a `sudoers` config, and the banner tells you to run `sudo apk update` — advice that only makes sense for a non-root account.

If the name turns out to be something else, the target will tell you:

```bash
qnx# cat /etc/passwd
qnx# grep -iE 'PermitRootLogin|PasswordAuthentication' /etc/ssh/sshd_config
```

Two alternatives are in §9.4 (`PermitRootLogin yes` — may not survive a reboot) and §9.5 (**use a key** — do this now; Chapter 08 runs `gdb` across this link and a password prompt in that loop gets old fast). Logged as **D-009**.

⚠️ **`scp` runs over SSH**, so V5.6 needs `scp hello_qnx qnxuser@192.168.122.46:/tmp/` too.

## ✅ I was wrong about the networking

I predicted the `virbr0` bridge would be the most likely failure in the whole guide — libvirt needs systemd, WSL2 doesn't enable it. **It worked first try**, on libvirt's default `192.168.122.0/24` subnet. Installing `libvirt-daemon-system` back in Setup Guide 01 was enough.

Hazard **H-9 closed**, §12.1 downgraded from "most likely failure" to a contingency, with the success stated up front so nobody troubleshoots a problem they don't have. The fallbacks stay — they're correct, just unnecessary here.

## 😌 Those boot errors are all harmless — D-010

Four alarming lines, none of them a problem:

| Message | Reality |
|---|---|
| `ACPI table not found` | QEMU's firmware doesn't present it; QNX falls back and carries on |
| `Unable to start "uname" (2)` | Error 2 is `ENOENT` — a script called `uname` before the disk was mounted. Cosmetic |
| `slog2_api: cannot connect to slogger2` | The logger hadn't started **yet**. The next line literally says it'll retry |
| `rm: /etc/ca-certificates/extracted` | Cleanup script tidying a file that was never there |

> **A habit worth forming:** early-boot complaints about services that start *later* are almost always ordering noise. The ones worth chasing appear **after** that subsystem started — or stop the boot entirely.

## 💎 Your `pidin` output is the best teaching material in the course so far

I rewrote §8 around it. Three things it shows that no amount of documentation could:

**1. Drivers are ordinary processes.** `devb-eide` (disk), `io-sock` (the entire TCP/IP stack), `io-usb-otg` (USB), `devc-ser8250` (serial), `drm-virtio` (graphics) — every one has a PID. On Linux all five are kernel code. Only `procnto` is the kernel here. **That's the microkernel argument, and it needs no prose.**

**2. The 256-priority scale, visibly in use.** `0f` idle → `10r` services → `21r`/`25r` drivers → `254i`/`255i` kernel interrupt threads. Chapter 11 explains it; your listing demonstrates it.

**3. Live message passing, in the `REPLY` column:**

```text
397328  1 system/bin/fullscreen-winmgr  10r REPLY  249881   ← waiting on screen
249881 13 system/bin/screen             10r REPLY  184343   ← waiting on io-hid
```

A chain of synchronous `MsgSend` calls, visible in one column, on a system nobody instrumented. That is Chapter 13's entire subject, already running.

**And the detail I enjoyed most** — your `ls /proc/boot` contains:

```text
ldqnx-64.so.2
```

That's the exact file your Linux machine couldn't find in Setup Guide 02 when it refused to run your binary. **It was never missing. It was just on the wrong computer.** It lives in the boot image, and it's why `hello_qnx` will run in V5.6.

I also documented `slm` — QNX's answer to `systemd`, 22 components on your image, configuration in a single readable `slm.cfg`. **`qconn` is one of them**, already listening on port 8000, so Chapter 08's remote debugging needs nothing installed.

## 📕 Setup Guide 03 → v1.2

**§§4–9 are now ✅ verified**, with real output throughout: the boot log with the four warnings explained, the real login banner (`apk`, VNC, the `sudo` hint), real `uname`/`pidin`/`pidin info`/`ls /proc/boot`, real `ifconfig` with `vtnet0`/`pflog0`/`enc0` explained, and §9.3 built entirely around the SSH refusal.

**Only §§10–11 remain unverified** — the last two steps in the guide.

Bonus: **T-202 is partly answered.** The kernel reports its build as `2026/02/27-11:02:56EST`, which is the version identity chapter front matter needs.

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_03_QEMU_VM.md` | → **v1.2.** §§4–9 verified; §7 boot log + warnings; §7.1 real banner; §8 rewritten around `pidin`; §9 rewritten around the SSH fix; §12.1 downgraded; §13.4a added |
| `docs/meta/Doubts.md` | **+D-009** (SSH refuses root by design) · **+D-010** (benign boot warnings) |
| `docs/meta/DecisionsLog.md` | Session 009: M2 · **H-9 closed as a failed prediction** · the SSH refusal · `pidin` as course material |
| `docs/internal/VerificationRuns.md` | V5.3–V5.5 ✅ · **verified QNX target facts table** for chapter front matter |
| `docs/meta/CourseState.md` | **M2 dated 2026-08-26**; VM booting ✅; Session 009 |
| `docs/meta/CompactContext.md` | Verified target facts recorded for future sessions |
| `docs/meta/ToDos.md` | T-015 → V5.6–V5.7; **T-018** added (confirm the SSH account); T-202 downgraded |
| `docs/internal/CLAUDE-MEMORY.md` | Session 009; **H-9 closed, H-11 opened** (SSH must use `qnxuser`) |
| `toAgent/README.md` | Drop 4 indexed |

---

## 👉 Finish V5.6 — you're two commands away

```bash
host$ scp /tmp/hello_qnx qnxuser@192.168.122.46:/tmp/
host$ ssh qnxuser@192.168.122.46
qnx$  cd /tmp && chmod +x hello_qnx && ./hello_qnx
```

Expected:

```text
Hello from QNX!
My process ID is <pid>
```

**That's the whole loop closed** — written on Linux, compiled by a cross-compiler into a binary your own machine physically refuses to run, moved across a virtual network, executed on a real-time microkernel.

Then V5.7: `mkqnximage --stop` (from `~/qnx800/images/qemu/qemu`) or `Ctrl+A` `X`.

And while you're logged in, one small thing that settles **T-018**:

```bash
qnx# cat /etc/passwd
```

`qnxuser` is my inference from the banner, not something I've proven.

**After that, Setup Guide 03 is fully verified and Chapter 00 is next.**

---

## PROMPT#9

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 010 |
| **Context** | The learner completed the final two checkpoints of block V5, closing the environment phase. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I executed V5.6 and V5.7, output in toAgent/5.BlockV5.5V5.7-NoteOnPasswordAtV5.5.md - please read once. So with this, V5 is completed.

Accompanying observations, in the drop file:

> 1. During ssh "qnxuser" was working fine but the password was "qnxuser".
> 2. Same way, even for the ssh as "root", surprisingly using "qnxuser" as password was working. I don't know why.
> 3. I hope the output of below commands make some sense to you. You may can explain what is there and not there.
> 	"cat /etc/passwd" and "grep -iE 'PermitRootLogin|PasswordAuthentication' /etc/ssh/sshd_config"

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# ✅ Phase 1 complete — the loop is closed

```text
[root@qnxqemu /tmp]# ./hello_qnx
Hello from QNX!
My process ID is 14032920
```

You wrote C on Linux, compiled it with a cross-compiler into a binary your own machine physically refuses to run, moved it into a different operating system, and executed it there. **Block V5 complete. Milestone M2 complete. Phase 1 complete.**

**Setup Guide 03 → v2.0.** All three published setup guides are now verified end to end, and **the course carries zero `[UNVERIFIED]` markers.**

## ✏️ A correction — my D-009 explanation was wrong

I told you `sshd` was using `PermitRootLogin prohibit-password`. Your grep shows otherwise:

```text
PermitRootLogin no
PasswordAuthentication yes
```

**The difference is actionable, not cosmetic.** Under `prohibit-password`, root can still log in *with a key* — and §9.5 told you exactly that. Under **`no`**, root is refused by **every** method, keys included. That advice would simply not have worked. Fixed in the guide and in D-009.

Same lesson as D-007: a plausible, well-known default is not the value in the file in front of you.

## 🔍 Your question 3 — reading those two files

Logged in full as **D-011**. The short version:

**`/etc/passwd` — what's there:**

| Detail | What it tells you |
|---|---|
| Homes under **`/data/home/`** | ⭐ `/data` is the **writable partition**. Everything else comes from the read-only boot image. That's why edits to `/etc` may not survive a reboot — and it's the shape of nearly every embedded system: immutable image + small writable area. |
| `sshd` with shell `/bin/false`, home `/data/var/chroot/sshd` | **Privilege separation.** Before anyone authenticates, `sshd` forks a child that drops to this unprivileged account and `chroot`s in, so untrusted network data is parsed with almost no authority. `/bin/false` means it's a service identity, not a login. |
| `qnxuser` at UID 1000 | The conventional first human user, same as Linux. |

**What's *absent* is equally informative:** none of the dozens of service accounts a Linux distribution carries (`daemon`, `bin`, `mail`, `www-data`…). This is an embedded image — only accounts that are actually used exist.

> 🐧 And note that `/etc/passwd` is *the same file* as on Linux — seven POSIX fields, `x` meaning "hash is in `/etc/shadow`". QNX being POSIX-compliant isn't a slogan.

**`sshd_config` — one trap worth flagging.** Your grep matched three lines that are **comments**:

```text
# the setting of "PermitRootLogin prohibit-password".
```

That mentions `prohibit-password` — a *different* value from the one in force. Reading it as the setting gives exactly the wrong answer. When a directive matters, check for the leading `#`.

**What's absent there is good news:** no `AllowUsers` (no hidden account allowlist), no `PubkeyAuthentication` line (so it defaults to `yes` — key auth works for non-root, which is what §9.5 recommends).

## 🤔 Your question 2 — root SSH with the `qnxuser` password

**It can't have worked, and your own transcript agrees.** In the log you sent:

```text
$ ssh root@192.168.122.46
Permission denied, please try again.     ← ×3
root@192.168.122.46: Permission denied (publickey,password).

$ ssh qnxuser@192.168.122.46
[qnxuser@qnxqemu ~]$                      ← succeeded
```

With `PermitRootLogin no`, `sshd` rejects the *username* before any password is compared, so the outcome doesn't depend on what you type.

Three easy ways the impression arises, none of them a mistake worth worrying about: shell history recalling the `qnxuser@` line after the root attempt failed; the prompt becoming `[root@qnxqemu ~]#` after `sudo -i` (a root shell, reached via `qnxuser`); or conflating the serial console, where `root`/`root` genuinely works.

Ten-second check next time: `whoami` right after connecting.

I logged this as **D-012** rather than waving it away — *"it worked and I don't know why"* is the worst state to leave a security control in. And if you ever **can** reproduce a successful `ssh root@`, that's a genuine finding: it would mean `sshd_config` isn't the file in effect.

## 🔢 That process ID — 14032920

Not a typo, and worth understanding. Look at your own `pidin`: `16386`, `32773`, `1458208`, `13520913`. Not a counter.

> 🐧 On Linux, PIDs are small integers that wrap at 32768 and get **recycled aggressively**.

**Why QNX can't afford that.** Here a PID is an **addressable endpoint for message passing** — `ConnectAttach(0, pid, chid, ...)` names the server your client talks to. If PIDs were small and promptly recycled, a server could die, an unrelated process could inherit its number, and a client holding a stale connection would send its next request **to the wrong process**. In a real-time system where those messages carry control commands, that isn't an inconvenience.

Spreading IDs across a 32-bit space means a stale reference fails cleanly instead of silently reaching a stranger. You'll meet the same instinct again with connection IDs, channel IDs and server identifiers in Chapters 13 and 16: **identifiers that name an IPC endpoint are capabilities, not indices.** Logged as **D-013**.

## ⚠️ One thing worth saying plainly

Every credential on this image is a published default — `root`/`root`, `qnxuser`/`qnxuser`, VNC `qnxuser` — and **`qnxuser` holds full `sudo`**. So `PermitRootLogin no` buys much less than it looks: anyone who reaches port 22 with the default password has root anyway.

Fine for a disposable VM on a private virtual network. **Unacceptable on anything else.** It's now stated in §9.3.1, and it becomes a worked example in Chapter 28.

---

### What changed on disk

| File | Change |
|------|--------|
| `docs/guides/Setup_03_QEMU_VM.md` | → **v2.0 verified.** All markers cleared; §9.3 corrected to `PermitRootLogin no`; §9.3.1 added (reading `/etc/passwd`); §9.4 fixed to *change* the line not append; §9.5's wrong key claim removed; §10 shows the real PID with its explanation; note on the benign OpenSSH post-quantum warning |
| `docs/meta/Doubts.md` | **D-009 corrected** · **+D-011, D-012, D-013** |
| `docs/meta/DecisionsLog.md` | Session 010: Phase 1 complete · the correction · target accounts + the default-credential observation · QNX PID semantics · an evidence note |
| `docs/internal/VerificationRuns.md` | **Block V5 ✅ complete**; verified target facts extended |
| `docs/meta/CourseState.md` | **Phase 1 complete**, M2 ✅ dated, Session 010 |
| `docs/meta/CompactContext.md`, `ToDos.md`, `CLAUDE-MEMORY.md` | Regenerated; T-015/T-018/T-147 closed; H-11 resolved |

**An honesty note I put in the record rather than glossing over:** V5.6's `scp` and V5.7's shutdown command aren't in the transcript — the binary was already on the target and the session ended with `exit`. The *outcomes* are confirmed and you attested the block complete, so V5 is closed; but under ADR-024 the standard of evidence should stay visible rather than quietly relax at the finish line.

---

## 👉 Next: Chapter 00

Nothing blocks it. Environment done, toolchain proven, VM booting, loop closed.

**Chapter 00 — How To Use This Course** sets the template every one of the 34 chapters follows: conventions, the three path markers, how labs are structured, how the `💥 Break it` exercises work, and how to choose your path. It needs no software, and it's the last piece of scaffolding before Chapter 01 starts teaching real-time systems.

Say the word and I'll write it.

**Optional, whenever:** `cat ~/qnx800/images/qemu/README.md` (394 bytes — T-017), and `du -sh ~/qnx800/images/qemu/qemu/output/disk-qemu` to settle whether that 47 GB image is sparse (T-016).

---

## PROMPT#10

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 011 |
| **Context** | Phase 1 complete; the environment is verified and nothing blocks the course content. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Go ahead and write Chapter 00

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 00 published — 1 / 34

**[docs/chapters/Chapter00_HowToUseThisCourse.md](docs/chapters/Chapter00_HowToUseThisCourse.md)** — 897 lines, ~25 minutes to read, ~25 minutes of labs.

It follows `PLAN.md` §5 exactly, so it doubles as **the reference implementation of the template** all 34 chapters use. Future chapters get written by matching it rather than re-reading the spec.

## What's in it

**§§1–3 — the reading manual.** Why the three paths exist, how to pick one by *time available* rather than ego, the chapter skeleton, every callout box, and the prompt convention (`host$` / `qnx#` / `qnx$`) with a blunt warning that running the right command on the wrong machine is the top way to waste an hour here.

**§4 — the Notation Reference.** Chapter 00 teaches no QNX API, so its "API" section is the course's own notation: symbols, identifier forms (`D-NNN`, `ADR-NNN`, `T-NNN`), the lab directory layout, and a **target quick reference** with your verified credentials in it. That's the section you'll come back to.

**§5 — Worked Example.** A sample section written as a future Chapter 11 would be, then a table explaining *why each element is there*. Teaching you to read the course, using the course.

## The three labs — all on your verified VM

| | |
|---|---|
| ⭐ **Lab 00.1** | Prove the environment and meet the four commands you'll use in nearly every later lab: `uname -a`, `pidin`, `pidin info`, `ls /proc/boot`. Real expected output from *your* target. |
| **Lab 00.2** | Three habits: one terminal per machine, **SSH keys instead of passwords** (you'll `scp` hundreds of times), and reading `CourseState.md` after a break. |
| 💥 **Break It** | Run `mkqnximage` from one directory too high — deliberately reproducing D-006. |
| 🐣 **Path A** | Read a live `pidin` listing. No coding, no compiler. |

**The break-it exercise is the one I'd point at.** The course's first deliberate failure shouldn't teach an API — it should teach the *diagnostic habit*. This one costs nothing, has a real error message, and carries a genuine trap: the message recommends `--force`, and `--force` would quietly build a new image and ignore the 47 GB one you unpacked. The reader is asked to work that out before the answer is revealed.

> An error message tells you what the program *believes*, and offers an escape hatch for the case where the program is wrong. Ask which it is **before** reaching for the flag.

It also turns a bug this course actually hit into teaching material — which is the whole point of having logged it.

## The verification work paying off

Chapter 00 could have been pure prose. It isn't, because your five verification blocks mean **every expected output in it is real**. Lab 00.1's answers teach the microkernel argument straight from your own `pidin` listing — `io-sock` is the entire TCP/IP stack sitting there as an ordinary process — and the `ldqnx-64.so.2` question closes the loop Setup Guide 02 opened.

**Also done:** Glossary +10 terms (with new L and U sections, kept alphabetical), TOC and chapters index updated, README now shows 1/34 and points new readers at Chapter 00 first.

**Style audit passed mechanically:** one H1, no heading-level skips, no GitHub-only syntax, no raw HTML beyond `<details>`, two Mermaid diagrams each with a text description, relative links only.

---

## 👉 Two things

**1. Read it** (T-019) and do the three labs — about 50 minutes total. Then tell me:

- **which path you're taking** (I've assumed 🚶 B, but Chapter 00 argues for choosing by time available, so it's worth re-deciding now that you've seen the shape of the thing)
- **anything that reads wrong** — too slow, too fast, a section that doesn't earn its place

That feedback matters more now than it will later. Chapter 00 defines the template; a structural problem caught here costs one rewrite, and caught at Chapter 20 costs twenty.

**2. Say the word for Chapter 01 — What Is a Real-Time System?** Hard vs. soft real-time, determinism, latency, jitter, WCET, and why "fast" and "real-time" are different properties — one of which QNX deliberately trades away for the other. No software needed.

I can write Chapter 01 while you're reading Chapter 00, if you'd rather not serialise.

---

## PROMPT#11

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 012 |
| **Context** | The learner read Chapter 00 and asked for the next chapter. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I read chapter 00, please proceed to write chapter 01

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 01 — What Is a Real-Time System? (2/34)

**`docs/chapters/Chapter01_WhatIsARealTimeSystem.md`** — 1024 lines, ~60 minutes.

And the course's **first compiled lab**: `labs/lab01_timing/`.

## The chapter's argument

It defines real-time **without using the word "fast"**, then spends the rest of the chapter earning that.

**Hard / firm / soft is about consequences, not tightness.** A washing-machine door lock has a comfortable 100 ms deadline and is *hard* — a hand in a spinning drum. A 144 Hz game has a 6.9 ms deadline and is *soft*. That inversion is the point.

**Determinism is bounded-and-knowable, not small.** There's an ASCII histogram contrasting a system with a 2 µs mean and a 40 ms tail against one that's forty times slower and never exceeds 120 µs — and only the second can carry a 1 ms deadline. That's also why an RTOS can benchmark *worse* than Linux and still be the right choice.

**Four latency components, and you own one of them.** Interrupt latency → ISR → scheduling latency → your code. Three belong to the OS. That single fact is what makes "we profiled our function" an inadequate answer, and it's what you're buying when you buy an RTOS.

**Five classic unbounds**, each with its QNX answer and forward reference: interrupt masking, **priority inversion**, unbounded loops, page faults, dynamic allocation. They *compose* — one unfixed makes the total unbounded.

For priority inversion I used **Mars Pathfinder**: in July 1997 the lander began resetting itself on the Martian surface because a high-priority bus task blocked on a mutex held by a low-priority weather task, preempted by medium-priority comms. JPL diagnosed it from Earth and fixed it by enabling priority inheritance — a flag that had been switched off for performance.

## Two structural choices worth flagging

**§4 adapted again — into "The Vocabulary".** Chapter 00 turned "The API" into a notation reference; Chapter 01 turns it into the eight quantities with units, the **`R` vs `C` trap** (deadlines apply to response time; profilers report execution time), utilisation, and the **≈69 % rate-monotonic bound** — you can start missing deadlines with a third of the CPU idle.

I've recorded the rule this establishes: **§4 is whatever precise material the reader will come back to.** From Chapter 05 it becomes literal APIs and stays there.

**Chapter 01 gets a 🏃 Fast-Track Summary even though the TOC tagged it 🐣🚶.** ADR-008 is explicit that a path existing only as a marker is a broken promise. So the box is written *for someone who already knows this material* — it fixes the vocabulary, states the two traps, and sends them to Chapter 02. TOC tag updated. **The tag means "Path C may skip the body", not "Path C is unserved".**

## §5 — the worked example

Budgets a 1 kHz robot joint controller: six components, 205 µs total against a 300 µs deadline, 32 % margin, 20.5 % utilisation. Then it adds a shared mutex with telemetry and **derives a deadline failure from three individually correct components** — no buggy line anywhere — and fixes it with one `pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT)`.

That's Pathfinder in miniature, and it's why real-time is an OS concern rather than only a coding-discipline one.

## 🧪 The first compiled lab

`labs/lab01_timing/` — Makefile calling `qcc` directly (ADR-007; the recursive Makefile system is Chapter 08's job), skeleton with four TODOs, annotated solution, `expected_output.txt`.

**Why a measurement rather than a hello-world.** You already ran a hello-world on the target in V5.6. This one asks for a 1 ms sleep ten thousand times and reports min/mean/p50/p99/max — so **you produce the evidence for the chapter's central claim yourself** rather than taking my word for it.

It's deliberately plain POSIX, so you can build it for Linux too and compare tails.

**💥 Break It** runs it idle, then loaded, then `on -p 63` while still loaded. Prediction: `mean` barely moves, `max` moves a lot, and priority 63 pulls `max` back down on a fully-loaded machine. **If that doesn't reproduce, the chapter is wrong and I'll fix it.**

**🐣 Path A** is paper-only — five systems to classify, and a drone stopping budget whose punchline is that 30 of the 46 ms are physics, not software. I left `prebuilt/` empty rather than shipping a binary I can't verify; that's now a recorded rule, so Path A never becomes the path that quietly gets less.

## ⚠️ What's verified and what isn't

`solution/jitter.c` passes `gcc -fsyntax-only -Wall -Wextra` with **no warnings**. That's a weaker claim than it sounds: it was checked with the *host's GCC 15*, not with **`qcc` (GCC 12.2.0)**, and it has never run on the target. Everything compiled here is marked `[UNVERIFIED]`.

Also: Glossary +13 terms; TOC, chapters index, labs index and README updated.

---

## 👉 Next: block V6 — and it's more important than one lab

```bash
host$ source ~/qnx800/qnxsdp-env.sh
host$ cd ~/exercises/qnx-zero-to-hero/labs/lab01_timing
host$ make
host$ file solution/jitter
host$ scp solution/jitter qnxuser@<ip>:/tmp/
qnx$ /tmp/jitter
```

**This is the first Makefile, the first skeleton/solution pair, and the first build-deploy-run cycle in the course.** Whatever breaks here breaks in all 33 remaining chapters — which is why it gets a numbered block rather than a footnote.

Watch for two things: **warnings from `qcc`** (GCC 12 may complain where GCC 15 didn't — worth fixing on the course's first lab, not tolerating), and **`min ≥ 1000 µs`** (if it's lower, the measurement is wrong rather than the sleep being short).

Then V6.3 — the three-run comparison — which tests the chapter's argument directly. `on -p 63` is itself unverified; if the syntax is wrong, `on --help` on the target will give the real one.

**Meanwhile I can write Chapter 02 — What Is QNX?** History 1980→2026, the microkernel bet and why it survived when Mach didn't, the product family, and how QNX 8.0 relates to the QNX 6.x material that dominates search results. Say the word.

---

## PROMPT#12

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 013 |
| **Context** | The learner read Chapter 01's lab source and found four unexplained library functions. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> In lab01_timing, you have mentioned below functions: i) clock_gettime ii) nanosleep iii) perror iv) qsort And I don't know what those functions are? Are they part of c++ or are they part of qnx itself? Can you add explanation of those functions (what they do? What are the arguments to they? what those functions return) And In which files those functions live?

### Standing instructions

| # | Instruction | Recorded as |
|---|-------------|-------------|
| SI-14 | Every **library function** a chapter or lab calls must be explained on first use — purpose, arguments, return value, header — or linked to where it is. | `PLAN.md` §2 rule 1 and §17 Definition of Done; hazard **H-12** |

### Response (full)

> *Reproduced as delivered.*

---

Good catch, and a fair one — **this was a gap in the course, not in your knowledge.** Course rule #4 is *"nothing is a black box"*, and I shipped a lab that called four functions and explained none of them.

## The direct answer

**None of the four is C++, and none is QNX-specific.**

| Function | Standard | Header |
|---|---|---|
| `qsort` | **ISO C** — the C language standard itself | `<stdlib.h>` |
| `perror` | **ISO C** | `<stdio.h>` |
| `nanosleep` | **POSIX.1b** — the 1993 *real-time extensions* | `<time.h>` |
| `clock_gettime` | **POSIX.1b** | `<time.h>` |

- **C++?** No — they're **C**. C++ inherits the whole C library, so you *can* call them from C++ (`<cstdlib>`, `<cstdio>`, `<ctime>`), but they aren't C++ features.
- **QNX?** Not one of them. QNX's own calls — `MsgSend`, `ChannelCreate`, `InterruptAttach` — live in `<sys/neutrino.h>` and arrive in Chapter 13.

**Which files they live in — two different answers, and both matter:**

| | |
|---|---|
| **Declarations** (what the compiler reads) | `$QNX_TARGET/usr/include/time.h`, `stdio.h`, `stdlib.h` |
| **Machine code** (what runs) | **`libc.so.6`** — which you've already seen: it's one of the ~80 files you listed in `/proc/boot` |

```bash
host$ grep -n "nanosleep" $QNX_TARGET/usr/include/time.h
qnx#  ls /proc/boot/libc.so.6
```

> 💡 **Your question has a nice answer hiding in it.** "QNX is POSIX-compliant" has been an abstract claim in the Glossary since planning. Here it is concretely: four functions you can read in a header on your own disk, running from a library you've already seen in the boot image, behaving exactly as they would on Linux. That's what the claim *means*.

Full signatures, every argument, every return value, and the clock-choice reasoning are now in **`labs/lab01_timing/README.md` § *The library functions this lab uses***, and in **D-014**.

## Two traps in that lab worth knowing about

Neither is style — both are ways to be silently wrong.

**1. The comparator returns `(a > b) - (a < b)`, not `a - b`.** The obvious version **overflows**: with `a` very negative and `b` very positive, `a - b` wraps and returns the *wrong sign*. Your array comes back subtly mis-sorted, with no error reported anywhere.

**2. The lab sorts *after* the measurement loop, never inside it.** `qsort` isn't necessarily quicksort, and **its worst case is unspecified by the C standard** — which makes it exactly the *unbounded computation* Chapter 01 §3.2 warns about, sitting unremarked inside the lab that teaches it.

> Nothing is wrong with `qsort`. What matters is *where* you call it. Real-time discipline is less about forbidden functions than about keeping unbounded work off the deadline path.

## 🔧 I fixed the rule, not just the instance

`PLAN.md` §2 rule 1 read: *"Never assume a **term**. First use of any term → defined inline."* A function isn't a term — so four unexplained calls passed every check the course had.

**Rule 1 now covers library functions**, and there's a matching checkbox in the §17 Definition of Done so it's verifiable rather than merely intended.

## 😬 Then I audited, and found five more — in the same chapter

A case-sensitive sweep of both published chapters turned up nine function references. Two are invented placeholders in illustrative snippets. **Five were real, unexplained calls in Chapter 01 itself:**

| Call | Where | Now |
|---|---|---|
| `InterruptDisable()` / `InterruptEnable()` | §3.2 | Explained — and flagged as **QNX-specific**, unusual this early |
| `qsort()` | §3.2 | Explained, with a pointer to the full signature |
| `pthread_mutexattr_init`, `pthread_mutexattr_setprotocol`, `pthread_mutex_init` | §5.3 | Explained in a table |
| `ClockPeriod()` | lab notes | Named as a QNX call in `<sys/neutrino.h>` |

The `pthread_*` entry carries a trap worth having early: **that family returns an error number directly rather than returning `-1` and setting `errno`** — the well-known exception to the POSIX convention. `if (rc != 0)`, not `if (rc == -1)`.

And a point about §5.3's fix that I'd previously left implicit: a mutex is created *with* attributes, so **priority inheritance must be chosen before the mutex exists.** You can't switch it on later, under load, when you discover you needed it. That's an architectural decision disguised as an initialisation detail — and it's exactly the flag JPL had to change on Mars.

**The audit is now standing procedure before publishing any chapter.**

---

### What changed on disk

| File | Change |
|------|--------|
| `labs/lab01_timing/README.md` | → **v1.1.** New *"The library functions this lab uses"* — all four with signatures, arguments, returns, headers, `CLOCK_MONOTONIC` vs `CLOCK_REALTIME`, and how to look anything up (read the header first) |
| `docs/chapters/Chapter01_WhatIsARealTimeSystem.md` | → **v1.2.** Points at that section; five more calls explained |
| `docs/PLAN.md` | → v1.3. **Rule 1 extended to library functions**; §17 checkbox added |
| `docs/meta/Doubts.md` | **+D-014**, in full |
| `docs/reference/Glossary.md` | +6 terms: `errno`, header file, ISO C standard library, `libc`, POSIX.1b, `pthread_*` |
| `docs/meta/DecisionsLog.md` | Session 013: the rule gap, the fix at rule level, the audit results |
| `docs/internal/CLAUDE-MEMORY.md` | Hazard **H-12** — lab code is easy to under-explain |

---

## 👉 Where we are

**Block V6 is still with you** — building `lab01_timing` with `qcc` and running it. That's unchanged, and the README you'll be reading is now considerably more useful than it was an hour ago.

**Keep asking questions like this one.** It found a real defect in the course's process, not just in one file — which is worth more than the four answers. If anything else in Chapter 01 assumes knowledge you don't have, say so; that's precisely the feedback Chapter 00 asked for.

Say the word for **Chapter 02 — What Is QNX?** whenever you're ready.

---

## PROMPT#13

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 014 |
| **Context** | The learner finished Chapter 01 and asked for the next chapter. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I am done with Chapter 01. GO ahead with Chapter 02

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 02 — What Is QNX? (3/34)

935 lines, ~75 minutes. Part 0 is now three-quarters done.

## I verified the history instead of writing it from memory

Chapter 02 is history-heavy, and a wrong date in a published chapter is a nastier error than a wrong command — nobody's build fails, so nobody finds it. So I checked against **QNX's own "A little history" page** and **BlackBerry's SDP 8.0 announcement** before writing:

| | |
|---|---|
| **1980** | Dan Dodge and Gordon Bell, University of Waterloo graduates, found **Quantum Software Systems Limited**. Product: **QUNIX** |
| **1982** | First commercial release, Intel **8088**. AT&T's lawyers object to the *Unix* trademark → renamed **QNX** |
| **~1991** | **QNX 4** — 32-bit and **POSIX**. The decision that makes your C knowledge transferable |
| **1995** | **QNX Neutrino** — the origin of `procnto` |
| **2004 / 2010** | Harman, then RIM/BlackBerry for ~$200 M |
| **21 Mar 2024** | **QNX SDP 8.0 GA** — what you installed |

> One trap I flagged: QNX's co-founder **Gordon Bell is not the DEC computer architect** of the same name. Search engines conflate them cheerfully.

## The chapter's argument, and one point the usual telling omits

The microkernel bet, stated as one decision: **`procnto` provides scheduling, memory, timers and message passing, and nothing else.** Everything else — every driver, the TCP/IP stack, filesystems, graphics — is an ordinary process.

**The point I think is under-told:** the familiar benefit is fault isolation. The one that actually put QNX in vehicles is that isolation can be **demonstrated to a third party**. Under ISO 26262 you must produce *evidence* of freedom from interference. In a monolithic kernel every privileged component is potentially in scope — your safety case has to reason about the graphics driver, because it runs with the same authority as your safety task. With MMU-enforced process boundaries the argument becomes structural.

That resolves a historical puzzle worth knowing: microkernels largely *lost* the 1990s performance argument, and Mach survives mainly as a hybrid inside macOS. QNX kept the design — and what turned out to be worth having wasn't the isolation, it was the ability to prove it.

**I also wrote down what it costs.** §2.2 lists messages instead of function calls, context switches, 31 processes at idle, an unfamiliar driver model — and says plainly:

> *For a build server or a laptop, this trade is simply bad. **QNX is not a better Linux.** It is a different answer to a different requirement.*

A course that only argues for its subject produces readers who can't tell when *not* to use it — which is the judgement an employer is actually paying for.

## §4 — the section I expect you'll use most

It's **The Product & Version Map**, including **four reliable signals for spotting stale QNX material**:

| Signal | Means |
|---|---|
| `blackberry.qnx.com` | Pre-2025 |
| "QNX Neutrino RTOS 6.x" in a product name | The 6.x line |
| **`io-pkt`** | Pre-8.0 — your `pidin` showed **`io-sock`** |
| `docs/6.5.0/` or `docs/7.0.0/` in a URL | Read the number |

> **Concepts age well; commands age badly.** There isn't much written about QNX, and the best explanations are often old. Telling you to avoid old sources would be bad advice — the rule is to read them for understanding and verify every command.

I put this course inside that warning too: its own guides have been wrong five times so far.

## §5 decodes *your* system

```text
procnto-smp-instr
│   │  │   └── instrumented — kernel tracing compiled in (Ch 26 will work here)
│   │  └────── SMP — multi-core
│   └───────── nto — NeuTrinO
└───────────── proc — the process manager
```

Then `uname -a` field by field, and the observation I like most in the chapter: **one file out of about eighty in `/proc/boot` is the kernel.** The other seventy-nine are ordinary programs and libraries whose Linux equivalents live *inside* `vmlinuz`.

That ratio is the microkernel bet expressed as a directory listing. Nothing in §§1–3 is theoretical — you can `ls` it.

## 🧪 Labs — no compiler needed

| | |
|---|---|
| **02.1** | Identify your system and place it on the version map |
| **02.2** | **Kill `vncserv`, watch the system shrug, restart it** — a different PID comes back ([D-013](docs/meta/Doubts.md#d-013)) |
| 💥 **Break It** | **Try to `slay procnto`.** Predict first: refused, or does the VM stop? |
| 🐣 **Path A** | Date five documentation snippets. Paper only |

The break-it is my favourite so far, because *either outcome teaches the same thing*. In 02.2 you kill a server and the OS doesn't notice; here you reach the one component that **is** the OS. QNX's whole design is about keeping that set as small as possible — one file in eighty.

⚠️ Lab 02.2 uses `vncserv` deliberately: `slay io-sock` would be the more dramatic demo, but it kills the SSH session carrying your command. That version is in the mastery check, and in **V7.3** for the serial console.

## ✅ The new rule held

Session 013's library-function rule was applied *while writing* rather than after. `MsgSend`/`MsgReply` and `open`/`read`/`write` are explained on first use; every shell command in the labs is tabled with its standard.

**The audit afterwards found nothing to fix** — the first evidence the rule change works.

The `open`/`read`/`write` note carries the thesis restated at API level: they're *unchanged* on QNX, and become messages to a user-space process underneath. Your code can't tell. That's what "POSIX-compliant" buys.

---

### What changed on disk

`docs/chapters/Chapter02_WhatIsQNX.md` (new, 935 lines) · Glossary +10 terms with **POSIX** promoted from a planning stub · **block V7** added · `DecisionsLog` Session 014 · `ReferenceLinks` records the history verification · TOC, chapters index, README, `CourseState`, `CompactContext`, `ToDos`, `CLAUDE-MEMORY`.

---

## 👉 Two blocks are open, and they're independent

| | | |
|---|---|---|
| **V6** | Build `labs/lab01_timing/` with `qcc`, run it, do the loaded/priority comparison | Needs the toolchain |
| **V7** | Chapter 02's labs — kill and restart `vncserv`, then try to `slay procnto` | **No compiler.** ~20 min |

**V7 is the cheaper one** if you want a quick session: four commands, and it demonstrates the thing Chapter 02 spends 900 lines arguing.

**Next up is Chapter 03 — Why & Where QNX Is Used**, which closes Part 0: automotive, medical, rail, robotics; QNX versus Linux, FreeRTOS, VxWorks and Zephyr; and — in the same spirit as §2.2 — **when the honest answer is "use Linux".** Say the word.

---

## PROMPT#14

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 015 |
| **Context** | The learner finished Chapter 02 and asked for the next chapter, which closes Part 0. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> completed chapter 02. Please proceed to chapter 03

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 🎉 Chapter 03 published — Part 0 complete (4/34)

946 lines. **Milestone M1 — "I get it"** is reached.

## The thesis: certification, not latency, is what decides

The obvious way to write "why QNX" is a latency argument. I didn't. The deciding question in this chapter is **"will an independent assessor examine this system?"** —

> Latency is an engineering problem with many solutions. Certification is a procurement and liability problem with very few.

When someone asks *"should we use QNX?"*, they're almost never asking about latency. They're asking: can we ship without being sued, will the assessor accept it, can we afford it, will a supplier's bad driver kill our product. **Three of those four are commercial.** An engineer who can only quote interrupt latencies isn't useful in the meeting where the decision actually gets made.

**The verified numbers** (BlackBerry, 15 Oct 2024 — I checked rather than recalled, since Chapter 02 had already published the vehicle figure):

- **255 million vehicles**, +20 M year on year, +80 M since 2020
- IEC 61508 **SIL 3** · ISO 26262 **ASIL D** · IEC 62304 **Class C** · EN 50128/50657 **SIL 3**

## §4 — the framework, built to survive a meeting

An **eight-step decision tree** you work in order, stopping at the first question that decides. Plus the part nobody fills in:

| Cost | QNX | Linux |
|---|---|---|
| Licence | 💰 Real | Free |
| **Certification evidence** | **Included** | 💰💰💰 Yours to produce |
| Tool qualification | Available | 💰 Yours to arrange |
| **Schedule risk on certification** | Low | 💰💰 **High — the one that kills projects** |

> A licence fee is a known number in a spreadsheet. *"We think we can certify Linux for ASIL D, and we'll find out eighteen months in"* is an unbounded risk — and Chapter 01 taught you to distrust exactly that.

Also four sentences that should trigger a follow-up question — including *"QNX is certified"* → **"To what level, in which configuration, and have we read the safety manual?"**

## Each industry chose it for a *different* reason

| | Why |
|---|---|
| 🚗 Automotive | Consolidation forcing mixed criticality, + ASIL D, + 15-year support |
| 🏥 Medical | **Schedule.** A royalty is trivial against an $8 000 device; months off a regulatory submission is not |
| 🚆 Rail | SIL 3 — with deadlines measured in **seconds**. Nobody chose QNX here for speed |
| 🤖 Robotics | Cobots: a hard-deadline stop function beside an uncertifiable ROS 2 stack |

Rail is the sharpest illustration of Chapter 01 §2.2: **hard real-time with loose deadlines.**

## One of the three worked examples answers "Linux"

§5.2's telemetry gateway reaches **Linux**, and I gave the reasoning at full length rather than as a concession — because that's the project most often over-engineered onto an RTOS in real life. It also names the fallacy that does it:

> *"But it's industrial, so it must be real-time."* No. **Industrial is a market; real-time is a timing property.**

The competitive table keeps the same discipline: credits `PREEMPT_RT`, names Linux's ecosystem and hiring as genuinely decisive in the right context, and points at the **ELISA project** rather than claiming Linux "can't" be certified. The precise claim I make is narrower and defensible: **no mainline Linux is certified to ASIL D today.**

One more distinction worth having: **FreeRTOS is a scheduler, not an OS** — a few thousand lines, no MMU, one address space. Comparing it to QNX is comparing a bicycle to a train.

## 💥 The break-it, for a chapter about judgement

You can't break judgement with a wrong command, so the exercise asks you to **build the strongest possible case for QNX on the project where the answer was clearly Linux** — then find where it breaks.

**The instructive part: one of the four counter-arguments survives.** *"We already have QNX licences and QNX engineers"* is a legitimate engineering input, and I say so — while insisting it be stated as what it is rather than dressed up as a technical requirement.

> Most bad OS decisions aren't made by fools. They're made by reasonable people generalising a real requirement from a project where it applied.

## 🏁 The Part 0 review

Chapter 03's Path A activity **is** the Part 0 review, and it's worth doing on every path: a one-page memo with six headings — deadline, certification, isolation, recommendation, **cost of being wrong in both directions**, and what would change your mind.

Section 6 carries the weight. There's a worked table contrasting weak and strong versions:

| ❌ | ✅ |
|---|---|
| "Further investigation needed" | "If QNX royalties exceed $40/unit at 50 000/year, the certified-Linux route becomes worth a two-week feasibility study" |

The difference is naming **a test that could be run and a threshold that would flip the answer**. That converts an opinion into a hypothesis — and it's the most transferable thing in Part 0. It works on every technology choice, not just this one.

---

### What changed on disk

`Chapter03_WhyAndWhereQNXIsUsed.md` (new, 946 lines) · Glossary **+15 terms** with **ASIL** promoted from a planning stub · **block V8** added · `ReferenceLinks` records the verification · `DecisionsLog` Session 015 · TOC, README, indexes, `CourseState` (**M1 dated**), `CompactContext`, `ToDos`, `CLAUDE-MEMORY`.

---

## 👉 Where things stand

```text
Part 0  Orientation   [████████████████████] 100 %  (4/4) 🎉
OVERALL               [██                  ]  12 %  (4/34)
```

**Three verification blocks are open**, and two are cheap:

| | | |
|---|---|---|
| **V6** | Build `labs/lab01_timing/` with `qcc`, run it loaded and at priority 63 | Needs the toolchain |
| **V7** | Kill and restart `vncserv`; try to `slay procnto` | No compiler, ~20 min |
| **V8** | Confirm `libsecpol.so.1` and `ability` are in the image | No compiler, **5 min** |

V7 and V8 fold into one session and between them demonstrate what Chapters 02 and 03 spend 1 900 lines arguing.

**Next: Part 1 begins — Chapter 04, QNX Licensing & QNX Everywhere.** Slightly unusual, in that you've already *done* the licensing; Chapter 04 explains what you actually agreed to — what "non-commercial" permits and forbids, why writing training material is explicitly allowed (which is what makes this repository legitimate), and what would have to change to ship a product.

Say the word.

---

## PROMPT#15

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 016 |
| **Context** | Part 0 complete; the learner asked for the first chapter of Part 1. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Please proceed to chapter 04

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 04 — QNX Licensing & QNX Everywhere (5/34)

835 lines. **Part 1 begins.** And writing it turned up an error in material the course had already published.

## ⚠️ First, the correction

I read QNX's licensing page rather than restating the project's earlier notes. Good thing:

| | |
|---|---|
| **Setup Guide 02 §2 said** | "Demo to existing or potential **customers** — Explicitly listed as commercial activity" ❌ |
| **QNX's licensing page says, under *permitted*** | *"Build or develop a product or system (e.g. as part of a product roadmap) to demonstrate to existing or potential customers."* ✅ |

**Exactly backwards.** The same section also implied that building anything real was forbidden; QNX permits hobby/maker use to *"build a product or system"* — the condition attaches to commercialisation and production, not to construction.

**Why this error is worse than a wrong command.** A wrong command fails visibly and gets reported. A wrong licence claim fails **silently, in both directions** — it can make you refuse work you're entitled to do, or reason by analogy into something you're not. Nobody's build breaks, so nobody finds it.

Fixed: Setup Guide 02 → **v2.2**, `CompactContext`, `CLAUDE-MEMORY`, and the Glossary. Recorded as hazard **H-13**, with the rule generalised: **licence claims get checked against QNX's page or the EULA, never restated from an earlier course document.**

> One deliberate non-fix: `DecisionsLog.md` is append-only, so the incorrect line in the Session 001 entry **stays**, superseded by the new entry. That's the point of an append-only log — it shows what was believed and when it was corrected.

## The chapter's thesis

**The boundary is `production` and `distribution` — not whether money is involved.** That's wrong in *both* directions, which is what makes it worth a chapter:

| Permitted **despite** money | Forbidden **despite** no money |
|---|---|
| Training material and books — *"including if you intend to offer that material commercially"* | A permanent internal test rig — plausibly **production use** |
| Academic salaries, RA stipends | Sending **one** pilot unit — that's **distribution** |
| Building a product as a hobbyist/maker | |
| Demonstrating to existing or potential customers | |

The mental model asks the questions in that order — production, then distribution, then payment — because most people carry it money-first.

## The thing with budget implications

> *"Distribution and production use is not permitted under a development license and requires a separate distribution license."*

**A commercial development licence does not permit shipping.** Two licences. This applies to commercial holders too, and it's routinely discovered during launch planning. I state it three times and suggest asking *"do we have a distribution licence, or only development?"* in **month one**, not month twenty.

## 🐧 The contrast that explains most accidental non-compliance

| | GPL | QNX Everywhere |
|---|---|---|
| Restricts **use**? | ❌ No | ✅ **Yes** |
| Obligation lands when… | You **distribute** | You **use it beyond permitted purposes** |

Open-source experience trains you to think *"the licence only matters when I ship."* Under a **development licence** the restriction is on **use** — so compliance is a question you answer continuously, not once at release. That single difference explains most accidental violations by engineers who've only worked with open source.

## §5 uses this course as a worked example

A public repo teaching QNX, permitted under *"training material or books"* — and it **never ships QNX binaries**. Setup Guides 01–03 walk you through getting your own licence precisely so distribution never arises. That was an architectural decision about the *course*, made for licensing reasons.

It also retroactively explains why `prebuilt/` is empty in `lab01_timing` — a call I made in Session 012 for verification reasons, which turns out to be the licensing-correct answer too.

The sharpest pair in the chapter: **writing a paid course about porting to QNX is permitted; doing the port for a paying client is not.** Same money, different side of the line.

## 🧪 Labs

⭐ **Lab 04.1 is the one to do**, and its point is slightly subversive: everything in §2 is quoted from QNX's *summary* page. **The agreement you accepted is what binds.** So the lab has you find your licence file, run `-listLicenseKeys`, and then **open and read the actual agreement** — reporting any discrepancy with my chapter.

Given §1.2, that's not a rhetorical invitation.

**💥 Break It** renames your licence file aside, rebuilds with `qcc`, and renames it back. Prediction: it still compiles. The lesson isn't the result —

> **"The tool let me" is not "the licence allows it."** Most licence violations in industry aren't committed by people who decided to violate a licence. They're committed by people who did the thing the tool allowed, and never asked.

**🐣 Path A** classifies eight activities. The two that catch people — publishing a bootable image, and a permanent internal test rig — both involve no money at all.

## 🔧 Housekeeping worth mentioning

I'd drafted the file as `Chapter04_Licensing.md`; the TOC had specified `Chapter04_LicensingAndQNXEverywhere.md` all along. Renamed, references fixed — and I then ran a **link check across all five published chapters**: **zero broken links**, with forward references now pointing only at planned TOC filenames. Two chapters had already accumulated links to a filename that would never have existed. That check is now cheap and should run before every commit.

---

### What changed on disk

`Chapter04_LicensingAndQNXEverywhere.md` (new, 835 lines) · **Setup Guide 02 → v2.2** (correction) · `CompactContext`, `CLAUDE-MEMORY`, Glossary corrected · Glossary +3 terms · **block V9** added · `DecisionsLog` Session 016 · `ReferenceLinks` · TOC, README, indexes, `CourseState`, `ToDos`.

---

## 👉 Four blocks are open — V9 is new and cheap

| | | |
|---|---|---|
| **V6** | Build `labs/lab01_timing/`, run loaded and at priority 63 | Toolchain |
| **V7** | Kill and restart `vncserv`; try to `slay procnto` | Target, ~20 min |
| **V8** | Confirm `libsecpol.so.1` and `ability` are in the image | Target, 5 min |
| **V9** | **Read your licence file; test whether `qcc` is licence-gated; read the agreement** | **Host only**, ~15 min |

**V9.3 is the valuable one.** The course has now had one licensing fact backwards; there's no reason to assume it was the only one, and you're the only person who can check the binding document.

**Next: Chapter 05 — Installing QNX SDP 8.0.** What QNX Software Center actually did, the `~/qnx800` layout, what `qnxsdp-env.sh` sets, and how `$QNX_HOST` and `$QNX_TARGET` divide the world in two. Another chapter explaining something you've already done — which, as with licensing, is a better way to learn it.

---

## PROMPT#16

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 017 |
| **Context** | Chapter 04 published; the learner asked for the next chapter. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Please proceed to chapter 05

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 05 — Installing QNX SDP 8.0 (6/34)

1026 lines. Like Chapter 04, it explains something you already did.

## One idea, and everything follows from it

`~/qnx800` holds **two operating systems' worth of files**. The test for which tree anything belongs to:

> **"Which CPU and OS actually executes this file?"** Linux → host. QNX → target.

```text
~/qnx800/
├── host/linux/x86_64/     $QNX_HOST    ← runs on YOUR machine
│   └── usr/bin/           qcc, ntox86_64-gdb, mkifs, mkqnximage
├── target/qnx/            $QNX_TARGET  ← for the QNX target
│   ├── usr/include/       sys/neutrino.h
│   └── x86_64/ aarch64le/ libc.so.6, ldqnx-64.so.2, pidin, awk…
└── qnxsdp-env.sh
```

**`qcc` runs from the host tree and reads the target tree.** That crossing is where build errors live — and §4.3 shows the four common failures are *one bug seen from four angles*:

| Symptom | Actually means |
|---|---|
| `qcc: command not found` | Environment not sourced |
| `sys/neutrino.h: No such file` | `$QNX_TARGET` unset, or you used `gcc` |
| Odd link errors | Wrong or missing `-V<target>` |
| Builds but won't run | Wrong tree entirely |

> `echo $QNX_HOST; echo $QNX_TARGET` answers more build questions than any amount of reading compiler output.

## The section I'd point at

**§5.3 — the silent failure.** Every other error in the chapter announces itself. This one doesn't:

```bash
host$ gcc -o hello hello.c    # builds fine. Wrong operating system.
```

No error, no warning, a perfectly good **Linux** binary — discovered at deployment. The remedy is a habit rather than a rule: run `file` as part of *building*, not just debugging, and look for `interpreter /usr/lib/ldqnx-64.so.2`.

## Also covered

- **`source` vs `./`** — the most common Unix "I followed the instructions and nothing happened". `./` starts a child shell that sets the variables and exits with them.
- **QSC's four nouns** — installation, profile, baseline, package — with the CLT options **verified** from the `-help` output your V5.1 run captured, and a repeated warning that `-listAvailablePackages` doesn't exist.
- **`.sym` files** as separated debug symbols: small binaries on the target, full symbols for `gdb` on the host. That's what makes Chapter 25 work.
- 🔬 **Where the ~43 GB goes:** two complete architectures plus debug symbols for everything.
- 🐧 The **sysroot** comparison, including why QNX puts the target in a *flag* (`-Vgcc_ntox86_64`) rather than in the program name — which is why switching to ARM in Part 6 changes a flag, not a toolchain.

§2.2 has a line I like: **you can browse a QNX system on your Linux disk right now, without a VM.** `ls $QNX_TARGET/x86_64/usr/bin` is what `/usr/bin` looks like on a QNX box — and it's why Chapter 21 can assemble a boot image without a package manager.

## ⚠️ Being straight about what's verified

Facts carried from your verification runs and stated plainly: both variable values, GCC **12.2.0** and the six targets, the `ldqnx-64.so.2` interpreter, ~43 GB, and the QSC option list.

**Still only predicted** — and marked as such in the chapter:

| Prediction | Where |
|---|---|
| That `-I`/`-L` paths point into `$QNX_TARGET` | **§5.1 — the chapter's central mechanism** |
| That `qcc -v` is the verbose flag | §5.2 |
| `$MAKEFLAGS`'s actual value | §3.2 — from Setup Guide 02's docs, never observed |
| The `du -sh` breakdown | §3 deep dive |

Worth saying plainly: **the chapter's most important claim is currently its least evidenced.** §5.1 is reasoned from how cross-compilation must work, not observed. Block **V10.2** exists to close exactly that.

---

### What changed on disk

`Chapter05_InstallingQNXSDP.md` (new, 1026 lines) · Glossary **+8 terms** (`$QNX_HOST`, `$QNX_TARGET`, `qcc`, `qnxsdp-env.sh`, separated debug symbols, sysroot, cross-compilation, QSC baseline) · **block V10** added · `DecisionsLog` Session 017 · TOC, README, indexes, `CourseState`, `CompactContext`, `ToDos`, `CLAUDE-MEMORY`.

Link check across all six published chapters: **zero broken links.**

---

## 👉 Five blocks open — and two are host-only

| | | |
|---|---|---|
| **V6** | Build `labs/lab01_timing/`, run loaded and at priority 63 | Toolchain |
| **V7** | Kill and restart `vncserv`; try to `slay procnto` | Target, ~20 min |
| **V8** | Confirm `libsecpol.so.1` and `ability` are in the image | Target, 5 min |
| **V9** | Read your licence file; is `qcc` licence-gated?; read the agreement | **Host**, ~15 min |
| **V10** | SDP layout, disk breakdown, **`qcc -v` paths**, three deliberate failures | **Host**, ~25 min |

**V9 + V10 fold into one 40-minute host session, no VM needed.** V10.2 is the one I'd most like back — it's the only thing that turns §5.1 from reasoning into evidence.

**Next: ⭐ Chapter 06 — Your First QNX VM on QEMU.** The first `⭐ core` chapter: what QSTI actually is, what `mkqnximage --run` starts, and how `ifs.bin` plus a virtual disk become a running system. You've done it once in Setup Guide 03 — Chapter 06 explains it, then takes it apart.

---

## PROMPT#17

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 018 |
| **Context** | Chapter 05 published; the learner asked for the next chapter — the first `⭐ core` one. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> Please proceed to chapter 06

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# ⭐ Chapter 06 — Your First QNX VM on QEMU (7/34)

1087 lines, and the **first `⭐ core` chapter** — it contains lab **L06**, which every coding path does, including Path C.

## The line I built the chapter around

Your boot log has about twenty-five lines. One of them partitions the entire problem space:

```text
Startup complete
```

**Before it, you are debugging the BSP** — board initialisation, memory map, clocks. **After it, the system** — drivers, services, configuration. On a dead custom board (Chapter 32) it's the first question anyone competent asks, and a learner who carries that one boundary can triage a boot failure on any QNX target.

Everything in §5 is placed relative to it.

## The full chain

```text
SeaBIOS → iPXE → startup-* → procnto → slm (22 components) → login
```

**The syspage** gets introduced here rather than waiting for Chapter 22, because the chapter unavoidably raises the question: how does one `procnto` binary run on QEMU, a Raspberry Pi *and* an automotive SoC? Answer — `startup-*` builds a structure describing the hardware it found and hands it over. **The kernel contains no board-specific code.** That's also what a BSP fundamentally *is*.

## `ifs.bin` vs the disk

| | `ifs.bin` | `disk-qemu` |
|---|---|---|
| 20 MB, mounted in **RAM**, read-only, permanently | 47 GB apparent |
| Appears as **`/proc/boot`** | `/`, `/usr`, `/system`, `/data` |

> **A QNX system can boot and run with no disk at all.** Your VM has one, so it looks like a conventional computer. A real embedded QNX device may have `ifs.bin` in flash, RAM, and nothing else.

And `slm`'s 22 components are read as a **dependency argument** rather than a list: logger first (so everything after can log its startup), bus before disk, disk before mount, network before `ssh` and `qconn`.

## §3.3 — the section that saves an afternoon

**Only `/data` survives a reboot.** `/proc/boot` is read-only, `/tmp` is RAM, and `/etc` comes from the image's system partition.

This contradicts the habit every desktop Unix user brings — *configuration lives in `/etc`* — and it's why Setup Guide 03 hedged about your `sshd_config` edit not sticking. The rule underneath: **permanent configuration belongs in the image**, which is Chapter 21.

**And I made it testable rather than asserted.** The 💥 exercise writes to four locations and reboots. `/etc` is flagged as the one to watch, because I *predict* it doesn't persist and have never confirmed it. If it does, §3.3 and the Path A answers both need rewriting — and the chapter says so.

## The labs open Chapter 21's source material, fifteen chapters early

Lab 06.2 has you read `output/build/ifs.build`, `disk.layout` and `build.date` — files whose syntax Chapter 21 teaches. The lab says outright that they won't fully make sense yet, and that's fine. The point is cheap and worth it:

- the image is **not magic** — it's a text file and a build step
- everything you've observed on the target is **declared** somewhere in there
- when Chapter 21 asks you to write one, you'll have read one first

§3.4 also points out that `option_files/` and `local/snippets/` are **CTI already sitting on your disk** — the middle stage of ADR-004's QSTI → CTI → `mkifs` progression.

## §5 places every line of your actual boot log

Including *why* the four benign warnings appear exactly where they do: `uname` fails with `ENOENT` because the disk isn't mounted yet, and the logger isn't running because `slm` hasn't started it — with the very next line being `slm` doing so.

There's a table at the end mapping each line back to a claim from an earlier chapter. The boot log turns out to be evidence for most of Chapter 02.

---

### What changed on disk

`Chapter06_FirstQNXVMOnQEMU.md` (new, 1087 lines) · Glossary **+5 terms** (IFS, `slm`, syspage, `startup-*`, data partition) with **build file** promoted from a stub · **block V11** added · `DecisionsLog` Session 018 · TOC, README, indexes, `CourseState`, `CompactContext`, `ToDos`, `CLAUDE-MEMORY`. Link check across all seven chapters: **zero broken**.

---

## 👉 One request I'd single out

Six blocks are open, but **V11.2 is the highest-value one in the course**, and it costs you two commands:

```bash
host$ cd ~/qnx800/images/qemu/qemu
host$ head -60 output/build/ifs.build
host$ cat output/build/disk.layout
```

**`ifs.build` is the complete recipe for the system you're running** — every file in `/proc/boot`, every service `slm` starts, every partition.

**Why it matters more than the others:** Chapter 21 is a `⭐ core` chapter and currently has no concrete material. Written today it would be a walkthrough of QNX's documentation. With your `ifs.build` in hand it becomes an annotated walkthrough of **a system you have already booted, explored and debugged**. That's a categorical difference in quality for two `cat` commands, and I've recorded it in the decisions log so no future author writes Chapter 21 without asking first.

Also wanted: **`slm.cfg`** from the target (V11.1) — §2.3 currently describes `slm`'s components from the boot log alone.

**Next: Chapter 07 — First Contact: The QNX Shell.** You can boot the system and explain how; Chapter 07 has you *live* in it — `ksh`, the filesystem layout, `pidin` in earnest rather than as a demonstration, and the pathname space.

---

## PROMPT#18

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 019 |
| **Context** | The learner supplied the outstanding `du` measurement and asked for the next chapter. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> You asked me to give the "du" of ~/qnx800 folder to analyze and update the documents appropriately. Please find it in toAgent/6.sizeInfo.md document. And please proceed to Chapter 07.

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# Two things: a correction, and Chapter 07

## ⚠️ Your `du` corrected six documents and a script

```text
79G  ~/qnx800
53G  images/    23G  target/    2.7G  host/    1.1G  bsp/
315M custom/    24M  source/    4.6M sources/   2.9M docs/
```

**Three findings, and one of them mattered more than the numbers.**

**1. The virtual disk is *not* sparse.** D-008 speculated it might be, since `ls -lh` showed 47 GB apparent. `images/` occupies **53 GB of allocated disk** — essentially the full apparent size. Speculation retracted, not quietly dropped.

**2. The total is 79 GB, not ~43 GB — and both figures were right.** That's the part worth understanding:

| Measurement | What it actually measured |
|---|---|
| **43 GB** (block V3) | A **`df` delta** — everything written *anywhere* during the install, including QSC's download cache outside `~/qnx800`. Taken **before** the image was unpacked |
| **79 GB** (your drop) | **`du` on one directory**, after unpacking |

> **`df` measures the filesystem over time; `du` measures a directory now.** Quoting one as though it were the other is how disk estimates go wrong. Both are now stated together with the reconciliation.

**3. `bsp/` is 1.1 GB — Board Support Packages, already on your disk.** Chapter 22's entire subject. That's the *third* time later-chapter material has turned out to be present from the start, after `output/build/` and the CTI `option_files/`.

**Corrected:** `PLAN.md` (~50 GB → **~85 GB** budget, third revision), Setup Guides 01/02/03, Chapters 05 and 06 — and **`tools/check-environment.sh`**, whose thresholds would have told a reader that 30 GB free was "just enough".

> A wrong number in a *check script* is worse than a wrong number in prose: it carries the authority of a test. That's the third plausible-but-wrong published claim this course has caught, after `-listAvailablePackages` and the customer-demo licensing error — and none would have been found by re-reading our own documents.

**T-016 closed. D-008 answered.**

---

# 📕 Chapter 07 — First Contact: The QNX Shell (8/34)

992 lines. Part 1 is now 4/5 done.

## Built around one column

The chapter could have been a shell tour. Instead **blocking states** are the centre, because when a QNX system misbehaves the question is never *"which process is using the CPU?"* — it's:

> **"What is everything waiting for, and is anyone waiting on someone who will never answer?"**

Three reusable techniques carry it:

| | |
|---|---|
| `pidin \| grep -v RECEIVE \| grep -v SIGWAITINFO` | Hides the healthy idle majority — exceptions become visible instantly |
| **Follow the `REPLY` chain** | Each `REPLY` names a PID. Look it up, repeat, until you reach real work or a stuck thread |
| Look for **cycles, dead servers, queues** | The three shapes a hang actually takes |

## `RECEIVE` is normal — said five times, deliberately

A newcomer seeing a listing full of `RECEIVE` will reasonably conclude the system is stalled. It's the opposite: servers block waiting for work at **zero CPU cost**, so a healthy idle QNX system is overwhelmingly `RECEIVE`. I say so in the Fast-Track, §3.2, the recap, the cheat sheet and a mastery question — because the misreading is both natural and expensive.

## `/dev` is not what it looks like

| | Linux | QNX |
|---|---|---|
| `/dev/ser1` is | A node with major/minor numbers | A **path a process registered** |
| `open()` | Enters the kernel, dispatches by number | **Asks `procnto` who owns the path** |
| `read()` after | A kernel call | **A message to that process** |

You can verify it from the shell: for every interesting `/dev` entry there's a process in `pidin`. `devc-ser8250` owns the serial paths. **The filesystem is a directory of running services.**

There's also a deep dive on why QNX's `/proc` is small — *most of what Linux exposes there isn't in the QNX kernel to expose*. Network stats belong to `io-sock`, a process. That's a genuine cost of the microkernel, honestly stated.

## The Path A activity I'm happiest with

Six lines of `pidin` output containing a **three-process deadlock cycle** plus one innocent victim. The reader has to find both — and notice that restarting the victim (`display_app`, the visible symptom) would achieve nothing.

**You diagnose a deadlock from six lines of text, with no debugger and no source code.** That's why `pidin` is worth learning properly rather than treating as `ps` with a different name.

---

### What changed on disk

`Chapter07_FirstContactTheQNXShell.md` (new, 992 lines) · Glossary **+6** with a new **K** section and **blocking state** de-seeded · **block V12** added · disk corrections across `PLAN.md`, Setup Guides 01–03, Chapters 05–06, `check-environment.sh`, D-008 · `DecisionsLog` Session 019 · TOC, README, indexes, trackers. Link check across all eight chapters: **zero broken**.

---

## 👉 Seven blocks open — two I'd single out

| | | |
|---|---|---|
| ⭐ **V11.2** | `head -60 output/build/ifs.build` and `cat output/build/disk.layout` | **Still the highest-value request** — it turns Chapter 21 into a walkthrough of *your* system |
| **V12.1** | `pidin \| awk '{print $5}' \| sort \| uniq -c \| sort -rn` | Four commands. Becomes the course's documented **healthy-system baseline**, which Chapter 25's `⭐ L25` needs to teach recognising an unhealthy one |

Both are cheap, and both serve chapters far ahead. I've recorded the dependency in the decisions log so it's visible when those chapters get written.

**Next: ⭐ Chapter 08 — The Toolchain & Deployment**, which closes Part 1 and is a `⭐ core` lab: cross-compiling in earnest, QNX's recursive Makefiles, and **remote debugging** — `gdb` on your host attached over the network to a process on the target via `qconn`, which has been sitting in `slm`'s component list since Chapter 06.

After that, **Part 2 begins the microkernel itself.**

---

## PROMPT#19

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 020 |
| **Context** | Chapter 07 published; the learner asked for the next chapter, which closes Part 1. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> proceed to next

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 🎉 Chapter 08 published — Parts 0 and 1 complete (9/34)

1177 lines, containing **core lab L08**, and shipping `labs/lab08_devloop/`.

```text
Part 0  Orientation   [████████████████████] 100 %  (4/4) 🎉
Part 1  Environment   [████████████████████] 100 %  (5/5) 🎉
OVERALL               [█████               ]  26 %  (9/34)
```

## The chapter's centre: symbols stay on the host

Chapter 08 could have been a `qcc` flag reference. Instead it's built around **remote debugging**, and specifically one design decision:

> `gdb` runs on **your host** with the debug information. `qconn` on the target does *control* and speaks only in **addresses and raw memory**. Nothing that knows a function name ever crosses the network.

That single idea explains three things at once: why a production target can ship a **stripped** binary and stay fully debuggable, why Chapter 05's `.sym` files exist, and why core-dump analysis works the way Chapter 25 will describe.

**And it comes with a cost, given equal weight.** Nothing verifies the target binary is the one your host has symbols for — so **mismatched builds produce confident, detailed, entirely fictional answers.**

> That's worse than a crash. A crash tells you something is wrong. Here `gdb` insists you're stopped in `beta()` while the target prints `ALPHA`, and you'll believe it for as long as it takes to notice.

The 💥 exercise reproduces it deliberately. The remedy offered is structural, not vigilance: **never deploy by hand** — make `run` and `debug` depend on `deploy`, which depends on the build.

## §5 — finding a bug you can't see

An off-by-one buffer overrun that `-Wall -Wextra` **cannot** catch (the compiler doesn't know `count`'s value at the call site). Found with `print r[4]` rather than by reading.

And the argument for why this matters more here than elsewhere:

> `printf` debugging **changes timing**, and on a real-time system that changes the bug. It can hide a race, create one, or move a deadline miss out of reach — then it vanishes when you remove the `printf`.

That's why remote debugging is a `⭐ core` skill in this course rather than a convenience.

## The lab inverts skeleton and solution

`labs/lab08_devloop/` breaks Chapter 00's convention deliberately:

| | Usual | Here |
|---|---|---|
| `skeleton/` | `TODO`s to fill in | A **complete, compiling, subtly wrong** program |
| `solution/` | The reference implementation | The **fix** |

Because the exercise is *debugging*, not writing. The README says so and tells you **not to open `solution/` first**; the Makefile defaults to the skeleton so `make run` builds the buggy one without you choosing.

The Makefile also catches Chapter 05 §5.3's silent failure at build time:

```make
@if file $@ | grep -q 'ldqnx' && file $@ | grep -q 'x86-64'; then \
   echo "OK: QNX x86_64 binary"; else echo "WARNING: ..."; fi
```

## ⚠️ What's verified, and what isn't

**Carried from your runs:** GCC 12.2.0 and the six targets · `qconn` running, started by `slm` · SSH needs `qnxuser` · `/data` is writable.

**Predicted, never observed:**

| Prediction | Where |
|---|---|
| `target qnx <ip>:8000` is the right incantation | §3.4 — **the chapter's central mechanism** |
| `info pidlist` / `attach` work through `qconn` | §3.4 |
| `upload` copies over the debug link | §4.4 |
| A symbol mismatch gives nonsense rather than an error | 💥 |

As with Chapter 05, **the most important claim is the least evidenced**, and the chapter says so where it matters.

---

### What changed on disk

`Chapter08_ToolchainAndDeployment.md` (new, 1177 lines) · **`labs/lab08_devloop/`** (Makefile, buggy skeleton, fixed solution, README) · Glossary **+5** · **block V13** · TOC tag gains 🐣 (ADR-008 again — the Path A activity *reads* a debugging session) · `DecisionsLog` Session 020 · all trackers. Link check across nine chapters: **zero broken**.

---

## 👉 Block V13 is the one to do

Eight blocks are open, but this is **the most consequential since V5** — every chapter from 09 onwards assumes the loop works:

```bash
host$ source ~/qnx800/qnxsdp-env.sh
host$ export TGT=$(cd ~/qnx800/images/qemu/qemu && mkqnximage --getip)
host$ cd ~/exercises/qnx-zero-to-hero/labs/lab08_devloop
host$ make TGT=$TGT run
host$ make TGT=$TGT debug
```

Then in `gdb`: `break sum_readings`, `run`, step until `i` is 4, and `print r[4]`.

**What I most want back is the `gdb` session itself.** `target qnx <ip>:8000`, `info pidlist` and `attach` are all asserted from reasoning; if any of the syntax is wrong, `help target` inside `gdb` will give the real form.

**Next: Part 2 begins — Chapter 09, Microkernel Architecture & `procnto`.** What's actually inside the kernel, why a driver crash is survivable, and how a system assembled from cooperating processes stays fast enough to be worth it. This is where QNX stops resembling Linux, and where your remaining core labs live — **L13** and **L14** are message passing, the centre of the whole course.

---

## PROMPT#20

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 021 |
| **Context** | Parts 0 and 1 complete; the learner asked for the chapter that opens Part 2. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> proceed to chapter 09

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

# 📕 Chapter 09 — Microkernel Architecture & `procnto` (10/34)

1004 lines. **Part 2 begins**, and this is the chapter the rest of it rests on.

## The organising sentence

> **POSIX on top, messages underneath.**

`read(fd, buf, n)` on Linux enters the kernel. On QNX it becomes `MsgSend` to a **user-space process** — and your source is identical. That one sentence does three jobs:

- explains why your Linux C compiles unchanged
- explains why writing a QNX driver means writing a **program**, not patching a kernel
- explains why QNX's kernel-call list has been essentially stable since 1995 while Linux has grown to ~400 syscalls — new QNX functionality arrives as **new servers**, not new kernel entry points

## Fault isolation, mechanically rather than as a slogan

Chapter 02 made the claim. Chapter 09 walks the page tables:

> The bad pointer cannot reach your memory because your pages are **not mapped** in the driver's address space. Not "protected by convention" — **absent**. There is no address it could compute that would reach you.

Then `procnto`'s seven-step teardown — free memory, close connections, destroy channels, remove paths, detach interrupts, notify watchers, and the one that matters:

> ⭐ **Wake every client blocked on it, with an error.**

Without that step, isolation alone would leave every client stuck in `REPLY` forever, waiting on a process that will never answer.

## The half I'm most pleased with: what is *not* survivable

§3.3 and §4.3 are as long as the isolation argument:

| Not survivable | Why |
|---|---|
| `procnto` faulting | It *is* the scheduler |
| A driver misusing hardware it legitimately controls | Memory is protected; **the device is not** |
| ⚠️ **Deadlock** | **Nothing faults, so nothing detects it** |

**Deadlock is the one that matters**, because it's where the chapter's own subject stops helping. Every other entry is about failing *loudly*. It's also the retrospective justification for Chapter 07 — `pidin` is the only thing that finds a failure the kernel cannot.

And the hardware row is the sharpest case: **the driver is not faulty.** It had legitimate access and used it as instructed. Memory protection is irrelevant. That needs abilities and security policies — Chapter 28.

## §5's lesson

The obvious ending for this chapter is *"and the system survived"*. I went one step further, to the client:

> **The microkernel converts another process's catastrophe into your `errno`.** What you do with it is the part it cannot help you with.

A client that ignores `MsgSend`'s return value inherits the crash it was supposedly protected from. That's the honest meaning of "QNX is robust" — not *nothing goes wrong*, but *everything that goes wrong arrives at your code as an error, at a point where you can act on it*.

Also: a 🔬 deep dive on why first-generation microkernels lost the throughput argument (Mach survives as a hybrid inside macOS) and QNX didn't — synchronous IPC as *the* system call mechanism rather than one service among many, plus priority inheritance built into messaging.

---

### What changed on disk

`Chapter09_MicrokernelArchitecture.md` (new, 1004 lines) · **`labs/lab09_faultisolation/`** · Glossary **+4** (address space, kernel call, blast radius, `ESRCH`) · **block V14** · `DecisionsLog` Session 021 · all trackers. Link check across ten chapters: **zero broken**.

---

## 👉 Where things stand

```text
Part 0  [████████████████████] 100 %  (4/4) 🎉
Part 1  [████████████████████] 100 %  (5/5) 🎉
Part 2  [██                  ]  14 %  (1/7)
OVERALL [█████               ]  29 %  (10/34)
```

**Block V13 is still the priority** — core lab L08, the development loop. Everything from here builds and debugs code, so it's the block that unblocks the most.

**V14.3 is the interesting new one.** It tests Chapter 09's central mechanical claim in four commands: kill a server while a client is blocked on it, and see whether the client is *woken with an error* or *stuck in `REPLY` on a PID that no longer exists*. If it's the latter, §3.2 is wrong and I'll rewrite it.

There are now **three blocks that exist to serve later chapters** — V11.2 → Chapter 21, V12.1 and V14.4 → Chapter 25. All cheap, all materially change what those chapters can be. I've recorded them together in the decisions log so the dependency is visible when I get there.

**Next: Chapter 10 — Processes and Threads.** The process model, address spaces, thread lifecycle, how `pthread_*` maps onto `ThreadCreate` — and why QNX schedules **threads** rather than processes, which is the fact behind every `pidin` listing you've read.

---

## PROMPT#21

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 022 |
| **Context** | The learner hit a permission failure on the first run of core lab L08. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I am facing some permission issue while performing lab08. "tyrostir@APT-CR-5ZSYVG3:~/exercises/qnx-zero-to-hero/labs/lab08_devloop$ make TGT=$QTGT run
> scp avg qnxuser@192.168.122.46:/data/
> ** WARNING: connection is not using a post-quantum key exchange algorithm.
> ** This session may be vulnerable to "store now, decrypt later" attacks.
> ** The server may need to be upgraded. See https://openssh.com/pq.html
> scp: dest open "/data/avg": Permission denied
> scp: failed to upload file avg to /data/
> make: *** [Makefile:50: deploy] Error 1" and I tried directly on qnx seiral terminal. "[qnxuser@qnxqemu /data]$ mkdir avg
> mkdir: 'avg': Permission denied"

### Standing instructions

*(None new.)*

### Response (full)

> *Reproduced as delivered.*

---

**My error, not your setup.** Here is the unblock:

```bash
host$ cd ~/exercises/qnx-zero-to-hero
host$ git pull
host$ cd labs/lab08_devloop
host$ make TGT=$QTGT run
```

The Makefile now deploys to `/data/home/qnxuser` instead of `/data`. If you would rather not pull yet:

```bash
host$ make TGT=$QTGT DEST=/data/home/qnxuser run
```

## What is actually wrong

**`/data` is the writable *partition*. Its root *directory* is owned by `root`.**

Those are different claims, and I conflated them. Chapter 06 §3.3 correctly established that `/data` is the only partition where changes survive a reboot — and then Chapters 06, 07, 08 and 09 all slid from that into *"deploy to `/data`"*, which does not follow. Like any Unix directory, `/data` has an owner and a mode.

**Your home is on that partition and is yours** — `/data/home/qnxuser`, exactly as `/etc/passwd` showed back in [D-011](docs/meta/Doubts.md#d-011). So it is both writable and persistent.

| Destination | Writable by you? | Survives reboot? | |
|---|---|---|---|
| **`~` = `/data/home/qnxuser`** | ✅ | ✅ | ⭐ the default now |
| `/tmp` | ✅ | ❌ RAM | throwaways |
| `/data` | ❌ root-owned | ✅ | only with `sudo` |

## Your `mkdir` was the right move

```text
[qnxuser@qnxqemu /data]$ mkdir avg
mkdir: 'avg': Permission denied
```

That one command **eliminated SSH, `scp` and the network** and proved it was ordinary filesystem permissions. That is exactly the right instinct — reduce the failing thing to the smallest command that still fails.

> 🐣 The `post-quantum key exchange` warning above it is unrelated and harmless — your host's OpenSSH 10.2 noting that the target's older `sshd` doesn't offer PQ key exchange. It's in Setup Guide 03 §9.3.

## The general lesson, which I've written into the course

> *"The partition is writable"* and *"you can write there"* are different claims.

And the reassuring half: **this was not a QNX exotic.** Unix permissions apply normally here. The genuinely unusual parts of this filesystem are `/proc/boot` (a mounted 20 MB file) and the read-only system partition — **everything else behaves exactly as you'd expect on Linux**, including the bit that just stopped you.

I've recorded that as a check rather than an observation: *before telling a reader to write somewhere, confirm the **directory** is writable by the **account** they'll use, not merely that the filesystem is.*

## Fixed

**D-015** written in full. Corrected in **Chapter 06 → v1.2**, **Chapter 07 → v1.1**, **Chapter 08 → v1.1**, **Chapter 09 → v1.1**, both lab Makefiles (`DEST ?= /data/home/$(USER)`), both lab READMEs, and the Glossary. Chapter 08's troubleshooting table now carries **the exact error text**, so the next reader finds it by searching for what they actually saw.

## 📌 This is the fourth published claim caught by running it

| # | Claim | How it was wrong | Found by |
|---|---|---|---|
| 1 | `-listAvailablePackages` | Doesn't exist | Running it |
| 2 | Customer demos forbidden | Exactly backwards | Reading the licence |
| 3 | Disk image probably sparse | It isn't; total ~40 GB low | Running `du` |
| **4** | **Deploy to `/data`** | **Root-owned** | **Running the lab** |

All four plausible, well-sourced and wrong. **Three of the four were caught by you executing something** — which is the whole argument for the `[UNVERIFIED]` protocol.

---

## 👉 Back to it

```bash
host$ git pull && cd labs/lab08_devloop && make TGT=$QTGT run
```

Then the part I most want back — **block V13.2**:

```bash
host$ make TGT=$QTGT debug
(gdb) break sum_readings
(gdb) run
(gdb) next          # until i reaches 4
(gdb) print r[4]
```

And while you're on the target, two commands that settle what I had to infer:

```bash
qnx$ ls -ld /data /data/home /data/home/qnxuser
qnx$ id
```

I deduced `/data`'s ownership from your failure; I've never seen the actual modes.

---

## PROMPT#22

| | |
|---|---|
| **Date** | 2026-08-26 |
| **Agent** | Claude (Opus 5) via Claude Code |
| **Session** | 023 |
| **Context** | Lab 08.1, step 5 — `attach` to an already-running process. |
| **Status** | ✅ Answered |

### Prompt (verbatim)

> I have a problem when performing Step 5 - attach to something already running. "[qnxuser@qnxqemu /data/home]$ sleep 600 &
> [1] 1540128
> [qnxuser@qnxqemu /data/home]$ pidin | grep sleep
>  1540128   1 usr/bin/sleep                 10r NANOSLEEP
> [qnxuser@qnxqemu /data/home]$ " and "tyrostir@APT-CR-5ZSYVG3:~/qnx800/images/qemu/qemu$ ntox86_64-gdb
> GNU gdb (qnx800-gdb-14.2-release-55-g85f1a3-dev) 14.2
> Copyright (C) 2023 Free Software Foundation, Inc.
> License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
> This is free software: you are free to change and redistribute it.
> There is NO WARRANTY, to the extent permitted by law.
> Type "show copying" and "show warranty" for details.
> This GDB was configured as "--host=x86_64-pc-linux-gnu --target=x86_64-nto-qnx8.0.0".
> Type "show configuration" for configuration details.
> For bug reporting instructions, please see:
> <https://www.gnu.org/software/gdb/bugs/>.
> --Type <RET> for more, q to quit, c to continue without paging--
> Find the GDB manual and other documentation resources online at:
>     <http://www.gnu.org/software/gdb/documentation/>.
>
> For help, type "help".
> Type "apropos word" to search for commands related to "word".
> (gdb) target qnx 192.168.122.46
> ^C(gdb) target qnx 192.168.122.46:8000
> Remote debugging using 192.168.122.46:8000
> MsgNak received - resending
> Remote target is little-endian
> (gdb) info pidlist
> /proc/boot/procnto-smp-instr - 1/26
> /proc/boot/procnto-smp-instr - 1/27
> /proc/boot/procnto-smp-instr - 1/28
> /proc/boot/procnto-smp-instr - 1/29
> /proc/boot/procnto-smp-instr - 1/30
> /proc/boot/procnto-smp-instr - 1/31
> /proc/boot/procnto-smp-instr - 1/32
> /proc/boot/procnto-smp-instr - 1/37
> /proc/boot/procnto-smp-instr - 1/40
> /proc/boot/procnto-smp-instr - 1/41
> /proc/boot/procnto-smp-instr - 1/42
> proc/boot/slm - 16386/1
> --Type <RET> for more, q to quit, c to continue without paging--Quit
> (gdb) attach 1540128
> usr/bin/sleep: No such file or directory.
> (gdb) "

### Standing instructions

SI-1…SI-14 all in force. Relevant here: **ADR-024** (only learner-pasted output clears an
`[UNVERIFIED]` marker), **SI-8** (Tier 1 must not reveal the two-machine split), **SI-5/SI-6**
(prompt and full response logged here).

### Response (full)

**Nothing is broken. Three of the four things in that paste are good news, and the fourth is the
chapter's own design showing itself.**

#### 1. ✅ You just verified Chapter 08's central mechanism

`target qnx 192.168.122.46:8000` → *"Remote debugging using 192.168.122.46:8000"*, and `info pidlist`
listing the target's processes. **Both of those were `[UNVERIFIED]`** — asserted from documentation
and reasoning, never observed. They are now confirmed on GDB **14.2**, target `x86_64-nto-qnx8.0.0`.

The output format is `path - pid/tid`, so `procnto-smp-instr` appears eleven times (one line per
thread) — which is itself a nice preview of Chapter 10.

`MsgNak received - resending` is **benign** — a retransmit in the `qconn` protocol. The session
proceeded normally, which is the proof.

#### 2. 🆕 The port is mandatory, and omitting it *hangs*

```text
(gdb) target qnx 192.168.122.46      ← hung; you had to Ctrl+C
(gdb) target qnx 192.168.122.46:8000 ← worked
```

A silent hang is the worst failure mode a documented command can have — you cannot tell a wrong
command from a slow network. **This is now stated wherever the command appears in the course.** Good
catch, and it was free: you found it by mistyping.

#### 3. ❌ Why `attach` failed

```text
(gdb) attach 1540128
usr/bin/sleep: No such file or directory.
```

**`gdb` is looking for that file on your *host*, not on the target — and it is right to.**

`attach` does two separate jobs:

| | Where it happens | Did it work? |
|---|---|---|
| **Control** — stop the process, read its registers and memory | On the **target**, through `qconn` | ✅ Yes |
| **Interpretation** — turn addresses into function names, lines, types | On the **host**, from a copy of the binary | ❌ **No copy to read** |

`info pidlist` printed `usr/bin/sleep` — a path **on the target**. `gdb` tried to open it on your
laptop and found nothing.

> ⚠️ **Notice the missing leading slash.** It is relative, so `gdb` searched the directory you
> started it from. And `/usr/bin/sleep` would have been **worse** — on Ubuntu that file *exists*, and
> `gdb` would have cheerfully loaded **Linux's** `sleep` and reported its symbols as gospel. That is
> Chapter 08's 💥 exercise, reached by accident.

#### 4. The fix — where a target utility's symbols live on your host

Chapter 05 §2.2 said `$QNX_TARGET/x86_64/` is *a faithful image of a QNX filesystem*. Here is the
payoff:

```text
target:  /usr/bin/sleep
host:    $QNX_TARGET/x86_64/usr/bin/sleep     ← the same binary, with symbols
```

So:

```bash
host$ ntox86_64-gdb $QNX_TARGET/x86_64/usr/bin/sleep
(gdb) target qnx 192.168.122.46:8000
(gdb) attach 1540128
(gdb) backtrace
(gdb) detach
```

Two alternatives:

```bash
(gdb) file /home/tyrostir/qnx800/target/qnx/x86_64/usr/bin/sleep   # after connecting
host$ ntox86_64-gdb -ex "set sysroot $QNX_TARGET/x86_64"           # point at the whole tree
```

> 💡 In the last one the **shell** expands `$QNX_TARGET` before `gdb` sees it. `gdb` does **not**
> expand shell variables — inside `gdb`, type the literal path.

**For your own programs this never comes up**, because the host copy is already in your hand:

```bash
host$ ntox86_64-gdb avg
(gdb) target qnx 192.168.122.46:8000
(gdb) attach <pid>
```

#### 5. 💡 Why this failure is worth more than a success would have been

§3.4 claims that symbols stay on the host and only addresses cross the network. Look at what your
session demonstrated: `gdb` had a live connection, the target's complete process list, and the power
to stop and inspect any process on it — **and still could not proceed without one local file.**

| Crossed the network | Did not |
|---|---|
| Control: stop, continue, registers, memory | Symbols |
| Addresses | Names, types, line numbers |
| The process list | **The meaning of anything in it** |

A successful `attach` would have shown the mechanism working. **This showed you where the seam is.**

#### 6. What I changed

The chapter's *claim* was right; the gap was between the claim and the recipe. Steps 1–4 always had
the binary loaded, so the requirement never surfaced — and step 5 was the first place it mattered.

**Chapter 08 → v1.2:**

- **§3.4** — the local-copy requirement, the exact error text, and all three remedies
- **§4.4** — `info pidlist`'s output format; `attach`'s prerequisite; **`set sysroot`** added
- **Fast-Track, recap, cheat sheet, troubleshooting table** — the port requirement and the `attach`
  prerequisite, with the error text verbatim so a reader finds it by searching for what they saw
- **Lab 08.1 step 5 split in two**: **5a** attaches to *your own program* (the realistic case);
  **5b** keeps `sleep` **precisely because it forces the `$QNX_TARGET` question**. Your failure is
  kept in the lab and explained, not engineered away

**Also:** **D-016** written in full · hazard **H-15** · Glossary's `qconn` and *Sysroot* entries
sharpened · **V13.3 recorded as partially verified** with V13.3b added for the retry · **T-030**
(retry step 5) and **T-031** (finish V13.2 — `break`, `print r[4]`, `upload`) added.

#### 📋 Two things to run when you have a moment

```bash
# T-030 — 5a: your own program
qnx$  ~/avg &
host$ ntox86_64-gdb avg
(gdb) target qnx 192.168.122.46:8000
(gdb) attach <pid>
(gdb) backtrace
(gdb) detach

# T-030 — 5b: the target utility, with symbols this time
qnx$  sleep 600 &
host$ ntox86_64-gdb $QNX_TARGET/x86_64/usr/bin/sleep
(gdb) target qnx 192.168.122.46:8000
(gdb) attach <the sleep pid>
(gdb) backtrace
(gdb) detach
```

I would expect `backtrace` on the sleeping process to show `nanosleep` in the frame list —
consistent with `pidin`'s `NANOSLEEP` state. **That is still unobserved**, so please paste it.

**The running scoreboard:** five of the six claims tested by execution so far were *found* by
execution — four wrong, one right-but-incomplete. None was found by re-reading the draft.

**Next chapter is 10 — Processes and Threads**, whenever you are ready.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 2.20 | 2026-08-26 | PROMPT#22 logged: `attach` diagnosed; Chapter 08's `qconn` connection verified for the first time. |
| 2.19 | 2026-08-26 | PROMPT#21 logged: the deploy-path error and its correction. |
| 2.18 | 2026-08-26 | PROMPT#20 logged: Chapter 09; Part 2 begins. |
| 2.17 | 2026-08-26 | PROMPT#19 logged: Chapter 08; Parts 0 and 1 complete. |
| 2.16 | 2026-08-26 | PROMPT#18 logged: disk corrections and Chapter 07. |
| 2.15 | 2026-08-26 | PROMPT#17 logged: Chapter 06, the first core chapter. |
| 2.14 | 2026-08-26 | PROMPT#16 logged: Chapter 05 published. |
| 2.13 | 2026-08-26 | PROMPT#15 logged: Chapter 04 published; a published licensing error corrected. |
| 2.12 | 2026-08-26 | PROMPT#14 logged: Chapter 03 published, Part 0 complete. |
| 2.11 | 2026-08-26 | PROMPT#13 logged: Chapter 02 published. |
| 2.10 | 2026-08-26 | PROMPT#12 logged: a course rule gap found by the learner and fixed at rule level. |
| 2.9 | 2026-08-26 | PROMPT#11 logged: Chapter 01 and the first compiled lab. |
| 2.8 | 2026-08-26 | PROMPT#10 logged: Chapter 00 published. |
| 2.7 | 2026-08-26 | PROMPT#9 logged: block V5 complete, Phase 1 complete. |
| 2.6 | 2026-08-26 | PROMPT#8 logged: milestone M2 reached; SSH-as-root diagnosed. |
| 2.5 | 2026-08-26 | PROMPT#7 logged: V5.3 diagnosed and unblocked; `/btw` convention adopted. |
| 2.4 | 2026-08-26 | PROMPT#6 logged: Setup Guide 03 published. |
| 2.3 | 2026-08-26 | PROMPT#5 logged: blocks V2–V4 complete, all `[UNVERIFIED]` markers cleared. |
| 2.2 | 2026-08-26 | PROMPT#4 logged: name spelling correction and Block V2 completion. |
| 2.1 | 2026-08-26 | PROMPT#3 logged: Block V1 verification results and the Git identity change. |
| 2.0 | 2026-08-26 | **ADR-023 adopted:** full agent responses are now logged alongside prompts. PROMPT#1's response back-filled; PROMPT#2 added. Marked Tier 3 per ADR-022. |
| 1.0 | 2026-08-26 | Created at the Copilot → Claude handover. PROMPT#1 logged. |
