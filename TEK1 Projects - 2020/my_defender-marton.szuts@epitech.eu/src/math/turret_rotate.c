/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_rotate
*/

#include "defender.h"
#include "utils.h"


int calcul_magnitude(tuto_t *tmp, turret_t *turret)
{
    float vx = tmp->pos.x - turret->pos_c.x;
    float vy = tmp->pos.y - turret->pos_c.y;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}

void rotate_turret_maths2(turret_t *tmp, float dif_angle)
{
    float speed = tmp->r_speed, speed_rad = speed * MY_PI / 180;
    if (((dif_angle < 0 && dif_angle >= -180)
    || (dif_angle < 360 && dif_angle >= 180))
    && (dif_angle < -3 || dif_angle > 3)) {
        if (tmp->rotate > 360) tmp->rotate -= 360;
        tmp->pos_c2.x = ((tmp->pos_c2.x - tmp->pos_c.x) * cos(speed_rad))
        - ((tmp->pos_c2.y - tmp->pos_c.y) * sin(speed_rad)) + tmp->pos_c.x;
        tmp->pos_c2.y = ((tmp->pos_c2.y - tmp->pos_c.y) * cos(speed_rad))
        + ((tmp->pos_c2.x - tmp->pos_c.x) * sin(speed_rad)) + tmp->pos_c.y;
        tmp->rotate += speed;
    } else if (dif_angle < -3 || dif_angle > 3) {
        if (tmp->rotate > 360) tmp->rotate -= 360;
        tmp->pos_c2.x = ((tmp->pos_c2.x - tmp->pos_c.x)
        * cos(speed_rad * -1)) - ((tmp->pos_c2.y - tmp->pos_c.y)
        * sin(speed_rad * -1)) + tmp->pos_c.x;
        tmp->pos_c2.y = ((tmp->pos_c2.y - tmp->pos_c.y)
        * cos(speed_rad * -1)) + ((tmp->pos_c2.x - tmp->pos_c.x)
        * sin(speed_rad * -1)) + tmp->pos_c.y, tmp->rotate -= speed;
    } sfSprite_setRotation(tmp->sprite_c, tmp->rotate);
}

void turret_calibration(float angle_turret, turret_t *tmp)
{
    if (angle_turret >= 268 && angle_turret <= 271) tmp->rotate = 0;
    if (angle_turret >= 313 && angle_turret <= 316) tmp->rotate = 45;
    if (angle_turret >= 358 && angle_turret <= 1) tmp->rotate = 90;
    if (angle_turret >= 43 && angle_turret <= 46) tmp->rotate = 135;
    if (angle_turret >= 88 && angle_turret <= 91) tmp->rotate = 180;
    if (angle_turret >= 134 && angle_turret <= 136) tmp->rotate = 225;
    if (angle_turret >= 178 && angle_turret <= 181) tmp->rotate = 270;
    if (angle_turret >= 223 && angle_turret <= 226) tmp->rotate = 315;
}

void rotate_loop(all_t *s_all, turret_t *tmp)
{
    targetting_selector(s_all, tmp);
    if (tmp->locked != NULL) {
        float angle_mob = atan2(tmp->locked->pos.y - (tmp->pos_c.y),
            tmp->locked->pos.x - (tmp->pos_c.x));
        float angle_turret = atan2(tmp->pos_c2.y - (tmp->pos_c.y),
            tmp->pos_c2.x - (tmp->pos_c.x));
        angle_mob = angle_mob * 180 / MY_PI;
        angle_turret = angle_turret * 180 / MY_PI;
        angle_turret -= 90;
        if (angle_mob < 0) angle_mob = 360 + angle_mob;
        if (angle_turret < 0) angle_turret = 360 + angle_turret;
        float dif_angle = angle_turret - angle_mob;
        if (tmp->rotate > 360) tmp->rotate -= 360;
        if (dif_angle >= -3 && dif_angle <= 3)
            turret_shoot(tmp, dif_angle, s_all);
        turret_calibration(angle_turret, tmp);
        rotate_turret_maths2(tmp, dif_angle);
    }
}

void rotate_turret_maths(all_t *s_all)
{
    if (s_all->s_game.pause == 1) return;
    if (s_all->s_turret == NULL) {
        correct_slow(s_all);
        return;
    } correct_slow(s_all);
    turret_t *tmp = s_all->s_turret;
    while (tmp != NULL) {
        if (tmp->type == 4) {
            tmp->rotate += 5;
            sfSprite_setRotation(tmp->sprite_c, tmp->rotate);
            slow_mobs_in_range(tmp, s_all);
        } else {
            rotate_loop(s_all, tmp);
        } tmp = tmp->next;
    }
}