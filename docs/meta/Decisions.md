---
title: "Decisions — Active Architecture Decision Records"
document_id: DEC
version: 1.0
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "Whenever a decision is made, changed, or superseded"
---

# ⚖️ Decisions.md

> **What this document is:** the **current, active** set of decisions governing this course — the
> *what*.
> **What it is not:** a history. Superseded decisions are *removed* from here and preserved forever
> in [`DecisionsLog.md`](DecisionsLog.md) — the *why and when*.
>
> Read this file to know **how things are**. Read `DecisionsLog.md` to know **how we got here**.

**Status key:** ✅ Active · 🔄 Provisional (may change with new information) · ⏳ Pending your input

---

## Index

| ID | Decision | Category | Status |
|----|----------|----------|--------|
| [ADR-001](#adr-001) | Target QNX SDP 8.0 as the primary version | Product | ✅ |
| [ADR-002](#adr-002) | Use the QNX Everywhere free non-commercial licence | Licensing | ✅ |
| [ADR-003](#adr-003) | QEMU + KVM is the primary lab environment | Environment | ✅ |
| [ADR-004](#adr-004) | Use `mkqnximage` to build the VM | Environment | ✅ |
| [ADR-005](#adr-005) | `x86_64` is the default target architecture for labs | Environment | ✅ |
| [ADR-006](#adr-006) | VS Code + QNX Toolkit is the primary IDE | Tooling | ✅ |
| [ADR-007](#adr-007) | Teach raw `qcc` first, QNX recursive Makefiles second | Pedagogy | ✅ |
| [ADR-008](#adr-008) | Three learning paths implemented as in-chapter markers, not separate files | Pedagogy | ✅ |
| [ADR-009](#adr-009) | Message passing (Ch 13/14) is the pedagogical centre of the course | Pedagogy | ✅ |
| [ADR-010](#adr-010) | Mermaid for all diagrams | Docs | ✅ |
| [ADR-011](#adr-011) | Pandoc + XeLaTeX + Eisvogel for PDF export | Docs | ✅ |
| [ADR-012](#adr-012) | `TableOfContents.md` is canonical; `TableOfContext.md` is an alias | Docs | ✅ |
| [ADR-013](#adr-013) | Hardware content is a separate track, not woven into the core | Structure | ✅ |
| [ADR-014](#adr-014) | Every question becomes a permanent `D-NNN` artefact | Process | ✅ |
| [ADR-015](#adr-015) | No GitHub-only Markdown syntax | Docs | ✅ |
| [ADR-016](#adr-016) | One chapter = one commit; repo is the deliverable | Process | ✅ |
| [ADR-017](#adr-017) | Course content CC BY-SA 4.0, lab code MIT | Legal | ✅ |
| [ADR-018](#adr-018) | Default learner path is 🚶 Path B | Pedagogy | 🔄 |

---

## ADR-001

### Target QNX SDP 8.0 as the primary version

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Product |

**Decision.** All course material targets **QNX SDP 8.0 / QNX OS 8.0**. QNX SDP 7.1 differences are
noted in ⚠️ boxes where they materially affect a reader working on a legacy codebase. QNX 6.x and
QNX 4 appear only as history in Chapter 02.

**Why.**
- SDP 8.0 is the current generation and the one available under the free QNX Everywhere programme.
- New projects (robotics, physical AI, next-gen automotive SoCs) start on 8.0.
- Teaching two versions in parallel doubles the material and halves the clarity.

**Consequences.**
- Readers on existing SDP 7.1 projects need the ⚠️ delta boxes — these are mandatory, not optional.
- Notably different in 8.0: the networking stack (`io-sock` vs the older `io-pkt`), the kernel
  rewrite, toolchain version, and removal of 32-bit targets.

**Verify before relying on it.** Exact SDP build number is recorded per chapter in front matter.

---

## ADR-002

### Use the QNX Everywhere free non-commercial licence

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Licensing |

**Decision.** The course is built entirely on the **QNX Everywhere** programme — a free
non-commercial licence for QNX SDP 8.0, obtained via a myQNX account.

**Why.** Zero cost, legally clean, and explicitly intended for students, hobbyists and learners.

**Consequences.**
- ⚠️ **Nothing built in this course may be commercialised or put into production.** This warning is
  repeated in Chapter 04 and in `Hardware_02_Custom_Board.md`.
- The licence must be requested early (Setup Guide 02, day 1) because processing takes time.
- If you later work commercially, your employer needs a Commercial licence + a separate Distribution
  licence. This distinction is taught explicitly, because engineers get it wrong.

**Alternative considered.** 30-day Commercial Trial — rejected: expires mid-course, and its terms
don't fit learning.

---

## ADR-003

### QEMU + KVM is the primary lab environment

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Environment |

**Decision.** All labs run on a QNX VM under **QEMU with KVM acceleration** on the learner's
WSL2/Ubuntu host. No physical hardware is required for Chapters 00–30.

**Why.**
- `/dev/kvm` is present and working on the learner's machine → near-native speed.
- Free, scriptable, snapshot-able, and reproducible — a broken VM is deleted and rebuilt in minutes.
- Removes cost and shipping delays as barriers to starting.

**Consequences.**
- Interrupt/driver chapters (19, 20) must use *virtual* devices; real-hardware caveats are called out
  explicitly so the learner is not surprised later.
- A TCG (no-KVM) fallback path is documented in Setup Guide 03 for readers on other machines.

**Alternatives considered.** VirtualBox (weaker QNX/`mkqnximage` integration), VMware Workstation
(licence friction), cloud QNX images on AWS/Azure (cost + account friction).

---

## ADR-004

### Use `mkqnximage` to build the VM

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Environment |

**Decision.** The lab VM is created with **`mkqnximage`**, the official image-builder shipped with
QNX SDP, rather than hand-rolled `qemu-img` + manual IFS assembly.

**Why.** It is the supported, reproducible path; it configures networking, SSH, a host shared
directory and `qconn` for us; and it is what QNX's own documentation and support assume.

**Consequences.**
- Chapter 06 explains *what `mkqnximage` did for us* rather than treating it as magic — otherwise it
  violates course rule #4 ("nothing is a black box").
- Chapter 21 later removes the training wheels: the learner builds an IFS by hand with `mkifs`.

---

## ADR-005

### `x86_64` is the default target architecture for labs

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Environment |

**Decision.** All lab code is built for **`x86_64`** QNX targets. `aarch64le` is introduced in the
hardware track (Raspberry Pi) and in Chapter 08 as a "same code, different `-V` flag" demonstration.

**Why.** The host CPU is x86_64, so KVM gives native-speed virtualization. Emulating aarch64 under
TCG would be 10–50× slower and would frustrate learning.

**Consequences.** Endianness and alignment differences between x86_64 and ARM are called out in
Chapter 15 (memory) and Chapter 31 (hardware) so the learner doesn't build x86-only habits.

---

## ADR-006

### VS Code + QNX Toolkit is the primary IDE

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Tooling |

**Decision.** Primary: **VS Code with the QNX Toolkit extension**. Secondary (fully documented but
optional): **QNX Momentics IDE** (Eclipse-based).

**Why.** The learner already works in VS Code; it runs well under WSL2 with the Remote extension;
QNX now ships and documents an official VS Code Toolkit.

**Consequences.** Momentics still owns some capabilities (notably parts of the System Analysis
Toolkit GUI). Chapter 26 documents installing and using Momentics for those specific tasks.
**All labs must also work from a plain terminal** — the IDE is a convenience, never a dependency.

---

## ADR-007

### Teach raw `qcc` first, QNX recursive Makefiles second

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** The first compilation the learner performs is a literal, fully-explained `qcc` command
line. Only afterwards are QNX recursive Makefiles (`common.mk`, `Makefile.dnm`, the
`arch/variant/` directory tree) introduced. CMake appears as an appendix.

**Why.** Course rule #4. QNX's recursive Makefile system is powerful but deeply confusing to
newcomers; understanding the underlying command makes it legible instead of magical.

**Consequences.** Chapter 08 is longer than a typical "hello world" chapter. Accepted.

---

## ADR-008

### Three learning paths implemented as in-chapter markers, not separate files

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Paths 🐣 A / 🚶 B / 🏃 C are implemented as **tags and boxes inside a single chapter
file**, not as three parallel documents.

**Why.** Three copies of 34 chapters = 102 documents that drift out of sync. A single source keeps
content correct and lets a reader switch paths (or peek at a deeper path) without leaving the page.

**Consequences.**
- Every chapter must carry a `🏃 Fast-Track Summary` box at the top and clear path tags on labs.
- PDF path-filtering (producing a Path-A-only book) becomes a build-time filter, not a content
  problem — listed as a stretch goal in `PDF_Export.md`.

---

## ADR-009

### Message passing (Ch 13/14) is the pedagogical centre of the course

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Synchronous message passing (`MsgSend`/`MsgReceive`/`MsgReply`) gets the most page
count, the most diagrams, and the most labs of any topic. Everything before it is framed as
preparation; everything after it is framed as an application of it.

**Why.** It is *the* thing that makes QNX QNX. Resource managers, drivers, `open()`/`read()`,
`qconn`, and the whole "everything is a path" model are all message passing underneath. Engineers
who learn QNX badly are almost always people who never internalised Send/Receive/Reply and its
blocking-state machine.

**Consequences.** Chapters 10–12 are deliberately trimmed to what is needed to support Chapter 13.

---

## ADR-010

### Mermaid for all diagrams

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Docs |

**Decision.** Diagrams are authored as **Mermaid** fenced code blocks inside the Markdown.

**Why.** Renders natively on GitHub, is plain text (so it diffs and reviews well), needs no binary
assets in the repo, and converts to PNG/SVG for PDF via `mermaid-filter`.

**Consequences.**
- Every Mermaid block must be followed by a one-line plain-text description (PDF fallback +
  screen-reader accessibility).
- The PDF build gains a Node.js/`mermaid-cli` dependency (documented, and skippable with a flag).

---

## ADR-011

### Pandoc + XeLaTeX + Eisvogel for PDF export

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Docs |

**Decision.** `tools/build-pdf.sh` uses **Pandoc** → **XeLaTeX** with the **Eisvogel** template.

**Why.** Best-in-class Markdown→PDF fidelity: real TOC, page numbers, syntax highlighting, callout
styling; XeLaTeX handles the emoji font we rely on for path markers.

**Consequences.** Constrains Markdown syntax (see ADR-015). Adds a ~2–4 GB TeX Live dependency, but
only for readers who actually want PDFs — the course is fully usable without it.

---

## ADR-012

### `TableOfContents.md` is canonical; `TableOfContext.md` is an alias

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Docs |

**Decision.** The index file is [`docs/TableOfContents.md`](../TableOfContents.md). A one-line
[`docs/TableOfContext.md`](../TableOfContext.md) exists that points to it.

**Why.** The requested name `TableOfContext.md` appeared to be a typo for "Table of Contents".
Rather than guess silently or drop the requested filename, both exist and cannot diverge.

**Consequences.** None. Remove the alias any time.

---

## ADR-013

### Hardware content is a separate track, not woven into the core

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Structure |

**Decision.** Real-hardware material lives in two standalone guides
(`Hardware_01_Public_Boards.md`, `Hardware_02_Custom_Board.md`) plus Chapters 31–32, and is never a
prerequisite for the core course.

**Why.** Requiring hardware would gate the course on money, shipping, and soldering. The core course
must be completable with a laptop alone.

**Consequences.** Some topics (real interrupts, real flash, JTAG, power-on reset behaviour) get a
"this is simulated here — on real hardware it differs because…" note in the core, and full treatment
in the hardware track.

---

## ADR-014

### Every question becomes a permanent `D-NNN` artefact

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Process |

**Decision.** No question is answered only conversationally. Each gets an ID, a dated entry in
[`Doubts.md`](Doubts.md) with a short answer *and* a full answer, and cross-links to chapters. If the
question exposed a gap, the chapter is edited too.

**Why.** Requested explicitly by the learner, and it converts a linear conversation into a
searchable, permanent FAQ that improves the course for every future reader.

**Consequences.** `Doubts.md` will grow large; it therefore carries an index table grouped by
category, kept at the top of the file.

---

## ADR-015

### No GitHub-only Markdown syntax

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Docs |

**Decision.** Forbidden across all `.md` files: GitHub alert blocks (`> [!NOTE]`, `> [!WARNING]`),
task-list-only semantics, HTML beyond `<details>`/`<summary>`/a single centered `<div>` in the
README, and absolute in-repo links.

**Why.** These render as broken text in Pandoc/PDF. Fixing them across 34 chapters later would be
far more expensive than avoiding them now.

**Consequences.** Callouts use the emoji-blockquote convention defined in `PLAN.md` §5.1.

---

## ADR-016

### One chapter = one commit; the repository is the deliverable

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Process |

**Decision.** Each published chapter (plus its labs, glossary additions and reference links) is a
single git commit, pushed to `Tyrostir/qnx-zero-to-hero`. Follow-up fixes and doubt-driven edits are
separate commits.

**Why.** Gives clean history, easy rollback, visible progress, and a portfolio artefact.

**Consequences.** Meta documents are touched by almost every commit — expected and fine.

---

## ADR-017

### Course content CC BY-SA 4.0, lab code MIT

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Legal |

**Decision.** Prose, diagrams and documentation: **CC BY-SA 4.0**. Lab source code: **MIT**.

**Why.** Share-alike keeps educational text open; MIT keeps code maximally reusable in the reader's
own projects.

**Consequences.**
- ⚠️ This licence applies **only to material written in this repository**. It does **not** apply to
  QNX software, QNX headers, QNX documentation, or anything copied from QNX sources.
- QNX code samples are referenced by URL and paraphrased, not copied wholesale.
- The QNX Everywhere non-commercial terms explicitly permit publishing training material — including
  commercially — which is why this repo can be public.

---

## ADR-018

### Default learner path is 🚶 Path B

| | |
|---|---|
| **Status** | 🔄 Provisional |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Unless the learner says otherwise, chapters are paced and delivered for **🚶 Path B —
Self-Learner**: full theory, all labs, all break-it exercises.

**Why.** Matches the stated profile: starting-level embedded engineer with solid C/C++ and strong
Python, no RTOS background, wanting depth from scratch.

**Revisit if.** The learner says the pace is too slow (→ Path C for some parts) or the theory is too
dense (→ Path A framing for some chapters). Path can be changed per part, not just globally.

---

## ⏳ Pending decisions (need your input)

| ID | Question | Default if you don't choose | Asked |
|----|----------|------------------------------|-------|
| P-01 | Do you want **Hindi/Tamil/other-language** glossary hints alongside English terms? | No — English only | 2026-08-25 |
| P-02 | Should the capstone be **automotive-flavoured** (sensor→control→actuator, CAN-like) or **robotics-flavoured** (motor control + telemetry)? | Robotics — more relatable, no CAN hardware needed | 2026-08-25 |
| P-03 | Do you want **weekly quizzes** as a separate `quizzes/` folder in addition to per-chapter mastery checks? | No — per-chapter checks only | 2026-08-25 |
| P-04 | Should I **auto-commit and push** after every chapter, or batch and let you review first? | Auto-commit and push per chapter | 2026-08-25 |
| P-05 | Do you want Raspberry Pi hardware guidance written **early** (so you can order a board now) or when you reach Part 6? | Early — a short "should I buy?" note now, full guide later | 2026-08-25 |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Initial 18 ADRs + 5 pending decisions recorded. |
