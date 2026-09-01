---
title: "Decisions Log — Append-Only History"
document_id: DECLOG
version: 1.21
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

## 2026-08-25 — Session 002 (Plan approved; QSTI discovered)

### 🔍 VERIFIED — Host readiness, via `tools/check-environment.sh`

**Context.** The environment-check script was written and run against the learner's actual machine.

**Result.** `13 passed · 9 warnings · 3 failed`

**Significant finding.** `/dev/kvm` **exists but is not writable by the user** — they are not a member
of the `kvm` group. The Session 001 record said only "present", which was incomplete and would have
led to a confusing "why is my VM so slow?" experience.

**Consequence.** New action item **T-008**: `sudo usermod -aG kvm $USER`, then `wsl --shutdown` from
Windows. Recorded in `CourseState.md`, `CompactContext.md`, and Setup Guide 01.

**Lesson recorded.** "Present" is not the same as "usable". The environment check now tests
readability *and* writability, not just existence.

---

### 🔍 VERIFIED — QNX Everywhere ships official target images (QSTI and CTI)

**Context.** While researching the exact SDP installation procedure, the QNX Everywhere
documentation set was read directly rather than relying on prior knowledge.

**Findings (verified 2026-08-25).**

| Fact | Detail |
|------|--------|
| **QSTI** | *Quick Start Target Image* — official **pre-built** QNX 8.0 images, with dedicated guides for **QEMU** and for **Raspberry Pi 4/5**. Includes sample apps. Has its own getting-started, specifications and troubleshooting pages. |
| **CTI** | *Custom Target Image* — official **build-your-own** image flow, for Raspberry Pi **and** QEMU (x86_64). |
| **Licence flow** | **request → accept → deploy** at `https://www.qnx.com/getqnx`. Deployment happens in the **myQNX License Manager** (`qnx.com/account/dashboard`). |
| **Install order** | myQNX account + deployed licence → **QNX Software Center (QSC)** → **QNX SDP 8.0** → IDE (QNX Toolkit for VS Code, or Momentics). |
| **Host support** | x86-based Windows or Linux. **No macOS.** **No ARM hosts.** Authoritative list in the SDP 8.0 Release Notes. |
| **QSTI-for-QEMU host OS** | Documented for **Ubuntu 22.04 or 24.04**. |
| **QEMU packages (Ubuntu 24.04)** | `qemu-system qemu-utils qemu-user qemu-user-binfmt qemu-block-extra libvirt-daemon-system libvirt-clients libguestfs-tools bridge-utils` |
| **QEMU packages (Ubuntu 22.04)** | `qemu qemu-system-x86 qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils` |
| **QNX Everywhere Discord** | `https://discord.com/invite/nF3UE97RND` — *distinct from* the general QNX Discord invite found on the marketing site |
| **Community, per the docs** | Stack Overflow `qnx` tag · Reddit **r/qnx** · the Discord above |
| **Additional OSS ports host** | `gitlab.com/qnx/ports` — in addition to `github.com/qnx-ports` |
| **Other QNX Everywhere guides** | Self-Hosted Developer Desktop · Hardware Interfacing · **QNX Porting Guide (Linux → QNX)** · **Driver Development Kit (DDK) Developer's Guide** |

**Why this matters.** The QSTI-for-QEMU guide did not exist in older QNX material. Following the
pre-`mkqnximage` plan would have sent the learner down a longer, less-supported path on day one,
with no official troubleshooting page to fall back on.

**Consequences.**
- **ADR-004 revised** (below).
- Two previously unknown guides — the **QNX Porting Guide** and the **DDK Developer's Guide** —
  are now source material for Chapters 19–20 and 22.
- `ReferenceLinks.md` gained 15 links; the QNX Everywhere Discord invite was corrected.
- \u26a0\ufe0f **New risk R9 registered:** QSTI-for-QEMU is documented for Ubuntu 22.04/24.04; the learner's
  host is **Ubuntu 26.04**. Package names and library versions may differ.

---

### 🔄 REVISED — ADR-004: `mkqnximage` → QSTI first, then CTI, then `mkifs`

**Superseded text.** *"The lab VM is created with `mkqnximage`, the official image-builder shipped
with QNX SDP."*

**New decision.** A staged progression:

| Stage | Method | Where | Purpose |
|-------|--------|-------|---------|
| 1 | **QSTI** (pre-built) | Setup 03 / Ch 06 | Boot QNX today. Minimise first-day failure modes. |
| 2 | **CTI** (build your own) | Ch 21 | Understand what is in the image. |
| 3 | **`mkifs`** (raw build file) | Ch 21 | Full control; how real products are built. |

`mkqnximage` remains taught as the SDP-native alternative.

**Why the change.** New evidence. QSTI is QNX's own documented beginner on-ramp for exactly our
scenario (QEMU on Ubuntu), and it comes with an official troubleshooting page — which directly
reduces Risk R2.

**Pedagogically better, too.** The QSTI → CTI → `mkifs` progression mirrors the course philosophy:
get a working system first, then remove one layer of magic at a time (course rule #4).

---

### 🆕 DECIDED — Learner approved the plan, with two amendments

The learner approved `PLAN.md` and the 34-chapter table of contents **as drafted**, and answered the
five deferred questions. Two answers changed the plan materially.

#### Amendment 1 → ADR-008 strengthened: all three paths authored in full

> 💬 *Learner:* "My learning path will be Path B. But this repo course should have contents of Path A
> and Path C also. So that in future, someone else can start from the path that suits them. … you
> should not skip creating contents for Path A and C as well."

**What changed.** ADR-008 previously guaranteed only *structure* for three paths (markers and a
Fast-Track box). It now guarantees *content*: every chapter must ship a genuine Path C fast-track
summary and a genuine Path A no-coding activity with pre-built binaries — even though the learner
personally uses neither.

**Why this is right.** The repository is a public course, not a private tutoring log. A path that
exists only as a marker is a broken promise to the next reader.

**Cost accepted.** Roughly 20–30 % more work per chapter, plus maintaining `labs/*/prebuilt/`
binaries. Added to the Definition of Done so it cannot quietly lapse.

#### Amendment 2 → ADR-019: the capstone ships in three domain flavours

> 💬 *Learner:* "Have all 3 flavours in this repo course… Do not skip any flavour. Plan to have all
> three flavours and let the reader decide which one to take."

**What changed.** Chapter 33 was to be a single robotics project. It becomes one shared architecture
and rubric with three domain briefs and three reference solutions: **robotics**, **automotive**,
**medical/industrial**.

**Why this is cheap and good.** The QNX content of a capstone — resource manager, message passing,
priority assignment, custom IFS, timing verification — is identical across domains. Only vocabulary
and the safety story differ. Three skins cost far less than three projects.

**Bonus consequence.** Worked examples throughout Parts 2–4 will now deliberately rotate between the
three domains, so no reader ever feels the course is "not for my industry".

---

### 🆕 DECIDED — ADR-020: one chapter per turn, auto-committed and pushed

**Learner's choices.** Delivery: *"Write → auto-commit → push, then tell you."* Batch size:
*"1 chapter at a time."*

**Why it's the right call.** Depth per chapter is maximised and the feedback loop stays tight: the
learner reads, hits friction, asks a question, and that question becomes a `D-NNN` entry that
improves the chapter *before* we build the next one on top of it. Batching defers that feedback until
acting on it is expensive.

**One exception carved out.** Tightly coupled setup guides may ship in pairs where splitting would
leave the learner blocked — specifically Setup 01 + Setup 02, because Setup 02 initiates the
long-latency licence request that Risk R1 is about.

---

### 🆕 DECIDED — ADR-021: `qnx.com/getqnx`, and teach "request → accept → **deploy**"

**Evidence.** The QNX Everywhere introduction states the flow as *request, accept, and deploy* a free
non-commercial licence at `https://www.qnx.com/getqnx`, with deployment performed in the myQNX
License Manager.

**Why it gets its own ADR.** The **deploy** step is the one people miss. A licence that has been
requested and accepted but never *deployed to your account* leaves QNX Software Center unable to
install anything — and the resulting error message does not say why. Teaching the three verbs
explicitly pre-empts a top support issue.

---

### ❓ DEFERRED — P-06: weekly time budget

Not yet answered. Default assumption: **~5 h/week** (the Path B baseline used in the `PLAN.md`
timeline). Affects only chapter sizing, so it does not block anything.

---

## 2026-08-26 — Session 003 (Author handover; document tiers established)

### 🔍 VERIFIED — Repository state at handover

Read end to end: `COPILOT_PROMPT_HISTORY.md`, `README.md`, `PLAN.md`, `TableOfContents.md`, all six
`docs/meta/` documents, all `docs/reference/` documents, Setup Guides 01 and 02, and both `tools/`
scripts.

Confirmed accurate: 6 parts / 34 chapters / 3 paths / 21 ADRs / 5 answered doubts / 2 commits on
`main` / 0 chapters published / 2 setup guides published.

Found **incomplete**: the final instruction of Session 002 asked for `NewAgentOnboardingGuide.md`,
`NewAgentOnboardingPrompts.md` and `CLAUDE-MEMORY.md`. **None had been created** — the session ended
first. All three are delivered in this session.

---

### 🆕 DECIDED — ADR-022: Three document tiers

**Decision.** Every document belongs to Tier 1 (course), Tier 2 (`docs/meta/` bookkeeping) or
Tier 3 (`docs/internal/` plus the root prompt logs). Tier 3 is excluded from the PDF book and is not
linked from the Table of Contents.

**Why.** The course has already changed authors once and expects to again. Continuity requires
operational documents — handover notes, working memory, prompt logs — that teach the reader nothing
about QNX. Keeping them in a marked tier means continuity costs the course nothing.

**What was rejected.** Scattering onboarding notes through `docs/meta/`. It would have made the
bookkeeping documents serve two audiences badly, and would eventually have leaked authoring
mechanics into the book.

**Consequence.** Tier 1 and Tier 2 describe **exactly one machine**: the learner's Ubuntu 26.04 /
WSL2 host. `tools/build-pdf.sh` was annotated so no future author adds Tier 3 to the book.

---

### 🆕 DECIDED — ADR-023: `PROMPTS.md` logs prompts *and* responses

**Decision.** Every learner prompt is recorded verbatim, and the author's complete response is
recorded beneath it.

**Why.** Requested directly by the learner. A prompt without its response records what was asked but
not what was decided, explained or promised — and this project has already lost one author mid-task.

**Consequence.** `PROMPTS.md` becomes the project's narrative history, alongside this log (what was
decided) and `Doubts.md` (what was asked technically).

---

### 🆕 DECIDED — ADR-024: The author cannot verify; only learner-run output clears `[UNVERIFIED]`

**Decision.** The author writes commands; the learner runs them. A marker is cleared by pasted
output from a real run, and by nothing else.

**Why.** The course promises that nothing stays in it that has not actually been run. Under Copilot
this was blurred, because the author and the machine were the same session. Making the separation
explicit protects the promise. It matters most against Risk **R9** — QNX documents its QEMU flow for
Ubuntu 22.04/24.04 while the host runs 26.04.

