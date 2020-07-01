/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_sesttings_volume.c
*/

#include "defender.h"

void vol_init(s_game *g)
{
    sfVector2f pos = (sfVector2f){(1000), (430)};
    g->volume.size = (sfVector2f){400, 40};
    g->volume.x = 160;
    g->volume.percentage = ((g->volume.size.x / 400) * 100);
    g->volume.bg = sfRectangleShape_create();
    g->volume.fr = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->volume.bg, (sfColor){100, 100, 100, 255});
    sfRectangleShape_setFillColor(g->volume.fr, (sfColor){200, 200, 200, 255});
    sfRectangleShape_setSize(g->volume.bg, g->volume.size);
    sfRectangleShape_setSize(g->volume.fr, (sfVector2f){g->volume.x, 40});
    sfRectangleShape_setPosition(g->volume.bg, pos);
    sfRectangleShape_setPosition(g->volume.fr, pos);
}

int vol_update_press(s_game *g, int holding, int pressed)
{
    sfFloatRect bg_rect = sfRectangleShape_getGlobalBounds(g->volume.bg);
    sfFloatRect fr_rect = sfRectangleShape_getGlobalBounds(g->volume.fr);
    sfIntRect r = sfRectangleShape_getTextureRect(g->volume.bg);
    float mouse_x = (float)sfMouse_getPosition((const sfWindow *)g->window).x;

    if ((pressed || holding)) {
        if (((mouse_x - bg_rect.left) >= bg_rect.width) ||
            ((mouse_x - bg_rect.left) <= 0))
            return 0;
        holding = 1;
            g->volume.x = mouse_x - bg_rect.left;
        sfRectangleShape_setSize(g->volume.fr,
            (sfVector2f){g->volume.x, bg_rect.height});
        g->volume.percentage = (((fr_rect.width)/ bg_rect.width) * 100);
        sfListener_setGlobalVolume(g->volume.percentage);
        return (holding);
    }
    return (0);
}

void vol_update(s_game *g)
{
    static int holding = 0;
    sfFloatRect bg_rect = sfRectangleShape_getGlobalBounds(g->volume.bg);
    int hovering = is_mouse_hovering(&bg_rect, g->window);
    int pressed = sfMouse_isButtonPressed(sfMouseLeft);
    if (hovering || holding) {
        if ((holding = vol_update_press(g, holding, pressed)) == 0)
            return;
    }
    if (!pressed && holding == 1)
        holding = 0;
}

void vol_draw(s_game *g)
{
    sfRenderWindow_drawRectangleShape(g->window, g->volume.bg, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->volume.fr, NULL);
}