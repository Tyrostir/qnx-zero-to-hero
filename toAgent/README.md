---
title: "toAgent — Learner → Author Handoff Drop"
document_id: TOAGENT
version: 1.0
status: Active
created: 2026-08-26
last_updated: 2026-08-26
audience: "The learner and the AI author only (Tier 3 — internal, per ADR-022)"
---

# 📥 toAgent/ — Learner → Author Handoff Drop

> ⛔ **Tier 3 — internal working directory.** Not part of the QNX course, not linked from the Table
> of Contents, never included in the PDF book (ADR-022).

**What this is for.** Raw output the learner captures on the host and hands to the author: terminal
transcripts, error messages, screenshots of licence portal wording, `check-environment.sh` reports.

**Why it exists.** The author cannot execute commands (**ADR-024**). Pasted output is the *only*
thing that can clear an `[UNVERIFIED]` marker. Dropping it in a file is easier and more faithful than
pasting a long transcript into a chat message, and it keeps the evidence in version control.

---

## Naming convention

```text
toAgent/<n>.<WhatItIs>.md
```

`<n>` increments. Examples:

| File | Contents |
|------|----------|
| `1.BlockV1Output.md` | Terminal output from `VerificationRuns.md` Block V1 |
| `2.BlockV2Licence.md` | Licence portal wording and timings |

---

## What makes a good drop

- **Raw output, not a summary.** "It worked" is not evidence; the text is.
- **The command as well as its output**, so the two can be matched up.
- **Failures included.** A failure means the guide is wrong for a real machine — that is exactly what
  needs finding. Errors are as valuable as successes.
- **Don't hand-edit the transcript.** Line-wrap artefacts and truncation are fine; the author will
  work around them.

---

## Index

| # | File | Block | Date | Outcome |
|---|------|-------|------|---------|
| 1 | `1.BlockV1Output.md` | **V1** — host preparation | 2026-08-25 | ✅ `19 passed · 6 warnings · 0 failed`. T-008 and T-009 cleared; Setup Guide 01 → v2.0; Risks R3 and R9 closed. |
| 2 | `2.BlockV2V3V4Output.md` | **V2 · V3 · V4** — licence, SDP install, toolchain proof | 2026-08-26 | ✅ `24 passed · 3 warnings · 0 failed`. SDP 8.0 at `~/qnx800`; cross-compile proven; Setup Guide 02 → v2.0; Risk R2 closed. **Found 3 real bugs in the guide.** T-202 (SDP build number) not captured. |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.1 | 2026-08-26 | Drop 2 indexed (blocks V2–V4). |
| 1.0 | 2026-08-26 | Created after the first drop (Block V1). |
