---
title: "CLAUDE-MEMORY — The Agent's Complete Working Memory"
document_id: MEM
version: 1.22
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

**Progress: Phase 2. 10/34 chapters — Parts 0 and 1 complete, Part 2 begun. Core labs L06 and L08 published. 3/5 setup guides, all verified.**

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
| Phase | **2 — writing chapters** |
| Plan | ✅ Approved 2026-08-25 |
| Chapters published | **10 / 34** — Parts 0 and 1 complete (00–08) · **Part 2 begun** (09). Core labs **L06** and **L08** published |
| Setup guides published | **3 / 5** — **all three ✅ verified end to end**; zero `[UNVERIFIED]` markers in the course |
| Host preparation | ✅ **Complete** — `19 passed · 6 warnings · 0 failed` |
| QNX licence | ✅ **Requested, accepted and deployed** 2026-08-26 |
| QNX SDP | ✅ **8.0 installed** at `~/qnx800` · cross-compiler **GCC 12.2.0** · cross-compile proven |
| QNX VM booting | ✅ 🎉 **YES** — QNX 8.0.0 boots, `192.168.122.46`. **Milestone M2 reached 2026-08-26.** |
| VM booting | ❌ Not yet |
| Doubts logged | 15 (D-001…D-015, all answered) |
| ADRs | 25 (ADR-001…ADR-025) |
| Git identity | `Karthikeyan Kasivishwanathan <Karthikeyan.KLU@gmail.com>` — note the **`i` after `Kas`**; a misspelling was corrected 2026-08-26. Commits 1–2 remain under `Tyrostir`. |
| Commits | 6 on `main`; the learner pushes manually |
| Blocker | **None.** **Chapter 10 (T-130b) is next.** Blocks V6–V14 with the learner. **V13 remains the most consequential** (core lab L08). Three blocks now exist to serve later chapters: **V11.2** → Ch 21, **V12.1** → Ch 25, **V14.4** → Ch 25. |

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

> 📕 **Chapter 01 shows how a *teaching* chapter is built** (problem → concept → mechanism →
> vocabulary → worked budget → labs), and how §4 and §5 adapt when a chapter has no QNX API yet.
> **Chapter 00 is the reference implementation.** Before writing any chapter, read
> `docs/chapters/Chapter00_HowToUseThisCourse.md` — it demonstrates the template, the callout boxes,
> the path markers, the lab structure and the collapsed-answer mastery check, all in the house voice.
> Match it.

### Writing rules (non-negotiable — from `PLAN.md` §2 and §10)

