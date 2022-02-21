/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Settings menu events handler
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void settings_events_extend(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->setting->s_up, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_sound_up(e);
    }
    if (button_is_clicked(e->setting->s_down, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_sound_down(e);
    }
    if (button_is_clicked(e->setting->t_up, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_game_up(e);
    }
    if (button_is_clicked(e->setting->t_down, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_game_down(e);
    }
}

void settings_events(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->setting->r_button, e->win, event)
        || event_escape(event) || event_enter(event)) {
        sound_set_status(e->click, "play");
        if (e->setting->last_mode == 3) {
            music_set_status(e->music_beach, "pause");
            music_set_status(e->music_menu, "stop");
        }
        e->mode = e->setting->last_mode;
    }
    if (button_is_clicked(e->setting->m_up, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_music_up(e);
    }
    if (button_is_clicked(e->setting->m_down, e->win, event)) {
        sound_set_status(e->rollover, "play");
        setting_update_music_down(e);
    }
    settings_events_extend(e, event);
}