/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemy_boss_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void boss_anim(sfRenderWindow *window, scene_t *fight)
{
    if (fight[2].objs->rect.left == 900) {
        fight[2].objs->rect.left = 0;
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
    }
    if (fight[39].times->seconds >= 0.15) {
        fight[2].objs->rect.left += 300;
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
        sfClock_restart(fight[39].times->clock);
    }
}

int animattack_boss(sfRenderWindow *window, scene_t *fight, int *ret)
{
    sfRenderWindow_drawSprite(window, fight[38].objs->my_sprite, NULL);
    if (fight[38].objs->rect.left == 900) {
        fight[38].objs->rect.left = 0;
        fight[38].objs->pos.x = 1100;
        sfSprite_setTextureRect(fight[38].objs->my_sprite, fight[38].objs->rect);
        sfSprite_setPosition(fight[38].objs->my_sprite, fight[38].objs->pos);
        sfText_setString(fight[22].texts->text, "");
        sfText_setPosition(fight[34].texts->text, create_v2f(-30, -30));
        return (boss_fight(window, fight, ret[2]));
    }
    if (fight[38].objs->rect.left == 200 &&
        sfText_getPosition(fight[34].texts->text).x == -30)
        boss_damage(fight);
    if (fight[37].times->seconds >= 0.07) {
        fight[38].objs->rect.left += 100;
        fight[38].objs->pos.x -= 50;
        sfSprite_setTextureRect(fight[38].objs->my_sprite, fight[38].objs->rect);
        sfSprite_setPosition(fight[38].objs->my_sprite, fight[38].objs->pos);
        sfClock_restart(fight[37].times->clock);
    }
}

int boss_victory(scene_t *fight)
{
    int lvl = fight[5].player->lvl;
    int gain_exp = 100;
    char exp[4], gain_lvl[4];
    if (fight[5].player->exp + gain_exp >= 800) {
        sfText_setString(fight[22].texts->text, "Victoire!");
        return (2);
    }
    fight[5].player->exp += gain_exp;
    fight[5].player->lvl = (fight[5].player->exp / 100) + 1;
    if (lvl < fight[5].player->lvl) {
        fight[5].player->pv += 10;
        fight[5].player->pm += 5;
        int_to_str(gain_lvl, fight[5].player->lvl, 2);
        sfText_setString(fight[22].texts->text,
                        "Victoire! vous gagnez\t\texp!\nVous passez au niveau");
        sfText_setString(fight[36].texts->text, gain_lvl);
    } else
        sfText_setString(fight[22].texts->text, "Victoire! vous gagnez\t\t exp!");
    int_to_str(exp, gain_exp, 4);
    sfText_setString(fight[35].texts->text, exp);
    return (2);
}

void boss_damage(scene_t *fight)
{
    int lower = 5;
    int upper = 7;
    char dmg[10];
    float damage = ((fight[2].objs->rect.top + 400) / 400) * 0.5;
    int ret = verif_enemy_attack(fight);
    if (ret != 2) {
        damage *= ((rand() % (upper - lower + 1)) + lower);
        if (ret == 1)
            damage *= 2;
        if (fight[5].player->defense_up > 0) {
            damage /= 2;
            fight[5].player->defense_up--;
        }
        if (damage == 0)
             damage = 2;
        int_to_str(dmg, damage, 2);
        sfText_setPosition(fight[34].texts->text, create_v2f(725, 225));
        sfText_setString(fight[34].texts->text, dmg);
        fight[5].player-> pv -= damage;
    }
}

int boss_fight(sfRenderWindow *window, scene_t *fight, int atk)
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
