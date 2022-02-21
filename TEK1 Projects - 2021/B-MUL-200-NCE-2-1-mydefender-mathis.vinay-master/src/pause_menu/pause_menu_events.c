/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** the events of the pause menu
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void pause_menu_extend_x(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->pause->setting_b, e->win, event)) {
        music_set_status(e->music_beach, "pause");
        music_set_status(e->music_menu, "play");
        e->setting->last_mode = e->mode;
        sound_set_status(e->click, "play");
        sprite_set_texturerect_pos(e->back->perso, 0, 67);
        e->mode = 8;
    }
}

void pause_menu_extend(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->pause->restart_button, e->win, event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_beach, "play");
        music_set_status(e->music_menu, "stop");
        e->mode = 2;
        main_game_init(e->game,
                        e->level->lvl->list_lvl[e->level->lvl->list_index]);
        sound_set_status(e->click, "play");
    } if (button_is_clicked(e->pause->exit_button, e->win, event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_menu, "stop");
        sound_set_status(e->click, "play");
        sfRenderWindow_close(e->win);
    } if (button_is_clicked(e->pause->htp_button, e->win, event)) {
        music_set_status(e->music_beach, "pause");
        music_set_status(e->music_menu, "play");
        e->htp->last_mode = e->mode;
        e->mode = 6;
        sound_set_status(e->click, "play");
    }
}

void pause_menu(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->pause->resume_button, e->win, event) ||
    event_escape(event) || event_enter(event)) {
        music_set_status(e->music_beach, "play");
        music_set_status(e->music_menu, "stop");
        e->mode = 2;
        sound_set_status(e->click, "play");
    }
    if (button_is_clicked(e->pause->main_menu_button, e->win, event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_menu, "play");
        e->mode = 0;
        sound_set_status(e->click, "play");
    }
    pause_menu_extend_x(e, event);
    pause_menu_extend(e, event);
}