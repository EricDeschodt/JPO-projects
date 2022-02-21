/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** create the setting struct
*/

#include "../../include/settings.h"
#include "../../include/elements.h"

void set_button(setting_t *setting)
{
    setting->r_button =
        button_create("assets/gui/return_button.png", "C");
    setting->m_down = button_create("assets/gui/moins_button.png", "C");
    setting->s_down = button_create("assets/gui/moins_button.png", "C");
    setting->m_up = button_create("assets/gui/plus_button.png", "C");
    setting->s_up = button_create("assets/gui/plus_button.png", "C");
    setting->t_down = button_create("assets/gui/moins_button.png", "C");
    setting->t_up = button_create("assets/gui/plus_button.png", "C");
    sprite_set_pos(setting->r_button, 960, 850, 1);
    sprite_set_pos(setting->m_down, 700, 220, 0.8);
    sprite_set_pos(setting->m_up, 1300, 220, 0.8);
    sprite_set_pos(setting->s_down, 700, 420, 0.8);
    sprite_set_pos(setting->s_up, 1300, 420, 0.8);
    sprite_set_pos(setting->t_down, 700, 620, 0.8);
    sprite_set_pos(setting->t_up, 1300, 620, 0.8);
}

void set_text(setting_t *setting)
{
    setting->m_text = text_create("Music:", "C", sfWhite, false);
    text_set_pos(setting->m_text, 200, 200, 60);
    text_set_outline(setting->m_text, sfBlack, 1);
    setting->t_text = text_create("SFX:", "C", sfWhite, false);
    text_set_pos(setting->t_text, 200, 600, 60);
    text_set_outline(setting->t_text, sfBlack, 1);
    setting->s_text = text_create("Sound:", "C", sfWhite, false);
    text_set_pos(setting->s_text, 200, 400, 60);
    text_set_outline(setting->s_text, sfBlack, 1);
    setting->mnb = text_create(int_to_str(setting->m_str, setting->m_volume),
                                "C", sfWhite, false);
    setting->snb = text_create(int_to_str(setting->s_str, setting->s_volume),
                                "C", sfWhite, false);
    text_set_pos(setting->mnb, 960, 200, 60);
    text_set_outline(setting->mnb, sfBlack, 1);
    text_set_pos(setting->snb, 960, 400, 60);
    text_set_outline(setting->snb, sfBlack, 1);
}

void init_params(setting_t *s)
{
    if (!my_is_file_valid(".parameters")) {
        s->s_volume = 100;
        s->m_volume = 100;
        s->t_volume = 100;
        return;
    }
    char *buf = my_get_file_ctn(".parameters");
    char **array = my_str_to_word_array(buf);
    free(buf);
    s->s_volume = (int)check_volume_value((float)my_getnbr(array[1]), 100);
    s->m_volume = (int)check_volume_value((float)my_getnbr(array[0]), 100);
    s->t_volume = (int)check_volume_value((float)my_getnbr(array[2]), 100);
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

setting_t *setting_create(void)
{
    setting_t *setting = malloc(sizeof(setting_t));
    set_button(setting);
    init_params(setting);
    setting->m_str = malloc(sizeof(char) * 100 + 1);
    setting->s_str = malloc(sizeof(char) * 100 + 1);
    setting->t_str = malloc(sizeof(char) * 100 + 1);
    set_text(setting);
    setting->tnb = text_create(int_to_str(setting->t_str, setting->t_volume),
                                "C", sfWhite, false);
    text_set_pos(setting->tnb, 960, 600, 60);
    text_set_outline(setting->tnb, sfBlack, 1);
    return setting;
}
