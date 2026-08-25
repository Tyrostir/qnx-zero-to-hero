---
title: "docs/internal — Internal Working Documents (NOT part of the course)"
document_id: INTERNAL
version: 1.0
status: Active
created: 2026-08-26
last_updated: 2026-08-26
audience: "AI author agents and the learner only — never the end reader"
---

# 🔒 docs/internal — Internal Working Documents

> ⛔ **Nothing in this directory is part of the QNX course.**
>
> These documents exist so that an AI author agent can be replaced mid-project without losing
> context. They are **operational**, not **educational**.

---

## Who reads what — the three document tiers (ADR-022)

| Tier | Location | Audience | Rule |
|------|----------|----------|------|
| 📗 **Tier 1 — Course** | `README.md`, `docs/PLAN.md`, `docs/TableOfContents.md`, `docs/chapters/`, `docs/guides/`, `docs/reference/` | **The end reader.** Anyone who finds this repo. | Describes **exactly one machine**: the learner's laptop, Ubuntu 26.04 on WSL2. |
| 📘 **Tier 2 — Course bookkeeping** | `docs/meta/` | The learner, and readers curious how the course is made. Included in the PDF book. | Progress, decisions, doubts. **Must stay reader-safe** — no authoring-infrastructure detail. |
| 🔒 **Tier 3 — Internal** | **this directory**, plus `PROMPTS.md` and `COPILOT_PROMPT_HISTORY.md` at the repo root | **AI agents and the learner only.** | Everything else: the two-machine authoring split, agent handover, session mechanics, raw prompt logs. |

**Tier 3 is excluded from the PDF book automatically** — `tools/build-pdf.sh` enumerates Tier 1 and
Tier 2 by explicit path and never globs `docs/internal/`.

---

## Contents

| File | Purpose | Read when |
|------|---------|-----------|
| [`CLAUDE-MEMORY.md`](CLAUDE-MEMORY.md) | **The agent's brain dump.** Everything known about the learner, the environment, the QNX facts, the decisions, and the operating rules — in one file. | **First.** Always. |
| [`NewAgentOnboardingGuide.md`](NewAgentOnboardingGuide.md) | How a brand-new agent takes over this project: what to read, in what order, what it may and may not do, and how to verify it is properly oriented. | You are a new agent |
| [`NewAgentOnboardingPrompts.md`](NewAgentOnboardingPrompts.md) | Copy-paste prompts **the learner** sends to a new agent to bootstrap it in one message. | You are the learner, starting a new agent |
| [`VerificationRuns.md`](VerificationRuns.md) | The `[UNVERIFIED]` clearance protocol: what the learner must run on the laptop, and where results get pasted. | Clearing `[UNVERIFIED]` markers |

---

## The one rule that matters most

> 🚨 **Never let Tier 3 information leak into Tier 1 or Tier 2.**
>
> The end reader must believe — correctly, from their point of view — that this course was written
> on and for a single Ubuntu 26.04 / WSL2 laptop. The authoring environment is not part of the
> story, adds nothing pedagogically, and would only confuse. See
> [`CLAUDE-MEMORY.md` § The Two-Machine Split](CLAUDE-MEMORY.md#-the-two-machine-split-tier-3-only).

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-26 | Created at the Copilot → Claude handover (Session 003). Establishes the three document tiers per ADR-022. |
