/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** touch_monster
*/

#include "runner.h"

monster1_t *check_monster_hitbox(monster1_t *s_monster, controll_t *s_controll)
{
    float x = s_monster->pos.x, y = s_monster->pos.y;
    int x_run = s_controll->s_runner.pos.x, y_run = s_controll->s_runner.pos.y;
    if (x_run + 80 >= x + 20 && x_run + 80 <= x + 190 && y_run + 80 >= y &&
    y_run + 80 <= y + 230) {
        s_controll->s_state.lose = 1;
        s_controll->s_interface.end.score_int =
        s_controll->s_interface.distance_int *
        s_controll->s_interface.nb_coin_int;
        s_controll->s_interface.end.strscore =
        my_put_strnbr(s_controll->s_interface.end.score_int);
        sfText_setString(s_controll->s_interface.end.score,
        s_controll->s_interface.end.strscore);
    }
    return (s_monster->next);
}

void touch_monster(controll_t *s_controll)
{
    monster1_t *temp = s_controll->s_monster;
    while (temp != NULL) {
        temp = check_monster_hitbox(temp, s_controll);
    }
}