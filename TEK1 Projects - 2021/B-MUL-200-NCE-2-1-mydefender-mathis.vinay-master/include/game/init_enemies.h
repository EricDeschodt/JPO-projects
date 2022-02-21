/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** initialize enemies
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_INIT_ENEMIES_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_INIT_ENEMIES_H

#include "../libs.h"

typedef struct {
    sfSprite *enemy;
    sfSprite *life_front;
    sfSprite *life_back;
    int max_health;
    int health;
    int gold;
    bool is_spawned;
    float global_speed;
    float speed_x;
    float speed_y;
    int last_x;
    int last_y;
} enemy_t;

void free_enemy(enemy_t **enemy);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_INIT_ENEMIES_H
