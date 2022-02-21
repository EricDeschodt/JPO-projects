/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** audio struct fnc
*/

#include "../include/audio.h"

audio_t *create_audio(void)
{
    audio_t *audio = malloc(sizeof(audio_t));
    audio->music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(audio->music, sfTrue);
    sfMusic_setVolume(audio->music, 20);
    audio->jump = sfSound_create();
    audio->jump_buf = sfSoundBuffer_createFromFile("assets/jump.ogg");
    sfSound_setBuffer(audio->jump, audio->jump_buf);
    audio->death = sfSound_create();
    audio->death_buf = sfSoundBuffer_createFromFile("assets/death.ogg");
    sfSound_setBuffer(audio->death, audio->death_buf);
    sfSound_setVolume(audio->death, 40);
    audio->win = sfSound_create();
    audio->win_buf = sfSoundBuffer_createFromFile("assets/win.ogg");
    sfSound_setBuffer(audio->win, audio->win_buf);
    sfSound_setVolume(audio->win, 40);
    return audio;
}

void destroy_audio(audio_t *audio)
{
    sfMusic_destroy(audio->music);
    sfSound_destroy(audio->jump);
    sfSoundBuffer_destroy(audio->jump_buf);
    sfSound_destroy(audio->death);
    sfSoundBuffer_destroy(audio->death_buf);
    sfSound_destroy(audio->win);
    sfSoundBuffer_destroy(audio->win_buf);
    free(audio);
}