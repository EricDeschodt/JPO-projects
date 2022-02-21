/*
** EPITECH PROJECT, 2020
** my_lprintf
** File description:
** Lite version of print f with putchar putnbr putstr and puttbl
**                               %c      %d     %s         %t
**                              char     int   char *    char **
*/

#include <stdarg.h>

void my_putchar(char);

int my_strlen(const char *);

int my_putstr(const char *);

int my_putnbr(const int);

int my_put_tbl(const char **);

static void param_caller(va_list t, int k)
{
    switch (k) {
        case 0:
            my_putchar(va_arg(t, const int));
            break;
        case 1:
            my_putnbr(va_arg(t, const int));
            break;
        case 2:
            my_putstr(va_arg(t, const char *));
            break;
        case 3:
            my_put_tbl(va_arg(t, const char **));
    }
}

static int my_parameters(char const *expr, int i, va_list t)
{
    char params[4] = "cdst";

    for (int k = 0; k < 4; k++)
        if (params[k] == expr[i + 1]) {
            param_caller(t, k);
            k = 5;
            i++;
        }
    return (i);
}

int my_lprintf(char const *expr, ...)
{
    va_list t;
    va_start(t, expr);

    if (expr[0] == '\0') {
        va_end(t);
        return (0);
    }
    for (int i = 0; i + 1 <= my_strlen(expr); i++) {
        if (expr[i] == '%')
            i = my_parameters(expr, i, t);
        else
            my_putchar(expr[i]);
    }
    va_end(t);
    return (0);
}
