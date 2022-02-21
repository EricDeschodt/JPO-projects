/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** check_draw.c
*/

#include "defender.h"

int check_draw(vars_t *va, play_t *btn, sfSprite *sprite)
{
    sfVector2f hover = {BTN_HOVER, BTN_HOVER};
    sfVector2f c = GET_MOUSE_POS(va->window);
    sfVector2f out = {1, 1};

    sfRectangleShape_setScale(btn->rect[0].rect, out);
    sfRectangleShape_setPosition(btn->rect[0].rect, btn->pos[0]);
    if ((c.x > btn->pos[0].x) && (c.x < btn->pos[0].x + 600)   \
    &&  (c.y > btn->pos[0].y) && (c.y < btn->pos[0].y + 100)) {
        sfRectangleShape_setScale(btn->rect[0].rect, hover);
        sfRectangleShape_setPosition(btn->rect[0].rect, btn->pos[0]);
        if (sfMouse_isButtonPressed(0)) return (1);
    }
    sfRenderWindow_drawSprite(va->window, sprite, NULL);
    sfRenderWindow_drawRectangleShape(va->window, btn->rect[0].rect, NULL);
    sfRenderWindow_drawText(va->window, btn->rect[0].text, NULL);
    return (0);
}
