#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...);

int _printf(const char *format, ...) {

    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; /* Move past the '%' */
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        printed_chars++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }
                default:
                    /* Unsupported conversion specifier, just print the '%' */
                    putchar('%');
                    printed_chars++;
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

