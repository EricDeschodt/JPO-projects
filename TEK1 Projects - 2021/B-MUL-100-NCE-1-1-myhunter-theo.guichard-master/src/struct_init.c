/*
** EPITECH PROJECT, 2020
** Project Name
** File description:
** all functions to initialize the structures
*/

#include "../include/myhunter.h"

dog_t *init_dog_struct(void)
{
    dog_t *dog;
    sfIntRect rect = {0, 0, 55, 43};

    dog = malloc(sizeof(dog_t));
    if (!dog)
        return (NULL);
    dog->dogsFrame = rect;
    dog->dogTexture_walk = sfTexture_createFromFile("dogs.png", NULL);
    if (!dog->dogTexture_walk)
        return (NULL);
    dog->dogTexture_snif = sfTexture_createFromFile("dogSnif.png", NULL);
    if (!dog->dogTexture_snif)
        return (NULL);
    dog->dogSprite = sfSprite_create();
    if (!dog->dogSprite)
        return (NULL);
    dog->step = 0;
    return (dog);
}

duck_t *init_duck_struct(void)
{
    duck_t *duck;
    sfIntRect rectFly = {0, 0, 34, 33};
    sfIntRect rectDrop = {0, 0, 19, 31};
    sfVector2f pos = {-34, random_coords(300)};

    duck = malloc(sizeof(duck_t ));
    if (!duck)
        return (NULL);
    duck->duckFrameFly = rectFly;
    duck->duckFrameDrop = rectDrop;
    duck->duckPosition = pos;
    duck->duckTextureFly = sfTexture_createFromFile("ducks.png", NULL);
    if (!duck->duckTextureFly) return (NULL);
    duck->duckTextureDeath = sfTexture_createFromFile("death.png", NULL);
    if (!duck->duckTextureDeath) return (NULL);
    duck->duckTextureDrop = sfTexture_createFromFile("drop.png", NULL);
    if (!duck->duckTextureDrop) return (NULL);
    duck->duckSprite = sfSprite_create();
    return (duck);
}

myhunter_t *struct_init_sec(myhunter_t *strct)
{
    strct->bckgrndSprite = sfSprite_create();
    if (!strct->bckgrndSprite)
        return (NULL);
    strct->scaler.x = 3.125;
    strct->scaler.y = 2.5;
    strct->dog = init_dog_struct();
    strct->dog->dogsPosition.x = 2 * strct->scaler.x;
    strct->dog->dogsPosition.y = 146 * strct->scaler.y;
    strct->duck = init_duck_struct();
    strct->sfBlueSky = sfColor_fromRGBA(63, 191, 255, 0);
    strct->clock = sfClock_create();
    if (!strct->clock)
        return (NULL);
    return (strct);
}

myhunter_t *struct_init_prim(char *title, int width, int height)
{
    myhunter_t *new;

    new = malloc(sizeof(myhunter_t));
    if (!new)
        return (NULL);
    new->mode.bitsPerPixel = BPP;
    new->mode.height = height;
    new->mode.width = width;
    new->window = sfRenderWindow_create(new->mode, title, \
    sfResize | sfClose, NULL);
    if (!new->window)
        return (NULL);
    new->framebuffer = framebuffer_create(width, height);
    if (!new->framebuffer)
        return (NULL);
    new->bckgrndTexture = sfTexture_createFromFile("bcgnd.png", NULL);
    if (!new->bckgrndTexture)
        return (NULL);
    return (new);
}