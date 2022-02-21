/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** game menu functions
*/

#include "../../include/game/main_game.h"

bool main_game_animate(main_game_t *game)
{
    if (!animate_enemies(game))
        return false;
    turret_animate(game);
    bullets_animate(game, 30);
    sidebar_init(game->sidebar, game);
    return true;
}

void main_game_display(main_game_t *game, sfRenderWindow *win,
                        bool should_animate)
{
    map_display(game, win);
    display_enemies(game, win);
    turret_display(game, win);
    bullet_display(game, win);
    if (should_animate)
        turret_indicator_display(game, win);
    sidebar_display(game, win, should_animate);
}

void main_game_destroy(main_game_t *game, bool is_full)
{
    if (game->map) {
        tab_free(game->map);
        time_destroy(game->time);
        sprite_destroy(game->map_tampon);
        turrets_destroy(game->turret_list);
        free_enemy(game->enemy_list);
    }
    if (is_full) {
        sprite_destroy(game->t_indic);
        sprite_destroy(game->range_indicator);
        sidebar_destroy(game->sidebar);
        for (int i = 0; game->texture_list[i]; i++)
            sfTexture_destroy(game->texture_list[i]);
        free(game->texture_list);
        free(game);
    }
}