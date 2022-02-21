/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle the angles
*/

#include "../../../../include/game/main_game.h"
#include "../../../../include/game/pathfinding.h"

bool move_e(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'E' && game->enemy_list[i]->speed_x < 0) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed;
        sfSprite_rotate(game->enemy_list[i]->enemy, 270);
        return true;
    }
    if (game->map[y][x] == 'E' && game->enemy_list[i]->speed_y < 0) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed;
        game->enemy_list[i]->speed_y = 0;
        sfSprite_rotate(game->enemy_list[i]->enemy, 90);
        return true;
    }
    return false;
}

bool move_f(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'F' && game->enemy_list[i]->speed_x > 0) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed;
        sfSprite_rotate(game->enemy_list[i]->enemy, 90);
        return true;
    }
    if (game->map[y][x] == 'F' && game->enemy_list[i]->speed_y < 0) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed * -1;
        game->enemy_list[i]->speed_y = 0;
        sfSprite_rotate(game->enemy_list[i]->enemy, 270);
        return true;
    }
    return false;
}

bool move_g(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'G' && game->enemy_list[i]->speed_x > 0) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed * -1;
        sfSprite_rotate(game->enemy_list[i]->enemy, 270);
        return true;
    }
    if (game->map[y][x] == 'G' && game->enemy_list[i]->speed_y > 0) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed * -1;
        game->enemy_list[i]->speed_y = 0;
        sfSprite_rotate(game->enemy_list[i]->enemy, 90);
        return true;
    }
    return false;
}

bool move_h(main_game_t *game, int i, int x, int y)
{
    if (game->map[y][x] == 'H' && game->enemy_list[i]->speed_x < 0) {
        game->enemy_list[i]->speed_x = 0;
        game->enemy_list[i]->speed_y = game->enemy_list[i]->global_speed * -1;
        sfSprite_rotate(game->enemy_list[i]->enemy, 90);
        return true;
    }
    if (game->map[y][x] == 'H' && game->enemy_list[i]->speed_y > 0) {
        game->enemy_list[i]->speed_x = game->enemy_list[i]->global_speed;
        game->enemy_list[i]->speed_y = 0;
        sfSprite_rotate(game->enemy_list[i]->enemy, 270);
        return true;
    }
    return false;
}

bool move_enemy_angle(main_game_t *game, int i, int x, int y)
{
    if (move_e(game, i, x, y))
        return true;
    if (move_f(game, i, x, y))
        return true;
    if (move_g(game, i, x, y))
        return true;
    if (move_h(game, i, x, y))
        return true;
    return false;
}