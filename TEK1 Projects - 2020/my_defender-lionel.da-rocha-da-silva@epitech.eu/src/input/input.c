/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** mouse_button_down.c
*/

#include "defender.h"

sfBool on_key_released(sfKeyCode key, s_game **game)
{
    sfBool released = sfFalse;
    if ((*game)->event.key.code == key && (*game)->event.type ==
    sfEvtKeyReleased) {
        (*game)->event.type = -1;
        released = sfTrue;
        return released;
    }
    return released;
}

sfBool get_key_down(sfKeyCode key)
{
    static sfBool pressed = sfFalse;
    static int count = 0;
    if (!pressed && sfKeyboard_isKeyPressed(key) && count == 0) {
        pressed = sfTrue;
        count++;
        return pressed;
    }
    else if (pressed && !sfKeyboard_isKeyPressed(key) && count != 0) {
        pressed = sfFalse;
        count = 0;
    }
    return pressed;
}

sfBool get_button_down(sfMouseButton button)
{
    static sfBool pressed = sfFalse;
    if (!pressed && sfMouse_isButtonPressed(button))
        pressed = sfTrue;
    else if (pressed && !sfMouse_isButtonPressed(button))
        pressed = sfFalse;
    return pressed;
}

void button_register_h(Button *button, sfRenderWindow *window, sfEvent e,
                        sfBool enter)
{
    static int h = 0, selected_button = -1;
    sfVector2f scale_vec = (sfVector2f){1.05f, 1.05f};
    if (selected_button != button->id)
        h = 0;
    if (h == 0)
        sfSound_play(button->sound);
    selected_button = button->id;
    sfSprite_setScale(button->sprite, scale_vec);
    sfText_scale(button->text, (sfVector2f){1.015, 1.01});
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfText_setColor(button->text, (sfColor){0, 200, 100, 255});
    sfRenderWindow_drawText(window, button->text, NULL);
    h++;
    if ((mouse_button_down(window, e)) || enter) {
        sfSound_play(button->clk_sound);
        sfSprite_setColor(button->sprite,
        sfColor_fromRGBA(255, 255, 255, 100));
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
        sfRenderWindow_drawText(window, button->text, NULL);
    }
}

void button_register(Button *button, sfRenderWindow *window, void *arg,
                    sfEvent e)
{
    sfBool enter = sfKeyboard_isKeyPressed(sfKeyEnter);
    sfBool hovering = is_mouse_hovering(&button->rect, window);
    if (hovering)
    {
        button_register_h(button, window, e, enter);
        if (button->click_event[0] != NULL && mouse_button_released(window, e))
            button->click_event[0](arg);
    }
    sfText_setColor(button->text, (sfColor){255, 255, 255, 255});
    on_button_released(button, arg, hovering);
}
