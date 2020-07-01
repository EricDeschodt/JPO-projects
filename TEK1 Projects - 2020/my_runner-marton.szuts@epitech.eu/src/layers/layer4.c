/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer4
*/

#include "runner.h"

int render_layer4(controll_t *s_controll)
{
    s_controll->s_background.texture4 =
    sfTexture_createFromFile("sprites/layer4.png", NULL);
    if (!s_controll->s_background.texture4)
        return (EXIT_FAILURE);
    s_controll->s_background.layer4 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer4,
    s_controll->s_background.texture4, sfTrue);
    s_controll->s_background.pos4.x = 0;
    s_controll->s_background.pos4.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer4,
    s_controll->s_background.pos4);
    return (0);
}

int render_layer4_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture4)
        return (EXIT_FAILURE);
    s_controll->s_background.layer4_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer4_bis,
    s_controll->s_background.texture4, sfTrue);
    s_controll->s_background.pos4_bis.x = 1920;
    s_controll->s_background.pos4_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer4_bis,
    s_controll->s_background.pos4_bis);
    return (0);
}

void move_layer_4(controll_t *s_controll)
{
    if (s_controll->s_background.pos4.x > -1920 &&
    s_controll->s_background.pos4_bis.x > 0) {
        s_controll->s_background.pos4.x -= 30 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos4_bis.x -= 30 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos4.x = 0;
        s_controll->s_background.pos4_bis.x = 1920;
    }
    move_layer_5(s_controll);
}