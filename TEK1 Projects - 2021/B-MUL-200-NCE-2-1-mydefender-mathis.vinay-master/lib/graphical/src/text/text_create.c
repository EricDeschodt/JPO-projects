/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates a sprite
*/

#include "../../include/text.h"

text_t *
text_create(char const *string, char const *pos, sfColor color, bool is_thin)
{
    text_t *text = malloc(sizeof(text_t));
    text->text = sfText_create();
    if (my_is_file_valid("assets/gui/kenvector_future.ttf")) {
        if (!is_thin)
            text->font = sfFont_createFromFile(
                        "assets/gui/kenvector_future.ttf");
        else
            text->font = sfFont_createFromFile
            ("assets/gui/kenvector_future_thin.ttf");
        sfText_setFont(text->text, text->font);
    } else
        text->font = NULL;
    sfText_setString(text->text, string);
    sfText_setColor(text->text, color);
    text_set_origin(text, pos);
    return text;
}

float get_pos_o_text(sfText *text, char pos, char axe)
{
    float res = 0;
    sfFloatRect r = sfText_getLocalBounds(text);
    if (pos == 'C')
        res = (axe == 'y')?r.height / 2:r.width / 2;
    if (pos == 'N' || pos == 'O' || pos == 'W')
        res = 0;
    if (pos == 'S' || pos == 'E')
        res = (axe == 'y')?r.height:r.width;
    return res;
}