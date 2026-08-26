---
title: "Compact Context — One-Page Session Reload"
document_id: CTX
version: 1.2
status: Active (regenerated every session)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "End of every session — regenerate from CourseState + Decisions"
---

# 🗜️ CompactContext.md

> **Purpose.** A single, dense page that restores *complete* working context in one read —
> for you after a break, or for a fresh AI session with no history.
> **Rule:** must stay under ~150 lines. If it grows, compress; don't append.

---

## WHO

- **Learner:** Tyrostir. Starting-level **embedded engineer**. **C/C++ solid**, **Python strong**.
  **No OS-internals or RTOS background** — teach from first principles.
- **Learner's path:** 🚶 **Path B** (full course: theory + all labs). **But 🐣 A and 🏃 C content must be
  written in full in every chapter** — explicit learner requirement (ADR-008), so future readers can
  enter by any path.
- **Wants:** everything explained from scratch, every step spelled out, nothing assumed, everything
  documented, every question logged with its answer.
- **Cadence:** **one chapter per turn**, auto-committed and **pushed** (ADR-020).

## WHAT

- **Course:** *QNX Zero to Hero* — 6 parts, 34 chapters, ~21 labs, 1 capstone.
- **Repo:** `https://github.com/Tyrostir/qnx-zero-to-hero`
- **Local path:** `~/exercises/qnx-zero-to-hero`
- **Deliverable:** a Markdown book + runnable labs, exportable to PDF.

## WHERE WE ARE

| | |
|---|---|
| Phase | **1 — Environment setup** |
| Plan | ✅ **Approved** 2026-08-25 |
| Chapters published | **0 / 34** |
| Setup guides published | **3 / 5** — 01, 02 ✅ · 03 §§4–9 ✅, §§10–11 pending |
| Host ready | ✅ **Setup 01 complete** — 19 pass / 6 warn / **0 fail** |
| QNX licence | ✅ **deployed** 2026-08-26 |
| QNX installed | ✅ **SDP 8.0 at `~/qnx800`** · cross-compile proven |
| VM booting | ✅ 🎉 **QNX 8.0.0 boots** — M2 reached 2026-08-26 |
| Blocker | **None.** Setup Guide 03 awaits its first real run |
| Next (me) | Clear Setup 03 §§10–11 from the V5.6–V5.7 output, then **Chapter 00** |
| Next (learner) | **V5.6:** `ssh qnxuser@192.168.122.46` (NOT root), `scp` + run `hello_qnx` |
| On hold | ⏸️ **Chapter 00**, by learner instruction, until the markers are cleared |

## HOST ENVIRONMENT (verified 2026-08-25)

```text
Ubuntu 26.04 LTS on WSL2 · kernel 6.18.33.2-microsoft-standard-WSL2
Intel i7-11850H · 16 logical CPUs · VT-x · /dev/kvm PRESENT AND ACCESSIBLE ✅
23 GiB RAM · 908 GB disk free  (SDP cost ~43 GB; budget ~50 GB)
Repo: ~/exercises/qnx-zero-to-hero
installed ✅: gcc 15.2.0 · make 4.4.1 · git 2.53.0 · curl 8.18.0 · tar 1.35
              ssh 10.2p1 · openjdk 25.0.4 · qemu 10.2.1 · qemu-img 10.2.1
licence ✅ deployed  ·  QNX SDP 8.0 ✅ ~/qnx800 (~43 GB)
  $QNX_HOST=~/qnx800/host/linux/x86_64  ·  $QNX_TARGET=~/qnx800/target/qnx
  cross-compiler GCC 12.2.0 · targets gcc_ntox86_64 (default) + gcc_ntoaarch64le (+_gpp/_cxx)
  dynamic linker /usr/lib/ldqnx-64.so.2  ·  licence ~/.qnx/license/licenses
NOT installed: VS Code QNX Toolkit, pandoc/TeX
Check any time: ./tools/check-environment.sh   (last: 24 pass / 3 warn / 0 FAIL ✅)
```

