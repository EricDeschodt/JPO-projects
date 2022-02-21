/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** All text related function
*/

#include "../include/project.h"

t_text *define_text(t_text *text)
{
    text->s = 0;
    text->s_score = malloc(sizeof(char) * 10 + 1);
    text->title_text = sfText_create();
    text->enter_text = sfText_create();
    text->lose_text = sfText_create();
    text->win_text = sfText_create();
    text->score = sfText_create();
    text->font = sfFont_createFromFile("./fonts/dogicapixelbold.ttf");
    sfText_setFont(text->score, text->font);
    sfText_setString(text->win_text, "You won");
    sfText_setString(text->lose_text, "You lost");
    define_title(text);
    define_score(text);
    define_win_lose(text);
    return text;
}

void define_title(t_text *text)
{
    sfText_setFont(text->title_text, text->font);
    sfText_setFont(text->enter_text, text->font);
    sfText_setString(text->title_text, "Lonely Runner");
    sfText_setString(text->enter_text, "press ENTER to play");
    sfVector2f title = {480, 300};
    sfVector2f enter = {520, 350};
    sfVector2f title_scale = {1, 1};
    sfVector2f enter_scale = {0.5, 0.5};
    sfText_setOutlineColor(text->title_text, sfBlack);
    sfText_setOutlineThickness(text->title_text, 2);
    sfText_setOutlineColor(text->enter_text, sfBlack);
    sfText_setOutlineThickness(text->enter_text, 3);
    sfText_setColor(text->title_text, sfYellow);
    sfText_setPosition(text->title_text, title);
    sfText_setPosition(text->enter_text, enter);
    sfText_setScale(text->title_text, title_scale);
    sfText_setScale(text->enter_text, enter_scale);
}

void define_score(t_text *text)
{
    sfVector2f score = {0.5, 0.5};
    sfText_setString(text->score, text->s_score);
    sfText_setOutlineColor(text->score, sfBlack);
    sfText_setOutlineThickness(text->score, 3);
    sfText_setScale(text->score, score);
}

void define_win_lose(t_text *text)
{
    sfText_setFont(text->win_text, text->font);
    sfText_setFont(text->lose_text, text->font);
    sfVector2f coord = {520, 300};
    sfVector2f scale = {1, 1};
    sfText_setOutlineColor(text->win_text, sfBlack);
    sfText_setColor(text->win_text, sfBlue);
    sfText_setOutlineThickness(text->win_text, 2);
    sfText_setOutlineColor(text->lose_text, sfBlack);
    sfText_setColor(text->lose_text, sfRed);
    sfText_setOutlineThickness(text->lose_text, 2);
    sfText_setPosition(text->win_text, coord);
    sfText_setPosition(text->lose_text, coord);
    sfText_setScale(text->win_text, scale);
    sfText_setScale(text->lose_text, scale);
}