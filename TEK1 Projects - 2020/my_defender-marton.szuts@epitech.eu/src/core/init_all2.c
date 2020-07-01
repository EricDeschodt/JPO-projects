/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_all2
*/

#include "defender.h"

void init_turret_texture2(all_t *s_all)
{
    s_all->turret_texture.turret3_foundation =
    sfTexture_createFromFile("sprites/upgrades/turret3_foundation.png", NULL);
    s_all->turret_texture.turret3_long =
    sfTexture_createFromFile("sprites/upgrades/turret3_long.png", NULL);
    s_all->turret_texture.turret3_shrapnel =
    sfTexture_createFromFile("sprites/upgrades/turret3_shrapnel.png", NULL);
    s_all->turret_texture.turret3_speed =
    sfTexture_createFromFile("sprites/upgrades/turret3_speed.png", NULL);
    s_all->turret_texture.turret4_slow =
    sfTexture_createFromFile("sprites/upgrades/turret4_slow.png", NULL);
    s_all->turret_texture.turret4_cold =
    sfTexture_createFromFile("sprites/upgrades/turret4_cold.png", NULL);
    s_all->turret_texture.turret4_system =
    sfTexture_createFromFile("sprites/upgrades/turret4_system.png", NULL);
    s_all->turret_texture.turret4_snowball =
    sfTexture_createFromFile("sprites/upgrades/turret4_snowball.png", NULL);
    s_all->s_menu.lost = sfSprite_create();
    s_all->s_menu.lost_tx = sfTexture_createFromFile("sprites/lost.png", NULL);
    sfSprite_setTexture(s_all->s_menu.lost, s_all->s_menu.lost_tx, sfTrue);
    sfSprite_setPosition(s_all->s_menu.lost, (sfVector2f){725, 100});
}

void init_turret_texture(all_t *s_all)
{
    s_all->turret_texture.turret1_dual =
    sfTexture_createFromFile("sprites/upgrades/turret1_dual_canon.png", NULL);
    s_all->turret_texture.turret1_foundation =
    sfTexture_createFromFile("sprites/upgrades/turret1_foundation.png", NULL);
    s_all->turret_texture.turret1_value =
    sfTexture_createFromFile("sprites/upgrades/turret1_value.png", NULL);
    s_all->turret_texture.turret1_large =
    sfTexture_createFromFile("sprites/upgrades/turret1_large.png", NULL);
    s_all->turret_texture.turret2_heavy =
    sfTexture_createFromFile("sprites/upgrades/turret2_heavy.png", NULL);
    s_all->turret_texture.turret2_speed =
    sfTexture_createFromFile("sprites/upgrades/turret2_speed.png", NULL);
    s_all->turret_texture.turret2_killshot =
    sfTexture_createFromFile("sprites/upgrades/turret2_killshot.png", NULL);
    s_all->turret_texture.turret2_long =
    sfTexture_createFromFile("sprites/upgrades/turret2_long.png", NULL);
    init_turret_texture2(s_all);
}