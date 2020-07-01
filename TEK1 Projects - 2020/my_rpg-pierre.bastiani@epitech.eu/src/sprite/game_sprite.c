/*
** EPITECH PROJECT, 2020
** utils
** File description:
** sprite
*/

#include "../../include/include.h"

void draw_game_inv2(s_game *game, s_sprite *sprite, sfRenderWindow *win)
{
    if (game->inventory == 4) {
        sfRenderWindow_drawSprite(win, sprite->sprite_inventaire, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_menu_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_exit_invent_p, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_croix, NULL);
    }
}

void draw_game_inv(s_game *game, s_sprite *sprite, sfRenderWindow *win)
{
    if (game->inventory == 1) {
        sfRenderWindow_drawSprite(win, sprite->sprite_inventaire, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_menu_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_exit_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_croix, NULL);
    }
    if (game->inventory == 2) {
        sfRenderWindow_drawSprite(win, sprite->sprite_inventaire, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_menu_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_exit_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_croix_p, NULL);
    }
    if (game->inventory == 3) {
        sfRenderWindow_drawSprite(win, sprite->sprite_inventaire, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_menu_invent_p, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_exit_invent, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_croix, NULL);
    }
    draw_game_inv2(game, sprite, win);
}