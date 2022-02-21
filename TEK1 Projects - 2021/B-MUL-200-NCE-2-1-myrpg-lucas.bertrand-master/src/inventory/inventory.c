/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** inventory
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *filled_inventory(char *save)
{
    char *item = malloc(sizeof(char) * 12);

    for (int i = 0, k = 35; i != 11; i++, k++) {
        if (save[k] >= '0' && save[k] <= ';')
            item[i] = save[k];
        else
            item[i] = ' ';
    }
    return (item);
}

int check_inventory(scene_t *area)
{
    for (int i = 0; area[5].player->item[i] != '\0'; i++)
        if ( area[5].player->item[i - 1] != ' ' && area[5].player->item[i] == ' '
             && area[5].player->item[i + 1] == '\0') {
            time_restart(area[21].times);
            sfSound_play(area[10].sounds->sound);
            sfText_setString(area[16].texts->text,
                             "Vous n'avez plus de place dans l'inventaire.");
            return (1);
        }
    return (0);
}

int wrong_item(scene_t *area, int i)
{
    if (area[5].player->item[i] >= '8' && ';' >= area[5].player->item[i]) {
        sfSound_play(area[10].sounds->sound);
        sfText_setString(area[16].texts->text,
                         "Vous ne pouvez pas utiliser cet objet ici.");
        time_restart(area[21].times);
        return (1);
    }
    return (0);
}

int choose_object(scene_t *area, int i)
{
    char *item = "01234567";
    void (*item_effect[8])(protagonist_t *) = {health_item_10, health_item_25, health_item_50,
        health_item_max, magic_item_5, magic_item_15, magic_item_30, magic_item_max};
    char *text[8] = {"Vous regagnez des pv.", "Vous regagnez des pv.", "Vous regagnez des pv.",
        "Vous regagnez des pv.", "Vous regagnez des pm.", "Vous regagnez des pm.",
        "Vous regagnez des pm.", "Vous regagnez des pm."};

    if (wrong_item(area, i) == 1)
        return (1);
    for (int j = 0; j != 8; j++)
        if (item[j] == area[5].player->item[i]) {
            item_effect[j](area[5].player);
            sfText_setString(area[16].texts->text, text[j]);
        }
    area[5].player->item[i] = ' ';
    sfSound_play(area[9].sounds->sound);
    time_restart(area[21].times);
    for ( ; area[5].player->item[i + 1] != '\0'; i++)
        area[5].player->item[i] = area[5].player->item[i + 1];
    return (1);
}
