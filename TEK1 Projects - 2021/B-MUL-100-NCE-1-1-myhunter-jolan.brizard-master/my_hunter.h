/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** header of my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "lib/my/print.h"

#ifndef B_MUL_100_NCE_1_1_MYHUNTER_JOLAN_BRIZARD_MY_HUNTER_H
#define B_MUL_100_NCE_1_1_MYHUNTER_JOLAN_BRIZARD_MY_HUNTER_H

typedef struct s_window {
    sfRenderWindow *window;
    sfClock *clock;
    sfTime time;
    double seconds;
    bool start;
    int framerate_limit;
}t_window;

typedef struct s_sprite {
    sfTexture *crow_texture;
    sfSprite *crow;
    sfTexture *heart_texture;
    sfSprite *heart;
    sfTexture *b_texture;
    sfSprite *background;
    sfTexture *text_texture;
    sfSprite *text;
    sfTexture *cursor_texture;
    sfSprite *cursor;
    sfVector2f cursor_pos;
    sfIntRect crow_rect;
    sfIntRect heart_rect;
    float speed;
    int life;
}t_sprite;

typedef struct s_audio {
    sfSoundBuffer *intro_buf;
    sfSound *intro;
    sfSoundBuffer *epic_buf;
    sfSound *epic;
}t_audio;


sfRenderWindow *create_window(unsigned int x, unsigned int y,
                                unsigned int bpp, char *window_title);

sfIntRect *define_heart_area(sfIntRect *rect);
sfIntRect *define_crow_area(sfIntRect *rect);
t_window *define_window(t_window *bag);
t_audio *define_audio(t_audio *audio);
void help_message(void);
void set_cursor(t_window *windw, t_sprite *sprite);
void draw_cursor(t_window *windw, t_sprite *sprite);
void clear_all(t_window *windw, t_sprite *sprite, t_audio *audio);
void destroy_all(t_window *windw, t_sprite *sprite, t_audio *audio);
void sprites_coord(t_sprite *sprite);
bool is_mouse_overit(t_window *windw, t_sprite *sprite);
void draw_text(t_window *windw, t_sprite *sprite);
t_sprite *define_sprite(t_sprite *sprite,
                        sfIntRect *crow_rect, sfIntRect *heart_rect);
void crow_animation(t_window *windw, t_sprite *sprite);
void draw_all(t_window *windw, t_sprite *sprite);
void draw_background(t_window *windw, t_sprite *sprite);
void draw_crow(t_window *windw, t_sprite *sprite);
void draw_heart(t_window *windw, t_sprite *sprite);
bool make_conditions(t_window *windw, t_sprite *sprite);
void play_music(t_audio *audio);
void analyse_events(t_window *windw, sfEvent event, t_sprite *sprite);
sfIntRect move_rect(sfIntRect rect, int offset, int max_value);

#endif //B_MUL_100_NCE_1_1_MYHUNTER_JOLAN_BRIZARD_MY_HUNTER_H
