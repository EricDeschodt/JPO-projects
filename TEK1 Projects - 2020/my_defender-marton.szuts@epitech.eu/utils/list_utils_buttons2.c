/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** list_utils_buttons2
*/

#include "defender.h"

list_buttons_t *clear_list(list_buttons_t *li)
{
    while (!is_empty_list_buttons(li))
        li = pop_front_buttons(li);
    return (new_list_buttons());
}

list_targetting_t *clear_list_target(list_targetting_t *li)
{
    while (!is_empty_list_targetting(li))
        li = pop_front_targetting(li);
    return (NULL);
}

void black_init(all_t *s_all)
{
    s_all->s_buttons->black = sfSprite_create();
    s_all->s_buttons->text_black =
    sfTexture_createFromFile("sprites/black.png", NULL);
    sfSprite_setTexture(s_all->s_buttons->black,
    s_all->s_buttons->text_black, sfTrue);
    s_all->s_buttons->color = (sfColor){0, 0, 0, 125};
    sfSprite_setColor(s_all->s_buttons->black, s_all->s_buttons->color);
}