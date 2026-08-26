---
title: "CLAUDE-MEMORY — The Agent's Complete Working Memory"
document_id: MEM
version: 1.4
status: Active (living document — regenerate at the end of every session)
created: 2026-08-26
last_updated: 2026-08-26
audience: "AI author agents only (Tier 3 — internal)"
update_trigger: "End of every session, and immediately after any decision or learner instruction"
---

# 🧠 CLAUDE-MEMORY.md

> ⛔ **Tier 3 — internal.** Not part of the course. Never quoted, linked, or paraphrased in
> `README.md`, `docs/PLAN.md`, `docs/chapters/`, `docs/guides/`, `docs/reference/`, or `docs/meta/`.
>
> **What this is.** A language model starts every session with no memory. This file is the memory.
> It is written so that reading *only this file* makes an agent immediately competent to continue
> the project — who the learner is, what is being built, what has been decided, what the rules are,
> and what must never be said.
>
> **Rule:** keep it dense and current. Update it; do not append to it indefinitely.

---

## Contents

1. [The 60-second version](#1-the-60-second-version)
2. [The two-machine split](#2--the-two-machine-split-tier-3-only)
3. [Who the learner is](#3-who-the-learner-is)
4. [What is being built](#4-what-is-being-built)
5. [Where the project stands](#5-where-the-project-stands)
6. [Standing instructions from the learner](#6-standing-instructions-from-the-learner)
7. [Operating rules for the agent](#7-operating-rules-for-the-agent)
8. [QNX facts worth remembering](#8-qnx-facts-worth-remembering-verified-2026-08-25)
9. [Decisions in force](#9-decisions-in-force)
10. [Project history — how we got here](#10-project-history--how-we-got-here)
11. [Known hazards and open loops](#11-known-hazards-and-open-loops)

---

## 1. The 60-second version

You are the **author** of a book-length QNX course. The **learner** owns the repo and does all the
hands-on work. You write Markdown; you do not run software. The course is
**6 parts, 34 chapters, ~21 labs, 1 capstone**, published as Markdown *and* PDF, teaching QNX SDP 8.0
on a QEMU/KVM virtual machine at zero cost.

**Progress: Phase 1. 0/34 chapters. 2/5 setup guides. Plan approved.**

**Cadence: one chapter per turn**, committed and pushed, with `docs/meta/` updated each time.

---

## 2. 🔒 The two-machine split (Tier 3 only)

This is the single most important internal fact, and the single most important thing to keep out of
the course.

```text
┌────────────────────────────────────────┐            ┌────────────────────────────────────────┐
│ 📱 AUTHORING BOX — "the writing desk"  │    git     │ 💻 EXECUTION BOX — "the machine"       │
│                                        │  ◄──────►  │                                        │
│ Ubuntu under Termux on Android         │            │ Ubuntu 26.04 LTS on WSL2 / Windows     │
│ aarch64 · ~7 GB RAM · ~18 GB free      │            │ Intel i7-11850H · 23 GB · 952 GB free  │
│ /root/claude/qnx-zero-to-hero          │            │ /home/tyrostir/exercises/             │
│                                        │            │        qnx-zero-to-hero                │
│ ✍️  Markdown + Git ONLY                │            │ ⚙️  QNX SDP · QEMU/KVM · labs · PDF    │
│ ❌ No builds, no VMs, no installs      │            │ ✅ Everything real happens here        │
│ ❌ No long-running commands            │            │ ✅ Operated BY HAND by the learner     │
└────────────────────────────────────────┘            └────────────────────────────────────────┘
                    ▲                                                    ▲
                    │                                                    │
              the AI agent                                          the learner
              works only here                                       works only here
```

### Why the split is permanent, not a workaround

QNX SDP 8.0 supports **x86-64 Windows or Linux hosts only** — **no ARM hosts, no macOS**. The
authoring box is `aarch64`. It could not run QNX with infinite RAM. The split is therefore forced by
the product, not by convenience.

### What this means for you, the agent

| You may | You must never |
|---------|----------------|
| Read, grep, and edit files | Run QEMU, install SDP, `apt install`, build PDFs, or clone large repos |
| Run `git` (status/add/commit/log/diff) | Run anything long-running or memory-hungry |
| Run tiny inspection commands | Claim you *verified* a command by running it |
| Write install steps for the learner to perform | Assume you can execute the steps yourself |

### 🚨 What the end reader must believe

> From the reader's point of view **there is exactly one machine**: an Ubuntu 26.04 / WSL2 laptop.
> The authoring box **does not exist** in any Tier 1 or Tier 2 document.

This is not deception — it is scope. The reader is learning QNX, not the logistics of how the book
was typed. Mentioning a phone would confuse a course whose whole premise is "here is your one
development host". Recorded as **ADR-022**.

**Vocabulary to use in the course:** "your host machine", "your laptop", "your Ubuntu 26.04 / WSL2
system". **Never:** "the authoring machine", "the phone", "Termux", "Android", "aarch64 box",
"the writing desk".

---

## 3. Who the learner is

| | |
|---|---|
| **Name / handle** | Tyrostir |
| **GitHub** | `github.com/tyrostir` · repo `qnx-zero-to-hero` |
| **Role** | Starting-level **embedded engineer** |
| **Strong in** | **C / C++** (comfortable), **Python** (strong) |
| **Assumed zero** | OS internals, RTOS concepts, QNX. Teach from first principles. |
| **Chosen path** | 🚶 **Path B — Self-Learner** (full course: all theory + all labs) |
| **Working style** | Wants *everything* explained, every step spelled out, nothing assumed, everything documented, every question logged permanently. |
| **Time budget** | Not yet stated (T-007). Assume ~5 h/week. |

### How the learner likes to be treated

- **Literal, copy-pasteable commands** with expected output. Never "install the usual dependencies".
- **Why before how.** Explain the problem a mechanism solves before naming the API.
- **Nothing is a black box.** Every flag, every magic number gets explained.
- **Ask before assuming** when a choice would change the deliverable materially — but make routine
  judgement calls without asking.
- **Report honestly.** If something is unverified, say `[UNVERIFIED]`. Never fake a result.

---

## 4. What is being built

**QNX: Zero to Hero** — a course written as *a book you can execute*.

| Dimension | Value |
|---|---|
| Structure | **6 parts · 34 chapters · ~21 labs · 1 capstone** |
| Paths | 🐣 A Absolute Beginner (no coding) · 🚶 B Self-Learner · 🏃 C Fast-Track Pro — **markers inside one file**, and **all three authored in full** |
| Target | QNX SDP 8.0 / QNX OS 8.0, `x86_64` |
| Lab platform | **QEMU + KVM**, image via **QSTI → CTI → raw `mkifs`** |
| Cost to learner | **₹0** — QNX Everywhere free non-commercial licence |
| Output | Markdown on GitHub + Pandoc/XeLaTeX PDF (per chapter + one bound book) |
| Licence | Content **CC BY-SA 4.0**, lab code **MIT** |

### Course shape

```text
Part 0  Ch 00–03  Orientation: real-time, what QNX is, why/where used     [no software needed]
Part 1  Ch 04–08  Environment: licence, SDP, QEMU VM, shell, toolchain    ⭐06 ⭐08
Part 2  Ch 09–15  Microkernel: procnto, threads, scheduling, sync,
                  MESSAGE PASSING, memory                                 ⭐13 ⭐14
Part 3  Ch 16–20  Resource managers: pathname space, first resmgr,
                  deep dive, interrupts, drivers                          ⭐17
Part 4  Ch 21–24  System building: boot/IFS/mkifs, BSPs, networking, PPS  ⭐21
Part 5  Ch 25–30  Production: debug, tracing, adaptive partitioning,
                  security, functional safety, hypervisor                 ⭐25
Part 6  Ch 31–34  Real hardware, custom board bring-up, CAPSTONE, career
```

**Critical path:** Ch 05 → 06 → 08 → 13 → 17 → 21.
**Centre of gravity:** message passing (Ch 13/14). Resource managers are message passing wearing a
filesystem costume.

---

## 5. Where the project stands

| | |
|---|---|
| Phase | **1 — Environment setup** |
| Plan | ✅ Approved 2026-08-25 |
| Chapters published | **0 / 34** |
| Setup guides published | **3 / 5** — 01, 02 ✅ verified · **03 published**, `[UNVERIFIED]` pending block V5 |
| Host preparation | ✅ **Complete** — `19 passed · 6 warnings · 0 failed` |
| QNX licence | ✅ **Requested, accepted and deployed** 2026-08-26 |
| QNX SDP | ✅ **8.0 installed** at `~/qnx800` · cross-compiler **GCC 12.2.0** · cross-compile proven |
| QNX VM booting | ❌ Not yet — Setup Guide 03 is written; the learner runs block V5 next |
| VM booting | ❌ Not yet |
| Doubts logged | 5 (D-001…D-005, all answered) |
| ADRs | 24 (ADR-001…ADR-024) |
| Git identity | `Karthikeyan Kasivishwanathan <Karthikeyan.KLU@gmail.com>` — note the **`i` after `Kas`**; a misspelling was corrected 2026-08-26. Commits 1–2 remain under `Tyrostir`. |
| Commits | 6 on `main`; the learner pushes manually |
| Blocker | **None.** SI-8's condition is satisfied — onboarding and verification are both complete, so **Chapter 00 is off hold**. Awaiting the learner's choice between Chapter 00 and Setup Guide 03. |

**Always confirm against [`docs/meta/CourseState.md`](../meta/CourseState.md) — it is authoritative.**

---

## 6. Standing instructions from the learner

Permanent, not one-off. Sourced from [`PROMPTS.md`](../../PROMPTS.md).

| # | Instruction | From |
|---|-------------|------|
| **SI-1** | Authoring happens on the writing-desk box; **execution happens on the learner's laptop**. | PROMPT#1 |
| **SI-2** | **No long-running or heavy commands** in the authoring environment. Ever. | PROMPT#1 |
| **SI-3** | **Guide the learner step by step, manually.** Never assume you can perform the step. | PROMPT#1 |
| **SI-4** | Log **every learner prompt verbatim** in `PROMPTS.md`. | PROMPT#1 |
| **SI-5** | Log **every agent response in full** in `PROMPTS.md`, immediately below its prompt. | PROMPT#2 |
| **SI-6** | The **end reader must never learn about the two-machine split.** One laptop exists, and that is all. | PROMPT#2 |
| **SI-7** | The GitHub PAT in `.git/config` is **deliberately left in place**. Do not rotate it, do not scrub it, do not raise it again unprompted. Deferred by the learner. | PROMPT#2 |
| **SI-8** | **Do not begin Chapter 00** until onboarding documents and `[UNVERIFIED]` clearance are complete. | PROMPT#2 |

---

## 7. Operating rules for the agent

### Every turn

1. **Log the prompt** verbatim in `PROMPTS.md` as `PROMPT#N` (ADR-023).
2. Do the work.
3. **Log your full response** in `PROMPTS.md` under that prompt (ADR-023).
4. If the learner asked a technical question → also add a `D-NNN` entry to
   [`docs/meta/Doubts.md`](../meta/Doubts.md) with a short answer **and** a full answer (ADR-014).
5. If a decision was made → add `ADR-NNN` to [`Decisions.md`](../meta/Decisions.md) **and**
   [`DecisionsLog.md`](../meta/DecisionsLog.md).
6. Update [`CourseState.md`](../meta/CourseState.md), [`ToDos.md`](../meta/ToDos.md), and this file.
7. Commit. Push only when the learner has said to.

### Writing rules (non-negotiable — from `PLAN.md` §2 and §10)

1. Define every term on first use; add it to `Glossary.md`.
2. **Why → How → API → Lab → Break it → Mastery check.**
3. Every QNX concept gets a **🐧 "In Linux this would be…"** box.
4. No black boxes — explain every flag and every magic number.
5. Every install step is **literal and copy-pasteable**, with expected output shown separately.
6. Shell prompts: **`host$`** = the learner's Ubuntu/WSL2 laptop · **`qnx#`** = the QNX target.
   **Never a bare `#`** (ambiguous with comments).
7. The `PLAN.md` §5 chapter template is mandatory, including the `🏃 Fast-Track Summary`.
8. **No GitHub-only Markdown** — it breaks Pandoc. No `> [!NOTE]`, no raw HTML except
   `<details>`/`<summary>`, relative links only (ADR-015).
9. Emoji are **semantic only**, per the callout table in `PLAN.md` §5.1.
10. Every document ends with a **Changelog** table.

### Honesty rules

- Anything not actually executed on the execution box is marked **`[UNVERIFIED]`**.
- You cannot clear an `[UNVERIFIED]` marker yourself. Only the learner's pasted output clears it.
  See [`VerificationRuns.md`](VerificationRuns.md).
- If a lab's expected output has not been observed on a real VM, say so.

---

## 8. QNX facts worth remembering (verified 2026-08-25)

Much of what is online about QNX is stale. These were checked against live QNX sources.

- BlackBerry QNX **rebranded**: `blackberry.qnx.com` → **`qnx.software`**.
- Current product: **QNX SDP 8.0 / QNX OS 8.0**. **SDP 7.1 is NOT in the free programme.**
- Free tier: **QNX Everywhere**, free **non-commercial**. Entry point **`qnx.com/getqnx`**.
- ⚠️ **The licence flow has THREE verbs: request → accept → DEPLOY.** Deploy happens in the myQNX
  License Manager. **Skipping deploy = "no products available" in QNX Software Center** — the #1
  setup failure, and the error never explains why.
- Install chain: myQNX account + **deployed** licence → **QNX Software Center (QSC)** →
  **SDP 8.0** (`~/qnx800`) → IDE.
- ⚠️ Host support: **x86-64 Windows or Linux only. No macOS. No ARM hosts.**
- **QSTI** = *Quick Start Target Image* — official **pre-built** images for **QEMU** and RPi 4/5.
  This is how the course boots QNX (ADR-004). QSC package **`com.qnx.qnx800.quickstart.qemu`** →
  `~/qnx800/images/qemu` → `./unpack_qemu_image.sh` → `output/{ifs.bin, disk-qemu.vmdk}`.
- ⚠️ **QSTI and `mkqnximage` are NOT alternatives** — a natural misreading of ADR-004. QSTI is the
  *image*; **`mkqnximage --run`** is the *launcher* (also `--stop`, `--getip`). Login **root/root**.
  Defaults 8 CPUs / 4 GB (>16 GB may misbehave) / 1280×768; network `bridge,br=virbr0`; display
  `sdl,gl=on`; serial on `mon:stdio` (hence `Ctrl+A` `X`).
- **CTI** = *Custom Target Image* — official build-your-own flow. Used in Ch 21.
- QSTI-for-QEMU is documented for **Ubuntu 22.04 / 24.04**; the execution box runs **26.04** → risk **R9**.
- Non-commercial **allows**: learning, academia, hobby/maker, **writing training material or books
  — even commercially** (this is what makes the public repo legitimate), interoperable OSS.
- Non-commercial **forbids**: production use, distribution, commercial products, customer demos.
- Also exists: **QNX Developer Desktop** (self-hosted QNX 8.0 XFCE desktop).
- OSS ports: `github.com/qnx-ports` and `gitlab.com/qnx/ports` · dashboard `oss.qnx.com`.
- Docs: `qnx.com/developers/docs/8.0/` and `qnx.com/developers/docs/qnxeverywhere/`.
- Also available as source material: **QNX Porting Guide (Linux→QNX)**, **DDK Developer's Guide**,
  **Hardware Interfacing Guide** → feed Ch 19, 20, 22.
- Community: **Discord `nF3UE97RND`** · **r/qnx** · Stack Overflow `qnx` tag.
- `$QNX_HOST` = Linux-side tools (`qcc`, `mkifs`); `$QNX_TARGET` = QNX-side headers/libs.
  Activated by `source ~/qnx800/qnxsdp-env.sh`.

---

## 9. Decisions in force

Full text: [`Decisions.md`](../meta/Decisions.md) · rationale and history:
[`DecisionsLog.md`](../meta/DecisionsLog.md).

| ID | Decision |
|----|----------|
| ADR-001 | QNX **SDP 8.0** only (7.1 as ⚠️ delta boxes) |
| ADR-002 | **QNX Everywhere** free non-commercial licence |
| ADR-003 | Labs run on **QEMU + KVM** — no hardware needed for Ch 00–30 |
| ADR-004 | VM image: **QSTI (pre-built) → CTI → raw `mkifs`** |
| ADR-005 | Default target arch **`x86_64`**; `aarch64le` in the hardware track |
| ADR-006 | **VS Code + QNX Toolkit** primary IDE; Momentics documented; labs must work from a bare terminal |
| ADR-007 | Teach raw **`qcc`** first → simple Makefile → QNX recursive Makefiles → CMake appendix |
| ADR-008 | 3 paths = markers in **one file**, and **all three authored in full** |
| ADR-009 | **Message passing (Ch 13/14) is the centre of the course** |
| ADR-010 | **Mermaid** diagrams, each with a one-line text description |
| ADR-011 | PDF via **Pandoc + XeLaTeX + Eisvogel** |
| ADR-012 | `TableOfContents.md` canonical; `TableOfContext.md` = alias |
| ADR-013 | Hardware = **separate track** |
| ADR-014 | Every question → permanent **`D-NNN`** entry in `Doubts.md` |
| ADR-015 | **No GitHub-only Markdown** (it breaks PDF export) |
| ADR-016 | **One chapter = one commit**, pushed |
| ADR-017 | Content **CC BY-SA 4.0**, lab code **MIT** |
| ADR-018 | Learner's path **🚶 B** |
| ADR-019 | Capstone in **three flavours**: 🤖 robotics · 🚗 automotive · 🏥 medical/industrial |
| ADR-020 | **One chapter per turn**, auto-commit + push |
| ADR-021 | Licence entry point `qnx.com/getqnx`; teach request → accept → **deploy** |
| **ADR-022** | **Three document tiers; the two-machine split is Tier 3 / internal only** |
| **ADR-023** | **`PROMPTS.md` logs every prompt *and* every full agent response** |
| **ADR-024** | **The agent cannot verify anything; `[UNVERIFIED]` is cleared only by learner-pasted output** |

---

## 10. Project history — how we got here

| Session | Date | Agent | What happened |
|---------|------|-------|---------------|
| **001** | 2026-08-25 | GitHub Copilot | Repo created. Host verified. QNX product/licensing state researched post-rebrand. `README`, `PLAN`, `TableOfContents`, all six `docs/meta/` documents, all `docs/reference/` documents, folder structure, `.gitignore`, `LICENSE`, `check-environment.sh`, `build-pdf.sh` written. ADR-001…014. Commit `4755aaa`. |
| **002** | 2026-08-25 | GitHub Copilot | `check-environment.sh` run on the execution box → found `/dev/kvm` present but **not writable** (T-008). Discovered **QSTI/CTI**, the Porting Guide and the DDK Guide → ADR-004 revised. **Plan approved** with two learner amendments (all three paths authored in full; three capstone flavours). ADR-019/020/021 added. **Setup Guides 01 and 02 published.** Commit `79029c2`. |
| **007** | 2026-08-26 | Claude (Opus 5) | **Setup Guide 03 published** (729 lines) from QNX's official QSTI-for-QEMU docs, read live. Key finding: **QSTI and `mkqnximage` are not alternatives** — QSTI is the image, `mkqnximage --run` is the launcher. Documented the underlying QEMU flags, first-contact commands, SSH, and running the Setup Guide 02 binary on the target. Predicted three WSL2 failure modes (chiefly the `virbr0` bridge → H-9). Wrote `tools/qemu/qnx-vm.sh`. Added verification block **V5** (7 checkpoints); V5.1 also closes T-202. |
| **006** | 2026-08-26 | Claude (Opus 5) | **Blocks V3 + V4 complete — all verification done.** QNX SDP 8.0 installed at `~/qnx800`; cross-compile proven (`ldqnx-64.so.2` interpreter; Linux refuses to run the binary); `24 passed · 3 warnings · 0 failed`. Setup Guide 02 → **v2.0**, all markers cleared. **Three real bugs found by running the guide**: missing `#include <unistd.h>`, a false claim that `file` prints "QNX", and a disk estimate ~4× low (~43 GB actual). `PLAN.md` disk budget corrected to ~50 GB. **Risk R2 closed.** T-202 (SDP build number) still open. Learner pushed to GitHub manually. |
| **005** | 2026-08-26 | Claude (Opus 5) | **Block V2 complete.** Learner confirmed the QNX Everywhere licence is requested, accepted and **deployed**. T-003 and T-010 cleared; **Risk R1 closed** — no external blocker remains anywhere in the project. Setup Guide 02 → v1.1, `[UNVERIFIED]` cleared from §§3–5 and scoped to Part B. Block V3 (QSC + SDP install) promoted to the next action. Git author name spelling corrected. |
| **004** | 2026-08-26 | Claude (Opus 5) | **Block V1 verified.** Learner ran Setup Guide 01 on the host and reported output: `19 passed · 6 warnings · 0 failed` (was 13/9/3). T-008 and T-009 cleared; Risk R9 closed (no package-name drift on 26.04); Risk R3 closed. Setup Guide 01 → **v2.0**, all `[UNVERIFIED]` removed and every expected-output block replaced with real observed output. Repo path corrected to `~/exercises/qnx-zero-to-hero`. Git identity updated. |
| **003** | 2026-08-26 | **Claude (Opus 5)** | **Handover.** Copilot credit limit reached; project moved to the writing-desk box. Full context absorbed and reported. `PROMPTS.md` created. `docs/internal/` tier established with this file, the onboarding guide, the onboarding prompts, and the verification protocol. ADR-022/023/024 added. Chapter 00 held. |

### Why the agent changed

The learner exhausted GitHub Copilot's credit allowance on the office laptop. The project source was
moved to the writing-desk box, and Claude took over as author. **Expect this to happen again** —
that is precisely why the onboarding documents exist.

---

## 11. Known hazards and open loops

| # | Hazard | Status |
|---|--------|--------|
| **H-1** | The Git remote in `.git/config` embeds a **plaintext GitHub PAT**. Not in any tracked file. | ⏸️ **Deliberately deferred by the learner (SI-7). Do not raise again.** |
| **H-2** | Two working copies exist. Divergence is possible if the learner edits on the execution box. | ⚠️ Always `git status` / `git log --oneline -3` before writing. Pull before editing if the learner has been working. |
| ~~H-3~~ | Setup Guides 01 and 02 are both verified end to end. Three real bugs were found in Setup Guide 02 by running it. | ✅ Closed 2026-08-26 |
| ~~H-4~~ | Risk **R9** — tested at Setup 01. **Did not materialise**: every documented package installed under its documented name on Ubuntu 26.04. | ✅ Closed 2026-08-25 |
| ~~H-5~~ | Risk **R1** — licence approval latency. **Licence deployed 2026-08-26.** Latency itself was never captured, so Chapter 04 still cannot tell a reader what to expect (T-014, non-blocking). | ✅ Closed |
| **H-9** | **Setup Guide 03's default networking may not work on WSL2.** It uses `bridge,br=virbr0`, which libvirt creates as a systemd service — and WSL2 does not enable systemd by default. Documented in §12.1 with three fallbacks, but **unverified**. If the learner reports no IP, this is the first place to look. | ⚠️ Predicted |
| **H-8** | **T-202 — the SDP build number was never captured.** `PLAN.md` §5 requires every chapter's front matter to record the SDP build it was written against (Risk R5). No chapter can state it today. Ask the learner for `qnxsoftwarecenter_clt -listAvailablePackages` before writing chapters that depend on it. | ⬜ Open |
| **H-6** | Risk **R10** — authoring all three paths in full costs ~20–30 % more effort per chapter. | ✅ Accepted deliberately |
| **H-7** | `CompactContext.md` (Tier 2) must never gain Tier 3 detail, even though it is the "re-prime a session" document. **This file is the Tier 3 equivalent.** | ⚠️ Ongoing discipline |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.4 | 2026-08-26 | Session 007: Setup Guide 03 published; QSTI/`mkqnximage` distinction recorded; H-9 added. |
| 1.3 | 2026-08-26 | Session 006: SDP verified, both setup guides done, H-3 closed, H-8 added (SDP build number), Chapter 00 off hold. |
| 1.2 | 2026-08-26 | Session 005: licence deployed, Block V2 complete, R1 closed, hazards H-3/H-5 updated, Git identity spelling fixed. |
| 1.1 | 2026-08-26 | Session 004: Block V1 verified; host state, hazards H-3/H-4/H-5 and the session table updated. |
| 1.0 | 2026-08-26 | Created in Session 003 at the Copilot → Claude handover. Captures the two-machine split, standing instructions SI-1…SI-8, ADR-022/023/024, and the full project history. |
