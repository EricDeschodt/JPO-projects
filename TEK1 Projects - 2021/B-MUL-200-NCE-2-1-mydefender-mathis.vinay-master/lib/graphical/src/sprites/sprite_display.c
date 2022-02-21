/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a function to display sriptes
*/

#include "../../include/sprites.h"

void sprite_display(sprite_t *element, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, element->sprite, NULL);
}