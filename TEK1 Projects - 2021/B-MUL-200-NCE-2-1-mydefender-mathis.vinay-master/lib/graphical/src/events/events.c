/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Event handling
*/

#include "../../include/events.h"

void event_close(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int event_getkey(sfEvent event)
{
    return (event.type == sfEvtKeyReleased)?event.key.code:-1;
}

bool event_isclicked(sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft && event.type ==
    sfEvtMouseButtonReleased) return true;
    return false;
}

bool event_escape(sfEvent event)
{
    if (event_getkey(event) == sfKeyEscape) return true;
    return false;
}

bool event_enter(sfEvent event)
{
    if (event_getkey(event) == sfKeySpace || event_getkey(event) == sfKeyEnter)
        return true;
    return false;
}