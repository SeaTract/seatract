CC = gcc
CFLAGS = -I./include -Wall -Wextra
EXAMPLES_DIR = examples
SOURCES = $(wildcard $(EXAMPLES_DIR)/*.c)
BINS = $(SOURCES:.c=)

all: $(BINS)

$(EXAMPLES_DIR)/%: $(EXAMPLES_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)
