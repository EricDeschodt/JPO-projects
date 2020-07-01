/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_2duck
*/

#include "my.h"

void dog_up_down2(all_t *all)
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
    all->my_int.dog_clock++;
    dog_reset(all);
}

void dog_2duck(all_t *all, sfEvent event)
{
    if (all->my_int.dog_sound != 1) {
        sfSound_play(all->sound.success);
        all->my_int.dog_sound = 1;
    }
    dog_up_down2(all);
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
    }
    sfSprite_setPosition(all->sprite2.dog_2duck, all->pos.pos_menu_dog_pause);
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.dog_2duck, NULL);
}