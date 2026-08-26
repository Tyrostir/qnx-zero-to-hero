---
title: "PROMPTS.md — Learner Prompt & Response Log (Claude sessions)"
document_id: PROMPTS
version: 2.0
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

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
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
