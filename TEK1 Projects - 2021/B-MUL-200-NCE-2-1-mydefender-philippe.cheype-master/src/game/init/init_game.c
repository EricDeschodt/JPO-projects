/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** init_game
*/

#include <stdlib.h>
#include "defender.h"

static void init_wave_ints(wave_t *wave)
{
    wave->mem_kills = 0;
    wave->timer = NULL;
    wave->status = 2;
    wave->skip = 0;
    wave->wave = 1;
}

static wave_t *init_wave(void)
{
    sfFloatRect pos_size_button = { WIDTH - 91, 0, 45, 45 };
    sfFloatRect pos_size_timer =  { WIDTH - 45,  0, 45, 45 };
    sfVector2f pos_button = {WIDTH - 91 + 15, -7};
    sfVector2f pos_timer =  {WIDTH - 45 + 7, -6};
    wave_t *wave;

    wave = malloc(sizeof(wave_t));
    wave->skip_timer = create_button(pos_size_button, ">",  NULL);
    wave->time_left = create_button(pos_size_timer,   "60", NULL);
    sfRectangleShape_setFillColor(wave->skip_timer->rect, sfWhite);
    sfRectangleShape_setFillColor(wave->time_left->rect,  sfWhite);
    sfText_setPosition(wave->skip_timer->text, pos_button);
    sfText_setPosition(wave->time_left->text,  pos_timer);
    sfText_setCharacterSize(wave->skip_timer->text, 40);
    sfText_setCharacterSize(wave->time_left->text,  40);
    wave->start_clock = sfClock_create();
    init_wave_ints(wave);
    return (wave);
}

static void init_life_bar(game_t *gm, sfVector2f pos_a, sfVector2f size_a)
{
    gm->life = handle_health_bar(pos_a, size_a);
    gm->life->points = size_a;
    gm->life_percent = 100;
}

static void init_sound(game_t *gm)
{
    gm->sound = malloc(sizeof(sfMusic *) * 3);
    gm->sound[0] = sfMusic_createFromFile("assets/sound/click.ogg");
    gm->sound[1] = sfMusic_createFromFile("assets/sound/shot.ogg");
    gm->sound[2] = sfMusic_createFromFile("assets/sound/zombie.ogg");
}

game_t *init_game(void)
{
    char path[] = "assets/textures/missing.png";
    sfVector2f pos = {-100, -100}, pos_a = {516, 373};
    sfVector2f size = {64, 64}, size_a = {30, 450};
    game_t *gm;

    gm = malloc(sizeof(game_t));
    init_sound(gm);
    gm->mn = create_env();
    gm->it = create_items();
    gm->wave = init_wave();
    gm->bl = malloc(sizeof(bullet_t));
    gm->bl->next = NULL;
    gm->bl->prev = NULL;
    gm->bl->head = NULL;
    gm->tw = init_object(pos, size, path);
    gm->tw->head = gm->tw;
    gm->en = init_object(pos, size, path);
    gm->en->head = gm->en;
    init_life_bar(gm, pos_a, size_a);
    return (gm);
}
