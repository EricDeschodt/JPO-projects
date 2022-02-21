/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int analyse_event_ultimate_fight(sfRenderWindow *window, sfEvent event, scene_t *fight)
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
            button_is_clicked_inventory_ultimate_fight(fight, click_pos);
        int_to_str(stat[0], fight[5].player->pv, 2);
        int_to_str(stat[1], fight[5].player->pm, 2);
        sfText_setString(fight[26].texts->text, stat[0]);
        sfText_setString(fight[28].texts->text, stat[1]);
        if (fight[5].player->defense == false && fight[1].objs->rect.top == 400
            && my_strcmp(sfText_getString(fight[18].texts->text), "") == 0)
            return (verif_ultimate_click(window, fight));
    }
    return (0);
}

int button_is_clicked_inventory_ultimate_fight(scene_t *fight, sfVector2i click_pos)
{
    sfVector2i pos = {285, 225};
    sfVector2i pos_max = {650, 300};

    for (int i = 0; fight[5].player->item[i] != ' '; i++) {
        if (pos.x <= click_pos.x && pos_max.x >= click_pos.x
            && pos.y <= click_pos.y && pos_max.y >= click_pos.y)
            return (choose_object_ultimate_fight(fight, i));
        pos.y += 75;
        pos_max.y += 75;
        if (i == 4) {
            pos.y = 225;
            pos_max.y = 300;
            pos.x = 640;
            pos_max.x = 990;
        }
    }
    return (0);
}


int choose_ultimate_attack(sfRenderWindow *window,
                   scene_t * fight, int ret)
{
    if (ret == 14 || ret == 0)
        ret = 10 + (fight[1].objs->rect.top / 100);
    switch (ret) {
    case 10:
        fight[1].objs->rect.top = 0;
        ultimate_animattack(window,fight);
        return (1);
    case 11:
        fight[1].objs->rect.top = 100;
        ultimate_animattack(window, fight);
        return (2);
    case 12:
        fight[1].objs->rect.top = 200;
        ultimate_animattack(window, fight);
        return (3);
    case 13:
        fight[1].objs->rect.top = 300;
        ultimate_animattack(window, fight);
        return (4);
    }
}

int button_is_clicked_ultimate_attack(scene_t *fight, sfVector2i click_position)
{
    sfVector2f pos_max[4], pos[4], size[4];
    for (int i = 0, j = 150; i < 4; i++, j += 100) {
        pos[i] = sfRectangleShape_getPosition(fight[i + 14].buttons->rect);
        size[i] = sfRectangleShape_getSize(fight[i + 14].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(fight[i + 14].buttons, fight[i + 22].texts, 535) == 1) {
                fight[1].objs->rect.left = 0;
                if (ultimate_verif_mana(fight, i) == 0)
                    return (i + 10);
            }
        }
        else
            put_button_back(fight[i + 14].buttons, fight[i + 22].texts, 550);
    }
    return (0);
}


int button_is_clicked_ultimate_fight(sfRenderWindow *window, scene_t *fight, sfVector2i click_position)
{
    sfVector2f pos_max[2], pos[2], size[2];
    for (int i = 0; i < 2; i++) {
        pos[i] = sfRectangleShape_getPosition(fight[i + 12].buttons->rect);
        size[i] = sfRectangleShape_getSize(fight[i + 12].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(fight[i + 12].buttons, fight[i + 20].texts, 700) == 1) {
                sfSound_play(fight[8].sounds->sound);
                if (i == 2)
                    return (-1);
                return (i + 2);
            }
        }
        else
            put_button_back(fight[i + 12].buttons, fight[i + 20].texts, 685);
    }
    return (0);
}
