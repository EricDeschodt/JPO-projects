/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** project header
*/

#ifndef MYHUNTER_H_
#define MYHUNTER_H_

#include <time.h>
#include "framebuffer.h"


typedef struct dog {
    sfIntRect    dogsFrame;
    sfVector2f   dogsPosition;
    sfTexture   *dogTexture_walk;
    sfTexture   *dogTexture_snif;
    sfSprite    *dogSprite;
    int step;
} dog_t;

typedef struct duck {
    sfIntRect    duckFrameFly;
    sfIntRect    duckFrameDrop;
    sfVector2f   duckPosition;
    sfTexture   *duckTextureFly;
    sfTexture   *duckTextureDeath;
    sfTexture   *duckTextureDrop;
    sfSprite    *duckSprite;
} duck_t;

typedef struct myhunter {
    sfVideoMode         mode;
    sfRenderWindow*     window;
    framebuffer_t      *framebuffer;
    sfTexture          *bckgrndTexture;
    sfSprite           *bckgrndSprite;
    sfVector2f          scaler;
    dog_t              *dog;
    duck_t             *duck;
    sfColor             sfBlueSky;
    sfClock            *clock;
    sfEvent             event;
    sfVector2f          posMouse;
} myhunter_t;

myhunter_t *struct_init_sec(myhunter_t *strct);
myhunter_t *struct_init_prim(char *title, int width, int height);
void game_loop(myhunter_t *myhunter, dog_t *dog, duck_t *duck);
void destroyer_hunter_struct(myhunter_t *myhunter);
void analyseEvents(myhunter_t *myhunter);
void dog_anim(myhunter_t *myhunter);
void duck_anim(myhunter_t *myhunter, char way);
void move_duck_rect(sfIntRect *rect, int offset, int max_value);
int move_dog_rect(sfIntRect *rect, int offset, int max_value, int step);
void move_dog_sprite(sfVector2f *pos, int step);
void move_duck_sprite(sfVector2f *pos, char way, float speed);
float random_coords(int limit);
int check_coords(myhunter_t *myhunter, duck_t *duck);
char duck_death_anim(myhunter_t *myhunter, float seconds);
void dog_anim_snif(dog_t *dog);

#endif    /* MYHUNTER_H_ */