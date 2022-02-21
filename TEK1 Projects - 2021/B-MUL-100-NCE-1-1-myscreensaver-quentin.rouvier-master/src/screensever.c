/*
** EPITECH PROJECT, 2020
** sreensavers
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

void screensavers(int c)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    framebuffer_t *framebuffer;

    framebuffer = framebuffer_create(video_mode);
    window = sfRenderWindow_create(video_mode, "My Window",
                                   sfResize | sfClose, NULL);
    if (!window)
        EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        if (c == 49)
            c = first_screen(window, framebuffer);
        if (c == 50)
            c = second_screen(window, framebuffer);
        if (c == 51)
            c = third_screen(window, framebuffer);
        if (c == 52)
            c = fourth_screen(window, framebuffer);
        if (c == 53)
            c = fifth_screen(window, framebuffer);
        framebuffer_clear(framebuffer, sfBlack);
    }
    framebuffer_destroy(framebuffer);
    sfRenderWindow_destroy(window);
}
