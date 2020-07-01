/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slot_init
*/

#include "defender.h"

void create_slot_pos(s_slot **obj, v2 pos, char *filepath[], int i)
{
    sfSprite_setPosition(obj[i]->sprite_placable,
    sfSprite_getPosition(obj[i]->sprite));
    sfTexture_setSmooth(obj[i]->texture, sfTrue);
    obj[i]->f_color = sfRed;
    obj[i]->color = sfRed;
    obj[i]->area = sfCircleShape_create();
    sfCircleShape_setRadius(obj[i]->area, obj[i]->range);
    sfCircleShape_setOutlineThickness(obj[i]->area, 1);
    sfCircleShape_setOutlineColor(obj[i]->area, sfRed);
    sfCircleShape_setFillColor(obj[i]->area, (sfColor){255, 10, 10, 1});
    sfCircleShape_setPosition(obj[i]->area, obj[i]->pos);
}

void create_slot(s_slot **obj, v2 pos, char *filepath[], int i)
{
    static int id = 0;
    obj[i] = malloc(sizeof(s_slot));
    obj[i]->id = id++;
    obj[i]->is_tower = 0;
    obj[i]->pos = pos;
    obj[i]->texture = sfTexture_createFromFile(filepath[i], NULL);
    obj[i]->texture_placable = sfTexture_createFromFile("res/plus.png", NULL);
    obj[i]->sprite = sfSprite_create();
    obj[i]->sprite_tower = sfSprite_create();
    obj[i]->sprite_placable = sfSprite_create();
    obj[i]->on_slot_hover = on_slot_hover;
    obj[i]->tower = NULL;
    obj[i]->range = 100;
    sfSprite_setOrigin(obj[i]->sprite, (sfVector2f){24, 60});
    sfSprite_setOrigin(obj[i]->sprite_placable, (sfVector2f){48/2, 48/2});
    sfSprite_setTexture(obj[i]->sprite, obj[i]->texture, sfTrue);
    sfSprite_setTexture(obj[i]->sprite_placable, obj[i]->texture_placable, 1);
    sfSprite_setPosition(obj[i]->sprite, obj[i]->pos);
    create_slot_pos(obj, pos, filepath, i);
}

void create_slot_rect(s_slot **obj, int i, sfColor white)
{
    sfRectangleShape_setTextureRect(obj[i]->shape_contour,
    sfSprite_getTextureRect(obj[i]->sprite));
    sfRectangleShape_setSize(obj[i]->shape_contour, (v2){43, 43});
    sfRectangleShape_setOutlineThickness(obj[i]->shape_contour, 5);
    sfRectangleShape_setOutlineColor(obj[i]->shape_contour, sfBlue);
    sfRectangleShape_setFillColor(obj[i]->shape_contour, white);
}

s_slot **create_slot_object(char *filepath[], v2 pos)
{
    s_slot **obj = malloc(sizeof(*obj) * 6);
    sfColor white = (sfColor){0, 0, 0, 0};
    for (int i = 0; i < 5; i++) {
        create_slot(obj, pos, filepath, i);
        obj[i]->rect = (sfFloatRect){pos.x-24, pos.y-10, 48, 48};
        obj[i]->shape_contour = sfRectangleShape_create();
        sfRectangleShape_setPosition(obj[i]->shape_contour, obj[i]->pos);
        sfRectangleShape_setOrigin(obj[i]->shape_contour,
        (v2){48/2-2, 48/2-2});
        create_slot_rect(obj, i, white);
        sfSprite_setColor(obj[i]->sprite, (sfColor){163, 196, 80, 1});
        sfSprite_setPosition(obj[i]->sprite_tower, (v2){pos.x-24, pos.y-80});
        obj[i]->clock = sfClock_create();
        obj[i]->seconds = 0;
    }
    obj[5] = NULL;
    return (obj);
}