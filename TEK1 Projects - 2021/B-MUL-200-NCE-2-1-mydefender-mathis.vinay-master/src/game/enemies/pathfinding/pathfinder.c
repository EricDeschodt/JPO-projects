/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handles the path
*/

#include "../../../../include/game/main_game.h"
#include "../../../../include/game/pathfinding.h"

void global_move(main_game_t *game, int i, int x, int y)
{
    if (move_enemy_start(game, i, x, y))
        return;
    if (move_enemy_angle(game, i, x, y))
        return;
    if (move_enemy_basics(game, i, x, y))
        return;
}

void center_x(main_game_t *game, int i, int x, int y)
{
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    int pix_x = x * (int) h;
    sfVector2f actual = sfSprite_getPosition(game->enemy_list[i]->enemy);
    if (game->enemy_list[i]->speed_x > 0) {
        if (actual.x >= (float) pix_x + (h / 2)) {
            global_move(game, i, x, y);
            game->enemy_list[i]->last_x = x;
        }
    }
    if (game->enemy_list[i]->speed_x < 0) {
        if (actual.x <= (float) pix_x + (h / 2)) {
            global_move(game, i, x, y);
            game->enemy_list[i]->last_x = x;
        }
    }
}

void center_y(main_game_t *game, int i, int x, int y)
{
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    int pix_y = y * (int) h;
    sfVector2f actual = sfSprite_getPosition(game->enemy_list[i]->enemy);
    if (game->enemy_list[i]->speed_y > 0) {
        if (actual.y >= (float) pix_y - (h / 2)) {
            global_move(game, i, x, y);
            game->enemy_list[i]->last_y = y;
        }
    }
    if (game->enemy_list[i]->speed_y < 0) {
        if (actual.y <= (float) pix_y - (h / 2)) {
            global_move(game, i, x, y);
            game->enemy_list[i]->last_y = y;
        }
    }
}

void pathfinder(main_game_t *g, int i, double v)
{
    int x = get_col_index(g, g->enemy_list[i]->enemy);
    int y = get_row_index(g, g->enemy_list[i]->enemy);
    if (g->enemy_list[i]->speed_x == 0 && g->enemy_list[i]->speed_y == 0)
        global_move(g, i, x, y);
    if (x != g->enemy_list[i]->last_x || y != g->enemy_list[i]->last_y) {
        center_x(g, i, x, y);
        center_y(g, i, x, y);
    }
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    sfVector2f mv = {(float)(g->enemy_list[i]->speed_x * h * v),
                        (float)(g->enemy_list[i]->speed_y * h * v)};
    sfSprite_move(g->enemy_list[i]->enemy, mv);
}