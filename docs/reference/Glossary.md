---
title: "Glossary — QNX Terminology A–Z"
document_id: GLOSSARY
version: 1.13
status: Active (living document)
created: 2026-08-25
last_updated: 2026-08-26
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
| **Address space** | The MMU-enforced mapping from the virtual addresses a process uses to the physical memory it may touch. Each QNX process has its own, which is *mechanically* why a driver fault cannot reach your memory: your pages are not **mapped** in the driver's address space, so no address it could compute would reach you. | 09, 15 |
| **Adaptive Partitioning** | A QNX scheduler feature that guarantees each *partition* (group of threads) a minimum percentage of CPU time over a window, while still allowing free use of idle CPU. Prevents one misbehaving subsystem from starving another, without the rigidity of fixed time slicing. | 27 🌱 |
| **`aarch64le`** | QNX's name for the 64-bit ARM little-endian target architecture. Used for Raspberry Pi and most automotive SoCs. | 08 🌱 |
| **ASIL** | *Automotive Safety Integrity Level* (A–D) from ISO 26262. **ASIL D** is the most stringent; QNX OS and the QNX Hypervisor are certified to it. Level is assigned per hazard from severity, exposure and controllability — it is a property of the *hazard*, not of the software. | 03, 29 |
| **Attribute structure** | In a resource manager, the per-*resource* state (`iofunc_attr_t`) — permissions, size, timestamps — shared by all clients that open that resource. Contrast **OCB**. | 18 🌱 |

## B

| Term | Definition | Ch. |
|------|-----------|-----|
| **Blast radius** | How far a failure propagates. On QNX: an application fault kills its process; a driver fault kills that driver and returns errors to its clients; a `procnto` fault stops the system. ⚠️ Bounded only for failures that are **loud** — a deadlock produces no fault, so nothing detects it. | 09 |
| **Baseline (QSC)** | QNX Software Center's term for a complete SDP release, installed with `-installBaseline`. Contrast a **package**, one component installed with `-installPackage`. | 05 |
| **Blocking state** | The precise reason a thread is not running — `RECEIVE`, `REPLY`, `SEND`, `MUTEX`, `CONDVAR`, `SEM`, `SIGWAITINFO`, `NANOSLEEP`, `INTR`, `DEAD`. Shown by `pidin`. **`RECEIVE` dominates a healthy system**; **`REPLY`** names the PID being waited on, so chains can be followed and cycles (deadlock) spotted directly. Reading these is *the* core QNX debugging skill. | 07, 13, 25 |
| **BSP** | *Board Support Package* — the hardware-specific software (IPL, `startup-*`, drivers, build files) that lets QNX boot on a particular board. | 22 🌱 |
| **Build file** | The text file (`*.build`) telling `mkifs` what goes into a boot image: which kernel, which drivers, which files, and what runs at startup. Your QSTI image ships the ones that built it, in `output/build/ifs.build` — readable now, taught in Ch 21. | 06, 21 |

## C

| Term | Definition | Ch. |
|------|-----------|-----|
| **Cross-compilation** | Building on one machine (the **host**) for a different one (the **target**). Removes every assumption a native compiler makes: headers, libraries, dynamic-linker path and CPU must all be supplied explicitly. On QNX this is the host/target split of `$QNX_HOST` and `$QNX_TARGET`. | 05 |
| **Certification (functional safety)** | An independent assessor's judgement that a system meets a standard, reached by examining **evidence**: hazard analysis, requirements traceability, test coverage, tool qualification and freedom-from-interference arguments. Applies to a **specific version in a specific configuration** — it is inherited, never automatic. | 03, 29 |
| **Core lab (⭐)** | One of the six labs every coding path must complete: L06 (boot), L08 (deploy/debug loop), L13 (message passing), L17 (resource manager), L21 (custom IFS), L25 (diagnose a hung system). | 00 |
| **Critical path** | The six chapters that carry the course: 05 → 06 → 08 → 13 → 17 → 21. If you only ever do six chapters, do those. | 00 |
| **Channel** | A server-side endpoint that receives messages. Created with `ChannelCreate()`. Clients create a **connection** to it. | 13 🌱 |
| **Connection** | A client-side handle to a server's **channel**, created by `ConnectAttach()` or, indirectly, by `open()`. It *is* a file descriptor — this is why `open()` and message passing are the same thing in QNX. | 13 🌱 |
| **Cross-compilation** | Building on one machine/architecture (your x86_64 Linux host) for another (the QNX target). The normal mode of QNX development. | 08 🌱 |

