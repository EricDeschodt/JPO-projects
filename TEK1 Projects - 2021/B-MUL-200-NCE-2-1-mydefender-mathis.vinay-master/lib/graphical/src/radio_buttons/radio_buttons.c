/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a set a fonctions to use the radio_button struct
*/

#include "../../include/radio_buttons.h"

radio_buttons_t *radio_buttons_create(int h, char const *selector_path, float
x, float y)
{
    radio_buttons_t *r = malloc(sizeof(radio_buttons_t));
    r->h = h;
    r->selector = sprite_create(selector_path, "C", false, false);
    sfIntRect rect = sfSprite_getTextureRect(r->selector->sprite);
    rect.height = rect.height / 2;
    sfSprite_setTextureRect(r->selector->sprite, rect);
    sprite_set_origin(r->selector, "C");
    r->x = x;
    r->y = y;
    r->selected = -1;
    r->button_list = malloc(sizeof(sprite_t));
    r->button_list[0] = NULL;
    return r;
}

void radio_buttons_append(radio_buttons_t *r, char const *buttonpath)
{
    int len = radio_buttons_len(r);
    sprite_t **list = malloc(sizeof(sprite_t *) * (len + 2));
    int i = 0;
    for (; r->button_list[i]; i++)
        list[i] = r->button_list[i];
    list[i] = sprite_create(buttonpath, "C", false, false);
    sprite_set_pos(list[i], r->x, r->y + (float)(r->h * (i + 1)), 1);
    list[++i] = NULL;
    free(r->button_list);
    r->button_list = list;
}

void radio_buttons_update_selection(radio_buttons_t *r, sfRenderWindow *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; r->button_list[i]; i++) {
        sfFloatRect rect = sfSprite_getGlobalBounds(r->button_list[i]->sprite);
        if (rect.left <= (float)(pos.x) && (float)(pos.x) <= rect.left + rect
        .width && rect.top <= (float)(pos.y) && (float)(pos.y) <= rect.top +
        rect.height) {
            if (r->selected == i)
                r->selected = -1;
            else
                r->selected = i;
            return;
        }
    }
}

void radio_buttons_display(radio_buttons_t *r, struct sfRenderWindow *w,
bool should_animate)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(w);
    sfIntRect selec_rect = sfSprite_getTextureRect(r->selector->sprite);
    for (int i = 0; r->button_list[i]; i++) {
        sprite_display(r->button_list[i], w);
        sfFloatRect rect = sfSprite_getGlobalBounds(r->button_list[i]->sprite);
        sfVector2f pos = sfSprite_getPosition(r->button_list[i]->sprite);
        if (rect.left <= (float)(mouse_pos.x) && (float)(mouse_pos.x) <=
        (rect.left + rect.width) && rect.top <= (float)(mouse_pos.y) &&
        (float)(mouse_pos.y) <= (rect.top + rect.height) && should_animate)
            selec_rect.top = (int)(selec_rect.height);
        else if (i == r->selected)
            selec_rect.top = 0;
        else
            continue;
        sfSprite_setTextureRect(r->selector->sprite, selec_rect);
        sfSprite_setPosition(r->selector->sprite, pos);
        sprite_display(r->selector, w);
    }
}

void radio_buttons_destroy(radio_buttons_t *r)
{
    sprite_destroy(r->selector);
    for (int i = 0; r->button_list[i]; i++)
        sprite_destroy(r->button_list[i]);
    free(r->button_list);
    free(r);
}