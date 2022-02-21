/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates the window
*/

#include "../../include/window.h"

struct sfRenderWindow *window_create(char const *name, int x, int y, int fps)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_display(window);
    return window;
}