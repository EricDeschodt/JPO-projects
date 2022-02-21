/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** manage all event
*/

#include "../include/myhunter.h"

static void manage_keyboard_press(myhunter_t *myhunter)
{
    if (myhunter->event.key.code == sfKeyEscape)
        sfRenderWindow_close(myhunter->window);
}

static void manage_mouse_button(myhunter_t *myhunter)
{
    if (myhunter->event.mouseButton.button == sfMouseLeft) {
        myhunter->posMouse.x = myhunter->event.mouseButton.x;
        myhunter->posMouse.y = myhunter->event.mouseButton.y;
    }
    return;
}

void analyseEvents(myhunter_t *myhunter)
{
    if (myhunter->event.type == sfEvtMouseButtonPressed) {
        manage_mouse_button(myhunter);
        // duck_anim(myhunter, myhunter->duck);
    } else if (myhunter->event.type == sfEvtClosed)
        sfRenderWindow_close(myhunter->window);
    else if (myhunter->event.type == sfEvtKeyPressed)
        manage_keyboard_press(myhunter);
    return;
}