/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** turret_support
*/

#include "defender.h"

support_t *fill_support(support_t *s_support, sfVector2f pos,
                        char *filepath, char type)
{
    support_t *new = malloc(sizeof(support_t));
    new->sprite = sfSprite_create(), new->sprite_base = sfSprite_create();
    new->texture =
    sfTexture_createFromFile(filepath, NULL);
    new->texture_base =
    sfTexture_createFromFile("sprites/spawner_base.png", NULL);
    sfSprite_setTexture(new->sprite_base, new->texture_base, sfTrue);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos = pos, new->base_pos = pos, new->type = type, new->on = 0;
    if (type == 'S') {
        sfSprite_setOrigin(new->sprite, (sfVector2f){60, 60});
        sfSprite_setPosition(new->sprite,
        (sfVector2f){pos.x + 60, pos.y + 60});
    } else sfSprite_setPosition(new->sprite, pos);
    sfSprite_setPosition(new->sprite_base, pos);
    new->next = s_support;
    return (new);
}

void rotate_spawner(support_t *s_support, all_t *s_all)
{
    float rotate = s_all->s_game.seconds;
    if (s_all->s_game.pause == 0)
        sfSprite_rotate(s_support->sprite, 100 * rotate);
    sfClock_restart(s_all->s_game.clock);
    sfShader_setVec2Uniform(s_all->s_game.shader, "lightpos",
        (sfGlslVec2){s_support->pos.x + 60, s_support->pos.y + 60});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_support->sprite_base, NULL);
    if (s_all->s_game.scene == 1 && s_all->s_settings->shaders == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_support->sprite_base, &s_all->s_game.state);
}

void display_support(all_t *s_all)
{
    support_t *temp;
    if (s_all->s_game.scene == 1) temp = s_all->s_map.s_support;
    if (s_all->s_game.scene == 2) temp = s_all->s_map_edit.head;
    while (temp != NULL) {
        if (temp->type == 'S') {
            rotate_spawner(temp, s_all);
        } sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->sprite, NULL);
        if (temp->type != 'S' && s_all->s_settings->shaders == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite, &s_all->s_game.state);
        temp = temp->next;
    }
}