## D

| Term | Definition | Ch. |
|------|-----------|-----|
| **Development loop** | Edit → build → deploy → run → **debug**. On QNX the middle two cross a network, and the classic failures are a **stale binary**, a **symbol mismatch**, the **wrong target architecture**, and an **unwritable destination**. The structural fix is making `run` and `debug` depend on `deploy`, which depends on the build. | 08 |
| **Data partition (`/data`)** | The writable partition on a QNX target image — the only place changes survive a reboot, since `/proc/boot` is read-only, `/tmp` is RAM, and `/`, `/usr` and `/etc` come from the image's system partition. ⚠️ **Its root directory is owned by `root`**, so an unprivileged user writes to their home, `/data/home/<user>`, which lives on the same partition ([D-015](../meta/Doubts.md#d-015)). Permanent *configuration* still belongs in the image (Ch 21). | 06, 08, 21 |
| **Development licence** | A QNX licence permitting you to *build* software. **It does not permit shipping** — *"distribution and production use is not permitted under a development license and requires a separate distribution license"*. Both the non-commercial and commercial development licences work this way. | 04 |
| **Distribution licence** | The **separate** QNX licence required to give software containing QNX to anyone else. Needed in addition to a commercial development licence. Frequently discovered late, at launch planning. | 04 |
| **Deadline** | The latest acceptable completion time for a response, measured from its release. Often equal to the period for a periodic task. Missing one is a *failure* (hard), makes the result *worthless* (firm), or *degrades quality* (soft). | 01 |
| **Determinism** | The property that timing is **bounded and the bound is knowable** — *not* that it is small. A slower system with a tight bound is more deterministic than a faster one with a long tail. | 01 |
| **Doubt (`D-NNN`)** | A permanent, numbered record of a question and its full answer, in [`Doubts.md`](../meta/Doubts.md). Prefix an aside with `/btw` to guarantee one is created. | 00 |
| **`devb-*`** | Naming convention for QNX **block** device drivers (e.g. `devb-ahci` for SATA). | 20 🌱 |
| **`devc-*`** | Naming convention for QNX **character** device drivers (e.g. `devc-ser8250` for a serial port). | 20 🌱 |
| **`devctl()`** | QNX's device-control call — the POSIX-flavoured replacement for `ioctl()`. Sends a typed command plus data to a resource manager. | 18 🌱 |
| **Determinism** | The property that an operation's timing has a known, bounded worst case. Not "fast" — *predictable*. The defining property of an RTOS. | 01 🌱 |
| **Dispatch layer** | The QNX library machinery (`dispatch_create`, `dispatch_block`, `dispatch_handler`) that multiplexes messages, pulses and select-style events in a resource manager's main loop. | 17 🌱 |

## E

| Term | Definition | Ch. |
|------|-----------|-----|
| **`ESRCH`** | *No such process.* The `errno` value `MsgSend` returns when the server a client was blocked on has died. **The kernel converting another process's catastrophe into your error return** — and the point at which the robustness becomes your error handling's responsibility. | 09, 13 |
| **EN 50128 / EN 50657** | European rail software standards (trackside / on-board). QNX holds **SIL 3**. Rail deadlines are often *seconds* — hard real-time with loose deadlines. | 03, 29 |
| **Evidence package** | The artefacts a certified OS vendor supplies — safety manual, hazard analysis, test reports, tool-qualification data — that let your assessor examine *your application* against a certified baseline instead of a bare kernel. **This is what you buy when you buy a certified OS.** | 03, 29 |
| **`errno`** | A per-thread integer that failing library calls set to say *why* they failed. Meaningful **only immediately after** a call that reported failure — a successful call may leave anything in it. Always test the return value first, then read `errno`. `perror()` and `strerror()` turn it into text. | 01 |
| **ETFS** | *Embedded Transaction Filesystem* — a QNX filesystem designed for raw NAND flash with power-fail robustness. | 20 🌱 |

## F

| Term | Definition | Ch. |
|------|-----------|-----|
| **FreeRTOS** | A free (MIT) real-time **scheduler**, not a full OS: a few thousand lines, typically no MMU, one address space. Right for kilobyte-scale microcontrollers; a different category from QNX despite the shared "RTOS" label. **SafeRTOS** is the certified commercial sibling. | 03 |
| **Freedom from interference** | The safety requirement that non-critical code cannot affect critical code — in timing, memory or shared resources. QNX argues it **structurally**, from MMU-enforced process boundaries, partitioning and security policies, rather than from code review. The core of §1.3's argument for the microkernel. | 03, 27, 29 |
| **FIFO scheduling (`SCHED_FIFO`)** | Run-to-completion scheduling within a priority: a thread runs until it blocks, yields, or is preempted by a higher priority. No time slicing. | 11 🌱 |
| **Freedom from interference** | A functional-safety requirement that a lower-criticality component cannot affect a higher-criticality one (in time, memory or data). QNX's process isolation + adaptive partitioning is how this is argued. | 29 🌱 |

