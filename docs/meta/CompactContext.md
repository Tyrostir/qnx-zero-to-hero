---
title: "Compact Context — One-Page Session Reload"
document_id: CTX
version: 1.0
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
- **Active path:** 🚶 **Path B** (full course: theory + all labs). Paths A 🐣 / C 🏃 also maintained.
- **Wants:** everything explained from scratch, every step spelled out, nothing assumed, everything
  documented, every question logged with its answer.

## WHAT

- **Course:** *QNX Zero to Hero* — 6 parts, 34 chapters, ~21 labs, 1 capstone.
- **Repo:** `https://github.com/Tyrostir/qnx-zero-to-hero`
- **Local path:** `/home/tyrostir/exercises/qnx/qnx-zero-to-hero`
- **Deliverable:** a Markdown book + runnable labs, exportable to PDF.

## WHERE WE ARE

| | |
|---|---|
| Phase | **0 — Planning & scaffolding** |
| Chapters published | **0 / 34** |
| Setup guides published | **0 / 5** |
| QNX installed | ❌ |
| VM booting | ❌ |
| Blocker | None — awaiting approval of `PLAN.md` |
| Next | Approve plan → Setup 01 → Setup 02 → Ch 00 → Ch 01 |

## HOST ENVIRONMENT (verified 2026-08-25)

```text
Ubuntu 26.04 LTS on WSL2 · kernel 6.18.33.2-microsoft-standard-WSL2
Intel i7-11850H · 16 logical CPUs · VT-x · /dev/kvm PRESENT ✅
  ⚠️ user NOT in `kvm` group → device not writable → T-008: sudo usermod -aG kvm $USER
23 GiB RAM (21 free) · 952 GB disk free
installed: git 2.53 · curl 8.18 · tar · ssh
NOT installed: gcc/make (build-essential), qemu, java, QNX SDP, QNX licence,
               VS Code QNX Toolkit, pandoc/TeX
Disk budget needed: ~25 GB
Check any time: ./tools/check-environment.sh   (last: 13 pass / 9 warn / 3 fail)
```

## KEY QNX FACTS (verified 2026-08-25 — much online info is stale)

- BlackBerry QNX rebranded: **`blackberry.qnx.com` → `qnx.software`**.
- Current product: **QNX SDP 8.0 / QNX OS 8.0**.
- Free tier: **QNX Everywhere** — free **non-commercial** licence. Flow: myQNX account → licence
  form → licence issued → install **QNX Software Center** → install SDP 8.0.
- Non-commercial **allows**: learning, academia, hobby/maker, **writing training material or books
  (even commercially)**, interoperable OSS.
- Non-commercial **forbids**: production use, distribution, commercial products, customer demos.
- **SDP 7.1 is NOT in the free programme.**
- Free **QNX Quick Start Image for Raspberry Pi** (4/5) on GitLab: `gitlab.com/qnx/quick-start-images/`
- New: **QNX Developer Desktop** (self-hosted QNX 8.0 desktop).
- OSS ports: `github.com/qnx-ports` · dashboard `oss.qnx.com`
- Docs: `qnx.com/developers/docs/8.0/` and `qnx.com/developers/docs/qnxeverywhere/`
- Official **Discord** community exists.

## TECHNICAL DECISIONS (full list → `Decisions.md`)

| ID | Decision |
|----|----------|
| ADR-001 | QNX **SDP 8.0** only (7.1 as ⚠️ delta boxes) |
| ADR-002 | **QNX Everywhere** free non-commercial licence |
| ADR-003 | Labs run on **QEMU + KVM** — no hardware needed for Ch 00–30 |
| ADR-004 | VM built with **`mkqnximage`** (official SDP tool) |
| ADR-005 | Default target arch **`x86_64`** (KVM speed); `aarch64le` in hardware track |
| ADR-006 | **VS Code + QNX Toolkit** primary IDE; Momentics documented; labs must work from bare terminal |
| ADR-007 | Teach raw **`qcc`** first → simple Makefile → QNX recursive Makefiles → CMake appendix |
| ADR-008 | 3 paths = **markers inside one file**, not 3 copies |
| ADR-009 | **Message passing (Ch 13/14) is the centre of the course** |
| ADR-010 | **Mermaid** diagrams + 1-line text description each |
| ADR-011 | PDF via **Pandoc + XeLaTeX + Eisvogel** |
| ADR-012 | `TableOfContents.md` canonical; `TableOfContext.md` = alias |
| ADR-013 | Hardware = **separate track** (public boards + custom board guides) |
| ADR-014 | Every question → permanent **`D-NNN`** entry in `Doubts.md` |
| ADR-015 | **No GitHub-only Markdown** (breaks PDF): no `> [!NOTE]`, no raw HTML, relative links only |
| ADR-016 | **One chapter = one commit**, pushed |
| ADR-017 | Content **CC BY-SA 4.0**, lab code **MIT** |
| ADR-018 | Default path **🚶 B** (provisional) |

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
labs/labNN_*/{README,Makefile,skeleton,solution,prebuilt}
tools/{build-pdf.sh,check-environment.sh,qemu/,pdf/}
```

## OPEN ITEMS

- **Pending learner input:** P-01 glossary language hints · P-02 capstone theme (robotics vs
  automotive) · P-03 separate quizzes folder · P-04 auto-push policy · P-05 how early to write RPi
  guidance. *(Safe defaults exist for all five; see `Decisions.md`.)*
- **Doubts logged:** 0
- **Top risk:** R1 — QNX Everywhere licence approval latency (mitigated: Part 0 needs no software).

## SESSION-START CHECKLIST

1. Read this file.
2. Read `CourseState.md` §1–§2 (at-a-glance + next action).
3. Skim `ToDos.md` for anything marked 🔴.
4. Check `Doubts.md` for entries with status `Open`.
5. Proceed with the "Next action".

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Created at end of Session 001. |
