/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** castle
*/

#include "defender.h"

s_castle *create_castle_object(char *filepath[], sfVector2f pos, e_type type)
{
    s_castle *obj = malloc(sizeof(*obj));
    obj->pos = pos;
    obj->type = type;
    for (int i = 0; i < 3; i++) {
        obj->texture[i] = sfTexture_createFromFile(filepath[i], NULL);
    }
    obj->sprite = sfSprite_create();
    obj->life = 1000;
    obj->font = sfFont_createFromFile("res/fonts/pondesora.ttf");
    obj->text = sfText_create();
    sfText_setFont(obj->text, obj->font);
    sfText_setString(obj->text, my_itoa(obj->life));
    sfText_setColor(obj->text, sfRed);
    sfText_setPosition(obj->text, (v2){obj->pos.x + 70, obj->pos.y - 50});
    sfSprite_setTexture(obj->sprite, obj->texture[0], sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

void create_castles(s_game *game)
{
    char *path[] = {"sprites/castle_full.png", "sprites/castle_half.png",
    "sprites/castle_destroyed.png"};
    int posx[] = {1720, 1720, 1720, 1720, 1720};
    int posy[] = {200, 200, 630, 0, 0};
    for (int j = 0; j < 5; j++) {
            game->castles[j] = create_castle_object(path,
            (sfVector2f){posx[j], posy[j]}, CASTLE);
    }
}

void draw_castle(s_game *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->castles[game->levels]->sprite, NULL);
}

void init_game_struct(s_game *game)
{
    game->best = malloc(sizeof(char) * 10000);
    game->best[0] = '\0', game->framerate = 60;
    game->released = sfFalse, game->paused_time = 0;
    game->m = 0.1f;
    game->g_pause.paused = sfFalse;
    game->menu = malloc(sizeof(menu_t));
    game->state = MENU;
    game->menu->pages_state = -1, game->levels = MAP1;
    game->castle_states = FULL, game->w_nb = -1;
    for (int i = 0; i < 4; i++) {
        game->wave_nbs[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        game->w_len[i] = 0;
    }
    for (int i = 0; i < 3; i++) {
        game->bestscores[i] = 0;
    }
    game->score = 0, game->upgr = sfFalse;
}