/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** screensaver_end
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct.h"

void screen_end(framebuffer_t *fb, sfSprite *sprite, \
                    sfTexture *texture, sfRenderWindow *window)
{
    framebuffer_destroy(fb);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return;
}
