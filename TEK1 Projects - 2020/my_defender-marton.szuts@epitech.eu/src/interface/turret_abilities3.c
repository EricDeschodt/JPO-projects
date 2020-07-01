/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_abilities3
*/

#include "defender.h"
#include "utils.h"

void upgrade_abilities_type2_bis2(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 2 && tmp->id == 2) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite_c,
        s_all->turret_texture.turret2_long, sfTrue);
        s_all->s_selected.tur->range *= 1.25;
        s_all->s_selected.tur->range_str =
            strnbr(s_all->s_selected.tur->range);
        sfText_setString(s_all->s_selected.tur->range_txt,
            s_all->s_selected.tur->range_str);
        sfVector2f zone = sfSprite_getScale(s_all->s_selected.tur->zone);
        sfSprite_setScale(s_all->s_selected.tur->zone,
            (sfVector2f){zone.x * 1.25, zone.y * 1.25});
    }
}

void upgrade_abilities_type2_bis(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 2 && tmp->id == 0) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite_c,
        s_all->turret_texture.turret2_speed, sfTrue);
        s_all->s_selected.tur->r_speed *= 1.25;
        s_all->s_selected.tur->bullet_speed *= 1.25;
        s_all->s_selected.tur->b_speed_str =
            strnbr_float(s_all->s_selected.tur->bullet_speed);
        sfText_setString(s_all->s_selected.tur->b_speed_txt,
            s_all->s_selected.tur->b_speed_str);
        s_all->s_selected.tur->r_speed_str =
            strnbr_float(s_all->s_selected.tur->r_speed);
        sfText_setString(s_all->s_selected.tur->r_speed_txt,
            s_all->s_selected.tur->r_speed_str);
    }
}

void upgrade_abilities_type2(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 2 && tmp->id == 1) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret2_heavy, sfTrue);
        s_all->s_selected.tur->dmg *= 1.25;
        s_all->s_selected.tur->dmg_str =
            strnbr(s_all->s_selected.tur->dmg);
        sfText_setString(s_all->s_selected.tur->dmg_txt,
            s_all->s_selected.tur->dmg_str);
    }
    if (s_all->s_selected.tur->type == 2 && tmp->id == 3) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret2_killshot, sfTrue);
        s_all->s_selected.tur->rate_fire /= 1.50;
        s_all->s_selected.tur->rof_str =
            strnbr_float(1 / s_all->s_selected.tur->rate_fire);
        sfText_setString(s_all->s_selected.tur->rof_txt,
            s_all->s_selected.tur->rof_str);
    }
    upgrade_abilities_type2_bis(s_all, tmp);
    upgrade_abilities_type2_bis2(s_all, tmp);
}

void upgrade_abilities_type3_bis(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 3 && tmp->id == 2) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret3_foundation, sfTrue);
        s_all->s_selected.tur->r_speed *= 1.25;
        s_all->s_selected.tur->bullet_speed *= 1.25;
        s_all->s_selected.tur->b_speed_str =
            strnbr_float(s_all->s_selected.tur->bullet_speed);
        sfText_setString(s_all->s_selected.tur->b_speed_txt,
            s_all->s_selected.tur->b_speed_str);
        s_all->s_selected.tur->r_speed_str =
            strnbr_float(s_all->s_selected.tur->r_speed);
        sfText_setString(s_all->s_selected.tur->r_speed_txt,
            s_all->s_selected.tur->r_speed_str);
    } upgrade_abilities_type3_bis_2(s_all, tmp);
}

void upgrade_abilities_type3(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 3 && tmp->id == 0) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret3_shrapnel, sfTrue);
        s_all->s_selected.tur->dmg *= 1.25;
        s_all->s_selected.tur->dmg_str =
            strnbr(s_all->s_selected.tur->dmg);
        sfText_setString(s_all->s_selected.tur->dmg_txt,
            s_all->s_selected.tur->dmg_str);
    } if (s_all->s_selected.tur->type == 3 && tmp->id == 1) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite_c,
        s_all->turret_texture.turret3_long, sfTrue);
        s_all->s_selected.tur->range *= 1.25;
        s_all->s_selected.tur->range_str =
            strnbr(s_all->s_selected.tur->range);
        sfText_setString(s_all->s_selected.tur->range_txt,
            s_all->s_selected.tur->range_str);
        sfVector2f zone = sfSprite_getScale(s_all->s_selected.tur->zone);
        sfSprite_setScale(s_all->s_selected.tur->zone,
            (sfVector2f){zone.x * 1.25, zone.y * 1.25});
    } upgrade_abilities_type3_bis(s_all, tmp);
}