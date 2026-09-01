---
title: "Labs — Index and Conventions"
document_id: LABS
version: 1.0
status: Active
created: 2026-08-25
---

# 🧪 labs/ — Hands-On Exercises

Every lab in this course lives here. Labs are published alongside their chapter — this directory
fills up as the course progresses.

> 📑 The authoritative lab list is in
> [`docs/TableOfContents.md` § Labs Index](../docs/TableOfContents.md#-part-v--labs-index).

---

## Lab directory layout

Every lab follows the same structure:

```text
labs/labNN_short_name/
├── README.md            objective · steps · expected output · troubleshooting
├── Makefile             builds for the QNX target
├── skeleton/            🚶 your starting point — code with TODO markers
├── solution/            🏃 complete reference implementation
├── prebuilt/            🐣 ready-to-run binaries (no compiler needed)
└── expected_output.txt  exactly what a correct run prints
```

## The three variants

| Variant | For | What you do |
|---------|-----|-------------|
| 🐣 **observe** | Path A | Copy a binary from `prebuilt/` to the VM, run it, read the output, answer the questions in the lab README. |
| 🚶 **build** | Path B | Start from `skeleton/`, fill in the `TODO`s, compile, deploy, run, and match `expected_output.txt`. |
| 🏃 **reference** | Path C | Read `solution/`, run it, move on. |

## Shell prompt convention

Throughout all labs and chapters:

| Prompt | Means |
|--------|-------|
| `host$` | Your Ubuntu / WSL2 shell |
| `qnx#` | The QNX target shell, as root |

A bare `#` is never used, because it is ambiguous with a comment.

## Before your first lab

1. Complete [Setup Guide 01](../docs/guides/Setup_01_Prerequisites.md) — host prerequisites.
2. Complete [Setup Guide 02](../docs/guides/Setup_02_QNX_Account_And_License.md) — QNX licence + SDP 8.0.
3. Complete [Setup Guide 03](../docs/guides/Setup_03_QEMU_VM.md) — a booting QNX VM.
4. Source the SDP environment in **every new terminal**:

   ```bash
   host$ source ~/qnx800/qnxsdp-env.sh
   ```

   Verify:

   ```bash
   host$ echo "$QNX_HOST"
   ```

   Expected output (path may differ):

   ```text
   /home/tyrostir/qnx800/host/linux/x86_64
   ```

> ⚠️ **Warning.** Forgetting to source `qnxsdp-env.sh` is the single most common cause of "`qcc:
> command not found`" and of mysterious build failures. Add it to your `~/.bashrc` if you like — it
> is safe to run repeatedly.

## Shared build infrastructure

`labs/common/` will hold the shared Makefile fragments and deploy helpers used by every lab, so
individual lab Makefiles stay short and readable.

---

## Licence

All lab source code is MIT licensed. See [`../LICENSE`](../LICENSE) § 2.

## Published labs

| Lab | Chapter | Title | Paths | Status |
|-----|---------|-------|-------|--------|
| [01.2](lab01_timing/) | 01 | Measure jitter | 🚶🏃 | `[UNVERIFIED]` — block V6 |
| [08.1 ⭐](lab08_devloop/) | 08 | **The development loop, with a debugger** | 🚶🏃 | `[UNVERIFIED]` — block V13 |
| [09.2](lab09_faultisolation/) | 09 | Watch a fault stay local | 🚶🏃 | `[UNVERIFIED]` — block V14 |

