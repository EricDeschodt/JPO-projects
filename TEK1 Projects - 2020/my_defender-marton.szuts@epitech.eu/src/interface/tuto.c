/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** round_mob
*/

#include "defender.h"

tuto_t *fill_balls(tuto_t *s_tuto, sfVector2f pos, int map_pos)
{
    tuto_t *new = malloc(sizeof(tuto_t));
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->map_pos = map_pos, new->increment = 120;
    new->previous = '@', new->state = 0, new->speed = 2, new->seconds = 0;
    new->texture =
    sfTexture_createFromFile("sprites/path.png", NULL);
    new->state = 0;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = pos.x + 60, new->pos.y = pos.y + 60;
    sfSprite_setOrigin(new->sprite, (sfVector2f){15, 15});
    sfSprite_setPosition(new->sprite, pos), new->id = 0;
    new->scale = (sfVector2f){0.1, 0.1}, new->snow = NULL;
    new->snow_text = NULL;
    sfSprite_setScale(new->sprite, new->scale);
    new->next = s_tuto, new->castle = 0;
    return (new);
}

void generate_round_mobs(all_t *s_all)
{
    tuto_t *s_tuto = NULL;
    sfVector2f pos = s_all->s_map.spawner_pos;
    for (int i = 0; i != 1; i++) {
        s_tuto = fill_balls(s_tuto, pos, s_all->s_map.spawner);
    }
    s_all->s_tuto = s_tuto;
}

void display_round_mobs(all_t *s_all)
{
    tuto_t *temp = s_all->s_tuto;
    sfVector2f scl;
    while (temp != NULL) {
        scl = sfSprite_getScale(temp->sprite);
        if (scl.x < 1 && scl.y < 1 && temp->state == 0)  {
            temp->scale.x += temp->seconds + 0.03;
            temp->scale.y += temp->seconds + 0.03;
            sfSprite_setScale(temp->sprite, temp->scale);
            sfClock_restart(temp->clock);
        } check_path(s_all, temp);
        sfSprite_setPosition(temp->sprite, temp->pos);
        if (s_all->s_wave_c.go == 0)
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->sprite, NULL);
        temp = temp->next;
    } if (s_all->s_spawning.seconds2 > 0.4 && s_all->s_game.pause != 1) {
        s_all->s_tuto = fill_balls(s_all->s_tuto, s_all->s_map.spawner_pos,
        s_all->s_map.spawner), sfClock_restart(s_all->s_spawning.clock2);
    } check_destroy_ball(s_all, 0);
}