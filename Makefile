CC = gcc
CFLAGS = -I./include -Wall -Wextra
CFLAGS_STRIP= -DNDEBUG

EXAMPLES_DIR = examples
SOURCES = $(wildcard $(EXAMPLES_DIR)/*.c)
BINS = $(SOURCES:.c=)
	BINS_STRIPPED = $(SOURCES:.c=_stripped)
#SOURCES_VALID = $(wildcard $(EXAMPLES_DIR)/*_valid.c)
SOURCES_VALID = $(shell ls $(EXAMPLES_DIR)/*_valid.c)
BINS_VALID = $(SOURCES_VALID:.c=)
CHECKMAKE=go run github.com/checkmake/checkmake/cmd/checkmake@latest




.PHONY: all
all: build build.stripped
.PHONY: build
build: examples
.PHONY: examples
examples:$(BINS)
.PHONY:build.stripped
build.stripped: examples.stripped
.PHONY: examples.stripped

examples.stripped: $(BINS_STRIPPED)
$(EXAMPLES_DIR)/%_stripped: $(EXAMPLES_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $(CFLAGS_STRIP) $< -o $@

$(EXAMPLES_DIR)/%: $(EXAMPLES_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(BINS) $(BINS_STRIPPED)

.PHONY: makeckmake
checkmake: ## lint the Makefile with checkmake.
	@$(CHECKMAKE) Makefile

.PHONY: check
check: checkmake

.PHONY: run.examples.valid
run.examples.valid: $(BINS_VALID)
	@for cmd in $(BINS_VALID); do $$cmd ;  done

.PHONY: test
test: clean all check run.examples.valid
