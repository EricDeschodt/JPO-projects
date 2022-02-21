/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Event handling
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_EVENTS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_EVENTS_H

#include <SFML/Graphics.h>
#include <stdbool.h>

int event_getkey(sfEvent event);
void event_close(sfRenderWindow *window, sfEvent event);
bool event_isclicked(sfEvent event);
bool event_escape(sfEvent event);
bool event_enter(sfEvent event);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_EVENTS_H
