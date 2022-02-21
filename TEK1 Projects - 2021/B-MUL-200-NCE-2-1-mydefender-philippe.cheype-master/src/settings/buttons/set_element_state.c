/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** set_elements_state
*/

#include "defender.h"

void set_element_state(menu_t *s_mn, sfVector2f scale,     \
                                sfVector2f pos, int i)
{
    if (i == 0) {
        sfRectangleShape_setScale(s_mn->slide->b->rect,    scale);
        sfRectangleShape_setPosition(s_mn->slide->b->rect, pos);
        sfText_setScale(s_mn->slide->b->text,              scale);
        sfRectangleShape_setScale(s_mn->slide->slider,     scale);
    } else {
        sfRectangleShape_setScale(s_mn->button[i - 1].rect,    scale);
        sfRectangleShape_setPosition(s_mn->button[i - 1].rect, pos);
        sfText_setScale(s_mn->button[i - 1].text,              scale);
    }
}
