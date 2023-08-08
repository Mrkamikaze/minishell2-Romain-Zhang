/*
** EPITECH PROJECT, 2022
** my_printf in disguise.c
** File description:
** my_printf in disguise
*/

#include <stdarg.h>
#include "my.h"
char my_putstr(char const *str);
int my_put_nbr(int nb);
float my_put_float(double nb);
void my_putchar (char c);
unsigned int my_put_hex_nbrup(unsigned int nb);

void display(char format, va_list list)
{
    switch (format) {
    case 's':
        my_putstr(va_arg(list, char*));
        break;
    case 'c':
        my_putchar((char)va_arg(list, int));
        break;
    case 'i': case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'f':
        my_put_float(va_arg(list, double));
        break;
    case 'X':
        my_put_hex_nbrup(va_arg(list, unsigned int));
        break;
    }
}

void my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    for (int i = 0 ;format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            display(format[i], list);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
}
