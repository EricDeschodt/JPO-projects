/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** destroy window, framebuffer, texture, ...
*/

#include <SFML/Graphics.h>
#include "../include/myhunter.h"
#include <stdlib.h>

static void destroyer_dog_struct(dog_t *dog)
{
    sfSprite_destroy(dog->dogSprite);
    sfTexture_destroy(dog->dogTexture_snif);
    sfTexture_destroy(dog->dogTexture_walk);
    free(dog);
    return;
}

void destroyer_hunter_struct(myhunter_t *myhunter)
{
    sfClock_destroy(myhunter->clock);
    destroyer_dog_struct(myhunter->dog);
    sfSprite_destroy(myhunter->bckgrndSprite);
    sfTexture_destroy(myhunter->bckgrndTexture);
    framebuffer_destroy(myhunter->framebuffer);
    sfRenderWindow_destroy(myhunter->window);
    free(myhunter);
    return;
}