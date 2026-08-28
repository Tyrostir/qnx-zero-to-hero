---
title: "QNX Zero to Hero — Table of Contents"
document_id: TOC
version: 1.0
status: Active
created: 2026-08-25
last_updated: 2026-08-25
---

# 📑 Table of Contents

> The master index of the course. Every document in this repository is reachable from here.
> Chapter status is mirrored in [`meta/CourseState.md`](meta/CourseState.md).

**Legend**

| Symbol | Meaning |
|--------|---------|
| 🐣 | Included in **Path A** — Absolute Beginner (no coding) |
| 🚶 | Included in **Path B** — Self-Learner (full course) |
| 🏃 | Included in **Path C** — Fast-Track Pro (summary only unless ⭐) |
| ⭐ | Contains a **core lab** — mandatory for all coding paths |
| 📕 | Status: **Published** |
| 📙 | Status: **Drafting** |
| 📄 | Status: **Planned** |

---

## Quick navigation

| I want to… | Go to |
|-----------|-------|
| Understand the whole plan | [PLAN.md](PLAN.md) |
| Know how to read this course | [Chapter 00](chapters/Chapter00_HowToUseThisCourse.md) |
| Install everything | [Setup Guides](#-part-i--setup-guides) |
| Find where I left off | [CourseState.md](meta/CourseState.md) |
| Look up a term | [Glossary.md](reference/Glossary.md) |
| Find a link/resource | [ReferenceLinks.md](reference/ReferenceLinks.md) · [ResourcesMeta.md](reference/ResourcesMeta.md) |
| Re-read a question I asked | [Doubts.md](meta/Doubts.md) |
| Buy/use real hardware | [Hardware Guides](#-part-ii--hardware-guides) |
| Make PDFs | [PDF_Export.md](guides/PDF_Export.md) |

---

## 📘 Part 0 — Orientation: What & Why

*Goal: understand what QNX is and why anyone would use it. **No software required** — you can read
all of Part 0 while your QNX licence request is being processed.*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 00 | [How To Use This Course](chapters/Chapter00_HowToUseThisCourse.md) | 🐣🚶🏃 | 25 m | 📕 |
| 01 | [What Is a Real-Time System?](chapters/Chapter01_WhatIsARealTimeSystem.md) | 🐣🚶🏃 | 60 m | 📕 |
| 02 | [What Is QNX?](chapters/Chapter02_WhatIsQNX.md) | 🐣🚶🏃 | 75 m | 📕 |
| 03 | [Why & Where QNX Is Used](chapters/Chapter03_WhyAndWhereQNXIsUsed.md) | 🐣🚶🏃 | 60 m | 📕 |

**Part 0 review:** *Write a one-page "Should we use QNX?" memo for a fictional project.*

---

## 🛠️ Part 1 — Getting Your Environment

*Goal: a working QNX development setup and a booting QNX VM.*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 04 | [QNX Licensing & QNX Everywhere](chapters/Chapter04_LicensingAndQNXEverywhere.md) | 🐣🚶🏃 | 45 m | 📕 |
| 05 | [Installing QNX SDP 8.0](chapters/Chapter05_InstallingQNXSDP.md) | 🐣🚶🏃 | 90 m | 📕 |
| 06 | [Your First QNX VM on QEMU](chapters/Chapter06_FirstQNXVMOnQEMU.md) ⭐ | 🐣🚶🏃 | 90 m | 📄 |
| 07 | [First Contact — The QNX Shell](chapters/Chapter07_FirstContactTheQNXShell.md) | 🐣🚶🏃 | 75 m | 📄 |
| 08 | [The Toolchain: qcc, q++ and Deployment](chapters/Chapter08_ToolchainAndDeployment.md) ⭐ | 🚶🏃 | 120 m | 📄 |

**Companion setup guides:** see [Part I — Setup Guides](#-part-i--setup-guides) below.

**Part 1 review:** *Cross-compile, deploy, run and remote-debug a "hello, QNX" program.*

---

## 🧠 Part 2 — The Microkernel Core

*Goal: understand and use the QNX kernel — the part that makes QNX **QNX**.*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 09 | [Microkernel Architecture & procnto](chapters/Chapter09_MicrokernelArchitecture.md) | 🐣🚶🏃 | 90 m | 📄 |
| 10 | [Processes and Threads](chapters/Chapter10_ProcessesAndThreads.md) | 🚶🏃 | 90 m | 📄 |
| 11 | [Scheduling & Real-Time Priorities](chapters/Chapter11_SchedulingAndPriorities.md) | 🚶🏃 | 100 m | 📄 |
| 12 | [Synchronization Primitives](chapters/Chapter12_Synchronization.md) | 🚶🏃 | 100 m | 📄 |
| 13 | [Message Passing I — Send / Receive / Reply](chapters/Chapter13_MessagePassingI.md) ⭐ | 🐣🚶🏃 | 150 m | 📄 |
| 14 | [Message Passing II — Pulses, Events, Timers](chapters/Chapter14_MessagePassingII.md) ⭐ | 🚶🏃 | 120 m | 📄 |
| 15 | [Memory Management](chapters/Chapter15_MemoryManagement.md) | 🚶🏃 | 100 m | 📄 |

**Part 2 review:** *Build a 3-process pipeline with a priority-correct message-passing design.*

---

## 🔌 Part 3 — Resource Managers & Drivers

*Goal: extend the OS itself. In QNX, drivers are ordinary user-space programs — and you will write one.*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 16 | [The Pathname Space](chapters/Chapter16_ThePathnameSpace.md) | 🐣🚶🏃 | 75 m | 📄 |
| 17 | [Your First Resource Manager](chapters/Chapter17_FirstResourceManager.md) ⭐ | 🚶🏃 | 150 m | 📄 |
| 18 | [Resource Manager Deep Dive](chapters/Chapter18_ResourceManagerDeepDive.md) | 🚶🏃 | 150 m | 📄 |
| 19 | [Interrupts & Hardware Access](chapters/Chapter19_InterruptsAndHardware.md) | 🚶🏃 | 120 m | 📄 |
| 20 | [Device Drivers & Filesystems](chapters/Chapter20_DriversAndFilesystems.md) | 🚶🏃 | 100 m | 📄 |

**Part 3 review:** *Write a `/dev/` resource manager backed by a simulated device with interrupts.*

---

## 📦 Part 4 — Building the System

*Goal: own the boot image. Go from "I run programs on QNX" to "I define what QNX **is** on this board."*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 21 | [Boot Process & the IFS](chapters/Chapter21_BootProcessAndIFS.md) ⭐ | 🐣🚶🏃 | 150 m | 📄 |
| 22 | [Board Support Packages (BSPs)](chapters/Chapter22_BoardSupportPackages.md) | 🚶🏃 | 120 m | 📄 |
| 23 | [Networking on QNX](chapters/Chapter23_Networking.md) | 🚶🏃 | 100 m | 📄 |
| 24 | [PPS, Logging & Persistence](chapters/Chapter24_PPSLoggingPersistence.md) | 🚶🏃 | 100 m | 📄 |

**Part 4 review:** *Produce a minimal custom IFS that boots to your own program instead of a shell.*

---

## 🔍 Part 5 — Debug, Performance, Safety & Production

*Goal: the skills that separate "it works on my VM" from "it ships in a car."*

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 25 | [Debugging Toolbox](chapters/Chapter25_DebuggingToolbox.md) ⭐ | 🚶🏃 | 120 m | 📄 |
| 26 | [Tracing & Performance Analysis](chapters/Chapter26_TracingAndPerformance.md) | 🚶🏃 | 120 m | 📄 |
| 27 | [Adaptive Partitioning & High Availability](chapters/Chapter27_AdaptivePartitioningAndHA.md) | 🐣🚶🏃 | 100 m | 📄 |
| 28 | [Security on QNX](chapters/Chapter28_Security.md) | 🐣🚶🏃 | 100 m | 📄 |
| 29 | [Functional Safety](chapters/Chapter29_FunctionalSafety.md) | 🐣🚶🏃 | 90 m | 📄 |
| 30 | [QNX Hypervisor](chapters/Chapter30_Hypervisor.md) | 🐣🚶🏃 | 90 m | 📄 |

**Part 5 review:** *Given a deliberately broken system image, diagnose 5 planted faults.*

---

## 🏭 Part 6 — Real Hardware, Capstone & Beyond

| # | Chapter | Paths | Est. | Status |
|---|---------|-------|------|--------|
| 31 | [Running QNX on Real Hardware](chapters/Chapter31_RealHardware.md) | 🐣🚶🏃 | 90 m | 📄 |
| 32 | [Bringing Up a Custom Board](chapters/Chapter32_CustomBoardBringUp.md) | 🚶🏃 | 150 m | 📄 |
| 33 | [Capstone Project](chapters/Chapter33_CapstoneProject.md) — *three flavours* | 🚶🏃 | 15–25 h | 📄 |
| 34 | [Ecosystem, Career & Next Steps](chapters/Chapter34_EcosystemAndCareer.md) | 🐣🚶🏃 | 45 m | 📄 |

### Capstone flavours (Chapter 33)

One shared architecture and rubric — pick the domain that interests you. **All three are fully
documented**; you are not locked in.

| Track | Project | Domain |
|-------|---------|--------|
| 🤖 **33-R** | Motor-control loop + sensor fusion + telemetry | Robotics / physical AI |
| 🚗 **33-A** | Sensor → control → actuator chain with CAN-style messaging + cluster display | Automotive |
| 🏥 **33-M** | Dose/setpoint controller with alarm supervision and safe-state fallback | Medical device / industrial PLC |

---

## 🧰 Part I — Setup Guides

*Standalone, do-this-once installation documents. Referenced from Part 1 chapters.*

| # | Guide | What it gets you | Status |
|---|-------|------------------|--------|
| 01 | [Prerequisites & Host Preparation](guides/Setup_01_Prerequisites.md) | Ubuntu/WSL2 packages, QEMU, KVM enabled, disk space, Git | 📕 |
| 02 | [QNX Account, Licence & SDP 8.0 Install](guides/Setup_02_QNX_Account_And_License.md) | myQNX account → request/accept/**deploy** licence → QNX Software Center → SDP 8.0 | 📕 |
| 03 | [Your First QNX VM on QEMU](guides/Setup_03_QEMU_VM.md) ⭐ | A booting QNX 8.0 x86_64 VM (QSTI), SSH access, and your own binary running on it | 📕 |
| 04 | [IDE & Tooling](guides/Setup_04_IDE_And_Tooling.md) | VS Code + QNX Toolkit, Momentics IDE, `qconn`, remote gdb | 📄 |
| 05 | [Troubleshooting Catalogue](guides/Setup_05_Troubleshooting.md) | Symptom → cause → fix, for every install/boot failure seen | 📄 |

---

## 🔩 Part II — Hardware Guides

*Kept deliberately separate from the QEMU-based course. Read when you're ready for real silicon.*

| # | Guide | Scope | Status |
|---|-------|-------|--------|
| H1 | [Publicly Available QNX Hardware](guides/Hardware_01_Public_Boards.md) | Raspberry Pi 4/5, x86_64 PCs, NXP, TI, Qualcomm, Renesas eval kits — buy, flash, boot, run labs | 📄 |
| H2 | [Custom Hardware Bring-Up](guides/Hardware_02_Custom_Board.md) | Your own PCB: IPL → startup → procnto → drivers → production image | 📄 |

---

## 📚 Part III — Reference

| Document | Contents |
|----------|----------|
| [Glossary.md](reference/Glossary.md) | A–Z of QNX terminology with chapter cross-references |
| [ReferenceLinks.md](reference/ReferenceLinks.md) | Every external URL, categorized, with verification dates |
| [ResourcesMeta.md](reference/ResourcesMeta.md) | Rated meta-review of docs, books, courses, videos, forums, repos |
| [cheatsheets/](reference/cheatsheets/) | Printable one-pagers |

### Cheat sheets

| Sheet | Covers | Status |
|-------|--------|--------|
| [CS_pidin.md](reference/cheatsheets/CS_pidin.md) | Every useful `pidin` invocation | 📄 |
| [CS_qcc.md](reference/cheatsheets/CS_qcc.md) | `qcc`/`q++` flags, target triples | 📄 |
| [CS_MessagePassing.md](reference/cheatsheets/CS_MessagePassing.md) | Blocking states, API map, state diagram | 📄 |
| [CS_ResourceManager.md](reference/cheatsheets/CS_ResourceManager.md) | resmgr skeleton + callback table | 📄 |
| [CS_BuildFile.md](reference/cheatsheets/CS_BuildFile.md) | `mkifs` build-file syntax | 📄 |
| [CS_Debugging.md](reference/cheatsheets/CS_Debugging.md) | gdb, dumper, slog2, hogs, showmem | 📄 |
| [CS_QNXvsLinux.md](reference/cheatsheets/CS_QNXvsLinux.md) | Side-by-side command & concept translation | 📄 |

---

## 🗃️ Part IV — Course Meta (living documents)

| Document | Purpose |
|----------|---------|
| [CourseState.md](meta/CourseState.md) | 📍 Where we are, what's next, session history |
| [Decisions.md](meta/Decisions.md) | Current active decisions (ADR index) |
| [DecisionsLog.md](meta/DecisionsLog.md) | Append-only decision history with rationale |
| [CompactContext.md](meta/CompactContext.md) | 1-page context reload for a fresh session |
| [ToDos.md](meta/ToDos.md) | Open work items (yours and mine) |
| [Doubts.md](meta/Doubts.md) | Every question asked + full answer (`D-NNN`) |

---

## 🧪 Part V — Labs Index

*Populated as chapters are published. Each lab lives in `labs/labNN_name/`.*

| Lab | Chapter | Title | Core | Status |
|-----|---------|-------|:----:|--------|
| L06.1 | 06 | Build and boot a QNX VM | ⭐ | 📄 |
| L07.1 | 07 | Explore the QNX filesystem and `/proc` | | 📄 |
| L08.1 | 08 | Hello QNX: compile, deploy, run | ⭐ | 📄 |
| L08.2 | 08 | Remote debugging with `qconn` + `gdb` | | 📄 |
| L10.1 | 10 | Thread lifecycle and `pidin` observation | | 📄 |
| L11.1 | 11 | Priority inversion, observed and fixed | | 📄 |
| L12.1 | 12 | Mutex / condvar producer-consumer | | 📄 |
| L13.1 | 13 | Client / server with `MsgSend`–`MsgReply` | ⭐ | 📄 |
| L13.2 | 13 | 💥 Break it: the missing `MsgReply` | | 📄 |
| L14.1 | 14 | Pulses and periodic timers | ⭐ | 📄 |
| L15.1 | 15 | Shared memory between processes | | 📄 |
| L17.1 | 17 | `/dev/hello` resource manager | ⭐ | 📄 |
| L18.1 | 18 | Add `devctl()` to your resource manager | | 📄 |
| L19.1 | 19 | Attach to a timer interrupt | | 📄 |
| L21.1 | 21 | Build a custom IFS with `mkifs` | ⭐ | 📄 |
| L23.1 | 23 | TCP echo server on QNX | | 📄 |
| L24.1 | 24 | Publish and subscribe with PPS | | 📄 |
| L25.1 | 25 | Diagnose a hung system with `pidin` | ⭐ | 📄 |
| L26.1 | 26 | Capture and read a kernel trace | | 📄 |
| L27.1 | 27 | Adaptive partitioning under CPU load | | 📄 |
| L33-R | 33 | 🎓 Capstone — 🤖 Robotics flavour | ⭐ | 📄 |
| L33-A | 33 | 🎓 Capstone — 🚗 Automotive flavour | ⭐ | 📄 |
| L33-M | 33 | 🎓 Capstone — 🏥 Medical / industrial flavour | ⭐ | 📄 |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.8 | 2026-08-26 | **Chapter 05 published.** |
| 1.7 | 2026-08-26 | **Chapter 04 published — Part 1 begins.** |
| 1.6 | 2026-08-26 | **Chapter 03 published — Part 0 complete (4/4).** |
| 1.5 | 2026-08-26 | **Chapter 02 published.** |
| 1.4 | 2026-08-26 | **Chapter 01 published.** Its path tag gains 🏃 — ADR-008 requires a genuine Fast-Track Summary in every chapter, so Path C is served even where it skips the body. |
| 1.3 | 2026-08-26 | **Chapter 00 published** — the first chapter. |
| 1.2 | 2026-08-26 | Setup Guide 03 published. |
| 1.1 | 2026-08-25 | Chapter 33 split into three documented capstone flavours (ADR-019). Setup Guides 01–02 published. |
| 1.0 | 2026-08-25 | Initial TOC: 6 parts, 34 chapters, 5 setup guides, 2 hardware guides, 7 cheat sheets, 21 labs. |
