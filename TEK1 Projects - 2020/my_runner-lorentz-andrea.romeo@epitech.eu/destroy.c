/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** destroy
*/

#include "my.h"

void destroy_sound_punches(all_t *all)
{
    sfSoundBuffer_destroy(all->sound.buff_jab);
    sfSound_destroy(all->sound.jab);
    sfSoundBuffer_destroy(all->sound.buff_upper_cut);
    sfSound_destroy(all->sound.upper_cut);
    sfSoundBuffer_destroy(all->sound.buff_right_hook);
    sfSound_destroy(all->sound.right_hook);
    sfSoundBuffer_destroy(all->sound.buff_right_cross);
    sfSound_destroy(all->sound.right_cross);
    sfSoundBuffer_destroy(all->sound.buff_left_hook);
    sfSound_destroy(all->sound.left_hook);
}

void destroy_sound(all_t *all)
{
    sfSoundBuffer_destroy(all->sound.buff_heehee);
    sfSound_destroy(all->sound.heehee);
    sfSoundBuffer_destroy(all->sound.buff_whosbad);
    sfSound_destroy(all->sound.whosbad);
    sfMusic_destroy(all->music);
    sfSoundBuffer_destroy(all->sound.buff_da);
    sfSound_destroy(all->sound.da);
    sfSoundBuffer_destroy(all->sound.buff_ouw);
    sfSound_destroy(all->sound.ouw);
    sfSoundBuffer_destroy(all->sound.buff_shamone);
    sfSound_destroy(all->sound.shamone);
    sfSoundBuffer_destroy(all->sound.buff_skull);
    sfSound_destroy(all->sound.skull);
    sfSoundBuffer_destroy(all->sound.buff_scream);
    sfSound_destroy(all->sound.scream);
    destroy_sound_punches(all);
}

void destroy_regroup(all_t *all)
{
    destroy_sound(all);
    sfRenderWindow_destroy(all->window);
}