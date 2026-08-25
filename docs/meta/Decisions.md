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
| [ADR-004](#adr-004) | Use the official **QSTI for QEMU** image to get booting fast; build our own later | Environment | ✅ (revised) |
| [ADR-005](#adr-005) | `x86_64` is the default target architecture for labs | Environment | ✅ |
| [ADR-006](#adr-006) | VS Code + QNX Toolkit is the primary IDE | Tooling | ✅ |
| [ADR-007](#adr-007) | Teach raw `qcc` first, QNX recursive Makefiles second | Pedagogy | ✅ |
| [ADR-008](#adr-008) | Three learning paths implemented as in-chapter markers, **all three fully authored** | Pedagogy | ✅ (revised) |
| [ADR-009](#adr-009) | Message passing (Ch 13/14) is the pedagogical centre of the course | Pedagogy | ✅ |
| [ADR-010](#adr-010) | Mermaid for all diagrams | Docs | ✅ |
| [ADR-011](#adr-011) | Pandoc + XeLaTeX + Eisvogel for PDF export | Docs | ✅ |
| [ADR-012](#adr-012) | `TableOfContents.md` is canonical; `TableOfContext.md` is an alias | Docs | ✅ |
| [ADR-013](#adr-013) | Hardware content is a separate track, not woven into the core | Structure | ✅ |
| [ADR-014](#adr-014) | Every question becomes a permanent `D-NNN` artefact | Process | ✅ |
| [ADR-015](#adr-015) | No GitHub-only Markdown syntax | Docs | ✅ |
| [ADR-016](#adr-016) | One chapter = one commit; repo is the deliverable | Process | ✅ |
| [ADR-017](#adr-017) | Course content CC BY-SA 4.0, lab code MIT | Legal | ✅ |
| [ADR-018](#adr-018) | Learner's path is 🚶 Path B | Pedagogy | ✅ (confirmed) |
| [ADR-019](#adr-019) | The capstone ships in **all three domain flavours**; the reader chooses | Pedagogy | ✅ |
| [ADR-020](#adr-020) | Deliver **one chapter per turn**, auto-committed and pushed | Process | ✅ |
| [ADR-021](#adr-021) | Use `https://www.qnx.com/getqnx` as the canonical licence entry point | Setup | ✅ |
| [ADR-022](#adr-022) | Documents are organised in **three tiers**; `docs/internal/` is excluded from the book | Docs | ✅ |
| [ADR-023](#adr-023) | `PROMPTS.md` records every learner prompt **and** every full author response | Process | ✅ |
| [ADR-024](#adr-024) | The author does not execute commands; `[UNVERIFIED]` is cleared only by learner-run output | Process | ✅ |

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

### Use the official QSTI for QEMU image to get booting fast; build our own later

| | |
|---|---|
| **Status** | ✅ Active — **revised 2026-08-25** (originally: "use `mkqnximage`") |
| **Date** | 2026-08-25 |
| **Category** | Environment |

**Decision.** The lab VM is obtained in **two stages**:

| Stage | Method | Where | Why |
|-------|--------|-------|-----|
| 1. Get booting fast | **QSTI** — QNX's official *Quick Start Target Image* for QEMU | Setup Guide 03, Chapter 06 | Pre-built, supported, includes sample apps. Shortest path from "installed" to "`qnx#` prompt". |
| 2. Build your own | **CTI** — *Custom Target Image*, and later raw `mkifs` | Chapter 21 | You cannot claim to know QNX until you have built the image yourself. |

**Why this changed.** The original decision assumed `mkqnximage` was the only sanctioned route. Live
verification of the QNX Everywhere documentation revealed two officially documented image products
that did not exist in older material:

- **QSTI (Quick Start Target Image)** — pre-built images for **QEMU** and **Raspberry Pi 4/5**
- **CTI (Custom Target Image)** — a build-your-own flow, also for QEMU and Raspberry Pi

QSTI is explicitly the beginner on-ramp, is documented by QNX, and has its own troubleshooting page.
Starting there removes an entire class of first-day failures.

**Consequences.**
- Setup Guide 03 follows the official QSTI-for-QEMU guide, annotated with the extra explanation this
  course demands (course rule #4: nothing is a black box).
- ⚠️ QNX documents QSTI for QEMU as supported on **Ubuntu 22.04 / 24.04**. The learner's host is
  **Ubuntu 26.04** — newer than documented. Setup Guide 01 handles the package-name differences and
  Setup Guide 05 records anything that breaks. Tracked as risk **R9**.
- Chapter 21 gains extra weight: it now covers CTI *and* raw `mkifs`, making the progression
  QSTI → CTI → `mkifs` explicit.
- `mkqnximage` is still taught (it remains the SDP-native tool) but as an alternative, not the
  primary route.

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

### Three learning paths implemented as in-chapter markers, all three fully authored

| | |
|---|---|
| **Status** | ✅ Active — **strengthened 2026-08-25** |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Paths 🐣 A / 🚶 B / 🏃 C are implemented as **tags and boxes inside a single chapter
file**, not as three parallel documents.

**And — added at the learner's explicit request — content for *all three paths* is written in full for
every chapter, even though the learner personally follows Path B.**

> 💬 *Learner's words (2026-08-25):* "My learning path will be Path B. But this repo course should
> have contents of Path A and Path C also. So that in future, someone else can start from the path
> that suits them. … you should not skip creating contents for Path A and C as well."

**Why.** Two reasons, one per half of the decision:

1. *Single file:* three copies of 34 chapters = 102 documents that drift out of sync. A single source
   keeps content correct and lets a reader switch paths (or peek at a deeper path) without leaving
   the page.
2. *All three authored:* the repository is a **public course**, not a private tutoring log. Omitting
   Path A and Path C content because the current learner doesn't need it would make the repo useless
   to the next reader.

**Consequences — mandatory per chapter, no exceptions:**

| Element | Required content |
|---------|-----------------|
| 🏃 **Fast-Track Summary** | A genuine ≤1-page "here is the QNX delta vs. what you already know" box at the top. Not a teaser — a professional must be able to read *only* this and be productive. |
| 🐣 **Path A Activity** | Every chapter with a lab also has a no-coding, observe-and-answer version with pre-built binaries in `labs/*/prebuilt/`. |
| 🐣 **Beginner notes** | Extra hand-holding boxes wherever a term or step assumes background. |
| 🚶 **Full labs** | Skeleton + solution + expected output. |
| ⭐ **Core lab tagging** | Marks the Path C minimum set. |

A chapter is **not complete** until all three paths are usable through it. This is enforced in the
Definition of Done ([`PLAN.md` §17](../PLAN.md#17-definition-of-done)).

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

### Learner's path is 🚶 Path B

| | |
|---|---|
| **Status** | ✅ Active — **confirmed by the learner 2026-08-25** |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Chapters are paced and delivered for **🚶 Path B — Self-Learner**: full theory, all
labs, all break-it exercises.

**Why.** Matches the stated profile: starting-level embedded engineer with solid C/C++ and strong
Python, no RTOS background, wanting depth from scratch. Confirmed directly by the learner.

**Note.** This governs *pacing and emphasis* only. Per **ADR-008**, Path A and Path C content is
still written in full for every chapter.

**Revisit if.** The learner says the pace is too slow or too dense. Path can be changed per part,
not just globally.

---

## ADR-019

### The capstone ships in all three domain flavours; the reader chooses

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Pedagogy |

**Decision.** Chapter 33 (Capstone) is not one project. It is **one shared architecture and rubric**
with **three interchangeable domain skins**:

| Track | Project | Domain flavour |
|-------|---------|----------------|
| 🤖 **33-R Robotics** | Motor-control loop + sensor fusion + telemetry link | Robotics / physical AI |
| 🚗 **33-A Automotive** | Sensor → control → actuator chain with CAN-style messaging and an instrument-cluster consumer | Automotive |
| 🏥 **33-M Medical / Industrial** | Dose/setpoint controller with alarm supervision and safe-state fallback | Medical device / PLC |

**Why.** Requested explicitly by the learner:

> 💬 *"Have all 3 flavours in this repo course, so that user can keep reading whichever he/she is
> interested in. Do not skip any flavour. Plan to have all three flavours and let the reader decide."*

It is also good pedagogy. The *QNX* content of a capstone — resource manager, message passing,
priority assignment, custom IFS, timing verification — is identical across domains. Only the domain
vocabulary and the safety story differ. Offering three skins costs far less than three projects and
makes the course relevant to three different audiences.

**Consequences.**
- Chapter 33 is structured as: shared architecture → shared rubric → three domain briefs → three
  reference solutions.
- Domain flavour is also used **earlier**, as example variety: worked examples across Parts 2–4 rotate
  between robotics, automotive and medical framings so no reader feels the course is "not for them".
- Labs directory gains `labs/lab33_capstone/{robotics,automotive,medical}/`.

---

## ADR-020

### Deliver one chapter per turn, auto-committed and pushed

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Process |

**Decision.** Confirmed by the learner. Per working turn: write **one** chapter (or one guide) to
full Definition-of-Done quality, update the affected meta documents, commit, **push to GitHub**, then
report and hand back for reading.

**Why.** Maximises depth per chapter and keeps a tight feedback loop — the learner reads, hits
friction, asks questions, and those questions become `D-NNN` entries that improve the chapter before
we move on. Batching would defer that feedback until it is expensive to act on.

**Exception.** Tightly coupled *setup guides* may be delivered in pairs where splitting them would
leave the learner blocked (for example, Setup 01 + Setup 02, because Setup 02 starts the
long-latency licence request).

**Consequences.** Resolves pending decision **P-04**. `CourseState.md` is updated every turn.

---

## ADR-021

### Use `https://www.qnx.com/getqnx` as the canonical licence entry point

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-25 |
| **Category** | Setup |

**Decision.** All course material directs the reader to **`https://www.qnx.com/getqnx`** to obtain
the free non-commercial licence.

**Why.** Verified against the official QNX Everywhere documentation, which states the licence flow
as: *request → **accept** → **deploy*** at that URL. The marketing pages link to several longer,
less stable URLs. `getqnx` is short, official, and stated in the docs themselves.

**Consequences.**
- The three-step **request → accept → deploy** wording is taught explicitly. Many people request a
  licence and then cannot install anything because they never *deployed* it to their account in the
  **myQNX License Manager** — a top support issue this course pre-empts.

---

## ADR-022

### Documents are organised in three tiers; `docs/internal/` is excluded from the book

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-26 |
| **Category** | Docs |

**Decision.** Every document in this repository belongs to exactly one of three tiers.

| Tier | Location | Audience | Included in the PDF book? |
|------|----------|----------|---------------------------|
| 📗 **1 — Course** | `README.md`, `docs/PLAN.md`, `docs/TableOfContents.md`, `docs/chapters/`, `docs/guides/`, `docs/reference/` | The end reader | ✅ Yes |
| 📘 **2 — Course bookkeeping** | `docs/meta/` | The learner, and readers curious how the course is made | ✅ Yes |
| 🔒 **3 — Internal** | `docs/internal/`, plus `PROMPTS.md` and `COPILOT_PROMPT_HISTORY.md` at the repo root | The learner and the author only | ❌ No |

**Why.** This course has already changed authors once and expects to again. Continuity requires
operational documents — handover notes, prompt logs, working memory — that have nothing to teach a
reader about QNX. Mixing them into the course would dilute it and confuse anyone who found the repo.

**Consequences.**
- Tier 1 and Tier 2 describe **exactly one machine**: the learner's Ubuntu 26.04 / WSL2 host. Any
  detail about how the course is *produced* stays in Tier 3.
- `tools/build-pdf.sh` enumerates Tier 1 and Tier 2 by explicit path and never globs
  `docs/internal/`, so Tier 3 is excluded from the book automatically.
- `docs/TableOfContents.md` does not link Tier 3.
- Tier 3 remains in Git — it is version-controlled continuity, not a secret.

---

## ADR-023

### `PROMPTS.md` records every learner prompt and every full author response

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-26 |
| **Category** | Process |

**Decision.** Every learner prompt is logged verbatim in [`PROMPTS.md`](../../PROMPTS.md) as
`PROMPT#N`, **and the author's complete response is logged immediately beneath it.** Both halves,
every time, without exception.

**Why.** Requested directly by the learner. A prompt without its response is half a record: it shows
what was asked but not what was decided, explained, or promised. Reasoning that exists only in a chat
window is lost the moment the session ends — and this project has already lost one author.

**Consequences.**
- `PROMPTS.md` becomes the project's narrative history, complementing `DecisionsLog.md` (what was
  decided) and `Doubts.md` (what was asked technically).
- Responses are logged in full, not summarised.
- This is Tier 3 (ADR-022) and is not part of the book.
- Extends, and does not replace, ADR-014 — a technical question still earns its own `D-NNN` entry.

---

## ADR-024

### The author does not execute commands; `[UNVERIFIED]` is cleared only by learner-run output

| | |
|---|---|
| **Status** | ✅ Active |
| **Date** | 2026-08-26 |
| **Category** | Process |

**Decision.** The author writes commands; **the learner runs them.** A step marked `[UNVERIFIED]`
can be cleared by exactly one thing: **output the learner pastes back from a real run on their own
machine.** The author may never clear a marker on its own judgement, however confident it is.

**Why.** The course's central honesty promise is that nothing stays in it that has not actually been
run. Confidence is not evidence. This matters most where the risk is highest: QNX documents its QEMU
flow for Ubuntu 22.04/24.04 while the learner's host is 26.04 (Risk **R9**), so package names and
behaviour genuinely may differ.

**Consequences.**
- [`docs/internal/VerificationRuns.md`](../internal/VerificationRuns.md) defines the clearance
  protocol and tracks every checkpoint.
- Setup Guide 01's front matter is corrected: only `check-environment.sh` was ever run against the
  host — its install steps are as unverified as Setup Guide 02's.
- Failures are as valuable as successes: a documented failure with a documented fix helps every
  future reader.
- `T-200` and `T-201` cannot close until the learner reports back.

---

## ✅ Resolved pending decisions

| ID | Question | Resolution | Resolved |
|----|----------|-----------|----------|
| P-01 | Glossary hints in other languages? | **No** — English only (default applied; not raised by learner) | 2026-08-25 |
| P-02 | Capstone domain flavour? | **All three** — robotics, automotive, medical/industrial → **ADR-019** | 2026-08-25 |
| P-03 | Separate `quizzes/` folder? | **No** — per-chapter mastery checks only (default applied) | 2026-08-25 |
| P-04 | Auto-push or review-first? | **Auto-commit and push per chapter** → **ADR-020** | 2026-08-25 |
| P-05 | How early to write the Raspberry Pi guidance? | Short "should I buy?" note in Chapter 03; full guide at Part 6 | 2026-08-25 |

## ⏳ Still pending

| ID | Question | Default if unanswered | Asked |
|----|----------|------------------------|-------|
| P-06 | Realistic weekly time budget? Lets me calibrate chapter length. | Assume ~5 h/week (Path B baseline) | 2026-08-25 |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.2 | 2026-08-26 | Author handover (Copilot → Claude). Added ADR-022 (three document tiers, `docs/internal/` excluded from the book), ADR-023 (`PROMPTS.md` logs prompts **and** responses), ADR-024 (the author cannot verify; only learner-run output clears `[UNVERIFIED]`). |
| 1.1 | 2026-08-25 | Learner approved the plan. ADR-004 revised (QSTI for QEMU). ADR-008 strengthened (all three paths fully authored). ADR-018 confirmed. Added ADR-019 (three capstone flavours), ADR-020 (one chapter per turn, auto-push), ADR-021 (`getqnx` licence flow). P-01…P-05 resolved; P-06 opened. |
| 1.0 | 2026-08-25 | Initial 18 ADRs + 5 pending decisions recorded. |
