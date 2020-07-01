/*
** EPITECH PROJECT, 2019
** defender
** File description:
** my_game
*/

#include "defender.h"

void init_map(s_game *game)
{
    char *path[] =
    {"sprites/land_1.png", "sprites/top_right.png",
    "sprites/top_left.png", "sprites/top_border.png",
    "sprites/bottom_border.png", "sprites/right_border.png",
    "sprites/left_border.png", "sprites/bottom_left.png",
    "sprites/bottom_right.png", "sprites/road_horizontal.png",
    "sprites/road_bottom_right.png", "sprites/road_top_left.png",
    "sprites/road_top_right.png", "sprites/road_vertical.png",
    "sprites/road_bottom_left.png"};
    char *maps[] = {"maps/map1.txt", "maps/map2.txt", "maps/map3.txt",
    "maps/map4.txt", "maps/map5.txt"};
    char *slots[] = {"sprites/empty.png", "sprites/tower-canon.png",
    "sprites/tower-ice.png", "sprites/tower-magic.png",
    "sprites/tower-tesla.png"};
    create_map(game, path, maps, slots);
}

void game_init3(s_game *game, s_path tmp, int k)
{
    for (int i = 0; i < 21; i++) {
        game->grid[k][i] = malloc(sizeof(s_path) * 42);
        for (int j = 0; j < 41; j++) {
            game->grid[k][i][j] = tmp;
        }
    }
}

void game_update(s_game *game)
{
    sfBool escape_key;
    float per = 0;
    game_update1(game);
    if (!game->g_pause.paused && game->sent == sfTrue) {
        for (int i = 0; i < game->w_len[game->w_nb]; i++) {
            run(game, game->w_nb, i);
            kill_mobs(game, i);
        }
        for (t_list *tmp = game->slots[game->levels]; tmp != NULL;
        tmp = tmp->next) {
            attack_update(game, tmp, per);
        }
    }
}

void game_draw(s_game *game)
{
    draw_map(game);
    draw_mob(game);
    draw_castle(game);
    for (t_list *tmp = game->slots[game->levels]; tmp != NULL;
    tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->tower[tmp->type]->sprite,
        NULL);
        tower_menu_draw(game);
    }
    if (game->g_pause.paused)
        pause_draw(game);
}