# Lab 01.2 — jitter measurement
# QNX: Zero to Hero, Chapter 01
#
# Deliberately a plain Makefile calling qcc directly (ADR-007): you should see
# the real command before it is hidden behind QNX's recursive Makefile system,
# which arrives in Chapter 08.
#
# Requires the SDP environment:  source ~/qnx800/qnxsdp-env.sh

CC      := qcc
TARGET  := -Vgcc_ntox86_64
CFLAGS  := -Wall -Wextra -O2
BINS    := solution/jitter skeleton/jitter

.PHONY: all clean solution skeleton check-env

all: check-env solution

solution: solution/jitter
skeleton: skeleton/jitter

check-env:
	@command -v $(CC) >/dev/null 2>&1 || { \
	  echo "ERROR: qcc not found. Run: source ~/qnx800/qnxsdp-env.sh"; exit 1; }

%: %.c
	$(CC) $(TARGET) $(CFLAGS) -o $@ $<
	@echo "built $@ — verify with: file $@"

clean:
	rm -f $(BINS)
