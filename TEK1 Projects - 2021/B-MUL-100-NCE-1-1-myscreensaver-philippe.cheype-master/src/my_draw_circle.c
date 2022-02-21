/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_draw_circle
*/

#include "struct.h"

void my_draw_circle(framebuffer_t *framebuffer, sfVector2i c, unsigned int r, \
                                                                sfColor color)
{
    for (unsigned int i = c.x - r; i <= c.x + r; i++)
        for (unsigned int j = c.y - r; j <= c.y + r; j++)
            (((i - c.x) * (i - c.x)) + ((j - c.y) * (j - c.y)) <= r * r) && \
                                    (my_put_pixel(framebuffer, i, j, color), 0);
    return;
}
