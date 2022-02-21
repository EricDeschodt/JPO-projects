/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** end menu events
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void end_menu_extend(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->end->score_button, e->win, event)) {
        e->mode = 5;
        scoreboard_set_last_mode(e->score, 4);
        scoreboard_load(e->score,
        e->level->lvl->list_lvl[e->level->lvl->list_index]);
        sprite_set_texturerect_pos(e->back->perso, 0, 67);
    }
    if (button_is_clicked(e->end->exit_button, e->win, event)
        || event_getkey(event) == sfKeyEscape) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_menu, "stop");
        sound_set_status(e->click, "play");
        sfRenderWindow_close(e->win);
    }
    if (button_is_clicked(e->end->htp_button, e->win, event)) {
        e->htp->last_mode = e->mode;
        sprite_set_texturerect_pos(e->back->perso, 0, 67);
        e->mode = 6;
        sound_set_status(e->click, "play");
    }
}

void end_menu(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->end->replay_button, e->win, event) ||
    event_enter(event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_beach, "play");
        music_set_status(e->music_menu, "stop");
        e->mode = 2;
        sound_set_status(e->click, "play");
        main_game_init(e->game,
        e->level->lvl->list_lvl[e->level->lvl->list_index]);
        e->back->time->is_paused = true;
    }
    if (button_is_clicked(e->end->main_menu_button, e->win, event) ||
    event_escape(event)) {
        music_set_status(e->music_beach, "stop");
        music_set_status(e->music_menu, "play");
        e->mode = 0;
        sprite_set_texturerect_pos(e->back->perso, 0, 0);
        sound_set_status(e->click, "play");
    }
    end_menu_extend(e, event);
}