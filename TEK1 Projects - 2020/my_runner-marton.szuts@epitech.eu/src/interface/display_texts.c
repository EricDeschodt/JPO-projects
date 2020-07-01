/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** display_texts
*/

#include "runner.h"

void increment_distance(controll_t *s_controll)
{
    if (s_controll->s_game.scene == 1)
        if (s_controll->s_interface.seconds > 0.1) {
            free_previous_txt(s_controll->s_interface.strdistance);
            s_controll->s_interface.distance_int += 1;
            s_controll->s_interface.strdistance =
            my_put_strnbr(s_controll->s_interface.distance_int);
            sfText_setString(s_controll->s_interface.nb_dist,
            s_controll->s_interface.strdistance);
            sfClock_restart(s_controll->s_interface.clock);
        }
}

void display_texts(controll_t *s_controll)
{
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.coin_mult, NULL);
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.nb_coin, NULL);
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.distance, NULL);
    increment_distance(s_controll);
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.nb_dist, NULL);
}