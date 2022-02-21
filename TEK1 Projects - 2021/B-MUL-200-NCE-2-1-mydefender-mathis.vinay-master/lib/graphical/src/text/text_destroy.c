/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Destroys the text
*/

#include "../../include/text.h"

void text_destroy(text_t *text)
{
    if (!text) return;
    if (text->font)
        sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text);
}