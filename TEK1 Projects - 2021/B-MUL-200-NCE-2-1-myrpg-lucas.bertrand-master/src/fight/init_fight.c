/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

protagonist_t *before_fight(protagonist_t *fighter,
                            protagonist_t *player, int top)
{
    fighter = malloc(sizeof(protagonist_t));
    fighter->exp = player->exp;
    fighter->lvl = player->lvl;
    fighter->pv = player->pv;
    fighter->pm = player->pm;
    fighter->attack = false;
    fighter->defense = false;
    fighter->inventory = false;
    fighter->victory = false;
    fighter->attack_up = 0;
    fighter->defense_up = 0;
    fighter->enemy_pv = 15 * ((top / 100) + 1);
    fighter->item = player->item;
    return (fighter);
}

void after_fight(protagonist_t *fighter, protagonist_t *player)
{
    player->exp = fighter->exp;
    player->lvl = (fighter->exp / 100) + 1;
    player->pv = fighter->pv;
    player->pm = fighter->pm;
    player->item = fighter->item;
}

int init_fight(sfRenderWindow *window, scene_t *area, char **map)
{
    char *code = "123l";
    int ret = 0;

    for (int i = 0; i != 4; i++)
        if (map[0][0] == code[i]) {
            ret = create_fight_one(window, i, area[5].player,
                                   area[6].sounds->pause);
            if (ret == 1)
                return (1);
        }
}

int transition(sfRenderWindow *window, scene_t *area, char **map)
{
    if (area[4].objs->rect.left == 640) {
        sfSound_pause(area[6].sounds->sound);
        sfSound_play(area[12].sounds->sound);
    }
    if (area[4].objs->rect.left == 5120) {
        sfSound_pause(area[6].sounds->sound);
        sfRenderWindow_clear(window, sfBlack);
        if (init_fight(window, area, map) == 1)
            return (1);
        area[4].objs->rect.left = 0;
        sfSprite_setTextureRect(area[4].objs->my_sprite, area[4].objs->rect);
        if (area[6].sounds->pause == false)
            sfSound_play(area[6].sounds->sound);
        return (0);
    } if (area[21].times->seconds >= 0.075) {
        area[4].objs->rect.left += 640;
        sfSprite_setTextureRect(area[4].objs->my_sprite, area[4].objs->rect);
        sfClock_restart(area[21].times->clock);
    }
    return (0);
}
