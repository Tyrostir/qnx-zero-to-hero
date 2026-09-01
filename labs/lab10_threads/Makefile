# Lab 10 -- threads, and what a process actually is
# QNX: Zero to Hero, Chapter 10
#
#   make                                    build threadzoo (solution)
#   make SRC=skeleton/threadzoo.c           build YOUR version
#   make TGT=<ip> deploy                    build + copy to the target
#   make TGT=<ip> run                       build + deploy + run
#   make SRC=solution/forktest.c BIN=forktest TGT=<ip> run     the 💥 Break It
#   make clean
#
# Requires:  source ~/qnx800/qnxsdp-env.sh

CC     := qcc
TARGET := -Vgcc_ntox86_64
CFLAGS := -g -O0 -Wall -Wextra
LDLIBS :=
TGT    ?= 192.168.122.46
USER   ?= qnxuser
# /data is the writable PARTITION, but its root is owned by root -- qnxuser
# cannot create files there. Deploy into the user's home, which lives on /data
# and so persists across reboots. See D-015.
DEST   ?= /data/home/$(USER)
SRC    ?= solution/threadzoo.c
BIN    ?= threadzoo

.PHONY: all deploy run clean check-env

all: check-env $(BIN)

check-env:
	@command -v $(CC) >/dev/null 2>&1 || { \
	  echo "ERROR: qcc not found. Run: source ~/qnx800/qnxsdp-env.sh"; exit 1; }

# On QNX 8 the pthread_* functions live in libc -- there is no separate
# -lpthread to link against, unlike Linux. If your build says otherwise,
# that is a finding: please report it.
$(BIN): $(SRC)
	$(CC) $(TARGET) $(CFLAGS) -o $@ $< $(LDLIBS)
	@if file $@ | grep -q 'ldqnx' && file $@ | grep -q 'x86-64'; then \
	   echo "OK: QNX x86_64 binary"; \
	 else echo "WARNING: not a QNX x86_64 binary"; file $@; fi

deploy: $(BIN)
	scp $(BIN) $(USER)@$(TGT):$(DEST)/
	ssh $(USER)@$(TGT) 'chmod +x $(DEST)/$(BIN)'

run: deploy
	@echo "--- $(BIN) runs until you stop it; open a SECOND session for pidin ---"
	ssh -t $(USER)@$(TGT) '$(DEST)/$(BIN)'

clean:
	rm -f threadzoo forktest stacksize
