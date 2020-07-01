/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** on_button
*/

#include "runner.h"

void hover_check(buttons_t *s_button, controll_t *s_controll)
{
    if (is_button(s_button, s_controll)) {
        sfSprite_setTexture(s_button->sprite, s_button->texture_on, sfTrue);
    }
    else
        sfSprite_setTexture(s_button->sprite, s_button->texture, sfTrue);
}

void check_on_button(controll_t *s_controll)
{
    buttons_t *temp;
    if (s_controll->s_game.scene == 0)
        temp = s_controll->s_button;
    if (s_controll->s_game.scene == 2 || s_controll->s_game.scene == 4 ||
    s_controll->s_game.scene == 5)
        temp = s_controll->s_pause;
    if (s_controll->s_game.scene == 3)
        temp = s_controll->s_levels;
    while (temp != NULL) {
        hover_check(temp, s_controll);
        temp = temp->next;
    }
}