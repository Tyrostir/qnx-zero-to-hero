---
title: "Decisions Log — Append-Only History"
document_id: DECLOG
version: 1.10
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

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
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
