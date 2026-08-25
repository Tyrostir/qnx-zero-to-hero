---
title: "Resources Meta — Rated Review of Learning Materials"
document_id: RESMETA
version: 1.0
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "When a new resource is evaluated, or an existing one is used in anger"
---

# 📚 ResourcesMeta.md

> **What this is.** Not a link dump — [`ReferenceLinks.md`](ReferenceLinks.md) is the link dump.
> This is a **critical review**: for each resource, how good is it, how deep does it go, what does it
> cost, who should use it, and what is it *bad* at.
>
> Honest assessments. Where a resource is weak, this document says so.

**Rating scale**

| | |
|---|---|
| ⭐⭐⭐⭐⭐ | Essential. Use it. |
| ⭐⭐⭐⭐ | Very good. Worth your time. |
| ⭐⭐⭐ | Useful for specific needs. |
| ⭐⭐ | Situational / dated / shallow. |
| ⭐ | Skip unless you have a specific reason. |

**Depth:** 🌱 Intro · 🌿 Working knowledge · 🌳 Deep/reference
**Cost:** 🆓 Free · 🔒 Free w/ account · 💰 Paid
**Paths:** 🐣 A · 🚶 B · 🏃 C

---

## Index

1. [The short version — what to actually use](#1-the-short-version)
2. [Official QNX documentation](#2-official-qnx-documentation)
3. [Official QNX training](#3-official-qnx-training)
4. [Books](#4-books)
5. [Video & podcasts](#5-video--podcasts)
6. [Community & forums](#6-community--forums)
7. [Code to read](#7-code-to-read)
8. [Adjacent background material](#8-adjacent-background-material)
9. [What's missing in the QNX ecosystem](#9-whats-missing-in-the-qnx-ecosystem)
10. [Recommended study stack per path](#10-recommended-study-stack-per-path)

---

## 1. The short version

If you only use four things besides this course:

| # | Resource | Why |
|---|----------|-----|
| 1 | **QNX System Architecture** guide (in the SDP 8.0 docs) | The single best explanation of *why* QNX is shaped the way it is. Written by people who built it. |
| 2 | **QNX Library Reference** (in the SDP 8.0 docs) | Your `man` pages. You will live here. |
| 3 | **Official QNX free online training** | Structured, official, video-based, free. Perfect complement to a text course. |
| 4 | **Official QNX Discord** | Where you get unstuck in hours rather than days. The forums are quieter than they used to be. |

---

## 2. Official QNX documentation

> **Overall: ⭐⭐⭐⭐⭐ · 🌳 Deep · 🆓 Free · 🐣🚶🏃**
> QNX documentation is genuinely excellent — significantly better than most commercial RTOS
> documentation. It is thorough, precise, and honest about limitations. Its weakness is
> *navigability*: it is a set of Eclipse-style "booksets" and finding the right book is half the
> battle.

### The booksets that matter

| Bookset | Rating | Depth | Use it for | Weakness |
|---------|:------:|:-----:|-----------|----------|
| **System Architecture** | ⭐⭐⭐⭐⭐ | 🌿🌳 | *The* conceptual foundation: microkernel, message passing, resource managers, the pathname space. Read this cover to cover — it's the best QNX writing that exists. | Assumes some OS vocabulary; Chapter 01/09 of this course exists partly to prepare you for it. |
| **Programmer's Guide** | ⭐⭐⭐⭐⭐ | 🌿 | How to actually write QNX programs: processes, threads, IPC, resource managers, interrupts. | Examples are terse; not much hand-holding. |
| **Library Reference** | ⭐⭐⭐⭐⭐ | 🌳 | Every API call, with parameters, returns, errno values, blocking behaviour and safety class. | Reference only — you cannot learn *from* it, only *with* it. |
| **Utilities Reference** | ⭐⭐⭐⭐ | 🌳 | Every command-line tool (`pidin`, `slay`, `mkifs`, `use`, `hogs`…). | Dry. Use the cheat sheets in this course for the 90% case. |
| **Building Embedded Systems** | ⭐⭐⭐⭐ | 🌿🌳 | Boot process, IPL, startup, build files, `mkifs`, BSPs. Essential for Part 4. | Genuinely hard on a first read — Chapter 21 of this course is the on-ramp. |
| **QNX Everywhere docs** | ⭐⭐⭐⭐ | 🌱🌿 | The newest, most beginner-friendly doc set. Start here rather than the full SDP bookset. | Narrower coverage; won't take you to expert level. |
| **SDP 8.0 Quick Start Guide** | ⭐⭐⭐⭐ | 🌱 | Getting from "installed" to "running something" fast. | Only covers the happy path — no troubleshooting depth. |
| **QNX Toolkit for VS Code guide** | ⭐⭐⭐⭐ | 🌿 | Our primary IDE workflow. | New product; docs still maturing. |
| **Momentics IDE User's Guide** | ⭐⭐⭐ | 🌿 | Needed for the System Analysis Toolkit GUI. | Eclipse-heavy, dated feel. |
| **Hypervisor bookset** | ⭐⭐⭐⭐ | 🌳 | Chapter 30. | Very specialised; skip until then. |

> 💡 **How to search QNX docs effectively.** Site-restricted search works far better than the
> built-in search: `site:qnx.com/developers/docs/8.0 MsgSend`. Also, the "index terms" page of the
> doc root is an underrated way to find API pages.

---

## 3. Official QNX training

**⭐⭐⭐⭐⭐ · 🌱🌿 · 🔒 Free with a myQNX account · 🐣🚶🏃**

QNX runs free online training courses for QNX OS developers. As of 2026 they report 6,000+
registered learners.

| | |
|---|---|
| **Best for** | Structured video learning; official terminology; a credential-ish sense of completion. |
| **Use alongside** | This course. Read a chapter here, watch the corresponding official module. |
| **Strength** | It is *official* — no risk of learning outdated or wrong practice. |
| **Weakness** | Broad rather than deep; doesn't cover the messy real-world troubleshooting that this course's "💥 Break it" exercises target. |
| **Path guidance** | 🐣 A: do the intro modules. 🚶 B: do all of them, in parallel with Parts 1–3. 🏃 C: skip — the docs are faster. |

---

## 4. Books

> ⚠️ **Honest assessment.** The QNX book market is **thin and dated**. There is no current,
> widely-recommended QNX 8.0 book. This is a real gap in the ecosystem — and part of why this course
> exists.

| Book | Rating | Depth | Cost | Verdict |
|------|:------:|:-----:|:----:|---------|
| **QNX official PDFs of the doc booksets** | ⭐⭐⭐⭐⭐ | 🌳 | 🆓 | The docs *are* the book. Download the PDFs from the doc site and read System Architecture like a book. **This is the recommendation.** |
| *Getting Started with QNX Neutrino* — Rob Krten | ⭐⭐⭐⭐ | 🌿 | 💰 (used) | The classic. Superb pedagogy on message passing and resource managers — arguably still the best explanation ever written of Send/Receive/Reply. **But it targets QNX 6.x**: APIs mostly survive, tooling and build system do not. Read for *concepts*, never for *commands*. |
| *The QNX Cookbook* — Rob Krten | ⭐⭐⭐ | 🌿 | 🆓/💰 | Recipe-style companion to the above. Same caveat: dated tooling, sound concepts. |
| Generic RTOS textbooks (Liu, Buttazzo) | ⭐⭐⭐⭐ | 🌳 | 💰 | Not QNX-specific, but the right place to learn real-time *theory* properly: schedulability, rate-monotonic analysis, WCET. Useful if Chapter 11 leaves you wanting more rigour. |
| *Operating System Concepts* (Silberschatz) | ⭐⭐⭐ | 🌿 | 💰 | Standard OS textbook. Fills gaps if OS fundamentals feel shaky. 🐣 A may find it heavy. |

> 💡 **Insight for the learner.** The absence of a modern QNX book is exactly why QNX's own licence
> explicitly permits writing training material commercially. If you finish this course and write up
> what you learned, you would be filling a real hole.

---

## 5. Video & podcasts

| Resource | Rating | Depth | Cost | Verdict |
|----------|:------:|:-----:|:----:|---------|
| "Get Started With QNX Everywhere" YouTube playlist | ⭐⭐⭐⭐ | 🌱 | 🆓 | Directly relevant to Setup Guides 02–03. Watching someone else click through QNX Software Center removes a lot of anxiety. |
| QNX official YouTube channel | ⭐⭐⭐ | 🌱🌿 | 🆓 | Mixed: some solid technical talks, a lot of marketing. Filter by title. |
| *Code the Future* podcast (QNX) | ⭐⭐ | 🌱 | 🆓 | Industry context and strategy, not technique. Good commute listening; teaches no skills. |
| Conference talks (Embedded World, automotive) | ⭐⭐⭐ | 🌿 | 🆓 | Occasionally excellent deep dives. Search per topic rather than browsing. |

---

## 6. Community & forums

| Resource | Rating | Response speed | Verdict |
|----------|:------:|----------------|---------|
| **Official QNX Discord** | ⭐⭐⭐⭐⭐ | Hours | **The best place to ask questions in 2026.** Active, includes QNX staff, tolerant of beginners. |
| QNX official support portal | ⭐⭐⭐⭐ | Days | Excellent — but effectively for commercial licence holders. Non-commercial users should use Discord. |
| Reddit (QNX presence + r/embedded) | ⭐⭐⭐ | Days | Decent for "should I use QNX?" discussions; weak for API-level help. |
| Stack Overflow `[qnx]` tag | ⭐⭐ | Slow | Low volume, many old QNX 6.x answers. Check dates carefully before trusting an answer. |
| Legacy QNX community forums | ⭐⭐ | — | Historically valuable, now quiet. Good for archaeology when you hit an obscure error string. |

> ⚠️ **Warning.** When you find a QNX answer online, **check whether it's about QNX 6.x**. The
> ecosystem's centre of gravity online is still Neutrino 6.x. `io-pkt` vs `io-sock`, the toolchain
> version, and the build system all changed. Concepts transfer; commands often don't.

---

## 7. Code to read

Reading real QNX code is the fastest way past the beginner plateau.

| Source | Rating | Depth | Verdict |
|--------|:------:|:-----:|---------|
| **`github.com/qnx-ports`** | ⭐⭐⭐⭐⭐ | 🌿🌳 | Official ports of open-source projects to QNX. Shows *idiomatic* QNX build recipes and porting patterns. Best single source of real-world QNX build knowledge outside the docs. |
| **SDP sample code** (`$QNX_TARGET/usr/src` and the IDE templates) | ⭐⭐⭐⭐⭐ | 🌿 | Ships with your install. Resource manager samples in particular are the canonical starting point for Chapter 17. |
| **BSP source** (from the BSP catalogue) | ⭐⭐⭐⭐ | 🌳 | Read one end to end before attempting Chapter 32. Dense, but it's the ground truth for how QNX meets hardware. |
| **`oss.qnx.com` dashboard** | ⭐⭐⭐⭐ | 🌿 | Tells you what's already ported and how well tested — saves you porting something that exists. |

---

## 8. Adjacent background material

*Useful if this course's assumptions outrun your background.*

| Topic | Suggested resource | For whom |
|-------|-------------------|----------|
| C refresher | *Modern C* (Jens Gustedt) — free PDF | 🐣 A, if code blocks feel opaque |
| Linux/POSIX systems programming | *The Linux Programming Interface* (Kerrisk) | 🚶 B — the POSIX half of QNX is exactly this |
| Real-time theory | Buttazzo, *Hard Real-Time Computing Systems* | 🚶 B/🏃 C wanting rigour after Chapter 11 |
| Computer architecture | *Computer Organization and Design* (Patterson & Hennessy) | Anyone shaky on MMU, caches, interrupts |
| Make / build systems | GNU Make manual | 🚶 B before Chapter 08 |
| Git | *Pro Git* (free online) | Anyone unsure about the repo workflow |

---

## 9. What's missing in the QNX ecosystem

*Naming the gaps honestly, so you know it's not you.*

| Gap | Impact on you | How this course compensates |
|-----|---------------|----------------------------|
| **No current QNX 8.0 book** | No single narrative path from beginner to competent | This course *is* that narrative |
| **Docs assume prior OS knowledge** | Beginners bounce off System Architecture | Chapters 01, 09 build the vocabulary first |
| **Most tutorials online target QNX 6.x** | Commands silently fail; you assume you did it wrong | Every command here is SDP 8.0 and version-stamped |
| **Small Q&A corpus** | Google/Stack Overflow often have nothing | `Doubts.md` accumulates your own corpus; Discord fills the rest |
| **Little hobbyist content** | Hard to find "weekend project" material | QEMU labs + the Raspberry Pi track |
| **Sparse troubleshooting material** | One bad error message can cost a day | `Setup_05_Troubleshooting.md` grows with every failure we hit |

---

## 10. Recommended study stack per path

### 🐣 Path A — Absolute Beginner

| Order | Resource | Time |
|-------|----------|------|
| 1 | This course, Chapters 00–03 | ~3 h |
| 2 | QNX Everywhere docs (skim the overview sections) | ~1 h |
| 3 | "Get Started With QNX Everywhere" videos | ~1 h |
| 4 | This course: 🐣 sections of Chapters 09, 13, 16, 21, 27–30 | ~8 h |
| 5 | *System Architecture* — overview chapters only | ~2 h |

### 🚶 Path B — Self-Learner *(your default)*

| Order | Resource | Time |
|-------|----------|------|
| 1 | This course, all of it, all labs | ~120 h |
| 2 | *System Architecture* — cover to cover, in parallel with Part 2 | ~10 h |
| 3 | Official QNX free training modules | ~10 h |
| 4 | *Programmer's Guide* — as reference during Parts 2–3 | ongoing |
| 5 | Krten's *Getting Started with QNX Neutrino* — concepts only | ~8 h |
| 6 | `github.com/qnx-ports` — read two ports end to end | ~4 h |
| 7 | Discord — ask at least three real questions | ongoing |

### 🏃 Path C — Fast-Track Pro

| Order | Resource | Time |
|-------|----------|------|
| 1 | This course: all `🏃 Fast-Track Summary` boxes + all cheat sheets | ~4 h |
| 2 | This course: the 6 `⭐ core` labs | ~6 h |
| 3 | *System Architecture* — message passing + resource manager chapters | ~2 h |
| 4 | *Building Embedded Systems* — build files and boot | ~2 h |
| 5 | *Library Reference* — bookmark, don't read | — |
| 6 | Discord | as needed |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Created. Rated ~30 resources across 8 categories; documented 6 ecosystem gaps; per-path study stacks. |
