/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "time.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif

typedef struct game {
    sfRenderWindow *window;
    sfShader *shader;
    sfRenderStates state;
    sfEvent event;
    int scene;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfTexture *locked;
    sfColor clear_color;
    int pause, eric;
    int mob_nb;
    sfRenderTexture *render;
    int lost_anim;
    int transition;
    sfClock *anim_clock;
    sfTime anim_time;
    float anim_seconds;
} game_t;

typedef struct menu {
    sfSprite *sp_background;
    sfTexture *tx_background;
    sfMusic *main_theme;
    sfRectangleShape *line;
    sfSprite *about;
    sfTexture *about_tx;
    sfSprite *settings;
    sfTexture *settings_tx;
    sfSprite *statistics;
    sfTexture *statistics_tx;
    sfSprite *handbook;
    sfTexture *handbook_tx;
    sfSprite *lost;
    sfTexture *lost_tx;
} menu_t;

typedef struct statistics
{
    int coins;
    int killed;
    int passed;
    int defeated;
    int score;
    int built;
    int sold;
    int started;
    sfText *coins_tx;
    sfText *killed_tx;
    sfText *passed_tx;
    sfText *defeated_tx;
    sfText *score_tx;
    sfText *built_tx;
    sfText *sold_tx;
    sfText *started_tx;
} statistics_t;

typedef struct sounds
{
    sfSoundBuffer *buff_button;
    sfSound *button;
    sfSoundBuffer *buff_build;
    sfSound *build;
    sfSoundBuffer *buff_upgrade;
    sfSound *upgrade;
    sfSoundBuffer *buff_sell;
    sfSound *sell;
    sfSoundBuffer *buff_reached;
    sfSound *reached;
    sfSoundBuffer *buff_ability;
    sfSound *ability;
    sfSoundBuffer *buff_defeat;
    sfSound *defeat;
} sounds_t;

typedef struct targetting {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f text_pos;
    int big;
    int show;
    sfText *str;
    sfFont *font;
    struct targetting *next;
    struct targetting *back;
} targetting_t;

typedef struct list_targetting {
    int length;
    int size;
    sfClock *clock;
    sfTime time;
    float seconds;
    targetting_t *begin;
    targetting_t *end;
} list_targetting_t;

typedef struct spawning {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *clock2;
    sfTime time2;
    float seconds2;
} spawning_t;

typedef struct tuto {
    sfSprite *sprite;
    sfCircleShape *light;
    sfClock *clock, *clock2;
    sfTime time, time2;
    sfTexture *texture;
    sfVector2f pos, scale;
    sfSprite *snow;
    sfTexture *snow_text;
    sfShader *shader;
    sfRenderStates states;
    char previous;
    int state, life, id, direction, nb;
    sfRectangleShape *life_bar;
    sfRectangleShape *black;
    float seconds, move, increment, speed, save_speed, slow;
    float seconds2;
    int map_pos, castle, check;
    struct tuto *next;
} tuto_t;

typedef struct support {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_base;
    sfTexture *texture_base;
    sfVector2f base_pos;
    sfVector2f pos;
    char type;
    int on;
    struct support *placed;
    struct support *next;
} support_t;

typedef struct t_select {
    sfSprite *sprite;
    sfSprite *sprite_a;
    sfTexture *texture;
    sfTexture *texture_a;
    sfVector2f pos, scale;
    sfText *text;
    int type, price;
    int clicked;
    struct t_select *next;
} t_select_t;

typedef struct player {
    sfSprite *sprite_h;
    sfSprite *sprite_m;
    sfTexture *texture_h;
    sfTexture *texture_m;
    sfText *txt_money;
    sfText *txt_life;
    char *strmoney;
    char *strlife;
    int money;
    int life;
    int defeat;
} player_t;

