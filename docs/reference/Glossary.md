---
title: "Glossary — QNX Terminology A–Z"
document_id: GLOSSARY
version: 1.0
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-25
update_trigger: "Every time a chapter introduces a new term"
---

# 📖 Glossary.md

> Every term this course defines, in one place. The **Ch.** column shows where the term is properly
> introduced — if you meet a word before that chapter, this table is the safety net.
>
> 🌱 = seeded during planning (will be expanded when its chapter is written)

---

## A

| Term | Definition | Ch. |
|------|-----------|-----|
| **Adaptive Partitioning** | A QNX scheduler feature that guarantees each *partition* (group of threads) a minimum percentage of CPU time over a window, while still allowing free use of idle CPU. Prevents one misbehaving subsystem from starving another, without the rigidity of fixed time slicing. | 27 🌱 |
| **`aarch64le`** | QNX's name for the 64-bit ARM little-endian target architecture. Used for Raspberry Pi and most automotive SoCs. | 08 🌱 |
| **ASIL** | *Automotive Safety Integrity Level* (A–D) from ISO 26262. ASIL D is the most stringent. QNX OS is certified to ASIL D. | 29 🌱 |
| **Attribute structure** | In a resource manager, the per-*resource* state (`iofunc_attr_t`) — permissions, size, timestamps — shared by all clients that open that resource. Contrast **OCB**. | 18 🌱 |

## B

| Term | Definition | Ch. |
|------|-----------|-----|
| **Blocking state** | The precise reason a thread is not running: `SEND`, `REPLY`, `RECEIVE`, `MUTEX`, `CONDVAR`, `SIGWAIT`, `NANOSLEEP`, `INTR`, etc. Shown by `pidin`. Reading blocking states is *the* core QNX debugging skill. | 13 🌱 |
| **BSP** | *Board Support Package* — the hardware-specific software (IPL, `startup-*`, drivers, build files) that lets QNX boot on a particular board. | 22 🌱 |
| **Build file** | The text file (`*.build`) that tells `mkifs` what goes into a boot image: which kernel, which drivers, which files, and what to run at startup. | 21 🌱 |

## C

| Term | Definition | Ch. |
|------|-----------|-----|
| **Channel** | A server-side endpoint that receives messages. Created with `ChannelCreate()`. Clients create a **connection** to it. | 13 🌱 |
| **Connection** | A client-side handle to a server's **channel**, created by `ConnectAttach()` or, indirectly, by `open()`. It *is* a file descriptor — this is why `open()` and message passing are the same thing in QNX. | 13 🌱 |
| **Cross-compilation** | Building on one machine/architecture (your x86_64 Linux host) for another (the QNX target). The normal mode of QNX development. | 08 🌱 |

## D

| Term | Definition | Ch. |
|------|-----------|-----|
| **`devb-*`** | Naming convention for QNX **block** device drivers (e.g. `devb-ahci` for SATA). | 20 🌱 |
| **`devc-*`** | Naming convention for QNX **character** device drivers (e.g. `devc-ser8250` for a serial port). | 20 🌱 |
| **`devctl()`** | QNX's device-control call — the POSIX-flavoured replacement for `ioctl()`. Sends a typed command plus data to a resource manager. | 18 🌱 |
| **Determinism** | The property that an operation's timing has a known, bounded worst case. Not "fast" — *predictable*. The defining property of an RTOS. | 01 🌱 |
| **Dispatch layer** | The QNX library machinery (`dispatch_create`, `dispatch_block`, `dispatch_handler`) that multiplexes messages, pulses and select-style events in a resource manager's main loop. | 17 🌱 |

## E

| Term | Definition | Ch. |
|------|-----------|-----|
| **ETFS** | *Embedded Transaction Filesystem* — a QNX filesystem designed for raw NAND flash with power-fail robustness. | 20 🌱 |

## F

| Term | Definition | Ch. |
|------|-----------|-----|
| **FIFO scheduling (`SCHED_FIFO`)** | Run-to-completion scheduling within a priority: a thread runs until it blocks, yields, or is preempted by a higher priority. No time slicing. | 11 🌱 |
| **Freedom from interference** | A functional-safety requirement that a lower-criticality component cannot affect a higher-criticality one (in time, memory or data). QNX's process isolation + adaptive partitioning is how this is argued. | 29 🌱 |

## H

