/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_turret_abilities
*/

#include "defender.h"

void init_upgrade_texture3(all_t *s_all)
{
    s_all->s_texture.turret4_slow =
        sfTexture_createFromFile("sprites/turret4_slow.png", NULL);
    s_all->s_texture.turret4_cold =
        sfTexture_createFromFile("sprites/turret4_cold.png", NULL);
    s_all->s_texture.turret4_system =
        sfTexture_createFromFile("sprites/turret4_system.png", NULL);
    s_all->s_texture.turret4_snowball =
        sfTexture_createFromFile("sprites/turret4_snowball.png", NULL);
}

void init_upgrade_texture2(all_t *s_all)
{
    s_all->s_texture.turret2_long =
        sfTexture_createFromFile("sprites/turret2_long.png", NULL);
    s_all->s_texture.turret2_heavy =
        sfTexture_createFromFile("sprites/turret2_heavy.png", NULL);
    s_all->s_texture.turret2_killshot =
        sfTexture_createFromFile("sprites/turret2_killshot.png", NULL);
    s_all->s_texture.turret2_speed =
        sfTexture_createFromFile("sprites/turret2_speed.png", NULL);
    s_all->s_texture.turret3_long =
        sfTexture_createFromFile("sprites/turret3_long.png", NULL);
    s_all->s_texture.turret3_shrapnel =
        sfTexture_createFromFile("sprites/turret3_shrapnel.png", NULL);
    s_all->s_texture.turret3_foundation =
        sfTexture_createFromFile("sprites/turret3_foundation.png", NULL);
    s_all->s_texture.turret3_speed =
        sfTexture_createFromFile("sprites/turret3_speed.png", NULL);
    s_all->s_texture.round =
        sfTexture_createFromFile("sprites/under_round.png", NULL);
}

void init_upgrade_texture(all_t *s_all)
{
    s_all->s_texture.clock = sfClock_create();
    s_all->s_texture.bounce = 0;
    s_all->s_texture.alpha = 0;
    s_all->s_texture.square =
        sfTexture_createFromFile("sprites/under_square.png", NULL);
    s_all->s_texture.triangle =
        sfTexture_createFromFile("sprites/under_triangle.png", NULL);
    s_all->s_texture.hexa =
        sfTexture_createFromFile("sprites/under_hexa.png", NULL);
    s_all->s_texture.turret1_dual =
        sfTexture_createFromFile("sprites/turret1_dual_canon.png", NULL);
    s_all->s_texture.turret1_foundation =
        sfTexture_createFromFile("sprites/turret1_foundation.png", NULL);
    s_all->s_texture.turret1_large =
        sfTexture_createFromFile("sprites/turret1_large.png", NULL);
    s_all->s_texture.turret1_value =
        sfTexture_createFromFile("sprites/turret1_value.png", NULL);
    init_upgrade_texture2(s_all);
    init_upgrade_texture3(s_all);
}

abilities_t *init_abilities(all_t *s_all, int type)
{
    abilities_t *head = NULL;

    for (int i = 0; i != 4; i++)
        head = push_front_abilities(s_all, head, type);

    return (head);
}