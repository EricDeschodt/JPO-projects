/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** update_user_action.c
*/

#include "defender.h"

void update_user_action(vars_t *va, game_t *gm)
{
    sfVector2f mouse_pos = GET_MOUSE_POS(va->window);

    if (gm->it[0]->info.check.x == 0)
        check_items(mouse_pos, gm);
    else
        update_items(mouse_pos, gm, va);
}
