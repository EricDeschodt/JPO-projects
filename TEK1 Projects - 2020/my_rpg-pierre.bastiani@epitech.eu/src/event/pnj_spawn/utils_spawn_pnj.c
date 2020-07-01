/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

void init_pnj_sprite(pnjs *pnj, char *filepath, pos *posi)
{
    pnj->posi = posi;
    pnj->text = sfTexture_createFromFile(filepath, NULL);
    pnj->sprit = sfSprite_create();
    sfSprite_setTexture(pnj->sprit, pnj->text, 0);
    sfSprite_setPosition(pnj->sprit, (sfVector2f){posi->x, posi->y});
}