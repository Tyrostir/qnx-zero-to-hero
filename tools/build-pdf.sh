#!/usr/bin/env bash
#
# build-pdf.sh — Convert the QNX Zero to Hero course from Markdown to PDF.
#
# See docs/guides/PDF_Export.md for dependency installation and troubleshooting.
#
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DOCS="$REPO_ROOT/docs"
BUILD="$REPO_ROOT/build"
PDF_OUT="$BUILD/pdf"
TEMPLATE="$REPO_ROOT/tools/pdf/eisvogel.latex"
METADATA="$REPO_ROOT/tools/pdf/metadata.yaml"
TEMPLATE_URL="https://raw.githubusercontent.com/Wandmalfarbe/pandoc-latex-template/master/template/eisvogel.latex"

USE_MERMAID=1
BUILD_BOOK=1
BUILD_CHAPTERS=1
WITH_TOC=1
PAPER="a4"
OPEN_AFTER=0
SINGLE_FILE=""
CHECK_ONLY=0

GREEN=$'\033[0;32m'; RED=$'\033[0;31m'; YELLOW=$'\033[0;33m'; BOLD=$'\033[1m'; NC=$'\033[0m'
info()  { printf '%s==>%s %s\n' "$BOLD" "$NC" "$*"; }
ok()    { printf '  %s✅%s %s\n' "$GREEN" "$NC" "$*"; }
warn()  { printf '  %s⚠️ %s %s\n' "$YELLOW" "$NC" "$*"; }
fail()  { printf '  %s❌%s %s\n' "$RED" "$NC" "$*"; }

usage() {
    sed -n '2,8p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'
    cat <<'EOF'

Usage: ./tools/build-pdf.sh [options] [file.md]

Options:
  --check            Verify dependencies and exit
  --book-only        Build only the combined book
  --chapters-only    Build only per-file PDFs
  --no-mermaid       Skip Mermaid diagram rendering (much faster)
  --no-toc           Omit the generated table of contents
  --paper <a4|letter>  Page size (default: a4)
  --open             Open the book PDF when finished
  -h, --help         Show this help
EOF
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --check)          CHECK_ONLY=1 ;;
        --book-only)      BUILD_CHAPTERS=0 ;;
        --chapters-only)  BUILD_BOOK=0 ;;
        --no-mermaid)     USE_MERMAID=0 ;;
        --no-toc)         WITH_TOC=0 ;;
        --paper)          PAPER="$2"; shift ;;
        --open)           OPEN_AFTER=1 ;;
        -h|--help)        usage; exit 0 ;;
        *.md)             SINGLE_FILE="$1"; BUILD_BOOK=0 ;;
        *)                fail "Unknown option: $1"; usage; exit 1 ;;
    esac
    shift
done

# ---------------------------------------------------------------- dependencies

fetch_template() {
    [[ -f "$TEMPLATE" ]] && return 0
    info "Downloading the Eisvogel template..."
    mkdir -p "$(dirname "$TEMPLATE")"
    if curl -fsSL -o "$TEMPLATE" "$TEMPLATE_URL"; then
        ok "Eisvogel template downloaded"
    else
        fail "Could not download the Eisvogel template. See docs/guides/PDF_Export.md §4."
        return 1
    fi
}

