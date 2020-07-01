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
    sfIntRect rect_michael;
    sfIntRect rect_jump;
    sfIntRect rect_hit;
    sfIntRect rect_crouch_hit;
    sfIntRect rect_up_throw;
    sfIntRect rect_down_throw;
} rect_t;

typedef struct write_s
{
    char *score;
    char *skull;
    char *top_score;
    sfFont* font;
    sfText* text;
    sfText* skull_txt;
    sfText* score_txt;
    sfText* game_over;
    sfText* victory;
} write_t;

typedef struct background2_s
{
    sfSprite *background2_1;
    sfSprite *background2_1_2;
    sfSprite *background2_2;
    sfSprite *background2_3;
    sfSprite *background2_4;
    sfSprite *background2_5;
} background2_t;

typedef struct background_s
{
    sfSprite *background1;
    sfSprite *background1_2;
    sfSprite *background2;
    sfSprite *background3;
    sfSprite *background4;
    sfSprite *background5;
    sfSprite *background6;
    sfSprite *background7;
} background_t;

typedef struct background_text_s
{
    sfTexture *background_text1;
    sfTexture *background_text1_2;
    sfTexture *background_text2;
    sfTexture *background_text3;
    sfTexture *background_text4;
    sfTexture *background_text5;
    sfTexture *background_text6;
    sfTexture *background_text7;
} background_text_t;

typedef struct sprite_s
{
    sfSprite *michael;
    sfSprite *jump;
    sfSprite *crouch;
    sfSprite *hit;
    sfSprite *crouch_hit;
    sfSprite *up_throw;
    sfSprite *down_throw;
    sfSprite *hat;
} sprite_t;

typedef struct texture_s
{
    sfTexture *text_michael;
    sfTexture *text_jump;
    sfTexture *text_crouch;
    sfTexture *text_hit;
    sfTexture *text_crouch_hit;
    sfTexture *text_up_throw;
    sfTexture *text_down_throw;
    sfTexture *text_hat;
    sfTexture *text_fat_zombie;
    sfTexture *text_flying_zombie;
    sfTexture *text_traps;
    sfTexture *text_skull;
} texture_t;

typedef struct background_pos_s
{
    sfVector2f pos_layer1;
    sfVector2f pos_layer1_2;
    sfVector2f pos_layer2;
    sfVector2f pos_layer3;
    sfVector2f pos_layer4;
    sfVector2f pos_layer5;
    sfVector2f pos2_layer1;
    sfVector2f pos2_layer1_2;
    sfVector2f pos2_layer2;
    sfVector2f pos2_layer3;
    sfVector2f pos2_layer4;
    sfVector2f pos2_layer5;
} background_pos_t;

typedef struct pos_s
{
    sfVector2f pos_michael;
    sfVector2f pos_crouch;
    sfVector2f pos_hat;
} pos_t;

typedef struct int_s
{
    int i;
    int plan;
    int jump;
    int energy;
    int high;
    int gravity[8];
    int index;
    int jump_sound;
    int jump_count;
    int crouch;
    int hit;
    int hit_time;
    int hit_check;
    int hit_crouch;
    int up_throw;
    int down_throw;
    int hat;
    int speed;
    int check_throw;
    int rect_flying;
    int reset;
    int alpha;
    int day;
    int ia;
    int menu;
    int reset_menu;
    int level;
    int skull;
    int score;
} int_t;

typedef struct sound_s
{
    sfSoundBuffer *buff_heehee;
    sfSound *heehee;
    sfSoundBuffer *buff_whosbad;
    sfSound *whosbad;
    sfSoundBuffer *buff_thriller;
    sfSound *thriller;
    sfSoundBuffer *buff_da;
    sfSound *da;
    sfSoundBuffer *buff_ouw;
    sfSound *ouw;
    sfSoundBuffer *buff_shamone;
    sfSound *shamone;
    sfSoundBuffer *buff_skull;
    sfSound *skull;
    sfSoundBuffer *buff_jab;
    sfSound *jab;
    sfSoundBuffer *buff_upper_cut;
    sfSound *upper_cut;
    sfSoundBuffer *buff_left_hook;
    sfSound *left_hook;
    sfSoundBuffer *buff_right_hook;
    sfSound *right_hook;
    sfSoundBuffer *buff_right_cross;
    sfSound *right_cross;
    sfSoundBuffer *buff_scream;
    sfSound *scream;
} sound_t;

typedef struct my_clock_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *clock_michael;
    sfTime time_michael;
    float seconds_michael;
    sfClock *clock_jump;
    sfTime time_jump;
    float seconds_jump;
    sfClock *clock_hit;
    sfTime time_hit;
    float seconds_hit;
    sfClock *clock_crouch;
    sfTime time_crouch;
    float seconds_crouch;
    sfClock *clock_fat;
    sfTime time_fat;
    float seconds_fat;
    sfClock *clock_flying;
    sfTime time_flying;
    float seconds_flying;
    sfClock *clock_flying_dead;
    sfTime time_flying_dead;
    float seconds_flying_dead;
    sfClock *clock_fat_dead;
    sfTime time_fat_dead;
    float seconds_fat_dead;
    sfClock *clock_skull;
    sfTime time_skull;
    float seconds_skull;
    sfClock *clock_total;
    sfTime time_total;
    float seconds_total;
    sfClock *clock_cycle;
    sfTime time_cycle;
    float seconds_cycle;
} my_clock_t;

