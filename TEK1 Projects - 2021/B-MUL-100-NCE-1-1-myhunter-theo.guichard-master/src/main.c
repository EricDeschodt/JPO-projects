/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main and init sprite function
*/

#include "../include/myhunter.h"

static void sprite_init(myhunter_t *myhunter, dog_t *dog, duck_t *duck)
{
    sfSprite_setTexture(dog->dogSprite, dog->dogTexture_walk, sfTrue);
    sfSprite_setScale(dog->dogSprite, myhunter->scaler);
    sfSprite_setPosition(dog->dogSprite, dog->dogsPosition);
    sfSprite_setTexture(duck->duckSprite, duck->duckTextureFly, sfTrue);
    sfSprite_setScale(duck->duckSprite, myhunter->scaler);
    sfSprite_setPosition(duck->duckSprite, duck->duckPosition);
    sfSprite_setTexture(myhunter->bckgrndSprite, \
    myhunter->bckgrndTexture, sfTrue);
    sfSprite_setScale(myhunter->bckgrndSprite, myhunter->scaler);
    return;
}

int main(void)
{
    myhunter_t *myhunter;

    myhunter = struct_init_sec(struct_init_prim("my_hunter", 800, 600));
    if (!myhunter)
        return EXIT_FAILURE;
    sprite_init(myhunter, myhunter->dog, myhunter->duck);
    sfRenderWindow_setFramerateLimit(myhunter->window, 30);
    game_loop(myhunter, myhunter->dog, myhunter->duck);
    destroyer_hunter_struct(myhunter);
    return EXIT_SUCCESS;
}