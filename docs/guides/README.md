---
title: "Guides — Index"
document_id: GUIDES-INDEX
version: 1.0
status: Active
created: 2026-08-25
---

# 🛠️ docs/guides/

Standalone, do-this-once documents: installation, hardware, and publishing.

Unlike chapters, guides are **procedures**, not lessons. They are written to be followed literally,
step by step, with every command shown and every expected output stated.

---

## Setup guides — follow in order

| # | Guide | What it gets you | Status |
|---|-------|------------------|--------|
| 01 | [Prerequisites & Host Preparation](Setup_01_Prerequisites.md) | QEMU, KVM verified, build tools, disk space | 📄 Planned |
| 02 | [QNX Account, Licence & SDP 8.0](Setup_02_QNX_Account_And_License.md) | myQNX account → QNX Everywhere licence → Software Center → SDP 8.0 | 📄 Planned |
| 03 | [Building & Running the QNX VM](Setup_03_QEMU_VM.md) ⭐ | A booting QNX 8.0 VM with networking and a shared folder | 📄 Planned |
| 04 | [IDE & Tooling](Setup_04_IDE_And_Tooling.md) | VS Code + QNX Toolkit, Momentics, `qconn`, remote gdb | 📄 Planned |
| 05 | [Troubleshooting Catalogue](Setup_05_Troubleshooting.md) | Symptom → cause → fix for every failure encountered | 📄 Planned |

> ⚠️ **Start Setup 02 on day one.** The QNX Everywhere licence request takes time to process
> (Risk R1). Chapters 00–03 need no software, so read those while you wait.

## Hardware guides — optional, read when ready

| # | Guide | Scope | Status |
|---|-------|-------|--------|
| H1 | [Publicly Available QNX Hardware](Hardware_01_Public_Boards.md) | Raspberry Pi 4/5, x86_64 PCs, NXP/TI/Qualcomm/Renesas eval kits | 📄 Planned |
| H2 | [Custom Hardware Bring-Up](Hardware_02_Custom_Board.md) | Your own PCB: IPL → startup → procnto → drivers → production image | 📄 Planned |

> 💡 **No hardware is required for Chapters 00–30.** The entire core course runs in QEMU.

## Publishing

| Guide | Scope | Status |
|-------|-------|--------|
| [PDF_Export.md](PDF_Export.md) | Convert the whole course to PDF with Pandoc + XeLaTeX | 📙 Drafted (untested) |

---

## Conventions used in all guides

| Prompt | Means |
|--------|-------|
| `host$` | Your Ubuntu / WSL2 shell |
| `qnx#` | The QNX target shell, as root |

Every command block is followed by an **Expected output** block. If what you see differs, stop and
check [Setup_05_Troubleshooting.md](Setup_05_Troubleshooting.md).

Steps marked **`[UNVERIFIED]`** have been written but not yet executed on the learner's machine.
The marker is removed once the step has actually been run and its real output confirmed (ADR-024).
This currently applies to **both** Setup Guide 01 and Setup Guide 02.
