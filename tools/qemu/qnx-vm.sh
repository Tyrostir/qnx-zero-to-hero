#!/usr/bin/env bash
#
# qnx-vm.sh — a thin, readable wrapper around mkqnximage for the QNX Zero to Hero labs.
#
# This script does NOT do anything mkqnximage cannot. It exists to:
#   * fail with a useful message instead of "command not found"
#   * remember where the image lives, so you can call it from any directory
#   * put run / stop / ip / ssh / status behind one verb each
#
# Everything here is [UNVERIFIED] until Setup Guide 03 block V5 is run on a real host.
# See docs/guides/Setup_03_QEMU_VM.md
#
set -uo pipefail

IMAGE_DIR="${QNX_IMAGE_DIR:-$HOME/qnx800/images/qemu}"
SDP_ENV="${QNX_SDP_ENV:-$HOME/qnx800/qnxsdp-env.sh}"

GREEN=$'\033[0;32m'; RED=$'\033[0;31m'; YELLOW=$'\033[0;33m'; BOLD=$'\033[1m'; NC=$'\033[0m'
info() { printf '%s==>%s %s\n' "$BOLD" "$NC" "$*"; }
ok()   { printf '  %s✅%s %s\n' "$GREEN" "$NC" "$*"; }
warn() { printf '  %s⚠️ %s %s\n' "$YELLOW" "$NC" "$*"; }
die()  { printf '  %s❌%s %s\n' "$RED" "$NC" "$*" >&2; exit 1; }

usage() {
    cat <<'USAGE'
Usage: qnx-vm.sh <command>

  run       Boot the QNX VM (serial console attaches to this terminal).
            Quit with: Ctrl+A, release, then X
  stop      Stop a running VM from another terminal
  ip        Print the VM's IP address
  ssh       SSH into the VM as root (password: root)
  status    Report whether the environment and image look usable
  help      This message

Environment overrides:
  QNX_IMAGE_DIR   default ~/qnx800/images/qemu
  QNX_SDP_ENV     default ~/qnx800/qnxsdp-env.sh
USAGE
}

# Load the SDP environment if mkqnximage is not already on PATH.
ensure_sdp() {
    if command -v mkqnximage >/dev/null 2>&1; then
        return 0
    fi
    [[ -f "$SDP_ENV" ]] || die "SDP environment not found at $SDP_ENV — is QNX SDP 8.0 installed? (Setup Guide 02)"
    # shellcheck disable=SC1090
    source "$SDP_ENV" >/dev/null 2>&1
    command -v mkqnximage >/dev/null 2>&1 \
        || die "mkqnximage still not on PATH after sourcing $SDP_ENV"
}

ensure_image() {
    [[ -d "$IMAGE_DIR" ]] \
        || die "Image directory not found: $IMAGE_DIR — install com.qnx.qnx800.quickstart.qemu (Setup Guide 03 §4)"
    [[ -f "$IMAGE_DIR/output/ifs.bin" ]] \
        || die "No boot image at $IMAGE_DIR/output/ifs.bin — run ./unpack_qemu_image.sh (Setup Guide 03 §5)"
}

cmd_status() {
    info "QNX VM environment"
    if command -v mkqnximage >/dev/null 2>&1 || [[ -f "$SDP_ENV" ]]; then
        ok "SDP found        $SDP_ENV"
    else
        warn "SDP missing      $SDP_ENV  (Setup Guide 02)"
    fi
    if [[ -d "$IMAGE_DIR" ]]; then ok "image dir        $IMAGE_DIR"
    else warn "image dir absent $IMAGE_DIR  (Setup Guide 03 §4)"; fi
    if [[ -f "$IMAGE_DIR/output/ifs.bin" ]]; then ok "boot image       output/ifs.bin"
    else warn "boot image absent — run unpack_qemu_image.sh  (Setup Guide 03 §5)"; fi
    if [[ -w /dev/kvm ]]; then ok "KVM              /dev/kvm writable 🚀"
    else warn "KVM unavailable — the VM will run 10-50x slower  (Setup Guide 01 §8)"; fi
}

main() {
    case "${1:-help}" in
        run)
            ensure_sdp; ensure_image
            info "Booting QNX. Quit with Ctrl+A then X."
            cd "$IMAGE_DIR" && mkqnximage --run
            ;;
        stop)
            ensure_sdp; ensure_image
            cd "$IMAGE_DIR" && mkqnximage --stop
            ;;
        ip)
            ensure_sdp; ensure_image
            cd "$IMAGE_DIR" && mkqnximage --getip
            ;;
        ssh)
            ensure_sdp; ensure_image
            cd "$IMAGE_DIR" || exit 1
            ip="$(mkqnximage --getip 2>/dev/null | tr -d '[:space:]')"
            [[ -n "$ip" ]] || die "Could not determine the VM's IP — is it running? See Setup Guide 03 §12.1"
            info "Connecting to root@$ip (password: root)"
            ssh "root@$ip"
            ;;
        status)  cmd_status ;;
        help|-h|--help) usage ;;
        *) usage; exit 1 ;;
    esac
}

main "$@"
