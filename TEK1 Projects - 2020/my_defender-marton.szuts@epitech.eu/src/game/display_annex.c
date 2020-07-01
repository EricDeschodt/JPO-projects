/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_annex
*/

#include "defender.h"

void display_annex(all_t *s_all, tuto_t *temp)
{
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    temp->black, NULL); sfRectangleShape_setPosition(temp->black,
        (sfVector2f){temp->pos.x - 31, temp->pos.y - 46});
    sfRenderWindow_drawRectangleShape(s_all->s_game.window, temp->life_bar,
    NULL), sfRectangleShape_setPosition(temp->life_bar,
        (sfVector2f){temp->pos.x - 30, temp->pos.y - 45});
    sfShader_setVec2Uniform(temp->shader, "lightpos",
        (sfGlslVec2){temp->pos.x, temp->pos.y});
    if (s_all->s_settings->shaders == 1) {
        sfRenderWindow_drawCircleShape(s_all->s_game.window,
            temp->light, &temp->states);
    }
    sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
    sfCircleShape_setPosition(temp->light, temp->pos);
}