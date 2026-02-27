/*
 * hexi - Modern Integer to Hexadecimal Converter
 * Copyright (c) 2022-2026 YUNUS EMRE VURGUN
 * Licensed under MIT License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define VERSION "2.0.0"
#define MAX_NUMBERS 1000

typedef enum {
    FORMAT_LOWERCASE = 0,
    FORMAT_UPPERCASE = 1,
    FORMAT_0X_PREFIX = 2,
    FORMAT_SPACE_SEP = 4,
    FORMAT_COMMA_SEP = 8
} OutputFormat;

typedef struct {
    bool uppercase;
    bool show_prefix;
    bool interactive;
    bool from_file;
    bool show_binary;
    bool show_octal;
    char separator;
    int width;
} Config;

void print_banner(void) {
    printf("\n");
    printf("╔═══════════════════════════════════════════════════════════╗\n");
    printf("║           HEXI - Integer to Hexadecimal Converter        ║\n");
    printf("║                      Version %s                        ║\n", VERSION);
    printf("║              © 2022-2026 YUNUS EMRE VURGUN                ║\n");
    printf("╚═══════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

void print_help(const char *program_name) {
    print_banner();
    printf("USAGE:\n");
    printf("  %s [OPTIONS] [NUMBERS...]\n\n", program_name);
    
    printf("OPTIONS:\n");
    printf("  -h, --help              Show this help message\n");
    printf("  -v, --version           Show version information\n");
    printf("  -i, --interactive       Run in interactive mode\n");
    printf("  -u, --uppercase         Output in uppercase hexadecimal\n");
    printf("  -p, --prefix            Add '0x' prefix to output\n");
    printf("  -w, --width <N>         Set output width (padding with zeros)\n");
    printf("  -b, --binary            Also show binary representation\n");
    printf("  -o, --octal             Also show octal representation\n");
    printf("  -f, --file <PATH>       Read numbers from file (one per line)\n");
    printf("  -s, --separator <CHAR>  Set separator character (default: space)\n");
    printf("  -c, --comma             Use comma as separator\n\n");
    
    printf("EXAMPLES:\n");
    printf("  %s 12 13 14 15 16\n", program_name);
    printf("  %s -u -p 255 256 257\n", program_name);
    printf("  %s -w 8 -p 42\n", program_name);
    printf("  %s -i\n", program_name);
    printf("  %s -b -o 255\n", program_name);
    printf("  %s -f numbers.txt\n\n", program_name);
    
    printf("INPUT FORMATS:\n");
    printf("  Decimal:     123, -456\n");
    printf("  Hexadecimal: 0x1A, 0xFF\n");
    printf("  Octal:       0755, 0644\n");
    printf("  Binary:      0b1010, 0b1111\n\n");
}

void print_version(void) {
    printf("hexi version %s\n", VERSION);
    printf("Copyright (c) 2022-2026 YUNUS EMRE VURGUN\n");
    printf("Licensed under MIT License\n");
}

long long parse_number(const char *str, bool *success) {
    char *endptr;
    long long value;
    
    *success = false;
    
    if (str == NULL || *str == '\0') {
        return 0;
    }
    
    // Remove leading/trailing whitespace
    while (isspace(*str)) str++;
    
    // Check for binary format (0b prefix)
    if (strncmp(str, "0b", 2) == 0 || strncmp(str, "0B", 2) == 0) {
        value = 0;
        str += 2;
        while (*str == '0' || *str == '1') {
            value = value * 2 + (*str - '0');
            str++;
        }
        *success = (*str == '\0' || isspace(*str));
        return value;
    }
    
    // Use strtoll for decimal, hex (0x), and octal (0) formats
    errno = 0;
    value = strtoll(str, &endptr, 0);
    
    if (errno == 0 && (*endptr == '\0' || isspace(*endptr))) {
        *success = true;
        return value;
    }
    
    return 0;
}

void print_number(long long num, const Config *config, bool is_last) {
    if (config->show_prefix) {
        printf("0x");
    }
    
    if (config->uppercase) {
        if (config->width > 0) {
            printf("%0*llX", config->width, (unsigned long long)num);
        } else {
            printf("%llX", (unsigned long long)num);
        }
    } else {
        if (config->width > 0) {
            printf("%0*llx", config->width, (unsigned long long)num);
        } else {
            printf("%llx", (unsigned long long)num);
        }
    }
    
    if (!is_last) {
        printf("%c", config->separator);
    }
}

void print_detailed(long long num, const Config *config) {
    printf("Decimal:     %lld\n", num);
    printf("Hexadecimal: ");
    if (config->show_prefix) printf("0x");
    if (config->uppercase) {
        printf("%llX\n", (unsigned long long)num);
    } else {
        printf("%llx\n", (unsigned long long)num);
    }
    
    if (config->show_octal) {
        printf("Octal:       0%llo\n", (unsigned long long)num);
    }
    
    if (config->show_binary) {
        printf("Binary:      0b");
        unsigned long long unum = (unsigned long long)num;
        int bits = sizeof(long long) * 8;
        bool started = false;
        
        for (int i = bits - 1; i >= 0; i--) {
            if (unum & (1ULL << i)) {
                started = true;
            }
            if (started) {
                printf("%d", (unum & (1ULL << i)) ? 1 : 0);
                if (i > 0 && i % 4 == 0) printf(" ");
            }
        }
        if (!started) printf("0");
        printf("\n");
    }
    printf("\n");
}

void interactive_mode(const Config *config) {
    char input[256];
    bool success;
    long long num;
    
    print_banner();
    printf("Interactive Mode - Enter numbers to convert (or 'q' to quit)\n");
    printf("Supported formats: decimal, 0x (hex), 0 (octal), 0b (binary)\n\n");
    
    while (1) {
        printf("hexi> ");
        fflush(stdout);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // Remove newline
        input[strcspn(input, "\n")] = 0;
        
        // Check for quit
        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            break;
        }
        
        // Skip empty lines
        if (strlen(input) == 0) {
            continue;
        }
        
        // Parse and convert
        num = parse_number(input, &success);
        
        if (success) {
            print_detailed(num, config);
        } else {
            printf("Error: Invalid number format\n\n");
        }
    }
    
    printf("\nGoodbye!\n");
}

int process_file(const char *filename, const Config *config) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    
    char line[256];
    long long numbers[MAX_NUMBERS];
    int count = 0;
    bool success;
    
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_NUMBERS) {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }
        
        numbers[count] = parse_number(line, &success);
        if (success) {
            count++;
        } else {
            fprintf(stderr, "Warning: Skipping invalid line: %s\n", line);
        }
    }
    
    fclose(file);
    
    if (count == 0) {
        fprintf(stderr, "Error: No valid numbers found in file\n");
        return 1;
    }
    
    for (int i = 0; i < count; i++) {
        print_number(numbers[i], config, i == count - 1);
    }
    printf("\n");
    
    return 0;
}

int main(int argc, char *argv[]) {
    Config config = {
        .uppercase = false,
        .show_prefix = false,
        .interactive = false,
        .from_file = false,
        .show_binary = false,
        .show_octal = false,
        .separator = ' ',
        .width = 0
    };
    
    long long numbers[MAX_NUMBERS];
    int num_count = 0;
    char *filename = NULL;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(argv[0]);
            return 0;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        } else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--interactive") == 0) {
            config.interactive = true;
        } else if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--uppercase") == 0) {
            config.uppercase = true;
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--prefix") == 0) {
            config.show_prefix = true;
        } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--binary") == 0) {
            config.show_binary = true;
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--octal") == 0) {
            config.show_octal = true;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--comma") == 0) {
            config.separator = ',';
        } else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--width") == 0) {
            if (i + 1 < argc) {
                config.width = atoi(argv[++i]);
            } else {
                fprintf(stderr, "Error: --width requires an argument\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--separator") == 0) {
            if (i + 1 < argc) {
                config.separator = argv[++i][0];
            } else {
                fprintf(stderr, "Error: --separator requires an argument\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if (i + 1 < argc) {
                filename = argv[++i];
                config.from_file = true;
            } else {
                fprintf(stderr, "Error: --file requires an argument\n");
                return 1;
            }
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Error: Unknown option '%s'\n", argv[i]);
            fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
            return 1;
        } else {
            // Parse as number
            bool success;
            numbers[num_count] = parse_number(argv[i], &success);
            if (success) {
                num_count++;
            } else {
                fprintf(stderr, "Error: Invalid number '%s'\n", argv[i]);
                return 1;
            }
        }
    }
    
    // Execute based on mode
    if (config.interactive) {
        interactive_mode(&config);
        return 0;
    }
    
    if (config.from_file) {
        return process_file(filename, &config);
    }
    
    if (num_count == 0) {
        // Default demo mode
        print_banner();
        printf("Welcome to HEXI - Integer to Hexadecimal Converter!\n\n");
        printf("Converting example values: 12, 13, 14, 15, 16\n\n");
        
        int demo[] = {12, 13, 14, 15, 16};
        printf("Decimal:     ");
        for (int i = 0; i < 5; i++) {
            printf("%d%s", demo[i], i < 4 ? ", " : "\n");
        }
        
        printf("Hexadecimal: ");
        for (int i = 0; i < 5; i++) {
            printf("0x%02x%s", demo[i], i < 4 ? ", " : "\n");
        }
        
        printf("\nTry running with your own numbers!\n");
        printf("Example: %s 255 256 1024\n", argv[0]);
        printf("For more options, use: %s --help\n\n", argv[0]);
        
        return 0;
    }
    
    // Convert and print numbers
    for (int i = 0; i < num_count; i++) {
        if (config.show_binary || config.show_octal) {
            printf("Number %d:\n", i + 1);
            print_detailed(numbers[i], &config);
        } else {
            print_number(numbers[i], &config, i == num_count - 1);
        }
    }
    
    if (!config.show_binary && !config.show_octal) {
        printf("\n");
    }
    
    return 0;
}
