/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void draw_inventory_fight(sfRenderWindow *window, char *inventory,
                          object_t *item, object_t *board)
{
    sfRenderWindow_drawSprite(window, board->my_sprite, NULL);
    if (inventory[0] == ' ')
      return;
    item->pos.x = 660;
    item->pos.y = 100;
    sfSprite_setPosition(item->my_sprite, item->pos);
    for (int i = 0; inventory[i - 1] != ' '; i++) {
        sfRenderWindow_drawSprite(window, item->my_sprite, NULL);
        item->rect.top = (inventory[i] - 48) * 50;
        sfSprite_setTextureRect(item->my_sprite, item->rect);
        sfSprite_setPosition(item->my_sprite, item->pos);
        item->pos.y += 75;
        if (i == 4) {
            item->pos.x = 1015;
            item->pos.y = 100;
        }
    }
}

int draw_fight_three(sfRenderWindow *window, scene_t *fight, int *ret)
{
    if (my_strcmp(sfText_getString(fight[22].texts->text), "") != 0
        && fight[37].times->seconds > 1.5) {
        fight[5].player->defense = true;
        fight[5].player->attack = false;
        sfText_setString(fight[22].texts->text, "");
    }
    if (fight[5].player->defense == true) {
        if (my_strcmp(sfText_getString(fight[22].texts->text), "") == 0)
            if (fight[5].player->victory == true) {
                sfSound_play(fight[7].sounds->sound);
                sfSound_play(fight[13].sounds->sound);
                return (victory(fight));
            }
        fight[5].player->attack = false;
        ret[1] = animattack_enemy(window, fight, ret);
        if (ret[1] == 1)
            return (1);
    }
    return (0);
}

void draw_fight_two(sfRenderWindow *window, scene_t *fight, int *ret, int max)
{
    sfRenderWindow_drawSprite(window, fight[0].objs->my_sprite, NULL);
    if (fight[1].objs->rect.top == 400) defense(window, fight);
    sfRenderWindow_drawSprite(window, fight[1].objs->my_sprite, NULL);
    if (ret[3] != 2)
        sfRenderWindow_drawSprite(window, fight[2].objs->my_sprite, NULL);
    for (int i = 14; i != 18; i++)
        sfRenderWindow_drawRectangleShape(window, fight[i].buttons->rect, NULL);
    for (int i = 22; i != 26; i++)
        sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    if (fight[5].player->attack == true && fight[1].objs->rect.top == 400) {
        for (int i = 18, j = 0; j != max; i++, j++)
            sfRenderWindow_drawRectangleShape(window,
                                              fight[i].buttons->rect, NULL);
        for (int i = 26, j = 0; j != max; i++, j++)
            sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    } for (int i = 30; i != 37; i++)
          sfRenderWindow_drawText(window, fight[i].texts->text, NULL);
    if (fight[5].player->inventory == true)
        draw_inventory_fight(window, fight[5].player->item,
                             fight[4].objs, fight[3].objs);
}

int draw_fight_one(sfRenderWindow *window, scene_t *fight, int max)
{
    sfEvent event;
    int ret[4] = {0, 0, 0, 0};
    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        ret[0] = analyse_events_fight(window, event, fight, max);
        if (ret[0] == 1) return (1);
        if (my_strcmp(sfText_getString(fight[22].texts->text),
                   "Vous prenez la fuite.") == 0
            && fight[37].times->seconds > 1.25)
            break;
        time_increase(fight[37].times);
        if (ret[0] >= 10 && ret[0] <= 13 || fight[1].objs->rect.top != 400
            && fight[5].player->attack == true)
            ret[2] = choose_attack(window, fight, ret[0]);
        draw_fight_two(window, fight, ret, max);
        ret[1] = verif_victory(window, fight, ret, max);
        if (ret[1] != 0)
            return (ret[1]);
    }
}