typedef struct fat_zombie1_s
{
    sfSprite *sprite;
    sfVector2f pos_fat;
    sfVector2f scale_fat;
    sfVector2f origin_fat;
    sfIntRect rect_fat;
    float float_fat;
} fat_zombie1_t;

typedef struct flying_zombie_s
{
    sfSprite *sprite;
    sfVector2f pos_flying;
    sfIntRect rect_flying;
    sfColor color;
    int alpha;
} flying_zombie_t;

typedef struct traps_s
{
    sfSprite *sprite;
    sfVector2f pos_traps;
    sfVector2f scale_traps;
    sfVector2f origin_traps;
    sfIntRect rect_traps;
    float float_traps;
    float rotate;
} traps_t;

typedef struct dlist_node_s
{
    fat_zombie1_t fat;
    flying_zombie_t flying;
    traps_t traps;
    int who;
    int dead;
    struct dlist_node_s *back;
    struct dlist_node_s *next;
} dlist_node_t, node_t;

typedef struct dlist_s
{
    int length;
    struct dlist_node_s *begin;
    struct dlist_node_s *end;
} dlist_t;

typedef struct sp_button_s
{
    sfSprite *play;
    sfSprite *restart;
    sfSprite *menu;
    sfSprite *quit;
    sfSprite *levels;
    sfSprite *ia;
    sfSprite *level1;
    sfSprite *level2;
    sfSprite *level3;
    sfSprite *your;
    sfSprite *back;
} sp_button_t;

typedef struct tx_button_s
{
    sfTexture *play;
    sfTexture *restart;
    sfTexture *menu;
    sfTexture *quit;
    sfTexture *levels;
    sfTexture *ia_on;
    sfTexture *ia_off;
    sfTexture *level1;
    sfTexture *level2;
    sfTexture *level3;
    sfTexture *your;
    sfTexture *back;
    sfTexture *play_w;
    sfTexture *restart_w;
    sfTexture *menu_w;
    sfTexture *quit_w;
    sfTexture *levels_w;
    sfTexture *ia_on_w;
    sfTexture *ia_off_w;
    sfTexture *level1_w;
    sfTexture *level2_w;
    sfTexture *level3_w;
    sfTexture *your_w;
    sfTexture *back_w;
} tx_button_t;

typedef struct pos_menu_s
{
    sfVector2f levels;
    sfVector2f ia;
    sfVector2f quit;
    sfVector2f level1;
    sfVector2f back;
} pos_menu_t;

typedef struct all_s
{
    sp_button_t sp_button;
    tx_button_t tx_button;
    pos_menu_t pos_menu;
    my_clock_t clock;
    sound_t sound;
    texture_t texture;
    sprite_t sprite;
    background_text_t background_text;
    background_t background;
    background2_t background2;
    background_pos_t background_pos;
    rect_t rect;
    pos_t pos;
    int_t my_int;
    write_t write;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    dlist_t *mobs;
    sfMusic *music;
    sfRectangleShape *rectangle;
    sfColor color;

} all_t;

void set_texture(sprite_t *sprite, texture_t *texture);
void sprite_init(sprite_t *sprite);
void texture_init(texture_t *texture);
void set_sprite_background(background_t *sprite, background_text_t *texture,
    background2_t *sprite2);
