/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "time.h"

typedef struct map {
    char *map;
    int nb_monster;
    int monster_pos;
    int nb_coins;
    int coin_pos;
} map_t;

typedef struct texts {
    sfFont *font;
} texts_t;

typedef struct runner {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfClock *jump_cl;
    sfTime time;
    sfTime time_air;
    sfIntRect rect;
    float secconds;
    float jump_sec;
    sfVector2f pos;
    int jump;
    int fall;
    int inercy;
} runner_t;

typedef struct dead {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    float seconds;
    sfVector2f pos;
} dead_t;

typedef struct win {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    float seconds;
    sfVector2f pos;
} win_t;

typedef struct jelly {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    float secconds;
    sfVector2f pos;
} jelly_t;

typedef struct title {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} title_t;

typedef struct monster1 {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float secconds;
    sfVector2f pos;
    sfIntRect rect;
    int id;
    struct monster1 *next;
} monster1_t;

typedef struct obstacle {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    struct obstacle *next;
} obstacle_t;

typedef struct coin {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float secconds;
    sfVector2f pos;
    sfIntRect rect;
    int id;
    struct coin *next;
} coin_t;

typedef struct buttons {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture_on;
    sfVector2f pos;
    int id;
    struct buttons *next;
} buttons_t;

typedef struct music {
    sfMusic *background_sound;
    sfSound *jump_sound;
    sfSoundBuffer *buff_jump;
    sfSound *slide_sound;
    sfSoundBuffer *buff_slide;
    sfSound *coin_sound;
    sfSoundBuffer *buff_coin;
} music_t;

typedef struct jump {
    sfSprite *sprite_j;
    sfTexture *texture_j;
    sfSprite *sprite_f;
    sfTexture *texture_f;
} jump_t;

typedef struct stopped {
    sfSprite *sprite;
    sfTexture *texture;
} stopped_t;

typedef struct slide {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    float secconds;
    sfVector2f pos;
    int slide;
} slide_t;

typedef struct background {
    sfSprite *layer1;
    sfSprite *layer1_bis;
    sfSprite *layer2;
    sfSprite *layer2_bis;
    sfSprite *layer3;
    sfSprite *layer3_bis;
    sfSprite *layer4;
    sfSprite *layer4_bis;
    sfSprite *layer5;
    sfSprite *layer5_bis;
    sfSprite *layer6;
    sfSprite *layer6_bis;
    sfSprite *layer7;
    sfSprite *layer8;
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture4;
    sfTexture *texture5;
    sfTexture *texture6;
    sfTexture *texture7;
    sfTexture *texture8;
    sfVector2f pos1;
    sfVector2f pos1_bis;
    sfVector2f pos2;
    sfVector2f pos2_bis;
    sfVector2f pos3;
    sfVector2f pos3_bis;
    sfVector2f pos4;
    sfVector2f pos4_bis;
    sfVector2f pos5;
    sfVector2f pos5_bis;
    sfVector2f pos6;
    sfVector2f pos6_bis;
    sfVector2f pos7;
    sfVector2f pos8;
    sfClock *clock;
    sfTime time;
    float secconds;
} background_t;

typedef struct state {
    float mouse_posx;
    float mouse_posy;
    int score;
    char *strscore;
    int lose;
} state_t;

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    int scene;
    int speed;
    int infinite;
} game_t;

typedef struct end_lvl {
    sfText *lose;
    sfText *win;
    sfText *score;
    sfText *your_score;
    int score_int;
    char *strscore;
} end_lvl_t;

typedef struct interface {
    coin_t s_coin;
    end_lvl_t end;
    sfClock *clock;
    sfTime time;
    sfText *coin_mult;
    sfText *nb_coin;
    sfText *best;
    sfText *your_best;
    sfText *distance;
    sfText *nb_dist;
    int distance_int;
    int nb_coin_int;
    int best_int;
    float seconds;
    char *strdistance;
    char *strcoin;
    char *strbest;
} interface_t;

