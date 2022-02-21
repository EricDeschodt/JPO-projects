/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-mathis.vinay
** File description:
** functions for graphical handling
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include "../include/my.h"

bool is_sprite_on_hover(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2i mouse_coord = sfMouse_getPositionRenderWindow(window);
    sfVector2f origin = sfSprite_getOrigin(sprite);
    sfVector2f position = sfSprite_getPosition(sprite);
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    if (position.x - origin.x <= (float)mouse_coord.x && (float)mouse_coord.x
    <= position.x - origin.x + (float)rect.width && position.y - origin.y <=
    (float)mouse_coord.y && (float)mouse_coord.y <= position.y - origin.y +
    (float)rect.height)
        return true;
    return false;
}

struct sfRenderWindow *create_window(char const *name)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_display(window);
    return window;
}

sfSprite *create_background(sfTexture *texture)
{
    sfTexture_setRepeated(texture, sfTrue);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *animate_background(sfSprite *b, int v)
{
    sfIntRect rect = sfSprite_getTextureRect(b);
    rect.left += v;
    if (rect.left >= rect.width)
        rect.left -= rect.width;
    sfSprite_setTextureRect(b, rect);
    return b;
}