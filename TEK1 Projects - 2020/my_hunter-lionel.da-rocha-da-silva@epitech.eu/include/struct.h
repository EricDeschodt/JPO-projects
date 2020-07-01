/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#ifndef _STRUCT_
#define _STRUCT_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>
#include <stdlib.h>

typedef struct image
{
    sfTexture *texture;
    sfSprite *sprite;
} s_disp;

typedef struct mouse
{
    float x;
    float y;
} s_mouse;

typedef struct background
{
    s_disp back;
} s_back;

typedef struct shoot
{
    s_mouse mouse;
    sfFloatRect hitbox;
} s_shoot;

typedef struct animation
{
    s_disp duck;
    float x;
    float y;
    sfClock *clock;
    sfClock *clock_move;
    sfTime time;
    float seconds;
    sfIntRect frame;
    sfTime time_move;
    float seconds_fly;
    sfFloatRect hitbox;
    s_shoot hit;
} s_animation;

typedef struct dead_duck
{
    s_disp dead_duck;
    float deadx;
    float deady;
    sfClock *dead_clock;
    sfTime dead_time;
} s_dead;

typedef struct text
{
    sfFont *font;
    sfText *text;
    sfText *score;
    char *number;
    s_mouse pos;
    sfText *gameover;
    sfText *play_text;
    sfText *exit;
    sfText *restart;
    sfText *best_score;
    sfText *best_number;
} s_text;

typedef struct crosshair
{
    s_disp cross;
    s_mouse pos;
} s_cross;


typedef struct life
{
    s_disp life;
    sfIntRect heart;
    int lives;
    int state;
} s_life;

typedef struct display
{
    sfEvent event;
    s_disp back;
    s_animation duck;
    s_animation duck_rev;
    s_animation dog;
    s_animation dog_rev;
    s_dead dead;
    s_text text;
    s_cross cross;
    sfMusic *sound;
    s_life life;
    int func;
    int dog_state;
    float level;
    char const *filepath;
    char *str;
    int score_size;
} s_show;

#endif
