/*
** EPITECH PROJECT, 2020
** inv
** File description:
** entory
*/

#include "../../include/include.h"

void init_inventory4(players *player)
{
    char *filepath[] = {"assets/inventaire/0.png", "assets/inventaire/1.png",
    "assets/inventaire/2.png", "assets/inventaire/3.png",
    "assets/inventaire/4.png", "assets/inventaire/5.png",
    "assets/inventaire/6.png", "assets/inventaire/7.png",
    "assets/inventaire/8.png", "assets/inventaire/9.png",
    "assets/inventaire/10.png"};
    for (int i = 0; i < 11; i++)
        player->inv->text_xp_bar[i] =
    sfTexture_createFromFile(filepath[i], NULL);
    player->inv->text_xp_bar[11] = NULL;
    player->inv->xp_bar = sfSprite_create();
    sfSprite_setPosition(player->inv->xp_bar, (sfVector2f){690, 1010});
    sfSprite_setScale(player->inv->xp_bar, (sfVector2f){2, 2});
}

void init_inventory3(players *player)
{
    sfSprite_setTexture(player->inv->sprit_map, player->inv->text_map, 0);
    sfSprite_setTexture(player->inv->sprit_pick, player->inv->text_pick, 0);
    sfSprite_setPosition(player->inv->sprit_troph, (sfVector2f){1003, 832});
    sfSprite_setPosition(player->inv->sprit_punch, (sfVector2f){994, 603});
    sfSprite_setPosition(player->inv->sprit_kick, (sfVector2f){750, 603});
    sfSprite_setPosition(player->inv->sprit_strangle, (sfVector2f){994, 668});
    sfSprite_setPosition(player->inv->sprit_head, (sfVector2f){750, 668});
    sfSprite_setPosition(player->inv->sprit_key, (sfVector2f){918, 831});
    sfSprite_setPosition(player->inv->sprit_map, (sfVector2f){828, 838});
    sfSprite_setPosition(player->inv->sprit_pick, (sfVector2f){743, 834});
    player->inv->text_xp_bar = malloc(sizeof(sfTexture *) * 12);
    player->inv->xp_txt = sfText_create();
    player->inv->lvl_txt = sfText_create();
    sfText_setPosition(player->inv->xp_txt, (sfVector2f){940, 900});
    sfText_setPosition(player->inv->lvl_txt, (sfVector2f){590, 290});
    sfText_setFont(player->inv->xp_txt, player->font);
    sfText_setFont(player->inv->lvl_txt, player->font);
    sfText_setCharacterSize(player->inv->xp_txt, 100);
    sfText_setCharacterSize(player->inv->lvl_txt, 70);
    init_inventory4(player);
}

void init_inventory2(players *player)
{
    player->inv->text_pick =
    sfTexture_createFromFile("assets/item/pioche.png", NULL);
    player->inv->text_troph =
    sfTexture_createFromFile("assets/item/troph.png", NULL);
    player->inv->sprit_punch = sfSprite_create();
    player->inv->sprit_kick = sfSprite_create();
    player->inv->sprit_strangle = sfSprite_create();
    player->inv->sprit_troph = sfSprite_create();
    player->inv->sprit_head = sfSprite_create();
    player->inv->sprit_key = sfSprite_create();
    player->inv->sprit_map = sfSprite_create();
    player->inv->sprit_pick = sfSprite_create();
    sfSprite_setTexture(player->inv->sprit_troph, player->inv->text_troph, 0);
    sfSprite_setTexture(player->inv->sprit_punch, player->inv->text_punch, 0);
    sfSprite_setTexture(player->inv->sprit_kick, player->inv->text_kick, 0);
    sfSprite_setTexture(player->inv->sprit_strangle,
    player->inv->text_strangle, 0);
    sfSprite_setTexture(player->inv->sprit_head, player->inv->text_head, 0);
    sfSprite_setTexture(player->inv->sprit_key, player->inv->text_key, 0);
    init_inventory3(player);
}

void init_inventory(players *player)
{
    player->inv = malloc(sizeof(inventory));
    player->inv->xp = 0;
    player->inv->lvl = 0;
    player->inv->pick = false;
    player->inv->map = false;
    player->inv->key = false;
    player->inv->troph = true;
    player->inv->text_punch =
    sfTexture_createFromFile("assets/comp/punch.png", NULL);
    player->inv->text_kick =
    sfTexture_createFromFile("assets/comp/kick.png", NULL);
    player->inv->text_strangle =
    sfTexture_createFromFile("assets/comp/strangle.png", NULL);
    player->inv->text_head =
    sfTexture_createFromFile("assets/comp/head.png", NULL);
    player->inv->text_key =
    sfTexture_createFromFile("assets/item/clé.png", NULL);
    player->inv->text_map =
    sfTexture_createFromFile("assets/item/map.png", NULL);
    init_inventory2(player);
}