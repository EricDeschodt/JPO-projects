/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_draw_square
*/

#include "struct.h"

void my_draw_square(framebuffer_t *framebuffer, sfVector2u position,
                    unsigned int size, sfColor color)
{
    for (unsigned int i = position.x; i < position.x + size; i++)
        for (unsigned int j = position.y; j < position.y + size; j++)
            my_put_pixel(framebuffer, i, j, color);
    return;
}
