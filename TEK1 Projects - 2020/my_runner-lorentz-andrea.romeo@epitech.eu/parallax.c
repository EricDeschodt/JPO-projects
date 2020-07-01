/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parallax
*/

#include "my.h"

void reset_parallax(background_pos_t *pos)
{
    if (pos->pos_layer1.x <= -1920) { pos->pos_layer1.x = pos->pos2_layer1.x
    + 1920, pos->pos_layer1_2.x = pos->pos2_layer1.x +1920; }
    if (pos->pos_layer2.x <= -1920)
        pos->pos_layer2.x = pos->pos2_layer2.x + 1920;
    if (pos->pos_layer3.x <= -1920)
        pos->pos_layer3.x = pos->pos2_layer3.x + 1920;
    if (pos->pos_layer4.x <= -1920)
        pos->pos_layer4.x = pos->pos2_layer4.x + 1920;
    if (pos->pos_layer5.x <= -1920)
        pos->pos_layer5.x = pos->pos2_layer5.x + 1920;
    if (pos->pos2_layer1.x <= -1920) { pos->pos2_layer1.x = pos->pos_layer1.x
    + 1920, pos->pos2_layer1_2.x = pos->pos_layer1.x + 1920; }
    if (pos->pos2_layer2.x <= -1920)
        pos->pos2_layer2.x = pos->pos_layer2.x + 1920;
    if (pos->pos2_layer3.x <= -1920)
        pos->pos2_layer3.x = pos->pos_layer3.x + 1920;
    if (pos->pos2_layer4.x <= -1920)
        pos->pos2_layer4.x = pos->pos_layer4.x + 1920;
    if (pos->pos2_layer5.x <= -1920)
        pos->pos2_layer5.x = pos->pos_layer5.x + 1920;
}

void parallax_background_pos(all_t *all)
{
    if (all->my_int.menu != 5) {
        if (list_end_map(all) != 1) all->my_int.skull += 2;
        if (all->pos.pos_michael.x >= 1920) all->my_int.menu = 5;
        all->background_pos.pos_layer1.x -= all->my_int.speed / 7;
        all->background_pos.pos_layer1_2.x -= all->my_int.speed / 7;
        all->background_pos.pos_layer2.x -= all->my_int.speed / 11;
        all->background_pos.pos_layer3.x -= all->my_int.speed / 17;
        all->background_pos.pos_layer4.x -= all->my_int.speed / 33;
        all->background_pos.pos_layer5.x -= all->my_int.speed / 50;
        all->background_pos.pos2_layer1.x -= all->my_int.speed / 7;
        all->background_pos.pos2_layer1_2.x -= all->my_int.speed / 7;
        all->background_pos.pos2_layer2.x -= all->my_int.speed / 11;
        all->background_pos.pos2_layer3.x -= all->my_int.speed / 17;
        all->background_pos.pos2_layer4.x -= all->my_int.speed / 33;
        all->background_pos.pos2_layer5.x -= all->my_int.speed / 50;
    }
}

void parallax_pos(all_t *all)
{
    if (all->clock.seconds > 0.01 && all->my_int.speed != 0) {
        if (all->pos.pos_michael.y >= 520) all->pos.pos_michael.y = 520;
        list_move_zombie(all);
        michael_jump(all), michael_moonwalk(all), michael_hit(all);
        michael_hit_crouch(all), michael_up_throw(all), michael_down_throw(all);
        parallax_background_pos(all), reset_parallax(&all->background_pos);
        parallax_set(all);
        if ((list_end_map(all) == 1) && all->my_int.menu == 0
        && all->pos.pos_michael.x < 1920) {
            all->pos.pos_michael.x += 15;
            sfSprite_setPosition(all->sprite.michael, all->pos.pos_michael);
        } sfClock_restart(all->clock.clock);
    }
}

void parallax_set(all_t *all)
{
    sfSprite_setPosition(all->background.background1, all->background_pos
    .pos_layer1), sfSprite_setPosition(all->background.background2,
        all->background_pos.pos_layer2);
    sfSprite_setPosition(all->background.background3, all->background_pos
    .pos_layer3), sfSprite_setPosition(all->background.background4,
        all->background_pos.pos_layer4);
    sfSprite_setPosition(all->background.background5, all->background_pos
    .pos_layer5), sfSprite_setPosition(all->background2.background2_1,
        all->background_pos.pos2_layer1);
    sfSprite_setPosition(all->background2.background2_2, all->background_pos
    .pos2_layer2), sfSprite_setPosition(all->background2.background2_3,
        all->background_pos.pos2_layer3);
    sfSprite_setPosition(all->background2.background2_4,
        all->background_pos.pos2_layer4);
    sfSprite_setPosition(all->background2.background2_5,
        all->background_pos.pos2_layer5);
    sfSprite_setPosition(all->background2.background2_1_2,
        all->background_pos.pos2_layer1_2);
    sfSprite_setPosition(all->background.background1_2,
        all->background_pos.pos_layer1_2);
}