## H

| Term | Definition | Ch. |
|------|-----------|-----|
| **`hogs`** | QNX utility listing the top CPU consumers, sampled. Roughly Linux's `top`. Distinguishes a *busy* system from a *blocked* one — a different investigation each. | 07, 25 |
| **Header file** | A `.h` file holding *declarations* — signatures, types, constants — that the compiler reads. It contains no machine code; that lives in a library. On QNX, target headers are under `$QNX_TARGET/usr/include/`. Reading the header is the authoritative way to check a signature for *your* version. | 01 |
| **Hard real-time** | A system in which missing a deadline is a failure, possibly causing harm. The value of a late result is *negative*. Contrast **firm** (value zero) and **soft** (value diminishing). Hardness is about **consequences**, not tightness. | 01 |
| **HAM** | *High Availability Manager* — a QNX process that monitors other processes and automatically restarts them (or runs recovery actions) on failure. | 27 🌱 |
| **Hard real-time** | A deadline miss is a *system failure*. Airbag deployment, flight control. Contrast **soft real-time**. | 01 🌱 |
| **Hypervisor (type-1)** | Software that runs directly on hardware and hosts multiple guest OSes. QNX Hypervisor lets a safety-critical QNX guest and a feature-rich Linux guest share one SoC. | 30 🌱 |

## I

| Term | Definition | Ch. |
|------|-----------|-----|
| **IFS — Image File System** | QNX's bootable image: a single file (`ifs.bin`, 20 MB on the QSTI image) containing `procnto`, `startup-*`, drivers, `libc` and basic utilities. **Mounted in RAM, in place, permanently, read-only**, and visible as **`/proc/boot`**. A QNX system can boot and run entirely from it with no disk attached. | 06, 21 |
| **IEC 61508** | The base international functional-safety standard for electrical/electronic systems; levels **SIL 1–4**. QNX holds **SIL 3**. Most domain standards (ISO 26262, EN 50128, IEC 62304) derive from it. | 03, 29 |
| **IEC 62304** | Medical device software lifecycle standard; classes A/B/C. **Class C** covers software whose failure can cause death or serious injury. QNX holds Class C. | 03, 29 |
| **INTEGRITY** | Green Hills' high-assurance separation kernel. QNX's closest competitor at the very top of the assurance range; smaller ecosystem, higher cost. | 03 |
| **ISO C standard library** | The set of functions defined by the C language standard itself — `printf`, `malloc`, `qsort`, `perror` — available on every conforming C implementation. Distinct from **POSIX**, which adds operating-system services on top. | 01 |
| **IFS** | *Image FileSystem* — the bootable image containing the kernel, essential drivers and startup files. Built by `mkifs`; mounted read-only at `/proc/boot` on a running system. | 21 🌱 |
| **`io-pkt`** | The **legacy** QNX network stack (SDP 6.x/7.x). Largely replaced in QNX 8.0 by `io-sock`. Still widely referenced online — a common source of confusion. | 23 🌱 |
| **`io-sock`** | The QNX 8.0 network stack manager. | 23 🌱 |
| **`iofunc_*`** | A library of default POSIX-behaviour implementations for resource managers (`iofunc_open_default`, `iofunc_read_default`, …). Handles permissions, offsets and timestamps so you only implement what's special about *your* device. | 18 🌱 |
| **IPL** | *Initial Program Loader* — the very first code that runs on a board at reset. Minimal: bring up RAM and enough hardware to load and jump into `startup`. | 21 🌱 |
| **Interrupt handler (ISR)** | A short function attached with `InterruptAttach()` that runs in kernel context with severe restrictions. Typically it does almost nothing except return a `sigevent` that wakes a normal thread. | 19 🌱 |

## J

| Term | Definition | Ch. |
|------|-----------|-----|
| **Jitter** | The *variation* in latency, usually reported as `max − min` or as a percentile spread (p99.9 − p50). Matters most for periodic tasks, where a wandering interval makes every derivative term in a controller wrong. | 01 |
| **Jitter** | Variation in the timing of a repeated event. Low average latency with high jitter is often worse for control systems than higher but stable latency. | 01 🌱 |