| Term | Definition | Ch. |
|------|-----------|-----|
| **HAM** | *High Availability Manager* — a QNX process that monitors other processes and automatically restarts them (or runs recovery actions) on failure. | 27 🌱 |
| **Hard real-time** | A deadline miss is a *system failure*. Airbag deployment, flight control. Contrast **soft real-time**. | 01 🌱 |
| **Hypervisor (type-1)** | Software that runs directly on hardware and hosts multiple guest OSes. QNX Hypervisor lets a safety-critical QNX guest and a feature-rich Linux guest share one SoC. | 30 🌱 |

## I

| Term | Definition | Ch. |
|------|-----------|-----|
| **IFS** | *Image FileSystem* — the bootable image containing the kernel, essential drivers and startup files. Built by `mkifs`; mounted read-only at `/proc/boot` on a running system. | 21 🌱 |
| **`io-pkt`** | The **legacy** QNX network stack (SDP 6.x/7.x). Largely replaced in QNX 8.0 by `io-sock`. Still widely referenced online — a common source of confusion. | 23 🌱 |
| **`io-sock`** | The QNX 8.0 network stack manager. | 23 🌱 |
| **`iofunc_*`** | A library of default POSIX-behaviour implementations for resource managers (`iofunc_open_default`, `iofunc_read_default`, …). Handles permissions, offsets and timestamps so you only implement what's special about *your* device. | 18 🌱 |
| **IPL** | *Initial Program Loader* — the very first code that runs on a board at reset. Minimal: bring up RAM and enough hardware to load and jump into `startup`. | 21 🌱 |
| **Interrupt handler (ISR)** | A short function attached with `InterruptAttach()` that runs in kernel context with severe restrictions. Typically it does almost nothing except return a `sigevent` that wakes a normal thread. | 19 🌱 |

## J

| Term | Definition | Ch. |
|------|-----------|-----|
| **Jitter** | Variation in the timing of a repeated event. Low average latency with high jitter is often worse for control systems than higher but stable latency. | 01 🌱 |

## M

| Term | Definition | Ch. |
|------|-----------|-----|
| **Message passing** | QNX's fundamental IPC: a *synchronous* `MsgSend()` → `MsgReceive()` → `MsgReply()` exchange between processes. Everything in QNX — files, devices, drivers — is built on it. | 13 🌱 |
| **Microkernel** | An OS design where the kernel provides only scheduling, IPC, interrupt dispatch, timers and basic memory management. Drivers, filesystems and network stacks run as ordinary user-space processes. | 09 🌱 |
| **`mkifs`** | The tool that turns a **build file** into a bootable **IFS** image. | 21 🌱 |
| **`mkqnximage`** | An SDP tool that builds a ready-to-run QNX VM image for QEMU/VMware/VirtualBox, with networking, SSH and `qconn` preconfigured. Our lab environment builder. | 06 🌱 |
| **Momentics** | The Eclipse-based QNX IDE shipped with SDP. | 05 🌱 |
| **MMIO** | *Memory-Mapped I/O* — accessing device registers as if they were memory. On QNX, obtained with `mmap_device_memory()`. | 19 🌱 |

## N

| Term | Definition | Ch. |
|------|-----------|-----|
| **Neutrino** | The historical product name of the QNX microkernel OS (SDP 6.x/7.x era). Surviving in the `nto` in tool names like `gcc_ntox86_64`. | 02 🌱 |
| **`nto`** | Abbreviation of "Neutrino", used throughout QNX target triples and tool names. | 08 🌱 |

## O

| Term | Definition | Ch. |
|------|-----------|-----|
| **OCB** | *Open Control Block* — per-*open* state in a resource manager (current file offset, open flags). One per `open()` call. Contrast **attribute structure**, which is per-resource. | 18 🌱 |

## P

