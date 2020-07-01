/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** is_mouse_hovering.c
*/

#include "defender.h"

sfBool is_mouse_hovering(sfFloatRect *rect, sfRenderWindow *window)
{
    return sfFloatRect_contains(rect,
            sfMouse_getPositionRenderWindow(window).x,
            sfMouse_getPositionRenderWindow(window).y);
}

s_hud *create_hud(s_game *game)
{
    s_hud *obj = malloc(sizeof(*obj));
    obj->life = castle_hud(game);
    obj->waves = wave_hud(game);
    obj->gold = gold_hud(game);
    obj->score = score_hud(game);
    obj->texture = sfTexture_createFromFile("res/buttons/topbar.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}

void update_waves(s_game *game)
{
    char *str = malloc(4);
    str[0] = '\0';
    game->hud->waves->w_nb = game->w_nb + 1;
    my_strcat(str, my_itoa(game->hud->waves->w_nb));
    my_strcat(str, "/");
    my_strcat(str, my_itoa(game->hud->waves->t_waves));
    sfText_setString(game->hud->waves->text, str);
    free(str);
}

void update_gold(s_game *game)
{
    char *str = my_itoa(game->hud->gold->gold);
    sfText_setString(game->hud->gold->text, str);
}

void restart(s_game *game)
{
    game->enemies = game->b_enemies;
    game->hud = game->b_hud;
    game->slots = game->b_slots;
    game->w_nb = -1;
    game->score = 0;
    sfText_setString(game->hud->score->text, my_itoa(game->score));
    update_waves(game);
    game->castles[game->levels]->life = 100;
    sfText_setString(game->castles[game->levels]->text,
    my_itoa( game->castles[game->levels]->life));
    game->castles[game->levels]->type = FULL;
    sfSprite_setTexture(game->castles[game->levels]->sprite,
    game->castles[game->levels]->texture[FULL], sfTrue);
    if (game->g_pause.paused == sfTrue)
        game->g_pause.paused = sfFalse;
}