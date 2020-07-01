/*
** EPITECH PROJECT, 2019
** init_params
** File description:
** init_params
*/

#include "ducky.h"

void init_params(s_show *image)
{
    image->level = 1.0;
    image->func = 0;
    image->duck.clock = sfClock_create();
    image->duck.clock_move = sfClock_create();
    image->duck_rev.clock = sfClock_create();
    image->duck_rev.clock_move = sfClock_create();
    image->dog.clock = sfClock_create();
    image->dog.clock_move = sfClock_create();
    image->dog_rev.clock = sfClock_create();
    image->dog_rev.clock_move = sfClock_create();
    image->dead.dead_clock = sfClock_create();
    image->text.number = "0";
    image->life.lives = 5, image->life.state = 0;
    image->filepath = "score.txt";
    image->score_size = 0;
}

void destroy_sprites(s_show *image)
{
    sfTexture_destroy(image->duck.duck.texture);
    sfSprite_destroy(image->duck.duck.sprite);
    sfTexture_destroy(image->duck_rev.duck.texture);
    sfSprite_destroy(image->duck_rev.duck.sprite);
    sfTexture_destroy(image->life.life.texture);
    sfSprite_destroy(image->life.life.sprite);

}

void write_help_msg(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            write(1, "MY HUNTER\n\n", 11);
            write(1, "PRESS ENTER TO START OR ESC TO EXIT\n", 36);
            write(1, "YOU HAVE 5 LIVES\n", 17);
            write(1, "EVERY TIME A DUCK LEAVE'S THE SCREEN YOU "\
            "LOOSE ONE LIFE\n", 56);
            write(1, "CLICK ON DUCKS TO SHOOT THEM\n", 29);
            write(1, "WHEN YOU KILL A DUCK YOUR SCORE INCREASES BY 1\n", 48);
            write(1, "WHEN THE GAME IS FINISHED PRESS R "\
            "TO RESTART OR ESC TO EXIT\n", 61);
        }
        else
            write(1, "Wrong flag try '-h' for help\n", 30);
    }
}

void destroy_menu(s_show *image)
{
    sfTexture_destroy(image->dog.duck.texture);
    sfSprite_destroy(image->dog.duck.sprite);
    sfTexture_destroy(image->dog_rev.duck.texture);
    sfSprite_destroy(image->dog_rev.duck.sprite);
    sfText_destroy(image->text.play_text);
    sfText_destroy(image->text.best_number);
    sfText_destroy(image->text.best_score);
    sfText_destroy(image->text.exit);
    sfTexture_destroy(image->back.texture);
    sfSprite_destroy(image->back.sprite);
    sfTexture_destroy(image->cross.cross.texture);
    sfSprite_destroy(image->cross.cross.sprite);
}

void destroy_gameover(s_show *image)
{
    sfTexture_destroy(image->dead.dead_duck.texture);
    sfSprite_destroy(image->dead.dead_duck.sprite);
    sfText_destroy(image->text.gameover);
    sfText_destroy(image->text.restart);
}
