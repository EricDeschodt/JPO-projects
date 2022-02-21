/*
** EPITECH PROJECT, 2020
** my print nbr
** File description:
** disp int as char
*/

#include "print.h"

void my_put_nbr(int nb)
{
    int power = -1;
    int real = nb;
    int mult  = 0;
    int ret = 0;

    if (nb == 0)
        my_putchar('0');
    for (; nb; power++)
        nb /= 10;
    mult = my_compute_power_rec(10, power);
    if (real < 0)
        my_putchar('-');
    else
        real *= -1;
    while (mult) {
        ret = (real / mult) * -1;
        real %= mult;
        mult /= 10;
        my_putchar(ret + 48);
    }
}

void my_put_unsigned_nbr(unsigned nb)
{
    unsigned s = 0;
    unsigned i = 0;

    i = nb % 10;
    s = nb / 10;
    if (s != 0) {
        my_put_unsigned_nbr(s);
    }
    my_putchar(i + '0');
}

void my_put_ll_unsigned_nbr(unsigned long long nb)
{
    unsigned long long s = 0;
    unsigned long long i = 0;

    i = nb % 10;
    s = nb / 10;
    if (s != 0) {
        my_put_ll_unsigned_nbr(s);
    }
    my_putchar(i + '0');
}
