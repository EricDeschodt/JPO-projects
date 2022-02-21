/*
** EPITECH PROJECT, 2020
** second_screen.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

int second_screen(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfVector2i *center;
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfColor *color;
    sfEvent event;
    sfSprite *sprite = sfSprite_create();
    float i = 0;

    srand(time(0));
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        center = get_pos(i);
        color = gradiant_color(i);
        framebuffer_trans(framebuffer, 1.5);
        for (int k = 0; k < 4; k++)
            my_draw_circle(framebuffer, center[k], 100, color[k]);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        i = i + (M_PI / 180);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            free(color);
            free(center);
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (3 + 48);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            free(color);
            free(center);
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (1 + 48);
        }
    }
    free(color);
    free(center);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
