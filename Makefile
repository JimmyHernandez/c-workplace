CC ?= gcc
CFLAGS ?= -Wall -Wextra -O2 -Iinclude -g
SRCDIR := src
BINDIR := build
TESTDIR := tests
SRC := $(SRCDIR)/main.c
TEST_SRC := $(TESTDIR)/test_main.c
TARGET := $(BINDIR)/main
TEST_TARGET := $(BINDIR)/test_main

.PHONY: all clean run test
all: $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET): | $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

$(TEST_TARGET): | $(BINDIR)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

run: all
	$(TARGET)

test: $(TEST_TARGET)
	$(TEST_TARGET)

clean:
	rm -rf $(BINDIR)
