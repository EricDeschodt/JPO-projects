/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu_route.c
*/

#include "defender.h"

void route_all_updates(s_game *game)
{
    e_menu_pages m = game->menu->pages_state;
    switch (game->state) {
    case MENU:
            menu_update(game);
            if (game->menu->pages_state == LEVELS) page_levels_update(game);
            if (game->menu->pages_state == SCORE) page_score_update(game);
            if (game->menu->pages_state == GUIDE) page_guide_update(game);
            if (game->menu->pages_state == SETTINGS)
                page_settings_update(game);
        break;
    case GAME:
        game_update(game);
        break;
    case GAMEOVER:
        gameover_update(game);
    default:
        break;
    }
}

void route_draw_calls(s_game *game)
{
    switch (game->state) {
    case MENU:
            menu_draw(game);
            if (game->menu->pages_state == LEVELS) page_levels_draw(game);
            if (game->menu->pages_state == SCORE) page_score_draw(game);
            if (game->menu->pages_state == GUIDE) page_guide_draw(game);
            if (game->menu->pages_state == SETTINGS) page_settings_draw(game);
        break;
    case GAME:
        game_draw(game);
        break;
    case GAMEOVER:
        draw_gameover(game);
    default:
        break;
    }
}