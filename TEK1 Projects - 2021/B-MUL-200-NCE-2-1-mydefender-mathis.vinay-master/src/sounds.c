/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** the sound functions
*/

#include "../include/elements.h"

void sounds_create(element_t *e)
{
    e->click = sound_create("assets/audio/click1.ogg", false,
    (e->setting->s_volume));
    e->rollover = sound_create("assets/audio/rollover2.ogg", false,
    e->setting->s_volume);
    e->music_menu = music_create("assets/audio/crypt.ogg", true,
    (float)(e->setting->m_volume) / 5);
    e->music_beach = music_create("assets/audio/gerudo.ogg", true,
    (float)(e->setting->m_volume) / 5);
    music_set_status(e->music_menu, "play");
}

void sounds_destroy(element_t *e)
{
    sound_destroy(e->click);
    sound_destroy(e->rollover);
    music_destroy(e->music_menu);
    music_destroy(e->music_beach);
    setting_destroy(e->setting);
}