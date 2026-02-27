# HEXI - Live Demonstration

## Quick Start Demo

### 1. Default Mode (Backward Compatible)
```bash
$ ./hexi

╔═══════════════════════════════════════════════════════════╗
║           HEXI - Integer to Hexadecimal Converter        ║
║                      Version 2.0.0                        ║
║              © 2022-2026 YUNUS EMRE VURGUN                ║
╚═══════════════════════════════════════════════════════════╝

Welcome to HEXI - Integer to Hexadecimal Converter!

Converting example values: 12, 13, 14, 15, 16

Decimal:     12, 13, 14, 15, 16
Hexadecimal: 0x0c, 0x0d, 0x0e, 0x0f, 0x10

Try running with your own numbers!
Example: ./hexi 255 256 1024
For more options, use: ./hexi --help
```

### 2. Basic Conversion
```bash
$ ./hexi 255 256 1024
ff 100 400
```

### 3. Uppercase with Prefix
```bash
$ ./hexi -u -p 255 256 1024
0xFF 0x100 0x400
```

### 4. Formatted Output (Width)
```bash
$ ./hexi -w 8 -p 42
0x0000002a
```

### 5. Multiple Representations
```bash
$ ./hexi -b -o 255
Number 1:
Decimal:     255
Hexadecimal: ff
Octal:       0377
Binary:      0b1111 1111
```

### 6. Different Input Formats
```bash
$ ./hexi 255 0xFF 0377 0b11111111
ff ff ff ff
```

### 7. Custom Separators
```bash
$ ./hexi -c 10 20 30 40
a,14,1e,28

$ ./hexi -s ":" 10 20 30 40
a:14:1e:28
```

### 8. Batch File Processing
```bash
$ cat numbers.txt
255
0xFF
0b11111111
0377

$ ./hexi -f numbers.txt -u -p
0xFF 0xFF 0xFF 0xFF
```

### 9. Interactive Mode
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

## Real-World Examples

### RGB Color to Hex
```bash
$ ./hexi -u -w 2 255 128 64
FF 80 40
# Result: #FF8040
```

### Memory Addresses
```bash
$ ./hexi -u -p -w 8 1024 2048 4096
0x00000400 0x00000800 0x00001000
```

### File Permissions
```bash
$ ./hexi 0644 0755 0777
1a4 1ed 1ff
```

### ASCII Character Codes
```bash
$ ./hexi 65 66 67 68 69
41 42 43 44 45
# A B C D E
```

### Bit Pattern Analysis
```bash
$ ./hexi -b 0xAA
Number 1:
Decimal:     170
Hexadecimal: aa
Binary:      0b1010 1010
```

### Network Addresses
```bash
$ ./hexi 192 168 1 1
c0 a8 1 1
# C0.A8.01.01
```

## Feature Showcase

### All Options Combined
```bash
$ ./hexi -u -p -w 4 -b -o 42
Number 1:
Decimal:     42
Hexadecimal: 002A
Octal:       052
Binary:      0b10 1010
```

### Help System
```bash
$ ./hexi --help
[Shows comprehensive help with all options and examples]

$ ./hexi --version
hexi version 2.0.0
Copyright (c) 2022-2026 YUNUS EMRE VURGUN
Licensed under MIT License
```

### Error Handling
```bash
$ ./hexi invalid
Error: Invalid number 'invalid'

$ ./hexi -f nonexistent.txt
Error: Cannot open file 'nonexistent.txt': No such file or directory
```

## Build and Test

### Building
```bash
$ make
gcc -Wall -Wextra -O2 -std=c11 -o hexi hexi.c
Build complete! Run './hexi --help' for usage information.
```

### Testing
```bash
$ make test
Running tests...

Test 1: Basic conversion
c d e f 10

Test 2: Uppercase with prefix
0xFF 0x100 0x400

Test 3: Width formatting
0x0000002a

Test 4: Binary and octal output
Number 1:
Decimal:     255
Hexadecimal: ff
Octal:       0377
Binary:      0b1111 1111

Test 5: Hex input
ff 100

Test 6: Binary input
a ff

All tests complete!
```

### Installation
```bash
$ sudo make install
Installing hexi to /usr/local/bin...
Installation complete! You can now run 'hexi' from anywhere.

$ hexi 42
2a
```

## Comparison: Before vs After

### Before (Version 1.0)
```c
// hexi.c - Had to edit this file
int array[]={12,13,14,15,16};  // Change values here
hexi(array, 5);                // Recompile every time
```

**Output:**
```
0000000c 0000000d 0000000e 0000000f 00000010
```

### After (Version 2.0)
```bash
# Just use command line - no recompilation needed!
$ ./hexi 12 13 14 15 16
c d e f 10

# Want different format? Just add flags!
$ ./hexi -u -p 12 13 14 15 16
0xC 0xD 0xE 0xF 0x10

# Need to explore? Use interactive mode!
$ ./hexi -i
hexi> 12
Decimal:     12
Hexadecimal: c

# Processing many numbers? Use a file!
$ ./hexi -f mydata.txt
```

## Performance

### Speed Test
```bash
# Convert 1000 numbers instantly
$ seq 1 1000 | xargs ./hexi > /dev/null
# Completes in milliseconds
```

### Memory Efficiency
```bash
# Supports up to 1000 numbers in one command
$ ./hexi $(seq 1 1000) | wc -w
1000
```

## Integration Examples

### Bash Script
```bash
#!/bin/bash
# rgb2hex.sh
echo -n "#"
./hexi -u -w 2 $1 $2 $3 | tr -d ' '
echo

# Usage: ./rgb2hex.sh 255 128 64
# Output: #FF8040
```

### Python Integration
```python
import subprocess

def to_hex(numbers):
    result = subprocess.run(
        ['./hexi', '-u', '-p'] + [str(n) for n in numbers],
        capture_output=True, text=True
    )
    return result.stdout.strip().split()

print(to_hex([255, 256, 1024]))
# ['0xFF', '0x100', '0x400']
```

### Pipe Usage
```bash
# Convert process IDs
$ ps aux | awk 'NR>1 {print $2}' | head -5 | xargs ./hexi -u -p

# Convert from calculation
$ echo $((256 * 256)) | xargs ./hexi
10000
```

## Tips and Tricks

### Quick Aliases
```bash
# Add to ~/.bashrc or ~/.zshrc
alias hex='hexi -u -p'
alias hexw='hexi -u -p -w 8'
alias hexi='hexi -i'

# Usage
$ hex 255
0xFF

$ hexw 42
0x0000002A
```

### Color Code Converter
```bash
# Create a function
rgb2hex() {
    echo -n "#"
    hexi -u -w 2 $1 $2 $3 | tr -d ' '
    echo
}

# Usage
$ rgb2hex 255 128 64
#FF8040
```

### Batch Processing
```bash
# Convert all numbers in a file
$ cat data.txt | xargs ./hexi -u -p -c > output.txt
```

## Summary

HEXI 2.0 transforms a simple educational tool into a professional, production-ready utility:

✅ **Easy to Use** - Intuitive command-line interface
✅ **Flexible** - Multiple input/output formats
✅ **Powerful** - Batch processing and interactive mode
✅ **Professional** - Comprehensive documentation and error handling
✅ **Fast** - Optimized C implementation
✅ **Portable** - Works on Linux, macOS, Windows

**Try it now:**
```bash
./hexi --help
./hexi -i
./hexi 255 256 1024
```

---

For more information, see:
- [README.md](README.md) - Full documentation
- [EXAMPLES.md](EXAMPLES.md) - More examples
- [CONTRIBUTING.md](CONTRIBUTING.md) - How to contribute
