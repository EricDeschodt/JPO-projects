/*
** EPITECH PROJECT, 2020
** first graphical prog
** File description:
** initiation to graphical prog
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

framebuffer_t *framebuffer_trans(framebuffer_t *framebuffer, float opacity);
framebuffer_t *framebuffer_clear(framebuffer_t *framebuffer, sfColor color);
framebuffer_t *framebuffer_create(sfVideoMode video_mode);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);
sfSprite *draw_frame(framebuffer_t *framebuffer, sfVector2i pos1, sfVector2i pos2, sfColor color);
void screensavers(int c);
void draw_square(framebuffer_t *framebuffer, sfVector2i pos1, sfVector2i sizes, sfColor color);
void draw_stuff(sfRenderWindow *window, framebuffer_t *framebuffer, sfEvent event, int c);
void my_draw_circle(framebuffer_t *framebuffer, sfVector2i center, int radius, sfColor color);
void put_line(framebuffer_t *framebuffer, sfVector2i pos1, int angle, sfColor color);
void my_draw_crown(framebuffer_t *framebuffer, sfVector2i center, int radius, int thickness, sfColor color);

int first_screen(sfRenderWindow *window, framebuffer_t *framebuffer);
void draw_screen_1(framebuffer_t *framebuffer, sfVector2i *circles, int i, int j, sfColor *color);
void draw_fading_crown(framebuffer_t *framebuffer, sfVector2i center, int j, sfColor color);
int get_limit(sfVector2i center);
sfVector2i random_pos(void);
sfColor random_color(void);

int second_screen(sfRenderWindow *window, framebuffer_t *framebuffer);
int third_screen(sfRenderWindow *window, framebuffer_t *framebuffer);
sfColor color_change(int i);
sfColor *gradiant_color(float i);
sfVector2i *get_pos(float i);
void my_draw_seg(framebuffer_t *framebuffer, sfVector2i pos1, int angle, int length, sfColor color);

int fourth_screen(sfRenderWindow *window, framebuffer_t *framebuffer);
int draw_rain(framebuffer_t *framebuffer, int i, int r);
void thunder_crack(sfRenderWindow *window, framebuffer_t *framebuffer, sfSprite *sprite, sfTexture *texture);
framebuffer_t *framebuffer_reverse(framebuffer_t *framebuffer);

void my_move_rosace(framebuffer_t *framebuffer, int a, int k, sfColor color);
int fifth_screen(sfRenderWindow *window, framebuffer_t *framebuffer);

#endif