typedef struct controll {
    char *current_map;
    char *arg_map;
    sfFont *font;
    state_t s_state;
    game_t s_game;
    texts_t s_texts;
    runner_t s_runner;
    dead_t s_dead;
    win_t s_win;
    jelly_t s_jelly;
    background_t s_background;
    jump_t s_jump;
    stopped_t s_stopped;
    slide_t s_slide;
    music_t s_music;
    title_t s_title;
    map_t s_map;
    interface_t s_interface;
    struct coin *s_coin;
    struct monster1 *s_monster;
    struct buttons *s_button;
    struct buttons *s_pause;
    struct buttons *s_levels;
    struct obstacle *s_obstacle;
    int nb_coins;
    int nb_monsters;
} controll_t;

int my_strlen(char *str);
char *my_revstr(char *str);
char *my_put_strnbr(int n);

int game_loop(controll_t *s_controll);
int message(void);
void restart_button(buttons_t *s_button, controll_t *s_controll);
void pause_game(controll_t *s_controll);
int is_button(buttons_t *s_button, controll_t *s_controll);

void event_controll(controll_t *s_controll);
void jump_slide(controll_t *s_controll);
void animation(controll_t *s_controll);
void jump(controll_t *s_controll);
void fall(controll_t *s_controll);
void slide(controll_t *s_controll);
void check_infinite(buttons_t *s_button, controll_t *s_controll);

void render_texts(controll_t *s_controll);
void render_sprites(controll_t *scontroll, char *filepath);
void render_sounds(controll_t *s_controll);
void render_all(controll_t *scontroll);
void render_menu(controll_t *s_controll);
int render_runner(controll_t *s_controll);
void render_title(controll_t *s_controll);
void render_background(controll_t *scontroll);
int render_layer1(controll_t *s_controll);
int render_layer1_bis(controll_t *s_controll);
int render_layer2(controll_t *s_controll);
int render_layer2_bis(controll_t *s_controll);
int render_layer3(controll_t *s_controll);
int render_layer3_bis(controll_t *s_controll);
int render_layer4(controll_t *s_controll);
int render_layer4_bis(controll_t *s_controll);
int render_layer5(controll_t *s_controll);
int render_layer5_bis(controll_t *s_controll);
int render_layer6(controll_t *s_controll);
int render_layer6_bis(controll_t *s_controll);
int render_layer7(controll_t *s_controll);
int render_layer8(controll_t *s_controll);
void render_jump(controll_t *s_controll);
int render_slide(controll_t *s_controll);
int render_up(controll_t *s_controll);
int render_down(controll_t *s_controll);
int render_jelly(controll_t *s_controll);
int render_stopped(controll_t *s_controll);
int render_dead(controll_t *s_controll);
int render_win(controll_t *s_controll);
monster1_t *render_monster(monster1_t *s_monster, int height, int posx);
void free_monster(monster1_t *s_monster, controll_t *s_controll);
buttons_t *render_buttons(buttons_t *s_button, char const *filepath,
                            sfVector2f pos, int id);
void init_buttons(controll_t *s_controll);

void move_rect_runner(controll_t *s_controll, int offset, int max_value);
void move_rect_slide(controll_t *s_controll, int offset, int max_value);
void move_rect_coin(coin_t *s_coin, int offset, int max_value);
void move_rect_jelly(controll_t *s_controll, int offset, int max_value);
void move_rect_monster(monster1_t *s_monster, int offset, int max_value);
void move_rect_dead(controll_t *s_controll, int offset, int max_value);
void move_rect_win(controll_t *s_controll, int offset, int max_value);
void move_layers(controll_t *s_controll);
void move_layer_1(controll_t *s_controll);
void move_layer_2(controll_t *s_controll);
void move_layer_3(controll_t *s_controll);
void move_layer_4(controll_t *s_controll);
void move_layer_5(controll_t *s_controll);
void move_layer_6(controll_t *s_controll);
monster1_t *move_monster(controll_t *s_controll, monster1_t *s_monster);

void layers_display1(controll_t *s_controll);
void layers_display2(controll_t *s_controll);
void layers_setpos1(controll_t *s_controll);
void layers_setpos2(controll_t *s_controll);

void game_scene(controll_t *s_controll);
void display_runner(controll_t *s_controll);
void display_background(controll_t *s_controll);
void setpos_background(controll_t *s_controll);
void display_jelly(controll_t *s_controll);
void display_buttons(controll_t *s_controll);
void draw_runner(controll_t *s_controll);
void display_monster(controll_t *s_controll);
monster1_t *draw_monster(controll_t *s_controll, monster1_t *s_monster);
void background_setposition(controll_t *s_controll);
void display_stopped(controll_t *s_controll);
void display_dead(controll_t *s_controll);
void display_win(controll_t *s_controll);

