/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a struct for handling time with precision
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TIME_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TIME_H

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    sfClock *clock;
    bool is_paused;
    long long int counter;
    long long int counter_2;
    long long int counter_3;
    long long int counter_4;
    float counter_dps;
    long long int counter_5;
} _time_t;

_time_t *time_create();
void time_update(_time_t *time, double degree);
void time_destroy(_time_t *clock);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TIME_H
