/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_functions.c
*/

#include "defender.h"

void on_slot_hover(void *data, s_slot *s, sfRenderWindow *w)
{
    static int old_slot = -1;
    s_game *g = (s_game *)data;
    const sfRenderWindow *window = g->window;
    sfVector2i m = sfMouse_getPositionRenderWindow(window);
    sfBool hov = sfFloatRect_contains(&s->rect, (float)m.x, (float)m.y);
    sfRenderWindow_drawSprite(w, s->sprite_placable, NULL);
    if (hov)
    {
        sfRenderWindow_drawRectangleShape(w, s->shape_contour, NULL);
        if (is_button_released(g->window, sfMouseLeft, g->event))
        {
            toggle_tower_menu(g, s);
        }
    }
}