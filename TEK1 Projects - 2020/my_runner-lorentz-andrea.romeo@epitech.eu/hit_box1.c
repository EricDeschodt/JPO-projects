/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hit_box1
*/

#include "my.h"

void hat_fat_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 0) {
        if (((all->pos.pos_hat.x + 70 >= tmp->fat.pos_fat.x -
            (150 * tmp->fat.float_fat) && all->pos.pos_hat.x <= tmp->fat
            .pos_fat.x && all->pos.pos_hat.y + 30 >= tmp->fat.pos_fat.y -
            (280 * tmp->fat.float_fat)) && all->my_int.hat == 1 && tmp->dead ==
            0) || ((all->pos.pos_michael.x + 175 >= tmp->fat.pos_fat.x -
            (150 * tmp->fat.float_fat) && all->pos.pos_michael.x + 80 <=
            tmp->fat.pos_fat.x && all->pos.pos_michael.y + 150 >=
            tmp->fat.pos_fat.y - (280 * tmp->fat.float_fat)) && all->my_int
            .hit == 1 && tmp->dead == 0)) {
            punches_sounds_random(all);
            if (all->my_int.up_throw == 1)
                all->my_int.hit_time = 20 + (20 - all->my_int.hit_time);
            else if (all->my_int.down_throw == 1)
                all->my_int.hit_time = 17 + (17 - all->my_int.hit_time);
            tmp->fat.rect_fat.top = 1349, tmp->dead = 1;
            tmp->fat.rect_fat.left = 900;
            sfSprite_setTextureRect(tmp->fat.sprite, tmp->fat.rect_fat);
        }
    }
}

void hat_flying_hit_box2(dlist_node_t *tmp)
{
    if (tmp->dead == 0) {
        tmp->flying.rect_flying.height = 440;
        tmp->flying.rect_flying.width = 180;
        tmp->flying.rect_flying.top = 460;
        tmp->dead = 1;
        tmp->flying.rect_flying.left = 800;
        tmp->flying.pos_flying.y = 340;
        sfSprite_setTextureRect(tmp->flying.sprite,
            tmp->flying.rect_flying);
        sfSprite_setPosition(tmp->flying.sprite,
            tmp->flying.pos_flying);
    }
}

void hat_flying_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 1) {
        if (all->pos.pos_hat.x + 50 >= tmp->flying.pos_flying.x
            && all->pos.pos_hat.x <= tmp->flying.pos_flying.x + 180
            && all->pos.pos_hat.y + 30 >= tmp->flying.pos_flying.y
            && all->pos.pos_hat.y <= tmp->flying.pos_flying.y + 280
            && all->my_int.hat == 1 && tmp->dead == 0) {
            punches_sounds_random(all);
            if (all->my_int.up_throw == 1)
                all->my_int.hit_time = 20 + (20 - all->my_int.hit_time);
            else if (all->my_int.down_throw == 1)
                all->my_int.hit_time = 17 + (17 - all->my_int.hit_time);
            hat_flying_hit_box2(tmp);
        }
    }
}

void hat_flying2_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 1) {
        if (all->pos.pos_hat.x + 50 >= tmp->flying.pos_flying.x
            && all->pos.pos_hat.x <= tmp->flying.pos_flying.x + 180
            && all->pos.pos_hat.y + 30 >= tmp->flying.pos_flying.y
            && all->pos.pos_hat.y <= tmp->flying.pos_flying.y + 150
            && all->my_int.hat == 1 && tmp->dead == 2) {
            punches_sounds_random(all);
            if (all->my_int.up_throw == 1) {
                all->my_int.hit_time = 20 + (20 - all->my_int.hit_time);
                tmp->dead = 3;
            }
        }
        hit_flying_hit_box(all, tmp);
    }
}

void hit_flying_hit_box(all_t *all, dlist_node_t *tmp)
{
    if ((all->pos.pos_michael.x + 190 >= tmp->flying.pos_flying.x + 50
        && all->pos.pos_michael.x + 80 <= tmp->flying.pos_flying.x + 180
        && all->pos.pos_michael.y + 130 >= tmp->flying.pos_flying.y
        && all->pos.pos_michael.y + 50 <= tmp->flying.pos_flying.y + 150
        && all->my_int.hit == 1 && (tmp->dead == 0 || tmp->dead == 2))) {
        punches_sounds_random(all);
        if (tmp->dead == 0) {
            tmp->dead = 1;
            tmp->flying.rect_flying.height = 440;
            tmp->flying.rect_flying.width = 180;
            tmp->flying.rect_flying.top = 460;
            tmp->flying.rect_flying.left = 800, tmp->flying.pos_flying.y = 340;
            sfSprite_setTextureRect(tmp->flying.sprite,
                tmp->flying.rect_flying);
            sfSprite_setPosition(tmp->flying.sprite, tmp->flying.pos_flying);
        }
        else if (tmp->dead == 2)
            tmp->dead = 3;
    }
}