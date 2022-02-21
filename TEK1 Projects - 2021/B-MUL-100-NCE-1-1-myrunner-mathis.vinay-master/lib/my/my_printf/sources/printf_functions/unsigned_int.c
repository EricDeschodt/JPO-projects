/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_unsigned_int
*/

#include "../../include/my.h"

int flags_long_long_gestionner(long long n, char *format);

int pf_u_int(unsigned int n, char *format)
{
    int res = flags_long_long_gestionner(n, format);
    unsigned int div = 1000000000;
    bool printed = false;
    if (n == 0) {
        my_putchar('0');
        res++;
    }
    while (div != 0) {
        if ((n / div > 0) || printed) {
            res++;
            printed = true;
            my_putchar((n / div) + 48);
            n = n % div;
        }
        div = (div != 1) ? div / 10 : 0;
    }
    return res;
}