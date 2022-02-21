/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_screenshot
*/

#include "defender.h"

sfSprite *get_screenshot(sfRenderWindow *win)
{
    sfTexture *ss_texture;
    sfSprite *screenshot;
    sfVector2u size;

    screenshot = sfSprite_create();
    size = sfRenderWindow_getSize(win);
    ss_texture = sfTexture_create(size.x, size.y);
    sfTexture_updateFromRenderWindow(ss_texture, win,       \
                        (unsigned int)0, (unsigned int)0);
    sfSprite_setTexture(screenshot, ss_texture, sfTrue);
    return (screenshot);
}