typedef struct upgrade_texture
{
    sfClock *clock;
    sfTime time;
    float seconds;
    int bounce;
    int alpha;
    sfTexture *hexa;
    sfTexture *square;
    sfTexture *triangle;
    sfTexture *round;
    sfTexture *turret1_dual;
    sfTexture *turret1_large;
    sfTexture *turret1_foundation;
    sfTexture *turret1_value;
    sfTexture *turret2_speed;
    sfTexture *turret2_heavy;
    sfTexture *turret2_long;
    sfTexture *turret2_killshot;
    sfTexture *turret3_foundation;
    sfTexture *turret3_long;
    sfTexture *turret3_shrapnel;
    sfTexture *turret3_speed;
    sfTexture *turret4_slow;
    sfTexture *turret4_cold;
    sfTexture *turret4_system;
    sfTexture *turret4_snowball;
} upgrade_texture_t;

typedef struct turret_texture
{
    sfTexture *turret1_dual;
    sfTexture *turret1_foundation;
    sfTexture *turret1_large;
    sfTexture *turret1_value;
    sfTexture *turret2_speed;
    sfTexture *turret2_heavy;
    sfTexture *turret2_long;
    sfTexture *turret2_killshot;
    sfTexture *turret3_foundation;
    sfTexture *turret3_long;
    sfTexture *turret3_shrapnel;
    sfTexture *turret3_speed;
    sfTexture *turret4_slow;
    sfTexture *turret4_cold;
    sfTexture *turret4_system;
    sfTexture *turret4_snowball;
} turret_texture_t;

typedef struct abilities {
    sfRectangleShape *rectangle;
    sfSprite *under;
    sfSprite *upgrade;
    sfText *name;
    int id;
    int bought;
    struct abilities *next;
} abilities_t;

typedef struct turret {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_b;
    sfSprite *zone;
    sfTexture *zone_txt;
    sfTexture *texture_b;
    sfSprite *sprite_c;
    sfTexture *texture_c;
    sfSprite *bullet;
    sfTexture *text_bullet;
    sfVector2f pos;
    sfVector2f pos_c;
    sfVector2f pos_bullet;
    sfVector2f pos_xp;
    tuto_t *locked;
    list_targetting_t *target;
    sfClock *clock;
    sfTime time;
    sfText *r_speed_txt;
    sfText *name;
    sfText *range_txt;
    sfText *rof_txt;
    sfText *dmg_txt;
    sfText *sell_txt;
    sfText *upg_price_txt;
    sfText *xp_txt;
    sfText *lvl_txt;
    sfText *b_speed_txt;
    sfRectangleShape *under;
    sfRectangleShape *xp_bar;
    char *r_speed_str, *rof_str, *dmg_str, *b_speed_str, *range_str;
    char *strsell, *strupg_price, *strlvl, *strxp;
    float seconds;
    int type, mode, level, xp, dmg, sell, button, upg_price;
    int range, shoot, hit, draw_stat, price, counter, max;
    float rotate, r_speed, bullet_speed, rate_fire;
    sfVector2f pos_c2;
    abilities_t *abilities;
    struct turret *next;
} turret_t;

typedef struct selected {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfSprite *clicked_s;
    sfVector2f pos;
    sfVector2f pos2;
    support_t *sel;
    turret_t *tur;
    char type;
    int on, click;
} selected_t;

typedef struct selected2 {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfSprite *clicked_s;
    sfVector2f pos;
    sfVector2f pos2;
    int type;
    int on, click;
    t_select_t *zone;
} selected2_t;

typedef struct levels {
    char *filepath;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *click;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    sfText *name;
    float seconds;
    float scale;
    int id;
    struct levels *next;
} levels_t;

typedef struct map {
    char *map;
    int spawner;
    int castle;
    sfVector2f castle_pos;
    sfVector2f spawner_pos;
    struct support *s_support;
} map_t;

typedef struct utils {
    int id;
    sfVector2f pos;
} utils_t;

typedef struct waves {
    int round, square, triangle;
    sfClock *clock;
    sfTime time;
    float seconds;
    struct waves *next;
} waves_t;

typedef struct sell {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfVector2f pos;
    int clic;
} sell_t;

typedef struct info_text {
    sfText *support_txt;
    sfText *ground_txt;
    sfText *spawner_txt;
    sfText *castle_txt;
    sfText *title_o;
    sfText *title_g;
    sfText *title_s;
    sfText *title_c;
    sfVector2f pos_title;
    sfVector2f pos_txt;
} info_text_t;

