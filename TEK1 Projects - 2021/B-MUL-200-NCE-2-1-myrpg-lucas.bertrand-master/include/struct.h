/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct scene_s {
    struct game_object_s *objs;
    struct button_s *buttons;
    struct sound_s *sounds;
    struct text_s *texts;
    struct struct_time_s *times;
    struct protagonist_s *player;
    struct enemies_s *enemy;
}scene_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfIntRect r;
}button_t;

typedef struct game_object_s {
    sfSprite *my_sprite;
    sfTexture *my_texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    int nbr;
    int rect_max;
}object_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
    bool pause;
    int nbr;
}sound_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    int size;
}text_t;

typedef struct struct_time_s {
    sfClock *clock;
    float seconds;
    sfTime time;
    bool pause;
    int nbr;
}struct_time_t;

typedef struct protagonist_s {
    int pv;
    int pm;
    int lvl;
    int exp;
    int pos_x;
    int pos_y;
    int map_move[2];
    int steps;
    char *item;
    bool attack;
    bool defense;
    bool inventory;
    bool victory;
    int attack_up;
    int defense_up;
    int enemy_pv;
}protagonist_t;

#endif
