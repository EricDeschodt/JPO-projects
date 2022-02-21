/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle h2p events
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void htp_events(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->htp->return_button, e->win, event) ||
    event_escape(event)) {
        e->mode = e->htp->last_mode;
        if (e->htp->last_mode == 3) {
            music_set_status(e->music_beach, "pause");
            music_set_status(e->music_menu, "stop");
        }
        if (e->htp->last_mode == 4)
            sprite_set_texturerect_pos(e->back->perso, 0, 134);
        sound_set_status(e->click, "play");
    }
    if (button_is_clicked(e->htp->manual_button, e->win, event) ||
    event_enter(event)) {
        sound_set_status(e->click, "play");
        e->mode = 7;
    }
}