/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** end_game
*/

#include "runner.h"

void *end_game(controll_t *s_controll)
{
    write_score(s_controll);
    s_controll->s_game.scene = 4;
    destroy_level(s_controll);
    free_coins(s_controll);
    free_monsters(s_controll);
    free_obstacles(s_controll);
    return (NULL);
}

void destroy_level(controll_t *s_controll)
{
    sfSprite_destroy(s_controll->s_jelly.sprite);
    sfSprite_destroy(s_controll->s_runner.sprite);
    sfSprite_destroy(s_controll->s_jump.sprite_j);
    sfSprite_destroy(s_controll->s_jump.sprite_f);
    sfSprite_destroy(s_controll->s_slide.sprite);
    sfSprite_destroy(s_controll->s_stopped.sprite);
    sfTexture_destroy(s_controll->s_jump.texture_j);
    sfTexture_destroy(s_controll->s_jump.texture_f);
    sfTexture_destroy(s_controll->s_slide.texture);
    sfTexture_destroy(s_controll->s_stopped.texture);
    sfTexture_destroy(s_controll->s_runner.texture);
    sfTexture_destroy(s_controll->s_jelly.texture);
    sfClock_destroy(s_controll->s_runner.clock);
    sfClock_destroy(s_controll->s_jelly.clock);
    sfClock_destroy(s_controll->s_runner.jump_cl);
    sfClock_destroy(s_controll->s_slide.clock);
}

void free_coins(controll_t *s_controll)
{
    coin_t *temp;
    if (s_controll->s_coin != NULL)
        while (s_controll->s_coin != NULL) {
            temp = s_controll->s_coin;
            s_controll->s_coin = s_controll->s_coin->next;
            destroy_coin(temp);
            free(temp);
        }
}

void free_obstacles(controll_t *s_controll)
{
    obstacle_t *temp;
    if (s_controll->s_obstacle != NULL)
        while (s_controll->s_obstacle != NULL) {
            temp = s_controll->s_obstacle;
            s_controll->s_obstacle = s_controll->s_obstacle->next;
            destroy_obstacle(temp);
            free(temp);
        }
}

void free_monsters(controll_t *s_controll)
{
    monster1_t *temp;
    if (s_controll->s_monster != NULL)
        while (s_controll->s_monster != NULL) {
            temp = s_controll->s_monster;
            s_controll->s_monster = s_controll->s_monster->next;
            destroy_monster(temp);
            free(temp);
        }
}