/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** layer1
*/

#include "runner.h"

int render_layer1(controll_t *s_controll)
{
    s_controll->s_background.clock = sfClock_create();
    s_controll->s_background.texture1 =
    sfTexture_createFromFile("sprites/layer1.png", NULL);
    if (!s_controll->s_background.texture1)
        return (EXIT_FAILURE);
    s_controll->s_background.layer1 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer1,
    s_controll->s_background.texture1, sfTrue);
    s_controll->s_background.pos1.x = 0;
    s_controll->s_background.pos1.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer1,
    s_controll->s_background.pos1);
    return (0);
}

int render_layer1_bis(controll_t *s_controll)
{
    if (!s_controll->s_background.texture1)
        return (EXIT_FAILURE);
    s_controll->s_background.layer1_bis = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer1_bis,
    s_controll->s_background.texture1, sfTrue);
    s_controll->s_background.pos1_bis.x = 1920;
    s_controll->s_background.pos1_bis.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer1_bis,
    s_controll->s_background.pos1_bis);
    return (0);
}

void move_layer_1(controll_t *s_controll)
{
    if (s_controll->s_background.pos1.x > -1920 &&
    s_controll->s_background.pos1_bis.x > 0) {
        s_controll->s_background.pos1.x -= 750 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
        s_controll->s_background.pos1_bis.x -= 750 *
        s_controll->s_background.secconds * s_controll->s_game.speed;
    }
    else {
        s_controll->s_background.pos1.x = 0;
        s_controll->s_background.pos1_bis.x = 1920;
    }
    move_layer_2(s_controll);
}