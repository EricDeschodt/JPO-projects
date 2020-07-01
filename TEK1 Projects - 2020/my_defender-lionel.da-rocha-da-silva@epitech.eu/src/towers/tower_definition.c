/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_definition.c
*/

#include "defender.h"

void create_dam(t_tower **t)
{
    (*t)->id = 0;
    (*t)->price = 100;
    (*t)->atk = 1;
    (*t)->cd = 0.5f;
    (*t)->range = 120;
    (*t)->slow = 0;
    (*t)->dot_dmg = 0;
    (*t)->time = 0;
    (*t)->sprite = sfSprite_create();
    (*t)->color = sfRed;
    (*t)->f_color = (sfColor){255, 10, 10, 1};
    (*t)->text_atk = init_text();
    (*t)->text_range = init_text();
}

t_tower *create_dam_tower(t_tower **t)
{
    *t = malloc(sizeof(t_tower));
    create_dam(t);
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    sfSprite_setTexture((*t)->sprite,
    sfTexture_createFromFile("sprites/tower-canon.png", NULL), 1);
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

void create_slow(t_tower **t)
{
    (*t)->id = 0;
    (*t)->price = 150;
    (*t)->atk = 2;
    (*t)->cd = 0.5f;
    (*t)->range = 150;
    (*t)->slow = 10;
    (*t)->dot_dmg = 0;
    (*t)->time = 0;
    (*t)->sprite = sfSprite_create();
    (*t)->color = (sfColor){50, 221, 255, 100};
    (*t)->f_color = (sfColor){50, 221, 255, 1};
    (*t)->text_atk = init_text();
    (*t)->text_range = init_text();
}

t_tower *create_slow_tower(t_tower **t)
{
    *t = malloc(sizeof(t_tower));
    create_slow(t);
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    sfSprite_setTexture((*t)->sprite,
    sfTexture_createFromFile("sprites/tower-ice.png", NULL), 1);
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

void create_dot(t_tower **t)
{
    (*t)->id = 0;
    (*t)->price = 200;
    (*t)->atk = 3;
    (*t)->cd = 0.5f;
    (*t)->range = 170;
    (*t)->slow = 0;
    (*t)->dot_dmg = 0.7;
    (*t)->time = 0;
    (*t)->sprite = sfSprite_create();
    (*t)->color = (sfColor){119, 0, 178, 100};
    (*t)->f_color = (sfColor){119, 0, 178, 3};
    (*t)->text_atk = init_text();
    (*t)->text_range = init_text();
}