/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_guide.c
*/

#include "defender.h"

void page_guide_init(s_game *game)
{
    page_guide_t *level = game->menu->guide;
    level->title = init_text();
}

void page_guide_update(s_game *game)
{
    page_guide_t *level = game->menu->guide;
}

void page_guide_draw(s_game *game)
{
    page_guide_t *level = game->menu->guide;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    put_text(&level->title, game->guide, (sfVector2f){380, 210}, 16);
    button_draw(game->window, game->menu->button_return, game, game->event);
    sfRenderWindow_drawText(game->window, level->title, NULL);
}