void destroy_background(controll_t *s_controll);
void destroy_next(controll_t *s_controll);
void destroy_coin(coin_t *s_coin);
void destroy_monster(monster1_t *s_monster);
void destroy_level(controll_t *s_controll);
void *end_game(controll_t *s_controll);
void init_clocks(controll_t *s_controll);
void init_clocks2(controll_t *s_controll);
void init_clocks3(controll_t *s_controll);
void init_coin_clocks(controll_t *s_controll);
void init_monster_clock(controll_t *s_controll);
void init_monster(controll_t *s_controll);
void game(controll_t *s_controll);

int background_sound(controll_t *s_controll);
int jump_sound(controll_t *s_controll);
int slide_sound(controll_t *s_controll);

void init_coin(controll_t *s_controll);
coin_t *render_coin(coin_t *s_coin, int id, int posx);
coin_t *draw_coin(controll_t *s_controll, coin_t *s_coin);
void display_coins(controll_t *s_controll);
coin_t *move_coins(controll_t *s_controll, coin_t *s_coin);
void free_coin(coin_t *s_coin, controll_t *s_controll);
int coin_sound(controll_t *s_controll);

coin_t *check_coin_hitbox(coin_t *s_coin, controll_t *s_controll);
void touch_coin(controll_t *s_controll);
coin_t *remove_coin(controll_t *s_controll, coin_t *s_coin);

void check_play(buttons_t *s_button, controll_t *s_controll);
void button_hitbox(controll_t *s_controll);
monster1_t *check_monster_hitbox(monster1_t *s_monster,
                                    controll_t *s_controll);
void touch_monster(controll_t *s_controll);


obstacle_t *render_obstacle(obstacle_t *s_obstacle, int height, int posx);
void display_obstacle(controll_t *s_controll);
obstacle_t *move_obstacle(controll_t *s_controll, obstacle_t *s_obstacle);
void free_obstacle(obstacle_t *s_obstacle, controll_t *s_controll);
void destroy_obstacle(obstacle_t *s_obstacle);
obstacle_t *draw_obstacle(controll_t *s_controll, obstacle_t *s_obstacle);
void touch_obstacle(controll_t *s_controll);
obstacle_t *check_obstacle_hitbox(obstacle_t *s_obstacle,
                                    controll_t *s_controll);

void free_coins(controll_t *s_controll);
void free_obstacles(controll_t *s_controll);
void free_monsters(controll_t *s_controll);
void free_map(controll_t *s_controll);
void free_buttons(controll_t *s_controll);

void init_pause(controll_t *s_controll);
void display_pause(controll_t *s_controll);
void check_on_button(controll_t *s_controll);
void hover_check(buttons_t *s_button, controll_t *s_controll);
void init_levels(controll_t *s_controll);
void display_levels(controll_t *s_controll);
void check_levels(buttons_t *s_button, controll_t *s_controll);

void render_interface(controll_t *s_controll);
void render_nbcoins_txt(controll_t *s_controll);
void render_coin_interface(controll_t *s_controll);
void render_nbcoins_int(controll_t *s_controll);
void render_distace_int(controll_t *s_controll);
void render_ditance_txt(controll_t *s_controll);
void display_coin_interface(controll_t *s_controll);
void display_end_txts(controll_t *s_controll);
void render_final_score_txt(controll_t *s_controll);
void render_final_score_int(controll_t *s_controll);
void end_txt_lose_gameover(controll_t *s_controll);
void display_texts(controll_t *s_controll);
void destroy_interface(controll_t *s_controll);
void destroy_buttons(buttons_t *s_button);
void free_previous_txt(char *str);
buttons_t *get_last_node(buttons_t *s_button);
void render_win_txt(controll_t *s_controll);
void show_win(controll_t *s_controll);
void winning_check(controll_t *s_controll);
int get_score(void);
void write_score(controll_t *s_controll);
void render_best_txt(controll_t *s_controll);
void render_best_int(controll_t *s_controll);
void set_final_score(controll_t *s_controll);

#endif