## K

| Term | Definition | Ch. |
|------|-----------|-----|
| **Kernel call** | A function that traps directly into `procnto` — declared in `<sys/neutrino.h>`, named CamelCase by family (`Msg*`, `Thread*`, `Sched*`, `Sync*`, `Timer*`, `Interrupt*`). Distinct from a **library call**, which runs in your process, and from a **message**, which goes to another process. QNX has a few dozen; Linux has ~400 syscalls, because on QNX new functionality arrives as new *servers* rather than new kernel entry points. | 09 |
| **`ksh`** | The Korn shell — QNX's default. POSIX-compliant, so ordinary shell skills transfer. `bash` is also present on the QSTI image. | 07 |

## L

| Term | Definition | Ch. |
|------|-----------|-----|
| **`libc`** | The C library: the shared object holding the machine code for the standard C and POSIX functions. On QNX it is `libc.so.6`, and it lives in `/proc/boot` because nothing — not even the shell — can run without it. | 01 |
| **Latency** | Elapsed time from stimulus to response. Decomposes into interrupt latency, ISR duration, scheduling latency and execution time — **three of the four belong to the OS**. | 01 |
| **Learning path** | One of three routes through the same chapters: 🐣 **A** (understand, no coding), 🚶 **B** (full course with all labs), 🏃 **C** (QNX deltas only, ~1 week). Markers inside each chapter, not separate documents. | 00 |

## M

| Term | Definition | Ch. |
|------|-----------|-----|
| **Mixed criticality** | One processor running software of different safety integrity levels — e.g. an ASIL D warning light beside an uncertified infotainment stack. Requires demonstrable isolation: process boundaries, adaptive partitioning, or a hypervisor. The main modern driver of QNX adoption. | 03, 27, 30 |
| **Microkernel** | An OS design in which the kernel provides only what cannot live anywhere else — on QNX: scheduling, memory management, timers and message passing — and everything else, including **every driver, filesystem and the network stack**, runs as an ordinary user-space process. QNX has held this design since 1980. Contrast **monolithic kernel**. | 02 |
| **Monolithic kernel** | An OS design in which drivers, filesystems and the network stack all run **inside** kernel space with full privilege. Faster in the common case; a fault anywhere can halt the machine. Linux and Windows. | 02 |
| **Momentics** | QNX's Eclipse-based IDE, shipped with the SDP since 2002. VS Code with the QNX Toolkit is now a first-class alternative. | 02 |
| **`mkqnximage`** | The SDP tool that builds, launches (`--run`), stops (`--stop`) and queries (`--getip`) a QNX virtual machine. It identifies an image directory by the presence of `local/` and `output/`. Not the same thing as **QSTI**, which is the image it launches. | 00 |
| **Message passing** | QNX's fundamental IPC: a *synchronous* `MsgSend()` → `MsgReceive()` → `MsgReply()` exchange between processes. Everything in QNX — files, devices, drivers — is built on it. | 13 🌱 |
| **Microkernel** | An OS design where the kernel provides only scheduling, IPC, interrupt dispatch, timers and basic memory management. Drivers, filesystems and network stacks run as ordinary user-space processes. | 09 🌱 |
| **`mkifs`** | The tool that turns a **build file** into a bootable **IFS** image. | 21 🌱 |
| **`mkqnximage`** | An SDP tool that builds a ready-to-run QNX VM image for QEMU/VMware/VirtualBox, with networking, SSH and `qconn` preconfigured. Our lab environment builder. | 06 🌱 |
| **Momentics** | The Eclipse-based QNX IDE shipped with SDP. | 05 🌱 |
| **MMIO** | *Memory-Mapped I/O* — accessing device registers as if they were memory. On QNX, obtained with `mmap_device_memory()`. | 19 🌱 |

## N

| Term | Definition | Ch. |
|------|-----------|-----|
| **`ntox86_64-gdb`** | The cross-debugger in `$QNX_HOST/usr/bin`. Runs on Linux, controls a process on the QNX target through **`qconn`**. Companions: `ntox86_64-objdump`, `-nm`, `-strip`. | 08, 25 |
| **Neutrino** | The QNX microkernel line introduced in **1995**, and the origin of `procnto`. Present-day products are called *QNX OS*; "Neutrino RTOS" in a product name signals **6.x-era material**. The name survives internally — the `nto` in `procnto` and in `gcc_ntox86_64`. | 02 |
| **Neutrino** | The historical product name of the QNX microkernel OS (SDP 6.x/7.x era). Surviving in the `nto` in tool names like `gcc_ntox86_64`. | 02 🌱 |
| **`nto`** | Abbreviation of "Neutrino", used throughout QNX target triples and tool names. | 08 🌱 |