**Consequence.** [`docs/internal/VerificationRuns.md`](../internal/VerificationRuns.md) defines the
clearance protocol across 18 checkpoints in four blocks.

---

### 🔍 VERIFIED — Setup Guide 01 was never actually run

Setup Guide 01's front matter claimed `verified_on: "Ubuntu 26.04 LTS on WSL2 …"`. Only
`tools/check-environment.sh` was ever executed against the host. **None of its install commands
were.** The front matter has been corrected and the guide now carries the same `[UNVERIFIED]` notice
as Setup Guide 02.

**Why this matters.** An unearned verification claim is worse than no claim: it is exactly the kind
of quiet inaccuracy the `[UNVERIFIED]` convention exists to prevent.

---

### ❓ DEFERRED — Credential hygiene in the Git remote

Raised by the author, **consciously deferred by the learner** on 2026-08-26. Not to be raised again
unprompted. Recorded here so the deferral is a decision on the record rather than an oversight.

---

## 2026-08-26 — Session 004 (Block V1 verified on the host)

### 🔍 VERIFIED — Setup Guide 01 executed end to end

The learner ran the full host-preparation sequence on **Ubuntu 26.04 LTS / WSL2** and reported the
output. `tools/check-environment.sh` went from **13 passed · 9 warnings · 3 failed** to
**19 passed · 6 warnings · 0 failed**.

Real versions observed — now the documented expected output, and the reference for chapter front
matter:

| Component | Version |
|-----------|---------|
| GCC | 15.2.0 | 
| GNU Make | 4.4.1 |
| OpenJDK | 25.0.4 |
| QEMU / qemu-img | 10.2.1 |
| Git · curl · tar · OpenSSH | 2.53.0 · 8.18.0 · 1.35 · 10.2p1 |

Setup Guide 01 is promoted to **v2.0**, its `[UNVERIFIED]` notice removed, and every
expected-output block replaced with real observed output.

---

### 🔍 VERIFIED — Risk R9 did not materialise

**R9** anticipated that QNX's QEMU instructions — written for Ubuntu 22.04/24.04 — might not
translate to 26.04. Tested in practice: **every package installed under its documented name**, with
no substitutions and no "Unable to locate package" errors. R9 is closed for host preparation.

**Why record a risk that did not happen.** Future readers on 26.04 need to know the guide was proven
there, not merely believed to work.

---

### 🔍 VERIFIED — KVM acceleration works under nested virtualization

`/dev/kvm` is now present **and accessible** (T-008 closed). QEMU launched with `-enable-kvm`,
initialised acceleration, and ran its firmware to completion: SeaBIOS → iPXE (which obtained a DHCP
lease of `10.0.2.15` from QEMU's built-in NAT) → *"No bootable device."* No KVM error at any point.
**Risk R3 closed.**

Setup Guide 01 §9.2 previously documented a different invocation (`-kernel /dev/null`) that was never
run. It has been rewritten around the command actually executed, with the boot trace explained —
it is a useful preview of what Setup Guide 03 will replace with a `qnx#` prompt.

---

### 🔍 VERIFIED — Repository path was documented incorrectly

Every document recorded the checkout as `~/exercises/qnx/qnx-zero-to-hero`. The real path is
**`~/exercises/qnx-zero-to-hero`** — no intermediate `qnx/` directory. Corrected in Setup Guides 01
and 02, `CompactContext.md`, and `VerificationRuns.md`. `COPILOT_PROMPT_HISTORY.md` is left as-is; it
is a historical transcript, not a live instruction.

**Why this mattered.** Every verification block opens with a `cd` to that path. A wrong path is a
copy-paste failure on the first line of the first command.

---

### 🆕 DECIDED — Git identity for this repository

Commit identity set to **`Karthikeyan Kasvishwanathan <Karthikeyan.KLU@gmail.com>`** at the
learner's request. Earlier commits remain under `Tyrostir <19234119+Tyrostir@users.noreply.github.com>`;
history is not rewritten.

---

## 2026-08-26 — Session 005 (Licence deployed; Risk R1 closed)

### 🔍 VERIFIED — The QNX Everywhere licence flow works as documented

The learner completed **request → accept → deploy** at `qnx.com/getqnx` and the myQNX License
Manager, and confirmed the licence is **deployed**. Blocks **V2.1–V2.3** are complete; **T-003** and
**T-010** are closed.

Setup Guide 02 §§3–5 are promoted from `[UNVERIFIED]` to **confirmed by a real run**. The
`[UNVERIFIED]` scope now covers **Part B only** (§§7–11: Software Center, SDP install, environment
setup, verification).

**What was not captured.** Approval latency and the portal's real button labels were not recorded.
Both remain wanted for Chapter 04 — the course still cannot honestly tell a reader whether approval
takes minutes or days — but neither blocks anything. Tracked as **T-014**, priority 🔵.

---

### ⛔ CLOSED — Risk R1: QNX Everywhere licence latency

R1 was rated *Medium likelihood / **Blocking** impact* and was the only risk in the project with an
external dependency. The licence is deployed, so it is closed.

**Consequence — this changes the project's shape.** Since Session 001 the course has been organised
around waiting: Part 0 was sequenced first *because* it needs no software, and the plan's timeline
assumed dead time. **Nothing external gates the course any more.** Every remaining step — install,
boot, write, verify — is under our own control.

Risks **R3** (KVM) and **R9** (Ubuntu 26.04 package drift) closed in Session 004. The next risk due
for testing is **R2** — QNX Software Center's GUI/Java behaviour under WSL2, which block V3 exercises
directly.

---

### 🔄 REVISED — Git author identity spelling

Corrected to **`Karthikeyan Kasivishwanathan`** — with an `i` after `Kas`. The previous session had
set `Kasvishwanathan`, transcribed literally from the learner's message; the learner confirmed the
`i` belongs.

The one affected commit was **unpushed**, so it was re-authored in place rather than left wrong or
rewritten after publication. Commits 1–2 remain under `Tyrostir` and are untouched — they are already
published, and rewriting them would break their GitHub history for no benefit.

**Why a name spelling is worth a log entry.** It is the identity attached to every future commit in a
public repository. Fixing it silently would leave no record of which commits carry which spelling.

---

## 2026-08-26 — Session 006 (SDP verified; setup guides complete)

### 🔍 VERIFIED — QNX SDP 8.0 installs and cross-compiles

Blocks **V3** and **V4** executed on the host. `check-environment.sh` reports
**24 passed · 3 warnings · 0 failed** — the three warnings are the optional PDF toolchain.

| Item | Observed |
|------|----------|
| SDP root | `/home/tyrostir/qnx800` |
| `$QNX_HOST` | `/home/tyrostir/qnx800/host/linux/x86_64` |
| `$QNX_TARGET` | `/home/tyrostir/qnx800/target/qnx` |
| Licence file | `~/.qnx/license/licenses` |
| Cross-compiler | **GCC 12.2.0** |
| Targets | `gcc_ntox86_64` *(default)*, `_gpp`, `_cxx`; `gcc_ntoaarch64le`, `_gpp`, `_cxx` |
| Dynamic linker | `/usr/lib/ldqnx-64.so.2` |

The cross-compile proof behaved exactly as designed: the binary built, `file` identified the QNX
interpreter, and Linux refused to execute it with `cannot execute: required file not found`.

**Setup Guide 02 is promoted to v2.0**, verified end to end, with no `[UNVERIFIED]` markers
remaining anywhere in the course. **T-011, T-012, T-141, T-144 and T-200 are closed.**

---

### 🔍 VERIFIED — Three real bugs in Setup Guide 02, found only by running it

| # | Bug | Correction |
|---|-----|-----------|
| 1 | §11.2's sample program called `getpid()` with no `#include <unistd.h>`. It emitted `warning: implicit declaration of function 'getpid'` while the guide claimed the expected output was *"nothing at all"*. | Include added. The warning is now documented as a teaching moment: `<sys/neutrino.h>` carries QNX-specific calls; ordinary POSIX functions live in the standard POSIX headers, exactly as on Linux. |
| 2 | §11.3 told the reader to look for the word **"QNX"** in `file` output. `file` never prints it — QNX uses the System V ELF ABI, so it reports `SYSV`. | Corrected. The real tell is the interpreter `/usr/lib/ldqnx-64.so.2`. The section now also explains `pie executable` (forward reference to ASLR, Ch 28) and `with debug_info` (Ch 08). |
| 3 | The install was documented as **~8–12 GB**, with a ~25 GB total budget. | Measured: free space fell 951 GB → 908 GB, i.e. **~43 GB**. New §12.1; `PLAN.md` §7.1 total budget corrected to **~50 GB**. |

**Why this entry matters more than the others.** All three were plausible, sourced from official
documentation, and wrong. No amount of further reading would have caught them — only execution did.
This is the concrete justification for **ADR-024**, and the reason `[UNVERIFIED]` is not bureaucracy.

---

### ⛔ CLOSED — Risk R2: QNX Software Center install on WSL2

QNX Software Center and SDP 8.0 both installed successfully under WSL2. **R2 is closed.**

⚠️ **One detail was not captured:** whether the *graphical* installer worked under WSLg or whether the
headless route (`-- --unattended`) was needed. Setup Guide 02 §8 still presents both routes as
equals; it should name the one that works and keep the other as a fallback. Tracked as **T-014**.

With R1, R2, R3 and R9 all closed, **no risk in this project now has an external dependency.**

---

### ❓ OPEN — T-202: the SDP build number was never captured

`PLAN.md` §5 requires every chapter's front matter to record the exact SDP build it was written
against — the mitigation for **Risk R5** (version drift between SDP 8.0 patch releases). Block V3.3
would have produced it via `qnxsoftwarecenter_clt -listAvailablePackages`, but that output was not
reported.

**Consequence.** Chapters can be written, but their front matter cannot yet state the build. Promoted
to a learner action item and recorded as hazard **H-8** so it is not silently skipped.

---

### 🔍 VERIFIED — Commits are now published

The learner pushed `main` to GitHub manually. Commits 1–2 are authored as `Tyrostir`; commits 3
onward as `Karthikeyan Kasivishwanathan`. **History is now published and must not be rewritten.**

---

## 2026-08-26 — Session 007 (Setup Guide 03 published)

### 🔍 VERIFIED — QSTI and `mkqnximage` are not alternatives

QNX's official *QSTI for QEMU* documentation was read directly (about, getting started, additional
specifications, troubleshooting — all four pages, 2026-08-26).

**The finding.** ADR-004 records the VM strategy as "QSTI → CTI → raw `mkifs`", with `mkqnximage`
demoted to "still taught, but as an alternative, not the primary route". That reads as though QSTI
*replaced* `mkqnximage`. It does not:

| | |
|---|---|
| **QSTI** | The **image** — a pre-built QNX system, installed as QSC package `com.qnx.qnx800.quickstart.qemu`, unpacked by `unpack_qemu_image.sh` into `output/ifs.bin` and `output/disk-qemu.vmdk`. |
| **`mkqnximage`** | The **launcher** — `--run`, `--stop`, `--getip`. It is how QNX's own QSTI guide starts the image. |

