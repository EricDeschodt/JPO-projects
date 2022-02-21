/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void ultimate_manage_damage(scene_t *fight)
{
    int lower = 7;
    int upper = 10;
    int damage = ((rand() % (upper - lower + 1)) + lower) + ((fight[5].player->lvl - 1) * 3);
    char dmg[10];
    damage += 3 * (fight[1].objs->rect.top / 100);
    if (fight[5].player->attack_up > 0) {
        damage *= 1.5;
        fight[5].player->attack_up--;
    }if (ultimate_verif_attack(fight) != 1) {
        if (my_strcmp(sfText_getString(fight[18].texts->text), "Coup critique!") == 0)
            damage *= 2;
        if (damage >= 100)
            damage = 99;
        int_to_str(dmg, damage, 2);
        sfText_setPosition(fight[30].texts->text, create_v2f(1050, 125));
        sfText_setString(fight[30].texts->text, dmg);
        fight[5].player->enemy_pv -= damage;
    }
}

void ultimate_enemy_damage(scene_t *fight)
{
    char dmg[10];
    int damage = 15;
    int ret = ultimate_verif_enemy_attack(fight);
    if (ret != 2) {
        if (ret == 1)
            damage *= 2;
        if (fight[5].player->defense_up > 0) {
            damage /= 2;
            fight[5].player->defense_up--;
        }
        int_to_str(dmg, damage, 2);
        sfText_setPosition(fight[30].texts->text, create_v2f(500, 500));
        sfText_setString(fight[30].texts->text, dmg);
        fight[5].player->pv -= damage;
    }
    if (fight[5].player->pv <= 0)
        if (fight[5].player->enemy_pv <= 75)
            fight[5].player->pv = 1;
        else
            fight[5].player->pv = 0;
}


int ultimate_enemy_fight(sfRenderWindow *window, scene_t *fight, sound_t *music)
{
    char pv[10];

    if (fight[5].player->pv <= 0) {
        int_to_str(pv, 0, 2);
        sfText_setString(fight[26].texts->text, pv);
        sfSound_stop(music->sound);
        game_over(window);
        return (1);
    }
    else if (fight[5].player->pv == 1 && fight[5].player->enemy_pv <= 75) {
        sfSound_stop(music->sound);
        fight[5].player->victory = true;
    }
    else {
        int_to_str(pv, fight[5].player->pv, 2);
        sfText_setString(fight[26].texts->text, pv);
    }
    sfText_setString(fight[18].texts->text, "");
    fight[5].player->defense = false;
}

int dodge(scene_t *fight)
{
    char *text = "Continue si tu en as envie,\nl'issu de ce combat est deja scellee.";
        
    sfSprite_setScale(fight[0].objs->my_sprite, create_v2f(-3, 3));
    sfSprite_setPosition(fight[0].objs->my_sprite, create_v2f(1920, 0));
    sfSprite_setPosition(fight[1].objs->my_sprite, create_v2f(1500, 395));
    sfText_setString(fight[19].texts->text, text);
}

void restore(scene_t *fight)
{
    sfSprite_setScale(fight[0].objs->my_sprite, create_v2f(3, 3));
    sfSprite_setPosition(fight[0].objs->my_sprite, create_v2f(0, 0));
    sfSprite_setPosition(fight[1].objs->my_sprite, create_v2f(260, 395));
}
