/*
** EPITECH PROJECT, 2020
** lib_include_makefile
** File description:
** Main header for the project
*/

#include "../lib/include/print.h"
#include "../lib/include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef LIB_INCLUDE_MAKEFILE_PROJECT_H
#define LIB_INCLUDE_MAKEFILE_PROJECT_H

typedef struct s_map {
    sfClock *clock_obs;
    sfTime time_obs;
    double seconds_obs;
    sfClock *clock;
    sfTime time;
    double seconds;
    sfTexture *obs_texture;
    sfSprite *obs;
    sfIntRect rct_obs;
    sfVector2f pos;
    char **tab;
    char *buf;
    int index;
    int minest;
}t_map;

typedef struct s_rect {
    sfIntRect l1_rect;
    sfIntRect l2_rect;
    sfIntRect l3_rect;
    sfIntRect l4_rect;
    sfIntRect l5_rect;
    sfIntRect l6_rect;
    sfIntRect l7_rect;
    sfIntRect l8_rect;
    sfIntRect l9_rect;
}t_rect;

typedef struct s_parallax {
    sfClock *clock;
    sfTime time;
    double seconds;
    sfTexture *layer01_texture;
    sfSprite *layer01;
    sfTexture *layer02_texture;
    sfSprite *layer02;
    sfTexture *layer03_texture;
    sfSprite *layer03;
    sfTexture *layer04_texture;
    sfSprite *layer04;
    sfTexture *layer05_texture;
    sfSprite *layer05;
    sfTexture *layer06_texture;
    sfSprite *layer06;
    sfTexture *layer07_texture;
    sfSprite *layer07;
    sfTexture *layer08_texture;
    sfSprite *layer08;
    sfTexture *layer09_texture;
    sfSprite *layer09;
}t_parallax;

typedef struct s_sprite {
    sfTexture *character_texture;
    sfSprite *character;
    sfTexture *idle_texture;
    sfSprite *idle;
    sfIntRect character_rect;
    sfIntRect idle_rect;
    sfClock *clock;
    sfTime time;
    sfVector2f base;
    double seconds;
    float speed;
    sfClock *clock_jp;
    sfTime time_jp;
    double seconds_jp;
    sfClock *clock_idle;
    sfTime time_idle;
    double seconds_idle;
    int offset;
    int max_value;
    int left;
}t_sprite;

typedef struct s_text {
    sfFont *font;
    sfText *title_text;
    sfText *enter_text;
    sfText *win_text;
    sfText *lose_text;
    sfText *score;
    char *s_score;
    int s;
}t_text;

typedef struct s_window {
    sfClock *clock;
    sfTime time;
    double seconds;
    sfRenderWindow *window;
    sfSoundBuffer *sound_buf;
    sfSound *sound;
    sfSoundBuffer *death_buf;
    sfSound *death_sound;
    bool start;
    bool win;
    bool end;
    bool jumping;
    struct s_text *text;
    struct s_parallax *px;
    struct s_sprite *sprite;
    struct s_map *map;
    struct s_rect *rect;
}t_window;

void draw_map(t_window *window);
void play_music(t_window *window);
void analyse_events(t_window *window, sfEvent event);
void help_message(void);
void player_jump(t_window *window);
void reset(t_window *window);
void win_lose(t_window *window);

void define_title(t_text *text);
void define_score(t_text *text);
void define_win_lose(t_text *text);
void int_to_str(t_text *sc, int nb);

sfRenderWindow *create_window(unsigned int x, unsigned int y,
                                unsigned int bpp, char *window_title);
t_window *define_window(t_window *window);
t_sprite *define_sprite(t_sprite *sprite);
t_text *define_text(t_text *text);
t_parallax *define_px(t_parallax *px);
t_map *define_map(t_map *map);
t_rect *define_rect(t_rect *rect, t_parallax *px);
void set_audio(t_window *window);
bool map_valid(t_map *map, char **av);
void load_map(t_map *map);

void idle_obs(t_window *window);
void ch_anim(t_window *window);
void jump_animation(t_window *window);
sfIntRect move_rect(sfIntRect rect, int offset, int max_value, int left);
void character_animation(t_window *window);
void px_animation(t_window *window, int speed);
void idle_animation(t_window *window);

void draw_score(t_window *window);
void draw_blocks(t_window *window);
void draw_background(t_window *window);
void draw_character(t_window *window);
void draw_title(t_window *window);
void draw_all(t_window *window);
void draw_win_lose(t_window *window);

int error_handling(int ac, char **av);
void clear_all(t_window *window);
void destroy_all(t_window *window);

#endif //LIB_INCLUDE_MAKEFILE_PROJECT_H
