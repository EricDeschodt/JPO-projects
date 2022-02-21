/*
** EPITECH PROJECT, 2020
** fifth_screen.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

int fifth_screen(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    int k = 2;
    int a = 0;
    sfVector2i center;
    sfColor color;

    srand(time(0));
    center.x = 960;
    center.y = 510;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown && k > 2) {
            k--;
            framebuffer_clear(framebuffer, sfBlack);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp && k < 100) {
            k++;
            framebuffer_clear(framebuffer, sfBlack);
        }
        color = color_change(255 * (k + a / 90));
        my_draw_crown(framebuffer, center, 509, 10, color);
        my_move_rosace(framebuffer, a, k, color);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        a++;
        if (a == 721) {
            a = 0;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (1 + 48);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (4 + 48);
        }
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
