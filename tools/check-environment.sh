#!/usr/bin/env bash
#
# check-environment.sh — Report whether this host is ready for the QNX Zero to Hero labs.
#
# Safe to run at any time. Read-only: installs nothing, changes nothing.
# Referenced by docs/guides/Setup_01_Prerequisites.md
#
set -uo pipefail

GREEN=$'\033[0;32m'; RED=$'\033[0;31m'; YELLOW=$'\033[0;33m'; BLUE=$'\033[0;34m'; BOLD=$'\033[1m'; NC=$'\033[0m'
PASS=0; WARN=0; FAIL=0

hdr()  { printf '\n%s%s%s\n' "$BOLD$BLUE" "$*" "$NC"; printf '%s\n' "$(printf '─%.0s' {1..64})"; }
ok()   { printf '  %s✅ %-22s%s %s\n' "$GREEN" "$1" "$NC" "${2:-}"; PASS=$((PASS+1)); }
warn() { printf '  %s⚠️  %-22s%s %s\n' "$YELLOW" "$1" "$NC" "${2:-}"; WARN=$((WARN+1)); }
bad()  { printf '  %s❌ %-22s%s %s\n' "$RED" "$1" "$NC" "${2:-}"; FAIL=$((FAIL+1)); }
note() { printf '     %s↳%s %s\n' "$BLUE" "$NC" "$*"; }

printf '%s\n' "$BOLD"
cat <<'BANNER'
  ╔════════════════════════════════════════════════════════════╗
  ║   QNX: Zero to Hero — Host Environment Check               ║
  ╚════════════════════════════════════════════════════════════╝
BANNER
printf '%s' "$NC"

# ------------------------------------------------------------------ host basics
hdr "1. Host system"

if [[ -r /etc/os-release ]]; then
    . /etc/os-release
    ok "OS" "$PRETTY_NAME"
else
    warn "OS" "cannot read /etc/os-release"
fi

ok "Kernel" "$(uname -r)"

if grep -qi microsoft /proc/version 2>/dev/null; then
    ok "Environment" "WSL2 (Windows Subsystem for Linux)"
    note "WSL2 is supported. Setup Guide 02 has WSL-specific notes for the QNX Software Center GUI."
else
    ok "Environment" "native Linux"
fi

ARCH="$(uname -m)"
if [[ "$ARCH" == "x86_64" ]]; then
    ok "Architecture" "$ARCH"
else
    warn "Architecture" "$ARCH — the course assumes x86_64; labs will need aarch64 adjustments"
fi

# ------------------------------------------------------------------------- CPU
hdr "2. CPU & virtualization"

NPROC="$(nproc 2>/dev/null || echo '?')"
if [[ "$NPROC" != "?" && "$NPROC" -ge 4 ]]; then
    ok "CPU cores" "$NPROC logical"
else
    warn "CPU cores" "$NPROC — 4+ recommended for comfortable VM use"
fi

MODEL="$(grep -m1 'model name' /proc/cpuinfo 2>/dev/null | cut -d: -f2- | sed 's/^ *//')"
[[ -n "$MODEL" ]] && ok "CPU model" "$MODEL"

if grep -qE '(vmx|svm)' /proc/cpuinfo 2>/dev/null; then
    ok "HW virtualization" "supported (VT-x / AMD-V)"
else
    warn "HW virtualization" "not advertised — QEMU will fall back to slow TCG emulation"
fi

if [[ -e /dev/kvm ]]; then
    if [[ -r /dev/kvm && -w /dev/kvm ]]; then
        ok "/dev/kvm" "present and accessible — KVM acceleration available 🚀"
    else
        warn "/dev/kvm" "present but not accessible by your user"
        note "fix: sudo usermod -aG kvm \$USER   (then log out and back in)"
    fi
else
    bad "/dev/kvm" "missing — VM will run under slow TCG emulation"
    note "On WSL2, ensure nested virtualization is enabled in .wslconfig"
    note "On bare metal, enable VT-x/AMD-V in the BIOS/UEFI"
fi

# ---------------------------------------------------------------------- memory
hdr "3. Memory & disk"

MEM_GB="$(awk '/MemTotal/ {printf "%.0f", $2/1024/1024}' /proc/meminfo 2>/dev/null || echo 0)"
if   [[ "$MEM_GB" -ge 16 ]]; then ok   "RAM" "${MEM_GB} GiB total"
elif [[ "$MEM_GB" -ge 8  ]]; then warn "RAM" "${MEM_GB} GiB — workable; keep the VM at 2 GB"
else                              bad  "RAM" "${MEM_GB} GiB — 8 GiB minimum recommended"; fi

