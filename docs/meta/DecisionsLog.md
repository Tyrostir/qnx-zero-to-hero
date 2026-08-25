---
title: "Decisions Log — Append-Only History"
document_id: DECLOG
version: 1.0
status: Active (append-only living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "Every time a decision is made, revisited, superseded or reversed"
---

# 🧾 DecisionsLog.md

> **Append-only.** Nothing in this file is ever edited or deleted — only appended.
> [`Decisions.md`](Decisions.md) tells you **what is true now**.
> This file tells you **what was decided, when, by whom, why, what was rejected, and what changed**.

**Entry types**

| Type | Meaning |
|------|---------|
| 🆕 `DECIDED` | A new decision was made |
| 🔄 `REVISED` | An existing decision was modified |
| ⛔ `SUPERSEDED` | A decision was replaced by a newer one |
| ↩️ `REVERSED` | A decision was undone entirely |
| ❓ `DEFERRED` | A decision was consciously postponed |
| 🔍 `VERIFIED` | An assumption was checked against reality |

---

## 2026-08-25 — Session 001 (Course inception)

### 🔍 VERIFIED — Host environment

**Context.** Before designing labs, the learner's machine was inspected directly.

**Findings.**

| Item | Result |
|------|--------|
| OS | Ubuntu 26.04 LTS on WSL2 (kernel 6.18.33.2-microsoft-standard-WSL2) |
| CPU | Intel Core i7-11850H, 16 logical CPUs, VT-x, full virtualization |
| `/dev/kvm` | **Present** (`crw-rw---- root:kvm`) — nested virtualization available |
| RAM | 23 GiB total, ~21 GiB free |
| Disk | 1007 GB, **952 GB free** |
| Installed | `git`, `curl` |
| Missing | `qemu-system-x86_64`, QNX SDP, VS Code QNX Toolkit, Pandoc/TeX |

**Why it matters.** KVM availability is the single biggest factor in lab usability. Its presence let
us commit to ADR-003 (QEMU+KVM) and ADR-005 (x86_64 targets) with confidence instead of hedging.

**Consequence.** Risk R3 in `PLAN.md` downgraded from *High likelihood* to *Low*.

---

### 🔍 VERIFIED — Current state of QNX products and licensing

**Context.** QNX documentation and marketing moved during 2025; much online material (and much model
training data) is out of date. Facts were re-checked against live sources before writing anything.

**Findings (verified 2026-08-25).**

| Fact | Detail | Source |
|------|--------|--------|
| Domain moved | `blackberry.qnx.com` now redirects to **`qnx.software`** | live redirect observed |
| Current SDP | **QNX SDP 8.0** (QNX OS 8.0) | qnx.software product pages |
| Free programme | **QNX Everywhere** — free non-commercial licence, requires a **myQNX account** | qnx.software/en/developers/get-started/qnx-everywhere/ |
| Licence flow | 1) myQNX account → 2) QNX Everywhere licence form → 3) licence issued | same |
| Two licence families | Non-Commercial (QNX Everywhere) vs Commercial (incl. 30-day trial) | qnx.software/…/qnx-everywhere/licensing |
| Explicitly permitted non-commercially | Learning, academic work, hobby/maker projects incl. Raspberry Pi and other QNX BSPs, **developing training material or books (even commercially)**, interoperable OSS | licensing page |
| Explicitly *not* permitted | Production use, distribution, building commercial products, customer demos | licensing page |
| Free RPi image | QNX 8.0 **Quick Start Image for Raspberry Pi**, hosted on GitLab | gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image |
| New product | **QNX Developer Desktop** — self-hosted QNX 8.0 desktop for building *on* QNX | qnx.com/developers/docs/qnxeverywhere/…/qdd |
| Official OSS ports | `github.com/qnx-ports` + dashboard at `oss.qnx.com` | qnx.software |
| Docs root | `qnx.com/developers/docs/8.0/` and `qnx.com/developers/docs/qnxeverywhere/` | live |
| Community | Official **Discord**, plus Reddit, YouTube | qnx.software footer |
| SDP 7.1 | **Not** part of the QNX Everywhere free programme | qnx.software FAQ |

**Why it matters.**
- The licensing page's explicit permission to "develop training material or books describing how to
  use our products, including if you intend to offer that material commercially" is what makes this
  public repository legally sound → drove **ADR-017**.
- SDP 7.1 being excluded from the free programme removed any option of teaching 7.1 → hardened
  **ADR-001**.
