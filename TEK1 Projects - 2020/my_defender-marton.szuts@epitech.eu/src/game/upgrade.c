/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** upgrade
*/

#include "defender.h"
#include "utils.h"

void init_upgrade_turret(all_t *s_all, turret_t *new)
{
    new->upg_price_txt = sfText_create();
    new->lvl_txt = sfText_create();
    new->xp_txt = sfText_create();
    if (new->type == 1) new->upg_price = 24;
    if (new->type == 2) new->upg_price = 40;
    if (new->type == 3) new->upg_price = 30;
    if (new->type == 4) new->upg_price = 40;
    new->level = 1, new->strupg_price = strnbr(new->upg_price);
    sfText_setString(new->upg_price_txt, new->strupg_price);
    sfText_setFont(new->upg_price_txt, s_all->s_game.font);
    sfText_setPosition(new->upg_price_txt, (sfVector2f){1743, 845});
    sfText_setString(new->lvl_txt, "1"), new->strlvl = strnbr(1);
    sfText_setFont(new->lvl_txt, s_all->s_game.font);
    sfText_setCharacterSize(new->lvl_txt, 25);
    sfText_setCharacterSize(new->upg_price_txt, 25);
    sfText_setPosition(new->lvl_txt, (sfVector2f){1815, 19}), new->strxp =
    my_strcat(strnbr(0), "/300"), sfText_setCharacterSize(new->xp_txt, 20);
    sfText_setFont(new->xp_txt, s_all->s_game.font);
    sfText_setString(new->xp_txt, new->strxp);
    sfText_setPosition(new->xp_txt, (sfVector2f){1760, 53});
}

void upgrade2(turret_t *tur)
{
    tur->sell += tur->upg_price / 7;
    free(tur->strsell);
    tur->strsell = strnbr(tur->sell);
    sfText_setString(tur->sell_txt, tur->strsell);
}

void set_xp(turret_t *tur)
{
    if (tur->level < 3) {
        free(tur->strxp);
        tur->strxp = my_strcat(strnbr(tur->xp), "/300");
        sfText_setString(tur->xp_txt, tur->strxp);
    }
    if (tur->level == 3) {
        free(tur->strxp);
        sfText_setString(tur->xp_txt, "Max level");
        tur->level += 1;
    }
}

void turret_level_up(turret_t *tur)
{
    tur->xp += 6;
    if (tur->xp >= 300 && tur->level < 3) {
        if (tur->level < 2) {
            free(tur->strlvl);
            tur->level += 1;
            tur->xp = tur->xp - 300;
            tur->strlvl = strnbr(tur->level);
            sfText_setString(tur->lvl_txt, tur->strlvl);
        }
        else if (tur->level == 2){
            free(tur->strlvl);
            tur->level += 1;
            tur->xp = 300;
            sfText_setString(tur->lvl_txt, "3");
        }
    }
    else if (tur->level >= 3)
        tur->xp = 300;
    set_xp(tur);
}

void max_upgrade(all_t *s_all, turret_t *tur)
{
    tur->max = 1;
    tur->counter++;
    free(tur->strupg_price);
    sfText_setString(tur->upg_price_txt, "MAX");
    sfSprite_setTexture(s_all->s_upgrade.sprite,
    s_all->s_upgrade.texture, sfTrue);
    sfText_setCharacterSize(tur->upg_price_txt, 20);
    sfText_setPosition(tur->upg_price_txt, (sfVector2f){1760, 848});
}