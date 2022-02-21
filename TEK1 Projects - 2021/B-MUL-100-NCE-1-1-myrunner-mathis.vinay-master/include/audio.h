/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** aduio struct
*/
#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_SOUNDS_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_SOUNDS_H

#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

typedef struct {
    sfMusic *music;
    sfSound *jump;
    sfSoundBuffer *jump_buf;
    sfSound *death;
    sfSoundBuffer *death_buf;
    sfSound *win;
    sfSoundBuffer *win_buf;
} audio_t;

audio_t *create_audio(void);
void destroy_audio(audio_t *audio);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_SOUNDS_H
