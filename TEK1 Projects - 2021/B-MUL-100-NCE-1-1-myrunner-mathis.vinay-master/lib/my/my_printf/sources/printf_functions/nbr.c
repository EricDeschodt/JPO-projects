/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_nbr
*/

#include "../../include/my.h"
#include "../../include/printf_functions.h"

int flags_long_long_gestionner(long long n, char *format);

int pf_nbr(int n, char *format)
{
    int div = 1000000000;
    bool printed = false;
    int res = flags_long_long_gestionner(n, format);
    if (n > 0)
        n = - n;
    else if (n == 0) {
        my_putchar('0');
        res++;
    } else {
        my_putchar('-');
        res++;
    } while (div != 0) {
        if ((n / div < 0) || printed) {
            printed = pf_char(-(n / div) + 48, "");
            res++;
            n = n % div;
        }
        div = (div != 1) ? div / 10 : 0;
    }
    return res;
}