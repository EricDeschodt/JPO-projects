/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** structure to handle multiple elements
*/
#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_ELEMENTS_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_ELEMENTS_H

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "my.h"
#include "graphical_funcs.h"
#include "backgrounds.h"
#include "time.h"
#include "score.h"
#include "character_interactions.h"
#include "audio.h"
#include "interface.h"

typedef struct {
    short menu;
    sfRenderWindow *window;
    backgrounds_t *b;
    map_t *map;
    character_t *chr;
    _time_t *time;
    audio_t *audio;
    score_t *score;
    interface_t *interface;

} elements_t;

elements_t *create_elements(char *filename);
elements_t *display_elements(elements_t *e);
bool animate_elements(elements_t *e);
void destroy_elements(elements_t *e);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_ELEMENTS_H
