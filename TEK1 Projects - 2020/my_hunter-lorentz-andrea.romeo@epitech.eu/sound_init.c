/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sound_init
*/

#include "my.h"

void sound_init2(sound_t *sound)
{
    sound->fall2 = sfSound_create();
    sound->buff_fall2 = sfSoundBuffer_createFromFile("sound/fall.ogg");
    sfSound_setBuffer(sound->fall2, sound->buff_fall2);
    sound->laugh_dog = sfSound_create();
    sound->buff_laugh_dog = sfSoundBuffer_createFromFile("sound/laugh.ogg");
    sfSound_setBuffer(sound->laugh_dog, sound->buff_laugh_dog);
    sound->success = sfSound_create();
    sound->buff_success = sfSoundBuffer_createFromFile("sound/success.ogg");
    sfSound_setBuffer(sound->success, sound->buff_success);
    sound->round = sfSound_create();
    sound->buff_round = sfSoundBuffer_createFromFile("sound/round.ogg");
    sfSound_setBuffer(sound->round, sound->buff_round);
    sound->select = sfSound_create();
    sound->buff_select = sfSoundBuffer_createFromFile("sound/select.ogg");
    sfSound_setBuffer(sound->select, sound->buff_select);
}

void sound_init(sound_t *sound)
{
    sound->shoot = sfSound_create();
    sound->buff_shoot = sfSoundBuffer_createFromFile("sound/shoot.ogg");
    sfSound_setBuffer(sound->shoot, sound->buff_shoot);
    sound->fall = sfSound_create();
    sound->buff_fall = sfSoundBuffer_createFromFile("sound/fall.ogg");
    sfSound_setBuffer(sound->fall, sound->buff_fall);
    sound->wing = sfSound_create();
    sound->buff_wing = sfSoundBuffer_createFromFile("sound/wing.ogg");
    sfSound_setBuffer(sound->wing, sound->buff_wing);
    sound->intro = sfSound_create();
    sound->buff_intro = sfSoundBuffer_createFromFile("sound/intro.ogg");
    sfSound_setBuffer(sound->intro, sound->buff_intro);
    sound->menu = sfSound_create();
    sound->buff_menu = sfSoundBuffer_createFromFile("sound/menu.ogg");
    sfSound_setBuffer(sound->menu, sound->buff_menu);
    sound->menu_select = sfSound_create();
    sound->buff_menu_select =
        sfSoundBuffer_createFromFile("sound/menu_select.ogg");
    sfSound_setBuffer(sound->menu_select, sound->buff_menu_select);
    sound_init2(sound);
}