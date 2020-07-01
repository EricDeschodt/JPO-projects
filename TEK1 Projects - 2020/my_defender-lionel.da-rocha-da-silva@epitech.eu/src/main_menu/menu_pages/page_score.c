/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_score.c
*/

#include "defender.h"

void page_score_init(s_game *game)
{
    page_score_t *level = game->menu->score;
    level->title = init_text();
    level->bestscores = init_text();
    level->best = malloc(sizeof(char) * 10000);
    level->best[0] = '\0';
    for (int i = 0; i < 3; i++) {
        my_strcat(level->best, my_itoa(game->bestscores[i]));
        my_strcat(level->best, "\n");
    }
}

void page_score_update(s_game *game)
{
    page_score_t *level = game->menu->score;
}

void page_score_draw(s_game *game)
{
    page_score_t *level = game->menu->score;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    put_text(&level->title, "BEST SCORES", (sfVector2f){730, 100}, 48);
    put_text(&level->bestscores, level->best, (sfVector2f){920, 200}, 32);
    button_draw(game->window, game->menu->button_return, game, game->event);
    sfRenderWindow_drawText(game->window, level->title, NULL);
    sfRenderWindow_drawText(game->window, level->bestscores, NULL);
}