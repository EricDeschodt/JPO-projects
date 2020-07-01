/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** my.h
*/

#ifndef CSFML_MY_H
#define CSFML_MY_H

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct rect_s
{
    sfIntRect dog_stop;
    sfIntRect dog;
    sfIntRect duck;
    sfIntRect menu_dog;
    sfIntRect laugh_dog;
    sfIntRect red_duck;
    sfIntRect ammo_rect;
} rect_t;

typedef struct write_s
{
    char *round_count_text;
    char *score;
    char *top_score;
    sfFont* font;
    sfText* text1;
    sfText* text2;
    sfText* text3;
    sfText* text4;
    sfText* text5;
    sfText* text6;
} write_t;

typedef struct sprite2_s
{
    sfSprite *duck1_2;
    sfSprite *duck2_2;
    sfSprite *duck3_2;
    sfSprite *duck1_fall2;
    sfSprite *duck2_fall2;
    sfSprite *duck3_fall2;
    sfSprite *duck1_rev2;
    sfSprite *duck2_rev2;
    sfSprite *duck3_rev2;
    sfSprite *duck1_bot2;
    sfSprite *duck2_bot2;
    sfSprite *duck3_bot2;
    sfSprite *dead_duck1_2;
    sfSprite *dead_duck2_2;
    sfSprite *dead_duck3_2;
    sfSprite *laugh_dog;
    sfSprite *dog_1duck;
    sfSprite *dog_2duck;
    sfSprite *overlay;
    sfSprite *overlay2;
    sfSprite *ammo;
    sfSprite *perfect_s;
} sprite2_t;

typedef struct sprite_s
{
    sfSprite *duck1;
    sfSprite *duck2;
    sfSprite *duck3;
    sfSprite *duck1_fall;
    sfSprite *duck2_fall;
    sfSprite *duck3_fall;
    sfSprite *duck1_rev;
    sfSprite *duck2_rev;
    sfSprite *duck3_rev;
    sfSprite *duck1_bot;
    sfSprite *duck2_bot;
    sfSprite *duck3_bot;
    sfSprite *dog;
    sfSprite *dog_jump;
    sfSprite *dead_duck1;
    sfSprite *dead_duck2;
    sfSprite *dead_duck3;
    sfSprite *background;
    sfSprite *foreground;
    sfSprite *cursor;
    sfSprite *main_menu;
    sfSprite *menu_arrow;
    sfSprite *menu_dog;
} sprite_t;

typedef struct texture2_s
{
    sfTexture *text_duck1_2;
    sfTexture *text_duck2_2;
    sfTexture *text_duck3_2;
    sfTexture *text_duck1_fall2;
    sfTexture *text_duck2_fall2;
    sfTexture *text_duck3_fall2;
    sfTexture *text_duck1_rev2;
    sfTexture *text_duck2_rev2;
    sfTexture *text_duck3_rev2;
    sfTexture *text_duck1_bot2;
    sfTexture *text_duck2_bot2;
    sfTexture *text_duck3_bot2;
    sfTexture *text_dead_duck1_2;
    sfTexture *text_dead_duck2_2;
    sfTexture *text_dead_duck3_2;
    sfTexture *text_laugh_dog;
    sfTexture *text_dog_1duck;
    sfTexture *text_dog_2duck;
    sfTexture *text_overlay;
    sfTexture *text_overlay2;
    sfTexture *text_ammo;
    sfTexture *text_perfect;
} texture2_t;

typedef struct texture_s
{
    sfTexture *text_duck1;
    sfTexture *text_duck2;
    sfTexture *text_duck3;
    sfTexture *text_duck1_fall;
    sfTexture *text_duck2_fall;
    sfTexture *text_duck3_fall;
    sfTexture *text_duck1_rev;
    sfTexture *text_duck2_rev;
    sfTexture *text_duck3_rev;
    sfTexture *text_duck1_bot;
    sfTexture *text_duck2_bot;
    sfTexture *text_duck3_bot;
    sfTexture *text_dog;
    sfTexture *text_dog_jump;
    sfTexture *text_dead_duck1;
    sfTexture *text_dead_duck2;
    sfTexture *text_dead_duck3;
    sfTexture *text_background;
    sfTexture *text_foreground;
    sfTexture *text_cursor;
    sfTexture *text_main_menu;
    sfTexture *text_menu_arrow;
    sfTexture *text_menu_dog;
} texture_t;

