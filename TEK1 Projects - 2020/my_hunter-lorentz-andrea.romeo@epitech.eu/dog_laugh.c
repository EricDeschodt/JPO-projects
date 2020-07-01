/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_laugh
*/

#include "my.h"

void dog_laugh_reset_duck(all_t *all)
{
    if (all->my_int.choice == 0 || all->my_int.choice == 1 ||
        all->my_int.choice == 2)
        all->pos.pos_duck.x = -120;
    if (all->my_int.choice == 3 || all->my_int.choice == 4 ||
        all->my_int.choice == 5)
        all->pos.pos_duck_rev.x = 850;
    if (all->my_int.choice == 6 || all->my_int.choice == 7 ||
        all->my_int.choice == 8)
        all->pos.pos_duck_bot.y = 450;
    if (all->my_int.choice2 == 0 || all->my_int.choice2 == 1 ||
        all->my_int.choice2 == 2)
        all->pos.pos_duck2.x = -120;
    if (all->my_int.choice2 == 3 || all->my_int.choice2 == 4 ||
        all->my_int.choice2 == 5)
        all->pos.pos_duck_rev2.x = 850;
    if (all->my_int.choice2 == 6 || all->my_int.choice2 == 7 ||
        all->my_int.choice2 == 8)
        all->pos.pos_duck_bot2.y = 450;
}

void dog_up_down(all_t *all)
{
    if (all->my_int.menu_dog > 8) {
        all->rect.laugh_dog.left = move_laugh_dog(all->rect.laugh_dog).left;
        sfSprite_setTextureRect(all->sprite2.laugh_dog, all->rect.laugh_dog);
        all->my_int.menu_dog = 0;
    }
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

void dog_laugh(all_t *all, sfEvent event)
{
    if (all->my_int.dog_sound != 1) {
        sfSound_play(all->sound.laugh_dog);
        all->my_int.dog_sound = 1;
    }
    all->my_int.menu_dog++;
    dog_up_down(all);
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
    }
    sfSprite_setPosition(all->sprite2.laugh_dog, all->pos.pos_menu_dog_pause);
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.laugh_dog, NULL);
}

void dog_if_regroup(all_t *all, sfEvent event)
{
    if (all->my_int.dog_sound != 1)
        all->my_int.dog_clock2++;
    if (all->my_int.duck_shoot == 0)
        dog_laugh(all, event);
    if (all->my_int.duck_shoot == 1 && all->my_int.dog_clock2 >= 30)
        dog_1duck(all, event);
}

void dog_spawn(all_t *all, sfEvent event)
{
    if (all->my_int.spawn_count >= 10 && all->my_int.end_round == 1) {
        *all = init_regroup_round(all);
        all->my_int.main_menu = 3;
        all->my_int.x1 += 6;
    }
    else if (all->my_int.game_mode != 1) {
        if (all->my_int.duck_spawn1 > 1)
            all->my_int.duck_spawn1 = 1;
        if (all->my_int.duck_spawn1 == 1)
            dog_if_regroup(all, event);
    }
    dog_spawn2(all, event);
}