## O

| Term | Definition | Ch. |
|------|-----------|-----|
| **OCB** | *Open Control Block* — per-*open* state in a resource manager (current file offset, open flags). One per `open()` call. Contrast **attribute structure**, which is per-resource. | 18 🌱 |

## P

| Term | Definition | Ch. |
|------|-----------|-----|
| **Pathname space** | The namespace `procnto` maintains, mapping paths to the **processes** that registered them. `open("/dev/ser1")` asks who owns that path and returns a connection to that process; `read()`/`write()` then become **messages**. Why `/dev` entries on QNX are running services rather than device nodes. | 07, 16 |
| **Production use** | Running software for real, as something people rely on — **including internally and without payment**. One of the two boundaries of the non-commercial licence (the other being distribution). A permanent internal test rig is plausibly production use. | 04 |
| **`PREEMPT_RT`** | The Linux real-time preemption patch set, mainlined in 2024. Makes Linux genuinely usable for soft and many firm real-time systems. Does **not** provide a certified OS with an evidence package — the gap that keeps QNX in safety-critical products. | 03 |
| **`procnto`** | The QNX kernel — *process manager* + *Neutrino*. Provides scheduling, memory management, timers and message passing, **and nothing else**. Always pid 1. Ships in variants: `-smp` (multi-core), `-instr` (kernel tracing compiled in, needed for Ch 26). | 02, 09 |
| **`pthread_*`** | The POSIX threads API — `<pthread.h>`. Standard POSIX, not QNX-specific, and identical on Linux. ⚠️ Unlike most POSIX calls, these **return an error number directly** rather than returning `-1` and setting `errno`. | 01, 10, 12 |
| **POSIX.1b** | The 1993 *real-time extensions* to POSIX. Source of `clock_gettime`, `nanosleep`, POSIX timers, real-time signals, message queues and priority scheduling. Where the standardised real-time vocabulary comes from. | 01 |
| **Priority inversion** | A high-priority thread blocked on a lock held by a low-priority thread that is itself preempted by a medium-priority thread — so the highest-priority thread waits on the lowest, for unbounded time. Caused the Mars Pathfinder resets in 1997. Fixed by **priority inheritance**. | 01, 12 |
| **Period (`T`)** | The interval between successive releases of a periodic task. | 01 |
| **`pidin`** | *Process information* — QNX's `ps`, and the single most-used diagnostic command in this course. Lists **threads**, with each one's priority, scheduling policy and **blocking state**. `ps` has no equivalent for that last column. | 00 |
| **Process ID (QNX)** | A 32-bit identifier that is neither small nor sequential — expect values like `14032920`. A QNX PID names an **addressable message-passing endpoint**, so IDs are spread across a large space to make a stale reference fail rather than reach a recycled process. | 00 |
| **Pathname space** | QNX's unified namespace mapping paths to the processes that serve them. When you `open("/dev/ser1")`, the process manager tells you which server owns that path; you then message that server directly. | 16 🌱 |
| **`pidin`** | *Process Information* — the most important QNX diagnostic command. Shows processes, threads, priorities, blocking states, memory, and what each thread is waiting on. | 07 🌱 |
| **POSIX** | The IEEE standard for Unix-like OS interfaces. QNX has been POSIX-compliant since QNX 4 (~1991), which is why your C/C++ knowledge transfers unchanged — `open`, `read`, `pthread_*` and the C library behave exactly as on Linux. On QNX these become **messages to a user-space process**, and your code cannot tell. | 02 |
| **PPS** | *Persistent Publish/Subscribe* — a QNX filesystem-based pub/sub service for loosely-coupled communication between components. Objects look like files under `/pps`. | 24 🌱 |
| **Priority inheritance** | A protocol where a thread holding a mutex temporarily inherits the priority of the highest-priority thread waiting for it — the standard cure for **priority inversion**. | 12 🌱 |
| **Priority inversion** | A high-priority thread is blocked by a low-priority thread holding a resource, while a medium-priority thread runs — inverting the intended ordering. Famously nearly killed the Mars Pathfinder mission. | 11 🌱 |
| **`procnto`** | The QNX microkernel binary itself — kernel plus process manager in one. The only thing running in kernel space. | 09 🌱 |
| **Pulse** | A small, **asynchronous**, non-blocking message (a code plus 4 bytes of data) delivered to a channel. Used for notifications, timer expiry and interrupt delivery. | 14 🌱 |

