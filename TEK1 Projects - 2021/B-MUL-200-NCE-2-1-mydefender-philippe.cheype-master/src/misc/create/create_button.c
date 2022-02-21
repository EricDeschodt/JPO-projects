/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** create_button
*/

#include <stdlib.h>
#include "defender.h"
#include "my.h"

button_t *create_button(sfFloatRect pos_size, char *string, sfTexture *texture)
{
    sfVector2f size =   {pos_size.width, pos_size.height};
    sfVector2f pos  =   {pos_size.left,  pos_size.top};
    sfVector2f text_p = { pos.x + 290 - 8 * my_strlen(string), pos.y + 18};
    button_t *button;

    button = malloc(sizeof(button_t));
    button->pos_size = pos_size;
    button->text = create_text(text_p, string, 50, sfBlack);
    button->rect = create_rectangle(pos, size, texture, sfTrue);
    return (button);
}

button_t *create_button_ns(sfFloatRect pos_size, char *string[],    \
                                sfTexture **text, int i)
{
    sfVector2f size = {pos_size.width, pos_size.height};
    sfVector2f pos  = {pos_size.left,  pos_size.top};
    sfVector2f text_p;
    button_t *button;

    button = malloc(sizeof(button_t) * i);
    for (int j = 0; j < i; j++) {
        text_p.x = pos.x + 290 - 8 * my_strlen(string[j + 1]);
        text_p.y = pos.y + 18;
        button[j].pos_size = pos_size;
        button[j].text = create_text(text_p, string[j + 1], 50, sfBlack);
        button[j].rect = create_rectangle(pos, size, text[j], sfTrue);
        pos.y += 130;
    }
    return (button);
}
