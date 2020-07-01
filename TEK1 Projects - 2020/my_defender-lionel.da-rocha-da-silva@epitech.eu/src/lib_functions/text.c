/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** text.c
*/

#include "defender.h"

sfFont *load_font(const char *filename)
{
    sfFont *font = sfFont_createFromFile(filename);
    return font;
}

sfText *init_text(void)
{
    sfFont *font = load_font("res/fonts/pondesora.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    return text;
}

sfText *text_center(sfText **text)
{
    sfFloatRect t_rect = sfText_getLocalBounds(*text);
    int t_x = t_rect.width, t_y = t_rect.height;
    t_rect.top += t_y/2 - t_y + 18;
    t_rect.left += t_x/2 - t_x;
    sfText_setOrigin(*text, (sfVector2f){t_x/2, t_y/2});
    return *text;
}
sfText *put_text(sfText **text, const char *str, sfVector2f pos,
    int text_size)
{
    sfText_setCharacterSize(*text, text_size);
    sfText_setString(*text, str);
    sfText_setPosition(*text, pos);

    return *text;
}