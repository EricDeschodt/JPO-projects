/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** sounds
*/

#include "runner.h"

int background_sound(controll_t *s_controll)
{
    s_controll->s_music.background_sound =
    sfMusic_createFromFile("sound/Background_sound.ogg");
    if (!s_controll->s_music.background_sound)
        return (EXIT_FAILURE);
    sfMusic_setLoop(s_controll->s_music.background_sound, sfTrue);
    sfMusic_setVolume(s_controll->s_music.background_sound, 40);
    return (0);
}

int jump_sound(controll_t *s_controll)
{
    s_controll->s_music.jump_sound = sfSound_create();
    s_controll->s_music.buff_jump =
    sfSoundBuffer_createFromFile("sound/jump.ogg");
    sfSound_setBuffer(s_controll->s_music.jump_sound,
    s_controll->s_music.buff_jump);
    sfSound_setVolume(s_controll->s_music.jump_sound, 10);
    return (0);
}

int slide_sound(controll_t *s_controll)
{
    s_controll->s_music.slide_sound = sfSound_create();
    s_controll->s_music.buff_slide =
    sfSoundBuffer_createFromFile("sound/slide.ogg");
    sfSound_setBuffer(s_controll->s_music.slide_sound,
    s_controll->s_music.buff_slide);
    sfSound_setVolume(s_controll->s_music.slide_sound, 100);
    return (0);
}

int coin_sound(controll_t *s_controll)
{
    s_controll->s_music.coin_sound = sfSound_create();
    s_controll->s_music.buff_coin =
    sfSoundBuffer_createFromFile("sound/coin.ogg");
    sfSound_setBuffer(s_controll->s_music.coin_sound,
    s_controll->s_music.buff_coin);
    sfSound_setVolume(s_controll->s_music.coin_sound, 100);
    return (0);
}