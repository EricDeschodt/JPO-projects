/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** print_unsigned_bin
*/

#include "../../../include/print.h"

int pf_u_bin(unsigned int n, char *format)
{
    int res = 0;
    unsigned int div = 2147483648;
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
        div = (div != 1) ? div / 2 : 0;
    }
    return res;
}