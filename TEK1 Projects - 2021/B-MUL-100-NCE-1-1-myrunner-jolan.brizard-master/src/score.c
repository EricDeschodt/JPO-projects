/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Free all
*/

#include "../include/project.h"

int mini_cond(t_text *sc, int nb)
{
    if (nb == 0) {
        sc->s_score[0] = '0';
        sc->s_score[1] = '\0';
        return 1;
    }
    return 0;
}

void int_to_str(t_text *sc, int nb)
{
    int power = -1;
    int real = nb;
    int ret = 0;
    int tmp = 0;
    if (mini_cond(sc, nb))
        return;
    for (; real; power++)
        real /= 10;
    tmp = power;
    int mult = my_compute_power_rec(10, power);
    while (mult) {
        ret = (nb / mult);
        nb %= mult;
        mult /= 10;
        sc->s_score[power--] = ret + 48;
    }
    sc->s_score[tmp + 1] = '\0';
    my_revstr(sc->s_score);
}