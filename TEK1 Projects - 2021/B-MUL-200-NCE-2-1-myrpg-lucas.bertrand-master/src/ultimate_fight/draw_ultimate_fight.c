/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void draw_inventory_ultimate_fight(sfRenderWindow *window, char *inventory,
                                   object_t *item, object_t *board)
{
    
    sfRenderWindow_drawSprite(window, board->my_sprite, NULL);
    if (inventory[0] == ' ')
        return;
    item->pos.x = 285;
    item->pos.y = 225;
    sfSprite_setPosition(item->my_sprite, item->pos);
    for (int i = 0; inventory[i - 1] != ' '; i++) {
        sfRenderWindow_drawSprite(window, item->my_sprite, NULL);
        item->rect.top = (inventory[i] - 48) * 50;
        sfSprite_setTextureRect(item->my_sprite, item->rect);
        sfSprite_setPosition(item->my_sprite, item->pos);
        item->pos.y += 75;
        if (i == 4) {
            item->pos.x = 640;
            item->pos.y = 225;
        }
    }
}

int draw_ultimate_fight_three(sfRenderWindow *window, scene_t *fight,
                              int *ret, sound_t *music)
{
    if (my_strcmp(sfText_getString(fight[18].texts->text), "") != 0
        && fight[33].times->seconds > 1.5) {
        fight[5].player->defense = true;
        fight[5].player->attack = false;
        sfText_setString(fight[18].texts->text, "");
    }
    if (my_strcmp(sfText_getString(fight[19].texts->text), "") != 0
        && fight[33].times->seconds > 0.4)
        sfText_setString(fight[19].texts->text, "");
    if (fight[5].player->defense == true &&
        my_strcmp(sfText_getString(fight[19].texts->text), "") == 0) {
        fight[5].player->attack = false;
        ret[1] = epilepsie_lazer(window, fight, music);
        if (ret[1] == 1)
            return (ret[1]);
    }
    if (fight[5].player->victory == true)
        return (2);
    return (0);
}

void draw_ultimate_fight_two(sfRenderWindow *window, scene_t *fight)
{
    if (fight[1].objs->rect.top == 400)
        ultimate_defense(fight);
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(window, fight[i].objs->my_sprite, NULL);
    for (int i = 11; i != 14; i++)
        sfRenderWindow_drawRectangleShape(window, fight[i].buttons->rect, NULL);
    for (int i = 18; i != 22; i++)
        sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    if (fight[5].player->attack == true && fight[1].objs->rect.top == 400) {
        for (int i = 14, j = 0; j != 4; i++, j++)
            sfRenderWindow_drawRectangleShape(window, fight[i].buttons->rect, NULL);
        for (int i = 22, j = 0; j != 4; i++, j++)
            sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    }
    for (int i = 26; i != 32; i++)
        sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    if (fight[5].player->inventory == true)
        draw_inventory_ultimate_fight(window, fight[5].player->item, fight[4].objs, fight[3].objs);
}

int draw_ultimate_fight_one(sfRenderWindow *window, scene_t *fight,
                            sound_t *music)
{
    sfEvent event;
    int ret[4] = {0, 0, 0, 0};
    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        ret[0] = analyse_event_ultimate_fight(window, event, fight);
        if (ret[0] == 1)
            return (1);
        for (int i = 33; i != 36; i++)
            time_increase(fight[i].times);
        epilepsie(fight);
        if (ret[0] >= 10 && ret[0] <= 13 || fight[1].objs->rect.top != 400
            && fight[5].player->attack == true)
            ret[2] = choose_ultimate_attack(window, fight, ret[0]);
        draw_ultimate_fight_two(window, fight);
        ret[1] = draw_ultimate_fight_three(window, fight, ret, music);
        if (ret[1] != 0)
            return (ret[1]);
    }        
}