## Q

| Term | Definition | Ch. |
|------|-----------|-----|
| **`qconn`** | The QNX **remote agent** on a target: lets a host-side debugger start, stop, inspect and control target processes, list them (`info pidlist`) and attach to a running one. Listens on port **8000**; started automatically by `slm`. More capable than Linux's `gdbserver`, which can only debug a process it launched itself. | 08 |
| **`q++`** | `qcc` for C++. Equivalent to `qcc -V<target>_gpp`. Use `_gpp` (GNU `libstdc++`) unless you specifically need `_cxx`, QNX's older C++ library. | 08 |
| **`$QNX_HOST`** | Environment variable naming the SDP directory of programs that **execute on your development machine** — `qcc`, `q++`, `ntox86_64-gdb`, `mkifs`, `mkqnximage`. Set by `qnxsdp-env.sh`. Verified value: `~/qnx800/host/linux/x86_64`. | 05 |
| **`$QNX_TARGET`** | Environment variable naming the SDP directory of files **for the QNX target** — headers, libraries and target binaries, organised by architecture (`x86_64/`, `aarch64le/`). Verified value: `~/qnx800/target/qnx`. Also serves as `mkifs` source material (Ch 21). | 05, 21 |
| **`qcc`** | QNX's compiler **driver** — not itself a compiler. Reads `-V<target>`, looks it up in `$QNX_HOST/etc/qcc/`, and assembles the real `ntox86_64-gcc` (GCC **12.2.0**) command with the right `-I` and `-L` paths into `$QNX_TARGET`. `qcc -v` shows what it ran. | 05, 08 |
| **`qnxsdp-env.sh`** | The SDP script that sets `$QNX_HOST`, `$QNX_TARGET` and `MAKEFLAGS`, and prepends `$QNX_HOST/usr/bin` to `PATH`. Must be run with **`source`** — `./` starts a child shell that exits with the variables. Affects one terminal only. | 05 |
| **QNX OS** | The operating system itself. Formerly *QNX Neutrino RTOS*; current version **8.0**, GA 21 March 2024. Distinct from **QNX SDP**, which is the OS plus the toolchain. | 02 |
| **QNX SDP** | *QNX Software Development Platform* — the OS **plus** the cross-toolchain, headers, libraries, target images and IDE. What you install on your Linux host (`~/qnx800`). | 02 |
| **QNX Everywhere** | The **free, non-commercial licence tier** for SDP 8.0, announced January 2024. Permits learning, academic work, **hobby/maker products**, public free OSS, **training material and books even commercially**, and **customer demonstrations**. Prohibits production use, distribution, commercial product development, and paid activity outside those exceptions. **The boundary is production and distribution, not money.** | 02, 04 |
| **`qnxuser`** | The unprivileged account (UID 1000) on the QSTI QEMU image, password `qnxuser`, holding full `sudo`. **The account you must use for SSH** — the image ships `PermitRootLogin no`, so `root` is refused by password *and* key. | 00 |
| **QSTI** | *Quick Start Target Image* — QNX's official **pre-built** system image for QEMU and Raspberry Pi. Installed as a QNX Software Center package and launched with `mkqnximage --run`. The course's day-one target. | 00 |
| **`qcc` / `q++`** | The QNX C and C++ compiler drivers — wrappers around GCC that select the right target, headers and libraries. | 08 🌱 |
| **`qconn`** | A daemon on the QNX target that lets host tools (IDE, `gdb`, System Analysis Toolkit) inspect, launch and debug processes remotely. Listens on TCP port 8000 by default. | 08 🌱 |
| **QDL** | *QNX Development Licence* — the licence terms governing your use of QNX software. | 04 🌱 |
| **QNX Everywhere** | BlackBerry's free non-commercial licensing programme for QNX SDP 8.0. How this course gets its software. | 04 🌱 |
| **QNX Software Center** | The installer/updater application used to download and manage QNX products on your host. | 05 🌱 |

## R

