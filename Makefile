# Makefile for hexi - Modern Integer to Hexadecimal Converter
# Copyright (c) 2022-2026 YUNUS EMRE VURGUN

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = hexi
SOURCE = hexi.c

# Platform detection
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q
else
    RM = rm -f
endif

.PHONY: all clean install uninstall test help

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "Build complete! Run './$(TARGET) --help' for usage information."

clean:
	$(RM) $(TARGET)
	@echo "Clean complete."

install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/
	@sudo chmod 755 /usr/local/bin/$(TARGET)
	@echo "Installation complete! You can now run 'hexi' from anywhere."

uninstall:
	@echo "Uninstalling $(TARGET) from /usr/local/bin..."
	@sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstallation complete."

test: $(TARGET)
	@echo "Running tests..."
	@echo ""
	@echo "Test 1: Basic conversion"
	@./$(TARGET) 12 13 14 15 16
	@echo ""
	@echo "Test 2: Uppercase with prefix"
	@./$(TARGET) -u -p 255 256 1024
	@echo ""
	@echo "Test 3: Width formatting"
	@./$(TARGET) -w 8 -p 42
	@echo ""
	@echo "Test 4: Binary and octal output"
	@./$(TARGET) -b -o 255
	@echo ""
	@echo "Test 5: Hex input"
	@./$(TARGET) 0xFF 0x100
	@echo ""
	@echo "Test 6: Binary input"
	@./$(TARGET) 0b1010 0b11111111
	@echo ""
	@echo "All tests complete!"

help:
	@echo "Makefile for hexi - Integer to Hexadecimal Converter"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Build the hexi executable"
	@echo "  make clean    - Remove built files"
	@echo "  make install  - Install hexi to /usr/local/bin (requires sudo)"
	@echo "  make uninstall- Remove hexi from /usr/local/bin (requires sudo)"
	@echo "  make test     - Run basic functionality tests"
	@echo "  make help     - Show this help message"
