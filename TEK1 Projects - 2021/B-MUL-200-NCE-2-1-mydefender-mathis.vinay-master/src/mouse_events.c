/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handles the corresponding mouse interaction (looking at mode)
*/

#include "../include/elements.h"
#include "../include/mouse_events.h"

bool mouse_events3(element_t *e, sfEvent event)
{
    if (e->mode == 7) {
        manual_events(e, event);
        return true;
    }
    if (e->mode == 8) {
        settings_events(e, event);
        return true;
    }
    return false;
}

bool mouse_events2(element_t *e, sfEvent event)
{
    if (e->mode == 4) {
        end_menu(e, event);
        return true;
    }
    if (e->mode == 3) {
        pause_menu(e, event);
        return true;
    }
    if (e->mode == 5) {
        scoreboard_menu(e, event);
        return true;
    }
    if (e->mode == 6) {
        htp_events(e, event);
        return true;
    }
    return false;
}

bool mouse_events(element_t *e, sfEvent event)
{
    if (e->mode == 2) {
        game_menu(e, event);
        upgrade_event(e, event);
        return true;
    }
    if (e->mode == 1) {
        level_menu(e, event);
        return true;
    }
    if (e->mode == 0) {
        main_menu(e, event);
        return true;
    }
    if (mouse_events3(e, event)) return true;
    if (mouse_events2(e, event)) return true;
    return false;
}