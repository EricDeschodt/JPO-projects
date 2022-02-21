/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** functions to handle font struct
*/

#include "../include/score.h"

score_t *create_score(char const *fontfile, char const *texte)
{
    score_t *text = malloc(sizeof(score_t));
    text->font = sfFont_createFromFile(fontfile);
    text->text = sfText_create();
    text->label = sfText_create();
    sfText_setString(text->label, "Score");
    text->string = malloc(sizeof(char) * (my_strlen(texte) + 1));
    my_strcpy(text->string, texte);
    sfText_setString(text->text, text->string);
    sfText_setFont(text->text, text->font);
    sfText_setFont(text->label, text->font);
    sfColor color = sfColor_fromRGB(0, 90, 0);
    sfText_setOutlineColor(text->label, color);
    sfText_setOutlineThickness(text->label, 3);
    sfText_setOutlineColor(text->text, color);
    sfText_setOutlineThickness(text->text, 3);
    sfVector2f pos = {150, 0};
    sfText_setPosition(text->text, pos);
    return text;
}

bool is_full_nine(char const *str)
{
    int i = 0;
    while (str[i] && str[i] == '9')
        i++;
    if (str[i])
        return false;
    return true;
}

char *score_add_one(char *str)
{
    if (!my_str_isint(str))
        return str;
    if (!is_full_nine(str)) {
        int i = (int)(my_strlen(str)) - 1;
        for (; str[i] == '9'; i--)
            str[i] = '0';
        str[i] += 1;
    }
    return str;
}

score_t *add_score(score_t *text)
{
    score_add_one(text->string);
    sfText_setString(text->text, text->string);
    return text;
}

void destroy_score(score_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    sfText_destroy(text->label);
    free(text->string);
    free(text);
}