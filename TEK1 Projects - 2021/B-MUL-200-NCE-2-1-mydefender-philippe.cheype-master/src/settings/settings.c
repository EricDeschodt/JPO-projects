/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** settings.c
*/

#include "setts_ptr.h"
static void close_window(vars_t *va)
{
    while (sfRenderWindow_pollEvent(va->window, &va->event))
        if (va->event.type == sfEvtClosed)
            sfRenderWindow_close(va->window);
}

void settings(framebuffer_t *fb, vars_t *va, menu_t *mn)
{
    int return_code = -1;
    menu_t *s_mn;

    s_mn = init_settings_menu(mn);
    add_pos(s_mn);
    WAIT_FOR_BUTTON_RELEASE;
    while (return_code == -1 && sfRenderWindow_isOpen(va->window)) {
        close_window(va);
        sfRenderWindow_clear(va->window, sfBlack);
        return_code = handle_interactions(va, s_mn, mn);
        draw_settings_elements(va, s_mn);
        if (return_code != -1)
            (setts_ptr[return_code])(va, fb, mn, &return_code);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    destroy_menu(s_mn);
    WAIT_FOR_BUTTON_RELEASE;
}

void how_to_play(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret)
{
    button_t *btn;
    play_t *py;
    int i = 6;
    btn = high_score_btn();
    py = init_py(btn);

    if (mn) {}
    while (i != 8 && sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            if (va->event.type == sfEvtClosed) sfRenderWindow_close(va->window);
        sfRenderWindow_clear(va->window, sfBlack);
        i = check_how_to_play(va, py, btn, i);
        draw_play(va, py, btn, i);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    *ret = -1;
    WAIT_FOR_BUTTON_RELEASE;
}

void credits(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret)
{
    sfSprite *sprite;
    sfTexture *texture;
    int code = 0;
    play_t *btn;

    btn = init_return();
    texture = sfTexture_createFromFile("assets/textures/credits.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    if (va || fb || mn || *ret) {}
    while (code == 0 && sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            if (va->event.type == sfEvtClosed) sfRenderWindow_close(va->window);
        sfRenderWindow_clear(va->window, sfBlack);
        code = check_draw(va, btn, sprite);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    (*ret) = -1;
}
