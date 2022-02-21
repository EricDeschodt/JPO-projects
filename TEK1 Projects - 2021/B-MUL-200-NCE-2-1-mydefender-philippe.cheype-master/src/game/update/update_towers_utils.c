/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** update_towers_utils
*/

#include "defender.h"
#include "elements.h"

void draw_tower_menu(vars_t *va, obj_t *tw)
{
    if (tw->stop != 1) {
        if (tw->body.rect) sfRenderWindow_drawRectangleShape(va->window,    \
                                                        tw->body.rect, NULL);
        sfRenderWindow_drawRectangleShape(va->window, tw->action[0], NULL);
        sfRenderWindow_drawRectangleShape(va->window, tw->action[1], NULL);
        sfRenderWindow_drawRectangleShape(va->window, tw->radius, NULL);
        if (tw->body.index.x != 2) {
            sfRenderWindow_drawRectangleShape(va->window,   \
                                            tw->health.background, NULL);
            sfRenderWindow_drawRectangleShape(va->window, tw->health.bar, NULL);
        }
    }
}

void set_colors(obj_t *tw, sfColor colors[3])
{
    sfRectangleShape_setFillColor(tw->radius, colors[0]);
    sfRectangleShape_setFillColor(tw->action[0], colors[1]);
    sfRectangleShape_setFillColor(tw->action[1], colors[2]);
}

void check(obj_t *tw, sfVector2f pos, sfVector2f mouse_pos, game_t *gm)
{
    sfColor colors[3] = { {0, 0, 0, 0}, {255, 0, 0, 0}, {0, 255, 0, 0} };
    int a = 0;

    if (CHECK_Y(mouse_pos, pos, 0, 64)) {
        colors[0].a = 50;
        sfRectangleShape_setFillColor(tw->radius, colors[0]);
        if (sfMouse_isButtonPressed(1)) {
            colors[0].a = 80;
            colors[1].a = 150;
            colors[2].a = 150;
            set_colors(tw, colors);
            colors[1].a = 255;
            colors[2].a = 255;
            ((a = handle_hover_buttons(tw, mouse_pos, pos, colors)) != 0 ?  \
            gm->it[0]->info.money -= a : 0);
        }
    }
}

sfIntRect handle_bonus(obj_t *temp, sfIntRect area, float bonus)
{
    int n;

    n = 6;
    if (bonus != 0.0) {
        area.top += 250;
        n = 4;
    }
    if (temp->frame == n)
        temp->frame = n;
    else
        area.left += 255 * (++temp->frame);
    return (area);
}
