# HEXI - Usage Examples

This document provides comprehensive examples of using hexi for various scenarios.

## Table of Contents
- [Basic Conversions](#basic-conversions)
- [Formatting Options](#formatting-options)
- [Input Formats](#input-formats)
- [Interactive Mode](#interactive-mode)
- [Batch Processing](#batch-processing)
- [Real-World Scenarios](#real-world-scenarios)

## Basic Conversions

### Simple decimal to hex
```bash
$ ./hexi 42
2a
```

### Multiple numbers
```bash
$ ./hexi 10 20 30 40 50
a 14 1e 28 32
```

### Large numbers
```bash
$ ./hexi 1000000
f4240
```

### Negative numbers
```bash
$ ./hexi -100
ffffffffffffff9c
```

## Formatting Options

### Uppercase output
```bash
$ ./hexi -u 255 256 1024
FF 100 400
```

### With 0x prefix
```bash
$ ./hexi -p 10 20 30
0xa 0x14 0x1e
```

### Uppercase with prefix
```bash
$ ./hexi -u -p 255
0xFF
```

### Fixed width (padding)
```bash
$ ./hexi -w 4 10 20 30
000a 0014 001e
```

### Width with prefix
```bash
$ ./hexi -w 8 -p 42
0x0000002a
```

### Custom separator
```bash
$ ./hexi -c 10 20 30
a,14,1e

$ ./hexi -s ":" 10 20 30
a:14:1e

$ ./hexi -s " | " 10 20 30
a | 14 | 1e
```

## Input Formats

### Decimal (default)
```bash
$ ./hexi 255
ff
```

### Hexadecimal input (0x prefix)
```bash
$ ./hexi 0xFF
ff

$ ./hexi 0x100
100
```

### Octal input (0 prefix)
```bash
$ ./hexi 0377
ff

$ ./hexi 0755
1ed
```

### Binary input (0b prefix)
```bash
$ ./hexi 0b11111111
ff

$ ./hexi 0b1010
a
```

### Mixed formats
```bash
$ ./hexi 255 0xFF 0377 0b11111111
ff ff ff ff
```

## Multiple Representations

### Show binary
```bash
$ ./hexi -b 255
Number 1:
Decimal:     255
Hexadecimal: ff
Binary:      0b1111 1111
```

### Show octal
```bash
$ ./hexi -o 255
Number 1:
Decimal:     255
Hexadecimal: ff
Octal:       0377
```

### Show all formats
```bash
$ ./hexi -b -o 255
Number 1:
Decimal:     255
Hexadecimal: ff
Octal:       0377
Binary:      0b1111 1111
```

### Multiple numbers with all formats
```bash
$ ./hexi -b -o -u 10 20 30
Number 1:
Decimal:     10
Hexadecimal: A
Octal:       012
Binary:      0b1010

Number 2:
Decimal:     20
Hexadecimal: 14
Octal:       024
Binary:      0b1 0100

Number 3:
Decimal:     30
Hexadecimal: 1E
Octal:       036
Binary:      0b1 1110
```

## Interactive Mode

### Basic interactive session
```bash
$ ./hexi -i

╔═══════════════════════════════════════════════════════════╗
║           HEXI - Integer to Hexadecimal Converter        ║
║                      Version 2.0.0                        ║
║              © 2022-2026 YUNUS EMRE VURGUN                ║
╚═══════════════════════════════════════════════════════════╝

Interactive Mode - Enter numbers to convert (or 'q' to quit)
Supported formats: decimal, 0x (hex), 0 (octal), 0b (binary)

hexi> 255
Decimal:     255
Hexadecimal: ff

hexi> 0xFF00
Decimal:     65280
Hexadecimal: ff00

hexi> 0b1010
Decimal:     10
Hexadecimal: a

hexi> quit
Goodbye!
```

### Interactive with options
```bash
$ ./hexi -i -u -b -o
hexi> 42
Decimal:     42
Hexadecimal: 2A
Octal:       052
Binary:      0b10 1010
```

## Batch Processing

### Create a numbers file
```bash
$ cat > numbers.txt << EOF
# RGB color values
255
128
64
# Hex values
0xFF00
0x00FF
# Binary
0b11111111
EOF
```

### Process the file
```bash
$ ./hexi -f numbers.txt
ff 80 40 ff00 ff ff
```

### Process with formatting
```bash
$ ./hexi -f numbers.txt -u -p -w 4
0x00FF 0x0080 0x0040 0xFF00 0x00FF 0x00FF
```

### Process and show all formats
```bash
$ ./hexi -f numbers.txt -b -o
Number 1:
Decimal:     255
Hexadecimal: ff
Octal:       0377
Binary:      0b1111 1111

Number 2:
Decimal:     128
Hexadecimal: 80
Octal:       0200
Binary:      0b1000 0000
...
```

## Real-World Scenarios

### 1. RGB Color Conversion
```bash
# Convert RGB values to hex color code
$ ./hexi -u -w 2 255 128 64
FF 80 40
# Result: #FF8040
```

### 2. File Permissions
```bash
# Convert octal permissions to hex
$ ./hexi 0644 0755 0777
1a4 1ed 1ff
```

### 3. Memory Addresses
```bash
# Format memory addresses
$ ./hexi -u -p -w 8 1024 2048 4096
0x00000400 0x00000800 0x00001000
```

### 4. Bit Flags Analysis
```bash
# Analyze bit flags
$ ./hexi -b 0x0F
Number 1:
Decimal:     15
Hexadecimal: f
Binary:      0b1111
```

### 5. Network Subnet Calculation
```bash
# Convert IP address octets
$ ./hexi 192 168 1 1
c0 a8 1 1
# Result: C0.A8.01.01
```

### 6. ASCII Character Codes
```bash
# Convert ASCII codes to hex
$ ./hexi 65 66 67  # A, B, C
41 42 43
```

### 7. Unicode Code Points
```bash
# Convert Unicode code points
$ ./hexi -u -p 0x1F600  # 😀 emoji
0x1F600
```

### 8. Debugging Binary Data
```bash
# Analyze binary patterns
$ ./hexi -b -o 0b10101010
Number 1:
Decimal:     170
Hexadecimal: aa
Octal:       0252
Binary:      0b1010 1010
```

### 9. Checksum Verification
```bash
# Convert checksum values
$ ./hexi -u -w 4 0xABCD 0x1234
ABCD 1234
```

### 10. Batch Color Palette
```bash
# Create a color palette file
$ cat > palette.txt << EOF
# Material Design Red
244
67
54
# Material Design Blue
33
150
243
EOF

$ ./hexi -f palette.txt -u -w 2 -c
F4,43,36,21,96,F3
# Result: #F44336 and #2196F3
```

## Scripting Examples

### Bash script for RGB to hex color
```bash
#!/bin/bash
# rgb2hex.sh - Convert RGB to hex color code

if [ $# -ne 3 ]; then
    echo "Usage: $0 <R> <G> <B>"
    exit 1
fi

echo -n "#"
./hexi -u -w 2 $1 $2 $3 | tr -d ' '
echo
```

### Python integration
```python
import subprocess

def dec_to_hex(numbers):
    result = subprocess.run(
        ['./hexi', '-u', '-p'] + [str(n) for n in numbers],
        capture_output=True,
        text=True
    )
    return result.stdout.strip().split()

# Usage
print(dec_to_hex([255, 256, 1024]))
# Output: ['0xFF', '0x100', '0x400']
```

### Pipe from other commands
```bash
# Convert process IDs to hex
$ ps aux | awk 'NR>1 {print $2}' | head -5 | xargs ./hexi -u -p
0x1 0x2 0x3 0x4 0x5
```

## Tips and Tricks

### Quick color code
```bash
# Create an alias for RGB to hex
alias rgb2hex='hexi -u -w 2 | tr -d " " | sed "s/^/#/"'

# Usage
$ echo "255 128 64" | xargs rgb2hex
#FF8040
```

### Hex calculator
```bash
# Use interactive mode as a hex calculator
$ ./hexi -i -u -p
hexi> 256
0x100
hexi> 0x100
0x100
```

### Batch conversion with formatting
```bash
# Convert and format in one line
$ seq 1 16 | xargs ./hexi -u -w 2 -c
01,02,03,04,05,06,07,08,09,0A,0B,0C,0D,0E,0F,10
```

---

For more information, run `./hexi --help` or check the [README.md](README.md).