1. Define every term on first use; add it to `Glossary.md`. **This includes library
   functions** — purpose, arguments, return value, header — or a link to where they are explained.
   Chapter 01's lab shipped with four unexplained functions (D-014); `PLAN.md` §2 and §17 now make
   this checkable.
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
  `~/qnx800/images/qemu` → `./unpack_qemu_image.sh` → ⚠️ **extracts into a nested `qemu/`**, so the
  image directory is **`~/qnx800/images/qemu/qemu`**. `mkqnximage` identifies an image by `local/` +
  `output/` in the CWD; one level up it offers to build a NEW image — **never pass `--force`**
  (D-006). Contents: `ifs.bin` 20 MB · `disk-qemu` 47 GB apparent · `procnto-smp-instr.sym`
  (**instrumented SMP kernel** → Ch 26 tracing) · `output/build/` = the **`mkifs` build files**
  (Ch 21's source material) · `option_files/` = CTI feature switches.
- ⚠️ **QSTI and `mkqnximage` are NOT alternatives** — a natural misreading of ADR-004. QSTI is the
  *image*; **`mkqnximage --run`** is the *launcher* (also `--stop`, `--getip`). Login **root/root**.
  Defaults 8 CPUs / 4 GB (>16 GB may misbehave) / 1280×768; network `bridge,br=virbr0`; display
  `sdl,gl=on`; serial on `mon:stdio` (hence `Ctrl+A` `X`).
- **CTI** = *Custom Target Image* — official build-your-own flow. Used in Ch 21.
- QSTI-for-QEMU is documented for **Ubuntu 22.04 / 24.04**; the execution box runs **26.04** → risk **R9**.
- Non-commercial **allows**: learning, academia, hobby/maker, **writing training material or books
  — even commercially** (this is what makes the public repo legitimate), interoperable OSS.
- Non-commercial **forbids**: **production use** (including internal, unpaid), **distribution**
  (including a single pilot unit), commercial products, activities for a fee.
  ⚠️ **Customer demos ARE permitted** (*"e.g. as part of a product roadmap"*) — this file previously
  said the opposite; corrected 2026-08-26. **The boundary is production + distribution, not money.**
  Hobby/maker *products*, paid training material and customer demos are all permitted. OSS is
  permitted only if *"publicly available at no charge"*. Verified against
  `qnx.software/en/developers/get-started/qnx-everywhere/licensing`.
- Also exists: **QNX Developer Desktop** (self-hosted QNX 8.0 XFCE desktop).
- OSS ports: `github.com/qnx-ports` and `gitlab.com/qnx/ports` · dashboard `oss.qnx.com`.
- ✅ **VERIFIED TARGET (2026-08-26):** `QNX qnxqemu 8.0.0 2026/02/27-11:02:56EST x86pc x86_64`;
  kernel `procnto-smp-instr` (SMP + instrumented → Ch 26 tracing); 31 processes / 207 threads;
  8 CPUs; 4095 MB RAM; net `vtnet0` (virtio) `192.168.122.46/24` via libvirt `virbr0`;
  console `root`/`root`; **SSH `qnxuser`** (root refused, D-009); VNC password `qnxuser`;
  SSH **`qnxuser`/`qnxuser`** (sudo password the same); **`PermitRootLogin no`** blocks root
  entirely; accounts root/sshd/qnxuser(1000, full sudo)/user1–6, homes on the writable `/data`
  partition; **QNX PIDs are large and non-sequential** (IPC endpoints — D-013);
  `apk` package manager on target; **`slm`** = QNX's `systemd`, 22 components on this image;
  `qconn` (remote debug, port 8000) starts automatically.
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
| **021** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 09 published — Part 2 begins** (1004 lines). Enumerates `procnto`'s eight responsibilities and the kernel-call families; establishes **POSIX on top, messages underneath** as Part 2's central idea. §3 explains fault isolation **mechanically** (page tables, fault path, seven-step teardown) and gives **equal weight to what is not survivable** — `procnto` faulting, hardware misuse, and **deadlock, which fails silently**. §5's lesson: the kernel converts another process's catastrophe into your `errno`, after which robustness is your error handling. Ships `labs/lab09_faultisolation/`; Glossary +4; **block V14** added. |
| **020** | 2026-08-26 | Claude (Opus 5) | ⭐ **Chapter 08 published — Parts 0 and 1 COMPLETE (9/34).** Contains **core lab L08** and ships `labs/lab08_devloop/`. Centre of the chapter is **remote debugging through `qconn`** and the split that makes it work: **symbols stay on the host**, only addresses cross the network — with its one hazard (mismatched builds → confident nonsense, no warning) given equal weight and a 💥 exercise. The lab **inverts the usual roles**: `skeleton/` is a complete, compiling, subtly wrong program; `solution/` is the fix, because the exercise is debugging. Glossary +5; **block V13** added — the most consequential since V5. |
| **019** | 2026-08-26 | Claude (Opus 5) | ⚠️ **Disk figures corrected across six documents and `check-environment.sh`** — `~/qnx800` is **79 GB**, not ~43 GB, and the VM image is **not sparse** (D-008 answered). The `df`/`du` discrepancy reconciled rather than replaced. **`bsp/` (1.1 GB) discovered** — Ch 22 material already on disk. 📕 **Chapter 07 published** (992 lines): `pidin` and **blocking states** as the centre, the `REPLY`-chain technique, `/dev` entries as processes, and why QNX's `/proc` is small. Glossary +6 (new **K** section); **block V12** added. |
| **018** | 2026-08-26 | Claude (Opus 5) | ⭐ **Chapter 06 published** (1087 lines) — the first core chapter, containing **lab L06**. Full boot chain with `Startup complete` as the BSP/system boundary; the **syspage** as what makes `procnto` board-independent; `ifs.bin` (20 MB, RAM-mounted, read-only) versus the disk; `slm`'s 22 components read as a dependency argument; §3.3 on what persists (only `/data`). §5 places every line of the verified boot log. Labs open `output/build/` — Chapter 21's source material — early. Glossary +5; **block V11** added, whose **V11.2 (`ifs.build` + `disk.layout`) is the highest-value outstanding request in the course**. |
| **017** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 05 published** (1026 lines). Organised around the host/target split and the test *"which CPU and OS executes this file?"*. `qcc` runs from the host tree and reads the target tree; §4.3 shows the four common build failures are one bug from four angles. Covers `source` vs `./`, QSC's four nouns with **verified** CLT options, `.sym` files, and where ~43 GB goes. §5 traces one `qcc` invocation and names the silent failure — plain `gcc` builds a working binary for the wrong OS. Glossary +8; **block V10** added, whose V10.2 tests the chapter's central mechanism (never yet confirmed). |
| **016** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 04 published** (835 lines) — Part 1 begins. **Found and corrected a licensing error already published in the course**: Setup Guide 02 listed customer demonstrations as forbidden; QNX permits them explicitly. Terms verified verbatim from QNX's licensing page. Thesis: **the boundary is production and distribution, not money** — wrong in both directions. Two-licence structure (development ≠ distribution); GPL contrast; §5 decides four scenarios including this course itself. Filename aligned to the TOC and all cross-chapter links verified. Hazard **H-13**; Glossary +3; **block V9** added. |
| **015** | 2026-08-26 | Claude (Opus 5) | 🎉 **Chapter 03 published — PART 0 COMPLETE (4/34), milestone M1.** Built on the claim that **certification, not latency, usually decides**. Three-question test + eight-step framework; industry-by-industry with the *distinct* reason in each; full competitive comparison; §5 decides three projects and **one answer is Linux**. 💥 exercise asks the reader to argue the wrong side. Figures verified against BlackBerry's 15 Oct 2024 announcement. Glossary +15; **block V8** added. |
| **014** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 02 published** (935 lines). The microkernel bet with its costs stated honestly ("QNX is not a better Linux"); §1.3 argues the real payoff is **evidence, not reliability**. §4 becomes The Product & Version Map with **four signals for spotting stale QNX material**; §5 decodes the learner's own `procnto-smp-instr` and `/proc/boot`. **History verified from primary sources** — QNX's own history page and BlackBerry's SDP 8.0 GA announcement (21 Mar 2024) — rather than from memory. Glossary +10; **block V7** added. |
| **013** | 2026-08-26 | Claude (Opus 5) | 🔧 **D-014 and a rule gap.** The learner found four unexplained library functions in Chapter 01's lab. Fixed at rule level: `PLAN.md` §2 rule 1 now covers library functions, with a §17 checkbox. An audit found five more in Chapter 01. Hazard **H-12**. |
| **012** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 01 published** (1024 lines) + **the course's first compiled lab**, `labs/lab01_timing/` (Makefile calling `qcc` directly per ADR-007, skeleton with 4 TODOs, annotated solution, expected output). Real-time defined without "fast"; hard/firm/soft by consequence; the four latency components and five classic unbounds; Mars Pathfinder as the priority-inversion illustration; §4 adapted into "The Vocabulary" (`R` vs `C`, the ≈69 % rate-monotonic bound); §5 budgets a 1 kHz loop and derives an inversion failure. Glossary +13. **Block V6 added** — it verifies the lab mechanism itself, so whatever breaks there breaks in every later chapter. |
| **011** | 2026-08-26 | Claude (Opus 5) | 📕 **Chapter 00 published** — the first of 34, and the reference implementation of `PLAN.md` §5. Three labs on the verified VM, including a **💥 Break It** that teaches reading an error instead of reaching for `--force`. §4 is a notation reference; §5 explains *why* each chapter element exists. Glossary +10 terms. Style audit clean. **Next: Chapter 01.** |
| **010** | 2026-08-26 | Claude (Opus 5) | ✅ **PHASE 1 COMPLETE.** `hello_qnx` ran on the target (PID 14032920) — the edit → cross-compile → deploy → run loop is closed. Block V5 complete, milestone M2 complete. Setup Guide 03 → **v2.0**; **zero `[UNVERIFIED]` markers remain anywhere in the course**. ✏️ **D-009 corrected:** the image ships `PermitRootLogin no`, not `prohibit-password` — keys do not help root, and §9.5 had wrongly said they would. `/etc/passwd` read into the guide. +D-011, D-012, D-013. **Next: Chapter 00.** |
| **009** | 2026-08-26 | Claude (Opus 5) | 🎉 **MILESTONE M2 — THE VM BOOTS.** QNX 8.0.0 up, 31 processes, `192.168.122.46`. **H-9 closed** — the `virbr0` bridge worked on WSL2 first try, contrary to prediction. **New blocker diagnosed:** `sshd` refuses root *password* auth (`PermitRootLogin prohibit-password`) — use `qnxuser` (**D-009**, hazard **H-11**). Four benign boot warnings explained (**D-010**). Setup Guide 03 → **v1.2**, §§4–9 verified: real boot log, `slm`'s 22 components, `pidin` with live message passing in the `REPLY` column, `ldqnx-64.so.2` found in `/proc/boot`. |
| **008** | 2026-08-26 | Claude (Opus 5) | **First real run of Setup Guide 03; three bugs fixed.** V5.1–V5.2 passed, V5.3 blocked: `unpack_qemu_image.sh` extracts into a **nested `qemu/`**, so `mkqnximage` was run one level too high — fix is `cd qemu`, and **never `--force`** (D-006). `-listAvailablePackages` does not exist; replaced course-wide (D-007). The 47 GB sparse `disk-qemu` documented (D-008). Setup Guide 03 → v1.1, Setup Guide 02 → v2.1, `qnx-vm.sh` path fixed. **ADR-025** adds the `/btw` convention. |
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
| **H-14** | **"The partition is writable" ≠ "you can write there."** The course told readers to deploy to `/data` for four chapters; its root is owned by `root`, so `scp` as `qnxuser` fails. **Unix permissions apply normally on QNX** — the exotic parts are `/proc/boot` and the read-only system partition, and nothing else. Deploy to `/data/home/<user>`. | ✅ Fixed 2026-08-26 (D-015) |
| **H-15** | **A remote-debug connection is not a symbol source.** `qconn` carries control — stop, read registers, read memory — and *never* symbols. `attach <pid>` therefore fails unless `gdb` already has a **host-side** copy of the binary; `info pidlist`'s paths are *target* paths and mean nothing locally. Start `gdb` with the binary, or `set sysroot $QNX_TARGET/x86_64`. Also: **`target qnx <ip>` without `:8000` hangs**, it does not error. | ✅ Fixed 2026-08-26 (D-016) |
| **H-16** | **`$QNX_TARGET` is two trees in one directory.** `$QNX_TARGET/usr/` is architecture-*independent* development files (headers, docs) — it has **no `bin`**. Everything that runs on QNX is under `$QNX_TARGET/x86_64/` or `/aarch64le/`. When writing a path with the architecture in it, **say that the architecture level is required** — in a line that already contains `x86_64` twice it reads as noise and gets dropped. | ✅ Fixed 2026-09-01 (D-017) |
| **H-17** | ⭐ **`$QNX_TARGET/x86_64/` is NOT a complete QNX system.** It holds the *optional, separately-shipped* pieces; the **base userland is `toybox`**, one multi-call binary whose command names are links, so `ls`/`grep`/`sed`/`sleep` are **not files there**. Consequences: (a) to debug a target utility, `scp` it off the running machine; (b) **Chapter 21 must put `toybox` into a `mkifs` image deliberately**, or the image boots with no `ls`. Chapter 05 §2.2 originally called the tree *"a faithful image of a real QNX filesystem"* — corrected. | ✅ Fixed 2026-09-01 (D-017) |
| **H-13** | **Licence facts in this course came from a summary, and one was backwards.** Setup Guide 02 listed customer demonstrations as forbidden; they are explicitly permitted. Any licensing claim must be checked against QNX's licensing page or the EULA — never restated from an earlier course document. | ✅ Fixed 2026-08-26 (Ch 04) |
| **H-12** | **Lab code is easy to under-explain.** Chapter 01's lab called `clock_gettime`, `nanosleep`, `perror` and `qsort` with no explanation of any — a course-rule-#4 violation that the writing rules missed because they spoke only of *terms*, not functions. Before publishing a lab, list every library call in it and confirm each is explained or linked. | ⚠️ Rule added to `PLAN.md` §2 and §17 |
| **H-10** | **`qnxsoftwarecenter_clt` option names must be checked against `-help`, not assumed.** `-listAvailablePackages` was carried in this course from Setup Guide 02 until a real run rejected it. Verified names live in D-007. | ✅ Fixed 2026-08-26 |
| ~~H-9~~ | Predicted that `bridge,br=virbr0` would fail on WSL2 without systemd. **It did not** — the bridge worked first try, `192.168.122.46`. Installing `libvirt-daemon-system` in Setup Guide 01 was sufficient. §12.1 keeps the fallbacks but is downgraded to a contingency. | ✅ Closed 2026-08-26 |
| **H-11** | **SSH to the QNX target must use `qnxuser`/`qnxuser`, never `root`.** The image ships **`PermitRootLogin no`** — root is refused by password *and* key. Applies to `scp` too. Confirmed against `/etc/passwd` and `sshd_config` 2026-08-26. | ✅ Documented (D-009) |
| **H-8** | **T-202 — the SDP build number was never captured.** `PLAN.md` §5 requires every chapter's front matter to record the SDP build it was written against (Risk R5). No chapter can state it today. Ask the learner for `qnxsoftwarecenter_clt -listInstalled` before writing chapters that depend on it. | ⬜ Open |
| **H-6** | Risk **R10** — authoring all three paths in full costs ~20–30 % more effort per chapter. | ✅ Accepted deliberately |
| **H-7** | `CompactContext.md` (Tier 2) must never gain Tier 3 detail, even though it is the "re-prime a session" document. **This file is the Tier 3 equivalent.** | ⚠️ Ongoing discipline |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.22 | 2026-09-01 | Session 025 cont.: D-017's second half — the SDP does not ship the base userland; H-17; Ch 05 → v1.1, Ch 08 → v1.4. |
| 1.21 | 2026-09-01 | Session 025: D-017 — the architecture level in `$QNX_TARGET`; H-16. Ch 10 published (Session 024). |
| 1.20 | 2026-08-26 | Session 022 cont.: D-016 — `attach` needs host-side symbols; H-15. **First direct verification of Chapter 08's `qconn` connection.** |
| 1.19 | 2026-08-26 | Session 022: D-015 — deploy path corrected across four chapters and both lab Makefiles; H-14. |
| 1.18 | 2026-08-26 | Session 021: Chapter 09; Part 2 begins; block V14. |
| 1.17 | 2026-08-26 | Session 020: **Parts 0 and 1 complete**; core lab L08; block V13. |
| 1.16 | 2026-08-26 | Session 019: disk figures corrected; Chapter 07; block V12. |
| 1.15 | 2026-08-26 | Session 018: Chapter 06 (core lab L06); block V11. |
| 1.14 | 2026-08-26 | Session 017: Chapter 05; block V10. |
| 1.13 | 2026-08-26 | Session 016: Chapter 04; licence facts corrected; H-13. |
| 1.12 | 2026-08-26 | Session 015: Part 0 complete; Part 1 next. |
| 1.11 | 2026-08-26 | Session 014: Chapter 02 published; history verified from primary sources. |
| 1.10 | 2026-08-26 | Session 013: D-014 closed a rule-#4 gap; H-12 added; the writing rules now cover library functions. |
| 1.9 | 2026-08-26 | Session 012: Chapter 01 + the first lab; block V6 opened. |
| 1.8 | 2026-08-26 | Session 011: Chapter 00 published; it is now the reference implementation for the chapter template. |
| 1.7 | 2026-08-26 | Session 010: **Phase 1 complete.** Loop closed; D-009 corrected; H-11 resolved; doubts to D-013. |
| 1.6 | 2026-08-26 | Session 009: **M2 reached.** Verified target facts recorded; H-9 closed, H-11 opened; doubts to D-010. |
| 1.5 | 2026-08-26 | Session 008: nested `qemu/qemu` trap, ADR-025, H-10, doubts to D-008. |
| 1.4 | 2026-08-26 | Session 007: Setup Guide 03 published; QSTI/`mkqnximage` distinction recorded; H-9 added. |
| 1.3 | 2026-08-26 | Session 006: SDP verified, both setup guides done, H-3 closed, H-8 added (SDP build number), Chapter 00 off hold. |
| 1.2 | 2026-08-26 | Session 005: licence deployed, Block V2 complete, R1 closed, hazards H-3/H-5 updated, Git identity spelling fixed. |
| 1.1 | 2026-08-26 | Session 004: Block V1 verified; host state, hazards H-3/H-4/H-5 and the session table updated. |
| 1.0 | 2026-08-26 | Created in Session 003 at the Copilot → Claude handover. Captures the two-machine split, standing instructions SI-1…SI-8, ADR-022/023/024, and the full project history. |
