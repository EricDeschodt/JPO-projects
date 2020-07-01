/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** destroy_sounds
*/

#include "defender.h"

void destroy_sounds(all_t *s_all)
{
    sfSound_destroy(s_all->s_sounds.button);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_button);
    sfSound_destroy(s_all->s_sounds.build);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_build);
    sfSound_destroy(s_all->s_sounds.upgrade);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_upgrade);
    sfSound_destroy(s_all->s_sounds.sell);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_sell);
    sfSound_destroy(s_all->s_sounds.reached);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_reached);
    sfSound_destroy(s_all->s_sounds.ability);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_ability);
    sfSound_destroy(s_all->s_sounds.defeat);
    sfSoundBuffer_destroy(s_all->s_sounds.buff_defeat);
}

void destroy_music(all_t *s_all)
{
    sfMusic_destroy(s_all->s_menu.main_theme);
    destroy_sounds(s_all);
}