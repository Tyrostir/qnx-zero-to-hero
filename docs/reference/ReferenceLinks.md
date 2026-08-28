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
| 🥈 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.qdd/topic/about.html | **QNX Developer Desktop** — self-hosted QNX 8.0 XFCE desktop; build on QNX without cross-compiling. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/qnxeverywhere/introduction.html | QNX Everywhere introduction — licence acquisition and official support paths, in QNX's own words. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxsdp.quickstart/topic/install_host.html | SDP 8.0 Quick Start — installation prerequisites (host requirements, no macOS, no ARM hosts). | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.neutrino.sys_arch/topic/about.html | **System Architecture guide** — the best conceptual QNX writing that exists. Read alongside Part 2. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.neutrino.building/topic/bsp/bsp_about.html | "Working with QNX BSPs" — Building Embedded Systems. Chapters 22, 31, 32. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.qnxsdp.migration/topic/about.html | **Migrating to QNX OS 8.0** — the definitive 7.1 → 8.0 delta. Source for the ⚠️ version boxes. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/8.0/com.qnx.doc.security.system/topic/manual/about.html | System Security Guide — Chapter 28. | 2026-08-25 |
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
| 🥇 | https://www.qnx.com/getqnx | **The canonical licence entry point** (ADR-021). Request → accept → deploy your free non-commercial SDP 8.0 licence here. | 2026-08-25 |
| 🥇🔒 | https://www.qnx.com/account/dashboard | **myQNX License Manager.** Where you *accept* and — critically — ***deploy*** the licence to yourself. Skipping deploy is the #1 setup failure. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qsc/com.qnx.doc.qsc.user_guide/topic/install_and_launch.html | **QNX Software Center — install and launch.** Used directly by Setup Guide 02. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qsc/com.qnx.doc.qsc.user_guide/topic/install_qnx_sdp.html | **Installing QNX SDP via the Software Center.** | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/qsc/com.qnx.doc.qsc.user_guide/topic/manage_licenses.html | "Manage Your Product Licenses" — the accept/deploy procedure in QNX's own words. | 2026-08-25 |
| 🥇 | https://support.qnx.com/developers/docs/relnotes8.0/com.qnx.doc.release_notes/topic/sdp8_rn.html | **SDP 8.0 Release Notes** — authoritative list of supported host OS versions. | 2026-08-25 |
| 🥇 | https://qnx.software/en/developers/get-started/qnx-everywhere/licensing | **Licence comparison**: non-commercial vs commercial, with the explicit permitted/forbidden lists. Read before Chapter 04. | 2026-08-25 |
| 🥇 | https://www.qnx.com/legal/licensing/document_archive/current_matrix.pdf | The official, authoritative licence matrix PDF. In case of any conflict, this wins. | 2026-08-25 |
| 🥈 | https://licensing.qnx.com/ | QNX Development Licence (QDL) terms portal. | 2026-08-25 |
| 🥈 | mailto:licensing@qnx.com | QNX licensing team — for eligibility questions. | 2026-08-25 |
| 🥈 | mailto:myqnx@blackberry.com | **Account/login troubleshooting** — the documented escalation path if myQNX registration fails (Risk R1). | 2026-08-25 |

---

## 4. Hardware & board support

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/qsti_qemu/about.html | **QSTI for QEMU Guide** — QNX's official pre-built QEMU image. The basis of Setup Guide 03 (ADR-004). | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/qsti_qemu/getting_started.html | QSTI for QEMU — getting started (download, run, log in). | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/qsti_qemu/troubleshooting.html | QSTI for QEMU — **official troubleshooting page**. Feeds Setup Guide 05. | 2026-08-25 |
| 🥈 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/qsti_qemu/additional_specs.html | QSTI for QEMU — image specifications (RAM, disk, ports). | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/cti/about.html | **CTI — Custom Target Image Guide** for Raspberry Pi and QEMU. Build your own image. Used in Chapter 21. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.target_images/topic/qsti/intro.html | **QSTI for Raspberry Pi 4/5 Guide.** The hardware track's main reference. | 2026-08-25 |
| 🥇 | https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image | Free QNX 8.0 quick-start image for Raspberry Pi — download location. | 2026-08-25 |
| 🥇 | https://qnx.software/en/developers/get-started/board-support-packages | **BSP catalogue** — which boards QNX officially supports. Essential for Chapters 22, 31, 32. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.interfacing/topic/interfacing-hardware.html | **Hardware Interfacing Guide** — talking to GPIO/I2C/SPI etc. Feeds Chapter 19 and the hardware track. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.ddk/topic/about.html | **Driver Development Kit (DDK) Developer's Guide.** Primary source for Chapters 19–20. | 2026-08-25 |
| 🥈 | https://qnx.software/en/partner | Silicon partners (AMD, Intel, NVIDIA, NXP, Qualcomm, Renesas, TI) — who ships QNX-supported SoCs. | 2026-08-25 |

