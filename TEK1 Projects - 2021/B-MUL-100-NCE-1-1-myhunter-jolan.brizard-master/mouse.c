/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** Handle mouse interraction && all things appearing on screen
*/

#include "my_hunter.h"

void analyse_events(t_window *windw, sfEvent event, t_sprite *sprite)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(windw->window);
    if (event.type == sfEvtMouseButtonReleased
    && is_mouse_overit(windw, sprite))
        sprites_coord(sprite);
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        windw->start = true;
}

bool is_mouse_overit(t_window *windw, t_sprite *sprite)
{
    sfVector2i mouse_coord = sfMouse_getPositionRenderWindow(windw->window);
    sfVector2f sprite_coord = sfSprite_getPosition(sprite->crow);
    sfIntRect hitbox = sfSprite_getTextureRect(sprite->crow);
    if (sprite_coord.x <= (float)mouse_coord.x
        && (float)mouse_coord.x <= sprite_coord.x
        + ((float)hitbox.width * 0.32)
        && sprite_coord.y <= (float)mouse_coord.y
        && (float)mouse_coord.y <= sprite_coord.y
        + ((float)hitbox.height * 0.32))
        return true;
    return false;
}