## KEY QNX FACTS (verified 2026-08-25 — much online info is stale)

- BlackBerry QNX rebranded: **`blackberry.qnx.com` → `qnx.software`**.
- Current product: **QNX SDP 8.0 / QNX OS 8.0**.
- Free tier: **QNX Everywhere**, free **non-commercial**. Canonical URL: **`qnx.com/getqnx`**.
- ⚠️ Licence flow has **THREE verbs: request → accept → DEPLOY**. Deploy happens in the myQNX License
  Manager (`qnx.com/account/dashboard`). **Skipping deploy = "no products available" in QSC** — the #1
  setup failure.
- Install chain: myQNX account + deployed licence → **QNX Software Center (QSC)** → **SDP 8.0**
  (`~/qnx800`) → IDE.
- ⚠️ Host support: x86-64 **Windows or Linux only**. **No macOS. No ARM hosts.**
- **QSTI** = *Quick Start Target Image* — official **pre-built** images for **QEMU** and **RPi 4/5**.
  **This is how we boot QNX (ADR-004).** QSC package **`com.qnx.qnx800.quickstart.qemu`** →
  `~/qnx800/images/qemu` → `./unpack_qemu_image.sh` → ⚠️ extracts into a **nested `qemu/`**, so the
  image directory is **`~/qnx800/images/qemu/qemu`** (twice). `mkqnximage` needs `local/` + `output/`
  in the CWD; run it one level up and it offers to build a NEW image — **never pass `--force`**.
- ✅ **VERIFIED TARGET:** `QNX qnxqemu 8.0.0 2026/02/27-11:02:56EST x86pc x86_64` · 31 procs /
  207 threads / 8 CPUs / 4 GB · net `vtnet0` `192.168.122.46` (virbr0 bridge **works** on WSL2) ·
  console `root`/`root` · **SSH must use `qnxuser`** — `sshd` refuses root password auth (D-009) ·
  VNC default password `qnxuser` · `apk` package manager on target · `slm` = QNX's `systemd`.
- ⚠️ **QSTI and `mkqnximage` are not alternatives.** QSTI supplies the image; **`mkqnximage --run`**
  launches it. Also `--stop`, `--getip`. Login **root/root**. Defaults: 8 CPUs, 4 GB (>16 GB may
  misbehave), 1280×768. Network defaults to a **`virbr0` bridge** — needs libvirt, hence systemd,
  which WSL2 does not enable by default. Display defaults to `sdl,gl=on`.
- **CTI** = *Custom Target Image* — official **build-your-own** flow (RPi + QEMU). Used in Ch 21.
- QSTI-for-QEMU is documented for **Ubuntu 22.04/24.04**; our host is **26.04**. Risk **R9** tested
  at Setup 01 and **did not materialise** — every documented package name still exists on 26.04.
- Non-commercial **allows**: learning, academia, hobby/maker, **writing training material or books
  (even commercially)**, interoperable OSS.
- Non-commercial **forbids**: production use, distribution, commercial products, customer demos.
- **SDP 7.1 is NOT in the free programme.**
- New: **QNX Developer Desktop** (self-hosted QNX 8.0 XFCE desktop).
- OSS ports: `github.com/qnx-ports` **and** `gitlab.com/qnx/ports` · dashboard `oss.qnx.com`
- Docs: `qnx.com/developers/docs/8.0/` and `qnx.com/developers/docs/qnxeverywhere/`
- Also exist: **QNX Porting Guide (Linux→QNX)**, **DDK Developer's Guide**, **Hardware Interfacing
  Guide** — source material for Ch 19, 20, 22.
- Community per official docs: **Discord `nF3UE97RND`** · **r/qnx** · Stack Overflow `qnx` tag.
- `$QNX_HOST` = Linux-side tools (`qcc`, `mkifs`); `$QNX_TARGET` = QNX-side headers/libs.
  `source ~/qnx800/qnxsdp-env.sh`.

