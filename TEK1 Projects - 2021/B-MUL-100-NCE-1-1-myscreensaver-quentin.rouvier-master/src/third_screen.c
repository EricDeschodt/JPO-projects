/*
** EPITECH PROJECT, 2020
** third_screen.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"


int third_screen(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfVector2i center = {960, 540};
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfColor color;
    sfEvent event;
    sfSprite *sprite = sfSprite_create();
    int i = 0;

    srand(time(0));
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        color = color_change(i);
        framebuffer_trans(framebuffer, 1.05);
        put_line(framebuffer, center, i, color);
        put_line(framebuffer, center, i - 90, color);
        put_line(framebuffer, center, -i, color);
        put_line(framebuffer, center, 90 - i, color);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        i++;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (4 + 48);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (2 + 48);
        }
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
