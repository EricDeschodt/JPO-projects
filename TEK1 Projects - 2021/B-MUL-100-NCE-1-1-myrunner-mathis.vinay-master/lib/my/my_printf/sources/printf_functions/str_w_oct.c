/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_w_oct
*/

#include "../../include/my.h"

int my_char_isprintable(char c);

int pf_str_w_oct(char *str, char *format)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        res++;
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            res += 3;
            int n = (unsigned char)str[i];
            if (n < 0)
                n = -n + 127;
            int div = 64;
            while (div != 0) {
                my_putchar((n / div) + 48);
                n = n % div;
                div = (div != 1) ? div / 8 : 0;
            }
        }
    }
    return res;
}