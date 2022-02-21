/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** fnc to handle the interface struct
*/

#include "../include/interface.h"

void battle_tendancy(interface_t *i)
{
    sfVector2f scale = {(float)(0.8), (float)(0.8)};
    sfVector2f origin = {(float)((double)(sfSprite_getTextureRect(i->logo)
    .width) / 2), (float)((double)(sfSprite_getTextureRect(i->logo).height) /
    2)};
    sfVector2f pos = {(float)(1920.0 / 2), (float)(1080.0 / 3)};
    sfSprite_setPosition(i->logo, pos);
    sfSprite_setOrigin(i->logo, origin);
    sfSprite_setScale(i->logo, scale);
    i->play_text = sfTexture_createFromFile("assets/idle_play.png", NULL);
    i->play = sfSprite_create();
    sfSprite_setTexture(i->play, i->play_text, sfTrue);
    sfVector2f o = {(float)((double)(sfSprite_getTextureRect(i->play)
    .width) / 2), (float)((double)(sfSprite_getTextureRect(i->play)
    .height) / 2)};
    sfVector2f p = {(float)(1920.0 / 2), (float)(1080.0 / 1.5)};
    sfSprite_setOrigin(i->play, o);
    sfSprite_setPosition(i->play, p);
    i->replay_text = sfTexture_createFromFile("assets/idle_replay.png", NULL);
}

interface_t *create_interface(void)
{
    interface_t *i = malloc(sizeof(interface_t));
    i->font = sfFont_createFromFile("assets/Panic.ttf");
    i->end_label = sfText_create();
    sfColor color = sfColor_fromRGB(0, 90, 0);
    sfText_setOutlineColor(i->end_label, color);
    sfText_setOutlineThickness(i->end_label, 6);
    sfText_setCharacterSize(i->end_label, 70);
    sfText_setFont(i->end_label, i->font);
    i->logo_text = sfTexture_createFromFile("assets/logo.png", NULL);
    i->logo = sfSprite_create();
    sfSprite_setTexture(i->logo, i->logo_text, sfTrue);
    battle_tendancy(i);
    return i;
}

void display_interface(sfRenderWindow *window, interface_t *i, short menu)
{
    if (menu == -1)
        sfRenderWindow_drawSprite(window, i->logo, NULL);
    else if (menu == 0)
        sfRenderWindow_drawText(window, i->end_label, NULL);
    if (menu != 1)
        sfRenderWindow_drawSprite(window, i->play, NULL);
}

void destroy_interface(interface_t *interface)
{
    sfTexture_destroy(interface->logo_text);
    sfFont_destroy(interface->font);
    sfSprite_destroy(interface->logo);
    sfText_destroy(interface->end_label);
    sfTexture_destroy(interface->play_text);
    sfTexture_destroy(interface->replay_text);
    sfSprite_destroy(interface->play);
    free(interface);
}