/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a set of tests for buttons
*/

#include "../../include/buttons.h"

bool button_is_on_over(sprite_t *button, sfRenderWindow *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
    if (rect.left <= (float)(pos.x) && (float)(pos.x) <= rect.left + rect
    .width && rect.top <= (float)(pos.y) && (float)(pos.y) <= rect.top + rect
    .height) return true;
    return false;
}

bool button_is_clicked(sprite_t *button, sfRenderWindow *win, sfEvent event)
{
    if (button_is_on_over(button, win) && (event.mouseButton.button ==
    sfMouseLeft && event.type == sfEvtMouseButtonReleased)) return true;
    return false;
}