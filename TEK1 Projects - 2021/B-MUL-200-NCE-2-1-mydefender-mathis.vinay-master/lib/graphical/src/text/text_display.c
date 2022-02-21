/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Displays the text
*/

#include "../../include/text.h"

void text_display(text_t *text, sfRenderWindow *win)
{
    sfRenderWindow_drawText(win, text->text, NULL);
}
