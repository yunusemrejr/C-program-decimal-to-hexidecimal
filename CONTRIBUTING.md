# Contributing to HEXI

Thank you for your interest in contributing to HEXI! This document provides guidelines and instructions for contributing.

## Table of Contents
- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Setup](#development-setup)
- [How to Contribute](#how-to-contribute)
- [Coding Standards](#coding-standards)
- [Testing](#testing)
- [Submitting Changes](#submitting-changes)

## Code of Conduct

### Our Pledge
We are committed to providing a welcoming and inspiring community for all. Please be respectful and constructive in your interactions.

### Expected Behavior
- Use welcoming and inclusive language
- Be respectful of differing viewpoints
- Accept constructive criticism gracefully
- Focus on what is best for the community
- Show empathy towards other community members

## Getting Started

### Prerequisites
- GCC or compatible C compiler
- Make (optional but recommended)
- Git
- Basic knowledge of C programming

### Fork and Clone
```bash
# Fork the repository on GitHub, then:
git clone https://github.com/YOUR_USERNAME/hexi.git
cd hexi
git remote add upstream https://github.com/ORIGINAL_OWNER/hexi.git
```

## Development Setup

### Build the Project
```bash
make
```

### Run Tests
```bash
make test
```

### Clean Build Artifacts
```bash
make clean
```

## How to Contribute

### Reporting Bugs
Before creating a bug report, please check existing issues. When creating a bug report, include:

- **Clear title and description**
- **Steps to reproduce**
- **Expected behavior**
- **Actual behavior**
- **System information** (OS, compiler version)
- **Code samples** if applicable

Example:
```markdown
**Bug**: Incorrect output for negative numbers

**Steps to Reproduce**:
1. Run `./hexi -100`
2. Observe output

**Expected**: Proper two's complement hex representation
**Actual**: Incorrect output

**System**: Ubuntu 22.04, GCC 11.3.0
```

### Suggesting Features
Feature suggestions are welcome! Please include:

- **Clear description** of the feature
- **Use case** - why is this useful?
- **Proposed implementation** (if you have ideas)
- **Examples** of how it would work

### Pull Requests
1. **Create a branch** for your feature/fix
   ```bash
   git checkout -b feature/amazing-feature
   ```

2. **Make your changes** following our coding standards

3. **Test thoroughly**
   ```bash
   make clean
   make
   make test
   ```

4. **Commit your changes**
   ```bash
   git commit -m "Add amazing feature"
   ```

5. **Push to your fork**
   ```bash
   git push origin feature/amazing-feature
   ```

6. **Open a Pull Request** on GitHub

## Coding Standards

### C Code Style

#### Formatting
- **Indentation**: 4 spaces (no tabs)
- **Line length**: Maximum 100 characters
- **Braces**: K&R style
  ```c
  if (condition) {
      // code
  } else {
      // code
  }
  ```

#### Naming Conventions
- **Functions**: `snake_case`
  ```c
  void print_number(int num);
  ```

- **Variables**: `snake_case`
  ```c
  int number_count = 0;
  ```

- **Constants**: `UPPER_CASE`
  ```c
  #define MAX_NUMBERS 1000
  ```

- **Structs/Enums**: `PascalCase` for type, `snake_case` for members
  ```c
  typedef struct {
      bool uppercase;
      int width;
  } Config;
  ```

#### Comments
- Use `//` for single-line comments
- Use `/* */` for multi-line comments
- Document complex logic
- Avoid obvious comments

Good:
```c
// Parse binary format (0b prefix)
if (strncmp(str, "0b", 2) == 0) {
    // Implementation
}
```

Bad:
```c
// Increment i
i++;
```

#### Error Handling
- Always check return values
- Provide meaningful error messages
- Use `stderr` for errors

```c
FILE *file = fopen(filename, "r");
if (file == NULL) {
    fprintf(stderr, "Error: Cannot open file '%s': %s\n", 
            filename, strerror(errno));
    return 1;
}
```

### Code Organization

#### File Structure
```c
/* 
 * File header with description
 * Copyright and license
 */

#include <system_headers.h>
#include "local_headers.h"

#define CONSTANTS

typedef struct { } Types;

// Function declarations
void function_prototype(void);

// Function implementations
void function_implementation(void) {
    // code
}

int main(int argc, char *argv[]) {
    // main code
}
```

#### Function Size
- Keep functions focused and small
- Ideally under 50 lines
- Extract complex logic into helper functions

#### Variable Declarations
- Declare variables close to first use
- Initialize variables when declared
- Use meaningful names

Good:
```c
int number_count = 0;
bool success = false;
```

Bad:
```c
int n;
bool b;
```

## Testing

### Manual Testing
Test your changes with various inputs:

```bash
# Basic functionality
./hexi 42
./hexi -u -p 255

# Edge cases
./hexi 0
./hexi -1
./hexi 9223372036854775807  # LLONG_MAX

# Error cases
./hexi invalid
./hexi -f nonexistent.txt
```

### Test Checklist
- [ ] Compiles without warnings
- [ ] Works with valid inputs
- [ ] Handles invalid inputs gracefully
- [ ] No memory leaks (use valgrind if available)
- [ ] Cross-platform compatibility (if possible)

### Running Valgrind
```bash
valgrind --leak-check=full ./hexi 42
```

## Submitting Changes

### Commit Messages
Follow these guidelines:

- **First line**: Brief summary (50 chars or less)
- **Body**: Detailed explanation (wrap at 72 chars)
- **Format**:
  ```
  Short summary of changes
  
  Detailed explanation of what changed and why.
  Include motivation and context.
  
  Fixes #123
  ```

Examples:
```
Add binary output format support

Implement -b flag to display binary representation
alongside hexadecimal output. This is useful for
debugging bit patterns and understanding number
representations.

Fixes #45
```

### Pull Request Guidelines

#### Title
- Clear and descriptive
- Reference issue number if applicable

#### Description
Include:
- **What** changed
- **Why** it changed
- **How** to test it
- **Screenshots** (if UI changes)
- **Breaking changes** (if any)

Template:
```markdown
## Description
Brief description of changes

## Motivation
Why is this change needed?

## Changes
- Change 1
- Change 2

## Testing
How to test these changes

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-review completed
- [ ] Comments added for complex code
- [ ] Tests pass
- [ ] Documentation updated
```

### Review Process
1. Maintainer reviews your PR
2. Address feedback if requested
3. Once approved, PR will be merged
4. Your contribution will be credited!

## Feature Ideas

Looking for something to work on? Here are some ideas:

### Easy
- [ ] Add more output formats (base64, base32)
- [ ] Improve error messages
- [ ] Add more examples to documentation
- [ ] Add shell completion scripts

### Medium
- [ ] Add JSON output format
- [ ] Support for floating-point numbers
- [ ] Add configuration file support
- [ ] Implement color output

### Hard
- [ ] Add arithmetic operations in interactive mode
- [ ] Support for arbitrary precision numbers
- [ ] Create a GUI version
- [ ] Add scripting language bindings (Python, etc.)

## Questions?

If you have questions:
- Check existing issues and discussions
- Open a new issue with the "question" label
- Be specific and provide context

## Recognition

Contributors will be:
- Listed in the README
- Credited in release notes
- Appreciated by the community!

Thank you for contributing to HEXI! 🎉
