/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** header for the radio_button struct
*/
#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_RADIO_BUTTONS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_RADIO_BUTTONS_H

#include "../../../include/libs.h"

typedef struct {
    int h;
    float x;
    float y;
    int selected;
    sprite_t *selector;
    sprite_t **button_list;
} radio_buttons_t;

radio_buttons_t *radio_buttons_create(int h, char const *selector_path, float
x, float y);
int radio_buttons_len(radio_buttons_t *r);
void radio_buttons_append(radio_buttons_t *r, char const *buttonpath);
void radio_buttons_update_selection(radio_buttons_t *r, sfRenderWindow *win);
void radio_buttons_display(radio_buttons_t *r, struct sfRenderWindow *w,
                            bool should_animate);
void radio_buttons_destroy(radio_buttons_t *r);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_RADIO_BUTTONS_H
