/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_menu_buttons.c
*/

#include "defender.h"

Button *create_menu_tower_button(t_tower t, void (*on_click)(void *), v2 pos)
{
    Button b;
    b.click_event[0] = &on_click;
    b.pos = pos;
    b.sprite = t.sprite;
    b.text = NULL;
}