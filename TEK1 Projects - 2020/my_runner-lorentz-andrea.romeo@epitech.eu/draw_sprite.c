/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** draw_sprite
*/

#include "my.h"

void draw_michael_bis(all_t *all)
{
    if (all->my_int.jump == 1 && (all->my_int.crouch != 1
        && all->my_int.hit != 1 && all->my_int.up_throw != 1))
        sfRenderWindow_drawSprite(all->window, all->sprite.jump, NULL);
    if (all->my_int.crouch == 1 && (all->my_int.hit != 1
        && all->my_int.jump != 1 && all->my_int .up_throw != 1)) {
        if (all->my_int.hit_crouch == 1) sfRenderWindow_drawSprite
            (all->window, all->sprite.crouch_hit, NULL);
        else if (all->my_int.down_throw == 1) {
            if (all->my_int.hat == 1)
                sfRenderWindow_drawSprite(all->window, all->sprite.hat, NULL);
            sfRenderWindow_drawSprite(all->window,
                all->sprite.down_throw, NULL);
        }
        else sfRenderWindow_drawSprite(all->window, all->sprite.crouch, NULL);
    }
    if (all->my_int.up_throw == 1) {
        if (all->my_int.hat == 1)
            sfRenderWindow_drawSprite(all->window, all->sprite.hat, NULL);
        sfRenderWindow_drawSprite(all->window, all->sprite.up_throw, NULL);
    }
}

void draw_michael(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->background2.background2_3,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background3,
        NULL), draw_list_zombie(all);
    if (all->my_int.jump != 1 && all->my_int.crouch != 1
        && all->my_int.hit != 1 && all->my_int.up_throw != 1)
        sfRenderWindow_drawSprite(all->window, all->sprite.michael, NULL);
    if (all->my_int.hit == 1 && (all->my_int.crouch != 1
        && all->my_int.up_throw != 1))
        sfRenderWindow_drawSprite(all->window, all->sprite.hit, NULL);
    draw_michael_bis(all);
    sfRenderWindow_drawSprite(all->window, all->background2.background2_2,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background2, NULL);
    sfRenderWindow_drawSprite(all->window, all->background2.background2_1,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background2.background2_1_2,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background1, NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background1_2, NULL);
}

void draw_background(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->background.background7, NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background6, NULL);
    sfRenderWindow_drawRectangleShape(all->window, all->rectangle, NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background5, NULL);
    sfRenderWindow_drawSprite(all->window,
        all->background2.background2_5, NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background5, NULL);
    sfRenderWindow_drawSprite(all->window, all->background2.background2_5,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background4, NULL);
    sfRenderWindow_drawSprite(all->window, all->background2.background2_4,
        NULL);
    sfRenderWindow_drawSprite(all->window, all->background.background4, NULL);
    draw_michael(all);
    if (all->my_int.menu != 0 || all->my_int.speed == 0) draw_menu_1(all);
    else if (all->my_int.menu == 0 && all->my_int.skull != 0) {
        sfText_setString(all->write.skull_txt, my_put_nbr(all->my_int.skull,
            all->write.skull));
        sfRenderWindow_drawText(all->window, all->write.skull_txt, NULL);
    } sfRenderWindow_display(all->window);
}

void while_loop(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 0 && tmp->dead != 2) {
        sfRenderWindow_drawSprite(all->window, tmp->fat.sprite, NULL);
        hat_fat_hit_box(all, tmp), crouch_fat_hit_box(all, tmp);
    }
    if (tmp->who == 1 && tmp->dead != 4) {
        sfRenderWindow_drawSprite(all->window, tmp->flying.sprite, NULL);
        hat_flying_hit_box(all, tmp), hat_flying2_hit_box(all, tmp);
        crouch_fat_hit_box(all, tmp);
    }
    if (tmp->who >= 2 && tmp->who <= 8)
        sfRenderWindow_drawSprite(all->window, tmp->traps.sprite, NULL);
    if ((tmp->who == 9 || tmp->who == -1) && tmp->dead != 1) {
        sfRenderWindow_drawSprite(all->window, tmp->traps.sprite, NULL);
        skull_hit_box(all, tmp);
    }
    michael_fat_hit_box(all, tmp), michael_flying_hit_box(all, tmp);
    michael_flying_hit_box2(all, tmp), michael_axe1_hit_box(all, tmp);
    michael_spikes_hit_box(all, tmp), michael_saw_hit_box(all, tmp);
    michael_balls_hit_box(all, tmp), michael_axe2_hit_box(all, tmp);
}

void draw_list_zombie(all_t *all)
{
    if (all->mobs != NULL) {
        dlist_node_t *tmp = all->mobs->begin;
        while (tmp != NULL) {
            while_loop(all, tmp);
            tmp = tmp->next;
        }
    }
}