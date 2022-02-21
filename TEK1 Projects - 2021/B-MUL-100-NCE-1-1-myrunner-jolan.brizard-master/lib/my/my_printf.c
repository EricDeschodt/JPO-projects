/*
** EPITECH PROJECT, 2020
** my dot ashe
** File description:
** all fucntion prototype
*/

#include "../include/print.h"
#include <stdarg.h>

void conv_flag(char f, va_list flag)
{
    char tab[] = {'c', 's', 'd', 'i', 'S', 'p', 'x', 'X', 'u', 'o', 'b', '\0'};
    void (*func[])() = {(void (*)()) my_putchar, (void (*)()) my_putstr, (void
    (*)()) my_put_nbr, (void (*)()) my_put_nbr, (void (*)())
                            my_put_octal, (void (*)()) my_show_ptr, (void (*)())
                            my_put_hexa_low, (void (*)()) my_put_hexa_cap,
                        (void (*)()) my_put_unsigned_nbr, (void (*)())
                            my_put_unsigned_octal, (void (*)())
                            my_put_binary, NULL};

    for (int i = 0; tab[i] != '\0'; i++) {
        if (f == '%') {
            my_putchar('%');
            return;
        } else if (tab[i] == f) {
            func[i](va_arg(flag, void (*)));
        }
    }
}

bool check_flag(char c)
{
    char tab_flag[] = {'d', 'i', 'o', 'u', 'x', 'X', 's', 'S', 'c', 'p', '%',
                        'b', '\0'};

    for (int i = 0; tab_flag[i] != '\0'; i++) {
        if (tab_flag[i] == c) {
            return true;
        }
    }
    return false;
}

int my_printf(const char *format, ...)
{
    va_list flag;
    va_start(flag, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && check_flag(format[i + 1])) {
            conv_flag(format[i + 1], flag);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(flag);
    return 0;
}