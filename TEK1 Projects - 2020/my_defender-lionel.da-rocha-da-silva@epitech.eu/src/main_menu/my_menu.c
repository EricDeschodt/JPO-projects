/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu.c
*/

#include "defender.h"

void menu_init(s_game *game)
{
    get_scores(game);
    game->menu->level = malloc(sizeof(page_level_t));
    game->menu->score = malloc(sizeof(page_score_t));
    game->menu->guide = malloc(sizeof(page_guide_t));
    game->menu->settings = malloc(sizeof(page_settings_t));
    game->menu->menu_bg = sfSprite_create();
    game->menu->pages_bg = sfSprite_create();
    game->menu->music = sfMusic_createFromFile("res/sounds/menu.ogg");
    game->music = sfMusic_createFromFile("res/sounds/game.ogg");
    sfMusic_setLoop(game->music, 1), sfMusic_setLoop(game->menu->music, 1);
    sfMusic_setVolume(game->music, 10), sfMusic_play(game->menu->music);
    sfMusic_setVolume(game->menu->music, 10);
    sfSprite_setColor(game->menu->pages_bg, (sfColor){0, 100, 0, 150});
    sfSprite_setTexture(game->menu->menu_bg,
    sfTexture_createFromFile("res/menu-bg.jpg", NULL), 1);
    sfSprite_setTexture(game->menu->pages_bg,
    sfTexture_createFromFile("res/pages-bg.png", NULL), 1);
    sfSprite_setPosition(game->menu->pages_bg, (sfVector2f){350, 200});
    menu_init_buttons(game), page_levels_init(game);
    page_score_init(game), page_guide_init(game), page_settings_init(game);
}

void menu_update(s_game *game)
{

}

void menu_draw(s_game *game)
{
    e_menu_pages s = game->menu->pages_state;
    sfRenderWindow_drawSprite(game->window, game->menu->menu_bg, NULL);
    if (s != -1 && s != LEVELS && s != SCORE)
        sfRenderWindow_drawSprite(game->window, game->menu->pages_bg, NULL);
    if (game->menu->pages_state == -1)
        menu_buttons_draw(game);
}

void draw_gameover(s_game *game)
{
    sfRenderWindow_drawSprite(game->window, game->gameover->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->gameover->gameover, NULL);
    sfRenderWindow_drawText(game->window, game->gameover->best_scores_t, NULL);
    sfRenderWindow_drawText(game->window, game->gameover->best_scores, NULL);
    button_draw(game->window, game->gameover->restart, game, game->event);
    button_draw(game->window, game->gameover->quit, game, game->event);
}

void draw_map_slot(s_game *game)
{
    for (t_list *tmp = game->slots[game->levels]; tmp != NULL;
    tmp = tmp->next) {
        tmp->tower[tmp->type]->on_slot_hover(game, tmp->tower[tmp->type],
        game->window);
        sfRenderWindow_drawSprite(game->window,
        tmp->tower[tmp->type]->sprite_tower, NULL);
    }
    if (game->sent == sfFalse)
        button_draw(game->window, game->w_button, game, game->event);
}