/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates audio
*/

#include "../../include/audio.h"

sound_t *sound_create(char *path, bool loop, int volume)
{
    sound_t *sound = malloc(sizeof(sound_t));
    sound->sound = sfSound_create();
    sound->sound_buffer = NULL;
    if (my_is_file_valid(path)) {
        sound->sound_buffer = sfSoundBuffer_createFromFile(path);
        sfSound_setBuffer(sound->sound, sound->sound_buffer);
    } else
        sound->sound_buffer = NULL;
    sound->volume = volume;
    sfSound_setVolume(sound->sound, (float)volume);
    if (loop)
        sfSound_setLoop(sound->sound, sfTrue);
    return sound;
}

void sound_set_status(sound_t *sound, char *status)
{
    if (my_str_is_equal(status, "play")) {
        sfSound_play(sound->sound);
        return;
    }
    if (my_str_is_equal(status, "pause")) {
        sfSound_pause(sound->sound);
        return;
    }
    if (my_str_is_equal(status, "stop")) {
        sfSound_stop(sound->sound);
        return;
    }
}

void sound_set_volume(sound_t *sound, float update)
{
    if (update < 0 && (float) sound->volume + update < 0) {
        sfSound_setVolume(sound->sound, 0);
        return;
    } if (update < 0 && (float) sound->volume + update >= 0) {
        sfSound_setVolume(sound->sound, (float) sound->volume + update);
        return;
    }
    sfSound_setVolume(sound->sound, update);
}

void sound_destroy(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    if (sound->sound_buffer)
        sfSoundBuffer_destroy(sound->sound_buffer);
    free(sound);
}