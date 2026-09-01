# Lab 09 — fault isolation
# QNX: Zero to Hero, Chapter 09
#
#   make                  build
#   make TGT=<ip> deploy  build + copy to the target
#   make TGT=<ip> run     build + deploy + run   (it WILL crash -- that is the point)
#   make clean
#
# Requires:  source ~/qnx800/qnxsdp-env.sh

CC     := qcc
TARGET := -Vgcc_ntox86_64
CFLAGS := -g -O0 -Wall -Wextra
TGT    ?= 192.168.122.46
USER   ?= qnxuser
# /data is the writable PARTITION, but its root is owned by root -- qnxuser
# cannot create files there. Deploy into the user's home, which lives on /data
# and so persists across reboots. See D-015.
DEST   ?= /data/home/$(USER)
BIN    := faulter

.PHONY: all deploy run clean check-env

all: check-env $(BIN)

check-env:
	@command -v $(CC) >/dev/null 2>&1 || { \
	  echo "ERROR: qcc not found. Run: source ~/qnx800/qnxsdp-env.sh"; exit 1; }

$(BIN): solution/faulter.c
	$(CC) $(TARGET) $(CFLAGS) -o $@ $<
	@if file $@ | grep -q 'ldqnx' && file $@ | grep -q 'x86-64'; then \
	   echo "OK: QNX x86_64 binary"; \
	 else echo "WARNING: not a QNX x86_64 binary"; file $@; fi

deploy: $(BIN)
	scp $(BIN) $(USER)@$(TGT):$(DEST)/
	ssh $(USER)@$(TGT) 'chmod +x $(DEST)/$(BIN)'

# It exits on a signal, so shield make from the non-zero status: the crash is
# the expected result, not a build failure.
run: deploy
	-ssh $(USER)@$(TGT) '$(DEST)/$(BIN)'
	@echo "--- now check the system from another session: pidin info ---"

clean:
	rm -f $(BIN)