void background_sprite_init(background_t *sprite, background2_t *sprite2);
void background_texture_init(background_text_t *texture);
void background_regroup(all_t *all);
all_t init_regroup(all_t *all);
void my_putchar(char c);
int my_putstr(char const *str);
void setup(all_t *all);
void draw_background(all_t *all);
void analyse_events(sfEvent event, all_t *all);
void init_pos_background(background_pos_t *pos);
void clock_init(my_clock_t *clock);
void clock_set(all_t *all);
void parallax_pos(all_t *all);
void parallax_set(all_t *all);
void sprite_regroup(sprite_t *sprite, texture_t *texture);
void rect_init(rect_t *rect);
void init_pos(pos_t *pos);
void int_init(int_t *my_int);
void michael_jump(all_t *all);
void michael_moonwalk(all_t *all);
void sound_init(sound_t *sound);
void destroy_regroup(all_t *all);
void michael_hit(all_t *all);
int my_strlen(char const *str);
void manual(void);
void michael_hit_crouch(all_t *all);
void michael_up_throw(all_t *all);
void michael_jump_set(all_t *all);
void michael_down_throw(all_t *all);
void zombies_move(all_t *all, dlist_node_t *mobs);
void fat_walk_anim(all_t *all, dlist_node_t *mobs);
dlist_t *new_list(void);
int is_empty_list(dlist_t *li);
dlist_node_t *new_node_fat1(all_t *all, int pos);
dlist_t *push_back_fat1(all_t *all, dlist_t *li, int pos);
dlist_t *push_back_flying(all_t *all, dlist_t *li, int pos);
dlist_t *pop_front_list(dlist_t *li);
dlist_t *pop_back_list(dlist_t *li);
dlist_t *clear_list(dlist_t *li);
void hat_fat_hit_box(all_t *all, dlist_node_t *tmp);
dlist_t *pop_anywhere(dlist_t *li, dlist_node_t *tmp_save);
void list_fat_zombie1(all_t *all, char *map);
void list_move_zombie(all_t *all);
void draw_list_zombie(all_t *all);
dlist_node_t *new_node_flying(all_t *all, int pos);
void flying_walk_anim(all_t *all, dlist_node_t *mobs);
void night_day_cycle(all_t *all);
void hat_flying_hit_box(all_t *all, dlist_node_t *tmp);
void hat_flying2_hit_box(all_t *all, dlist_node_t *tmp);
void crouch_fat_hit_box(all_t *all, dlist_node_t *tmp);
dlist_node_t *new_node_traps_base(all_t *all, int pos);
dlist_t *push_back_traps_base(all_t *all, dlist_t *li, int pos);
dlist_t *push_back_traps_axe1(all_t *all, dlist_t *li, int pos);
dlist_node_t *new_node_traps_axe1(all_t *all, int pos);
dlist_node_t *new_node_traps_balls(all_t *all, int pos);
dlist_t *push_back_traps_balls(all_t *all, dlist_t *li, int pos);
dlist_t *push_back_traps_saw(all_t *all, dlist_t *li, int pos);
dlist_t *push_back_traps_axe2(all_t *all, dlist_t *li, int pos);
dlist_t *push_back_sign(all_t *all, dlist_t *li, int pos);
dlist_node_t *new_node_iron_spikes(all_t *all, int pos);
dlist_t *push_back_iron_spikes(all_t *all, dlist_t *li, int pos);
char *load_file_in_mem(char *filepath);
int count_entities(char *map);
int pos_entities_bis(char *map, int nb, int pos);
int pos_entities(char *map, int nb, int pos);
int who_entities(char *map, int nb);
void hit_flying_hit_box(all_t *all, dlist_node_t *tmp);
void michael_fat_hit_box(all_t *all, dlist_node_t *tmp);
void michael_flying_hit_box(all_t *all, dlist_node_t *tmp);
void michael_flying_hit_box2(all_t *all, dlist_node_t *tmp);
void michael_axe1_hit_box(all_t *all, dlist_node_t *tmp);
void michael_axe1_hit_box_jump(all_t *all, dlist_node_t *tmp, float rotate);
void michael_spikes_hit_box(all_t *all, dlist_node_t *tmp);
void michael_saw_hit_box(all_t *all, dlist_node_t *tmp);
void michael_balls_hit_box2(all_t *all, dlist_node_t *tmp, float rotate);
void michael_balls_hit_box(all_t *all, dlist_node_t *tmp);
void michael_axe2_hit_box2(all_t *all, dlist_node_t *tmp, float rotate);
void michael_axe2_hit_box(all_t *all, dlist_node_t *tmp);
void auto_hit(all_t *all);
void sound_random(all_t *all);
void auto_hit4(all_t *all, dlist_node_t *tmp);
dlist_node_t *new_node_skull(all_t *all, int pos);
dlist_node_t *new_node_skull_down(all_t *all, int pos);
dlist_t *push_back_skull(all_t *all, dlist_t *li, int pos, int who);
void skull_hit_box(all_t *all, dlist_node_t *tmp);
void punches_sounds_random(all_t *all);
void list_move_zombie_inside(all_t *all, dlist_node_t *tmp);
void list_fat_zombie1_bis(all_t *all, int pos, int j);
void init_button(all_t *all);
void draw_menu_1(all_t *all);
void init_pos_menu(pos_menu_t *pos_menu);
void menu_events(sfEvent event, all_t *all);
void night_day_cycle(all_t *all);
void draw_menu_1(all_t *all);
void hitbox_menu_1_bis(all_t *all, sfVector2i mouse_pos);
void hitbox_menu_1(all_t *all);
void reset_menu(all_t *all);
void set_pos_button(pos_menu_t *pos_menu, sp_button_t *sp_button);
void hitbox_menu_2(all_t *all);
void hitbox_menu_3(all_t *all);
int list_end_map(all_t *all);
char *open_read(void);
void open_write(char *str);
void write_init(all_t *all);
char *my_put_nbr(int nb, char *str);
char *my_revstr(char *str);
dlist_node_t *new_node_menu_skull(all_t *all);
int load_map(all_t *all, char *argv);
void menu_display2(all_t *all);
int my_atoi(char const *str);
void print_top_score(all_t *all);
void hit_box_stat(all_t *all);

#endif
