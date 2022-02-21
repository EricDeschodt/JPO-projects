/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** draw_settings_elements
*/

#include "defender.h"

void draw_settings_elements(vars_t *va, menu_t *s_mn)
{
    sfRenderWindow_drawSprite(va->window,         s_mn->map,            NULL);
    sfRenderWindow_drawRectangleShape(va->window, s_mn->slide->b->rect, NULL);
    sfRenderWindow_drawText(va->window,           s_mn->slide->b->text, NULL);
    sfRenderWindow_drawRectangleShape(va->window, s_mn->slide->slider,  NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(va->window, \
        s_mn->button[i].rect, NULL);
        sfRenderWindow_drawText(va->window, \
        s_mn->button[i].text, NULL);
    }
}
