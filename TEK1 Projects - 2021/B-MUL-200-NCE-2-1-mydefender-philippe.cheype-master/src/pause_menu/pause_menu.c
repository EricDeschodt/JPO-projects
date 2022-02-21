/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pause_menu
*/

#include <stdlib.h>
#include "defender.h"

static int event_handler(vars_t *va)
{
    if (va->event.type == sfEvtClosed)
        sfRenderWindow_close(va->window);
    if (va->event.key.code == sfKeyEscape)
        return (0);
    return (1);
}

static void render_pause_menu(sfRenderWindow *win, menu_t *p_mn,         \
                                    game_t *gm, sfSprite *screenshot)
{
    sfRenderWindow_drawSprite(win, screenshot, NULL);
    sfRenderWindow_drawRectangleShape(win, gm->it[0]->filter, NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(win, p_mn->button[i].rect, NULL);
        sfRenderWindow_drawText(win, p_mn->button[i].text, NULL);
    }
}

static void add_pos_button(menu_t *p_mn)
{
    sfVector2f size = {600, 100};
    p_mn->pos = malloc(sizeof(sfVector2f) * 4);
    p_mn->pos_onclick = malloc(sizeof(sfVector2f) * 4);
    for (int i = 0; i < 3; i++) {
        p_mn->pos[i] = sfRectangleShape_getPosition(p_mn->button[i].rect);
        p_mn->pos_onclick[i] = GET_POS_ON_CLICK(p_mn->pos[i], size, BTN_HOVER);
    }
}

void set_button(menu_t *p_mn, sfVector2f offset, int opt, int i)
{
    if (opt == 0) {
        sfRectangleShape_setPosition(p_mn->button[i].rect, p_mn->pos[i]);
        sfRectangleShape_setScale(p_mn->button[i].rect, offset);
    } else {
        sfRectangleShape_setPosition(p_mn->button[i].rect,  \
                                                        p_mn->pos_onclick[i]);
        sfRectangleShape_setScale(p_mn->button[i].rect, offset);
    }
}

int pause_menu(framebuffer_t *fb, vars_t *va, game_t *gm)
{
    int return_code = 1;
    sfSprite *screenshot;
    menu_t *p_mn;

    screenshot = get_screenshot(va->window);
    p_mn = create_pause_menu();
    add_pos_button(p_mn);
    while (return_code == 1 && sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            return_code = event_handler(va);
        sfRenderWindow_clear(va->window, sfBlack);
        render_pause_menu(va->window, p_mn, gm, screenshot);
        if (return_code) return_code = handle_button(p_mn, va->window);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    return (return_code);
}
