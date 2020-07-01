/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** last_layers
*/

#include "runner.h"

int render_layer7(controll_t *s_controll)
{
    s_controll->s_background.texture7 =
    sfTexture_createFromFile("sprites/layer7.png", NULL);
    if (!s_controll->s_background.texture7)
        return (EXIT_FAILURE);
    s_controll->s_background.layer7 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer7,
    s_controll->s_background.texture7, sfTrue);
    s_controll->s_background.pos7.x = 0;
    s_controll->s_background.pos7.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer7,
    s_controll->s_background.pos7);
    return (0);
}

int render_layer8(controll_t *s_controll)
{
    s_controll->s_background.texture8 =
    sfTexture_createFromFile("sprites/layer8.png", NULL);
    if (!s_controll->s_background.texture8)
        return (EXIT_FAILURE);
    s_controll->s_background.layer8 = sfSprite_create();
    sfSprite_setTexture(s_controll->s_background.layer8,
    s_controll->s_background.texture8, sfTrue);
    s_controll->s_background.pos8.x = 0;
    s_controll->s_background.pos8.y = 0;
    sfSprite_setPosition(s_controll->s_background.layer8,
    s_controll->s_background.pos8);
    return (0);
}