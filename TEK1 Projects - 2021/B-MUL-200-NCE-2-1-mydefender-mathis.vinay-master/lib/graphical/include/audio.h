/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates sound
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_AUDIO_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_AUDIO_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../strings/include/strings.h"
#include "../../files/include/files.h"

typedef struct {
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
    int volume;
}sound_t;

void music_destroy(sfMusic *music);
void music_set_status(sfMusic *music, char *status);
sfMusic *music_create(char *path, bool loop, float volume);

sound_t *sound_create(char *path, bool loop, int volume);
void sound_set_status(sound_t *sound, char *status);
void sound_set_volume(sound_t *sound, float update);
void sound_destroy(sound_t *sound);
void music_set_volume(sfMusic *music, float volume);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_AUDIO_H