- The domain migration means many links found by search engines are stale → drove the
  "verified on" date column in `ReferenceLinks.md`.

---

### 🆕 DECIDED — ADR-001: Target QNX SDP 8.0

**Alternatives considered.**

| Option | Verdict | Reason |
|--------|---------|--------|
| SDP 8.0 only | ✅ **Chosen** | Current gen; the only version in the free programme; what new work uses |
| SDP 7.1 only | ❌ | Not available free; declining relevance |
| Teach both in parallel | ❌ | Doubles length, halves clarity; the deltas are better as targeted ⚠️ boxes |

**Trade-off accepted.** Readers maintaining a 7.1 codebase need the delta boxes; these are therefore
mandatory content, not optional.

---

### 🆕 DECIDED — ADR-002: QNX Everywhere non-commercial licence

**Alternatives considered.**

| Option | Verdict | Reason |
|--------|---------|--------|
| QNX Everywhere (free, non-commercial) | ✅ **Chosen** | Free, legal, designed exactly for this use |
| 30-day Commercial Trial | ❌ | Expires ~4 weeks into a ~6-month course |
| Cloud QNX on AWS/Azure | ❌ | Costs money, adds account/billing friction |
| Not using QNX at all (theory-only course) | ❌ | Violates the whole point — hands-on was explicitly requested |

**Risk registered as R1.** Licence approval latency is the single most likely blocker. Mitigation
baked into the course order: Part 0 (Chapters 00–03) requires **no software**, so the learner starts
the licence request on day 1 and reads while waiting.

---

### 🆕 DECIDED — ADR-003 / ADR-004 / ADR-005: QEMU + KVM + `mkqnximage` + x86_64

**Alternatives considered.**

| Option | Verdict | Reason |
|--------|---------|--------|
| QEMU + KVM, image via `mkqnximage`, x86_64 | ✅ **Chosen** | Free, fast (KVM verified), official, reproducible |
| VirtualBox | ❌ | Weaker fit with `mkqnximage`; extra kernel-module friction under WSL2 |
| VMware Workstation | ❌ | Licence friction; no advantage here |
| Raspberry Pi as the primary lab target | ❌ | Costs money + shipping; gates the course on hardware; would violate the "start today" goal. Kept as the *hardware track* instead |
| `aarch64le` under QEMU TCG | ❌ | No KVM for foreign architecture → 10–50× slower; frustrating for iterative labs |

**Trade-off accepted.** Virtual devices are not real devices. Chapters 19–20 explicitly flag every
place where the VM lies to you, and Chapter 31/Hardware guides restore the truth.

---

### 🆕 DECIDED — ADR-006: VS Code + QNX Toolkit primary, Momentics secondary

**Reasoning.** The learner already uses VS Code (this course is being authored inside it), it works
well over WSL2, and QNX ships an official VS Code Toolkit for SDP 8.0.

