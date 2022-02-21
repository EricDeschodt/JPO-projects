/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** anexe_settings.c
*/

#include <stdlib.h>
#include "defender.h"

void draw_play(vars_t *va, play_t *py, button_t *btn, int i)
{
    sfRenderWindow_drawRectangleShape(va->window, py->bg.rect, NULL);
    for (int j = 0; j < 7; j++) {
        sfRenderWindow_drawRectangleShape(va->window, btn[j].rect, NULL);
        sfRenderWindow_drawText(va->window, btn[j].text, NULL);
    }
    if (i != 8)
        sfRenderWindow_drawRectangleShape(va->window, py->rect[i].rect, NULL);
}

void settings_button(button_t *btn, play_t *py, int opt, int i)
{
    sfVector2f hover = {BTN_HOVER, BTN_HOVER};
    sfVector2f out = {1, 1};

    if (opt == 0) {
        sfRectangleShape_setPosition(btn[i].rect, py->pos[i]);
        sfRectangleShape_setScale(btn[i].rect, out);
        sfText_setScale(btn[i].text, out);
    } else {
        sfRectangleShape_setPosition(btn[i].rect, py->pos_onclick[i]);
        sfRectangleShape_setScale(btn[i].rect, hover);
        sfText_setScale(btn[i].text, hover);
    }
}

play_t *init_return(void)
{
    sfFloatRect pos_size = {100, 100, 600, 100};
    char *string[] = { "", "Return" };
    sfVector2f size = {600, 100};
    sfTexture **texture;
    play_t *btn;

    texture = get_button_textures(1);
    btn = malloc(sizeof(play_t));
    btn->pos = malloc(sizeof(sfVector2f) * 2);
    btn->rect = malloc(sizeof(button_t));
    btn->pos[0].x = 100;
    btn->pos[0].y = 100;
    btn->pos[1] = (sfVector2f)GET_POS_ON_CLICK(btn->pos[0], size, BTN_HOVER);
    btn->rect = create_button_ns(pos_size, string, texture, 1);
    return (btn);
}

void return_menu(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret)
{
    (*ret)++;
    if (va || fb || mn) {}
}
