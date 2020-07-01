/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_1duck
*/

#include "my.h"

void dog_up_down1(all_t *all)
{
    if (all->pos.pos_menu_dog_pause.y < 364) {
        all->my_int.laugh_dog_top = 1;
        all->my_int.dog_clock++;
    }
    if (all->pos.pos_menu_dog_pause.y > 364 && all->my_int.laugh_dog_top == 0)
        all->pos.pos_menu_dog_pause.y -= 10;
    if (all->pos.pos_menu_dog_pause.y < 500 && all->my_int.laugh_dog_top == 1
        && all->my_int.dog_clock > 45) {
        all->pos.pos_menu_dog_pause.y += 10;
        all->my_int.dog_clock++;
    }
    dog_reset(all);
}

void dog_1duck(all_t *all, sfEvent event)
{
    if (all->my_int.dog_sound != 1) {
        sfSound_play(all->sound.success);
        all->my_int.dog_sound = 1;
    }
    dog_up_down1(all);
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
    }
    sfSprite_setPosition(all->sprite2.dog_1duck, all->pos.pos_menu_dog_pause);
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.dog_1duck, NULL);
}

void if_select(all_t *all, sfEvent event)
{
    if (all->my_int.dog_sound != 1)
        all->my_int.dog_clock2++;
    if (all->my_int.duck_shoot == 0)
        dog_laugh(all, event);
    if (all->my_int.duck_shoot == 1 && all->my_int.dog_clock2 >= 30)
        dog_1duck(all, event);
    if (all->my_int.duck_shoot == 2 && all->my_int.dog_clock2 >= 60)
        dog_2duck(all, event);
}

void dog_spawn2(all_t *all, sfEvent event)
{
    if (all->my_int.game_mode == 1) {
        if (all->my_int.duck_spawn1 > 1)
            all->my_int.duck_spawn1 = 1;
        if (all->my_int.duck_spawn2 > 1)
            all->my_int.duck_spawn2 = 1;
        if (all->my_int.duck_spawn1 == 1 && all->my_int.duck_spawn2 == 1)
            if_select(all, event);
    }
}