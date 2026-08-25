---
title: "Reference Links — Curated External Sources"
document_id: REFS
version: 1.0
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "Every time a chapter cites a new external source"
---

# 🔗 ReferenceLinks.md

> Every external URL used anywhere in this course, categorized, with **what it's good for** and
> **when it was last verified**.
>
> ⚠️ **Why the verification dates matter.** BlackBerry rebranded and migrated the QNX web presence
> during 2025 — `blackberry.qnx.com` now redirects to `qnx.software`. A large amount of QNX material
> found via search engines (and a large amount of AI training data) points at dead or moved URLs.
> Every link below was opened and confirmed on the date shown.

**Legend:** 🥇 essential · 🥈 useful · 🥉 situational · 🔒 requires login · 💰 costs money

---

## Index

1. [Official QNX — start here](#1-official-qnx--start-here)
2. [Official documentation](#2-official-documentation)
3. [Getting the software & licensing](#3-getting-the-software--licensing)
4. [Hardware & board support](#4-hardware--board-support)
5. [Open source & code](#5-open-source--code)
6. [Community & support](#6-community--support)
7. [Training & video](#7-training--video)
8. [Background: RTOS & real-time theory](#8-background-rtos--real-time-theory)
9. [Functional safety & standards](#9-functional-safety--standards)
10. [Tooling used by this course](#10-tooling-used-by-this-course)
11. [Link health log](#11-link-health-log)

---

## 1. Official QNX — start here

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://qnx.software/ | The current QNX home. **Note the domain** — `blackberry.qnx.com` redirects here. | 2026-08-25 |
| 🥇 | https://qnx.software/en/developers/get-started/qnx-everywhere/ | The free non-commercial programme. Your entry point to getting QNX. | 2026-08-25 |
| 🥇 | https://www.qnx.com/products/everywhere/ | The actual "get started / request licence" landing page. | 2026-08-25 |
| 🥈 | https://qnx.software/en/software/products-and-solutions/qnx-software-development-platform | What SDP 8.0 contains, product-level overview. | 2026-08-25 |
| 🥈 | https://qnx.software/en/about-qnx/our-story | Company history — background for Chapter 02. | 2026-08-25 |

---

## 2. Official documentation

> This is the primary technical source for the entire course. Bookmark it.

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://www.qnx.com/developers/docs/8.0/ | **The SDP 8.0 documentation root.** Everything below hangs off this. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxsdp.quickstart/topic/about.html | **SDP 8.0 Quick Start Guide** — read alongside Setup Guides 02–03. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/index.html | **QNX Everywhere documentation** — the beginner-oriented doc set. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxsdp.nav/topic/bookset.html | SDP bookset: System Architecture, Programmer's Guide, Utilities, C Library, Building Embedded Systems. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxtoolkit.user_guide/topic/about_this_guide.html | **QNX Toolkit for VS Code** — our primary IDE (ADR-006). | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.ide.userguide/topic/about.html | QNX Momentics IDE User's Guide (Eclipse-based alternative). | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.qdd/topic/about.html | **QNX Developer Desktop** — self-hosted QNX 8.0 desktop. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.hypervisor.nav/topic/bookset.html | QNX Hypervisor — background for Chapter 30. | 2026-08-25 |
| 🥉 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.containers.user_guide/topic/about.html | QNX Containers. | 2026-08-25 |
| 🥉 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxcloud.nav/topic/bookset.html | Running QNX on AWS / Azure. | 2026-08-25 |
| 🥉 | https://www.qnx.com/developers/docs/8.0/indexTerms.html | Documentation index-terms page — surprisingly good for finding APIs. | 2026-08-25 |

> 💡 **Insight.** QNX docs are organised as *booksets*. The five you will actually live in are:
> **System Architecture** (concepts), **Programmer's Guide** (how to write code), **Library
> Reference** (API man pages), **Utilities Reference** (command-line tools), and **Building Embedded
> Systems** (boot images and BSPs).

---

## 3. Getting the software & licensing

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇🔒 | https://www.qnx.com/account/login.html | **myQNX account** — login / create. Step 1 of getting QNX. | 2026-08-25 |
| 🥇 | https://qnx.software/en/developers/get-started/qnx-everywhere/licensing | **Licence comparison**: non-commercial vs commercial, with the explicit permitted/forbidden lists. Read before Chapter 04. | 2026-08-25 |
| 🥇 | https://www.qnx.com/legal/licensing/document_archive/current_matrix.pdf | The official, authoritative licence matrix PDF. In case of any conflict, this wins. | 2026-08-25 |
| 🥈 | https://licensing.qnx.com/ | QNX Development Licence (QDL) terms portal. | 2026-08-25 |
| 🥈 | mailto:licensing@qnx.com | QNX licensing team — for eligibility questions. | 2026-08-25 |
| 🥈 | mailto:myqnx@blackberry.com | **Account/login troubleshooting** — the documented escalation path if myQNX registration fails (Risk R1). | 2026-08-25 |

---

## 4. Hardware & board support

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image | **Free QNX 8.0 image for Raspberry Pi** — the cheapest route to real QNX hardware. | 2026-08-25 |
| 🥇 | https://qnx.software/en/developers/get-started/board-support-packages | **BSP catalogue** — which boards QNX officially supports. Essential for Chapters 22, 31, 32. | 2026-08-25 |
| 🥈 | https://qnx.software/en/partner | Silicon partners (AMD, Intel, NVIDIA, NXP, Qualcomm, Renesas, TI) — who ships QNX-supported SoCs. | 2026-08-25 |

---

## 5. Open source & code

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://github.com/qnx-ports | **Official QNX open-source ports.** Real, idiomatic QNX build recipes — excellent reading material. | 2026-08-25 |
| 🥇 | https://oss.qnx.com/ | QNX Open-Source Dashboard: every port, its testing level, and where it's hosted. | 2026-08-25 |

---

## 6. Community & support

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://discord.com/invite/Jj4EkkrFTT | **Official QNX Discord.** The fastest place to get a real answer in 2026. | 2026-08-25 |
| 🥈 | https://qnx.software/en/developers/support-and-community/support | Official support portal. | 2026-08-25 |
| 🥈 | https://www.reddit.com/user/QNXEmbeddedSoftware/ | QNX on Reddit. | 2026-08-25 |
| 🥉 | https://qnx.software/en/resources-knowledge-hub/validation-success-stories/resource-center | Whitepapers, case studies — useful for Chapter 03 (where QNX is used). | 2026-08-25 |

---

## 7. Training & video

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://qnx.software/en/developers/get-started/training/overview/ | **Free official QNX online training courses.** Complements this course; do them in parallel. | 2026-08-25 |
| 🥈 | https://www.youtube.com/playlist?list=PL7D-rKNQhkfKU5PAvjyEBq6KbusRVVb5r | "Get Started With QNX Everywhere" video playlist. Good visual companion to Setup Guides 02–03. | 2026-08-25 |
| 🥉 | https://www.youtube.com/qnxcam | QNX official YouTube channel. | 2026-08-25 |
| 🥉 | https://podcasts.apple.com/us/podcast/code-the-future/id1794636330 | "Code the Future" — QNX podcast. Background listening. | 2026-08-25 |

---

## 8. Background: RTOS & real-time theory

*Not QNX-specific. Supporting material for Chapters 01, 11 and 12.*

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥈 | https://en.wikipedia.org/wiki/Real-time_operating_system | Decent orientation on RTOS concepts. | 2026-08-25 |
| 🥈 | https://en.wikipedia.org/wiki/Rate-monotonic_scheduling | Rate-monotonic scheduling and schedulability analysis — Chapter 11. | 2026-08-25 |
| 🥈 | https://en.wikipedia.org/wiki/Priority_inversion | Priority inversion, including the Mars Pathfinder incident — used as a case study in Chapter 11. | 2026-08-25 |
| 🥉 | https://en.wikipedia.org/wiki/Microkernel | Microkernel vs monolithic background — Chapter 09. | 2026-08-25 |

> 📚 Book-length and paid resources are rated separately in
> [`ResourcesMeta.md`](ResourcesMeta.md).

---

## 9. Functional safety & standards

*Background for Chapter 29. Standards documents themselves are paywalled; these are orientation.*

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://qnx.software/en/developers/developer-roadmap/certifications-and-compliance | **What QNX is actually certified to**, and what that means for your project. | 2026-08-25 |
| 🥈💰 | https://www.iso.org/standard/68383.html | ISO 26262 (road-vehicle functional safety). Paywalled. | 2026-08-25 |
| 🥈💰 | https://webstore.iec.ch/publication/5515 | IEC 61508 (functional safety of E/E/PE systems). Paywalled. | 2026-08-25 |

---

## 10. Tooling used by this course

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://www.qemu.org/docs/master/system/target-i386.html | QEMU x86_64 system emulation — flags used in Setup Guide 03. | 2026-08-25 |
| 🥇 | https://pandoc.org/MANUAL.html | Pandoc manual — the PDF pipeline. | 2026-08-25 |
| 🥇 | https://github.com/Wandmalfarbe/pandoc-latex-template | **Eisvogel** LaTeX template for Pandoc (ADR-011). | 2026-08-25 |
| 🥈 | https://mermaid.js.org/intro/ | Mermaid diagram syntax (ADR-010). | 2026-08-25 |
| 🥈 | https://github.com/mermaid-js/mermaid-cli | `mmdc` — renders Mermaid to PNG/SVG for the PDF build. | 2026-08-25 |
| 🥈 | https://github.com/raghur/mermaid-filter | Pandoc filter that renders Mermaid blocks during conversion. | 2026-08-25 |
| 🥉 | https://learn.microsoft.com/en-us/windows/wsl/ | WSL2 documentation — relevant to GUI apps and networking in Setup Guides 01–03. | 2026-08-25 |

---

## 11. Link health log

*Re-verify all links at the start of each new Part. Record findings here.*

| Date | Action | Result |
|------|--------|--------|
| 2026-08-25 | Initial verification of all links in this document | ✅ All reachable. **Notable:** `blackberry.qnx.com/*` now 301-redirects to `qnx.software`. All QNX links recorded in their post-migration form. |

### Known-stale patterns to watch for

| Stale pattern | Replace with |
|---------------|--------------|
| `blackberry.qnx.com/en/…` | `qnx.software/en/…` |
| `qnx.com/developers/docs/7.1/…` | `qnx.com/developers/docs/8.0/…` *(unless deliberately citing 7.1)* |
| `qnx.com/developers/docs/6.5.0/…` | Legacy Neutrino 6.5 — historical only |
| "QNX Neutrino RTOS" as a product name | "QNX OS 8.0" / "QNX SDP 8.0" |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Created. 45 links across 10 categories, all verified 2026-08-25. |
