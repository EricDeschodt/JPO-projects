/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** TODO: add description
*/

#include "../include/project.h"

void load_sprites(t_parallax *px)
{
    px->layer01_texture = sfTexture_createFromFile("./back/layer_1.png", NULL);
    px->layer01 = sfSprite_create();
    px->layer02_texture = sfTexture_createFromFile("./back/layer_2.png", NULL);
    px->layer02 = sfSprite_create();
    px->layer03_texture = sfTexture_createFromFile("./back/layer_3.png", NULL);
    px->layer03 = sfSprite_create();
    px->layer04_texture = sfTexture_createFromFile("./back/layer_4.png", NULL);
    px->layer04 = sfSprite_create();
    px->layer05_texture = sfTexture_createFromFile("./back/layer_5.png", NULL);
    px->layer05 = sfSprite_create();
    px->layer06_texture = sfTexture_createFromFile("./back/layer_6.png", NULL);
    px->layer06 = sfSprite_create();
    px->layer07_texture = sfTexture_createFromFile("./back/layer_7.png", NULL);
    px->layer07 = sfSprite_create();
    px->layer08_texture = sfTexture_createFromFile("./back/layer_8.png", NULL);
    px->layer08 = sfSprite_create();
    px->layer09_texture = sfTexture_createFromFile("./back/layer_9.png", NULL);
    px->layer09 = sfSprite_create();
}

void set_scale(t_parallax *px)
{
    sfVector2f scale = {(float) 1.38, (float) 0.91};
    sfVector2f tree = {(float) 1.38, (float) 1.5};
    sfSprite_setScale(px->layer01, scale);
    sfSprite_setScale(px->layer02, tree);
    sfSprite_setScale(px->layer03, tree);
    sfSprite_setScale(px->layer04, tree);
    sfSprite_setScale(px->layer05, tree);
    sfSprite_setScale(px->layer06, tree);
    sfSprite_setScale(px->layer07, tree);
    sfSprite_setScale(px->layer08, scale);
    sfSprite_setScale(px->layer09, scale);
    sfVector2f tree_pos = {0, -320};
    sfSprite_setPosition(px->layer02, tree_pos);
    sfSprite_setPosition(px->layer03, tree_pos);
    sfSprite_setPosition(px->layer04, tree_pos);
    sfSprite_setPosition(px->layer05, tree_pos);
    sfSprite_setPosition(px->layer06, tree_pos);
    sfSprite_setPosition(px->layer07, tree_pos);
}

void set_texture(t_parallax *px)
{
    sfSprite_setTexture(px->layer01, px->layer01_texture, sfFalse);
    sfSprite_setTexture(px->layer02, px->layer02_texture, sfFalse);
    sfSprite_setTexture(px->layer03, px->layer03_texture, sfFalse);
    sfSprite_setTexture(px->layer04, px->layer04_texture, sfFalse);
    sfSprite_setTexture(px->layer05, px->layer05_texture, sfFalse);
    sfSprite_setTexture(px->layer06, px->layer06_texture, sfFalse);
    sfSprite_setTexture(px->layer07, px->layer07_texture, sfFalse);
    sfSprite_setTexture(px->layer08, px->layer08_texture, sfFalse);
    sfSprite_setTexture(px->layer09, px->layer09_texture, sfFalse);
}

t_parallax *define_px(t_parallax *px)
{
    px->clock = sfClock_create();
    load_sprites(px);
    set_scale(px);
    set_texture(px);
    sfTexture_setRepeated(px->layer01_texture, sfTrue);
    sfTexture_setRepeated(px->layer02_texture, sfTrue);
    sfTexture_setRepeated(px->layer03_texture, sfTrue);
    sfTexture_setRepeated(px->layer04_texture, sfTrue);
    sfTexture_setRepeated(px->layer05_texture, sfTrue);
    sfTexture_setRepeated(px->layer06_texture, sfTrue);
    sfTexture_setRepeated(px->layer07_texture, sfTrue);
    sfTexture_setRepeated(px->layer08_texture, sfTrue);
    sfTexture_setRepeated(px->layer09_texture, sfTrue);
    return px;
}

t_rect *define_rect(t_rect *rect, t_parallax *px)
{
    rect->l1_rect = sfSprite_getTextureRect(px->layer01);
    rect->l2_rect = sfSprite_getTextureRect(px->layer02);
    rect->l3_rect = sfSprite_getTextureRect(px->layer03);
    rect->l4_rect = sfSprite_getTextureRect(px->layer04);
    rect->l5_rect = sfSprite_getTextureRect(px->layer05);
    rect->l6_rect = sfSprite_getTextureRect(px->layer06);
    rect->l7_rect = sfSprite_getTextureRect(px->layer07);
    rect->l8_rect = sfSprite_getTextureRect(px->layer08);
    rect->l9_rect = sfSprite_getTextureRect(px->layer09);
    return rect;
}