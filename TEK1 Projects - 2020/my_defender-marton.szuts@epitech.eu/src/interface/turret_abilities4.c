/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_abilities4
*/

#include "defender.h"
#include "utils.h"

void init_turret4(abilities_t *node, int type, all_t *s_all, int nb)
{
    if (type == 4)
        sfSprite_setTexture(node->under, s_all->s_texture.round, sfTrue);
    if (type == 4 && nb == 1) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret4_slow, sfTrue);
        sfText_setString(node->name, "  Frostblade\n  Slow x1.25");
    } if (type == 4 && nb == 0) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret4_cold, sfTrue);
        sfText_setString(node->name, "     Life support\n        Life +2");
    } if (type == 4 && nb == 2) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret4_system, sfTrue);
        sfText_setString(node->name, "  Radar system\n   Range x1.25");
    } if (type == 4 && nb == 3) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret4_snowball, sfTrue);
        sfText_setString(node->name, "       Ice age\n Give you 50 coins");
    }
}

void upgrade_abilities_type3_bis_2(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 3 && tmp->id == 3) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret3_speed, sfTrue);
        s_all->s_selected.tur->rate_fire /= 1.25;
        s_all->s_selected.tur->rof_str =
            strnbr_float(1 / s_all->s_selected.tur->rate_fire);
        sfText_setString(s_all->s_selected.tur->rof_txt,
            s_all->s_selected.tur->rof_str);
    }
}

void upgrade_abilities_type4_bis(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 4 && tmp->id == 2) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret4_system, sfTrue);
        s_all->s_selected.tur->range *= 1.25;
        s_all->s_selected.tur->range_str =
            strnbr(s_all->s_selected.tur->range);
        sfText_setString(s_all->s_selected.tur->range_txt,
            s_all->s_selected.tur->range_str);
        sfVector2f zone = sfSprite_getScale(s_all->s_selected.tur->zone);
        sfSprite_setScale(s_all->s_selected.tur->zone,
            (sfVector2f){zone.x * 1.25, zone.y * 1.25});
    } if (s_all->s_selected.tur->type == 4 && tmp->id == 3) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret4_snowball, sfTrue);
        s_all->s_player.money += 50;
        s_all->s_stats.coins += 50;
        s_all->s_player.strmoney = strnbr(s_all->s_player.money);
        sfText_setString(s_all->s_player.txt_money, s_all->s_player.strmoney);
    }
}

void upgrade_abilities_type4(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 4 && tmp->id == 1) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite_c,
        s_all->turret_texture.turret4_slow, sfTrue);
        s_all->s_selected.tur->r_speed *= 1.25;
        s_all->s_selected.tur->r_speed_str =
            strnbr_float(s_all->s_selected.tur->r_speed);
        sfText_setString(s_all->s_selected.tur->r_speed_txt,
            s_all->s_selected.tur->r_speed_str);
        sfSprite_setPosition(s_all->s_selected.tur->bullet,
        (sfVector2f){-100, -100});
    } if (s_all->s_selected.tur->type == 4 && tmp->id == 0) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret4_cold, sfTrue);
        s_all->s_player.life += 2;
        s_all->s_player.strlife = strnbr(s_all->s_player.life);
        sfText_setString(s_all->s_player.txt_life, s_all->s_player.strlife);
    }
    upgrade_abilities_type4_bis(s_all, tmp);
}