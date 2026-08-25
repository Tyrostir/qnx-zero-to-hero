---
title: "New Agent Onboarding Prompts"
document_id: ONBOARD-P
version: 1.0
status: Active
created: 2026-08-26
last_updated: 2026-08-26
audience: "The learner — prompts to paste into a new AI agent (Tier 3 — internal)"
---

# 📋 NewAgentOnboardingPrompts.md

> ⛔ **Tier 3 — internal.** Not part of the course.
>
> **This file is for you, the learner.** When you start a new AI agent on this project — because
> credits ran out, or you switched tools — copy one of the prompts below and paste it as your very
> first message. The agent will read itself into full context without you explaining anything.

---

## Contents

- [Prompt 1 — Cold start (use this one)](#prompt-1--cold-start-use-this-one)
- [Prompt 2 — Minimal cold start](#prompt-2--minimal-cold-start)
- [Prompt 3 — Resume after a long gap](#prompt-3--resume-after-a-long-gap)
- [Prompt 4 — Verify an agent is properly oriented](#prompt-4--verify-an-agent-is-properly-oriented)
- [Prompt 5 — Hand over / wind down the current agent](#prompt-5--hand-over--wind-down-the-current-agent)
- [Prompt 6 — Correct an agent that has drifted](#prompt-6--correct-an-agent-that-has-drifted)
- [If the agent has no file access](#if-the-agent-has-no-file-access)
- [Maintenance](#maintenance)

---

## Prompt 1 — Cold start (use this one)

> Use for any new agent with file-system access to the repository. This is the default.

```text
You are taking over as the author of an existing course-writing project. You have no memory
of it, and I am not going to re-explain it — the repository explains itself.

Before you do anything else, read these files, in this order:

  1. docs/internal/CLAUDE-MEMORY.md            <- everything known, in one file
  2. docs/internal/NewAgentOnboardingGuide.md  <- your role, constraints, turn protocol
  3. docs/meta/CourseState.md                  <- authoritative current position
  4. docs/meta/CompactContext.md
  5. docs/meta/ToDos.md
  6. docs/meta/Doubts.md                       <- index only
  7. PROMPTS.md                                <- my instructions, verbatim, and prior responses
  8. docs/PLAN.md                              <- sections 2, 5 and 10 at minimum
  9. docs/internal/VerificationRuns.md

Then read docs/guides/Setup_01_Prerequisites.md and
docs/guides/Setup_02_QNX_Account_And_License.md to absorb the house voice.

When you have finished reading, answer the self-check questions in
NewAgentOnboardingGuide.md section 8 in your own words — do not look at the collapsed
answers — and then tell me:

  - what this project is, in three sentences
  - exactly where we are and what the next action is
  - the hard constraints you are operating under
  - anything in the documents that looks stale, contradictory, or wrong

Do not write any course content yet. Wait for my go-ahead.
```

---

## Prompt 2 — Minimal cold start

> For agents with small context windows, or when you want to spend fewer tokens.

```text
Read docs/internal/CLAUDE-MEMORY.md and docs/internal/NewAgentOnboardingGuide.md in full,
then docs/meta/CourseState.md sections 1 and 2.

Summarise: what the project is, where we are, what you may not do, and what the next action
is. Then stop and wait for me.
```

---

## Prompt 3 — Resume after a long gap

> When the same agent — or a new one — picks the project up weeks later.

```text
We are resuming this project after a break. Re-read:

  docs/internal/CLAUDE-MEMORY.md
  docs/meta/CourseState.md
  docs/meta/ToDos.md
  PROMPTS.md  (the last two entries)

Then tell me:
  - where we left off
  - what I still owe you (my open action items)
  - what you still owe me (your open action items)
  - anything that may have gone stale while we were away — especially external QNX
    links and version numbers, which move often

Do not start writing until I confirm.
```

---

## Prompt 4 — Verify an agent is properly oriented

> Send this after a cold start if you want to be sure the agent really read the material. A wrong
> answer here means it is guessing, and it will produce bad chapters.

```text
Quick check before we continue — answer from what you have read, without searching again:

  1. Which learning path am I on, and why must you still write the other two in full?
  2. Which chapter is the centre of gravity of this course, and why?
  3. What are the three verbs of the QNX licence flow, and what breaks if one is skipped?
  4. Name three things you must never run in this environment.
  5. What must the end reader never learn about how this course is produced?
  6. What is the only thing that can clear an [UNVERIFIED] marker?
  7. Which four files receive, respectively: my prompt, your response, a technical
     question, a decision?
  8. How many chapters are published, and what is the next action?
```

**Expected answers** are in `NewAgentOnboardingGuide.md` §8. Pay particular attention to **Q5** —
an agent that gets this wrong will leak internal detail into the course.

---

## Prompt 5 — Hand over / wind down the current agent

> Send this to the *outgoing* agent while it still has credit, so the next one inherits a clean state.

```text
We are ending your run on this project. Before you stop, bring everything up to date so the
next agent needs no explanation from me:

  - PROMPTS.md current through my last prompt and your last response
  - docs/internal/CLAUDE-MEMORY.md regenerated: state, standing instructions, hazards,
    and a new row in the session history table
  - docs/meta/CourseState.md sections 1, 2 and the session log
  - docs/meta/CompactContext.md regenerated (keep it reader-safe — Tier 2)
  - docs/meta/ToDos.md accurate in both directions
  - docs/meta/Doubts.md with no unanswered entries
  - any new decisions recorded as ADR-NNN in BOTH Decisions.md and DecisionsLog.md
  - working tree committed

Then give me a short handover note: what you did, what is half-finished, and what the next
agent should do first.
```

---

## Prompt 6 — Correct an agent that has drifted

> Use the moment you notice a violation. Drift compounds — 34 chapters written the wrong way is a
> rewrite.

```text
Stop. You have drifted from this project's rules. Re-read
docs/internal/NewAgentOnboardingGuide.md sections 5 and 9, and docs/PLAN.md sections 5
and 10.

Specifically, you did this: <describe what went wrong>

Tell me which rule that violated, fix the affected files, and confirm the rule back to me
so I know it has landed.
```

---

## If the agent has no file access

Some agents are chat-only. In that case, paste the **entire contents of
[`CLAUDE-MEMORY.md`](CLAUDE-MEMORY.md)** as your first message, prefixed with:

```text
This is the complete working memory of a course-authoring project you are taking over.
Read it, then tell me what the project is, where we are, and what constraints you are
under. Do not write any course content until I say go.
```

Then paste `NewAgentOnboardingGuide.md` §§4–6 as a second message.

---

## Maintenance

> 🔧 **For the agent, not the learner.**

Keep these prompts working:

- Whenever a file in the reading list is renamed or moved, fix **Prompt 1**.
- Whenever a new hard constraint is agreed, add it to `NewAgentOnboardingGuide.md` §5 **and** add a
  question for it to **Prompt 4** and to the self-check in §8 of the guide.
- Keep every prompt **copy-pasteable as-is** — no placeholders except the one explicitly marked
  `<describe what went wrong>` in Prompt 6.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-26 | Created in Session 003, at the Copilot → Claude handover. Six prompts covering cold start, minimal start, resume, verification, handover, and correction. |