typedef struct wave_controll {
    sfClock *clock;
    sfTime time;
    float seconds;
    int nb_waves, go, start;
    int playing, min;
    char *strwave, *base;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfText *text2;
    sfTexture *one;
    sfTexture *two;
    sfTexture *three;
    sfTexture *eric;
    struct waves *head;
    struct waves *temp;
    struct tuto *round;
    struct tuto *square;
    struct tuto *triangle;
} wave_controll_t;

typedef struct hard_buttons {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfVector2f pos;
} hard_buttons_t;

typedef struct hard_upgrade {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    sfSprite *gold;
    sfTexture *gold_txt;
    sfVector2f pos;
} hard_upgrade_t;

typedef struct hard_arrow {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture4;
    sfVector2f pos;
    int stat;
} hard_arrow_t;

typedef struct node_buttons {
    int who;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfVector2f pos;
    struct node_buttons *next;
} node_buttons_t;

typedef struct list_buttons {
    int length;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfSprite *black;
    sfTexture *text_black;
    sfColor color;
    node_buttons_t *begin;
    node_buttons_t *end;
} list_buttons_t;

typedef struct side_menu {
    sfSprite *sprite;
    sfTexture *texture2;
    sfTexture *texture;
    sfTexture *texture3;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos;
    int slide;
    int draw;
} side_menu_t;

typedef struct map_edit {
    char *map;
    int error;
    sfText *error1;
    sfText *error2;
    sfClock *clock;
    sfTime time;
    float seconds;
    struct support *head;
    struct support *placed;
    struct support *examples;
} map_edit_t;

typedef struct buttons_tab {
    char *tab[12];
    char *tab2[12];
    char *tab_f[4];
    sfVector2f *tab_v[4];
} buttons_tab_t;

typedef struct map_buttons {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *hover;
    sfVector2f pos;
    int id;
    struct map_buttons *next;
} map_button_t;

typedef struct node_settings {
    int id;
    sfSprite *sprite;
    sfTexture *on;
    sfTexture *off;
    sfVector2f pos;
    struct node_settings *next;
} node_settings_t;

typedef struct list_settings {
    int length;
    int eric;
    int shaders;
    int sound;
    int music;
    node_settings_t *begin;
    node_settings_t *end;
} list_settings_t;

typedef struct lost {
    int display;
    sfCircleShape *circle;
    struct lost *next;
} lost_t;

typedef struct all {
    map_t s_map;
    upgrade_texture_t s_texture;
    game_t s_game;
    menu_t s_menu;
    map_edit_t s_map_edit;
    utils_t s_utils;
    player_t s_player;
    spawning_t s_spawning;
    side_menu_t s_side_menu;
    selected_t s_selected;
    sounds_t s_sounds;
    info_text_t s_info_text;
    sell_t s_sell;
    statistics_t s_stats;
    turret_texture_t turret_texture;
    hard_upgrade_t s_upgrade;
    hard_buttons_t s_hard_buttons;
    hard_buttons_t s_hard_buttons2;
    hard_arrow_t s_hard_arrow;
    buttons_tab_t s_buttons_tab;
    selected2_t s_selected2;
    wave_controll_t s_wave_c;
    lost_t *s_lost;
    tuto_t *s_tuto;
    levels_t *s_levels;
    levels_t *s_custom;
    map_button_t *s_map_buttons;
    t_select_t *s_t_select;
    list_buttons_t *s_buttons;
    list_targetting_t *s_targetting;
    list_settings_t *s_settings;
    turret_t *s_turret;
} all_t;

