/*
** EPITECH PROJECT, 2020
** My_h
** File description:
** Header
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <ncurses.h>
#include <string.h>

void print_help(int);
void write(int fd, const void *buf, int count);
void my_putchar(char c);
void which_anim(int nb);
int anim_1(void);
int anim_2(void);
int anim_3(void);
int anim_4(void);
int anim_5(void);
int random_x();
int random_y();

int error_gestion(int ac, char **av);
int my_putstr(char const *str);
int my_getnbr(char const *str);

typedef struct framebuffer framebuffer_t;
typedef struct sfVertexArray sfVertexArray;

struct screen {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *framebuffer;
}typedef screen;

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
sfColor random_color(void);
void framebuffer_destroy(framebuffer_t *framebuffer);
int my_put_line(framebuffer_t *buffer, sfColor color, int x, int y);
void my_put_pixel(framebuffer_t *framebuffer,
unsigned int x, unsigned int y, sfColor color);
void my_draw_square(framebuffer_t *buffer,
sfVector2u position, unsigned int size, sfColor color);
void init_struct(screen *anim, char *name, sfVideoMode mode);
void sf_destroy(screen *anim);