**ADR-004 is not changed** — the QSTI → CTI → `mkifs` progression stands, and the reasoning behind it
is untouched. Only the *mechanics* differ from what was assumed. Recorded here so no future author
tries to "correct" Setup Guide 03 into avoiding `mkqnximage`.

---

### 🔍 VERIFIED — QSTI's default QEMU configuration

Documented flag by flag in Setup Guide 03 §6, per course rule #4 (nothing is a black box).

| Setting | Default |
|---------|---------|
| Kernel / disk | `output/ifs.bin` · `output/disk-qemu.vmdk` (IDE) |
| CPUs / RAM | `-smp 8` · `-m 4G` — ⚠️ QNX warns **above 16 GB may misbehave** |
| Network | `bridge,br=virbr0`, MAC `52:54:00:91:01:ea` |
| Display | `sdl,gl=on`, `vga none`; default mode `1280 x 768 @ 60` |
| Serial | `mon:stdio` — hence `Ctrl+A` then `X` to quit |
| Credentials | `root` / `root` |

Also recorded: on hosts with **more than 32 GB RAM**, QNX's *Screen* graphics subsystem can fail to
start, fixed with `host-phys-bits-limit=39` (Intel) or `40` (AMD). The host has 23 GB, so it should
not apply — documented anyway, because it is an obscure failure with a non-obvious fix.

---

### 🔍 VERIFIED — Ubuntu 26.04 skips QNX's build-QEMU-from-source step

QNX's guide supports **Ubuntu 22.04 / 24.04** and instructs those users to build **QEMU 10 from
source**, because their distributions ship older versions. Ubuntu 26.04 ships **QEMU 10.2.1** in
`apt`, already verified installed in block V1.

**Risk R9 — being ahead of the documented platform — works in our favour here.** Setup Guide 03 §2.2
says so explicitly, so the reader does not go looking for a build step they do not need.

---

### ❓ OPEN — Predicted: bridged networking may fail on WSL2 (hazard H-9)

QSTI defaults to `bridge,br=virbr0`. That bridge is created by **libvirt**, which runs as a
**systemd** service — and **WSL2 does not enable systemd by default**. The VM may therefore boot with
no network.

Setup Guide 03 §12.1 documents three fallbacks in order of preference: enable systemd via
`/etc/wsl.conf`, start the libvirt default network by hand (`virsh net-start default`), or fall back
to QEMU user-mode NAT with port forwarding (`hostfwd=tcp::2222-:22`, plus **8000** for `qconn` in
Chapter 08).

**This is a prediction, not an observation.** Whichever route works becomes the documented one and
the others move to the troubleshooting section. Verified by block **V5.5**.

---

### 🆕 DECIDED — `tools/qemu/qnx-vm.sh` is a convenience, never the taught path

A small wrapper ships with the repository: `run`, `stop`, `ip`, `ssh`, `status`.

**Why it is deliberately thin.** It does nothing `mkqnximage` cannot. It exists to fail with a useful
message instead of `command not found`, to source the SDP environment if the user forgot, and to
remember the image directory.

**Why the guide tells the reader to use the real commands first.** Course rule #4. A convenience
wrapper introduced before the underlying command is understood is exactly the black box this course
promises not to create. Setup Guide 03 §7.2 states this explicitly and invites the reader to read the
script, which is short and commented.

---

## 2026-08-26 — Session 008 (First real run of Setup Guide 03; three bugs)

### 🔍 VERIFIED — `unpack_qemu_image.sh` extracts into a nested `qemu/` directory

The learner reached **V5.3** and `mkqnximage --run` refused:

```text
The current directory is neither that of an existing mkqnximage virtual image nor is it
an empty directory. ... you have to include the --force option to enable it.
```

**Cause.** The unpack script does not extract into the current directory; every path it writes begins
`qemu/`. The image therefore lives at **`~/qnx800/images/qemu/qemu`** — `qemu` twice.
`mkqnximage` identifies an image directory by the presence of `local/` and `output/`; from one level
up it sees archives and a script, so it concluded the user wanted to **create a new image** in an
unusual place and asked for confirmation.

**Fix.** `cd qemu`, then `mkqnximage --run`.

**⚠️ The dangerous part.** The error message names `--force`, and `--force` is the wrong answer.
It does not mean *run anyway*; it means *yes, create a new virtual image here* — which would build a
fresh image beside the archives and ignore the 47 GB one just unpacked. Setup Guide 03 §7 now quotes
the error verbatim and warns against the flag it recommends.

**Why the guide got it wrong.** QNX's official documentation says to run the script and then
`mkqnximage --run` "from the qemu folder", without mentioning that the script *creates* a nested
`qemu/`. From the documentation alone the instruction reads as complete. Logged as **D-006**.

---

### 🔍 VERIFIED — `qnxsoftwarecenter_clt -listAvailablePackages` does not exist

```text
Error: Unknown argument: -listAvailablePackages
```

**This bug had been in the course since Setup Guide 02 was written**, was carried into Setup Guide 03,
and was quoted in `ToDos.md`, `VerificationRuns.md` and `CLAUDE-MEMORY.md` as the command that would
close T-202. It never would have.

Verified against CLT **`2.0.4:v202501021438`**, the real options are `-list`, `-listAccessible`,
`-listQuery`, `-listInstalled`, `-listInstalledRoots`, `-listUpdates`. Also clarified:
`-installPackage` installs one package, `-installBaseline` installs a whole SDP baseline.

Corrected in every live instruction. Logged as **D-007**.

> 💡 **The lesson for the author.** Option names are exactly the kind of detail that *looks* verified
> because it appears in a plausible sentence. `-help` is cheap; guessing is not. Recorded as hazard
> **H-10**.

---

### 🔍 VERIFIED — What the QSTI image actually contains

| Artefact | Size | Significance |
|----------|------|--------------|
| `ifs.bin` | 20 MB | The bootable image — Chapter 21 builds one |
| `disk-qemu` + `.vmdk` | 47 GB apparent + 171 B descriptor | Likely sparse; see **D-008** |
| `procnto-smp-instr.sym` | 12 MB | Kernel debug symbols. The name says **SMP** and **instrumented** — the variant supporting kernel event tracing, which is what makes Chapter 26 possible |
| `output/build/` | — | ⭐ The actual **`mkifs` build files**: `ifs.build`, `system.build`, `disk.layout`, `startup.sh`. **Chapter 21's source material, already on disk** |
| `output/option_files/`, `local/snippets/` | — | The CTI feature switches: `opt_valgrind`, `opt_secpol`, `opt_python`, `opt_graphics` and dozens more |

The archive is `qnx_sdp8.0_qemu_quickstart_20260606.tar.gz.{0,1}` — a **6 June 2026** build stamp,
not the `__xxxxxxxx_.tar.gz._xx` pattern the documentation implied.

**Also learned:** the QSTI package was **already installed** with SDP 8.0. The V5.1 detour through
QNX Software Center was unnecessary. Setup Guide 03 §4.2 now says to check
`~/qnx800/images/qemu` first.

---

### 🆕 DECIDED — ADR-025: `/btw` marks an aside that must become a `D-NNN` entry

Requested by the learner. ADR-014 already promises every question becomes a permanent artefact; in
practice the ones that slip through are those asked *in passing*, which read like rhetorical asides.
The marker removes the ambiguity, and works inside `toAgent/` drops so a question can be raised at
the moment it occurs during a lab.

> ⚠️ **Note for this session.** The learner asked that the `/btw` questions be documented, but the
> drop file contained no `/btw` lines. The convention is now established and documented in both
> `Doubts.md` and `toAgent/README.md`; the three technical questions the run *did* raise were logged
> as D-006, D-007 and D-008 regardless, under ADR-014.

---

### ❓ OPEN — The disk budget needs a third revision

`PLAN.md` §7.1 has already gone from ~25 GB to ~50 GB. The QEMU image adds ~1.9 GB of archives plus
`disk-qemu`, whose *real* cost is unknown until `du -sh` is run — `ls -lh` reports apparent size, and
sparse files make the two very different. Tracked as **T-016**; the figure will be corrected once
measured rather than guessed again.

---

## 2026-08-26 — Session 009 🎉 (Milestone M2: the VM boots)

### 🎉 VERIFIED — QNX 8.0.0 boots on QEMU/KVM under WSL2

**Milestone M2 reached.** The target identifies itself as:

```text
QNX qnxqemu 8.0.0 2026/02/27-11:02:56EST x86pc x86_64
```

| Item | Value |
|------|-------|
| Kernel | `procnto-smp-instr` — **SMP** and **instrumented** (supports kernel tracing, Ch 26) |
| Build | `2026/02/27-11:02:56EST` · image stamp `20260606` |
| At idle | **31 processes, 207 threads**, 3659/4095 MB free, 8 CPUs |
| Network | `vtnet0` (virtio) · `192.168.122.46/24` |
| Startup | `slm` with **22 components**, `slog2` first, `qconn` and `sshd` among them |

This is the version identity `PLAN.md` section 5 requires in every chapter's front matter, and it
partially answers **T-202**.

---

### CLOSED — Hazard H-9: the `virbr0` bridge prediction was wrong

Session 007 predicted that QSTI's default `bridge,br=virbr0` networking would fail on WSL2, because
the bridge is created by libvirt, which runs under systemd, which WSL2 does not enable by default.
Three fallbacks were documented.

**None were needed.** The bridge worked on the first attempt, on libvirt's default
`192.168.122.0/24` subnet. Installing `libvirt-daemon-system` in Setup Guide 01 was sufficient;
WSL2's networking carried it without systemd supervising anything.

**Consequences.** Setup Guide 03 section 12.1 is downgraded from "the most likely failure in this
guide" to a contingency, with the successful result stated up front so no reader troubleshoots a
problem they do not have. The fallbacks are kept - they are correct, just unnecessary here.

> Worth recording that a prediction failed. The guide was written with an honest guess clearly
> labelled as a guess. Reality disagreed, and the document now says so. That is the protocol working
> in the direction people forget to check.

---

### VERIFIED — `sshd` refuses root password authentication (the V5.5 blocker)

`root`/`root` logs in perfectly at the serial console and is refused over SSH:

```text
root@192.168.122.46: Permission denied (publickey,password).
```

**Cause.** OpenSSH has shipped `PermitRootLogin prohibit-password` as its default since version 7.0.
Root may authenticate with a **key**; a password attempt is rejected regardless of correctness. The
error's `(publickey,password)` lists what the *server* offered - password was on offer, but not for
root.

**Remedies, best first:** use **`qnxuser`** and `sudo -i`; or set `PermitRootLogin yes` in
`/etc/ssh/sshd_config` (may not survive a reboot, since a QSTI system is largely rebuilt from the
image - itself a preview of Ch 21); or install a key, which is what Chapter 08's debug loop will want
anyway.

**`qnxuser` is inferred, not confirmed.** The evidence is circumstantial but strong: the login
banner gives `qnxuser` as the VNC password, the image ships `system_files.custom.sudoers` and
`data_files.custom.var_users`, and the banner instructs `sudo apk update` - advice that only makes
sense for a non-root account. Confirmation via `/etc/passwd` is **T-018**. Logged as **D-009** and
hazard **H-11**; `scp` is affected identically.

