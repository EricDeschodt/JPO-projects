/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** inventory
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int choose_object_fight(scene_t *fight, int i)
{
    char *item = "0123456789:;";
    void (*item_effect[12])(protagonist_t *) = {health_item_10, health_item_25, health_item_50,
        health_item_max, magic_item_5, magic_item_15, magic_item_30, magic_item_max,
        attack_up_1, attack_up_3, defense_up_1, defense_up_3};
    char *text[12] = {"vous regagnez des pv.", "vous regagnez des pv.", "vous regagnez des pv.",
        "vous regagnez des pv.", "vous regagnez des pm.", "vous regagnez des pm.",
        "vous regagnez des pm.", "vous regagnez des pm.", "Votre attaque augmente!",
        "Votre attaque augmente!", "Votre defense augmente!", "Votre defense augmente!"};
    for (int j = 0; j != 12; j++)
        if (item[j] == fight[5].player->item[i]) {
            item_effect[j](fight[5].player);
            fight[5].player->inventory = false;
            sfText_setString(fight[22].texts->text, text[j]);
            if (fight[5].player->pv > (((fight[5].player->lvl - 1) * 10) + 20) / 4)
                fight[1].objs->rect.left = 0;
            sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        } time_restart(fight[37].times);
    fight[5].player->item[i] = ' ';
    for (; fight[5].player->item[i + 1] != '\0'; i++)
        fight[5].player->item[i] = fight[5].player->item[i + 1];
    sfSound_play(fight[12].sounds->sound);
    return (1);
}

void attack_up_1(protagonist_t *player)
{
    player->attack_up = 1;
}

void attack_up_3(protagonist_t *player)
{
    player->attack_up = 3;
}

void defense_up_1(protagonist_t *player)
{
    player->defense_up = 1;
}

void defense_up_3(protagonist_t *player)
{
    player->defense_up = 3;
}