void actualize_stats(all_t *s_all);
void write_statistics(all_t *s_all);
void init_stats_text(all_t *s_all);
void display_statistics(all_t *s_all);
void init_sounds(all_t *s_all);
void menu_release_selector3(all_t *s_all, int i);
int message(void);
void init_map(all_t *s_all);
void display_map(all_t *s_all);
int game_loop(all_t *s_all);
void map_selector_release(all_t *s_all);
void event_controll(all_t *s_all);
void display(all_t *s_all);
void init_all(all_t *s_all);
void generate_round_mobs(all_t *s_all);
void display_error_texts(all_t *s_all);
void generate_waves(all_t *s_all);
void init_menu(all_t *s_all);
void setup(all_t *all);
void display_menu(all_t *s_all);
void init_custom_maps(all_t *s_all);
void display_round_mobs(all_t *s_all);
void clock_round(all_t *s_all);
void check_destroy_ball(all_t *s_all, int id);
void list_menu_buttons(all_t *s_all);
void init_clocks2(all_t *s_all);
int map_error_handling(char **saved, all_t *s_all);
void init_custom_level_buttons(all_t *s_all);
void display_custom_buttons(all_t *s_all);
void custom_map_selector_release(all_t *s_all);
void custom_menu_level_hitbox(levels_t *tmp, all_t *s_all);
void custom_map_selector_click(all_t *s_all);
void select_map(all_t *s_all, levels_t *temp);
void update_player(all_t *s_all);
void display_menu_buttons(all_t *s_all);
void destroy_music(all_t *s_all);
void init_turret_texture(all_t *s_all);
void destroy_regroup(all_t *s_all);
void init_selected(all_t *s_all);
void load_statistics(all_t *s_all);
void display_annex(all_t *s_all, tuto_t *temp);
void check_support_hitbox(all_t *s_all);
void init_player_infos(all_t *s_all);
void display_player_info(all_t *s_all);
void menu_press_buttons(all_t *s_all);
void display_info_texts(all_t *s_all);
void init_info_texts(all_t *s_all);
void menu_release_buttons(all_t *s_all);
void init_sell_button(all_t *s_all);
void display_sell_button(all_t *s_all);
void init_level_buttons(all_t *s_all);
void display_level_selector(all_t *s_all);
void button_sound(all_t *s_all);
void init_sell_button(all_t *s_all);
void init_count_wave_button(all_t *s_all);
void set_txt_sizes(turret_t *new);
void display_count_wave_button(all_t *s_all);
void menu_buttons_hitbox(node_buttons_t *tmp, all_t *s_all);
void init_pause_button(all_t *s_all);
void hitbox_pause_button(all_t *s_all);
void click_n_place(all_t *s_all);
void display_placed(all_t *s_all);
void display_pause_button(all_t *s_all);
void upgrade_abilities_type4(all_t *s_all, abilities_t *tmp);
void release_pause_button(all_t *s_all);
void display_clicked(all_t *s_all);
void max_upgrade(all_t *s_all, turret_t *tur);
void click_support(all_t *s_all);
void init_side_menu(all_t *s_all);
void display_side_menu(all_t *s_all, list_targetting_t *s_targetting);
void button_tab_init(char **tab);
void button_tab2_init(char **tab2);
void black_init(all_t *s_all);
int check_sell_hitbox(all_t *s_all);
void init_upgrade_texture(all_t *s_all);
void click_sell_button(all_t *s_all);
sfVector2f get_spawner_position(all_t *s_all);
void turret_level_up(turret_t *tur);
sfVector2f get_castle_position(all_t *s_all);
void check_path(all_t *s_all, tuto_t *s_balls);
void move_up(tuto_t *s_balls, int len, all_t *s_all);
void move_down(tuto_t *s_balls, int len, all_t *s_all);
void move_left(tuto_t *s_balls, all_t *s_all);
void move_right(tuto_t *s_balls, all_t *s_all);
int my_if(tuto_t *temp);
void check_path(all_t *s_all, tuto_t *s_balls);
void display_selected_turret(all_t *s_all);
void init_upgrade_turret(all_t *s_all, turret_t *new);
void generate_selected_turret(all_t *s_all);
void init_selected_turret(all_t *s_all);
int check_selected_turret(all_t *s_all, t_select_t *s_turret);
void list_targetting(all_t *s_all);
void display_targetting_buttons(all_t *s_all, list_targetting_t *s_targetting);
void hitbox_change_targetting_next(all_t *s_all);
void hitbox_change_targetting_back(all_t *s_all);
void keep_centered_targetting(list_targetting_t *s_targetting);
void slider_on1(all_t *s_all, list_targetting_t *s_targetting);
void slider_off1(all_t *s_all, list_targetting_t *s_targetting);
void set_show_targetting(list_targetting_t *s_targetting);
void display_slider_arrow(all_t *s_all);
void init_slider_arrow(all_t *s_all);
void hitbox_slider_arrow(all_t *s_all);
void release_slider_arrow(all_t *s_all);
void slider_on(all_t *s_all, list_targetting_t *s_targetting);
void slider_off(all_t *s_all, list_targetting_t *s_targetting);
int my_brick(all_t *s_all);
int check_side_menu(all_t *s_all);
void rotate_turret_maths(all_t *s_all);
int check_pause_button(all_t *s_all);
void turret_shoot(turret_t *tmp, float dif_angle, all_t *s_all);
void find_pos_closest(all_t *s_all, turret_t *turret);
void get_money_by_mobs(all_t *s_all);
void move_mob(tuto_t *mob, sfVector2f scl, all_t *s_all);
void init_wave_button(all_t *s_all);
void create_support_examples(all_t *s_all);
void display_support_examples(all_t *s_all);
void rotate_spawner(support_t *s_support, all_t *s_all);
void hitbox_wave_button(all_t *s_all);
void release_wave_button(all_t *s_all);
void get_turret_zone(all_t *s_all, t_select_t *temp);
void display_wave_button(all_t *s_all);
tuto_t *destroy_mob_head(tuto_t *s_tuto, tuto_t *temp3, all_t *s_all);
tuto_t *free_mobs(tuto_t *head);
int mob_destroy_animation(tuto_t *s_tuto);
void get_random_position(tuto_t *new);
void restart_tuto_clocks(all_t *s_all);
int calcul_magnitude(tuto_t *tmp, turret_t *turret);
void losing_life(all_t *s_all);
int check_in_range(turret_t *turret, tuto_t *locked);
void lock_target_in_range(turret_t *turret, tuto_t *locked);
void find_pos_last(all_t *s_all, turret_t *turret);
void find_pos_first(all_t *s_all, turret_t *turret);
void find_pos_weak(all_t *s_all, turret_t *tmp);
void find_pos_strong(all_t *s_all, turret_t *turret);
void targetting_selector(all_t *s_all, turret_t *tmp);
void turret_list_targetting(turret_t *tmp, all_t *s_all);
list_targetting_t *push_back_turret_targetting(turret_t *tmp,
    int x, char *tab, int big);
