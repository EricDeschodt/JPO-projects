/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer5
*/

#include "runner.h"

int render_layer5(controll_t *s_controll)
{
    s_controll->s_background.texture5 =
    sfTexture_createFromFile("sprites/layer5.png", NULL);
    if (!s_controll->s_background.texture5)
        return (EXIT_FAILURE);
    s_controll->s_background.layer5 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer5,
    s_controll->s_background.texture5, sfTrue);
    s_controll->s_background.pos5.x = 0;
    s_controll->s_background.pos5.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer5,
    s_controll->s_background.pos5);
    return (0);
}

int render_layer5_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture5)
        return (EXIT_FAILURE);
    s_controll->s_background.layer5_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer5_bis,
    s_controll->s_background.texture5, sfTrue);
    s_controll->s_background.pos5_bis.x = 1920;
    s_controll->s_background.pos5_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer5_bis,
    s_controll->s_background.pos5_bis);
    return (0);
}

void move_layer_5(controll_t *s_controll)
{
    if (s_controll->s_background.pos5.x > -1920 &&
    s_controll->s_background.pos5_bis.x > 0) {
        s_controll->s_background.pos5.x -= 20 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos5_bis.x -= 20 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos5.x = 0;
        s_controll->s_background.pos5_bis.x = 1920;
    }
    move_layer_6(s_controll);
}