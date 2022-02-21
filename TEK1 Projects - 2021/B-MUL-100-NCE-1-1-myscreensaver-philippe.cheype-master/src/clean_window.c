/*
** EPITECH PROJECT, 2020
** my_screensaver (Workspace)
** File description:
** clean_window
*/

#include "struct.h"

void clean_window(framebuffer_t *fb)
{
    for (unsigned int i = 0; i < WIDTH; i++)
        for (unsigned int j = 0; j < HEIGHT; j++)
            my_put_pixel(fb, i, j, sfBlack);
}
