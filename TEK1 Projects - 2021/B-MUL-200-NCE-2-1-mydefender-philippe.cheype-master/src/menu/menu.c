/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu_loop.c
*/

#include "menu_ptr.h"

static int check_button(menu_t *mn, vars_t *va)
{
    sfVector2f cursor = GET_MOUSE_POS(va->window);
    sfVector2f hover = { BTN_HOVER, BTN_HOVER };
    sfVector2f out =   { 1,         1         };

    for (int i = 0; i < NB_BUTTON; i++) {
        sfRectangleShape_setScale(mn->button[i].rect, out);
        sfText_setScale(mn->button[i].text, out);
        sfRectangleShape_setPosition(mn->button[i].rect, mn->pos[i]);
        if (cursor.x > mn->pos[i].x && cursor.x < mn->pos[i].x + mn->size.x  \
        &&  cursor.y > mn->pos[i].y && cursor.y < mn->pos[i].y + mn->size.y) {
            sfRectangleShape_setScale(mn->button[i].rect, hover);
            sfText_setScale(mn->button[i].text, hover);
            sfRectangleShape_setPosition(mn->button[i].rect,    \
                                                        mn->pos_onclick[i]);
            if (sfMouse_isButtonPressed(0)) return (i);
        }
    }
    return (-1);
}

static void draw_menu_elements(vars_t *va, menu_t *mn)
{
    sfRenderWindow_drawSprite(va->window, mn->map, NULL);
    for (int i = 0; i < NB_BUTTON; i++) {
        sfRenderWindow_drawRectangleShape(va->window, mn->button[i].rect, NULL);
        sfRenderWindow_drawText(va->window, mn->button[i].text, NULL);
    }
}

void menu(framebuffer_t *fb, vars_t *va)
{
    menu_t *mn;

    mn = init_menu();
    sfMusic_play(mn->music);
    WAIT_FOR_BUTTON_RELEASE;
    while (mn->state != 3 && sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            if (va->event.type == sfEvtClosed) sfRenderWindow_close(va->window);
        sfRenderWindow_clear(va->window, sfBlack);
        draw_menu_elements(va, mn);
        if ((mn->state = check_button(mn, va)) != -1)
            (menu_ptr[mn->state])(fb, va, mn);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                        fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    sfMusic_destroy(mn->music);
}
