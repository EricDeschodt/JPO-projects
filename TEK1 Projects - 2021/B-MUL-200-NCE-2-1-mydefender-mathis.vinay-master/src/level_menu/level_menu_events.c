/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Level menu events
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void level_events_x(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->level->button_right, e->win, event) ||
        event_getkey(event) == sfKeyRight || event_getkey(event) == sfKeyD) {
        sound_set_status(e->rollover, "play");
        e->level->lvl->list_index += 1;
        levels_update(e->level->lvl);
    } else if (button_is_clicked(e->level->button_left, e->win, event) ||
               event_getkey(event) == sfKeyLeft || event_getkey(event) == sfKeyQ) {
        sound_set_status(e->rollover, "play");
        e->level->lvl->list_index -= 1;
        levels_update(e->level->lvl);
    }
}

void level_menu_select_events(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->level->button_select, e->win, event) ||
    event_enter(event)) {
        music_set_status(e->music_beach, "play");
        music_set_status(e->music_menu, "stop");
        sound_set_status(e->click, "play");
        e->mode = 2;
        time_update(e->level->time, 1.0);
        srand(e->level->time->counter);
        main_game_init(e->game,
        e->level->lvl->list_lvl[e->level->lvl->list_index]);
        e->back->time->is_paused = true;
    }
    level_events_x(e, event);
}

void level_menu_score_events(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->level->button_score, e->win, event)) {
        e->mode = 5;
        sound_set_status(e->click, "play");
        scoreboard_set_last_mode(e->score, 1);
        scoreboard_load(e->score,
        e->level->lvl->list_lvl[e->level->lvl->list_index]);
    }
}

void level_menu(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->level->button_return, e->win, event) ||
    event_escape(event)) {
        e->mode = 0;
        sound_set_status(e->click, "play");
    }
    if (button_is_clicked(e->level->htp_button, e->win, event)) {
        e->htp->last_mode = e->mode;
        e->mode = 6;
        sound_set_status(e->click, "play");
    }
    level_menu_select_events(e, event);
    level_menu_score_events(e, event);
}