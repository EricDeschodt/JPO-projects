/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** turrets
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TURRETS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TURRETS_H

#include "../time.h"
#include "../libs.h"
#include "init_enemies.h"

typedef struct {
    sfSprite *bullet;
    int dist;
    enemy_t *e;
} bullet_t;

typedef struct {
    sfSprite *turret;
    bullet_t **bullets;
    int mode;
    int ad;
    int range;
    double dps;
    _time_t *time;
    sound_t *gunfire;
    int cost;
    bool upgraded;
} turret_t;

double to_degrees(double radian);
float get_angle(float x, float y, float x1, float y1);
void turret_destroy(turret_t *turret);
void turrets_destroy(turret_t **turret_list);
void bullet_destroy(bullet_t *bullet);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TURRETS_H
