/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** display_layers
*/

#include "runner.h"

void layers_setpos1(controll_t *s_controll)
{
    sfSprite_setPosition(s_controll->s_background.layer1,
    s_controll->s_background.pos1);
    sfSprite_setPosition(s_controll->s_background.layer1_bis,
    s_controll->s_background.pos1_bis);
    sfSprite_setPosition(s_controll->s_background.layer2,
    s_controll->s_background.pos2);
    sfSprite_setPosition(s_controll->s_background.layer2_bis,
    s_controll->s_background.pos2_bis);
    sfSprite_setPosition(s_controll->s_background.layer3,
    s_controll->s_background.pos3);
    sfSprite_setPosition(s_controll->s_background.layer3_bis,
    s_controll->s_background.pos3_bis);
    sfSprite_setPosition(s_controll->s_background.layer4,
    s_controll->s_background.pos4);
    sfSprite_setPosition(s_controll->s_background.layer4_bis,
    s_controll->s_background.pos4_bis);
    sfSprite_setPosition(s_controll->s_background.layer5,
    s_controll->s_background.pos5);
    sfSprite_setPosition(s_controll->s_background.layer5_bis,
    s_controll->s_background.pos5_bis), layers_setpos2(s_controll);
}

void layers_setpos2(controll_t *s_controll)
{
    sfSprite_setPosition(s_controll->s_background.layer6,
    s_controll->s_background.pos6);
    sfSprite_setPosition(s_controll->s_background.layer6_bis,
    s_controll->s_background.pos6_bis);
}

void layers_display1(controll_t *s_controll)
{
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer8, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer7, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer6, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer6_bis, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer5, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer5_bis, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer4, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer4_bis, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer3, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer3_bis, NULL), layers_display2(s_controll);
}

void layers_display2(controll_t *s_controll)
{
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer2, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer2_bis, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer1, NULL);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_background.layer1_bis, NULL);
}