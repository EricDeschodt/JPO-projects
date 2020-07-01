/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_aoe
*/

#include "defender.h"
#include "utils.h"

void mob_life_bar_aoe(tuto_t *tmp, turret_t *turret, all_t *s_all)
{
    float x = 0;
    if (tmp->id == 1) x = 60.0 * (tmp->life / 100.0);
    else if (tmp->id == 2) x = 60.0 * (tmp->life / 200.0);
    else x = 60.0 * (tmp->life / 65.0);
    if (x < 0) x = 0;
    sfRectangleShape_setSize(tmp->life_bar, (sfVector2f){x, 5});
    if (x <= 45.0) sfRectangleShape_setFillColor(tmp->life_bar,
            (sfColor){255, 215, 0, 200});
    if (x <= 30.0) sfRectangleShape_setFillColor(tmp->life_bar,
            (sfColor){255, 127, 80, 200});
    if (x <= 15.0) sfRectangleShape_setFillColor(tmp->life_bar,
            (sfColor){255, 0, 0, 200});
    if (tmp->life <= 0) {
        turret_level_up(turret);
        sfRectangleShape_setSize(turret->xp_bar, (sfVector2f){turret->xp, 20});
        get_money_by_mobs(s_all);
        tmp->state = -1;
    }
}

int calcul_magnitude_aoe(tuto_t *locked, tuto_t *tmp)
{
    float vx = tmp->pos.x - locked->pos.x;
    float vy = tmp->pos.y - locked->pos.y;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}

void check_aoe(all_t *s_all, turret_t *turret, tuto_t *tmp)
{
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp == turret->locked) continue;
        float magnitude = calcul_magnitude_aoe(turret->locked, tmp);
        if (magnitude <= 50) {
            tmp->life -= turret->dmg;
            mob_life_bar_aoe(tmp, turret, s_all);
        }
    }
}

void turret_aoe(all_t *s_all, turret_t *turret)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    check_aoe(s_all, turret, tmp);
    tmp = s_all->s_wave_c.square;
    check_aoe(s_all, turret, tmp);
    tmp = s_all->s_wave_c.triangle;
    check_aoe(s_all, turret, tmp);
}