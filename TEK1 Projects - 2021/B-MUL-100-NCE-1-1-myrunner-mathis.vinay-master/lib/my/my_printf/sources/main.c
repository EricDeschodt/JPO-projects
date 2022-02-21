/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** multifunctionnal print
*/

#include <stdarg.h>
#include "../include/my.h"

char get_element_format(char const *format, int element);

int is_format(const char *format);

int flag_operations(const char *format, va_list args, int res);

int my_printf_rec(char const *str, va_list args, int res)
{
    if (*str) {
        if (*str == '%' && is_format(&str[1])) {
            return my_printf_rec(&str[1 + is_format(&str[1])], args,
            flag_operations(&str[1], args, res) + res);
        } else {
            my_putchar(*str);
            return my_printf_rec(&str[1], args, res + 1);
        }
    }
    return res;
}

int my_printf(char const *str, ...)
{
    va_list args;
    va_start(args, str);
    int res = my_printf_rec(str, args, 0);
    va_end(args);
    return res;
}