/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** ints into strs
*/

#include "../../include/text.h"

int my_compute_power_rec(int nb, int p);

bool mini_cond(char *str, int nb)
{
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return true;
    }
    return false;
}

char *int_to_str(char *str, int nb)
{
    int power = -1;
    int real = nb;
    int ret = 0;
    int tmp = 0;
    if (mini_cond(str, nb))
        return str;
    for (; real; power++)
        real /= 10;
    tmp = power;
    int mult = my_compute_power_rec(10, power);
    while (mult) {
        ret = (nb / mult);
        nb %= mult;
        mult /= 10;
        str[power--] = ret + 48;
    }
    str[tmp + 1] = '\0';
    return my_revstr(str);
}