/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>

#define HEIGHT  750
#define WIDTH   1200
#define PIXELS  32

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct vars_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
} vars_t;

typedef struct utils_s {
    sfVector2i p;
    sfVector2u u;
    sfVector2i m;
} utils_t;

sfColor my_rand_color(int);
utils_t *utils_create(void);
void clean_window(framebuffer_t *);
void framebuffer_destroy(framebuffer_t *);
vars_t *vars_create(framebuffer_t *, unsigned int);
framebuffer_t *framebuffer_create(unsigned int, unsigned int);
void effect_index(framebuffer_t *, char *, vars_t *, utils_t *);
void my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);
void my_draw_square(framebuffer_t *, sfVector2u, unsigned int, sfColor);
void my_draw_circle(framebuffer_t *, sfVector2i, unsigned int, sfColor);
void screen_end(framebuffer_t *, sfSprite *, sfTexture *, sfRenderWindow *);

#endif /* STRUCT_H_ */
