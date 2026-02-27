# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.0.0] - 2026-02-27

### Added
- **Interactive Mode** (`-i` flag): REPL-style interface for quick conversions
- **Multiple Input Formats**: Support for decimal, hexadecimal (0x), octal (0), and binary (0b)
- **Multiple Output Formats**: 
  - Binary representation (`-b` flag)
  - Octal representation (`-o` flag)
  - Uppercase hexadecimal (`-u` flag)
  - 0x prefix option (`-p` flag)
- **Batch Processing**: Read numbers from files (`-f` flag)
- **Flexible Formatting**:
  - Custom width with zero-padding (`-w` flag)
  - Custom separators (`-s` flag)
  - Comma separator option (`-c` flag)
- **Command-line Arguments**: Full argument parsing for dynamic input
- **Help System**: Comprehensive help (`--help`) and version (`--version`) information
- **Error Handling**: Robust input validation and error messages
- **Professional UI**: Beautiful banner and formatted output
- **Build System**: Makefile with install, uninstall, test, and clean targets
- **Documentation**:
  - Comprehensive README.md
  - EXAMPLES.md with real-world use cases
  - CONTRIBUTING.md for contributors
  - CHANGELOG.md for version tracking
- **Git Integration**: .gitignore file for clean repository

### Changed
- Complete rewrite in modern C11 standard
- Improved code organization and structure
- Better function naming and modularity
- Enhanced user experience with clear messages
- Professional formatting and output

### Improved
- Memory efficiency with proper bounds checking
- Cross-platform compatibility
- Code readability and maintainability
- Error messages with context
- Input parsing with multiple format support

### Technical Details
- Uses `strtoll()` for robust number parsing
- Supports long long integers (64-bit)
- Proper errno handling for edge cases
- Modular design with separate functions for each feature
- Configuration struct for clean option management

## [1.0.0] - 2022

### Initial Release
- Basic integer to hexadecimal conversion
- Hardcoded array of 5 integers (12, 13, 14, 15, 16)
- Simple console output
- MIT License

---

## Migration Guide from 1.0 to 2.0

### Breaking Changes
None! Version 2.0 is fully backward compatible. The original functionality is preserved in the default mode.

### New Features You Can Use

#### Before (v1.0):
```c
// Had to modify source code and recompile
int array[]={12,13,14,15,16};
```

#### After (v2.0):
```bash
# Just pass numbers as arguments
./hexi 12 13 14 15 16

# Or use interactive mode
./hexi -i

# Or read from a file
./hexi -f numbers.txt
```

### Recommended Workflow

1. **Quick Conversions**: Use command-line arguments
   ```bash
   ./hexi 255 256 1024
   ```

2. **Exploring Numbers**: Use interactive mode
   ```bash
   ./hexi -i
   ```

3. **Batch Processing**: Use file input
   ```bash
   ./hexi -f data.txt
   ```

4. **Formatted Output**: Combine flags
   ```bash
   ./hexi -u -p -w 8 42
   ```

---

## Future Plans

### Version 2.1.0 (Planned)
- [ ] JSON output format
- [ ] Configuration file support (~/.hexirc)
- [ ] Shell completion scripts (bash, zsh, fish)
- [ ] Color output support
- [ ] Pipe input support (stdin)

### Version 2.2.0 (Planned)
- [ ] Arithmetic operations in interactive mode
- [ ] History support in interactive mode
- [ ] Expression evaluation (e.g., "255 + 1")
- [ ] Bitwise operations display

### Version 3.0.0 (Future)
- [ ] Arbitrary precision number support
- [ ] Floating-point number conversion
- [ ] GUI version
- [ ] Web version (WebAssembly)
- [ ] Language bindings (Python, Node.js, etc.)

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute to this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Original concept by YUNUS EMRE VURGUN (2022)
- Modern rewrite and enhancements (2026)
- Community feedback and contributions

---

**Note**: This changelog follows the [Keep a Changelog](https://keepachangelog.com/) format.
For the full commit history, see the git log.
