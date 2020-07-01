/*
** EPITECH PROJECT, 2020
** life
** File description:
** rpg
*/

#include "../../include/include.h"

void life2(mobs *mob)
{
    if (mob->statu_ennemi == 3) {
            mob->life_ennemi = mob->life_ennemi - 3;
        if (mob->life_ennemi < 0)
            mob->life_ennemi = 0;
        mob->life_sacha = mob->life_sacha - 2;
        mob->statu_ennemi = 0;
    }
    if (mob->statu_ennemi == 4) {
            mob->life_ennemi = mob->life_ennemi - 4;
        if (mob->life_ennemi < 0)
            mob->life_ennemi = 0;
        mob->life_sacha = mob->life_sacha - 2;
        mob->statu_ennemi = 0;
    }
}

void life(mobs *mob)
{
    if (sfClock_getElapsedTime(mob->clock_attaque).microseconds < 1000000)
        return;
    if (mob->statu_ennemi == 1) {
            mob->life_ennemi = mob->life_ennemi - 1;
            if (mob->life_ennemi < 0)
                mob->life_ennemi = 0;
            mob->life_sacha = mob->life_sacha - 2;
            mob->statu_ennemi = 0;
    }
    if (mob->statu_ennemi == 2) {
            mob->life_ennemi = mob->life_ennemi - 2;
            if (mob->life_ennemi < 0)
                mob->life_ennemi = 0;
            mob->life_sacha = mob->life_sacha - 1;
            mob->statu_ennemi = 0;
    }
    life2(mob);
}