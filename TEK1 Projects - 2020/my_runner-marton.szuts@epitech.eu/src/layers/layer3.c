/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer3
*/

#include "runner.h"

int render_layer3(controll_t *s_controll)
{
    s_controll->s_background.texture3 =
    sfTexture_createFromFile("sprites/layer3.png", NULL);
    if (!s_controll->s_background.texture3)
        return (EXIT_FAILURE);
    s_controll->s_background.layer3 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer3,
    s_controll->s_background.texture3, sfTrue);
    s_controll->s_background.pos3.x = 0;
    s_controll->s_background.pos3.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer3,
    s_controll->s_background.pos3);
    return (0);
}

int render_layer3_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture3)
        return (EXIT_FAILURE);
    s_controll->s_background.layer3_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer3_bis,
    s_controll->s_background.texture3, sfTrue);
    s_controll->s_background.pos3_bis.x = 1920;
    s_controll->s_background.pos3_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer3_bis,
    s_controll->s_background.pos3_bis);
    return (0);
}

void move_layer_3(controll_t *s_controll)
{
    if (s_controll->s_background.pos3.x > -1920 &&
    s_controll->s_background.pos3_bis.x > 0) {
        s_controll->s_background.pos3.x -= 40 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos3_bis.x -= 40 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos3.x = 0;
        s_controll->s_background.pos3_bis.x = 1920;
    }
    move_layer_4(s_controll);
}