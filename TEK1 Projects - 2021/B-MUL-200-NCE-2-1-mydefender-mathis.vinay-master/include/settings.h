/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** settings menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SETTINGS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SETTINGS_H

#include "libs.h"

typedef struct {
    sprite_t *m_down;
    sprite_t *m_up;
    sprite_t *s_down;
    sprite_t *s_up;
    sprite_t *t_down;
    sprite_t *t_up;
    sprite_t *r_button;
    text_t *m_text;
    text_t *s_text;
    text_t *t_text;
    text_t *mnb;
    text_t *snb;
    text_t *tnb;
    int m_volume;
    int s_volume;
    int t_volume;
    char *m_str;
    char *s_str;
    char *t_str;
    int last_mode;
}setting_t;

void set_text(setting_t *setting);
setting_t *setting_create(void);
void setting_display(setting_t *setting, sfRenderWindow *win);
void setting_destroy(setting_t *setting);
float check_volume_value(float volume, int max);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SETTINGS_H
