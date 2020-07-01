/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** stopped
*/

#include "runner.h"

int render_stopped(controll_t *s_controll)
{
    s_controll->s_stopped.texture =
    sfTexture_createFromFile("sprites/stopped.png", NULL);
    if (!s_controll->s_stopped.texture)
        return (EXIT_FAILURE);
    s_controll->s_stopped.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_stopped.sprite,
    s_controll->s_stopped.texture, sfTrue);
    return (0);
}

void display_stopped(controll_t *s_controll)
{
    sfSprite_setPosition(s_controll->s_stopped.sprite,
    s_controll->s_runner.pos);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_stopped.sprite, NULL);
}