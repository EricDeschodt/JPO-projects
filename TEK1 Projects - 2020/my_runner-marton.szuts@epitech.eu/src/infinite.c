/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** infinite
*/

#include "runner.h"
#include "map.h"

void random_map(controll_t *s_controll)
{
    int i = 0;
    srand(time(NULL));
    i = rand() % 2;
    switch (i) {
        case 0 :
        render_sprites(s_controll, "maps/map1");
        break;
        case 1 :
        render_sprites(s_controll, "maps/map2");
        break;
        case 2 :
        render_sprites(s_controll, "maps/map3");
        break;
    }
}

void restart_button(buttons_t *s_button, controll_t *s_controll)
{
    if (s_button->id == 1) {
        s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
        if (s_controll->s_game.infinite == 1)
            random_map(s_controll);
        else render_sprites(s_controll, s_controll->current_map);
        sfClock_restart(s_controll->s_background.clock);
        s_controll->s_interface.nb_coin_int = 0;
        s_controll->s_state.lose = 0;
        sfText_setString(s_controll->s_interface.nb_coin, "0");
        s_controll->s_interface.distance_int = 0;
        sfText_setString(s_controll->s_interface.nb_dist, "0");
    }
}

void check_infinite(buttons_t *s_button, controll_t *s_controll)
{
    if (s_button->id == 0) {
        s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
        free(s_controll->current_map);
        random_map(s_controll);
        s_controll->s_game.infinite = 1;
        s_controll->s_state.lose = 0;
        sfClock_restart(s_controll->s_background.clock);
        s_controll->s_interface.nb_coin_int = 0;
        sfText_setString(s_controll->s_interface.nb_coin, "0");
        s_controll->s_interface.distance_int = 0;
        sfText_setString(s_controll->s_interface.nb_dist, "0");
    }
}