typedef struct pos_s
{
    sfVector2f pos_duck;
    sfVector2f pos_duck_rev;
    sfVector2f pos_duck_bot;
    sfVector2f pos_dog;
    sfVector2f pos_save;
    sfVector2f pos_save_rev;
    sfVector2f pos_save_bot;
    sfVector2f pos_mouse;
    sfVector2f pos_main_menu;
    sfVector2f pos_menu_arrow;
    sfVector2f pos_menu_dog;
    sfVector2f pos_menu_score;
    sfVector2f pos_menu_dog_pause;
    sfVector2f pos_menu_pause_text;
    sfVector2f pos_duck2;
    sfVector2f pos_duck_rev2;
    sfVector2f pos_duck_bot2;
    sfVector2f pos_save2;
    sfVector2f pos_save_rev2;
    sfVector2f pos_save_bot2;
    sfVector2f pos_round_text;
    sfVector2f pos_round_text2;
    sfVector2f pos_overlay;
    sfVector2f pos_round_nb;
    sfVector2f pos_ammo;
    sfVector2f pos_score;
    sfVector2f pos_perfect;
} pos_t;

typedef struct int_s
{
    int x1;
    int x2;
    int count;
    int wait;
    int choice;
    int choice2;
    int check;
    int check2;
    int wing;
    int shoot;
    int shoot2;
    int shoot_check;
    int shoot_check2;
    int intro_check;
    int dog_draw;
    int dog_draw2;
    int dog_draw3;
    int save_choice;
    int save_choice2;
    int rand_check;
    int rand_check2;
    int main_menu;
    int state;
    int gun_clock;
    int menu_dog;
    int menu_check;
    int spawn_count;
    int duck_shoot;
    int duck_spawn1;
    int duck_spawn2;
    int laugh_dog_top;
    int dog_clock;
    int dog_clock2;
    int dog_sound;
    int round_check;
    int clock_restart;
    int clock_round;
    int new_round_clock;
    int end_round;
    int game_mode;
    int shoot_total;
    int round_count;
    int ammo_left;
    int score_int;
    int perfect;
    int begin;
} int_t;

typedef struct sound_s
{
    sfSoundBuffer *buff_shoot;
    sfSoundBuffer *buff_fall;
    sfSoundBuffer *buff_fall2;
    sfSoundBuffer *buff_wing;
    sfSoundBuffer *buff_intro;
    sfSoundBuffer *buff_menu;
    sfSoundBuffer *buff_menu_select;
    sfSoundBuffer *buff_laugh_dog;
    sfSoundBuffer *buff_success;
    sfSoundBuffer *buff_round;
    sfSoundBuffer *buff_select;
    sfSound *shoot;
    sfSound *fall;
    sfSound *fall2;
    sfSound *wing;
    sfSound *intro;
    sfSound *menu;
    sfSound *menu_select;
    sfSound *laugh_dog;
    sfSound *success;
    sfSound *round;
    sfSound *select;
} sound_t;

typedef struct my_clock_s
{
    sfClock *clock0_1s;
    sfTime time0_1s;
    float seconds0_1s;
    sfClock *clock_dead;
    sfTime time_dead;
    float seconds_dead;
    sfClock *clock_dead2;
    sfTime time_dead2;
    float seconds_dead2;
    sfClock *clock_dog;
    sfTime time_dog;
    float seconds_dog;
    sfClock *clock_dog_jump;
    sfTime time_dog_jump;
    float seconds_dog_jump;
    sfClock *clock_dog_jump2;
    sfTime time_dog_jump2;
    float seconds_dog_jump2;
} my_clock_t;

typedef struct all_s
{
    my_clock_t clock;
    sound_t sound;
    texture_t texture;
    texture2_t texture2;
    sprite_t sprite;
    sprite2_t sprite2;
    rect_t rect;
    pos_t pos;
    int_t my_int;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    write_t write;
    sfColor green_menu;
    sfColor overlay_green;
    sfVector2i mouse_position;
} all_t;

