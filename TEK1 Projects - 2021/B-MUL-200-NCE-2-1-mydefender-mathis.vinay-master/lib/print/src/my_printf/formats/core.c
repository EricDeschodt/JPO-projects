/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** a set of functions enemies by the differents print enemies by print
*/

#include "../../../include/print.h"

int is_format(const char *format);

char get_element_format(char const *format, int element);

void print_hex_min_chiffre(int n)
{
    if (n < 10)
        my_putchar(n + 48);
    else
        my_putchar(n - 10 + 97);
}

void print_hex_maj_chiffre(int n)
{
    if (n < 10)
        my_putchar(n + 48);
    else
        my_putchar(n - 10 + 65);
}

int flags_long_long_gestionner(long long n, char *format)
{
    int res = 1;
    char specifier = get_element_format(format, 0);
    if (my_is_char_in_strn('+', format, is_format(format)) &&
    my_is_char_in_str(specifier, "di") && n >= 0) {
        my_putchar('+');
    } else if (my_is_char_in_strn(' ', format, is_format(format)) &&
    my_is_char_in_str(specifier, "di") && n >= 0) {
        my_putchar(' ');
    } else
        res--;
    if (my_is_char_in_strn('#', format, is_format(format)) &&
    my_is_char_in_str(specifier, "oxX")) {
        res += 2;
        my_putchar('0');
        if (specifier == 'x' || specifier == 'X')
            my_putchar(specifier);
        else
            res--;
    }
    return res;
}