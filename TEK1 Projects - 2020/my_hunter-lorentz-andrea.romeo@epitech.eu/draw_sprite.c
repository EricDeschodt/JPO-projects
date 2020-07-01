/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** draw_sprite
*/

#include "my.h"

void draw_sprite_new_round2(all_t *all)
{
    sfRenderWindow_drawText(all->window, all->write.text3, NULL);
    sfRenderWindow_drawText(all->window, all->write.text4, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay2, NULL);
    sfRenderWindow_drawText(all->window, all->write.text5, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.ammo, NULL);
    sfRenderWindow_drawText(all->window, all->write.text6, NULL);
}

void draw_sprite_new_round(all_t *all, sfEvent event)
{
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    dog_spawn(all, event);
    if ((all->clock.seconds_dog_jump >= 4 && all->clock.seconds_dog_jump <=
        5) && all->my_int.perfect != 0)
        sfRenderWindow_drawSprite(all->window, all->sprite2.perfect_s, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite.foreground, NULL);
    if (all->my_int.dog_draw != 1)
        sfRenderWindow_drawSprite(all->window, all->sprite.dog, NULL);
    if (all->my_int.dog_draw == 1 && all->my_int.dog_draw3 != 1)
        sfRenderWindow_drawSprite(all->window, all->sprite.dog_jump, NULL);
    if (all->my_int.dog_draw3 == 1) {
        sfRenderWindow_drawSprite(all->window, all->sprite.dog_jump, NULL);
        sfRenderWindow_drawSprite(all->window, all->sprite.foreground, NULL);
        all->rect.red_duck.width = 180;
    }
    draw_sprite_new_round2(all);
}

void draw_sprite(sfEvent event, all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    regroup_if_choice(all, event);
    sfRenderWindow_drawSprite(all->window, all->sprite.foreground, NULL);
    if (all->my_int.dog_draw != 1 && all->my_int.end_round == 0) {
        sfRenderWindow_drawSprite(all->window, all->sprite.dog, NULL);
        sfRenderWindow_drawText(all->window, all->write.text3, NULL);
        sfRenderWindow_drawText(all->window, all->write.text4, NULL);
    }
    if (all->my_int.dog_draw == 1 && all->my_int.dog_draw3 != 1
        && all->my_int.end_round == 0)
        sfRenderWindow_drawSprite(all->window, all->sprite.dog_jump, NULL);
    if (all->my_int.dog_draw3 == 1 && all->my_int.end_round == 0) {
        sfRenderWindow_drawSprite(all->window, all->sprite.dog_jump, NULL);
        sfRenderWindow_drawSprite(all->window, all->sprite.foreground, NULL);
    }
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay2, NULL);
    sfRenderWindow_drawText(all->window, all->write.text5, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.ammo, NULL);
    sfRenderWindow_drawText(all->window, all->write.text6, NULL);
}

void draw_cursor(all_t *all)
{
    all->pos.pos_mouse.x = sfMouse_getPositionRenderWindow(all->window).x -28;
    all->pos.pos_mouse.y = sfMouse_getPositionRenderWindow(all->window).y -21;
    sfSprite_setPosition(all->sprite.cursor, all->pos.pos_mouse);
    sfRenderWindow_drawSprite(all->window, all->sprite.cursor, NULL);
}