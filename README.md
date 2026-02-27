# HEXI - Modern Integer to Hexadecimal Converter

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-2.0.0-blue.svg)](https://github.com/yourusername/hexi)

A modern, feature-rich command-line tool for converting integers to hexadecimal and other number formats. Written in C for maximum performance and portability.

## ✨ Features

- 🔢 **Multiple Input Formats**: Decimal, hexadecimal (0x), octal (0), and binary (0b)
- 🎨 **Flexible Output**: Uppercase/lowercase, with/without prefix, custom width
- 🔄 **Multiple Representations**: Show binary, octal, and hexadecimal simultaneously
- 💻 **Interactive Mode**: REPL-style interface for quick conversions
- 📁 **Batch Processing**: Read numbers from files
- ⚡ **Fast & Lightweight**: Pure C implementation with no dependencies
- 🎯 **User-Friendly**: Clear error messages and helpful documentation

## 🚀 Quick Start

### Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/hexi.git
cd hexi

# Build
make

# Optional: Install system-wide
sudo make install
```

### Basic Usage

```bash
# Convert decimal numbers to hex
./hexi 12 13 14 15 16
# Output: c d e f 10

# Uppercase with 0x prefix
./hexi -u -p 255 256 1024
# Output: 0xFF 0x100 0x400

# Show all representations
./hexi -b -o 255
# Output:
# Decimal:     255
# Hexadecimal: ff
# Octal:       0377
# Binary:      0b1111 1111
```

## 📖 Usage

### Command Line Options

```
USAGE:
  hexi [OPTIONS] [NUMBERS...]

OPTIONS:
  -h, --help              Show help message
  -v, --version           Show version information
  -i, --interactive       Run in interactive mode
  -u, --uppercase         Output in uppercase hexadecimal
  -p, --prefix            Add '0x' prefix to output
  -w, --width <N>         Set output width (padding with zeros)
  -b, --binary            Also show binary representation
  -o, --octal             Also show octal representation
  -f, --file <PATH>       Read numbers from file (one per line)
  -s, --separator <CHAR>  Set separator character (default: space)
  -c, --comma             Use comma as separator
```

### Examples

#### Basic Conversion
```bash
./hexi 42
# Output: 2a
```

#### Formatted Output
```bash
./hexi -u -p -w 8 42
# Output: 0x0000002A
```

#### Multiple Formats
```bash
./hexi -b -o 255
# Output:
# Decimal:     255
# Hexadecimal: ff
# Octal:       0377
# Binary:      0b1111 1111
```

#### Interactive Mode
```bash
./hexi -i
# Starts interactive REPL:
# hexi> 255
# Decimal:     255
# Hexadecimal: ff
# hexi> 0b1010
# Decimal:     10
# Hexadecimal: a
# hexi> quit
```

#### Batch Processing
```bash
# Create a file with numbers
echo -e "255\n256\n1024\n0xFF00" > numbers.txt

# Process the file
./hexi -f numbers.txt -u -p
# Output: 0xFF 0x100 0x400 0xFF00
```

#### Different Input Formats
```bash
# Decimal
./hexi 255

# Hexadecimal (0x prefix)
./hexi 0xFF

# Octal (0 prefix)
./hexi 0377

# Binary (0b prefix)
./hexi 0b11111111

# All produce the same output: ff
```

#### Custom Separators
```bash
./hexi -c 10 20 30
# Output: a,14,1e

./hexi -s ":" 10 20 30
# Output: a:14:1e
```

## 🎯 Use Cases

### For Developers
- Quick hex conversions during debugging
- Converting memory addresses
- Working with color codes
- Bit manipulation verification

### For Students
- Learning number systems
- Understanding binary/hex/octal relationships
- Computer science homework

### For System Administrators
- Converting file permissions (octal to hex)
- Working with network addresses
- Analyzing system logs

## 🔧 Building from Source

### Requirements
- GCC or any C11-compatible compiler
- Make (optional, for using Makefile)

### Manual Build
```bash
gcc -Wall -Wextra -O2 -std=c11 -o hexi hexi.c
```

### Using Make
```bash
# Build
make

# Run tests
make test

# Clean build artifacts
make clean

# Install system-wide (Linux/macOS)
sudo make install

# Uninstall
sudo make uninstall
```

## 📝 File Format for Batch Processing

When using the `-f` option, create a text file with one number per line:

```
# This is a comment
255
0xFF
0b11111111
0377
# All the above represent the same number
```

- Lines starting with `#` are treated as comments
- Empty lines are ignored
- Supports all input formats (decimal, hex, octal, binary)

## 🤝 Contributing

Contributions are welcome! Here are some ways you can contribute:

- Report bugs
- Suggest new features
- Submit pull requests
- Improve documentation

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👤 Author

**YUNUS EMRE VURGUN**

- Original version: 2022
- Modern rewrite: 2026

## 🙏 Acknowledgments

- Thanks to all contributors
- Inspired by the need for a simple, fast hex converter

## 📊 Version History

### Version 2.0.0 (2026)
- Complete rewrite with modern C practices
- Added interactive mode
- Support for multiple input/output formats
- Batch processing from files
- Comprehensive error handling
- Extensive documentation

### Version 1.0.0 (2022)
- Initial release
- Basic integer to hex conversion

## 🐛 Known Issues

None at the moment. Please report any issues you find!

## 💡 Tips

1. **Quick conversions**: Use interactive mode (`-i`) for multiple conversions
2. **Debugging**: Use `-b -o` to see all number representations
3. **Scripting**: Pipe numbers to hexi for batch processing
4. **Formatting**: Use `-w` for aligned output in tables

## 📞 Support

If you encounter any problems or have questions:
- Open an issue on GitHub
- Check the documentation with `hexi --help`
- Run tests with `make test`

---

Made with ❤️ by YUNUS EMRE VURGUN
