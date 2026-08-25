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

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 2.0 | 2026-08-26 | **ADR-023 adopted:** full agent responses are now logged alongside prompts. PROMPT#1's response back-filled; PROMPT#2 added. Marked Tier 3 per ADR-022. |
| 1.0 | 2026-08-26 | Created at the Copilot → Claude handover. PROMPT#1 logged. |
