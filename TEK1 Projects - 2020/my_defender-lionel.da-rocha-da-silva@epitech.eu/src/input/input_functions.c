/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** input_functions.c
*/

#include "defender.h"

sfBool is_button_released(sfRenderWindow *w, sfMouseButton button, sfEvent e)
{
    if (e.mouseButton.button == button &&
        e.mouseButton.type == sfEvtMouseButtonReleased)
        return sfTrue;
    return sfFalse;
}

sfBool is_button_pressed(sfEvent *e, sfMouseButton button)
{
    if (e->mouseButton.button == button &&
        e->mouseButton.type == sfEvtMouseButtonPressed)
        return sfTrue;
    return sfFalse;
}

t_tower *create_dot_tower(t_tower **t)
{
    *t = malloc(sizeof(t_tower));
    create_dot(t);
    sfSprite_setTexture((*t)->sprite,
    sfTexture_createFromFile("sprites/tower-magic.png", NULL), 1);
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    (*t)->s_dmg = malloc(20);
    (*t)->s_dmg[0] = '\0';
    my_strcat((*t)->s_dmg, "DMG: ");
    my_strcat((*t)->s_dmg, my_itoa((*t)->atk));
    put_text(&(*t)->text_atk, (*t)->s_dmg, (v2){pos.x + 150, pos.y + 45}, 16);
    (*t)->s_range = malloc(20);
    (*t)->s_range[0] = '\0';
    my_strcat((*t)->s_range, "Range: ");
    my_strcat((*t)->s_range, my_itoa((*t)->range));
    put_text(&(*t)->text_range,
    (*t)->s_range, (v2){pos.x + 150, pos.y + 60}, 16);
    return *t;
}

void create_freez(t_tower **t)
{
    (*t)->id = 0;
    (*t)->price = 250;
    (*t)->atk = 4;
    (*t)->cd = 0.5f;
    (*t)->range = 200;
    (*t)->slow = 0;
    (*t)->dot_dmg = 0;
    (*t)->time = 0;
    (*t)->sprite = sfSprite_create();
    (*t)->color = (sfColor){222, 215, 6, 100};
    (*t)->f_color = (sfColor){222, 215, 6, 1};
    (*t)->text_atk = init_text();
    (*t)->text_range = init_text();
}

t_tower *create_freez_tower(t_tower **t)
{
    *t = malloc(sizeof(t_tower));
    create_freez(t);
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    sfSprite_setTexture((*t)->sprite,
    sfTexture_createFromFile("sprites/tower-tesla.png", NULL), 1);
    (*t)->s_dmg = malloc(20);
    (*t)->s_dmg[0] = '\0';
    my_strcat((*t)->s_dmg, "DMG: ");
    my_strcat((*t)->s_dmg, my_itoa((*t)->atk));
    put_text(&(*t)->text_atk, (*t)->s_dmg, (v2){pos.x + 150, pos.y + 45}, 16);
    (*t)->s_range = malloc(20);
    (*t)->s_range[0] = '\0';
    my_strcat((*t)->s_range, "Range: ");
    my_strcat((*t)->s_range, my_itoa((*t)->range));
    put_text(&(*t)->text_range,
    (*t)->s_range, (v2){pos.x + 150, pos.y + 60}, 16);
    return *t;
}