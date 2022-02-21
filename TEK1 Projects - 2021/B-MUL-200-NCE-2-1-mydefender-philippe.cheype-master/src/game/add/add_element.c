/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** add_tower
*/

#include "defender.h"

void add_element(game_t *gm, int opt)
{
    obj_t *tower;
    sfVector2f pos;
    sfIntRect pos_size = {0, 0, 64, 64};

    if (gm->it[0]->temp.index.x == 0 && opt == 0) {
        tower = tower_prep(pos, gm, pos_size);
        tower = create_radius(tower, gm);
        tower_opt(gm, tower, pos);
    } else if (opt == 1) {
        tower = bomb_prep(pos, gm, pos_size);
        tower = create_radius(tower, gm);
        bomb_opt(gm, tower, pos);
    } else {
        tower = bonus_prep(pos, gm);
        tower = create_radius(tower, gm);
        bonus_opt(gm, tower, pos);
    }
}
