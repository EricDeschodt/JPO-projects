/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_abilities2
*/

#include "defender.h"
#include "utils.h"

int check_abilities_hitbox(abilities_t *tmp, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= sfRectangleShape_getPosition(tmp->rectangle).x
    && mouse_pos.x <= sfRectangleShape_getPosition(tmp->rectangle).x + 237)
    && (mouse_pos.y >= sfRectangleShape_getPosition(tmp->rectangle).y
    && mouse_pos.y <= sfRectangleShape_getPosition(tmp->rectangle).y + 88))
        return (1);
    return (0);
}

void upgrade_abilities_type1_bis(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 1 && tmp->id == 2) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret1_foundation, sfTrue);
        s_all->s_selected.tur->r_speed *= 1.50;
        s_all->s_selected.tur->bullet_speed *= 1.50;
        s_all->s_selected.tur->b_speed_str =
            strnbr_float(s_all->s_selected.tur->bullet_speed);
        sfText_setString(s_all->s_selected.tur->b_speed_txt,
            s_all->s_selected.tur->b_speed_str);
        s_all->s_selected.tur->r_speed_str =
            strnbr_float(s_all->s_selected.tur->r_speed);
        sfText_setString(s_all->s_selected.tur->r_speed_txt,
            s_all->s_selected.tur->r_speed_str);
    } if (s_all->s_selected.tur->type == 1 && tmp->id == 3) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret1_value, sfTrue);
        s_all->s_player.money += 100, s_all->s_stats.coins += 100;
        s_all->s_player.strmoney = strnbr(s_all->s_player.money);
        sfText_setString(s_all->s_player.txt_money, s_all->s_player.strmoney);
    }
}

void upgrade_abilities_type1(all_t *s_all, abilities_t *tmp)
{
    if (s_all->s_selected.tur->type == 1 && tmp->id == 0) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite_c,
        s_all->turret_texture.turret1_dual, sfTrue);
        s_all->s_selected.tur->rate_fire /= 1.25;
        s_all->s_selected.tur->rof_str =
            strnbr_float(1 / s_all->s_selected.tur->rate_fire);
        sfText_setString(s_all->s_selected.tur->rof_txt,
            s_all->s_selected.tur->rof_str);
    }
    if (s_all->s_selected.tur->type == 1 && tmp->id == 1) {
        sfSprite_setTexture(s_all->s_selected.tur->sprite,
        s_all->turret_texture.turret1_large, sfTrue);
        s_all->s_selected.tur->dmg *= 1.25;
        s_all->s_selected.tur->dmg_str =
            strnbr(s_all->s_selected.tur->dmg);
        sfText_setString(s_all->s_selected.tur->dmg_txt,
            s_all->s_selected.tur->dmg_str);
    }
    upgrade_abilities_type1_bis(s_all, tmp);
}

int upgrade_abilities(all_t *s_all, sfVector2i mouse_pos, abilities_t *tmp)
{
    if (check_abilities_hitbox(tmp, mouse_pos) == 1) {
        abilities_t *tmp2 = s_all->s_selected.tur->abilities;
        for (; tmp2 != NULL; tmp2 = tmp2->next) {
            tmp2->bought = 1;
            sfRectangleShape_setFillColor(tmp2->rectangle,
            (sfColor){0, 0, 0, 0});
        } sfRectangleShape_setFillColor(tmp->rectangle,
        (sfColor){213, 178, 64, 150});
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.ability);
        upgrade_abilities_type1(s_all, tmp);
        upgrade_abilities_type2(s_all, tmp);
        upgrade_abilities_type3(s_all, tmp);
        upgrade_abilities_type4(s_all, tmp);
        return (1);
    }
    return (0);
}

void hitbox_abilities(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if (s_all->s_selected.tur != NULL
    && s_all->s_selected.tur->abilities->bought != 1
    && s_all->s_selected.tur->level == 4) {
        abilities_t *tmp = s_all->s_selected.tur->abilities;
        for (int check; tmp != NULL && check != 1; tmp = tmp->next)
            check = upgrade_abilities(s_all, mouse_pos, tmp);
    }
}