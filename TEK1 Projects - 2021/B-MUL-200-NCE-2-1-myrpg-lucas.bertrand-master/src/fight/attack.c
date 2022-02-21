/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** attack
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void weak(scene_t *fight)
{
    if (fight[1].objs->rect.left < 600 || fight[1].objs->rect.left > 800)
        fight[1].objs->rect.left = 600;
    sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    if (fight[37].times->seconds > 0.5) {
        fight[1].objs->rect.left += 200;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        sfClock_restart(fight[37].times->clock);
    }
}

void defense(sfRenderWindow *window, scene_t *fight)
{
    if (fight[1].objs->rect.left >= 2400) {
        fight[5].player->defense = true;
        fight[1].objs->rect.left = 0;
        sfText_setString(fight[22].texts->text, "");
        sfText_setPosition(fight[34].texts->text, create_v2f(-30, -30));
    } if (fight[5].player->victory == true)
          fight[1].objs->rect.left = 1200;
    sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    if (fight[5].player->victory == false &&
        my_strcmp(sfText_getString(fight[22].texts->text), "") == 0 &&
        fight[5].player->pv <= (((fight[5].player->lvl - 1) * 10) + 20) / 4)
        weak(fight);
    else
        if (fight[1].objs->rect.left < 400)
            if (fight[37].times->seconds > 0.1) {
                fight[1].objs->rect.left += 200;
                sfSprite_setTextureRect(fight[1].objs->my_sprite,
                                        fight[1].objs->rect);
                sfClock_restart(fight[37].times->clock);
            }
}

void animattack(sfRenderWindow *window, scene_t *fight)
{
    if (fight[1].objs->rect.left == 0)
        sfSound_play(fight[8].sounds->sound);
    else if (fight[1].objs->rect.left == 2400) {
        time_restart(fight[37].times);
        fight[1].objs->rect.top = 400;
        fight[5].player->attack = false;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
    }
    if (fight[1].objs->rect.left == 1200 &&
        sfText_getPosition(fight[34].texts->text).x == -30)
        manage_damage(fight);
    if (fight[37].times->seconds >= 0.12 || (fight[1].objs->rect.left > 1000
        && fight[1].objs->rect.left < 1800 && fight[37].times->seconds >= 0.075)) {
        fight[1].objs->rect.left += 200;
        sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        sfClock_restart(fight[37].times->clock);
    }
}

int animattack_enemy(sfRenderWindow *window, scene_t *fight, int *ret)
{
    if (fight[2].objs->rect.left == fight[2].objs->rect_max) {
        fight[2].objs->rect.left -= 450;
        sfText_setPosition(fight[34].texts->text, create_v2f(-30, -30));
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
        time_restart(fight[37].times);
        return (enemy_fight(window, fight, ret[2]));
    }
    if (fight[2].objs->rect.left == fight[2].objs->rect_max - 300 &&
        sfText_getPosition(fight[34].texts->text).x == -30)
        enemy_damage(window, fight);
    if (fight[37].times->seconds >= 0.5) {
        fight[2].objs->rect.left += 150;
        sfSprite_setTextureRect(fight[2].objs->my_sprite, fight[2].objs->rect);
        sfClock_restart(fight[37].times->clock);
    }
}

int choose_attack(sfRenderWindow *window,
                   scene_t * fight, int ret)
{
    if (ret == 14 || ret == 0)
        ret = 10 + (fight[1].objs->rect.top / 100);
    switch (ret) {
    case 10:
        fight[1].objs->rect.top = 0;
        animattack(window,fight);
        return (1);
    case 11:
        fight[1].objs->rect.top = 100;
        animattack(window, fight);
        return (2);
    case 12:
        fight[1].objs->rect.top = 200;
        animattack(window, fight);
        return (3);
    case 13:
        fight[1].objs->rect.top = 300;
        animattack(window, fight);
        return (4);
    }
}
