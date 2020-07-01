/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** zombies_anim
*/

#include "my.h"

void fat_walk_anim2(all_t *all, dlist_node_t *mobs)
{
    if (all->clock.seconds_fat > 0.2 && mobs->dead == 0) {
        if (mobs->fat.rect_fat.left <= 0
            && mobs->fat.rect_fat.top == 0)
            mobs->fat.rect_fat.left = 900, mobs->fat.rect_fat.top = 335;
        else if (mobs->fat.rect_fat.left <= 0)
            mobs->fat.rect_fat.left = 900, mobs->fat.rect_fat.top = 0;
        else
            mobs->fat.rect_fat.left -= 340;
        sfSprite_setTextureRect(mobs->fat.sprite, mobs->fat.rect_fat);
        sfClock_restart(all->clock.clock_fat);
    }
}

void fat_walk_anim(all_t *all, dlist_node_t *mobs)
{
    fat_walk_anim2(all, mobs);
    if (all->clock.seconds_fat_dead > 0.08 && mobs->dead == 1) {
        if (mobs->fat.rect_fat.left <= 0) {
            mobs->dead = 2;
            return;
        }
        else
            mobs->fat.rect_fat.left -= 310;
        sfSprite_setTextureRect(mobs->fat.sprite, mobs->fat.rect_fat);
        sfClock_restart(all->clock.clock_fat_dead);
    }
    if (mobs->dead == 0)
        mobs->fat.pos_fat.x -= all->my_int.speed / 9;
    else
        mobs->fat.pos_fat.x += 10;
    sfSprite_setPosition(mobs->fat.sprite, mobs->fat.pos_fat);
}

void flying2_walk_anim(all_t *all, dlist_node_t *mobs)
{
    if (all->clock.seconds_flying > 0.35 && mobs->dead == 0) {
        if (mobs->flying.rect_flying.left <= 255)
            mobs->flying.rect_flying.left = 810;
        else
            mobs->flying.rect_flying.left -= 185;
        sfClock_restart(all->clock.clock_flying);
    }
    if (all->clock.seconds_flying > 0.35 && mobs->dead >= 2) {
        if (mobs->flying.rect_flying.left <= 200)
            mobs->flying.rect_flying.left = 800;
        else
            mobs->flying.rect_flying.left -= 200;
        sfClock_restart(all->clock.clock_flying);
    }
    if (mobs->dead == 0)
        mobs->flying.pos_flying.x -= all->my_int.speed / 16;
    else if (mobs->dead == 2)
        mobs->flying.pos_flying.x -= all->my_int.speed / 10;
}

void flying3_walk_anim(all_t *all, dlist_node_t *mobs)
{
    if (all->clock.seconds_flying_dead > 0.08 && mobs->dead == 3) {
        if (mobs->flying.alpha <= 15) {
            mobs->dead = 4;
            return;
        }
        mobs->flying.alpha -= 80;
        mobs->flying.color =
            sfColor_fromRGBA(255, 0, 0, mobs->flying.alpha);
        sfSprite_setColor(mobs->flying.sprite, mobs->flying.color);
        sfClock_restart(all->clock.clock_flying_dead);
    }
    if (mobs->dead == 3)
        mobs->flying.pos_flying.x += 3;
    if (mobs->dead == 1)
        mobs->flying.pos_flying.x += 7;
}

void flying_walk_anim(all_t *all, dlist_node_t *mobs)
{
    if (all->clock.seconds_flying_dead > 0.08 && mobs->dead == 1) {
        if (mobs->flying.rect_flying.left <= 0) {
            mobs->flying.rect_flying.left = 790;
            mobs->flying.rect_flying.top = 0, mobs->dead = 2;
        }
        else
            mobs->flying.rect_flying.left -= 200;
        sfClock_restart(all->clock.clock_flying_dead);
    }
    flying3_walk_anim(all, mobs);
    flying2_walk_anim(all, mobs);
    sfSprite_setTextureRect(mobs->flying.sprite, mobs->flying.rect_flying);
    sfSprite_setPosition(mobs->flying.sprite, mobs->flying.pos_flying);
}