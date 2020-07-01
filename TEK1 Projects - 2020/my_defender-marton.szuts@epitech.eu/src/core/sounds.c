/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** sounds
*/

#include "defender.h"

void button_sound(all_t *s_all)
{
    if (s_all->s_settings->sound == 1) sfSound_play(s_all->s_sounds.button);
}

void init_sounds2(all_t *s_all)
{
    s_all->s_sounds.reached = sfSound_create();
    s_all->s_sounds.buff_reached =
        sfSoundBuffer_createFromFile("sounds/reached.wav");
    sfSound_setBuffer(s_all->s_sounds.reached, s_all->s_sounds.buff_reached);
    s_all->s_sounds.ability = sfSound_create();
    s_all->s_sounds.buff_ability =
        sfSoundBuffer_createFromFile("sounds/ability.wav");
    sfSound_setBuffer(s_all->s_sounds.ability, s_all->s_sounds.buff_ability);
    s_all->s_sounds.defeat = sfSound_create();
    s_all->s_sounds.buff_defeat =
        sfSoundBuffer_createFromFile("sounds/defeat.wav");
    sfSound_setBuffer(s_all->s_sounds.defeat, s_all->s_sounds.buff_defeat);
}

void init_sounds(all_t *s_all)
{
    s_all->s_sounds.button = sfSound_create();
    s_all->s_sounds.buff_button =
        sfSoundBuffer_createFromFile("sounds/button.wav");
    sfSound_setBuffer(s_all->s_sounds.button, s_all->s_sounds.buff_button);
    s_all->s_sounds.build = sfSound_create();
    s_all->s_sounds.buff_build =
        sfSoundBuffer_createFromFile("sounds/build.wav");
    sfSound_setBuffer(s_all->s_sounds.build, s_all->s_sounds.buff_build);
    s_all->s_sounds.upgrade = sfSound_create();
    s_all->s_sounds.buff_upgrade =
        sfSoundBuffer_createFromFile("sounds/upgrade.wav");
    sfSound_setBuffer(s_all->s_sounds.upgrade, s_all->s_sounds.buff_upgrade);
    s_all->s_sounds.sell = sfSound_create();
    s_all->s_sounds.buff_sell =
        sfSoundBuffer_createFromFile("sounds/sell.wav");
    sfSound_setBuffer(s_all->s_sounds.sell, s_all->s_sounds.buff_sell);
    init_sounds2(s_all);
}