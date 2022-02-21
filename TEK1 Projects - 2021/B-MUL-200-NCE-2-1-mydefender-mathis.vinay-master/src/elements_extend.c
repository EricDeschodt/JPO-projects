/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** extend verison for element.c
*/

#include "../include/elements.h"
#include "../include/mouse_events.h"

void element_display_x(element_t *e)
{
    if (e->mode == 5) {
        background_display(e->back, e->win);
        scoreboard_display(e->score, e->win);
    }
    if (e->mode == 6) {
        background_display(e->back, e->win);
        htp_display(e->htp, e->win);
    }
    if (e->mode == 7) {
        background_display(e->back, e->win);
        manual_display(e->manual, e->win);
    }
    if (e->mode == 8) {
        background_display(e->back, e->win);
        setting_display(e->setting, e->win);
    }
}
