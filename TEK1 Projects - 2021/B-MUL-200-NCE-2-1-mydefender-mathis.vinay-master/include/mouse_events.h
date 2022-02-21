/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a header for the mouse_event functions
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MOUSE_EVENTS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MOUSE_EVENTS_H

bool mouse_events(element_t *e, sfEvent event);
void level_menu(element_t *e, sfEvent event);
void end_menu(element_t *e, sfEvent event);
void main_menu(element_t *e, sfEvent event);
void level_menu_select_events(element_t *e, sfEvent event);
void level_menu_score_events(element_t *e, sfEvent event);
void pause_menu(element_t *e, sfEvent event);
void scoreboard_menu(element_t *e, sfEvent event);
void game_menu(element_t *e, sfEvent event);
void htp_events(element_t *e, sfEvent event);
void manual_events(element_t *e, sfEvent event);
void settings_events(element_t *e, sfEvent event);
void upgrade_event(element_t *e, sfEvent event);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MOUSE_EVENTS_H
