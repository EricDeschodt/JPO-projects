/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_env.c
*/

#include <stdlib.h>
#include "defender.h"

menu_t *create_env(void)
{
    sfTexture *map_tx;
    menu_t *g_mn;

    g_mn = malloc(sizeof(menu_t));
    map_tx = sfTexture_createFromFile("assets/textures/game_bg.jpg", NULL);
    g_mn->map = sfSprite_create();
    sfSprite_setTexture(g_mn->map, map_tx, sfTrue);
    return (g_mn);
}
