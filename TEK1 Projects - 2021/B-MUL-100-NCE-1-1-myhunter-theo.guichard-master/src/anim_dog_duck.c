/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** all fonctions for animations
*/

#include "../include/myhunter.h"

int check_coords(myhunter_t *myhunter, duck_t *duck)
{
    if (myhunter->posMouse.x >= duck->duckPosition.x && \
    myhunter->posMouse.x <= duck->duckPosition.x + duck->duckFrameFly.width * \
    myhunter->scaler.x && myhunter->posMouse.y >= duck->duckPosition.y && \
    myhunter->posMouse.y <= duck->duckPosition.y + \
    duck->duckFrameFly.height * myhunter->scaler.y)
        return (0);
    return (-1);
}

void dog_anim_snif(dog_t *dog)
{
    sfSprite_setTexture(dog->dogSprite, dog->dogTexture_snif, sfTrue);
    dog->step = move_dog_rect(&dog->dogsFrame, 55, 110, dog->step);
    if (dog->step == 22) {
        dog->dogsPosition.x += 6.25;
        sfSprite_setPosition(dog->dogSprite, \
            dog->dogsPosition);
    }
    if (dog->step == 22) {
        dog->step = 0;
        dog->dogsFrame.left = 0;
    }
    return;
}

void dog_anim(myhunter_t *myhunter)
{
    if (myhunter->dog->step < 16) {
        sfSprite_setTexture(myhunter->dog->dogSprite, \
        myhunter->dog->dogTexture_walk, sfTrue);
        myhunter->dog->step = move_dog_rect(&myhunter->dog->dogsFrame, 55, \
        220, myhunter->dog->step);
        move_dog_sprite(&myhunter->dog->dogsPosition, myhunter->dog->step);
        sfSprite_setPosition(myhunter->dog->dogSprite, \
        myhunter->dog->dogsPosition);
    } else
        dog_anim_snif(myhunter->dog);
    if (myhunter->dog->dogsPosition.x >= myhunter->mode.width)
        myhunter->dog->dogsPosition.x = -55 * myhunter->scaler.x;
}

void duck_anim(myhunter_t *myhunter, char way)
{
    move_duck_rect(&myhunter->duck->duckFrameFly, \
    myhunter->duck->duckFrameFly.width, 3 * \
    myhunter->duck->duckFrameFly.width);
    move_duck_sprite(&myhunter->duck->duckPosition, way, 7);
    sfSprite_setPosition(myhunter->duck->duckSprite, \
    myhunter->duck->duckPosition);
    if (myhunter->duck->duckPosition.x >= myhunter->mode.width)
        myhunter->duck->duckPosition.x = -34 * myhunter->scaler.x;
    sfClock_restart(myhunter->clock);
}

char duck_death_anim(myhunter_t *myhunter, float seconds)
{
    if (seconds < 0.25) {
        sfSprite_setTexture(myhunter->duck->duckSprite, \
        myhunter->duck->duckTextureDeath, sfTrue);
    } else {
        sfSprite_setTexture(myhunter->duck->duckSprite, \
        myhunter->duck->duckTextureDrop, sfTrue);
        myhunter->posMouse.x = -1;
        myhunter->posMouse.y = -1;
        return ('d');
    }
}