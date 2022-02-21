/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle the basic moves
*/

#include "../../../../include/game/main_game.h"
#include "../../../../include/game/pathfinding.h"

bool move_ac(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'B') {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed;
        game->enemy_list[i]->speed_y = 0;
        return true;
    }
    if (game->map[y][x] == 'D') {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed * - 1;
        game->enemy_list[i]->speed_y = 0;
        return true;
    }
    return false;
}

bool move_bd(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'A') {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed * -1;
        return true;
    }
    if (game->map[y][x] == 'C') {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed;
        return true;
    }
    return false;
}

bool move_enemy_basics(main_game_t *game, int i, int x, int y)
{
    if (move_ac(game, i, x, y))
        return true;
    if (move_bd(game, i, x, y))
        return true;
    return false;
}