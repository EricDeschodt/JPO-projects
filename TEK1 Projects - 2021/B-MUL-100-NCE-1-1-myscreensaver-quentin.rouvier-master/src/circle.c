/*
** EPITECH PROJECT, 2020
** draw_circle.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

void my_draw_circle(framebuffer_t *framebuffer, sfVector2i center, int radius, sfColor color)
{
    //float max = 3600 * M_PI / 180;

    for (int i = 0; i <= radius; i++) {
        for (float alpha = 0; alpha <= 360; alpha = alpha + 0.5) {
            my_put_pixel(framebuffer, center.x + i * cos(alpha*M_PI/180), center.y + i * sin(alpha*M_PI/180), color);
            my_put_pixel(framebuffer, center.x - i * cos(alpha*M_PI/180), center.y - i * sin(alpha*M_PI/180), color);
        }
    }
}

void my_draw_crown(framebuffer_t *framebuffer, sfVector2i center, int radius, int thickness, sfColor color)
{
    int i = radius - thickness;

    
    for (; i <= radius; i++) {
        for (int alpha = 0; alpha <= 360; alpha++) {
            my_put_pixel(framebuffer, center.x + i * cos(alpha), center.y + i * sin(alpha), color);
            my_put_pixel(framebuffer, center.x - i * cos(alpha), center.y - i * sin(alpha), color);
        }
    }
}
