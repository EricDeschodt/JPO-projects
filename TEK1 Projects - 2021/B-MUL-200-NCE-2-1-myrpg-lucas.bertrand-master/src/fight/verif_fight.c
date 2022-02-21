/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** verif_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int verif_enemy_attack(scene_t *fight)
{
    int r = rand() % 20;

    if (r == 4) {
        sfText_setString(fight[22].texts->text, "Coup critique!");
        return (1);
    }
    else if (r == 7) {
        sfText_setString(fight[22].texts->text, "Vous esquivez!");
        return (2);
    }
    else
        sfText_setString(fight[22].texts->text, "L'ennemi attaque!");
    return (0);
}

int verif_attack(scene_t *fight)
{
    int r = rand() % 20;

    if (r == 4)
        sfText_setString(fight[22].texts->text, "Coup critique!");
    else if (r == 7) {
        sfText_setPosition(fight[34].texts->text, create_v2f(-40, -40));
        sfText_setString(fight[22].texts->text, "L'ennemi esquive!");
        return (1);
    }
    return (0);
}

int verif_mana(scene_t *fight, int i)
{
    char pm[10];
    int mana[4] = {0, 3, 7, 10};

    if (fight[5].player->pm >= mana[i]) {
        fight[5].player->pm -= mana[i];
        int_to_str(pm, fight[5].player->pm, 2);
        sfText_setString(fight[32].texts->text, pm);
        return (0);
    }
    else {
        sfSound_play(fight[11].sounds->sound);
        return (1);
    }
}

int verif_victory(sfRenderWindow *window, scene_t *fight,
                  int *ret, int max)
{
    if (ret[3] != 2)
        ret[3] = draw_fight_three(window, fight, ret);
    if (ret[3] == 1)
        return (ret[3]);
    else if (ret[3] == 2) {
        sfSound_pause(fight[6].sounds->sound);
        if (fight[37].times->seconds > 5)
            return (ret[3]);
    }
    return (0);
}

int verif_click(sfRenderWindow *window, scene_t *fight, int max)
{
    sfVector2i click_position = sfMouse_getPositionRenderWindow(window);
    int ret = button_is_clicked_fight(window, fight, click_position);
    if (fight[5].player->attack == true && fight[5].player->defense == false
        && fight[5].player->inventory == false) {
        if (ret == 2) fight[5].player->attack = false;
        if (fight[1].objs->rect.top == 400)
            return (button_is_clicked_attack(fight, click_position, max));
    } if (fight[5].player->attack == false
          && fight[5].player->defense == false) {
        if (ret == 3 && my_strcmp(sfText_getString(fight[22].texts->text),
                                  "") == 0)
            fight[5].player->inventory = !fight[5].player->inventory;
        if (ret == -1 && fight[5].player->inventory == false
            && my_strcmp(sfText_getString(fight[22].texts->text), "") == 0) {
            time_restart(fight[37].times);
            sfText_setString(fight[22].texts->text, "Vous prenez la fuite.");
        } if (ret == 2 && fight[5].player->inventory == false)
              fight[5].player->attack = true;
    }
    return (0);
}
