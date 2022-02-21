/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** Error handling, clean all allocated ressources and display help manual
*/

#include "my_hunter.h"

void help_message(void)
{
    my_printf("Welcome to Odin's Hunt, the game of the Gods !\n\n"
                "HOW TO PLAY:\nIn order to start a party, "
                "you must press 'Enter'"
                " key.\nBe careful ! Once the game started, "
                "Odin's crows will try"
                " to escape from Valhalla, "
                "catch them by clicking with your left"
                " mouse button !\nEvery bird escaped is 1/4 of your life-time"
                " drained by Loki, the viscious god.\n\nClick on the red-"
                "cross in the upper-right corner to exit the game.\n\n"
                "\nmade by : Jolan BRIZARD\n");
}

void clear_all(t_window *windw, t_sprite *sprite, t_audio *audio)
{
    free(windw);
    free(audio);
    free(sprite);
}

void destroy_all(t_window *windw, t_sprite *sprite, t_audio *audio)
{
    sfRenderWindow_destroy(windw->window);
    sfSprite_destroy(sprite->background);
    sfSprite_destroy(sprite->crow);
    sfSprite_destroy(sprite->heart);
    sfTexture_destroy(sprite->b_texture);
    sfTexture_destroy(sprite->crow_texture);
    sfTexture_destroy(sprite->heart_texture);
    sfSoundBuffer_destroy(audio->intro_buf);
    sfSound_destroy(audio->intro);
    sfSoundBuffer_destroy(audio->epic_buf);
    sfSound_destroy(audio->epic);
}