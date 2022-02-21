/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** the game loop
*/

#include <SFML/Graphics.h>
#include "../include/framebuffer.h"
#include "../include/myhunter.h"

void  reset_display_new_sprite(myhunter_t *myhunter, dog_t *dog, duck_t *duck)
{
    sfSprite_setTextureRect(dog->dogSprite, dog->dogsFrame);
    sfSprite_setTextureRect(duck->duckSprite, duck->duckFrameFly);
    sfRenderWindow_clear(myhunter->window, myhunter->sfBlueSky);
    sfRenderWindow_drawSprite(myhunter->window, duck->duckSprite, NULL);
    sfRenderWindow_drawSprite(myhunter->window, myhunter->bckgrndSprite, NULL);
    sfRenderWindow_drawSprite(myhunter->window, dog->dogSprite, NULL);
    sfRenderWindow_display(myhunter->window);
    return;
}

char reset_duck(myhunter_t *myhunter)
{
    sfSprite_setTexture(myhunter->duck->duckSprite, \
    myhunter->duck->duckTextureFly, sfTrue);
    myhunter->duck->duckPosition.x = -34 * myhunter->scaler.x;
    myhunter->duck->duckPosition.y = random_coords(300);
    return ('r');
}

void game_loop(myhunter_t *myhunter, dog_t *dog, duck_t *duck)
{
    sfTime time;
    float seconds;
    char way = 'r';

    while (sfRenderWindow_isOpen(myhunter->window)) {
        while (sfRenderWindow_pollEvent(myhunter->window, &myhunter->event))
            analyseEvents(myhunter);
        reset_display_new_sprite(myhunter, dog, duck);
        time = sfClock_getElapsedTime(myhunter->clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds >= 0.125) {
            dog_anim(myhunter);
            if (!check_coords(myhunter, duck))
                way = duck_death_anim(myhunter, seconds);
            else
                duck_anim(myhunter, way);
        }
        if (duck->duckPosition.y >= 400)
            way = reset_duck(myhunter);
    }
    return;
}