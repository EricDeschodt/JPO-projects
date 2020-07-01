/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** touch_obstacle
*/

#include "runner.h"

obstacle_t *check_obstacle_hitbox(obstacle_t *s_obstacle,
                                    controll_t *s_controll)
{
    float x = s_obstacle->pos.x, y = s_obstacle->pos.y;
    int x_run = s_controll->s_runner.pos.x, y_run = s_controll->s_runner.pos.y;
    if (x_run + 80 >= x + 20 && x_run + 80 <= x + 170 && y_run + 80 >= y &&
    y_run + 80 <= y + 200) {
        s_controll->s_state.lose = 1;
        s_controll->s_interface.end.score_int =
        s_controll->s_interface.distance_int *
        s_controll->s_interface.nb_coin_int;
        s_controll->s_interface.end.strscore =
        my_put_strnbr(s_controll->s_interface.end.score_int);
        sfText_setString(s_controll->s_interface.end.score,
        s_controll->s_interface.end.strscore);
    }
    return (s_obstacle->next);
}

void touch_obstacle(controll_t *s_controll)
{
    obstacle_t *temp = s_controll->s_obstacle;
    while (temp != NULL) {
        if (s_controll->s_game.scene != 0) {
            temp = check_obstacle_hitbox(temp, s_controll);
        }
    }
}