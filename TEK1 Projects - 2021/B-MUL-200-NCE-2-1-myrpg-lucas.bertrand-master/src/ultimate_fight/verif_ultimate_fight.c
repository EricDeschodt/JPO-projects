/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int choose_object_ultimate_fight(scene_t *fight, int i)
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
            sfText_setString(fight[18].texts->text, text[j]);
            if (fight[5].player->pv > (((fight[5].player->lvl - 1) * 10) + 20) / 4)
                fight[1].objs->rect.left = 0;
            sfSprite_setTextureRect(fight[1].objs->my_sprite, fight[1].objs->rect);
        }
    time_restart(fight[33].times);
    fight[5].player->item[i] = ' ';
    for (; fight[5].player->item[i + 1] != '\0'; i++)
        fight[5].player->item[i] = fight[5].player->item[i + 1];
    sfSound_play(fight[10].sounds->sound);
    return (1);
}

int verif_ultimate_click(sfRenderWindow *window, scene_t *fight)
{
    sfVector2i click_position = sfMouse_getPositionRenderWindow(window);
    int ret = button_is_clicked_ultimate_fight(window, fight, click_position);
    if (fight[5].player->attack == true
        && fight[5].player->defense == false && fight[5].player->inventory == false) {
        if (ret == 2)
            fight[5].player->attack = false;
        if (fight[1].objs->rect.top == 400)
            return (button_is_clicked_ultimate_attack(fight, click_position));
    }
    if (fight[5].player->attack == false
         && fight[5].player->defense == false) {
        if (ret == 3 && my_strcmp(sfText_getString(fight[18].texts->text), "") == 0)
            fight[5].player->inventory = !fight[5].player->inventory;
        if (ret == 2 && fight[5].player->inventory == false)
             fight[5].player->attack = true;
    }
    return (0);
}

int ultimate_verif_enemy_attack(scene_t *fight)
{
    int r = rand() % 10;
    
    if (r == 4) {
        sfText_setString(fight[18].texts->text, "Coup critique!");
        return (1);
    }
    else if (r == 7) {
        sfText_setString(fight[18].texts->text, "Vous esquivez!");
        return (2);
    }
    else 
        sfText_setString(fight[18].texts->text, "L'ennemi attaque!");
    return (0);
}

int ultimate_verif_attack(scene_t *fight)
{
    int r = rand() % 10;

    if (r == 4)
        sfText_setString(fight[18].texts->text, "Coup critique!");
    else if (r == 7) {
        sfText_setPosition(fight[30].texts->text, create_v2f(-40, -40));
        sfText_setString(fight[18].texts->text, "L'ennemi esquive!");
        return (1);
    }
    return (0);
}

int ultimate_verif_mana(scene_t *fight, int i)
{
    char pm[10];
    int mana[4] = {0, 3, 7, 10};

    if (fight[5].player->pm >= mana[i]) {
        fight[5].player->pm -= mana[i];
        int_to_str(pm, fight[5].player->pm, 2);
        sfText_setString(fight[28].texts->text, pm);
        return (0);
    }
    else {
        sfSound_play(fight[9].sounds->sound);
        return (1);
    }
}
