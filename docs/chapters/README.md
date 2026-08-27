---
title: "Chapters — Index"
document_id: CHAPTERS-INDEX
version: 1.0
status: Active
created: 2026-08-25
---

# 📖 docs/chapters/

The course itself. Chapters are published in order and appear here as they are written.

## Published

| # | Chapter | Paths | Time |
|---|---------|-------|------|
| 00 | [How To Use This Course](Chapter00_HowToUseThisCourse.md) | 🐣🚶🏃 | 25 m |
| 01 | [What Is a Real-Time System?](Chapter01_WhatIsARealTimeSystem.md) | 🐣🚶🏃 | 60 m |
| 02 | [What Is QNX?](Chapter02_WhatIsQNX.md) | 🐣🚶🏃 | 75 m |


> 📑 Full chapter list with status, path tags and time estimates:
> **[../TableOfContents.md](../TableOfContents.md)**
> 📍 Current progress: **[../meta/CourseState.md](../meta/CourseState.md)**

---

## Naming

```text
ChapterNN_PascalCaseTitle.md
```

`NN` is a zero-padded, monotonically increasing chapter number (`00`–`34`).

## Structure

Every chapter follows the mandatory template defined in
[`../PLAN.md` §5 — Chapter anatomy](../PLAN.md#5-chapter-anatomy):

| Section | Purpose |
|---------|---------|
| YAML front matter | Chapter number, part, paths, time, prerequisites, status, SDP version |
| `# Chapter NN — Title` | Single H1 |
| One-sentence promise | "By the end of this chapter you will…" |
| 🏃 Fast-Track Summary | Path C reads only this |
| 🎯 Learning Objectives | Checkbox list |
| 🧭 Prerequisites | Links to earlier chapters |
| 🗺️ Mental model | A Mermaid diagram, always |
| 1. The Problem | Why this exists |
| 2. The Concept | Plain-English, includes 🐧 Linux comparison |
| 3. The Mechanism | How QNX actually does it |
| 4. The API | Signatures, parameters, returns |
| 5. Worked Example | Fully annotated code |
| 🧪 Labs | Tagged by path, `⭐` marks core labs |
| 💥 Break It | Deliberate-failure exercise |
| ✅ Mastery Check | 5 questions with collapsed answers |
| 🧠 Concept Recap | Bullet summary |
| 📎 Cheat Sheet | Everything introduced, in a table |
| 🔗 Further Reading | Into `../reference/ReferenceLinks.md` |
| ➡️ What's Next | |
| 📝 Chapter Changelog | |

## Reading symbols

| Symbol | Meaning |
|--------|---------|
| 🐣 | Path A — Absolute Beginner |
| 🚶 | Path B — Self-Learner |
| 🏃 | Path C — Fast-Track Pro |
| ⭐ | Core lab — do this one regardless of path |
| 💡 | Insight worth remembering |
| ⚠️ | Something that will bite you |
| 🐧 | "In Linux this would be…" |
| 🔬 | Optional deep dive |
| 💥 | Break-it exercise |
| 📖 | First use of a glossary term |