check_deps() {
    local missing=0
    info "QNX Zero to Hero — PDF toolchain check"

    if command -v pandoc >/dev/null; then
        local v; v="$(pandoc --version | head -1 | awk '{print $2}')"
        if [[ "${v%%.*}" -lt 3 ]]; then
            warn "pandoc $v — version 3.x or newer recommended (see PDF_Export.md §3.2)"
        else
            ok "pandoc $v"
        fi
    else
        fail "pandoc — install with: sudo apt install -y pandoc"; missing=1
    fi

    if command -v xelatex >/dev/null; then
        ok "xelatex $(xelatex --version | head -1 | sed 's/.*(\(.*\))/\1/')"
    else
        fail "xelatex — install with: sudo apt install -y texlive-xetex texlive-latex-extra"; missing=1
    fi

    if [[ -f "$TEMPLATE" ]]; then
        ok "eisvogel.latex  ${TEMPLATE#"$REPO_ROOT"/}"
    else
        warn "eisvogel.latex missing — will be downloaded automatically"
    fi

    if [[ $USE_MERMAID -eq 1 ]]; then
        command -v mmdc           >/dev/null && ok "mmdc $(mmdc --version 2>/dev/null || echo '?')" \
            || { warn "mmdc missing — diagrams will not render (use --no-mermaid to silence)"; }
        command -v mermaid-filter >/dev/null && ok "mermaid-filter $(command -v mermaid-filter)" \
            || { warn "mermaid-filter missing — sudo npm install -g mermaid-filter"; }
    else
        warn "Mermaid rendering disabled (--no-mermaid)"
    fi

    if fc-list 2>/dev/null | grep -qi "noto color emoji"; then
        ok "emoji font — Noto Color Emoji"
    else
        warn "Noto Color Emoji not found — path markers (🐣🚶🏃) may render as boxes"
        warn "  fix: sudo apt install -y fonts-noto-color-emoji"
    fi

    if [[ $missing -eq 1 ]]; then
        fail "Missing required dependencies. See docs/guides/PDF_Export.md §3."
        return 1
    fi
    ok "All required dependencies present."
}

# ------------------------------------------------------------------ conversion

pandoc_args() {
    local args=(
        --from=gfm+yaml_metadata_block+footnotes+pipe_tables+task_lists
        --template="$TEMPLATE"
        --pdf-engine=xelatex
        --listings
        --highlight-style=tango
        --variable=papersize:"$PAPER"
        --variable=geometry:margin=2.4cm
        --variable=colorlinks:true
        --variable=linkcolor:NavyBlue
        --variable=urlcolor:NavyBlue
        --variable=toccolor:black
        --variable=titlepage:true
        --variable=titlepage-rule-color:"1E88E5"
        --variable=book:true
        --variable=mainfont:"DejaVu Serif"
        --variable=sansfont:"DejaVu Sans"
        --variable=monofont:"DejaVu Sans Mono"
        --variable=CJKmainfont:"Noto Color Emoji"
        --resource-path="$REPO_ROOT:$DOCS:$BUILD"
    )
    [[ $WITH_TOC -eq 1 ]] && args+=(--toc --toc-depth=3 --number-sections)
    [[ -f "$METADATA" ]] && args+=(--metadata-file="$METADATA")
    if [[ $USE_MERMAID -eq 1 ]] && command -v mermaid-filter >/dev/null; then
        args+=(--filter=mermaid-filter)
    fi
    printf '%s\n' "${args[@]}"
}

convert() {
    local src="$1" dst="$2"
    mapfile -t args < <(pandoc_args)
    if pandoc "${args[@]}" "$src" -o "$dst" 2>"$BUILD/pandoc.log"; then
        ok "$(basename "$dst")"
    else
        fail "$(basename "$src") — see $BUILD/pandoc.log"
        tail -20 "$BUILD/pandoc.log" | sed 's/^/      /'
        return 1
    fi
}

# ------------------------------------------------------------------------ main

if [[ $CHECK_ONLY -eq 1 ]]; then
    fetch_template || true
    check_deps
    exit $?
fi

check_deps
fetch_template

mkdir -p "$PDF_OUT" "$BUILD/mermaid-images"
export MERMAID_FILTER_FORMAT="png"
export MERMAID_FILTER_THEME="default"
if [[ ! -f "$REPO_ROOT/.puppeteer.json" ]]; then
    echo '{"args": ["--no-sandbox", "--disable-setuid-sandbox"]}' > "$REPO_ROOT/.puppeteer.json"
fi
export MERMAID_FILTER_PUPPETEER_CONFIG_FILE="$REPO_ROOT/.puppeteer.json"

