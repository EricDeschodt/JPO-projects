/*
** EPITECH PROJECT, 2020
** first screen
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

void draw_screen_1(framebuffer_t *framebuffer, sfVector2i *circles, int i, int j, sfColor *color)
{
    sfColor fade;
    int j_max = 100;

    for (int k = 0 ; k < i; k++) {
        if (j < j_max)
            my_draw_circle(framebuffer, circles[k], j, color[k]);
        else if (j >= j_max && j < 2 * j_max) {
            fade.r = 255 - color[k].r;
            fade.g = 255 - color[k].g;
            fade.b = 255 - color[k].b;
            fade.a = color[k].a / 1.5;
            my_draw_crown(framebuffer, circles[k], 2 * j_max - j, 1, fade);
        }
    }
}

int first_screen(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfVector2i *circles = malloc(sizeof(sfVector2i) * 150);
    sfColor *color = malloc(sizeof(sfColor) * 150);
    sfEvent event;
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();
    int i = 0;
    int j = 1;

    srand(time(0));
    circles[0] = random_pos();
    color[0] = random_color();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        if (j > 200.0) {
            i++;
            circles[i] = random_pos();
            color[i] = random_color();
            j = 0;
        }
        draw_screen_1(framebuffer, circles, i, j, color);
        j++;
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            free(color);
            free(circles);
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (2 + 48);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            free(circles);
            free(color);
            sfTexture_destroy(texture);
            sfSprite_destroy(sprite);
            return (5 + 48);
        }
    }
    free(circles);
    free(color);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
