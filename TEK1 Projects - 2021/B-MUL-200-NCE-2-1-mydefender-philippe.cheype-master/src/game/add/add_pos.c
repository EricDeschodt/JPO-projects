/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** add_pos.c
*/

#include <stdlib.h>
#include "defender.h"

void add_pos(menu_t *s_mn)
{
    sfVector2f size = {600, 100};
    s_mn->pos = malloc(sizeof(sfVector2f) * 4);
    s_mn->pos_onclick = malloc(sizeof(sfVector2f) * 4);

    s_mn->pos[0] = sfRectangleShape_getPosition(s_mn->slide->b->rect);
    s_mn->pos[1] = sfRectangleShape_getPosition(s_mn->button[0].rect);
    s_mn->pos[2] = sfRectangleShape_getPosition(s_mn->button[1].rect);
    s_mn->pos[3] = sfRectangleShape_getPosition(s_mn->button[2].rect);
    s_mn->pos_onclick[0] = GET_POS_ON_CLICK(s_mn->pos[0], size, BTN_HOVER);
    s_mn->pos_onclick[1] = GET_POS_ON_CLICK(s_mn->pos[1], size, BTN_HOVER);
    s_mn->pos_onclick[2] = GET_POS_ON_CLICK(s_mn->pos[2], size, BTN_HOVER);
    s_mn->pos_onclick[3] = GET_POS_ON_CLICK(s_mn->pos[3], size, BTN_HOVER);
}