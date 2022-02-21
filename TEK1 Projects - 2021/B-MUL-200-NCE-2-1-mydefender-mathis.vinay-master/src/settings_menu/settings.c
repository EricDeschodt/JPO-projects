/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle setting menu
*/

#include "../../include/settings.h"
#include "../../include/elements.h"
#include <stdio.h>

void setting_display(setting_t *setting, sfRenderWindow *win)
{
    button_display(setting->r_button, win, true);
    button_display(setting->m_up, win, true);
    button_display(setting->m_down, win, true);
    button_display(setting->s_up, win, true);
    button_display(setting->s_down, win, true);
    button_display(setting->t_up, win, true);
    button_display(setting->t_down, win, true);
    text_display(setting->mnb, win);
    text_display(setting->snb, win);
    text_display(setting->m_text, win);
    text_display(setting->s_text, win);
    text_display(setting->t_text, win);
    text_display(setting->tnb, win);
}

void settings_save_params(setting_t *s)
{
    FILE *file = fopen(".parameters", "w");
    if (!file) return;
    char *string = my_strcat(" ", s->t_str);
    char *substring = my_strcat(s->s_str, string);
    free(string);
    string = my_strcat(" ", substring);
    free(substring);
    substring = my_strcat(s->m_str, string);
    fwrite(substring, my_strlen(substring), 1, file);
    free(string);
    free(substring);
    fclose(file);
}

void setting_destroy(setting_t *setting)
{
    settings_save_params(setting);
    sprite_destroy(setting->s_down);
    sprite_destroy(setting->s_up);
    sprite_destroy(setting->m_down);
    sprite_destroy(setting->m_up);
    sprite_destroy(setting->t_down);
    sprite_destroy(setting->t_up);
    sprite_destroy(setting->r_button);
    text_destroy(setting->mnb);
    text_destroy(setting->snb);
    text_destroy(setting->tnb);
    text_destroy(setting->m_text);
    text_destroy(setting->s_text);
    text_destroy(setting->t_text);
    free(setting->m_str);
    free(setting->t_str);
    free(setting->s_str);
    free(setting);
}
