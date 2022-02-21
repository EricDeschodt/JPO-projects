/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** scoreboard events
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void scoreboard_menu(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->score->return_btn, e->win, event) ||
    event_escape(event) || event_enter(event)) {
        sound_set_status(e->click, "play");
        if (e->score->last_mode == 4)
            sprite_set_texturerect_pos(e->back->perso, 0, 134);
        e->mode = e->score->last_mode;
    }
}