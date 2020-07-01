/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy
*/

#include "runner.h"

void destroy_background(controll_t *s_controll)
{
    sfRenderWindow_destroy(s_controll->s_game.window);
    sfSprite_destroy(s_controll->s_background.layer1);
    sfSprite_destroy(s_controll->s_background.layer1_bis);
    sfSprite_destroy(s_controll->s_background.layer2);
    sfSprite_destroy(s_controll->s_background.layer2_bis);
    sfSprite_destroy(s_controll->s_background.layer3);
    sfSprite_destroy(s_controll->s_background.layer3_bis);
    sfSprite_destroy(s_controll->s_background.layer4);
    sfSprite_destroy(s_controll->s_background.layer4_bis);
    sfSprite_destroy(s_controll->s_background.layer5);
    sfSprite_destroy(s_controll->s_background.layer5_bis);
    sfSprite_destroy(s_controll->s_background.layer6);
    sfSprite_destroy(s_controll->s_background.layer6_bis);
    sfSprite_destroy(s_controll->s_background.layer7);
    sfSprite_destroy(s_controll->s_background.layer8);
    destroy_next(s_controll);
}

void destroy_next(controll_t *s_controll)
{
    sfMusic_destroy(s_controll->s_music.background_sound);
    sfSound_destroy(s_controll->s_music.jump_sound);
    sfSound_destroy(s_controll->s_music.slide_sound);
    sfSound_destroy(s_controll->s_music.coin_sound);
    sfSoundBuffer_destroy(s_controll->s_music.buff_jump);
    sfSoundBuffer_destroy(s_controll->s_music.buff_slide);
    sfSoundBuffer_destroy(s_controll->s_music.buff_coin);
}

void destroy_coin(coin_t *s_coin)
{
    sfSprite_destroy(s_coin->sprite);
    sfTexture_destroy(s_coin->texture);
    sfClock_destroy(s_coin->clock);
}

void destroy_monster(monster1_t *s_monster)
{
    sfSprite_destroy(s_monster->sprite);
    sfTexture_destroy(s_monster->texture);
    sfClock_destroy(s_monster->clock);
}

void destroy_obstacle(obstacle_t *s_obstacle)
{
    sfSprite_destroy(s_obstacle->sprite);
    sfTexture_destroy(s_obstacle->texture);
}