## TECHNICAL DECISIONS (full list → `Decisions.md`)

| ID | Decision |
|----|----------|
| ADR-001 | QNX **SDP 8.0** only (7.1 as ⚠️ delta boxes) |
| ADR-002 | **QNX Everywhere** free non-commercial licence |
| ADR-003 | Labs run on **QEMU + KVM** — no hardware needed for Ch 00–30 |
| ADR-004 | VM image: **QSTI (pre-built) → CTI → raw `mkifs`** — revised from `mkqnximage` |
| ADR-005 | Default target arch **`x86_64`** (KVM speed); `aarch64le` in hardware track |
| ADR-006 | **VS Code + QNX Toolkit** primary IDE; Momentics documented; labs must work from bare terminal |
| ADR-007 | Teach raw **`qcc`** first → simple Makefile → QNX recursive Makefiles → CMake appendix |
| ADR-008 | 3 paths = markers in **one file**, and **all three authored in full** |
| ADR-009 | **Message passing (Ch 13/14) is the centre of the course** |
| ADR-010 | **Mermaid** diagrams + 1-line text description each |
| ADR-011 | PDF via **Pandoc + XeLaTeX + Eisvogel** |
| ADR-012 | `TableOfContents.md` canonical; `TableOfContext.md` = alias |
| ADR-013 | Hardware = **separate track** (public boards + custom board guides) |
| ADR-014 | Every question → permanent **`D-NNN`** entry in `Doubts.md` |
| ADR-015 | **No GitHub-only Markdown** (breaks PDF): no `> [!NOTE]`, no raw HTML, relative links only |
| ADR-016 | **One chapter = one commit**, pushed |
| ADR-017 | Content **CC BY-SA 4.0**, lab code **MIT** |
| ADR-018 | Learner's path **🚶 B** (confirmed) |
| ADR-019 | Capstone ships in **three flavours**: 🤖 robotics · 🚗 automotive · 🏥 medical/industrial |
| ADR-020 | **One chapter per turn**, auto-commit + push |
| ADR-021 | Licence entry point **`qnx.com/getqnx`**; teach request → accept → **deploy** |
| ADR-022 | **Three document tiers**: course · `meta/` bookkeeping · `internal/` (excluded from the book) |
| ADR-023 | `PROMPTS.md` logs **every prompt and every full response** |
| ADR-024 | The author **cannot verify**; only learner-run output clears an `[UNVERIFIED]` marker |
| ADR-025 | **`/btw`** marks an aside that must become a `D-NNN` entry |

## COURSE SHAPE

```text
Part 0  Ch 00–03  Orientation: what is real-time, what is QNX, why/where used   [no software needed]
Part 1  Ch 04–08  Environment: licence, SDP install, QEMU VM, shell, toolchain  ⭐06 ⭐08
Part 2  Ch 09–15  Microkernel: procnto, threads, scheduling, sync, MESSAGE PASSING, memory  ⭐13 ⭐14
Part 3  Ch 16–20  Resource managers: pathname space, first resmgr, deep dive, interrupts, drivers  ⭐17
Part 4  Ch 21–24  System building: boot/IFS/mkifs, BSPs, networking, PPS/logging  ⭐21
Part 5  Ch 25–30  Production: debugging, tracing, adaptive partitioning, security, safety, hypervisor  ⭐25
Part 6  Ch 31–34  Real hardware, custom board bring-up, CAPSTONE, career
```

**Critical path:** Ch 05 → 06 → 08 → 13 → 17 → 21.

## WRITING RULES (non-negotiable)

