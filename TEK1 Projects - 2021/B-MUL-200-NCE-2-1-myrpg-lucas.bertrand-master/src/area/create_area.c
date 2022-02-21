/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create_area
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void destroy_area(scene_t *area)
{
    for (int i = 0; i != 5; i++)
        destroy_object(area[i].objs->my_sprite, area[i].objs->my_texture);
    free(area[5].player);
    for (int i = 6; i != 13; i++)
        destroy_sound(area[i].sounds->sound, area[i].sounds->soundbuffer);
    for (int i = 13; i != 15; i++)
        sfRectangleShape_destroy(area[i].buttons->rect);
    for (int i = 16; i != 20; i++)
        destroy_text(area[i].texts->text, area[i].texts->font);
    sfClock_destroy(area[21].times->clock);
        destroy_object(area[22].objs->my_sprite, area[22].objs->my_texture);
    for (int i = 23; i != 27; i++)
        destroy_text(area[i].texts->text, area[i].texts->font);
}

void create_area_three(scene_t *area)
{
    area[23].texts = create_text("/", create_v2f(655, 331), 30, sfCyan);
    area[24].texts = create_text("/", create_v2f(655, 374), 30, sfMagenta);
    area[25].texts = create_text("", create_v2f(680, 331), 30, sfCyan);
    area[26].texts = create_text("", create_v2f(680, 374), 30, sfMagenta);
}

void create_area_two(scene_t *area, char code)
{
    char *sound[6] = {"sound/button.ogg", "sound/save.ogg", "sound/item.ogg",
        "sound/error.ogg", "sound/get_item.ogg", "sound/battle_begin.ogg"};
    char *map = "f123l";
    sfColor color[5] = {sfWhite, sfRed, sfGreen, sfYellow, sfCyan};
    for (int i = 7, j = 0; i != 13; i++, j++)
        area[i].sounds = create_sound(sound[j], sfFalse);
    for (int i = 13; i != 15; i++)
        area[i].buttons =  init_button(create_v2f(485, 530),
                                        create_v2f(1000, 150));
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == code)
            area[15].texts = create_text("", create_v2f(510, 545), 30, color[i]);
    area[16].texts = create_text("", create_v2f(520, 550), 30, sfCyan);
    for (int i = 17, j = 245; i != 20; i++, j += 43)
        area[i].texts = create_text("", create_v2f(610, j), 30, sfCyan);
    area[20].texts = create_text("", create_v2f(610, 374), 30, sfMagenta);
    area[21].times = create_time();
    area[22].objs = create_object("sprite/mute.png", create_v2f(0, 0),
                                 create_rect_int(0, 0, 200, 200), create_v2f(0.5, 0.5));
    create_area_three(area);
}

void create_area_one(sfRenderWindow *window, char **file,
                 int *stat, char *save)
{
    scene_t area[27];
    area[0].objs = create_object(file[0], create_v2f(0, 0),
    create_rect_int(0, 0, 192, 108), create_v2f(1, 1));
    area[1].objs = create_object("sprite/protagonist.png", create_v2f(stat[3], stat[4]),
                                create_rect_int(100, 650, 65, 100), create_v2f(1.3, 1.3));
    area[2].objs = create_object("sprite/pause.png", create_v2f(485, 100),
                                create_rect_int(0, 0, 1000, 700), create_v2f(1, 1));
    area[3].objs = create_object("sprite/item.png", create_v2f(745, 270),
                                create_rect_int(0, 0, 350, 50), create_v2f(1, 1));
    area[4].objs = create_object("sprite/transition.png", create_v2f(0, 0),
                                create_rect_int(0, 0, 640, 360), create_v2f(3, 3));
    area[5].player = define_stat(stat, save);
    area[6].sounds = create_sound(file[1], sfTrue);
    sfSound_play(area[6].sounds->sound);
    create_area_two(area, file[2][0]);
    draw_area_one(window, area, my_str_to_word_array(file[2]));
    destroy_area(area);
}
