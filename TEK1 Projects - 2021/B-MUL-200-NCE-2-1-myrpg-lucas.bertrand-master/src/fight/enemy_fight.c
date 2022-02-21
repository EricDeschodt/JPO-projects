/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemy_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int victory(scene_t *fight)
{
    int lvl = fight[5].player->lvl, gain_exp = 20;
    char exp[4], gain_lvl[4];
    if (fight[5].player->exp + gain_exp >= 800) {
        sfText_setString(fight[22].texts->text, "Victoire!");
        return (2);
    } fight[5].player->exp += gain_exp;
    fight[5].player->lvl = (fight[5].player->exp / 100) + 1;
    if (lvl < fight[5].player->lvl) {
        fight[5].player->pv = ((fight[5].player->lvl - 1) * 10) + 20;
        if (fight[5].player->pv >= 100) fight[5].player->pv = 99;
        fight[5].player->pm = ((fight[5].player->lvl - 1) * 5) + 10;
        int_to_str(gain_lvl, fight[5].player->lvl, 2);
        sfText_setString(fight[22].texts->text,
                        "Victoire! vous gagnez\t\t exp!\nVous passez au niveau");
        sfText_setString(fight[36].texts->text, gain_lvl);
    } else
          sfText_setString(fight[22].texts->text,"Victoire! vous gagnez\t\t exp!");
    int_to_str(exp, gain_exp, 4);
    sfText_setString(fight[35].texts->text, exp);
    return (2);
}

void manage_damage(scene_t *fight)
{
    int lower = 8;
    int upper = 11;
    int damage = ((rand() % (upper - lower + 1)) + lower) +
            ((fight[5].player->lvl - 1) * 3);
    char dmg[10];
    damage += 3 * (fight[1].objs->rect.top / 100);
    if (fight[5].player->attack_up > 0) {
        damage *= 1.5;
        fight[5].player->attack_up--;
    } if (verif_attack(fight) != 1) {
        if (my_strcmp(sfText_getString(fight[22].texts->text), "Coup critique!") == 0)
            damage *= 2;
        if (damage >= 100)
            damage = 99;
        int_to_str(dmg, damage, 2);
        sfText_setPosition(fight[34].texts->text, create_v2f(1250, 200));
        sfText_setString(fight[34].texts->text, dmg);
        fight[5].player->enemy_pv -= damage;
        if (fight[5].player->enemy_pv <= 0)
            fight[5].player->victory = true;
    }
}

void enemy_damage(sfRenderWindow *window, scene_t *fight)
{
    int lower = 2;
    int upper = 3;
    char dmg[10];
    int damage = ((fight[2].objs->rect.top + 150) / 150) * 0.90;
    int ret = verif_enemy_attack(fight);
    if (ret != 2) {
        damage *= ((rand() % (upper - lower + 1)) + lower);
        if (ret == 1)
            damage *= 2;
        if (fight[5].player->defense_up > 0) {
            damage /= 2;
            fight[5].player->defense_up--;
        } if (damage == 0)
              damage = 1;
        int_to_str(dmg, damage, 2);
        sfText_setPosition(fight[34].texts->text, create_v2f(725, 225));
        sfText_setString(fight[34].texts->text, dmg);
        fight[5].player-> pv -= damage;
    } if (fight[5].player->pv < 0)
          fight[5].player->pv = 0;
}

int enemy_fight(sfRenderWindow *window, scene_t *fight, int atk)
{
    char pv[10];

    sfSound_play(fight[9].sounds->sound);
    if (fight[5].player->pv <= 0) {
        int_to_str(pv, 0, 2);
        sfText_setString(fight[30].texts->text, pv);
        sfSound_pause(fight[6].sounds->sound);
        game_over(window);
        return (1);
    }
    else {
        int_to_str(pv, fight[5].player->pv, 2);
        sfText_setString(fight[30].texts->text, pv);
    }
    sfText_setString(fight[22].texts->text, "");
    fight[5].player->defense = false;
}
