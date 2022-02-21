/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_item
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void item_labo(scene_t *area, int x, int y)
{
    int pos_x[5] = {11, 25, 17, 1, 26};
    int pos_y[5] = {23, 33, 20, 25, 12};
    char *item = "373;3";
    char *text[5] = {"Vous obtenez une capsule de soin - pv max!",
        "Vous obtenez une capsule de magie - pm max!",
        "Vous obtenez une capsule de soin - pv max!",
        "Vous obtenez une capsule de defense - 3 tours!",
        "Vous obtenez une capsule de soin - pv max!"};

    for (int i = 0; item[i] != '\0'; i++)
        if (pos_x[i] == x && pos_y[i] == y)
            for (int j = 0; area[5].player->item[j] != '\0'; j++)
                if (area[5].player->item[j] == ' ') {
                    area[5].player->item[j] = item[i];
                    sfText_setString(area[16].texts->text, text[i]);
                    break;
                }
}

void item_crypt3(scene_t *area, int x, int y)
{
    int pos_x[4] = {11, 5, 20, 17};
    int pos_y[4] = {19, 29, 15, 7};
    char *item = "2693";
    char *text[4] = {"Vous obtenez une capsule de soin - 50 pv!",
        "Vous obtenez une capsule de magie - 30 pm!",
        "Vous obtenez une capsule d'attaque - 3 tours!",
        "Vous obtenez une capsule de soin - pv max!"};

    for (int i = 0; item[i] != '\0'; i++)
        if (pos_x[i] == x && pos_y[i] == y)
            for (int j = 0; area[5].player->item[j] != '\0'; j++)
                if (area[5].player->item[j] == ' ') {
                    area[5].player->item[j] = item[i];
                    sfText_setString(area[16].texts->text, text[i]);
                    break;
                }
}

void item_crypt2(scene_t *area, int x, int y)
{
    int pos_x[4] = {3, 22, 12, 13};
    int pos_y[4] = {24, 20, 11, 3};
    char *item = "51:8";
    char *text[4] = {"Vous obtenez une capsule de magie - 15 pm!",
        "Vous obtenez une capsule de soin - 25 pv!",
        "Vous obtenez une capsule de defense - 1 tour!",
        "Vous obtenez une capsule d'attaque - 1 tour!"};

    for (int i = 0; item[i] != '\0'; i++)
        if (pos_x[i] == x && pos_y[i] == y)
            for (int j = 0; area[5].player->item[j] != '\0'; j++)
                if (area[5].player->item[j] == ' ') {
                    area[5].player->item[j] = item[i];
                    sfText_setString(area[16].texts->text, text[i]);
                    break;
                }
}

void item_crypt1(scene_t *area, int x, int y)
{
    int pos_x[4] = {1, 26, 28, 28};
    int pos_y[4] = {20, 25, 16, 3};
    char *item = "181:";
    char *text[4] = {"Vous obtenez une capsule de soin - 25 pv!",
        "Vous obtenez une capsule d'attaque - 1 tour!",
        "Vous obtenez une capsule de soin - 25 pv!",
        "Vous obtenez une capsule de defense - 1 tour!"};

    for (int i = 0; item[i] != '\0'; i++)
        if (pos_x[i] == x && pos_y[i] == y)
            for (int j = 0; area[5].player->item[j] != '\0'; j++)
                if (area[5].player->item[j] == ' ') {
                    area[5].player->item[j] = item[i];
                    sfText_setString(area[16].texts->text, text[i]);
                    break;
                }
}

void get_item(scene_t *area, char **map, int x, int y)
{
    char *code = "123l";
    void (*new_item[4])(scene_t *, int, int) = {item_crypt1, item_crypt2,
        item_crypt3, item_labo};

    if (map[0][0] == 'f') {
        for (int i = 0; area[5].player->item[i] != '\0'; i++)
            if (area[5].player->item[i] == ' ') {
                area[5].player->item[i] = '0';
                break;
            }
        sfText_setString(area[16].texts->text, "Vous obtenez une capsule de soin - 10 pv!");
    }
    for (int i = 0; code[i] != '\0' ; i++)
        if (code[i] == map[0][0])
            new_item[i](area, x, y);
}
