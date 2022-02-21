/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** manual button management
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void manual_events(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->manual->return_button, e->win, event) ||
    event_escape(event) || event_enter(event)) {
        sound_set_status(e->click, "play");
        e->mode = 6;
    }
}