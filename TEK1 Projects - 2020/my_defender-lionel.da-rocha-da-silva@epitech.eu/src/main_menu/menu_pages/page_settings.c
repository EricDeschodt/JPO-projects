/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_settings.c
*/

#include "defender.h"

void page_settings_init(s_game *game)
{
    float x = 1100, y = 550;
    page_settings_t *level = game->menu->settings;
    level->title = init_text();
    level->title_volume = init_text();
    level->framerate = init_text();
    level->title_frame = init_text();
    level->down = button_create("", (v2){x, y + 15},
        &on_frame_down, "res/arrow_left.png");
    level->up = button_create("", (v2){x + 150, y + 15},
        &on_frame_up, "res/arrow_right.png");
    put_text(&level->title_volume, "GLOBAL VOLUME", (v2){x - 600, y-120}, 32);
    put_text(&level->title_frame, "FRAMERATE", (v2){x - 600, y}, 32);
    put_text(&level->framerate, my_itoa(game->framerate), (v2){x + 50, y - 4},
    32);
    vol_init(game);
}

void page_settings_update(s_game *game)
{
    page_settings_t *level = game->menu->settings;
    vol_update(game);
}

void page_settings_draw(s_game *game)
{
    page_settings_t *level = game->menu->settings;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    put_text(&level->title, "SETTINGS", (sfVector2f){800, 220}, 48);
    button_draw(game->window, game->menu->button_return, game, game->event);
    button_draw(game->window, level->down, game, game->event);
    button_draw(game->window, level->up, game, game->event);
    sfRenderWindow_drawText(game->window, level->title, NULL);
    sfRenderWindow_drawText(game->window, level->title_volume, NULL);
    sfRenderWindow_drawText(game->window, level->title_frame, NULL);
    sfRenderWindow_drawText(game->window, level->framerate, NULL);
    vol_draw(game);
}