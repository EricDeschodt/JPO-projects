/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting
*/

#include "defender.h"
#include "utils.h"

void find_pos_closest2(all_t *s_all, turret_t *turret, float *closest,
    tuto_t **locked)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    while (tmp != NULL) {
        if (tmp->state == -1) { tmp = tmp->next;
            continue;
        } float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude < *closest) {
            *closest = magnitude, *locked = tmp;
        } tmp = tmp->next;
    }
}

void find_pos_closest(all_t *s_all, turret_t *turret)
{
    float closest = __INT_MAX__;
    tuto_t *locked = NULL, *tmp = s_all->s_wave_c.square;
    find_pos_closest2(s_all, turret, &closest, &locked);
    while (tmp != NULL) {
        if (tmp->state == -1) { tmp = tmp->next;
            continue;
        } float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude < closest) {
            closest = magnitude, locked = tmp;
        } tmp = tmp->next;
    } tmp = s_all->s_wave_c.triangle;
    while (tmp != NULL) {
        if (tmp->state == -1) { tmp = tmp->next;
            continue;
        } float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude < closest) {
            closest = magnitude, locked = tmp;
        } tmp = tmp->next;
    } lock_target_in_range(turret, locked);
}

void turret_life_bar(turret_t *tmp, all_t *s_all)
{
    float x = 0;
    if (tmp->locked->id == 1) x = 60.0 * (tmp->locked->life / 150.0);
    else if (tmp->locked->id == 2) x = 60.0 * (tmp->locked->life / 300.0);
    else x = 60.0 * (tmp->locked->life / 110.0);
    if (x < 0) x = 0;
    sfRectangleShape_setSize(tmp->locked->life_bar, (sfVector2f){x, 5});
    if (x <= 45.0) sfRectangleShape_setFillColor(tmp->locked->life_bar,
            (sfColor){255, 215, 0, 200});
    if (x <= 30.0) sfRectangleShape_setFillColor(tmp->locked->life_bar,
            (sfColor){255, 127, 80, 200});
    if (x <= 15.0) sfRectangleShape_setFillColor(tmp->locked->life_bar,
            (sfColor){255, 0, 0, 200});
    if (tmp->locked->life <= 0) {
        turret_level_up(tmp);
        sfRectangleShape_setSize(tmp->xp_bar, (sfVector2f){tmp->xp, 20});
        get_money_by_mobs(s_all);
        tmp->locked->state = -1, tmp->locked = NULL;
    }
}

void turret_shoot2(turret_t *tmp, all_t *s_all)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->locked != NULL && tmp->hit != 1 && ((tmp->pos_bullet.x >=
    tmp->locked->pos.x - 25 && tmp->pos_bullet.x <= tmp->locked->pos.x + 25)
    && (tmp->pos_bullet.y >= tmp->locked->pos.y - 25) && (tmp->pos_bullet.y
    <= tmp->locked->pos.y + 25))) {
        tmp->hit = 1, tmp->locked->life -= tmp->dmg;
        if (tmp->type == 3) turret_aoe(s_all, tmp);
        turret_life_bar(tmp, s_all);
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        sfClock_restart(tmp->clock);
    } if (tmp->seconds > tmp->rate_fire && tmp->hit == 1) {
        tmp->shoot = 0, tmp->hit = 0;
        sfClock_restart(tmp->clock);
    }
}

void turret_shoot(turret_t *tmp, float dif_angle, all_t *s_all)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    if (tmp->locked != NULL) {
        if (tmp->price == 0) { tmp->price = 1, tmp->sell /= 2;
            sfText_setString(tmp->sell_txt, strnbr(tmp->sell));
        } if (tmp->shoot == 0 && (dif_angle >= -3 && dif_angle <= 3)) {
            sfClock_restart(tmp->clock);
            tmp->pos_bullet = tmp->pos_c, tmp->shoot = 1;
        } else if (tmp->shoot == 1 && tmp->hit == 0) {
            float vx = tmp->locked->pos.x - tmp->pos_bullet.x;
            float vy = tmp->locked->pos.y - tmp->pos_bullet.y;
            float normalise = sqrt(pow(vx, 2) + pow(vy, 2));
            tmp->pos_bullet.x = tmp->pos_bullet.x
                + (tmp->bullet_speed * (vx / normalise));
            tmp->pos_bullet.y = tmp->pos_bullet.y
                + (tmp->bullet_speed * (vy / normalise));
            sfSprite_setPosition(tmp->bullet, tmp->pos_bullet);
        }
    } turret_shoot2(tmp, s_all);
}