---

### VERIFIED — Four boot-log warnings are benign

`ACPI table not found`, `Unable to start "uname" (2)`, `slog2_api: cannot connect to slogger2 server`
and `rm: /etc/ca-certificates/extracted: No such file`. Three are startup-ordering artefacts; one is
a cleanup script tidying a file that was never there.

**Why this earns a doubt entry.** A learner meeting their first QNX boot cannot tell noise from
failure, and these appear *before* the login prompt - the most alarming possible position. Logged as
**D-010**, with the general rule: early-boot complaints about services that start later are almost
always ordering noise.

---

### VERIFIED — The `pidin` output is better teaching material than anything written from documentation

The captured listing is now the backbone of Setup Guide 03 section 8 and feeds Chapters 09, 11 and 13:

- **Drivers are user-space processes.** `devb-eide`, `io-sock`, `io-usb-otg`, `devc-ser8250`,
  `drm-virtio` all have PIDs. Only `procnto` is the kernel. The microkernel argument needs no prose.
- **The 256-priority scale is visibly in use:** `0f` idle, `10r` services, `21r`/`25r` drivers,
  `254i`/`255i` kernel interrupt threads.
- **Live message passing.** `fullscreen-winmgr` sits in `REPLY 249881` (waiting on `screen`), and
  `screen` thread 13 sits in `REPLY 184343` (waiting on `io-hid`). A chain of synchronous `MsgSend`
  calls, visible in one column, on a system nobody instrumented.
- **`ldqnx-64.so.2` is in `/proc/boot`** - the exact file Linux could not find in Setup Guide 02.
  The loop that guide opened is closed by a directory listing.

---

## 2026-08-26 — Session 010 (Phase 1 complete: the loop closes)

### VERIFIED — A binary cross-compiled on Linux runs on QNX

```text
[root@qnxqemu /tmp]# ./hello_qnx
Hello from QNX!
My process ID is 14032920
```

**Block V5 complete. Milestone M2 complete. Phase 1 complete.** The full
**edit -> cross-compile -> deploy -> run** loop that Setup Guide 02 deliberately left open is closed.
Setup Guide 03 is promoted to **v2.0**, and **no `[UNVERIFIED]` marker remains anywhere in the
course**.

Setup Guides 01, 02 and 03 have now all been executed end to end on the real host. Between them they
cost **eight documented bugs** and **two wrong predictions** to get right - every one of which read
as perfectly reasonable when written from official documentation.

---

### CORRECTED — D-009: the image ships `PermitRootLogin no`, not `prohibit-password`

Session 009 attributed the SSH refusal to OpenSSH's shipped default,
`PermitRootLogin prohibit-password`. Reading the target's actual configuration showed:

```text
PermitRootLogin no
PasswordAuthentication yes
```

**Why the difference matters, and why this is a real correction rather than a detail.** Under
`prohibit-password`, root may still log in **with a key**. Under `no`, root is refused by *every*
method. Setup Guide 03 section 9.5 had told the reader that a key would let root in - actionable
advice that would simply not have worked. Corrected in the guide and in D-009.

> The lesson repeats the one from D-007: a plausible, well-known default is not the same as the
> value in the file in front of you. `grep` the file.

A related trap, now documented in D-011: the learner's `grep` also matched three **comment** lines,
one of which mentions `prohibit-password`. Reading a commented-out value as the live setting would
have produced exactly the wrong conclusion.

---

### VERIFIED — Target accounts, and a security observation worth recording

```text
root:x:0:0:root:/data/home/root:/bin/bash
sshd:x:15:15:sshd:/data/var/chroot/sshd:/bin/false
qnxuser:x:1000:1000:qnxuser:/data/home/qnxuser:/bin/bash
user1..user6
```

| Detail | Significance |
|--------|--------------|
| Homes under `/data/home/` | `/data` is the **writable partition**; the rest of the system comes from the read-only boot image. This is why edits to `/etc` may not survive a reboot, and it is the shape of most embedded systems. |
| `sshd` with `/bin/false` and a chroot home | **Privilege separation** - untrusted network data is parsed by an unprivileged, chrooted child before anyone authenticates. |
| `qnxuser` holds full `sudo`, password `qnxuser` | |

**The security observation.** Every credential on this image is a published default -
`root`/`root`, `qnxuser`/`qnxuser`, VNC `qnxuser` - and `qnxuser` has full `sudo`. So
`PermitRootLogin no` buys much less than it appears to: anyone who can reach port 22 with the default
password has root anyway. Entirely fine for a disposable VM on a private virtual network, and
unacceptable anywhere else. Stated plainly in Setup Guide 03 section 9.3.1, and it becomes a worked
example in Chapter 28.

---

### VERIFIED — QNX process IDs are large and non-sequential (D-013)

`hello_qnx` ran as PID **14032920**; the boot listing showed 16386, 32773, 1458208, 13520913. Not a
counter.

**Why this earns a doubt entry rather than a footnote.** It is the first genuinely QNX-specific thing
a learner meets after `Hello from QNX!`, and the explanation is load-bearing for the rest of the
course: a QNX PID is an **addressable endpoint for message passing** (`ConnectAttach`), not merely a
label for `kill`. Small, promptly-recycled IDs would let a stale connection reach a different,
newly-created process - unacceptable where messages carry control commands in a real-time system.

This is the same instinct that will reappear with connection IDs, channel IDs and server identifiers
in Chapters 13 and 16: identifiers that name an IPC endpoint are treated as capabilities, not
indices, and QNX would rather an operation fail loudly than succeed against the wrong target.

---

### ANSWERED — "SSH as root seemed to accept the qnxuser password" (D-012)

The learner reported this as a surprise. **The transcript contradicts it**: `ssh root@` failed three
times, `ssh qnxuser@` succeeded. With `PermitRootLogin no` the username is rejected before any
password is examined, so no password can work.

Logged rather than waved away. "It worked and I don't know why" is the worst state to leave a
security control in, and the most likely explanations - shell history recalling the `qnxuser@` line,
or the `[root@qnxqemu ~]#` prompt after `sudo -i` - are recorded so the observation is closed rather
than lingering. If a successful `ssh root@` can ever be reproduced, that would be a genuine finding:
it would mean `sshd_config` is not the file in effect.

---

### Evidence note (ADR-024)

V5.6's `scp` transfer and V5.7's shutdown command were not themselves captured in the drop - the
binary was already on the target, and the session ended with `exit`. The **outcomes** are confirmed
(the program ran; the learner attested the block complete), and the transfer path is the same SSH
channel proven in V5.5. Recorded so the standard of evidence stays visible rather than quietly
relaxed at the finish line.

---

## 2026-08-26 — Session 011 (Chapter 00 published)

### DECIDED — Chapter 00 is the reference implementation of the chapter template

`PLAN.md` section 5 defines the mandatory chapter skeleton in the abstract. Chapter 00 is now the
concrete example, and future chapters should be written by matching it rather than by re-reading the
specification.

**Two adaptations the template needed for a meta-chapter**, recorded so they are not mistaken for
drift:

| Template section | Chapter 00's version |
|------------------|----------------------|
| **4. The API** | **The Notation Reference.** Chapter 00 teaches no QNX API; its "API" is the course's own notation - symbols, prompts, identifiers, lab layout, target quick reference. |
| **5. Worked Example** | A *sample chapter section* in the house style, followed by a line-by-line reading of why each element is there. Teaching the reader to read, rather than to code. |

Everything else is unchanged: promise, Fast-Track Summary, objectives, prerequisites, mental model,
problem/concept/mechanism, labs with a break-it and a Path A activity, mastery check with collapsed
answers, recap, cheat sheet, further reading, what's next, changelog.

---

### DECIDED — Chapter 00's labs use the verified VM rather than being theoretical

Chapter 00 could have been pure prose. It is not, because the environment was verified first:

- **Lab 00.1 (core)** runs `check-environment.sh`, boots the VM, and introduces `uname -a`, `pidin`,
  `pidin info` and `ls /proc/boot` - the four commands used in almost every later lab. Every expected
  output is real, from the target verified in block V5.
- **Lab 00.2** establishes three habits: two terminals (host and target), SSH keys instead of
  passwords, and reading `CourseState.md` after a break.
- **The break-it exercise** deliberately runs `mkqnximage` from one directory too high, reproducing
  **D-006**, and asks the reader to work out what `--force` would actually do before reading the
  answer.

**Why the break-it exercise is that one.** The course's first deliberate failure should teach the
*diagnostic habit*, not a QNX API - and this failure costs nothing, has a real error message, and
carries a genuine trap: the message recommends a flag that would make things worse. It also converts
a bug the course hit for real into teaching material.

---

### VERIFIED — Chapter 00 passes the style rules mechanically

Audited: exactly one H1, no heading-level skips, no GitHub-only alert syntax, no raw HTML beyond
`<details>`, two Mermaid diagrams each followed by a one-line text description, all links relative,
a cheat sheet, and a changelog. Glossary gained 10 terms and two new letter sections, kept
alphabetical.

---

## 2026-08-26 — Session 012 (Chapter 01 and the first compiled lab)

### DECIDED — Chapter 01 gets a 🏃 Fast-Track Summary even though the TOC tags it 🐣🚶

The Table of Contents tagged Chapter 01 as Path A and B only, on the reasonable grounds that an
experienced engineer already knows what real-time means.

**ADR-008 wins.** Every chapter must carry a genuine Fast-Track Summary a professional could work
from — a path that exists only as a marker is a broken promise. Chapter 01's box is therefore written
for someone who *does* know the material: it fixes the vocabulary this course will use strictly,
states the `R` vs `C` distinction and the ~69 % rate-monotonic bound, and then explicitly sends the
reader to Chapter 02.

The TOC tag is updated to 🐣🚶🏃. **The tag means "Path C may skip the body", not "Path C is
unserved".**

---

### DECIDED — Section 4 adapts again, and this is now a pattern

Chapter 00 turned "The API" into *The Notation Reference*; Chapter 01 turns it into *The Vocabulary*
— eight quantities with symbols and units, the response-time versus execution-time trap, utilisation,
and the five things a testable timing requirement must name.

**The rule this establishes:** section 4 is *the precise, referenceable material a reader will come
back to*. In a chapter teaching an API that is function signatures; in a chapter teaching a way of
thinking it is the definitions. Chapters 02 and 03 will need the same latitude; from Chapter 05
onwards section 4 becomes literal APIs and stays that way.

---

### DECIDED — The first compiled lab is a measurement, not a "hello world"

`labs/lab01_timing/` asks for a 1 ms sleep ten thousand times and reports min/mean/p50/p99/max.

**Why a measurement.** The course has already run a hello-world on the target (block V5.6), so
repeating it would teach nothing. A jitter measurement instead makes the learner *produce the
evidence for the chapter's central claim themselves* — that the mean is a throughput statistic and
the maximum is the only number a deadline can rest on. Reading that assertion is weak; measuring it
is not.

