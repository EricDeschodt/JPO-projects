/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** button_selectable.c
*/

#include "defender.h"

static sfBool q;

Button *button_create_selectable(char *button_text, sfVector2f pos,
    void (*OnClick)(void *), char *sprite_path)
{
    q = 1;
    Button *button = malloc(sizeof(Button));
    button->sprite = sfSprite_create();
    if (sprite_path) button->texture_idle =
    sfTexture_createFromFile(sprite_path, NULL);
    else if (sprite_path == NULL)
        button->texture_idle = sfTexture_createFromFile(
            "res/buttons/button-bg.png", NULL);
    sfSprite_setTexture(button->sprite, button->texture_idle, 1);
    sfSprite_setPosition(button->sprite, pos);
    button->text = NULL, button->rect_shape = sfRectangleShape_create(),
    button->text = init_text();
    button->click_event[0] = OnClick;
    button->rect = sfSprite_getGlobalBounds(button->sprite);
    button_center_origin(&button);
    put_text(&button->text, button_text, (sfVector2f){pos.x, pos.y-10}, 32);
    button->text = text_center(&button->text);
    button->selected = sfFalse;
    return button;
}

void button_down(Button *button, sfRenderWindow *window, void *arg, sfEvent e)
{
    sfBool enter = sfKeyboard_isKeyPressed(sfKeyEnter);
    if ((mouse_button_down(window, e) && q == 1) || enter) {
        sfSprite_setColor(button->sprite,
        sfColor_fromRGBA(255, 255, 255, 100));
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
        sfRenderWindow_drawText(window, button->text, NULL);
        if (button->click_event[0] != NULL)
            button->click_event[0](arg);
        q = 0;
    }
}

void button_register_selectable(Button *button, sfRenderWindow *window,
                                void *arg, sfEvent e)
{
    sfVector2f scale_vec = (sfVector2f){1.05f, 1.05f};
    sfBool hovering = is_mouse_hovering(&button->rect, window);
    if (hovering || button->selected) {
        sfSprite_setScale(button->sprite, scale_vec);
        sfText_setScale(button->text, scale_vec);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
        sfRenderWindow_drawText(window, button->text, NULL);
        button_down(button, window, arg, e);
    }
    on_button_released(button, arg, hovering);
}

void button_draw_selectable(sfRenderWindow *window, Button *button, void *arg,
                            sfEvent e)
{
    if (button->sprite != NULL && window != NULL)
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
    button_register(button, window, arg, e);
}

void button_draw(sfRenderWindow *window, Button *button, void *arg, sfEvent e)
{
    if (button->sprite != NULL && window != NULL)
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
    button_register(button, window, arg, e);
}