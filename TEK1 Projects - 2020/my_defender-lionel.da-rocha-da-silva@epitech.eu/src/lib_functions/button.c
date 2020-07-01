/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** aaButton.c
*/

#include "defender.h"

void button_center_origin(Button **button)
{
    int x = (*button)->rect.width, y = (*button)->rect.height;
    (*button)->rect.top += y / 2 - y + 18;
    (*button)->rect.left += x / 2 - x;
    sfSprite_setOrigin((*button)->sprite, (sfVector2f){x / 2, y / 2});
}

void button_create_sound(Button *button)
{
    button->sprite = sfSprite_create();
    button->buffer =
    sfSoundBuffer_createFromFile("res/sounds/mouseover.ogg");
    button->clk_sound_buffer =
    sfSoundBuffer_createFromFile("res/sounds/button_h.wav");
    button->sound = sfSound_create();
    button->clk_sound = sfSound_create();
    sfSound_setLoop(button->sound, 0);
    sfSound_setBuffer(button->sound, button->buffer);
    sfSound_setBuffer(button->clk_sound, button->clk_sound_buffer);
}

Button *button_create(char *button_text, sfVector2f pos,
                    void (*OnClick)(void *), char *sprite_path)
{
    static int ID = 0;
    Button *button = malloc(sizeof(Button));
    button->id = ID++;
    button_create_sound(button);
    if (sprite_path)
        button->texture_idle = sfTexture_createFromFile(sprite_path, NULL);
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
    put_text(&button->text, button_text, (sfVector2f){pos.x, pos.y - 10}, 32);
    button->text = text_center(&button->text);
    button->selected = sfFalse;
    return button;
}

void on_button_released(Button *button, void *arg, sfBool hovering)
{
    if ((!sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setColor(button->sprite, sfWhite);
        sfSprite_setScale(button->sprite, (sfVector2f){1.f, 1.f});
        sfText_setScale(button->text, (sfVector2f){1.1f, 1.1f});
    }
}

sfBool mouse_button_down(sfRenderWindow *w, sfEvent e)
{
    if (e.mouseButton.button == sfMouseLeft && e.mouseButton.type ==
        sfEvtMouseButtonPressed) {
        return sfTrue;
    }
    return sfFalse;
}