**Deliberately plain POSIX, not QNX-specific.** It builds unchanged on Linux, so the learner can run
both and compare tails. QNX-specific timing (`ClockCycles`, `ClockPeriod`) waits for Chapters 14
and 26.

**A plain Makefile calling `qcc` directly**, per ADR-007 — the recursive QNX Makefile system is
Chapter 08's subject and would be a black box here.

---

### DECIDED — Path A activities do not depend on binaries this course cannot build

The Definition of Done asks for a pre-built binary in `labs/labNN_*/prebuilt/` so Path A can run
something without a compiler.

**`prebuilt/` is left empty, deliberately.** The course does not ship compiled artefacts it has not
verified, and ADR-024 means the author cannot build them. Rather than shipping an unverified binary
or quietly dropping the Path A requirement, **Chapter 01's Path A activity is designed to need no
binary at all**: five systems to classify by consequence, and a drone stopping-distance budget to
compute on paper — whose punchline is that 30 of the 46 ms are physics, not software.

**The general rule for future chapters:** where a verified binary exists, ship it; where one does
not, the Path A activity must be answerable from observation and reasoning. Path A must never be the
path that silently gets less.

---

### VERIFIED — Chapter 01's lab source is syntax-clean, and nothing more

`gcc -fsyntax-only -Wall -Wextra` passes on `solution/jitter.c` with no warnings.

**That is a much weaker claim than it sounds**, and is recorded so it is not mistaken for
verification: it was checked with the **host's GCC 15**, not with **`qcc` (GCC 12.2.0)**, and it has
never been run on the target. The lab and both of Chapter 01's compiled exercises are marked
`[UNVERIFIED]` accordingly.

**Block V6 verifies the lab mechanism itself** — first Makefile, first skeleton/solution pair, first
build-deploy-run cycle. Whatever breaks there breaks in all 33 remaining chapters, which is why it is
worth a numbered block rather than a footnote.

---

## 2026-08-26 — Session 013 (A rule gap, found by the learner)

### VERIFIED — The writing rules did not cover library functions

The learner asked what `clock_gettime`, `nanosleep`, `perror` and `qsort` are, whether they are C++
or QNX, and which files they live in. All four appear in Chapter 01's lab with no explanation
whatever.

**This violated course rule #4 — "nothing is a black box" — and the rules permitted it.**
`PLAN.md` section 2, rule 1 read: *"Never assume a term. First use of any **term** -> defined inline
and added to Glossary.md."* A function is not a term, so four unexplained function calls passed every
check the course had.

**Fix, at the rule level rather than the instance level:**

- Rule 1 extended: *"This includes library functions"* - purpose, arguments, return value, and the
  header each lives in, or a link to where that is explained.
- A matching checkbox added to the per-chapter Definition of Done (section 17), so it is verifiable
  rather than merely intended.

> The instance was worth fixing; the rule was worth fixing more. A gap that a reader has to find is a
> gap the process should have found.

---

### VERIFIED — Auditing under the new rule found five more, in the same chapter

A case-sensitive sweep for function references across both published chapters returned nine tokens.
Two (`refine()`, `process()`) are invented placeholders in illustrative snippets. **Five were real,
unexplained calls in Chapter 01 itself:**

| Call | Where | Now |
|------|-------|-----|
| `InterruptDisable()` / `InterruptEnable()` | section 3.2 | Explained, and flagged as **QNX-specific** - unusual for this point in the course |
| `qsort()` | section 3.2 | Explained, with a pointer to the full signature in the lab README |
| `pthread_mutexattr_init`, `pthread_mutexattr_setprotocol`, `pthread_mutex_init` | section 5.3 | Explained in a table, plus the trap that the `pthread_*` family **returns an error number rather than setting `errno`** |
| `ClockPeriod()` | lab notes | Named as a QNX call in `<sys/neutrino.h>`, with its chapter |

Chapter 01 -> v1.2. **The audit is now the standing procedure before publishing any chapter**, and is
recorded as hazard **H-12**.

---

### The substance of D-014, recorded because it recurs

**None of the four functions is C++, and none is QNX-specific.** `qsort` and `perror` are **ISO C**;
`nanosleep` and `clock_gettime` are **POSIX.1b**, the 1993 real-time extensions. Declarations in
`<stdlib.h>`, `<stdio.h>` and `<time.h>`; machine code in **`libc.so.6`**, which the learner had
already seen listed in `/proc/boot`.

**That is the concrete meaning of "QNX is POSIX-compliant"** - the same claim made abstractly in the
Glossary since planning, now attached to four functions the learner can read in a header on their own
disk. QNX's own calls live in `<sys/neutrino.h>` and arrive in Chapter 13.

Two traps documented alongside, because neither is a matter of style:

- **`return (a > b) - (a < b);` rather than `return a - b;`** in a comparator. The obvious form
  **overflows** for distant values and returns the wrong sign, mis-sorting silently with no error
  anywhere.
- **The lab sorts *after* the measurement loop.** `qsort`'s worst case is unspecified by the C
  standard, making it precisely the *unbounded computation* of Chapter 01 section 3.2 - appearing, unremarked,
  inside the lab that teaches it. Now remarked. The general lesson: real-time discipline is less about
  forbidden functions than about keeping unbounded work off the deadline path.

---

## 2026-08-26 — Session 014 (Chapter 02)

### VERIFIED — QNX's history, from primary sources rather than memory

Chapter 02 is history-heavy, and asserting wrong dates in a published chapter is a different kind of
error from a wrong command: nobody's build fails, so nobody finds it. The timeline was therefore
checked against QNX's own account and BlackBerry's announcements before publishing.

| Fact | Source |
|------|--------|
| 1980 founding by **Dan Dodge** and **Gordon Bell**, University of Waterloo graduates, as **Quantum Software Systems Limited**; product **QUNIX** | QNX's *"A little history"* |
| AT&T cease-and-desist over the Unix trademark forces the rename to **QNX** | same |
| First commercial release **1982**, for the Intel **8088** | same |
| **QNX 4 around 1991** — 32-bit and **POSIX support** | same |
| **QNX Neutrino, 1995** — the origin of `procnto` | same |
| Eclipse founding member; **Momentics Tool Suite, 2002** | Wikipedia / QNX |
| **Harman International, 2004**; **RIM/BlackBerry, 2010**, ~$200 million | Wikipedia |
| **QNX Everywhere announced January 2024** | BlackBerry |
| **QNX SDP 8.0 general availability, 21 March 2024** | BlackBerry press release + SDP 8.0 release notes |

