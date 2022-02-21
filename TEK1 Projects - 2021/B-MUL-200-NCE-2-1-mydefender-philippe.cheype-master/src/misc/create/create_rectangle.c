/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** create_rectangle
*/

#include "defender.h"

sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size,  \
                                sfTexture *texture, sfBool reset_rect)
{
    sfRectangleShape *rect;

    rect = sfRectangleShape_create();
    if (texture) sfRectangleShape_setTexture(rect, texture, reset_rect);
    sfRectangleShape_setSize(rect,     size);
    sfRectangleShape_setPosition(rect, pos);
    return (rect);
}
