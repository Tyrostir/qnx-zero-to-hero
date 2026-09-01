# Lab 08 — the QNX development loop
# QNX: Zero to Hero, Chapter 08 (core lab L08)
#
# One command to build, deploy, run or debug:
#
#   make                 build, and check it really is a QNX binary
#   make TGT=<ip> run    build + deploy + run on the target
#   make TGT=<ip> debug  build + deploy + launch gdb, connected to qconn
#   make clean
#
# Requires the SDP environment:  source ~/qnx800/qnxsdp-env.sh
#
# The dependency chain (run -> deploy -> avg) is the point: it makes running a
# STALE binary structurally impossible. See Chapter 08 section 4.3.

CC     := qcc
GDB    := ntox86_64-gdb
TARGET := -Vgcc_ntox86_64
CFLAGS := -g -O0 -Wall -Wextra

# Override on the command line:  make TGT=192.168.122.46 run
TGT    ?= 192.168.122.46
USER   ?= qnxuser
# /data is the writable PARTITION, but its root is owned by root -- qnxuser
# cannot create files there. Deploy into the user's home, which lives on /data
# and so persists across reboots. See D-015.
DEST   ?= /data/home/$(USER)
# Default to the SKELETON -- the buggy program you debug in Lab 08.1.
# Build the fixed one with:  make SRC=solution/avg.c run
SRC    ?= skeleton/avg.c
BIN    := avg

.PHONY: all deploy run debug release clean check-env

all: check-env $(BIN)

check-env:
	@command -v $(CC) >/dev/null 2>&1 || { \
	  echo "ERROR: qcc not found. Run: source ~/qnx800/qnxsdp-env.sh"; exit 1; }

$(BIN): $(SRC)
	$(CC) $(TARGET) $(CFLAGS) -o $@ $<
	@# Catch Chapter 05 section 5.3's silent failure: a working binary for the
	@# wrong OS. Checks BOTH the QNX interpreter and the architecture.
	@if file $@ | grep -q 'ldqnx' && file $@ | grep -q 'x86-64'; then \
	   echo "OK: QNX x86_64 binary"; \
	 else \
	   echo "WARNING: not a QNX x86_64 binary -- check -V and \$$QNX_TARGET"; \
	   file $@; \
	 fi

deploy: $(BIN)
	scp $(BIN) $(USER)@$(TGT):$(DEST)/
	ssh $(USER)@$(TGT) 'chmod +x $(DEST)/$(BIN)'

run: deploy
	ssh $(USER)@$(TGT) '$(DEST)/$(BIN)'

debug: deploy
	$(GDB) -ex "target qnx $(TGT):8000" $(BIN)

# Release build: optimised, no debug info, stripped.
# Compare its size with the debug build -- that difference is why Chapter 05's
# .sym files exist.
release: $(SRC)
	$(CC) $(TARGET) -O2 -Wall -o $(BIN)-rel $<
	ntox86_64-strip $(BIN)-rel
	@ls -l $(BIN) $(BIN)-rel 2>/dev/null || true

clean:
	rm -f $(BIN) $(BIN)-rel
