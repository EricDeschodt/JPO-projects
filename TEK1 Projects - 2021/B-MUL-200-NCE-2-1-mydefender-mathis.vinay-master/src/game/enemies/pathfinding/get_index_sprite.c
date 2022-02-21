/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** gets the relative indexes for a given sprite
*/

#include "../../../../include/game/main_game.h"

int get_row_index(main_game_t *game, sfSprite *enemy)
{
    sfVector2f pos = sfSprite_getPosition(enemy);
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    int row_index = (int)(pos.y / h) + 1;
    return row_index;
}

int get_col_index(main_game_t *game, sfSprite *enemy)
{
    sfVector2f pos = sfSprite_getPosition(enemy);
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    int col_index = (int)(pos.x / h);
    return col_index;
}