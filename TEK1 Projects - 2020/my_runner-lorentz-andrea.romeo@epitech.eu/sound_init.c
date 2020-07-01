/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sound_init
*/

#include "my.h"

void sound_init2(sound_t *sound)
{
    sound->scream = sfSound_create();
    sound->buff_scream = sfSoundBuffer_createFromFile("sounds/scream.ogg");
    sfSound_setBuffer(sound->scream, sound->buff_scream);
}

void sound_init_punches(sound_t *sound)
{
    sound->upper_cut = sfSound_create();
    sound->buff_upper_cut =
        sfSoundBuffer_createFromFile("sounds/upper_cut.ogg");
    sfSound_setBuffer(sound->upper_cut, sound->buff_upper_cut);
    sound->jab = sfSound_create();
    sound->buff_jab = sfSoundBuffer_createFromFile("sounds/jab.ogg");
    sfSound_setBuffer(sound->jab, sound->buff_jab);
    sound->right_cross = sfSound_create();
    sound->buff_right_cross =
        sfSoundBuffer_createFromFile("sounds/right_cross.ogg");
    sfSound_setBuffer(sound->right_cross, sound->buff_right_cross);
    sound->right_hook = sfSound_create();
    sound->buff_right_hook =
        sfSoundBuffer_createFromFile("sounds/right_hook.ogg");
    sfSound_setBuffer(sound->right_hook, sound->buff_right_hook);
    sound->left_hook = sfSound_create();
    sound->buff_left_hook =
        sfSoundBuffer_createFromFile("sounds/left_hook.ogg");
    sfSound_setBuffer(sound->left_hook, sound->buff_left_hook);
    sound_init2(sound);
}

void sound_init(sound_t *sound)
{
    sound->heehee = sfSound_create();
    sound->buff_heehee = sfSoundBuffer_createFromFile("sounds/heehee.ogg");
    sfSound_setBuffer(sound->heehee, sound->buff_heehee);
    sound->whosbad = sfSound_create();
    sound->buff_whosbad = sfSoundBuffer_createFromFile("sounds/whosbad.ogg");
    sfSound_setBuffer(sound->whosbad, sound->buff_whosbad);
    sound->da = sfSound_create();
    sound->buff_da = sfSoundBuffer_createFromFile("sounds/da.ogg");
    sfSound_setBuffer(sound->da, sound->buff_da);
    sound->ouw = sfSound_create();
    sound->buff_ouw = sfSoundBuffer_createFromFile("sounds/ouw.ogg");
    sfSound_setBuffer(sound->ouw, sound->buff_ouw);
    sound->shamone = sfSound_create();
    sound->buff_shamone = sfSoundBuffer_createFromFile("sounds/shamone.ogg");
    sfSound_setBuffer(sound->shamone, sound->buff_shamone);
    sound->skull = sfSound_create();
    sound->buff_skull = sfSoundBuffer_createFromFile("sounds/skull.ogg");
    sfSound_setBuffer(sound->skull, sound->buff_skull);
    sound_init_punches(sound);
}