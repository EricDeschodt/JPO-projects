/*
** EPITECH PROJECT, 2020
** fourth_screen.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

int draw_rain(framebuffer_t *framebuffer, int i, int r)
{
    sfVector2i start;

    for (int k = r % 3057; k < 1920 * 1080; k = k + 3057 + cos(i*M_PI/180)) {
        start.x = k % 1920;
        start.y = k / 1920;
        my_draw_seg(framebuffer, start, i, 10, sfWhite);
    }
    if (r == 1920 * 1079 + 1)
        return(3057);
    return (r + 1920);
}

void thunder_crack(sfRenderWindow *window, framebuffer_t *framebuffer, sfSprite *sprite, sfTexture *texture)
{
    sfVector2i pos;
    int alpha;

    pos.x = 101 + rand() % 1819;
    pos.y = 1;
    framebuffer_clear(framebuffer, sfWhite);
    while (pos.y < 1820) {
        alpha = 70 + rand() % 40;
        my_draw_seg(framebuffer, pos, alpha, (1920 - pos.y) / 2, sfBlack);
        pos.x = pos.x +  ((1920 - pos.y) / 2) * cos(alpha * M_PI / 180);
        pos.y = pos.y + (1920 - pos.y) / 2;
    }
    sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    framebuffer_reverse(framebuffer);
    sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int fourth_screen(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfEvent event;
    sfSprite *sprite = sfSprite_create();
    int i = 120;
    int r = 3057;

    srand(time(0));
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp && i < 120)
            i = i + 1;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown && i > 60)
            i = i - 1;
        if (event.type == sfEvtKeyPressed)
            if (event.key.code == sfKeyLShift)
                thunder_crack(window, framebuffer, sprite, texture);
        framebuffer_trans(framebuffer, 1.15);
        r = draw_rain(framebuffer, i, r);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (5 + 48);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (3 + 48);
        }
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
