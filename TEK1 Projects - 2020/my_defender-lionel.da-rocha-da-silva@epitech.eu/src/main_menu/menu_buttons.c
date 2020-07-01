/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu_buttons.c
*/

#include "defender.h"

void on_click_play(void *data)
{
    s_game *game = (s_game *)data;
    if (game->state == MENU) {
        game->state = GAME;
        sfMusic_stop(game->menu->music);
        sfMusic_play(game->music);
        for (int i = 0; i < game->w_len[game->w_nb]; i++) {
            game->enemies[game->levels][game->w_nb][i]->mob->movetime =
            sfClock_restart
            (game->enemies[game->levels][game->w_nb][i]->mob->moveclock);
        }
    }
}

void on_quit(void *data)
{
    s_game *game = (s_game *)data;
    sfRenderWindow_close(game->window);
}

void on_restart(void *data)
{
    s_game *game = (s_game *)data;
    game->state = MENU;
    restart(game);
}

void menu_init_buttons(s_game *game)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    v2 button_pos = (v2){win_size.x/1.15f, win_size.y/5};
    int spacing = 130;
    game->menu->button_return = button_create("BACK",
    (v2){200, 100}, &on_click_ret, NULL);
    game->menu->button_play = button_create("PLAY",
    (v2){button_pos.x, button_pos.y}, &on_click_play, NULL);
    game->menu->button_levels = button_create("LEVELS",
    (v2){button_pos.x, button_pos.y+spacing}, &on_click_levels, NULL);
    game->menu->button_score = button_create("SCORE",
    (v2){button_pos.x, button_pos.y+spacing*2}, &on_click_score, NULL);
    game->menu->button_guide = button_create("GUIDE",
    (v2){button_pos.x, button_pos.y+spacing*3}, &on_click_guide, NULL);
    game->menu->button_settings = button_create("SETTINGS",
    (v2){button_pos.x, button_pos.y+spacing*4}, &on_click_settings, NULL);
    game->menu->button_quit = button_create("QUIT",
    (v2){button_pos.x, button_pos.y+spacing*5}, &on_quit, NULL);
}

void menu_buttons_draw(s_game *game)
{
    button_draw(game->window, game->menu->button_play, game, game->event);
    button_draw(game->window, game->menu->button_levels, game, game->event);
    button_draw(game->window, game->menu->button_score, game, game->event);
    button_draw(game->window, game->menu->button_guide, game, game->event);
    button_draw(game->window, game->menu->button_settings, game, game->event);
    button_draw(game->window, game->menu->button_quit, game, game->event);
}