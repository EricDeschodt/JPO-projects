/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** verif_boss
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int analyse_events_boss_fight(sfRenderWindow *window, sfEvent event,
                         scene_t *fight, int max)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    char stat[2][10];
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) == true &&
            fight[5].player->inventory == true)
            button_is_clicked_inventory_fight(fight, click_pos);
        int_to_str(stat[0], fight[5].player->pv, 2);
        int_to_str(stat[1], fight[5].player->pm, 2);
        sfText_setString(fight[30].texts->text, stat[0]);
        sfText_setString(fight[32].texts->text, stat[1]);
        if (fight[5].player->defense == false && fight[1].objs->rect.top == 400
            && my_strcmp(sfText_getString(fight[22].texts->text), "") == 0)
            return (verif_boss_click(window, fight, max));
    }
    return (0);
}

protagonist_t *before_boss_fight(protagonist_t *fighter, protagonist_t *player, int top)
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
    fighter->enemy_pv = 75 * ((top / 400) + 1);
    fighter->item = player->item;
    return (fighter);
}

void after_boss_fight(protagonist_t *fighter, protagonist_t *player)
{
    player->exp = fighter->exp;
    player->lvl = (fighter->exp / 100) + 1;
    player->pv = ((fighter->lvl - 1) * 10) + 20;
    player->pm = ((fighter->lvl - 1) * 5) + 10;
    player->item = fighter->item;
}

int verif_boss_victory(sfRenderWindow *window, scene_t *fight,
                       int *ret, int max)
{
    if (ret[3] != 2)
        ret[3] = draw_boss_fight_three(window, fight, ret);
    if (ret[3] == 1)
        return (ret[3]);
    else if (ret[3] == 2) {
        sfSound_stop(fight[6].sounds->sound);
        fight[5].player->attack = false;
        if (fight[37].times->seconds > 5)
            return (ret[3]);
    }
    return (0);
}

int verif_boss_click(sfRenderWindow *window, scene_t *fight, int max)
{
    sfVector2i click_position = sfMouse_getPositionRenderWindow(window);
    int ret = button_is_clicked_fight(window, fight, click_position);
    if (fight[5].player->attack == true
        && fight[5].player->defense == false && fight[5].player->inventory == false) {
        if (ret == 2)
            fight[5].player->attack = false;
        if (fight[1].objs->rect.top == 400)
            return (button_is_clicked_attack(fight, click_position, max));
    }if (fight[5].player->attack == false
         && fight[5].player->defense == false) {
        if (ret == 3 && my_strcmp(sfText_getString(fight[22].texts->text), "") == 0)
            fight[5].player->inventory = !fight[5].player->inventory;
        if (ret == -1 && fight[5].player->inventory == false
            && my_strcmp(sfText_getString(fight[22].texts->text), "") == 0) {
            time_restart(fight[37].times);
            sfText_setString(fight[22].texts->text, "Vous ne pouvez pas fuir.");
        }if (ret == 2 && fight[5].player->inventory == false)
             fight[5].player->attack = true;
    }
    return (0);
}
