/*
** EPITECH PROJECT, 2021
** graphical
** File description:
** create
*/
#include "../../include/my.h"
#include "../../include/struct.h"

sound_t *create_sound(const char *filepath, sfBool loop)
{
    sound_t *obj = malloc(sizeof(sound_t));
    obj->sound = sfSound_create();
    obj->soundbuffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(obj->sound, obj->soundbuffer);
    sfSound_setLoop(obj->sound, loop);
    return (obj);
}

button_t *init_button(sfVector2f position, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile("sprite/button.png", NULL);
    sfTexture *message = sfTexture_createFromFile("sprite/message.png", NULL);
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    button->pos = position;
    button->r = create_rect_int(0, 0, 209, 107);
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, size);
    if (size.x < 1000) {
        sfRectangleShape_setTexture(button->rect, texture, sfFalse);
        sfRectangleShape_setTextureRect(button->rect, button->r);
    }
    else
        sfRectangleShape_setTexture(button->rect, message, sfFalse);
    return (button);
}

text_t *create_text(char *text, sfVector2f pos,
                        int size, sfColor color)
{
    text_t *obj = malloc(sizeof(text_t));
    if (my_strcmp(text, "BEYOND STARS") == 0)
        obj->font = sfFont_createFromFile("sprite/finalf.ttf");
    else
        obj->font = sfFont_createFromFile("sprite/rpg.ttf");
    obj->text = sfText_create();
    obj->pos = pos;
    obj->size = size;
    sfText_setFont(obj->text, obj->font);
    sfText_setString(obj->text, text);
    sfText_setCharacterSize(obj->text, obj->size);
    sfText_setPosition(obj->text, obj->pos);
    sfText_setColor(obj->text, color);
    return (obj);
}

protagonist_t *define_stat(int *stat, char *save)
{
    protagonist_t *obj = malloc(sizeof(protagonist_t));

    obj->lvl = (stat[0] / 100) + 1;
    obj->pv = stat[1];
    obj->pm = stat[2];
    obj->exp = stat[0];
    obj->pos_x = stat[3];
    obj->pos_y = stat[4];
    obj->steps = 0;
    obj->attack = false;
    obj->defense = false;
    obj->map_move[0] = stat[5];
    obj->map_move[1] = stat[6];
    obj->item = filled_inventory(save);
    return (obj);
}

struct_time_t *create_time(void)
{
    struct_time_t *obj = malloc(sizeof(struct_time_t));
    obj->clock = sfClock_create();
    obj->pause = false;
    return (obj);
}
