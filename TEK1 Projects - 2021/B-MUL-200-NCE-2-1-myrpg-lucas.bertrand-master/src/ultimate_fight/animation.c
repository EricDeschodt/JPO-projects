/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void ultimate_weak(scene_t *fight)
{
    if (fight[1].objs->rect.left < 600 || fight[1].objs->rect.left > 800)
        fight[1].objs->rect.left = 600;
    sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    if (fight[33].times->seconds > 0.5) {
        fight[1].objs->rect.left += 200;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        sfClock_restart(fight[33].times->clock);
    }
}

void ultimate_defense(scene_t *fight)
{
    if (fight[1].objs->rect.left >= 2400) {
        fight[5].player->defense = true;
        fight[1].objs->rect.left = 0;
        sfText_setString(fight[18].texts->text, "");
        sfText_setPosition(fight[30].texts->text, create_v2f(-30, -30));
    }
    if (fight[5].player->victory == true)
        fight[1].objs->rect.left = 1200;
    sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    if (fight[5].player->victory == false &&
        my_strcmp(sfText_getString(fight[18].texts->text), "") == 0 &&
        fight[5].player->pv <= (((fight[5].player->lvl - 1) * 10) + 20) / 4)
        ultimate_weak(fight);
    else
        if (fight[1].objs->rect.left < 400)
            if (fight[33].times->seconds > 0.1) {
                fight[1].objs->rect.left += 200;
                sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
                sfClock_restart(fight[33].times->clock);
            }
}

void ultimate_animattack(sfRenderWindow *window, scene_t *fight)
{
    if (fight[1].objs->rect.left == 0)
        sfSound_play(fight[6].sounds->sound);
    else if (fight[1].objs->rect.left == 2400) {
        restore(fight);
        time_restart(fight[33].times);
        fight[1].objs->rect.top = 400;
        fight[5].player->attack = false;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    }if (fight[1].objs->rect.left == 1200 &&
        sfText_getPosition(fight[30].texts->text).x == -30)
        if (fight[5].player->enemy_pv <= 75)
            dodge(fight);
        else
            ultimate_manage_damage(fight);
    if (fight[33].times->seconds >= 0.12 || (fight[1].objs->rect.left > 1000
        && fight[1].objs->rect.left < 1800 && fight[33].times->seconds >= 0.075)) {
        fight[1].objs->rect.left += 200;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        sfClock_restart(fight[33].times->clock);
    }
}

void epilepsie(scene_t *fight)
{
    if (fight[0].objs->rect.left >= 3840)
        fight[0].objs->rect.left = -640;
    if (fight[34].times->seconds > 0.065) {
        fight[0].objs->rect.left += 640;
        sfSprite_setTextureRect(fight[0].objs->my_sprite, fight[0].objs->rect);
        sfClock_restart(fight[34].times->clock);
    }
}

int epilepsie_lazer(sfRenderWindow *window, scene_t *fight, sound_t *music)
{
    if (fight[2].objs->rect.left >= 11520) {
        fight[2].objs->rect.left = -640;
        sfText_setPosition(fight[30].texts->text, create_v2f(-30, -30));
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
        time_restart(fight[35].times);
        return (ultimate_enemy_fight(window, fight, music));
    }
    else if (fight[2].objs->rect.left == 0)
        sfSound_play(fight[7].sounds->sound);
    if (fight[2].objs->rect.left == 6400 &&
        sfText_getPosition(fight[30].texts->text).x == -30)
        ultimate_enemy_damage(fight);
    if (fight[35].times->seconds > 0.075) {
        fight[2].objs->rect.left += 640;
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
        sfClock_restart(fight[35].times->clock);
    }
}
