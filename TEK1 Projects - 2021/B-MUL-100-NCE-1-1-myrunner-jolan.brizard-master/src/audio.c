/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** audio function
*/

#include "../include/project.h"

void set_audio(t_window *window)
{
    window->sound_buf = sfSoundBuffer_createFromFile("./sound/runner.ogg");
    window->sound = sfSound_create();
    window->death_buf =
            sfSoundBuffer_createFromFile("./sound/death_sound.wav");
    window->death_sound = sfSound_create();
    sfSound_setBuffer(window->death_sound, window->death_buf);
    sfSound_setLoop(window->sound, sfTrue);
}

void play_music(t_window *audio)
{
    sfSound_setBuffer(audio->sound, audio->sound_buf);
    sfSound_play(audio->sound);
}