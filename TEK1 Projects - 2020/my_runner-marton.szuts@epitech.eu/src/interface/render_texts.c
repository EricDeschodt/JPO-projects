/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** texts
*/

#include "runner.h"

void render_nbcoins_txt(controll_t *s_controll)
{
    s_controll->s_interface.coin_mult = sfText_create();
    sfText_setString(s_controll->s_interface.coin_mult, "x");
    sfText_setFont(s_controll->s_interface.coin_mult, s_controll->font);
    sfText_setCharacterSize(s_controll->s_interface.coin_mult, 30);
    sfText_setPosition(s_controll->s_interface.coin_mult,
    (sfVector2f){105 , 55});
}

void render_nbcoins_int(controll_t *s_controll)
{
    s_controll->s_interface.nb_coin = sfText_create();
    s_controll->s_interface.strcoin =
    my_put_strnbr(s_controll->s_interface.nb_coin_int);
    sfText_setString(s_controll->s_interface.nb_coin,
    s_controll->s_interface.strcoin);
    sfText_setFont(s_controll->s_interface.nb_coin, s_controll->font);
    sfText_setCharacterSize(s_controll->s_interface.nb_coin, 30);
    sfText_setPosition(s_controll->s_interface.nb_coin,
    (sfVector2f){135 , 57});
}

void render_ditance_txt(controll_t *s_controll)
{
    s_controll->s_interface.clock = sfClock_create();
    s_controll->s_interface.distance = sfText_create();
    sfText_setString(s_controll->s_interface.distance, "Distance :         m");
    sfText_setFont(s_controll->s_interface.distance, s_controll->font);
    sfText_setCharacterSize(s_controll->s_interface.distance, 30);
    sfText_setPosition(s_controll->s_interface.distance,
    (sfVector2f){1600 , 55});
}

void render_distace_int(controll_t *s_controll)
{
    s_controll->s_interface.distance_int = 0;
    s_controll->s_interface.nb_dist = sfText_create();
    s_controll->s_interface.strdistance =
    my_put_strnbr(s_controll->s_interface.distance_int);
    sfText_setString(s_controll->s_interface.nb_dist,
    s_controll->s_interface.strdistance);
    sfText_setFont(s_controll->s_interface.nb_dist, s_controll->font);
    sfText_setCharacterSize(s_controll->s_interface.nb_dist, 30);
    sfText_setPosition(s_controll->s_interface.nb_dist,
    (sfVector2f){1780 , 55});
}