| Term | Definition | Ch. |
|------|-----------|-----|
| **Remote debugging** | Running the debugger on the **host** while the process runs on the **target**. On QNX: `ntox86_64-gdb prog` then `target qnx <ip>:8000`. **Symbols stay on the host** — only addresses, registers and raw memory cross the network — which is why a stripped target binary is still fully debuggable, and why mismatched host/target builds produce confident nonsense. | 08, 25 |
| **Rate-monotonic** | Fixed-priority scheduling in which a shorter period earns a higher priority. Guarantees schedulability only up to `U ≤ n(2^(1/n) − 1)`, which approaches **≈ 69 %** for large task sets — so deadlines can be missed with a third of the CPU idle. | 01, 11 |
| **Real-time system** | A system whose **correctness depends on when a result is produced as well as what it is**. A late answer is a wrong answer. Says nothing about speed. | 01 |
| **Response time (`R`)** | Release → completion, **including any time spent preempted or blocked**. Deadlines apply to `R`, not to execution time `C`. Confusing the two is the most common beginner error in timing analysis. | 01 |
| **Resource manager** | A user-space QNX process that registers a path (e.g. `/dev/mydev`) and responds to POSIX messages (`open`, `read`, `write`, `devctl`). QNX's equivalent of a device driver — but with no kernel privileges. | 17 🌱 |
| **Round-robin (`SCHED_RR`)** | Like FIFO, but threads of *equal* priority share the CPU in timeslices. | 11 🌱 |
| **RTOS** | *Real-Time Operating System* — an OS whose design goal is bounded, predictable timing rather than maximum average throughput. | 01 🌱 |

## S

| Term | Definition | Ch. |
|------|-----------|-----|
| **`slog2info`** | Reads QNX's structured system log. **The first command to run after something misbehaved** — the console scrolls, the log does not. | 07, 24 |
| **`slm` — System Launch and Monitor** | QNX's service manager: starts components in dependency order, waits for readiness, and can restart one that dies. Its entire configuration is one readable file, `/proc/boot/slm.cfg`. Roughly Linux's `systemd`, but far smaller and with restart as its core purpose. 22 components on the QSTI image. | 06, 27 |
| **Syspage** | The structure `startup-*` builds and hands to `procnto`, describing the hardware it found: memory map, CPU count and features, timer frequency, interrupt controller. **`procnto` contains no board-specific code** — it learns the machine from the syspage, which is why one kernel binary runs on QEMU, a Raspberry Pi and an automotive SoC. What a BSP fundamentally provides. | 06, 21, 22 |
| **`startup-*`** | The QNX boot stage that runs before the kernel: initialises CPU, memory and interrupt controller, builds the **syspage**, and prints **`Startup complete`** — the boundary between debugging the *board* and debugging the *system*. Board-specific; part of a BSP. | 06, 22, 32 |
| **Separated debug symbols (`.sym`)** | Debugging information — symbol names, line numbers, types — stripped from an executable and stored in a `.sym` file beside it. Keeps target binaries small while letting `gdb` on the host produce symbolic backtraces. Must match the binary exactly; a stale `.sym` yields confidently wrong function names. | 05, 25 |
| **Sysroot** | The cross-compilation term for a directory tree standing in for the target's filesystem root, supplying headers and libraries at build time. `$QNX_TARGET` is QNX's equivalent — found via an environment variable rather than a `--sysroot=` flag. | 05 |
| **SIL** | *Safety Integrity Level* (1–4) from IEC 61508 — the general scale from which ASIL and rail levels derive. QNX holds **SIL 3**. | 03, 29 |
| **Safety manual** | The document defining the **certified envelope** of an OS: which version, which configuration, which features are prohibited, and what assumptions the certificate rests on. Read it **before** the architecture is fixed — discovering late that your design relies on an excluded feature is the classic expensive mistake. | 03, 29 |
| **`slay`** | QNX command that terminates processes **by name** rather than by PID — roughly Linux's `pkill`. `slay -f` forces. Because QNX drivers are ordinary processes, `slay` can stop a network stack or a disk driver, which has no equivalent on a monolithic kernel. | 02, 25 |
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
| **`toybox`** | The compact multi-call binary supplying much of QNX's core userland (`ls`, `grep`, `sed`, …). Present in `/proc/boot`. Implements the commonly used subset of each tool, so an unfamiliar GNU flag being rejected is usually `toybox`, not a QNX quirk. | 07 |
| **Target** | The machine running QNX (here: the QEMU VM). Contrast **host**, the machine you develop on. | 08 🌱 |
| **`tracelogger`** | The tool that captures kernel event traces for later analysis in the System Analysis Toolkit. | 26 🌱 |
| **Typed memory** | QNX's mechanism for allocating from specific, named physical memory regions (e.g. DMA-capable or device-specific memory). | 15 🌱 |

## U