if [[ -n "$SINGLE_FILE" ]]; then
    [[ -f "$SINGLE_FILE" ]] || { fail "No such file: $SINGLE_FILE"; exit 1; }
    info "Building a single document"
    convert "$SINGLE_FILE" "$PDF_OUT/$(basename "${SINGLE_FILE%.md}").pdf"
    exit 0
fi

# Documents in reading order. Chapters and guides are globbed so new files are
# picked up automatically without editing this script.
#
# ADR-022 — document tiers. This list contains Tier 1 (course) and Tier 2
# (docs/meta bookkeeping) ONLY. Tier 3 lives in docs/internal/ plus the
# root-level PROMPTS.md and COPILOT_PROMPT_HISTORY.md; it is internal working
# material and must never appear in the book. Do not add it here.
mapfile -t ORDERED < <(
    printf '%s\n' \
        "$REPO_ROOT/README.md" \
        "$DOCS/PLAN.md" \
        "$DOCS/TableOfContents.md"
    ls -1 "$DOCS/guides"/Setup_*.md   2>/dev/null || true
    ls -1 "$DOCS/chapters"/Chapter*.md 2>/dev/null || true
    ls -1 "$DOCS/guides"/Hardware_*.md 2>/dev/null || true
    printf '%s\n' \
        "$DOCS/guides/PDF_Export.md" \
        "$DOCS/reference/Glossary.md" \
        "$DOCS/reference/ReferenceLinks.md" \
        "$DOCS/reference/ResourcesMeta.md"
    ls -1 "$DOCS/reference/cheatsheets"/*.md 2>/dev/null || true
    printf '%s\n' \
        "$DOCS/meta/CourseState.md" \
        "$DOCS/meta/Decisions.md" \
        "$DOCS/meta/DecisionsLog.md" \
        "$DOCS/meta/CompactContext.md" \
        "$DOCS/meta/ToDos.md" \
        "$DOCS/meta/Doubts.md"
)

if [[ $BUILD_CHAPTERS -eq 1 ]]; then
    info "Building individual PDFs"
    for f in "${ORDERED[@]}"; do
        [[ -f "$f" ]] || continue
        convert "$f" "$PDF_OUT/$(basename "${f%.md}").pdf" || true
    done
fi

if [[ $BUILD_BOOK -eq 1 ]]; then
    info "Assembling the combined book"
    {
        cat <<EOF
---
title: "QNX: Zero to Hero"
subtitle: "A Complete Hands-On Course on the QNX Real-Time Operating System"
author: "Course repository: github.com/Tyrostir/qnx-zero-to-hero"
date: "$(date +%Y-%m-%d)"
lang: en
titlepage: true
titlepage-color: "0D1B2A"
titlepage-text-color: "FFFFFF"
titlepage-rule-color: "1E88E5"
toc-own-page: true
book: true
classoption: [oneside]
---

EOF
        for f in "${ORDERED[@]}"; do
            [[ -f "$f" ]] || continue
            # Strip per-file YAML front matter so only the book's own header survives.
            awk 'BEGIN{fm=0} NR==1 && /^---[[:space:]]*$/ {fm=1; next} fm==1 && /^---[[:space:]]*$/ {fm=0; next} fm==0 {print}' "$f"
            printf '\n\n\\newpage\n\n'
        done
    } > "$BUILD/book.md"

    convert "$BUILD/book.md" "$PDF_OUT/QNX-Zero-to-Hero.pdf"
fi

info "Done. Output in ${PDF_OUT#"$REPO_ROOT"/}/"
ls -1sh "$PDF_OUT" 2>/dev/null | sed 's/^/  /'

if [[ $OPEN_AFTER -eq 1 && -f "$PDF_OUT/QNX-Zero-to-Hero.pdf" ]]; then
    (xdg-open "$PDF_OUT/QNX-Zero-to-Hero.pdf" >/dev/null 2>&1 &) || true
fi
