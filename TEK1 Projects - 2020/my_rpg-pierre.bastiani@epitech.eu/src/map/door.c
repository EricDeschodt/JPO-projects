/*
** EPITECH PROJECT, 2020
** print
** File description:
** map
*/

#include "../../include/include.h"

void print_door(sfRenderWindow *window, players *player, s_game *game)
{
    sfSprite_setPosition(player->door->sprit_cave,
    (sfVector2f){8064 - player->pos_x - 96, 3936 - player->pos_y - 96});
    sfSprite_setPosition(player->door->sprit_door,
    (sfVector2f){6336 - player->pos_x - 96, 3072 - player->pos_y - 96});
    sfSprite_setPosition(player->door->sprit_door2,
    (sfVector2f){4896 - player->pos_x - 96, 4704 - player->pos_y - 96});
    sfSprite_setPosition(player->door->sprit_tree,
    (sfVector2f){4992 - player->pos_x - 96, 3168 - player->pos_y - 96});
    if (player->inv->pick == false)
        sfRenderWindow_drawSprite(window, player->door->sprit_cave, NULL);
    if (player->inv->key == false || game->statment == 12)
        sfRenderWindow_drawSprite(window, player->door->sprit_door, NULL);
    if (player->inv->map == false || game->statment == 10)
        sfRenderWindow_drawSprite(window, player->door->sprit_tree, NULL);
    if (player->inv->troph == false || player->state != 20)
        sfRenderWindow_drawSprite(window, player->door->sprit_door2, NULL);

}

void init_door(players *player)
{
    player->door = malloc(sizeof(doors));
    player->door->text_cave = sfTexture_createFromFile("assets/cave.png", NULL);
    player->door->text_door = sfTexture_createFromFile("assets/door.png", NULL);
    player->door->text_door2 =
    sfTexture_createFromFile("assets/door2.png", NULL);
    player->door->text_tree = sfTexture_createFromFile("assets/tree.png", NULL);
    player->door->sprit_cave = sfSprite_create();
    player->door->sprit_door = sfSprite_create();
    player->door->sprit_door2 = sfSprite_create();
    player->door->sprit_tree = sfSprite_create();
    sfSprite_setTexture(player->door->sprit_cave, player->door->text_cave, 0);
    sfSprite_setTexture(player->door->sprit_door, player->door->text_door, 0);
    sfSprite_setTexture(player->door->sprit_door2, player->door->text_door2, 0);
    sfSprite_setTexture(player->door->sprit_tree, player->door->text_tree, 0);
}