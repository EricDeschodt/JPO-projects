/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** yoyo
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void main_menu(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->main->exit_button, e->win, event) ||
    event_escape(event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_menu, "stop");
        sound_set_status(e->click, "play");
        sfRenderWindow_close(e->win);
    }
    if (button_is_clicked(e->main->play_button, e->win, event) ||
    event_enter(event)) {
        sound_set_status(e->click, "play");
        level_menu_init(e->level);
        e->mode = 1;
    }
    if (button_is_clicked(e->main->setting_b, e->win, event)) {
        e->setting->last_mode = e->mode;
        sound_set_status(e->click, "play");
        sprite_set_texturerect_pos(e->back->perso, 0, 67);
        e->mode = 8;
    }
}