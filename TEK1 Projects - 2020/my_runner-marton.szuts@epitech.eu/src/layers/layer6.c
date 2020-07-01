/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer6
*/

#include "runner.h"

int render_layer6(controll_t *s_controll)
{
    s_controll->s_background.texture6 =
    sfTexture_createFromFile("sprites/layer6.png", NULL);
    if (!s_controll->s_background.texture6)
        return (EXIT_FAILURE);
    s_controll->s_background.layer6 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer6,
    s_controll->s_background.texture6, sfTrue);
    s_controll->s_background.pos6.x = 0;
    s_controll->s_background.pos6.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer6,
    s_controll->s_background.pos6);
    return (0);
}

int render_layer6_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture6)
        return (EXIT_FAILURE);
    s_controll->s_background.layer6_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer6_bis,
    s_controll->s_background.texture6, sfTrue);
    s_controll->s_background.pos6_bis.x = 1920;
    s_controll->s_background.pos6_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer6_bis,
    s_controll->s_background.pos6_bis);
    return (0);
}

void move_layer_6(controll_t *s_controll)
{
    if (s_controll->s_background.pos6.x > -1920 &&
    s_controll->s_background.pos6_bis.x > 0) {
        s_controll->s_background.pos6.x -= 10 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos6_bis.x -= 10 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos6.x = 0;
        s_controll->s_background.pos6_bis.x = 1920;
    }
    sfClock_restart(s_controll->s_background.clock);
}