**One trap worth recording.** QNX's co-founder **Gordon Bell is not the DEC computer architect of the
same name** (Bell's Law, the Gordon Bell Prize). Search engines conflate them freely. Noted in the
chapter so a reader chasing the history does not end up in the wrong biography.

---

### DECIDED — Chapter 02 states the microkernel's costs, not only its benefits

The obvious way to write this chapter is as an argument for QNX. Section 2.2 instead lists what the
design costs — a message where a monolithic kernel makes a function call, context switches across
address spaces, 31 processes at idle, and a driver model nobody arrives already knowing — and says
plainly:

> "For a build server or a laptop, this trade is simply bad... **QNX is not a better Linux.** It is a
> different answer to a different requirement."

**Why this matters more than it looks.** A course that only argues for its subject produces readers
who cannot tell when *not* to use it — which is the judgement an employer is actually paying for.
Chapter 03 is built on the same principle and will include the cases where the honest answer is
"use Linux".

The section also credits Linux's movement in QNX's direction (FUSE, DPDK, SPDK, `PREEMPT_RT`) and
names what remains genuinely different: a **certified** version with a vendor's evidence package.

---

### DECIDED — The real argument for the microkernel is evidence, not reliability

Section 1.3 makes a point the usual telling omits. Fault isolation is the *familiar* benefit; the one
that put QNX in vehicles is that isolation can be **demonstrated to a third party**.

Under ISO 26262, freedom from interference must be shown with evidence. In a monolithic kernel every
privileged component is potentially in scope — the safety case has to reason about the graphics
driver, because it runs with the same authority as the safety task. With hardware-enforced process
boundaries, the argument becomes structural and the scope shrinks to the microkernel plus the
components actually chosen.

> This also explains the historical puzzle the chapter raises: microkernels largely *lost* the 1990s
> performance argument, and Mach survives mainly as a hybrid inside macOS. QNX kept the design, and
> what turned out to be worth having was not the isolation itself but the ability to prove it.

---

### DECIDED — Section 4 becomes "how to date what you read"

Following the pattern from Chapters 00 and 01, section 4 holds the chapter's referenceable material —
here, the product family and version map, plus **four signals for spotting stale QNX documentation**:
the `blackberry.qnx.com` domain, "Neutrino" in a product name, `io-pkt` where 8.0 uses `io-sock`, and
the version segment in a documentation URL.

**Why this earns a whole section.** There is not a great deal written about QNX, and much of the best
explanatory material is old. Telling a learner to avoid old sources would be bad advice; teaching
them the rule — **concepts age well, commands age badly** — is the useful version.

The section explicitly includes this course in the warning: its own guides have been wrong five times
so far, which is why `[UNVERIFIED]` exists.

---

### VERIFIED — The library-function audit was applied during authoring, not after

Hazard **H-12** and the new `PLAN.md` section 17 checkbox were applied while writing rather than
afterwards. Chapter 02 introduces `MsgSend`/`MsgReply` (with headers, blocking behaviour and a
pointer to Chapter 13) and `open`/`read`/`write` (POSIX, with the observation that they are
*unchanged* on QNX and become messages underneath — which is the chapter's thesis restated at the
API level). Every shell command in the labs is tabled with its standard and purpose.

**The audit found nothing to fix afterwards**, which is the first evidence that the rule change from
Session 013 works.

---

## 2026-08-26 — Session 015 (Chapter 03; Part 0 complete)

### VERIFIED — Market and certification figures, from BlackBerry's own announcements

Chapter 03's numbers will be quoted by learners in meetings, so they were checked rather than
recalled:

| Claim | Source |
|-------|--------|
| **255 million vehicles**, +20 million year on year, +80 million since 2020 | BlackBerry announcement, **15 October 2024** |
| IEC 61508 **SIL 3** · ISO 26262 **ASIL D** · IEC 62304 **Class C** · EN 50128 / EN 50657 **SIL 3** | BlackBerry / QNX |
| QNX Hypervisor was the **first hypervisor certified to ASIL D** | BlackBerry press release |
| Diversification into **robotics and medical**, leveraging existing certifications | BlackBerry |

**Chapter 02 already cited the 255 million figure** in its Fast-Track Summary; this pass confirmed it
rather than leaving a published number unsourced.

---

### DECIDED — Chapter 03's thesis is that certification, not latency, usually decides

The obvious way to write "why QNX" is a latency argument. The chapter instead makes the deciding
question **"will an independent assessor examine this system?"**, and says so in the mental model:
*latency is an engineering problem with many solutions; certification is a procurement and liability
problem with very few.*

**Why this framing.** An engineer who can only quote interrupt latencies is not useful in the meeting
where the decision is actually made. The four questions people are really asking — can we ship
without being sued, will the assessor accept it, can we afford it, will a supplier's bad driver kill
our product — are three parts commercial to one part technical.

Section 3 reinforces it by giving **each industry a different reason**: automotive chose QNX for
consolidation and ASIL D, medical for schedule and evidence, rail for SIL 3 with *loose* deadlines,
robotics for mixed criticality. Rail is the sharpest illustration — deadlines measured in seconds, and
nobody chose QNX there for speed.

---

### DECIDED — One of the three worked examples answers "Linux", stated as strongly as the others

Section 5.2's telemetry gateway reaches **Linux** and the reasoning is given at full length, not as a
concession.

**Why this matters more than it looks.** A course that cannot say when its subject is the wrong
answer produces readers who over-apply it — and the telemetry gateway is precisely the project that
gets over-engineered onto an RTOS in real life. The chapter also warns against the specific fallacy
that does it: *"industrial" is a market; "real-time" is a timing property.*

The competitive table extends the same discipline: it credits `PREEMPT_RT`, names Linux's ecosystem
and hiring advantages as decisive in the right context, and points at the **ELISA project** rather
than claiming Linux "cannot" be certified. The precise claim made is narrower and defensible: **no
mainline Linux is certified to ASIL D today.**

---

### DECIDED — The break-it exercise for a judgement chapter is "argue the wrong side"

Chapters 00–02 used deliberate failures with a command and an error message. Chapter 03 teaches
judgement, which cannot be broken that way, so its 💥 exercise asks the reader to build the strongest
possible case for QNX on the project where the answer was clearly Linux — then find where it breaks.

**The instructive part is that one of the four counter-arguments survives.** *"We already have QNX
licences and QNX engineers"* is a legitimate engineering input, and the exercise says so — while
insisting it be stated as what it is rather than dressed as a technical requirement.

> Most bad OS decisions are not made by fools. They are made by reasonable people generalising a real
> requirement from a project where it applied. Teaching the reader to construct the opposing case is
> the only defence that scales.

---

### DECIDED — Part 0's review is the one-page memo, and it is for every path

`PLAN.md` designates a "Should we use QNX?" memo as the Part 0 review. It is placed as Chapter 03's
🐣 Path A activity — with a note that all paths should do it — and given a structure (deadline,
certification, isolation, recommendation, cost of being wrong **in both directions**, what would
change my mind).

**Section 6 carries the weight.** A worked table contrasts weak and strong versions, the difference
being that a strong one names **a test that could be run and a threshold that would flip the
answer**. That converts an opinion into a hypothesis, and it is the most transferable skill in Part 0
— it works on every technology choice, not just this one.

---

### 🎉 MILESTONE M1 — "I get it"

Part 0 is complete: Chapters 00–03. The learner can now define real-time precisely, explain QNX's
architecture and its costs, and decide — in either direction — whether a project should use it.

**Part 1 begins with Chapter 04 (licensing)** — which the learner has, unusually, already *done*
before reading about it, since the environment was built first.

---

## 2026-08-26 — Session 016 (Chapter 04; a published licensing error corrected)

### CORRECTED — Setup Guide 02 listed a permitted use as forbidden

Writing Chapter 04 required the licence terms, so they were read from QNX's licensing page rather
than restated from this project's earlier notes. That turned up an error in already-published
material.

| | |
|---|---|
| **Setup Guide 02 §2 said** | "Demo to existing or potential **customers** — Explicitly listed as commercial activity" ❌ |
| **QNX's licensing page says, under *permitted*** | *"Build or develop a product or system (e.g. as part of a product roadmap) to demonstrate to existing or potential customers."* ✅ |

The same section also over-stated the prohibition on building things, implying that even a roadmap
prototype was forbidden. QNX permits hobby/maker use to *"build a product or system"*, with the
condition attaching to **commercialisation and production**, not to construction.

**Why this error is worse than a wrong command.** A wrong command fails visibly and gets reported. A
wrong licence claim fails **silently and in both directions** — it can make a reader refuse work they
are entitled to do, or reason by analogy into something they are not. Nobody's build breaks, so
nobody finds it.

**Fixed:** Setup Guide 02 → **v2.2** with the permitted list expanded and the exact QNX conditions
quoted; `CompactContext.md` and `CLAUDE-MEMORY.md` corrected; the Glossary's **QNX Everywhere** entry
rewritten. Recorded as hazard **H-13**.

> ⚠️ **Note on this file.** `DecisionsLog.md` is append-only, so the incorrect line in the Session 001
> entry ("Explicitly *not* permitted … customer demos") **stays**. This entry supersedes it. That is
> the point of an append-only log: the record shows what was believed and when it was corrected.

**The rule this generalises to:** licensing claims must be checked against QNX's licensing page or
the EULA, never restated from an earlier course document. The same discipline already applies to
commands (ADR-024) and now to library functions (`PLAN.md` §2); licence facts are the third category
where restating beats checking, and should not.

---

### DECIDED — Chapter 04's thesis is that the boundary is production and distribution, not money

The intuitive framing is *"non-commercial means no money"*. The chapter argues that is wrong in both
directions, and organises everything around it:

- **Permitted despite money:** training material and books *"including if you intend to offer that
  material commercially"*; academic salaries and RA stipends.
- **Permitted despite looking commercial:** building a product or system as a hobbyist/maker;
  demonstrating a product to existing or potential customers.
- **Forbidden despite no money:** a permanent internal test rig is plausibly **production use**;
  sending one pilot unit is **distribution**.

The mental model diagram asks the questions **in that order** — production, then distribution, then
payment — because most people carry it money-first.

---

### DECIDED — The chapter teaches the two-licence structure explicitly

*"Distribution and production use is not permitted under a development license and requires a separate
distribution license."* This applies to commercial licence holders too, and is routinely discovered
during launch planning.

Chapter 04 states it three times — Fast-Track, §2.3, and the mastery check — and suggests asking
*"do we have a distribution licence, or only development?"* in month one of a project.

---

### DECIDED — §5 uses this course as a worked example

The clearest illustration of the licence's shape is the artefact the reader is holding: a public
repository teaching QNX, permitted under *"training material or books"*, which **never ships QNX
binaries** — Setup Guides 01–03 walk the reader through obtaining their own licence so that
distribution never arises.

**That was an architectural decision about the course, made for licensing reasons**, and saying so
demonstrates the chapter's point better than a hypothetical. It also explains why `prebuilt/` is
empty in `labs/lab01_timing/` — a decision taken in Session 012 for verification reasons, which turns
out to be the licensing-correct answer as well.

---

### VERIFIED — Filename alignment and a full cross-chapter link check

Chapter 04 was drafted as `Chapter04_Licensing.md`; the Table of Contents had long specified
`Chapter04_LicensingAndQNXEverywhere.md`. Renamed to match the TOC, and all references updated.

A link check across all five published chapters now reports **zero broken links**, with forward
references pointing only at planned filenames taken from the TOC (`Chapter05_InstallingQNXSDP.md`,
`Chapter06_FirstQNXVMOnQEMU.md`).

> This check is cheap and should run before every chapter is committed. Two chapters had already
> accumulated forward links to a filename that would never have existed.

---

## 2026-08-26 — Session 017 (Chapter 05)

### DECIDED — Chapter 05 is organised around one question, not around the directory tree

The obvious structure for "installing the SDP" is a directory-by-directory tour. Chapter 05 instead
puts a single test at the centre — **"which CPU and OS actually executes this file?"** — and derives
the layout from it.

**Why.** A tour produces a reader who can recite the tree; the question produces one who can place a
file they have never seen. It also unifies the four common build failures, which section 4.3 presents as
**one bug seen from four angles**: `qcc: command not found`, `sys/neutrino.h: No such file`, odd link
errors, and "builds but will not run" all mean *something reached into the wrong tree*.

The Path A activity is that test applied to eight items, and the one people miss — `mkifs` — is
instructive precisely because it *feels* like it belongs with the target files it assembles. It runs
on Linux.

---

### DECIDED — The chapter names the silent failure explicitly

Section 5.3 states that plain `gcc` on portable source produces a **working binary for the wrong
operating system**, with no error and no warning, discovered at deployment.

**Why this earns its own section.** Every other failure in the chapter announces itself. This one does
not, and it is the one that costs a day. The remedy offered is a habit rather than a rule: run `file`
as part of building, not only when debugging, and look for
`interpreter /usr/lib/ldqnx-64.so.2`. Chapter 08 puts it in a Makefile so it stops depending on memory.

---

### VERIFIED — What the chapter states as fact, and what it only predicts

Facts carried over from earlier verification blocks and stated plainly:

| Fact | Source |
|------|--------|
| `$QNX_HOST` = `~/qnx800/host/linux/x86_64` · `$QNX_TARGET` = `~/qnx800/target/qnx` | Block V4.1 |
| Cross-compiler is **GCC 12.2.0**, six targets across x86_64 and aarch64le | Block V4.1 |
| `interpreter /usr/lib/ldqnx-64.so.2` | Block V4.2 |
| Install cost ~**43 GB** | Block V3 `df` delta (D-008) |
| QSC CLT option list, and that `-listAvailablePackages` does not exist | Block V5.1 (D-007) |
| `$QNX_TARGET/x86_64/usr/bin` contents | Block V2 |

**Still only predicted**, and marked as such:

| Prediction | Where |
|------------|-------|
| That `-I` and `-L` paths point into `$QNX_TARGET` | §5.1 — **the chapter's central mechanism** |
| That `qcc -v` is the verbose flag | §5.2 |
| `$MAKEFLAGS`'s actual value | §3.2 — carried from Setup Guide 02's documentation, never observed |
| The `du -sh` per-directory breakdown | §3 deep dive |

Block **V10** exists to close exactly these. It is worth noting that the chapter's *most important*
claim is currently its least evidenced — reasoned from how cross-compilation must work rather than
observed — and the chapter says so where it matters.

---

### DECIDED — Chapters 04 and 05 both explain something the learner already did

This is now a deliberate pattern rather than an accident of sequencing. The setup guides came first
because the course needed a working environment; Chapters 04 and 05 explain the licence and the
installation **afterwards**, with the artefacts on disk.

**Why it works better than the conventional order.** A reader with `~/qnx800` in front of them can
run every command as they read, and the abstractions have referents. Chapter 05 §2.2 exploits this
directly: *"you can browse a QNX system on your Linux disk right now, without a VM."*

Both chapters say plainly that they run backwards from the usual order, so the reader knows it is
intentional.

---

## 2026-08-26 — Session 018 (Chapter 06; the first core chapter)

### DECIDED — Chapter 06 identifies `Startup complete` as the line that matters

The boot log has around twenty-five lines. Chapter 06 singles one out and says so plainly: **before
`Startup complete` you are debugging the BSP; after it you are debugging the system.**

**Why it deserves that emphasis.** It is the only line in the log that partitions the problem space.
On a dead custom board (Chapter 32) it is the first question anyone competent will ask, and a learner
who carries that one boundary can triage a boot failure on any QNX target without knowing anything
else.

Everything else in section 5 is placed relative to it: firmware before, kernel and services after.

---

### DECIDED — The syspage is introduced here rather than in Chapter 22

`startup-*` builds a structure describing the hardware it found, and hands it to `procnto`. **The
kernel contains no board-specific code** — it learns the machine from the syspage.

**Why introduce it in Chapter 06.** It answers a question the chapter unavoidably raises: how does one
`procnto` binary run on QEMU, a Raspberry Pi and an automotive SoC? Deferring the answer to Chapter 22
would leave a visible hole in the boot chain. The full treatment stays in the BSP chapter; what
Chapter 06 provides is the shape and why it exists.

---

### DECIDED — Section 3.3 makes the persistence rule explicit and testable

Only `/data` survives a reboot. `/proc/boot` is read-only; `/tmp` is RAM; `/`, `/usr` and `/etc` come
from the image's system partition.

**Why it earns a section.** It is the single most likely thing to waste a learner's afternoon, and it
contradicts the habit every desktop Unix user brings: *configuration lives in `/etc`*. Setup Guide 03
section 9.4 had already hedged on this for `sshd_config` without explaining the underlying rule.

**And it is tested rather than asserted.** The 💥 exercise writes to four locations and reboots. The
`/etc` result is flagged as the one to watch, because the course **predicts** it does not persist and
has never confirmed it — block **V11.3**. If `/etc` turns out to persist, section 3.3 and the Path A
answers both need rewriting, and the chapter says so.

---

### DECIDED — The labs open `output/build/` fifteen chapters early

Lab 06.2 has the learner read `ifs.build`, `disk.layout` and `build.date` — files whose syntax
Chapter 21 teaches.

**The reasoning.** Opening them now establishes three things cheaply: the image is **not magic**, it
is a text file and a build step; everything observed on the target is **declared** somewhere in those
files; and when Chapter 21 asks the learner to write one, they will have read one first. The lab says
explicitly that it will not fully make sense yet, and that this is fine.

`disk.layout` does double duty — it is the concrete, written-down answer to section 3.3's persistence
question.

---

### OPEN — V11.2 is the highest-value outstanding request in the course

`output/build/ifs.build` is **the complete recipe for the system the learner is running**: every file
in `/proc/boot`, every service `slm` starts, every partition on the disk.

**Why it outranks the other open blocks.** Chapter 21 is a `⭐ core` chapter and currently has no
concrete material — it would have to be written from QNX's documentation. With `ifs.build` and
`disk.layout` in hand it can instead be an annotated walkthrough of a system the learner has already
booted, explored and debugged. That is a categorical difference in quality, and it costs the learner
two `cat` commands.

Recorded here so that no future author writes Chapter 21 before asking for it.

---

## 2026-08-26 — Session 019 (Disk figures corrected from measurement; Chapter 07)

### VERIFIED — `du -sh ~/qnx800` settles D-008, and corrects six documents

```text
79G  ~/qnx800
53G  images/    23G  target/    2.7G  host/    1.1G  bsp/
315M custom/    24M  source/    4.6M  sources/  2.9M docs/   1.5M gfx-source/
```

**Three findings.**

**1. The virtual disk is *not* sparse.** D-008 speculated it might be, since `ls -lh` reported 47 GB
apparent. `images/` occupies **53 GB of allocated disk** — essentially the full apparent size plus the
1.9 GB archives. **Plan for the space; do not hope for a hole.** The speculation is retracted rather
than quietly dropped.

**2. The total is 79 GB, not ~43 GB.** And the two numbers do not contradict each other:

| Measurement | What it actually measured |
|-------------|---------------------------|
| **43 GB** (block V3) | A **`df` delta** — everything written *anywhere* during the SDP install, including QNX Software Center and its download cache, which live **outside** `~/qnx800`. Taken **before** the VM image was unpacked |
| **79 GB** (this drop) | **`du` on one directory**, taken after unpacking |

> 💡 **The generalisable lesson, worth more than the QNX numbers:** `df` measures *the filesystem over
> time*; `du` measures *a directory now*. Quoting one as though it were the other is how disk
> estimates go wrong. Both figures are now stated together, with the reconciliation, rather than one
> silently replacing the other.

**3. `bsp/` is 1.1 GB — Board Support Packages, already on disk.** Chapter 22's entire subject. This
is the third time material for a much later chapter has turned out to be present from the start, after
`output/build/` (Ch 21) and the `option_files/` CTI machinery (Ch 21). Added to Chapter 05's layout
with a pointer.

**Corrected:** `PLAN.md` §7.1 (~50 GB → **~85 GB** budget, third revision), Setup Guide 01 (~25 GB →
~85 GB, plus the completion checklist), Setup Guide 02 §12.1, Setup Guide 03 §5, Chapter 05
(Fast-Track, §1.2, §3.1 layout, deep dive, Lab 05.1 answers, recap), Chapter 06, and
**`tools/check-environment.sh`'s thresholds**, which would otherwise have passed a machine with 30 GB
free.

**T-016 closed.**

---

### DECIDED — Chapter 07 is built around one column of `pidin` output

The chapter could have been a tour of the shell. Instead it puts **blocking states** at the centre and
treats everything else as supporting material.

**Why.** When a QNX system misbehaves the question is almost never *"which process is using the
CPU?"* — the tools for that are the same everywhere. It is *"what is everything waiting for, and is
anyone waiting on someone who will never answer?"* One column answers that, and no `ps` has an
equivalent.

Three techniques carry the chapter, and all three are reusable:

| Technique | What it does |
|-----------|--------------|
| `pidin \| grep -v RECEIVE \| grep -v SIGWAITINFO` | Hides the healthy idle majority so the exceptions are immediately visible |
| Following the **`REPLY` chain** | Each `REPLY` names a PID; look it up and repeat, until you reach real work or a stuck thread |
| Looking for **cycles, dead servers and queues** | The three shapes a hang actually takes |

The Path A activity gives six lines of output containing a **three-process deadlock cycle** plus one
innocent victim, and asks the reader to identify both. Restarting the victim — the visible symptom —
would achieve nothing, which is the mistake the technique exists to prevent.

---

### DECIDED — `RECEIVE` is taught as the *normal* state, emphatically

A newcomer reading a `pidin` listing full of `RECEIVE` will reasonably conclude the system is stalled.
It is the opposite: servers block waiting for work and consume **no CPU**, so a healthy idle QNX
system is overwhelmingly `RECEIVE`.

Stated in the Fast-Track box, §3.2, the recap, the cheat sheet and a mastery-check question — five
times, deliberately, because the misreading is both natural and expensive.

---

### OPEN — V12.1 exists to give Chapter 25 a baseline

Chapter 25's `⭐ L25` is *"diagnose a hung system with `pidin`"*. Teaching someone to recognise an
**abnormal** listing requires a documented **normal** one, and the course does not have it: §3.2's
claim that `RECEIVE` dominates is reasoning, not measurement.

Block **V12.1** captures a state census of the healthy VM. It is cheap — four commands — and Chapter
25 is materially better with it.

> This is now the second time a block has been created to serve a much later chapter, after V11.2 for
> Chapter 21. Both are recorded so the dependency is visible when those chapters are written.

---

### The pattern this is the third instance of

| # | Claim | How it was wrong | Found by |
|---|-------|------------------|----------|
| 1 | `-listAvailablePackages` | The option does not exist | Running it (D-007) |
| 2 | Customer demos are forbidden | Exactly backwards | Reading the licensing page (Ch 04) |
| 3 | The disk image is probably sparse | It is not; and the total was ~40 GB low | Running `du` (D-008) |

All three were **plausible, well-sourced and wrong**, and none would have been caught by re-reading
the course's own documents — which is precisely why `[UNVERIFIED]` and the verification blocks exist.

> ⚠️ **The one that would have hurt most is #3**, because `check-environment.sh` was actively telling
> readers that 30 GB of free disk was "just enough". A wrong number in a *check script* is worse than a
> wrong number in prose: it carries the authority of a test.

---

## 2026-08-26 — Session 020 (Chapter 08; Parts 0 and 1 complete)

### DECIDED — Chapter 08's centre is the symbols-stay-on-the-host split

The chapter could have been a `qcc` flag reference. Instead it is built around **remote debugging**,
and specifically around one design decision: `gdb` runs on the host with the debug information, while
`qconn` on the target does control and speaks only in addresses and raw memory.

**Why that framing.** It explains three things at once that otherwise look arbitrary: why a production
target can ship a **stripped** binary and stay debuggable, why Chapter 05's `.sym` files exist, and
why core-dump analysis in Chapter 25 works the way it does. One idea, three payoffs.

**And it comes with a cost, stated with equal weight.** Nothing verifies that the binary on the target
is the one the host has symbols for, so **mismatched builds produce confident, detailed, entirely
fictional answers**. The 💥 exercise reproduces this deliberately, because it is worse than a crash —
a crash tells you something is wrong.

The remedy offered is structural rather than vigilance: never deploy by hand, and make `run` and
`debug` depend on `deploy`, which depends on the build. Stated in section 3.2, section 4.3, section 4.5, the
recap and a mastery-check answer.

---

### DECIDED — `labs/lab08_devloop/` inverts skeleton and solution

Chapter 00 established the convention: `skeleton/` has `TODO`s to fill in, `solution/` is the complete
reference.

**Lab 08 reverses it.** `skeleton/avg.c` is a **complete, compiling, subtly wrong** program;
`solution/avg.c` is the corrected version. The exercise is **debugging**, not writing, so a skeleton
full of `TODO`s would teach the wrong skill.

The README says so explicitly and tells the reader **not to open `solution/` first**. The Makefile
defaults to the skeleton, so `make run` builds the buggy program without the learner having to choose.

> The bug is an off-by-one buffer overrun that `-Wall -Wextra` **cannot** catch, because the compiler
> does not know `count`'s value at the call site. That is deliberate: a bug the compiler finds would
> not motivate a debugger.

---

### DECIDED — Chapter 08 gains a 🐣 path tag the TOC did not give it

The Table of Contents tagged Chapter 08 as 🚶🏃 only, reasonably — it is a hands-on toolchain chapter.

**ADR-008 wins again**, as it did for Chapter 01. The 🐣 activity is *reading* a debugging session
rather than running one, and answering four questions about it — including which information crossed
the network and which did not. That is genuinely valuable for someone who will never drive a debugger
but will read colleagues' bug reports.

TOC tag updated to 🐣🚶🏃.

---

### VERIFIED — What Chapter 08 states and what it predicts

**Carried from earlier verification:** `qcc` is GCC 12.2.0 with six targets (V4.1); `qconn` is running
and started by `slm` (V5.3's boot log); SSH requires `qnxuser` (V5.5, D-009); `/data` is the writable
area (Ch 06 §3.3).

**Predicted, never observed** — and marked as such:

| Prediction | Where |
|------------|-------|
| `target qnx <ip>:8000` is the correct `gdb` incantation | §2.4, §3.4 — **the chapter's central mechanism** |
| `info pidlist` and `attach` work through `qconn` | §3.4, §4.4 |
| `upload` copies over the debug link | §4.4 |
| A symbol mismatch produces confident nonsense rather than an error | 💥 |

Block **V13** closes these. As with Chapter 05, **the chapter's most important claim is currently its
least evidenced** — and the chapter says so where it matters.

---

### 🎉 PARTS 0 AND 1 COMPLETE

Nine chapters, two `⭐ core` labs (L06, L08), three verified setup guides, and a development loop.
**Part 2 begins the microkernel itself**, and from Chapter 09 every chapter has code the learner
builds with `qcc` and debugs with `gdb` — which is why Chapter 08 came last in Part 1 rather than
first.

---

## 2026-08-26 — Session 021 (Chapter 09; Part 2 begins)

### DECIDED — Fault isolation is explained mechanically, not asserted

Chapter 02 made the architectural claim; Chapter 09's job is to make it *mechanical*. Section 3 walks the
page tables, the fault path and `procnto`'s seven-step teardown, and states the point people miss:

> The bad pointer cannot reach your memory because your pages are **not mapped** in the driver's
> address space. Not "protected by convention" — **absent**. There is no address it could compute
> that would reach you.

**Why the detail earns its space.** "A driver crash is survivable" is a slogan until a reader can say
*what stopped it*. The mechanism also explains the limits, which is the more valuable half.

---

### DECIDED — Equal weight to what is NOT survivable

Sections 3.3 and 4.3 are as long as the isolation argument, and deliberately so:

| Not survivable | Why |
|----------------|-----|
| `procnto` faulting | It is the scheduler |
| A driver misusing hardware it legitimately controls | Memory is protected; **the device is not** |
| Interrupts disabled too long | Chapter 01's unbound ① — isolation is irrelevant |
| ⚠️ **Deadlock** | **Nothing faults, so nothing detects it.** Every protection in the chapter is silent on it |

**Deadlock is the one that matters most**, because it is where the chapter's own subject stops
helping. Every other entry in the blast-radius table is about a component failing *loudly*. That is
also the retrospective justification for Chapter 07 having spent a whole chapter on blocking states:
`pidin` is the only thing that finds a failure the kernel cannot.

> A course that only teaches where its subject succeeds produces engineers who are surprised in
> production. The hardware-misuse row is the sharpest case: the driver is **not faulty**, so no
> protection applies.

---

### DECIDED — Section 5's lesson is about `errno`, not about crashing

The obvious ending for a fault-isolation chapter is *"and the system survived"*. Section 5.4 goes one
step further, to the client:

> **The microkernel converts another process's catastrophe into your `errno`.** What you do with it
> is the part it cannot help you with.

**Why that framing.** Isolation alone would leave every client stuck in `REPLY` forever. The step that
makes the design *useful* is `procnto` waking clients with `ESRCH` — and that hands the responsibility
straight back to application code. A client that ignores `MsgSend`'s return value inherits the crash
it was supposedly protected from.

This sets up Chapter 13 (the return values), Chapter 27 (what a good recovery looks like), and the
capstone's error-handling rubric.

---

### DECIDED — "POSIX on top, messages underneath" is Part 2's organising sentence

Section 2.3 states it as the single most important idea in Part 2, and it does three jobs at once:

- explains why the learner's Linux C compiles unchanged;
- explains why writing a QNX driver means writing a **program**, not patching a kernel;
- explains why QNX's kernel-call list has been essentially stable since 1995, while Linux has grown to
  ~400 syscalls — new QNX functionality arrives as **new servers**, not new kernel entry points.

Chapters 13 and 16–17 both depend on the reader having internalised it here.

---

### OPEN — A third block now exists to serve a later chapter

| Block | Serves | Wanted |
|-------|--------|--------|
| **V11.2** | Chapter 21 | `ifs.build`, `disk.layout` — the image recipe |
| **V12.1** | Chapter 25 | A healthy-system `pidin` state census |
| **V14.4** | Chapter 25 | Where `dumper` writes core dumps |

Recorded together so the dependencies are visible when those chapters are written. All three are
cheap for the learner and materially change what the chapter can be.

---

## 2026-08-26 — Session 022 (D-015: the deploy path was wrong)

### VERIFIED — `/data`'s root is owned by root, and the course said otherwise

The learner ran core lab L08 and hit:

```text
scp: dest open "/data/avg": Permission denied
[qnxuser@qnxqemu /data]$ mkdir avg
mkdir: 'avg': Permission denied
```

**The `mkdir` was good diagnosis** — it eliminated SSH, `scp` and the network in a single command,
proving the problem was ordinary filesystem permissions.

**What the course got wrong.** Chapter 06 §3.3 established, correctly, that `/data` is the **writable
partition** — the only place changes survive a reboot. Chapters 06, 07, 08 and 09 then slid from that
into *"deploy to `/data`"*, which does not follow: like any Unix directory, `/data` has an owner and a
mode, and on this image it is owned by `root`.

**The fix.** Deploy to the user's home, `/data/home/qnxuser`, which lives *on* that partition and is
theirs. Both lab Makefiles now default to `DEST ?= /data/home/$(USER)`.

**Corrected:** Chapter 06 → v1.2, Chapter 07 → v1.1, Chapter 08 → v1.1, Chapter 09 → v1.1, both lab
Makefiles, both lab READMEs, the Glossary's *Data partition* entry, and Chapter 08's troubleshooting
table — which now carries the **exact error text**, so the next reader finds it by searching for what
they actually saw.

---

### The lesson, which generalises past QNX

> *"The partition is writable"* and *"you can write there"* are different claims. The course conflated
> them, and four chapters inherited the error from one sentence.

**And the reassuring half:** the surprise here was **not** a QNX exotic. Unix permissions apply
normally; `/data` behaved exactly as any root-owned directory would. The genuinely unusual parts of
this filesystem are only `/proc/boot` (a mounted 20 MB file) and the read-only system partition —
**everything else behaves as a Linux engineer would expect**, including the bit that just stopped the
learner.

Recorded as hazard **H-14**, phrased as a check rather than an observation: before telling a reader to
write somewhere, confirm *the directory* is writable by *the account* they will use — not merely that
the filesystem is.

---

### The fourth published claim caught by running it

| # | Claim | How it was wrong | Found by |
|---|-------|------------------|----------|
| 1 | `-listAvailablePackages` | The option does not exist | Running it (D-007) |
| 2 | Customer demos are forbidden | Exactly backwards | Reading the licensing page (Ch 04) |
| 3 | The disk image is probably sparse | It is not; total ~40 GB low | Running `du` (D-008) |
| **4** | **Deploy to `/data`** | **Root-owned; unwritable by the user** | **Running the lab (D-015)** |

All four were plausible, well-sourced and wrong. **Three of the four were caught by the learner
executing something**, which is the entire argument for ADR-024 and the verification blocks.

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.21 | 2026-08-26 | Session 022 appended: D-015 — `/data`'s root is root-owned; the deploy path corrected across four chapters and both lab Makefiles; the fourth published claim caught by execution. |
| 1.20 | 2026-08-26 | Session 021 appended: fault isolation explained mechanically; equal weight to what is not survivable; section 5's `errno` framing; "POSIX on top, messages underneath" as Part 2's organising sentence; three blocks now serving later chapters. |
| 1.19 | 2026-08-26 | Session 020 appended: the symbols-on-the-host framing and its hazard; the inverted skeleton/solution roles; a 🐣 tag added against the TOC; **Parts 0 and 1 complete**. |
| 1.18 | 2026-08-26 | Session 019 appended: disk figures corrected from `du` measurement across six documents and the check script; D-008 answered; `df`-versus-`du` reconciled; the third instance of a plausible-but-wrong published claim. |
| 1.17 | 2026-08-26 | Session 018 appended: `Startup complete` as the partitioning line; the syspage introduced early; persistence made testable; build files opened fifteen chapters early; V11.2 flagged as the highest-value outstanding request. |
| 1.16 | 2026-08-26 | Session 017 appended: the organising question rather than a directory tour; the silent `gcc` failure; an explicit split between what Chapter 05 verifies and what it predicts; explaining-after-doing as a deliberate pattern. |
| 1.15 | 2026-08-26 | Session 016 appended: a published licensing error corrected (customer demos are permitted); the production/distribution boundary; the two-licence structure; the course as its own worked example; filename alignment and a link check. |
| 1.14 | 2026-08-26 | Session 015 appended: market figures verified; certification as the deciding question; one worked example answering Linux; "argue the wrong side" as the break-it for a judgement chapter; **milestone M1**. |
| 1.13 | 2026-08-26 | Session 014 appended: history verified from primary sources; the microkernel's costs stated honestly; evidence rather than reliability as the real argument; section 4 as documentation-dating; the library-function rule applied during authoring. |
| 1.12 | 2026-08-26 | Session 013 appended: the writing rules did not cover library functions; the fix at rule level; five more instances found by auditing; the substance of D-014. |
| 1.11 | 2026-08-26 | Session 012 appended: Path C served even where the TOC skips it; section 4 as adaptable reference material; the first lab as a measurement; Path A without binaries; the limits of a syntax check. |
| 1.10 | 2026-08-26 | Session 011 appended: Chapter 00 as the template's reference implementation; its two meta-chapter adaptations; labs grounded in the verified VM. |
| 1.9 | 2026-08-26 | Session 010 appended: Phase 1 complete; D-009 corrected (`PermitRootLogin no`); target accounts and the default-credential observation; QNX PID semantics; an evidence note. |
| 1.8 | 2026-08-26 | Session 009 appended: M2 reached; H-9 closed as a failed prediction; the SSH-root refusal; benign boot warnings; pidin as course material. |
| 1.7 | 2026-08-26 | Session 008 appended: the nested `qemu/` trap, the non-existent CLT option, the QSTI image contents, ADR-025, and an open disk-budget revision. |
| 1.6 | 2026-08-26 | Session 007 appended: QSTI/`mkqnximage` distinction, QSTI's default QEMU configuration, Ubuntu 26.04 advantage, predicted WSL2 bridge failure (H-9), and the `qnx-vm.sh` convention. |
| 1.5 | 2026-08-26 | Session 006 appended: SDP verified, 3 guide bugs recorded, R2 closed, T-202 opened, history published. |
| 1.4 | 2026-08-26 | Session 005 appended: licence flow verified, Risk R1 closed, Git identity spelling revised. |
| 1.3 | 2026-08-26 | Session 004 appended: 4 verifications (Setup Guide 01 executed, R9 closed, R3/KVM closed, repo path corrected) and 1 decision (Git identity). |
| 1.2 | 2026-08-26 | Session 003 appended: author handover (Copilot → Claude), 2 verifications, 3 new decisions (ADR-022/023/024), 1 deferral. Setup Guide 01's verification claim corrected. |
| 1.1 | 2026-08-25 | Session 002 appended: 2 verifications, 1 revision (ADR-004), 1 strengthening (ADR-008), 3 new decisions (ADR-019/020/021), plan approved, 1 new risk (R9), 1 deferral (P-06). |
| 1.0 | 2026-08-25 | Log created. Session 001: 2 verifications, 18 decisions, 5 deferrals. |
