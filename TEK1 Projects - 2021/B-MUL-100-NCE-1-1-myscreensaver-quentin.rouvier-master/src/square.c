/*
** EPITECH PROJECT, 2020
** square.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

void my_draw_seg(framebuffer_t *framebuffer, sfVector2i pos1, int angle, int length, sfColor color)
{
    int k = 0;
    float angle_rad = angle * M_PI / 180;

    
    for (; k < length; k++) {
        if (pos1.y + k * sin(angle_rad) < 1080 && pos1.y + k * sin(angle_rad) > 0 &&
            pos1.x + k * cos(angle_rad) < 1920 && pos1.x + k * cos(angle_rad) > 0)
            my_put_pixel(framebuffer, pos1.x + k * cos(angle_rad), pos1.y + k * sin(angle_rad), color);
    }
}

void put_line(framebuffer_t *framebuffer, sfVector2i pos1, int angle, sfColor color)
{
    int k = 0;
    float angle_rad = angle * M_PI / 180;

    
    for (; k < 1920; k++) {
        if (pos1.y + k * sin(angle_rad) < 1080 && pos1.y + k * sin(angle_rad) > 0 &&
            pos1.x + k * cos(angle_rad) < 1920 && pos1.x + k * cos(angle_rad) > 0)
            my_put_pixel(framebuffer, pos1.x + k * cos(angle_rad), pos1.y + k * sin(angle_rad), color);
        if (pos1.y - k * sin(angle_rad) < 1080 && pos1.y - k * sin(angle_rad) > 0 &&
            pos1.x - k * cos(angle_rad) < 1920 && pos1.x - k * cos(angle_rad) > 0)
            my_put_pixel(framebuffer, pos1.x - k * cos(angle_rad), pos1.y - k * sin(angle_rad), color);
            
        k++;
    }
}

void draw_square(framebuffer_t *framebuffer, sfVector2i pos1, sfVector2i sizes, sfColor color)
{
    for (int n = pos1.y; n < pos1.y + sizes.y && n < 1080; n++)
        for (int k = pos1.x; k < pos1.x + sizes.x && k < 1920; k++)
            my_put_pixel(framebuffer, k, n, color);
}
