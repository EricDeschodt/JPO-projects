/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** best_score
*/

#include "runner.h"

void render_best_txt(controll_t *s_controll)
{
    s_controll->s_interface.your_best = sfText_create();
    sfText_setString(s_controll->s_interface.your_best, "Your best score is :");
    sfText_setPosition(s_controll->s_interface.your_best,
    (sfVector2f){760, 250});
    sfText_setFont(s_controll->s_interface.your_best, s_controll->font);
}

void render_best_int(controll_t *s_controll)
{
    s_controll->s_interface.best = sfText_create();
    sfText_setString(s_controll->s_interface.best, my_put_strnbr(get_score()));
    sfText_setPosition(s_controll->s_interface.best,
    (sfVector2f){1110, 250});
    sfText_setFont(s_controll->s_interface.best, s_controll->font);
}