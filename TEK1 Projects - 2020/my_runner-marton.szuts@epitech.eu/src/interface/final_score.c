/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** final_score
*/

#include "runner.h"

void render_final_score_txt(controll_t *s_controll)
{
    s_controll->s_interface.end.your_score = sfText_create();
    sfText_setString(s_controll->s_interface.end.your_score,
    "Your final score is :");
    sfText_setCharacterSize(s_controll->s_interface.end.your_score, 50);
    sfText_setPosition(s_controll->s_interface.end.your_score,
    (sfVector2f){600, 900});
    sfText_setFont(s_controll->s_interface.end.your_score, s_controll->font);
}

void render_final_score_int(controll_t *s_controll)
{
    s_controll->s_interface.end.score_int = 0;
    s_controll->s_interface.end.score = sfText_create();
    sfText_setString(s_controll->s_interface.end.score, "0");
    sfText_setCharacterSize(s_controll->s_interface.end.score, 50);
    sfText_setPosition(s_controll->s_interface.end.score,
    (sfVector2f){1180, 903});
    sfText_setFont(s_controll->s_interface.end.score, s_controll->font);
}

void set_final_score(controll_t *s_controll)
{
    s_controll->s_interface.best_int = get_score();
    sfText_setString(s_controll->s_interface.best,
    my_put_strnbr(s_controll->s_interface.best_int));
}