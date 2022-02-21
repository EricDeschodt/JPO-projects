/*
** EPITECH PROJECT, 2020
** frmaebuffer.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

framebuffer_t *framebuffer_reverse(framebuffer_t *framebuffer)
{
    for (int i = 0; i < 1920 * 1080; i++) {
        framebuffer->pixels[i * 4] = 255 - framebuffer->pixels[i * 4];
        framebuffer->pixels[i * 4 + 1] = 255 - framebuffer->pixels[i * 4 + 1];
        framebuffer->pixels[i * 4 + 2] = 255 - framebuffer->pixels[i * 4 + 2];
    }
    return (framebuffer);
}

framebuffer_t *framebuffer_create(sfVideoMode video_mode)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    int width = video_mode.width;
    int height = video_mode.height;
    int bpp = video_mode.bitsPerPixel;

    if (framebuffer == NULL)
        return (NULL);
    framebuffer->pixels = malloc(bpp * width * height / 8);
    if (framebuffer->pixels == NULL)
        return (NULL);
    framebuffer->width = width;
    framebuffer->height = height;
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

framebuffer_t *framebuffer_clear(framebuffer_t *framebuffer, sfColor color)
{
    int i = 0;

    while (i < 1920 * 1080) {
        framebuffer->pixels[i * 4] = color.r;
        framebuffer->pixels[i * 4 + 1] = color.g;
        framebuffer->pixels[i * 4 + 2] = color.b;
        framebuffer->pixels[i * 4 + 3] = color.a;
        i++;
    }
    return (framebuffer);
}

framebuffer_t *framebuffer_trans(framebuffer_t *framebuffer, float opacity)
{
    int i = 0;

    while (i < 1920 * 1080) {
        framebuffer->pixels[i * 4 + 3] /= opacity;
        i++;
    }
    return (framebuffer);
}
