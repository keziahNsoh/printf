#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
        va_list args;

        va_start(args, format);
        int count = vfprintf(stdout, format, args);

        while (*format != '0')
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        count += printf("%c", va_arg(args, int));
                                        break;
                                case 's':
                                        count += printf("%s", va_arg(args, char *));
                                        break;
                                case 'd':
                                        count += printf("%d", va_arg(args, int));
                                        break;
                                case 'f':
                                        count += printf("%f", va_arg(args, double));
                                        break;
                                default:
                                        printf("Invalid format specifier: %c\n", *format);
                                        break;
                        }
                }
                else
                {
                        putchar(*format);
                        count++;
                }
                format++;
        }
        va_end(args);
        return (count);
}

int main(void);
int num = 123;
char *str = "Hello, world!";
_printf("%d\n", num);
_printf("%s\n", str);
_printf("%.2f\n", 3.14159);
return (0);

}