1. Define every term on first use; add it to `Glossary.md`.
2. **Why → How → API → Lab → Break it → Mastery check.**
3. Every QNX concept gets a **🐧 "In Linux this would be…"** box.
4. No black boxes — explain every flag, every magic number.
5. Every install step is a **literal, copy-pasteable command with expected output**.
6. Shell prompts: **`host$`** = Ubuntu/WSL2, **`qnx#`** = QNX target. Never bare `#`.
7. Chapter template in `PLAN.md` §5 is mandatory — including the `🏃 Fast-Track Summary` box.
8. Every chapter ends with a Changelog table.

## FILE MAP

```text
README.md                          entry point
docs/PLAN.md                       master plan (constitution)
docs/TableOfContents.md            index
docs/chapters/ChapterNN_*.md       the course
docs/guides/Setup_0N_*.md          install guides
docs/guides/Hardware_0N_*.md       hardware track
docs/guides/PDF_Export.md          md → pdf
docs/reference/{Glossary,ReferenceLinks,ResourcesMeta}.md
docs/reference/cheatsheets/CS_*.md
docs/meta/{CourseState,Decisions,DecisionsLog,CompactContext,ToDos,Doubts}.md
docs/internal/                     internal working documents — NOT part of the course (ADR-022)
labs/labNN_*/{README,Makefile,skeleton,solution,prebuilt}
tools/{build-pdf.sh,check-environment.sh,qemu/,pdf/}
```

## OPEN ITEMS

- **Pending learner input:** P-06 — weekly time budget (default assumed: ~5 h/week).
- **Learner's open actions:** ⭐ **T-015 run Setup Guide 03 → report block V5** (7 checkpoints,
  milestone M2) · **T-202** SDP build number *(V5.1 delivers it)* · T-014 QSC install route.
  ✅ Done: T-003, T-008–T-012, T-200 · **Blocks V1–V4 complete.**
- **Doubts logged:** 10 (D-001…D-010, all answered). **`/btw` marks an aside that must be logged (ADR-025).**
- **Top risks:** R5 (version drift — blocked on T-202) · R10 three-path authoring cost.
  ~~R1~~ ~~R2~~ ~~R3~~ ~~R9~~ all **closed**. No external dependency remains anywhere.

## CHANGELOG

| Version | Date | Change |
|---------|------|--------|
| 1.8 | 2026-08-26 | Regenerated after Session 009: **M2 reached**; verified target facts recorded; SSH-as-root trap noted. |
| 1.7 | 2026-08-26 | Regenerated after Session 008: the nested `qemu/qemu` trap recorded; ADR-025; 8 doubts. |
| 1.6 | 2026-08-26 | Regenerated after Session 007: Setup Guide 03 published; QSTI/`mkqnximage` mechanics recorded; block V5 is the next action. |
| 1.5 | 2026-08-26 | Regenerated after Session 006: SDP installed and toolchain verified; both setup guides done; R2 closed; nothing blocking. |
| 1.4 | 2026-08-26 | Regenerated after Session 005: licence deployed, R1 closed, V3 is the next action, no external blockers remain. |
| 1.3 | 2026-08-26 | Regenerated after Session 004: Block V1 verified, host now all-green, R9 and R3 closed, licence request is the sole blocker. |
| 1.2 | 2026-08-26 | Regenerated after Session 003 (author handover): ADR-022/023/024 added; next actions rewritten around the verification protocol; Chapter 00 on hold. |
| 1.1 | 2026-08-25 | Regenerated after Session 002: plan approved, ADR-004 revised (QSTI), ADR-008 strengthened, ADR-019/020/021 added, Setup Guides 01–02 published, QNX facts expanded. |
| 1.0 | 2026-08-25 | Created at end of Session 001. |

## SESSION-START CHECKLIST

1. Read this file.
2. Read `CourseState.md` §1–§2 (at-a-glance + next action).
3. Skim `ToDos.md` for anything marked 🔴.
4. Check `Doubts.md` for entries with status `Open`.
5. Proceed with the "Next action".

---

## 📝 Changelog

*(See the CHANGELOG section above.)*
