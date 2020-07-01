/*
** EPITECH PROJECT, 2020
** utils
** File description:
** mob
*/

#include "include.h"

void init_mob_sprite(mobs *mob, char *filepath, pos *posi)
{
    mob->posi = posi;
    mob->text = sfTexture_createFromFile(filepath, NULL);
    mob->sprit = sfSprite_create();
    sfSprite_setTexture(mob->sprit, mob->text, 0);
    sfSprite_setPosition(mob->sprit, (sfVector2f){posi->x, posi->y});
}