**Constraint attached.** Every lab must also be completable from a bare terminal. The IDE is
convenience, never a dependency. This keeps the course usable for readers on any editor and makes
the underlying commands visible (course rule #4).

---

### 🆕 DECIDED — ADR-007: `qcc` before Makefiles

**Reasoning.** QNX's recursive Makefile system (`common.mk` + `arch/variant` directory tree) is a
notorious newcomer stumbling block. Presenting it first would teach ritual instead of understanding.

**Order fixed as:** literal `qcc` command → simple hand-written Makefile → QNX recursive Makefiles →
(appendix) CMake.

---

### 🆕 DECIDED — ADR-008: Paths as in-chapter markers

**Alternatives considered.**

| Option | Verdict | Reason |
|--------|---------|--------|
| Markers inside one chapter file | ✅ **Chosen** | Single source of truth; readers can switch or peek; no drift |
| Three separate chapter sets (102 files) | ❌ | Guaranteed to diverge; 3× maintenance |
| Three separate repos/branches | ❌ | Worse than the above in every way |

**Consequence.** Mandatory per-chapter structure: a `🏃 Fast-Track Summary` box at the top and path
tags on every lab. Enforced by the chapter template in `PLAN.md` §5.

---

### 🆕 DECIDED — ADR-009: Message passing is the centre of the course

**Reasoning.** Send/Receive/Reply is the mechanism that everything else in QNX is built on:
resource managers, device drivers, `open()`/`read()`/`write()`, `qconn`, the pathname space. Learners
who struggle with QNX almost always never internalised the blocking-state machine.

**Consequence.** Chapters 10–12 (threads, scheduling, synchronization) are deliberately scoped to
"what you need in order to understand Chapter 13", not to exhaustive POSIX coverage. Chapters 13–14
get the largest page budget and the most diagrams in the course.

---

### 🆕 DECIDED — ADR-010 / ADR-011 / ADR-015: Mermaid, Pandoc/XeLaTeX, no GitHub-only syntax

**Reasoning.** The learner asked for PDF export "later". Retrofitting PDF-safety across 34 chapters
is expensive; enforcing it from file #1 is free.

**Rules locked in now** (full list in `PLAN.md` §10):
- Mermaid for diagrams, each followed by a one-line text description.
- No `> [!NOTE]`-style GitHub alerts — use `> 💡 **Insight**` instead.
- No raw HTML except `<details>`/`<summary>` and one centered `<div>` in the README.
- Relative links only.
- YAML front matter on every document (Pandoc metadata).

**Trade-off accepted.** Slightly less pretty on GitHub than native alert boxes; fully portable in
exchange.

---

### 🆕 DECIDED — ADR-012: `TableOfContents.md` canonical, `TableOfContext.md` alias

**Context.** The learner's request listed `TableOfContext.md`. This is almost certainly a typo for
"Table of Contents", but guessing silently is bad practice and dropping the requested filename is
worse.

**Resolution.** Canonical file is `TableOfContents.md`; a two-line `TableOfContext.md` points to it.
Both names work; they cannot diverge because the alias holds no content.

**Reversible.** Delete the alias at any time with no impact.

---

### 🆕 DECIDED — ADR-013: Hardware as a separate track

**Reasoning.** Explicitly requested ("keep a separate guide"), and it aligns with the goal of a
zero-cost, start-today course.

**Structure fixed as:** `Hardware_01_Public_Boards.md` (buy/flash/boot commercially available boards)
and `Hardware_02_Custom_Board.md` (your own PCB: IPL → startup → procnto → drivers → production
image), plus Chapters 31–32 which teach the concepts.

---

### 🆕 DECIDED — ADR-014: Doubts become permanent artefacts

**Reasoning.** Explicitly requested. Also the highest-leverage documentation practice available: it
turns a private conversation into a public, searchable FAQ and reveals gaps in the chapters.

**Protocol fixed** (full version in `PLAN.md` §13): ID → verbatim question → short answer → full
answer → related links → status; plus a chapter patch if the question exposed a gap, and an ADR if it
exposed an unrecorded decision.

---

### 🆕 DECIDED — ADR-016: One chapter, one commit

**Reasoning.** Gives a clean, reviewable history; lets the learner `git diff` what changed after
asking a question; produces a visible public portfolio artefact.

**Format fixed:**

```text
ChNN: <Title>

- chapter text + N labs + break-it exercise
- glossary: +N terms
- refs: +N links
```

---

### 🆕 DECIDED — ADR-017: CC BY-SA 4.0 (content) + MIT (code)

**Legal reasoning.** The QNX Everywhere non-commercial licence explicitly permits developing
training material and books about QNX products, *including commercially*. That permission is what
makes a public course repository sound.

**Boundaries stated explicitly.** The repo licence covers only material written here. It does not and
cannot cover QNX software, QNX headers, or QNX documentation. QNX code samples are linked and
paraphrased, never bulk-copied.

---

### ❓ DEFERRED — Five decisions needing learner input

Recorded as P-01 … P-05 in [`Decisions.md`](Decisions.md#-pending-decisions-need-your-input):
glossary language hints, capstone theme, separate quizzes folder, auto-push policy, and how early to
write the Raspberry Pi guidance.

**Why deferred.** Each depends on learner preference, and each has a safe default that lets work
proceed without blocking. Defaults will be applied if no answer is given before the relevant chapter.

---

### 🆕 DECIDED — ADR-018: Default path is 🚶 Path B (provisional)

**Reasoning.** The learner's stated profile — starting-level embedded engineer, solid C/C++, strong
Python, learning "from scratch" — maps exactly onto Path B.

**Marked provisional (🔄) deliberately.** Path is a preference, not a fact. It may be changed
globally or per part at any time; that change will be logged here as a `🔄 REVISED` entry.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Log created. Session 001: 2 verifications, 18 decisions, 5 deferrals. |
