/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** page_functions
*/

#include "defender.h"

void page_levels_init(s_game *game)
{
    page_level_t *level = game->menu->level;
    sfVector2f pos = (sfVector2f){250, 500};
    int x = 350;
    level->title = init_text();
    level->b_map1 = button_create("MAP1", pos, &map1, NULL);
    level->b_map2 = button_create("MAP2",
    (sfVector2f){pos.x+x, pos.y}, &map2, NULL);
    level->b_map3 = button_create("MAP3",
    (sfVector2f){pos.x+x*2, pos.y}, &map3, NULL);
    level->b_map4 = button_create("MAP4",
    (sfVector2f){pos.x+x*3, pos.y}, &map4, NULL);
    level->b_map5 = button_create("MAP5",
    (sfVector2f){pos.x+x*4, pos.y}, &map5, NULL);
}

void page_levels_update(s_game *game)
{
    page_level_t *level = game->menu->level;
}

void page_levels_draw(s_game *game)
{
    page_level_t *level = game->menu->level;
    sfText *title = level->title;
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    put_text(&title, "LEVEL SELECTION", (sfVector2f){win_size.x/3, 100}, 48);
    button_draw(game->window, game->menu->button_return, game, game->event);
    sfRenderWindow_drawText(game->window, level->title, NULL);
    button_draw_selectable(game->window, level->b_map1, game, game->event);
    button_draw_selectable(game->window, level->b_map2, game, game->event);
    button_draw_selectable(game->window, level->b_map3, game, game->event);
    button_draw_selectable(game->window, level->b_map4, game, game->event);
    button_draw_selectable(game->window, level->b_map5, game, game->event);
}

sfBool mouse_button_released(sfRenderWindow *w, sfEvent e)
{
    if (e.mouseButton.button == sfMouseLeft && e.mouseButton.type ==
    sfEvtMouseButtonReleased) {
        e.mouseButton.type = -1;
        return sfTrue;
    }
    return sfFalse;
}