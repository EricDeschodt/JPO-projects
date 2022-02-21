/*
** EPITECH PROJECT, 2020
** colors.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"


sfColor random_color(void)
{
    sfColor color;
    int k = rand();
    int r = rand();
    int n = rand();

    color.r = k % 256;
    color.g = r % 256;
    color.b = n % 256;
    color.a = 255;
    return (color);
}

sfColor *gradiant_color(float i)
{
    sfColor *color = malloc(sizeof(sfColor) * 4);
    int n = 1;

    for (int k = 0; k < 4; k = k + 2) {
        color[k].r = 127 + 127 * cos(i);
        color[k].g = 0;
        color[k].b = 127 + 127 * sin(i) * n;
        color[k].a = 255;
        n = n * -1;
    }
    for (int k = 1; k < 4; k = k + 2) {
        color[k].r = 127 - 127 * cos(i);
        color[k].g = 127 + 127 * sin(i) * n;
        color[k].b = 0;
        color[k].a = 255;
        n = n * -1;
    }
    return (color);
}

sfColor color_change(int i)
{
    sfColor color;
    int k = (i / 255) % 3;

    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    if (k == 0) {
        color.r = i % 256;
        color.g = 255 - (i % 255);
    }
    if (k == 1) {
        color.g = i % 256;
        color.b = 255 - (i % 255);
    }
    if (k == 2) {
        color.b = i % 256;
        color.r = 255 - (i % 255);
    }
    return (color);
}