void update_wave_button(all_t *s_all);
targetting_t *new_node_turret_targetting(int x, char *tab, int i);
int is_empty_list_targetting(list_targetting_t *li);
void display_turret_target(all_t *s_all);
void hitbox_change_targetting_next_turret(all_t *s_all,
    list_targetting_t *s_targetting);
void hitbox_change_targetting_back_turret(all_t *s_all,
    list_targetting_t *s_targetting);
void slow_mobs_in_range(turret_t *turret, all_t *s_all);
list_targetting_t *clear_list_target(list_targetting_t *li);
list_targetting_t *pop_front_targetting(list_targetting_t *li);
void fill_mobs3(tuto_t *new);
void turret_aoe(all_t *s_all, turret_t *turret);
support_t *free_support(support_t *head);
turret_t *free_turret(turret_t *head);
list_targetting_t *clear_list_target(list_targetting_t *li);
int check_selected(all_t *s_all, support_t *s_support);
list_buttons_t *new_list_buttons(void);
int is_empty_list_buttons(list_buttons_t *li);
node_buttons_t *new_node_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *push_back_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *pop_front_buttons(list_buttons_t *li);
list_buttons_t *clear_list(list_buttons_t *li);
targetting_t *new_node_targetting(int x, char *tab, int i);
list_targetting_t *push_back_targetting(all_t *s_all, int x, char *tab);
void general_game_clock(all_t *s_all);
void check_selected_turret_hitbox(all_t *s_all);
int check_selected_turret(all_t *s_all, t_select_t *s_turret);
void click_selected_turret(all_t *s_all);
void display_clicked_turret(all_t *s_all);
void display_turret(all_t *s_all);
void place_turret(all_t *s_all);
void load_turret(turret_t *new, sfVector2f pos);
void get_turret_type(turret_t *new, all_t *s_all);
void display_turret_stats(all_t *s_all);
void slider_off3(all_t *s_all);
void init_shader_mob(tuto_t *new, all_t *s_all);
void correct_slow(all_t *s_all);
void init_creator_buttons(all_t *s_all);
void display_creator_buttons(all_t *s_all);
void display_upgrade_button(all_t *s_all);
void init_upgrade_button(all_t *s_all);
void hitbox_upgrade_button(all_t *s_all);
void release_upgrade_button(all_t *s_all);
void slider_on4(all_t *s_all);
void slider_off4(all_t *s_all);
void upgrade2(turret_t *tur);
void menu_level_hitbox(levels_t *tmp, all_t *s_all);
void map_selector_click(all_t *s_all);
void init_level_buttons2(all_t *s_all);
int is_empty_list_settings(list_settings_t *li);
node_settings_t *new_node_settings(int y, int x, int id);
list_settings_t *push_back_settings(all_t *s_all, int x, int y, int id);
list_settings_t *pop_front_settings(list_settings_t *li);
list_settings_t *clear_list_settings(list_settings_t *li);
void list_settings_buttons(all_t *s_all);
void display_settings_buttons(all_t *s_all);
void settings_press_buttons(all_t *s_all);
void set_eric_skin(all_t *s_all);
lost_t *init_lost_screen(all_t *s_all);
void display_lost_screen(all_t *s_all);
void remove_lost_screen(all_t *s_all);
void set_lost_screen(all_t *s_all);
void anim_transition(all_t *s_all);
void restart_level(all_t *s_all);
abilities_t *init_abilities(all_t *s_all, int type);
void fill_turret_xp(turret_t *new);
lost_t *init_node(lost_t *node, all_t *s_all, float radius);
lost_t *push_front_lost(lost_t *head, all_t *s_all, float radius);
lost_t *init_lost_screen(all_t *s_all);
abilities_t *push_front_abilities(all_t *s_all, abilities_t *head, int type);
void slider_on_abilities(all_t *s_all);
void slider_off_abilities(all_t *s_all);
void upgrade_abilities_type3_bis_2(all_t *s_all, abilities_t *tmp);
void hitbox_abilities(all_t *s_all);
void upgrade_abilities_type2(all_t *s_all, abilities_t *tmp);
void upgrade_abilities_type3(all_t *s_all, abilities_t *tmp);
void init_turret4(abilities_t *node, int type, all_t *s_all, int nb);
void end_game(all_t *s_all);

