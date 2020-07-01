/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** destroy
*/

#include "my.h"

void destroy_sound2(all_t *all)
{
    sfSoundBuffer_destroy(all->sound.buff_round);
    sfSoundBuffer_destroy(all->sound.buff_select);
    sfSound_destroy(all->sound.round);
    sfSound_destroy(all->sound.select);
}

void destroy_sound(all_t *all)
{
    sfSoundBuffer_destroy(all->sound.buff_fall);
    sfSoundBuffer_destroy(all->sound.buff_fall2);
    sfSoundBuffer_destroy(all->sound.buff_shoot);
    sfSoundBuffer_destroy(all->sound.buff_wing);
    sfSoundBuffer_destroy(all->sound.buff_intro);
    sfSoundBuffer_destroy(all->sound.buff_menu);
    sfSoundBuffer_destroy(all->sound.buff_menu_select);
    sfSoundBuffer_destroy(all->sound.buff_laugh_dog);
    sfSoundBuffer_destroy(all->sound.buff_success);
    sfSound_destroy(all->sound.fall);
    sfSound_destroy(all->sound.fall2);
    sfSound_destroy(all->sound.shoot);
    sfSound_destroy(all->sound.wing);
    sfSound_destroy(all->sound.intro);
    sfSound_destroy(all->sound.menu);
    sfSound_destroy(all->sound.menu_select);
    sfSound_destroy(all->sound.laugh_dog);
    sfSound_destroy(all->sound.success);
    destroy_sound2(all);
}

void destroy_regroup(all_t *all)
{
    destroy_sound(all);
    sfRenderWindow_destroy(all->window);
}