DISK_AVAIL_GB="$(df -BG --output=avail "$HOME" 2>/dev/null | tail -1 | tr -dc '0-9')"
if [[ -n "$DISK_AVAIL_GB" ]]; then
    if   [[ "$DISK_AVAIL_GB" -ge 100 ]]; then ok   "Free disk (\$HOME)" "${DISK_AVAIL_GB} GB — plenty (need ~85 GB)"
    elif [[ "$DISK_AVAIL_GB" -ge  85 ]]; then warn "Free disk (\$HOME)" "${DISK_AVAIL_GB} GB — just enough (need ~85 GB)"
    else                                      bad  "Free disk (\$HOME)" "${DISK_AVAIL_GB} GB — need ~85 GB for SDP + VM image"; fi
fi

# ------------------------------------------------------------------------ tools
hdr "4. Required host tools"

check_cmd() {
    local cmd="$1" label="$2" hint="$3" version_flag="${4:---version}"
    if command -v "$cmd" >/dev/null 2>&1; then
        ok "$label" "$($cmd $version_flag 2>&1 | head -1 | cut -c1-52)"
    else
        bad "$label" "not installed"
        note "fix: $hint"
    fi
}

check_cmd git   "git"    "sudo apt install -y git"
check_cmd curl  "curl"   "sudo apt install -y curl"
check_cmd make  "make"   "sudo apt install -y build-essential"
check_cmd gcc   "gcc"    "sudo apt install -y build-essential"
check_cmd tar   "tar"    "sudo apt install -y tar"
check_cmd ssh   "ssh"    "sudo apt install -y openssh-client" "-V"

if command -v java >/dev/null 2>&1; then
    ok "java" "$(java -version 2>&1 | head -1 | cut -c1-52)"
else
    warn "java" "not installed — QNX Software Center may need it"
    note "fix: sudo apt install -y default-jre"
fi

# ------------------------------------------------------------------------- qemu
hdr "5. QEMU (lab environment)"

if command -v qemu-system-x86_64 >/dev/null 2>&1; then
    ok "qemu-system-x86_64" "$(qemu-system-x86_64 --version | head -1 | cut -c1-52)"
else
    bad "qemu-system-x86_64" "not installed"
    note "fix: sudo apt install -y qemu-system-x86 qemu-utils  (Setup Guide 01)"
fi

command -v qemu-img >/dev/null 2>&1 \
    && ok "qemu-img" "$(qemu-img --version | head -1 | cut -c1-52)" \
    || warn "qemu-img" "not installed — sudo apt install -y qemu-utils"

# -------------------------------------------------------------------------- qnx
hdr "6. QNX SDP"

QNX_FOUND=0
for d in "$HOME/qnx800" "$HOME/qnx710" /opt/qnx800 "${QNX_HOST:-}"; do
    [[ -n "$d" && -d "$d" ]] && { ok "QNX SDP directory" "$d"; QNX_FOUND=1; break; }
done
[[ $QNX_FOUND -eq 0 ]] && { warn "QNX SDP" "not found — install it via Setup Guide 02"; }

if [[ -n "${QNX_HOST:-}" ]]; then
    ok "\$QNX_HOST" "$QNX_HOST"
    ok "\$QNX_TARGET" "${QNX_TARGET:-unset}"
    command -v qcc >/dev/null 2>&1 \
        && ok "qcc" "$(qcc -V 2>&1 | head -1 | cut -c1-52)" \
        || warn "qcc" "not on PATH"
else
    warn "\$QNX_HOST" "unset — run: source ~/qnx800/qnxsdp-env.sh"
fi

[[ -f "$HOME/.qnx/license/licenses" ]] \
    && ok "QNX licence file" "~/.qnx/license/licenses" \
    || warn "QNX licence" "not found — see Setup Guide 02"

# ------------------------------------------------------------------------- pdf
hdr "7. PDF toolchain (optional)"

for t in pandoc xelatex mmdc; do
    command -v "$t" >/dev/null 2>&1 \
        && ok "$t" "installed" \
        || warn "$t" "not installed — optional, see docs/guides/PDF_Export.md"
done

# ---------------------------------------------------------------------- summary
hdr "Summary"
printf '  %s%d passed%s   %s%d warnings%s   %s%d failed%s\n\n' \
    "$GREEN" "$PASS" "$NC" "$YELLOW" "$WARN" "$NC" "$RED" "$FAIL" "$NC"

if [[ $FAIL -eq 0 && $WARN -eq 0 ]]; then
    printf '  %s🎉 Fully ready. Proceed to the next chapter.%s\n\n' "$BOLD$GREEN" "$NC"
elif [[ $FAIL -eq 0 ]]; then
    printf '  %s👍 Ready to proceed.%s Warnings above are for optional or not-yet-installed items.\n\n' "$BOLD$GREEN" "$NC"
else
    printf '  %s🔧 Action needed.%s Fix the ❌ items above, then re-run this script.\n' "$BOLD$YELLOW" "$NC"
    printf '     Full instructions: docs/guides/Setup_01_Prerequisites.md\n\n'
fi

exit 0
