/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer2
*/

#include "runner.h"

int render_layer2(controll_t *s_controll)
{
    s_controll->s_background.texture2 =
    sfTexture_createFromFile("sprites/layer2.png", NULL);
    if (!s_controll->s_background.texture2)
        return (EXIT_FAILURE);
    s_controll->s_background.layer2 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer2,
    s_controll->s_background.texture2, sfTrue);
    s_controll->s_background.pos2.x = 0;
    s_controll->s_background.pos2.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer2,
    s_controll->s_background.pos2);
    return (0);
}

int render_layer2_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture2)
        return (EXIT_FAILURE);
    s_controll->s_background.layer2_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer2_bis,
    s_controll->s_background.texture2, sfTrue);
    s_controll->s_background.pos2_bis.x = 1920;
    s_controll->s_background.pos2_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer2_bis,
    s_controll->s_background.pos2_bis);
    return (0);
}

void move_layer_2(controll_t *s_controll)
{
    if (s_controll->s_background.pos2.x > -1920 &&
    s_controll->s_background.pos2_bis.x > 0) {
        s_controll->s_background.pos2.x -= 150 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos2_bis.x -= 150 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos2.x = 0;
        s_controll->s_background.pos2_bis.x = 1920;
    }
    move_layer_3(s_controll);
}