void display_support(all_t *s_all);
support_t *fill_support(support_t *s_support, sfVector2f pos,
                        char *filepath, char type);
levels_t *fill_levels(levels_t *old, char *filepath, char **text,
    sfVector2f pos);
void click_creator_button(all_t *s_all);
int check_creator_button_hitbox(map_button_t *temp, all_t *s_all);
void release_creator_buttons(all_t *s_all);
void free_placed_node(all_t *s_all);
void save_map(all_t *s_all);
turret_t *fill_turret(turret_t *old, sfVector2f pos, int id, all_t *s_all);
turret_t *get_turret(all_t *s_all);
void release_sell_button(all_t *s_all);
void slider_on3(all_t *s_all);

void display_triangle(all_t *s_all);
void display_square(all_t *s_all);
void display_mobs(all_t *s_all);
void display_round(all_t *s_all);
void push_rand_rounds(all_t *s_all);
void push_rand_square(all_t *s_all);
void push_rand_triangle(all_t *s_all);
tuto_t *fill_mobs(tuto_t *s_tuto, all_t *s_all, sfTexture *texture, int id);
tuto_t *destroy_part1(all_t *s_all, tuto_t *temp2, tuto_t *temp3,
                        tuto_t *temp);
void destroy_part2(all_t *s_all, int id, tuto_t *temp);
tuto_t *destroy_part3(all_t *s_all, tuto_t *temp3, tuto_t *temp);
void destroy_mobs(all_t *s_all, int id);
void free_node2(all_t *s_all, tuto_t *temp, int id);
tuto_t *free_node(tuto_t *s_tuto, tuto_t *prev, tuto_t *temp3, all_t *s_all);

void map_editor_click(all_t *s_all);
void map_editor_release(all_t *s_all);

#endif /* !DEFENDER_H_ */