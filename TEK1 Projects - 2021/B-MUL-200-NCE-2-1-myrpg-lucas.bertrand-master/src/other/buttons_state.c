/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** buttons_state
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int button_state_pause(text_t *text, int pos)
{
    if (text->pos.y == pos) {
        text->pos.y -= 15;
        sfText_setPosition(text->text, text->pos);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
        text->pos.y += 15;
        sfText_setPosition(text->text, text->pos);
        return (1);
    }
}

int text_color(text_t *text)
{
    sfUint32 color[5] = {sfColor_toInteger(sfCyan), sfColor_toInteger(sfRed),
        sfColor_toInteger(sfGreen), sfColor_toInteger(sfYellow),
        sfColor_toInteger(sfWhite)};
    sfUint32 text_color = sfColor_toInteger(sfText_getColor(text->text));

    for (int i = 0; i != 5; i++)
        if (text_color == color[i])
            return ((i + 1) * 209);
}

int three_states_button(button_t *button,
                        text_t *text, int pos)
{
    if (button->pos.y == pos || button->pos.x == pos) {
        if (text->size == 23 || text->size == 30) {
            button->pos.x += 15;
            text->pos.x += 15;
        } else {
            button->pos.y -= 15;
            text->pos.y -= 15;
        }
        sfRectangleShape_setPosition(button->rect, button->pos);
        sfText_setPosition(text->text, text->pos);
    } if (sfMouse_isButtonPressed(sfMouseLeft) == true
        && button->r.left == 0) {
        button->r.left = text_color(text);
        sfRectangleShape_setTextureRect(button->rect, button->r);
        sfText_setColor(text->text, sfBlack);
    } if (sfMouse_isButtonPressed(sfMouseLeft) == false
         && button->r.left != 0) {
        put_button_back(button, text, 685);
        return (1);
    }
    return (0);
}

void put_button_back(button_t *button, text_t *text, int pos)
{
    sfColor color[5] = {sfCyan, sfRed, sfGreen, sfYellow, sfWhite};

    if (button->pos.y == pos || button->pos.x == pos) {
        if (text->size == 23 || text->size == 30) {
            button->pos.x -= 15;
            text->pos.x -= 15;
        }
        else {
            button->pos.y += 15;
            text->pos.y += 15;
        }
        sfRectangleShape_setPosition(button->rect, button->pos);
        sfText_setPosition(text->text, text->pos);
    }
    if (button->r.left != 0) {
        sfText_setColor(text->text, color[(button->r.left / 209) - 1]);
        button->r.left = 0;
        sfRectangleShape_setTextureRect(button->rect, button->r);
    }
}
