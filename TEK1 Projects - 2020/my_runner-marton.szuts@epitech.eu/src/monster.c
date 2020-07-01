/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** monster
*/

#include "runner.h"

monster1_t *render_monster(monster1_t *s_monster, int height, int posx)
{
    monster1_t *new_monster = malloc(sizeof(monster1_t));
    new_monster->clock = sfClock_create();
    new_monster->rect.left = 0, new_monster->rect.top = 0;
    new_monster->rect.width = 205;
    new_monster->rect.height = 165, new_monster->secconds = 0;
    new_monster->texture =
    sfTexture_createFromFile("sprites/flying_m.png", NULL);
    new_monster->sprite = sfSprite_create();
    sfSprite_setTexture(new_monster->sprite, new_monster->texture, sfTrue);
    sfSprite_setTextureRect(new_monster->sprite, new_monster->rect);
    if (height == 2)
        new_monster->pos = (sfVector2f){posx, 680};
    else
        new_monster->pos = (sfVector2f){posx, 600};
    sfSprite_setPosition(new_monster->sprite, new_monster->pos);
    new_monster->next = s_monster;
    return (new_monster);
}

void init_monster(controll_t *s_controll)
{
    monster1_t *s_monster = NULL;
    sfVector2f pos = (sfVector2f){2300, 600};
    s_controll->nb_monsters = 2;
    for (int i = 0; i < s_controll->nb_monsters; i++) {
        s_monster = render_monster(s_monster, 2, pos.x);
        pos.x += 500;
    }
    s_controll->s_monster = s_monster;
}

void display_monster(controll_t *s_controll)
{
    monster1_t *temp = s_controll->s_monster;
    for (; temp != NULL;) {
        temp = draw_monster(s_controll, temp);
    }
}

monster1_t *draw_monster(controll_t *s_controll, monster1_t *s_monster)
{
    if (s_controll->s_game.scene == 1) {
        if (s_monster->secconds > 0.08) {
            move_rect_monster(s_monster, 205, 820);
            sfSprite_setTextureRect(s_monster->sprite, s_monster->rect);
            sfClock_restart(s_monster->clock);
        }
    }
    sfSprite_setPosition(s_monster->sprite, s_monster->pos);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_monster->sprite, NULL);
    return (move_monster(s_controll, s_monster));

}

monster1_t *move_monster(controll_t *s_controll, monster1_t *s_monster)
{
    monster1_t *temp = s_monster;
    if (s_monster->pos.x > -700) {
        s_monster->pos.x -= 750 * s_controll->s_background.secconds *
        s_controll->s_game.speed;
        s_monster = s_monster->next;
    }
    else {
        s_monster = s_monster->next;
        free_monster(temp, s_controll);
    }
    return (s_monster);
}