void duck_animation_dead(all_t *all);
void analyse_events(sfEvent event, all_t *all);
void main_if_clock(all_t *all, sfEvent event);
void regroup_if_choice(all_t *all, sfEvent event);
void draw_sprite(sfEvent event, all_t *all);
void int_init(int_t *my_int);
void first_init_dog_duck(pos_t *pos);
all_t init_regroup(all_t *all);
void sprite_init(sprite_t *sprite);
void sound_init(sound_t *sound);
void texture_init(texture_t *texture);
void set_texture(sprite_t *sprite, texture_t *texture);
sfIntRect move_dog(sfIntRect rect);
sfIntRect move_duck(sfIntRect rect);
sfIntRect move_dog_stop(sfIntRect rect);
void rect_init(rect_t *rect);
void dog_walking(all_t *all);
void draw_cursor(all_t *all);
void destroy_regroup(all_t *all);
void duck_animation(all_t *all);
void clock_init(my_clock_t *clock);
void setup(all_t *all);
void clock_set(all_t *all);
void texture_init2(texture_t *texture);
void if_choice_is_3_rev(all_t *all, sfEvent event);
void if_choice_is_4_rev(all_t *all, sfEvent event);
void if_choice_is_5_rev(all_t *all, sfEvent event);
void if_choice_is_6_bot(all_t *all, sfEvent event);
void if_choice_is_7_bot(all_t *all, sfEvent event);
void if_choice_is_8_bot(all_t *all, sfEvent event);
void dog_jump2(all_t *all);
void dog_jump(all_t *all);
sfIntRect move_menu_dog(sfIntRect rect);
void main_pause(all_t *all, sfEvent event);
void if_choice_is_3_rev_2(all_t *all, sfEvent event);
void if_choice_is_4_rev_2(all_t *all, sfEvent event);
void if_choice_is_5_rev_2(all_t *all, sfEvent event);
void if_choice_is_0_2(all_t *all, sfEvent event);
void if_choice_is_1_2(all_t *all, sfEvent event);
void if_choice_is_2_2(all_t *all, sfEvent event);
void if_choice_is_6_bot_2(all_t *all, sfEvent event);
void if_choice_is_7_bot_2(all_t *all, sfEvent event);
void if_choice_is_8_bot_2(all_t *all, sfEvent event);
void set_texture3(sprite2_t *sprite2, texture2_t *texture2);
void set_texture2(sprite_t *sprite, texture_t *texture, sprite2_t *sprite2,
                    texture2_t *texure2);
void sprite_init2(sprite_t *sprite, sprite2_t *sprite2);
void texture_init4(texture2_t *texture2);
void texture_init3(texture_t *texture, texture2_t *texture2);
void if_duck2(all_t *all);
void if_duck_rev2(all_t *all);
void if_duck_bot2(all_t *all);
void duck_animation_dead3(all_t *all);
sfIntRect move_laugh_dog(sfIntRect rect);
void pause_start(all_t *all);
void dog_laugh(all_t *all, sfEvent event);
void if_duck(all_t *all);
void if_duck_rev(all_t *all);
void if_duck_bot(all_t *all);
void sprite_init3(sprite2_t *sprite2);
void dog_1duck(all_t *all, sfEvent event);
void dog_laugh_reset_duck(all_t *all);
void dog_2duck(all_t *all, sfEvent event);
void dog_spawn(all_t *all, sfEvent event);
void dog_reset(all_t *all);
void count_event1(all_t *all);
void count_event2(all_t *all);
void dog_walking_round(all_t *all);
void dog_count_wait(all_t *all);
void if_dead0_1(all_t *all);
void if_dead2_1(all_t *all);
void if_dead2_1_2(all_t *all);
void if_dead7_8(all_t *all);
void if_dead7_8_2(all_t *all);
void if_dead3_4(all_t *all);
void if_dead3_4_2(all_t *all);
void if_dead5(all_t *all);
void main_new_round(all_t *all, sfEvent event);
void main_walking(all_t *all, sfEvent event);
void draw_sprite_new_round(all_t *all, sfEvent event);
all_t init_regroup_round(all_t *all);
void main_render_game(sfEvent event);
void main_menu(sfEvent event, all_t *all);
void main_game(sfEvent event, all_t *all);
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
void manual(void);
void dog_spawn2(all_t *all, sfEvent event);
void duck_overlap(all_t *all);
char *my_put_nbr(int nb, char *str);
char *my_revstr(char *str);
void texture_init5(texture2_t *texture2);
void main_init(all_t *all);
void main_init2(all_t *all);
all_t init_game_over(all_t *all);
char *open_read(void);
void open_write(char *str);
int my_atoi(char const *str);

#endif