| Term | Definition | Ch. |
|------|-----------|-----|
| **Pathname space** | QNX's unified namespace mapping paths to the processes that serve them. When you `open("/dev/ser1")`, the process manager tells you which server owns that path; you then message that server directly. | 16 🌱 |
| **`pidin`** | *Process Information* — the most important QNX diagnostic command. Shows processes, threads, priorities, blocking states, memory, and what each thread is waiting on. | 07 🌱 |
| **POSIX** | The IEEE standard for Unix-like OS interfaces. QNX is POSIX-compliant, which is why your C/C++ knowledge transfers. | 02 🌱 |
| **PPS** | *Persistent Publish/Subscribe* — a QNX filesystem-based pub/sub service for loosely-coupled communication between components. Objects look like files under `/pps`. | 24 🌱 |
| **Priority inheritance** | A protocol where a thread holding a mutex temporarily inherits the priority of the highest-priority thread waiting for it — the standard cure for **priority inversion**. | 12 🌱 |
| **Priority inversion** | A high-priority thread is blocked by a low-priority thread holding a resource, while a medium-priority thread runs — inverting the intended ordering. Famously nearly killed the Mars Pathfinder mission. | 11 🌱 |
| **`procnto`** | The QNX microkernel binary itself — kernel plus process manager in one. The only thing running in kernel space. | 09 🌱 |
| **Pulse** | A small, **asynchronous**, non-blocking message (a code plus 4 bytes of data) delivered to a channel. Used for notifications, timer expiry and interrupt delivery. | 14 🌱 |

## Q

| Term | Definition | Ch. |
|------|-----------|-----|
| **`qcc` / `q++`** | The QNX C and C++ compiler drivers — wrappers around GCC that select the right target, headers and libraries. | 08 🌱 |
| **`qconn`** | A daemon on the QNX target that lets host tools (IDE, `gdb`, System Analysis Toolkit) inspect, launch and debug processes remotely. Listens on TCP port 8000 by default. | 08 🌱 |
| **QDL** | *QNX Development Licence* — the licence terms governing your use of QNX software. | 04 🌱 |
| **QNX Everywhere** | BlackBerry's free non-commercial licensing programme for QNX SDP 8.0. How this course gets its software. | 04 🌱 |
| **QNX Software Center** | The installer/updater application used to download and manage QNX products on your host. | 05 🌱 |

## R

| Term | Definition | Ch. |
|------|-----------|-----|
| **Resource manager** | A user-space QNX process that registers a path (e.g. `/dev/mydev`) and responds to POSIX messages (`open`, `read`, `write`, `devctl`). QNX's equivalent of a device driver — but with no kernel privileges. | 17 🌱 |
| **Round-robin (`SCHED_RR`)** | Like FIFO, but threads of *equal* priority share the CPU in timeslices. | 11 🌱 |
| **RTOS** | *Real-Time Operating System* — an OS whose design goal is bounded, predictable timing rather than maximum average throughput. | 01 🌱 |

## S

| Term | Definition | Ch. |
|------|-----------|-----|
| **SDP** | *Software Development Platform* — the complete QNX package installed on your host: OS images, cross-compilers, IDE, tools, BSPs. | 05 🌱 |
| **`sigevent`** | A QNX structure describing "what should happen when this event occurs" — deliver a pulse, send a signal, unblock a thread, create a thread. The glue between timers/interrupts and your code. | 14 🌱 |
| **SIL** | *Safety Integrity Level* (1–4) from IEC 61508. QNX OS is certified to SIL 3. | 29 🌱 |
| **`slog2`** | QNX's high-performance system logging framework. Read with `slog2info`. | 24 🌱 |
| **Soft real-time** | A missed deadline degrades quality but is not a failure. Video playback, audio. Contrast **hard real-time**. | 01 🌱 |
| **Sporadic scheduling** | A QNX scheduling policy that lets a thread run at a high priority for a limited *budget* per period, then drops to a lower priority — bounding the CPU a burst-y thread can consume. | 11 🌱 |
| **`startup-*`** | The board-specific program that runs after the IPL: initialises the CPU/SoC, builds the **system page**, and starts `procnto`. | 21 🌱 |
| **System page** | A data structure built by `startup` describing the hardware (CPU, memory map, clocks, interrupts) to the kernel and to drivers. | 21 🌱 |

## T

| Term | Definition | Ch. |
|------|-----------|-----|
| **Target** | The machine running QNX (here: the QEMU VM). Contrast **host**, the machine you develop on. | 08 🌱 |
| **`tracelogger`** | The tool that captures kernel event traces for later analysis in the System Analysis Toolkit. | 26 🌱 |
| **Typed memory** | QNX's mechanism for allocating from specific, named physical memory regions (e.g. DMA-capable or device-specific memory). | 15 🌱 |

## W

| Term | Definition | Ch. |
|------|-----------|-----|
| **WCET** | *Worst-Case Execution Time* — the provable upper bound on how long a piece of code can take. The unit of currency in real-time analysis. | 01 🌱 |

---

## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.0 | 2026-08-25 | Seeded with 55 terms during planning. All marked 🌱 pending their chapter. |
