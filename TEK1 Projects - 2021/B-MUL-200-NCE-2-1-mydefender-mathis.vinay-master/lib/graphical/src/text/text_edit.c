/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** functions to edit property of text_t objects
*/

#include "../../include/text.h"

void text_set_origin(text_t *text, char const *pos)
{
    float y;
    float x;
    if (my_strlen(pos) == 2) {
        y = get_pos_o_text(text->text, pos[0], 'y');
        x = get_pos_o_text(text->text, pos[1], 'x');
    } else if (my_strlen(pos) == 1) {
        y = get_pos_o_text(text->text, pos[0], 'y');
        x = get_pos_o_text(text->text, pos[0], 'x');
    } else {
        y = get_pos_o_text(text->text, 'N', 'y');
        x = get_pos_o_text(text->text, 'W', 'x');
    }
    sfVector2f vect = {x, y};
    sfText_setOrigin(text->text, vect);
}

void text_set_pos(text_t *text, float x, float y, int size)
{
    if (size != 0)
        sfText_setCharacterSize(text->text, size);
    sfVector2f position = {x, y};
    sfText_setPosition(text->text, position);
}

void text_set_outline(text_t *text, sfColor color, float thickness)
{
    sfText_setOutlineThickness(text->text, thickness);
    sfText_setOutlineColor(text->text, color);
}

void text_set_outline_rgb_color(text_t *text, int red, int green, int blue)
{
    sfText_setOutlineColor(text->text, sfColor_fromRGB(red, green, blue));
}

void text_set_rgb_color(text_t *text, int red, int green, int blue)
{
    sfText_setColor(text->text, sfColor_fromRGB(red, green, blue));
}