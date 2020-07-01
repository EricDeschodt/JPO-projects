/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_attack
*/

#include "defender.h"

int is_inRange(s_slot *slot, s_mob *mob)
{
    float distance = sqrt(pow((slot->pos.x - mob->pos.x), 2) +
    pow((slot->pos.y - mob->pos.y), 2));
    if (distance < slot->range)
        return 0;
    return (-1);
}

s_life *castle_hud(s_game *game)
{
    s_life *obj = malloc(sizeof(*obj));
    obj->life = game->castles[game->levels]->life;
    obj->pos = (sfVector2f){500, 6};
    obj->texture = sfTexture_createFromFile("sprites/heart.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    obj->hp = sfRectangleShape_create();
    obj->rect.width = 100, obj->rect.height = 15,
    obj->rect.top = 0, obj->rect.left = 0;
    sfRectangleShape_setSize(obj->hp, (v2){1000, 15});
    sfRectangleShape_setFillColor(obj->hp, sfGreen);
    sfRectangleShape_setTextureRect(obj->hp, obj->rect);
    sfRectangleShape_setPosition(obj->hp, (v2){obj->pos.x + 50,
    obj->pos.y + 8});
    return (obj);
}

s_waves *wave_hud(s_game *game)
{
    s_waves *obj = malloc(sizeof(*obj));
    obj->font = sfFont_createFromFile("res/fonts/pondesora.ttf");
    obj->text = sfText_create();
    sfText_setString(obj->text, "0/5");
    sfText_setScale(obj->text, (sfVector2f){.5, .5});
    sfText_setFont(obj->text, obj->font);
    sfText_setPosition(obj->text, (sfVector2f){360, 14});
    sfText_setColor(obj->text, sfWhite);
    obj->w_nb = game->w_nb;
    obj->t_waves = 5;
    obj->pos = (sfVector2f){300, 2};
    obj->texture = sfTexture_createFromFile("sprites/skull.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

s_gld *gold_hud(s_game *game)
{
    s_gld *obj = malloc(sizeof(*obj));
    obj->gold = 10000;
    obj->font = sfFont_createFromFile("res/fonts/pondesora.ttf");
    obj->text = sfText_create();
    sfText_setScale(obj->text, (sfVector2f){.5, .5});
    sfText_setFont(obj->text, obj->font);
    sfText_setPosition(obj->text, (sfVector2f){160, 14});
    sfText_setColor(obj->text, sfWhite);
    sfText_setString(obj->text, "10000");
    obj->pos = (sfVector2f){100, 2};
    obj->texture = sfTexture_createFromFile("sprites/gold.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

s_scr *score_hud(s_game *game)
{
    s_scr *obj = malloc(sizeof(*obj));
    obj->score = 0;
    obj->text = init_text();
    put_text(&obj->text, my_itoa(obj->score), (v2){1600, 14}, 16);
    return (obj);
}
