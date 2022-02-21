/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle the start pos
*/

#include "../../../../include/game/main_game.h"

bool move_r(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'R' && x == 0) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed;
        game->enemy_list[i]->speed_y = 0;
        return true;
    }
    if (game->map[y][x] == 'R' && x == game->col_max) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed * -1;
        game->enemy_list[i]->speed_y = 0;
        sfSprite_rotate(game->enemy_list[i]->enemy, 180);
        return true;
    }
    return false;
}

bool move_q(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'Q' && y == 1) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed;
        sfSprite_rotate(game->enemy_list[i]->enemy, 90);
        return true;
    }
    if (game->map[y][x] == 'Q' && y == game->row_max) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed * -1;
        sfSprite_rotate(game->enemy_list[i]->enemy, 270);
        return true;
    }
    return false;
}

bool move_enemy_start(main_game_t *game, int i, int x, int y)
{
    if (move_q(game, i, x, y))
        return true;
    if (move_r(game, i, x, y))
        return true;
    return false;
}