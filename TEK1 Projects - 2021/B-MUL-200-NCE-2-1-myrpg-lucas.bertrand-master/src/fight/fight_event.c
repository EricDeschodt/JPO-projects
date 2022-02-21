/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_event
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int analyse_events_fight(sfRenderWindow *window, sfEvent event,
                         scene_t *fight, int max)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    char stat[2][10];
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfSound_stop(fight[6].sounds->sound);
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
            return (verif_click(window, fight, max));
    }
    return (0);
}

int button_is_clicked_inventory_fight(scene_t *fight, sfVector2i click_pos)
{
    sfVector2i pos = {660, 100};
    sfVector2i pos_max = {1015, 175};

    for (int i = 0; fight[5].player->item[i] != ' '; i++) {
        if (pos.x <= click_pos.x && pos_max.x >= click_pos.x
            && pos.y <= click_pos.y && pos_max.y >= click_pos.y)
            return (choose_object_fight(fight, i));
        pos.y += 75;
        pos_max.y += 75;
        if (i == 4) {
            pos.y = 100;
            pos_max.y = 175;
            pos.x = 1015;
            pos_max.x = 1375;
        }
    }
    return (0);
}

int button_is_clicked_attack(scene_t *fight, sfVector2i click_position, int max)
{
    sfVector2f pos_max[max], pos[max], size[max];
    for (int i = 0, j = 150; i < max; i++, j += 100) {
        pos[i] = sfRectangleShape_getPosition(fight[i + 18].buttons->rect);
        size[i] = sfRectangleShape_getSize(fight[i + 18].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(fight[i + 18].buttons, fight[i + 26].texts,
                                    915) == 1) {
                fight[1].objs->rect.left = 0;
                if (verif_mana(fight, i) == 0)
                    return (i + 10);
            }
        }
        else
            put_button_back(fight[i + 18].buttons, fight[i + 26].texts, 930);
    }
    return (0);
}

int button_is_clicked_fight(sfRenderWindow *window, scene_t *fight,
                            sfVector2i click_position)
{
    sfVector2f pos_max[3], pos[3], size[3];
    for (int i = 0; i < 3; i++) {
        pos[i] = sfRectangleShape_getPosition(fight[i + 15].buttons->rect);
        size[i] = sfRectangleShape_getSize(fight[i + 15].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(fight[i + 15].buttons,
                                    fight[i + 23].texts, 700) == 1) {
                sfSound_play(fight[10].sounds->sound);
                if (i == 2)
                    return (-1);
                return (i + 2);
            }
        }
        else
            put_button_back(fight[i + 15].buttons, fight[i + 23].texts, 685);
    }
    return (0);
}
