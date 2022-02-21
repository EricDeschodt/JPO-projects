/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** displays a button
*/

#include "../../include/buttons.h"
#include "../../../print/include/print.h"

void button_display(sprite_t *button, sfRenderWindow *win, bool should_animate)
{
    bool is_in_sprite = button_is_on_over(button, win);
    sfIntRect rect_text = {0, sfSprite_getTextureRect (button->sprite)
    .height * 2, sfSprite_getTextureRect(button->sprite).width,
    sfSprite_getTextureRect(button->sprite).height};
    if (is_in_sprite && !sfMouse_isButtonPressed(sfMouseLeft))
        rect_text.top = rect_text.top / 2;
    else if (!is_in_sprite)
        rect_text.top = 0;
    if (!should_animate)
        rect_text.top = 0;
    sfSprite_setTextureRect(button->sprite, rect_text);
    sfRenderWindow_drawSprite(win, button->sprite, NULL);
}