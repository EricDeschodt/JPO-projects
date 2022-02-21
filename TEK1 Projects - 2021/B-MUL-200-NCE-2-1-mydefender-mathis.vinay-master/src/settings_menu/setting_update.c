/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** update settings and volume
*/

#include "../../include/settings.h"
#include "../../include/elements.h"

float check_volume_value(float volume, int max)
{
    if (volume > (float) max)
        return (float) max;
    if (volume < 0)
        return 0;
    return volume;
}

void setting_update_music_up(element_t *e)
{
    float current_volume = sfMusic_getVolume(e->music_beach);
    current_volume += (float) 2;
    current_volume = check_volume_value(current_volume, 20);
    music_set_volume(e->music_menu, current_volume);
    music_set_volume(e->music_beach, current_volume);
    e->setting->m_volume += 10;
    e->setting->m_volume = (int)
                check_volume_value((float) e->setting->m_volume, 100);
    sfText_setString(e->setting->mnb->text,
                        int_to_str(e->setting->m_str, e->setting->m_volume));
}

void setting_update_music_down(element_t *e)
{
    float current_volume = sfMusic_getVolume(e->music_beach);
    current_volume -= (float) 2;
    current_volume = check_volume_value(current_volume, 20);
    music_set_volume(e->music_menu, current_volume);
    music_set_volume(e->music_beach, current_volume);
    e->setting->m_volume -= 10;
    e->setting->m_volume = (int)
                check_volume_value((float) e->setting->m_volume, 100);
    sfText_setString(e->setting->mnb->text,
                        int_to_str(e->setting->m_str, e->setting->m_volume));
}

void setting_update_sound_up(element_t *e)
{
    float current_volume = sfSound_getVolume(e->click->sound);
    current_volume += (float) 10;
    current_volume = check_volume_value((float) current_volume, 100);
    sound_set_volume(e->click, current_volume);
    sound_set_volume(e->rollover, current_volume);
    e->setting->s_volume += 10;
    e->setting->s_volume = (int)
                check_volume_value((float) e->setting->s_volume, 100);
    sfText_setString(e->setting->snb->text,
                        int_to_str(e->setting->s_str, e->setting->s_volume));
}

void setting_update_sound_down(element_t *e)
{
    float current_volume = sfSound_getVolume(e->click->sound);
    current_volume -= (float) 10;
    current_volume = check_volume_value((float) current_volume, 100);
    sound_set_volume(e->click, current_volume);
    sound_set_volume(e->rollover, current_volume);
    e->setting->s_volume -= 10;
    e->setting->s_volume = (int)
                check_volume_value((float) e->setting->s_volume, 100);
    sfText_setString(e->setting->snb->text,
                        int_to_str(e->setting->s_str, e->setting->s_volume));
}