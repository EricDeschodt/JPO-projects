/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** init_regroup
*/

#include "my.h"

void write_init2(write_t *write, all_t *all)
{
    write->text5 = sfText_create();
    sfText_setFont(write->text5, write->font);
    sfText_setCharacterSize(write->text4, 40);
    all->overlay_green.r = 129;
    all->overlay_green.g = 199;
    all->overlay_green.b = 1;
    all->overlay_green.a = 255;
    sfText_setColor(write->text5, all->overlay_green);
    write->text6 = sfText_create();
    sfText_setFont(write->text6, write->font);
    sfText_setCharacterSize(write->text6, 32);
}

void write_init(write_t *write, all_t *all)
{
    write->font = sfFont_createFromFile("font/leaderson.ttf");
    write->text1 = sfText_create();
    sfText_setFont(write->text1, write->font);
    all->write.top_score = open_read();
    sfText_setString(all->write.text1, all->write.top_score);
    all->green_menu.r = 150;
    all->green_menu.g = 255;
    all->green_menu.b = 150;
    all->green_menu.a = 200;
    sfText_setColor(write->text1, all->green_menu);
    write->text2 = sfText_create();
    sfText_setFont(write->text2, write->font);
    sfText_setString(write->text2, "PAUSE");
    write->text3 = sfText_create();
    sfText_setFont(write->text3, write->font);
    sfText_setString(write->text3, "ROUND");
    write->text4 = sfText_create();
    sfText_setFont(write->text4, write->font);
    sfText_setCharacterSize(write->text4, 40);
    write_init2(write, all);
}

all_t init_game_over(all_t *all)
{
    all->write.top_score = open_read();
    sfText_setString(all->write.text1, all->write.top_score);
    first_init_dog_duck(&all->pos);
    rect_init(&all->rect);
    int_init(&all->my_int);
    return (*all);
}

all_t init_regroup_round(all_t *all)
{
    first_init_dog_duck(&all->pos);
    all->rect.dog.top = 0;
    all->rect.dog.left = 0;
    all->rect.dog.width = 120;
    all->rect.dog.height = 100;
    int_init(&all->my_int);
    return (*all);
}

all_t init_regroup(all_t *all)
{
    first_init_dog_duck(&all->pos);
    rect_init(&all->rect);
    sprite_init(&all->sprite);
    sprite_init2(&all->sprite, &all->sprite2);
    texture_init(&all->texture);
    texture_init2(&all->texture);
    texture_init3(&all->texture, &all->texture2);
    texture_init4(&all->texture2);
    set_texture(&all->sprite, &all->texture);
    set_texture3(&all->sprite2, &all->texture2);
    set_texture2(&all->sprite, &all->texture, &all->sprite2, &all->texture2);
    int_init(&all->my_int);
    sound_init(&all->sound);
    clock_init(&all->clock);
    write_init(&all->write, all);
    setup(all);
    return (*all);
}