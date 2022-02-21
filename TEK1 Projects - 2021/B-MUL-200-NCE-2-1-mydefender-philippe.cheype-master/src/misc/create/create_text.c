/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** create_text
*/

#include "defender.h"

sfText *create_text(sfVector2f pos, char *string,        \
            unsigned int char_size, sfColor color)
{
    sfText *text;
    sfFont *font;

    font = sfFont_createFromFile("assets/fonts/Carnevalee Freakshow.ttf");
    text = sfText_create();
    sfText_setCharacterSize(text, char_size);
    sfText_setString(text,        string);
    sfText_setColor(text,         color);
    sfText_setFont(text,          font);
    sfText_setPosition(text,      pos);
    return (text);
}