| Term | Definition | Ch. |
|------|-----------|-----|
| **`use`** | QNX's built-in help command — `use pidin` extracts the usage message embedded in the binary. Correct for the exact build you are running, and works offline. | 07 |
| **Utilisation (`U`)** | The fraction of CPU a task set demands: `Σ(Cᵢ/Tᵢ)`. `U > 1.0` is infeasible on one core; `U ≤ 1.0` is necessary but not sufficient — see **rate-monotonic**. | 01, 11 |
| **`[UNVERIFIED]`** | A marker on a step that was written from documentation but **has not been executed on a real machine**. Removed only when someone runs it and pastes back the real output. There are currently none in this course. | 00 |

## V

| Term | Definition | Ch. |
|------|-----------|-----|
| **VxWorks** | Wind River's commercial RTOS — QNX's closest direct competitor, with particularly strong aerospace/defence heritage (DO-178C). Similar niche, similar cost profile. | 03 |

## W

| Term | Definition | Ch. |
|------|-----------|-----|
| **WCET** | *Worst-Case Execution Time* — the upper bound on one computation across all inputs and machine states, excluding preemption. Measurement gives a *lower* bound; static analysis gives an upper bound that is often uselessly loose. Caches and multi-core make both harder. | 01, 26 |
| **WCET** | *Worst-Case Execution Time* — the provable upper bound on how long a piece of code can take. The unit of currency in real-time analysis. | 01 🌱 |


## Z

| Term | Definition | Ch. |
|------|-----------|-----|
| **Zephyr** | The Linux Foundation's Apache-2.0 RTOS for microcontrollers. Strong momentum and a modern toolchain; its functional-safety story is younger than QNX's or VxWorks'. | 03 |

---


## 📝 Changelog

| Version | Date | Change |
|---------|------|--------|
| 1.13 | 2026-08-26 | **Data partition** corrected — `/data`'s root is root-owned; unprivileged writes go to `/data/home/<user>` ([D-015](../meta/Doubts.md#d-015)). |
| 1.12 | 2026-08-26 | Chapter 09: +4 terms (address space, kernel call, blast radius, `ESRCH`). |
| 1.11 | 2026-08-26 | Chapter 08: +5 terms (`qconn`, `q++`, remote debugging, `ntox86_64-gdb`, development loop). |
| 1.10 | 2026-08-26 | Chapter 07: +6 terms (`ksh` — with a new K section, pathname space, `slog2info`, `toybox`, `use`, `hogs`) and **blocking state** promoted from a planning stub with the full state list. |
| 1.9 | 2026-08-26 | Chapter 06: +5 terms (IFS, `slm`, syspage, `startup-*`, data partition) and **build file** promoted from a planning stub. |
| 1.8 | 2026-08-26 | Chapter 05: +8 terms (`$QNX_HOST`, `$QNX_TARGET`, `qcc`, `qnxsdp-env.sh`, separated debug symbols, sysroot, cross-compilation, QSC baseline). |
| 1.7 | 2026-08-26 | Chapter 04: +3 terms (development licence, distribution licence, production use) and **QNX Everywhere** corrected — customer demonstrations are permitted, and the boundary is production and distribution rather than money. |
| 1.6 | 2026-08-26 | Chapter 03: +15 terms (certification, evidence package, freedom from interference, safety manual, mixed criticality, IEC 61508/62304, EN 50128/50657, SIL, `PREEMPT_RT`, FreeRTOS, Zephyr, VxWorks, INTEGRITY) and **ASIL** promoted from a planning stub. |
| 1.5 | 2026-08-26 | Chapter 02: +10 terms (microkernel, monolithic kernel, Momentics, Neutrino, `procnto`, QNX OS, QNX SDP, QNX Everywhere, `slay`) and **POSIX** expanded from its planning stub. |
| 1.4 | 2026-08-26 | +`pthread_*` from the Chapter 01 library-function audit. |
| 1.3 | 2026-08-26 | Chapter 01 lab: +5 terms (`errno`, header file, ISO C standard library, `libc`, POSIX.1b) from [D-014](../meta/Doubts.md#d-014). |
| 1.2 | 2026-08-26 | Chapter 01: +13 terms (real-time system, determinism, deadline, hard real-time, latency, jitter, period, response time, WCET, utilisation, rate-monotonic, priority inversion). |
| 1.1 | 2026-08-26 | Chapter 00: +10 terms (learning path, core lab, critical path, doubt, `[UNVERIFIED]`, `pidin`, QNX process ID, QSTI, `mkqnximage`, `qnxuser`). Sections L and U added and the index kept alphabetical. |
| 1.0 | 2026-08-25 | Seeded with 55 terms during planning. All marked 🌱 pending their chapter. |
