/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** some functions to run tests on radio buttons
*/

#include "../../include/radio_buttons.h"

int radio_buttons_len(radio_buttons_t *r)
{
    int i = 0;
    for (; r->button_list[i]; i++);
    return i;
}