---

## 5. Open source & code

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://github.com/qnx-ports | **Official QNX open-source ports.** Real, idiomatic QNX build recipes — excellent reading material. | 2026-08-25 |
| 🥇 | https://gitlab.com/qnx/ports | QNX open-source ports on **GitLab** — referenced from the QNX Everywhere docs. Check both hosts. | 2026-08-25 |
| 🥇 | https://oss.qnx.com/ | QNX Open-Source Dashboard: every port, its testing level, and where it's hosted. | 2026-08-25 |
| 🥇 | https://www.qnx.com/developers/docs/qnxeverywhere/com.qnx.doc.qpg/topic/about.html | **QNX Porting Guide (Linux → QNX).** Directly useful given your Linux background; source material for several chapters. | 2026-08-25 |

---

## 6. Community & support

| Rank | Link | What it's for | Verified |
|:---:|------|---------------|----------|
| 🥇 | https://discord.com/invite/nF3UE97RND | **QNX Everywhere Discord** — the invite given in the official QNX Everywhere docs. Use this one. | 2026-08-25 |
| 🥈 | https://discord.com/invite/Jj4EkkrFTT | General QNX Discord invite (from the marketing site footer). Different invite code — both were live at time of check. | 2026-08-25 |
| 🥈 | https://www.reddit.com/r/qnx | **r/qnx** — the subreddit cited by QNX's own support-path documentation. | 2026-08-25 |
| 🥈 | https://stackoverflow.com/questions/tagged/qnx | Stack Overflow `qnx` tag — also cited as an official support path. Check answer dates: many target QNX 6.x. | 2026-08-25 |
| 🥈 | https://qnx.software/en/developers/support-and-community/support | Official support portal. | 2026-08-25 |
| 🥉 | https://www.reddit.com/user/QNXEmbeddedSoftware/ | QNX's own Reddit account. | 2026-08-25 |
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
| 2026-08-26 | Fifth pass — market and certification figures verified for Chapter 03 | ✅ BlackBerry, **15 October 2024**: QNX in **255 million vehicles**, +20M year on year, +80M since 2020. Certifications confirmed: IEC 61508 SIL 3, ISO 26262 **ASIL D**, IEC 62304 Class C, EN 50128 / EN 50657 SIL 3. QNX Hypervisor was the first hypervisor certified to ASIL D. Diversification into robotics and medical confirmed. |
| 2026-08-26 | Fourth pass — QNX history and SDP 8.0 release facts verified for Chapter 02 | ✅ QNX's *"A little history"* confirms 1980 founding (Dodge + Bell, Waterloo), QUNIX → QNX after AT&T's letter, 8088 in 1982, QNX 4 ~1991 with POSIX, **Neutrino 1995**. BlackBerry confirms **SDP 8.0 GA 21 March 2024** and QNX Everywhere announced January 2024. |
| 2026-08-26 | Third pass — the four **QSTI for QEMU** pages re-read in full for Setup Guide 03 | ✅ All four live and unchanged in structure. Confirmed: package `com.qnx.qnx800.quickstart.qemu`; `unpack_qemu_image.sh`; launch via **`mkqnximage --run`** (not a raw `qemu-system-x86_64` line); credentials `root`/`root`; defaults 8 CPUs / 4 GB / 1280×768; network `bridge,br=virbr0`; display `sdl,gl=on`. Ubuntu **22.04/24.04** only, with QEMU 10 built from source — unnecessary on 26.04. |
| 2026-08-25 | Second pass — QNX Everywhere doc set read directly | ✅ Added 15 links. **Discovered QSTI (pre-built images for QEMU + Raspberry Pi) and CTI (custom images)** — these did not exist in older QNX material and changed ADR-004. Also found the **QNX Porting Guide** and **DDK Developer's Guide**, and a *different* Discord invite (`nF3UE97RND`) cited in the official docs vs. the marketing footer (`Jj4EkkrFTT`). Both live. |
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
| 1.4 | 2026-08-26 | Chapter 03: market share and certification list verified against BlackBerry's 15 Oct 2024 announcement; ELISA added as the counterweight to "Linux cannot be certified". |
| 1.3 | 2026-08-26 | Chapter 02: history and SDP 8.0 release facts verified against QNX's own history page and BlackBerry's GA announcement. |
| 1.2 | 2026-08-26 | QSTI-for-QEMU links re-verified for Setup Guide 03; findings recorded in the verification table. |
| 1.1 | 2026-08-25 | +15 links from the QNX Everywhere doc set: QSTI (QEMU + Raspberry Pi), CTI, Porting Guide, DDK Guide, Hardware Interfacing, `getqnx`, QSC User's Guide, Release Notes, System Architecture, Migration Guide, GitLab ports, r/qnx, SO tag. Discord invite corrected. |
| 1.0 | 2026-08-25 | Created. 45 links across 10 categories, all verified 2026-08-25. |
