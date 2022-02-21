/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** menu_event
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int analyse_events_menu_two(sfRenderWindow *window, sfEvent event,
                             scene_t *menu, int ret)
{
    if (event.type == sfEvtClosed || ret == 2) {
        sfRenderWindow_close(window);
        return (1);
    }
    else if (ret == 1) {
        sfSound_pause(menu[2].sounds->sound);
        sfSound_play(menu[4].sounds->sound);
        open_save(window);
        return (1);
    }
    if (ret == 4)
        eric_mode();
    else if (ret == 6)
        erase_save();
    return (0);
}

int analyse_events_menu_one(sfRenderWindow *window, sfEvent event,
                        scene_t *menu, bool *option)
{
    sfVector2i click_position = sfMouse_getPositionRenderWindow(window);
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (option[0] == false)
            ret = button_is_clicked_menu_one(menu, click_position);
        else
            ret = button_is_clicked_menu_two(menu, click_position);
        if (ret == 0 )
            sfText_setString(menu[12].texts->text, "");
        if (analyse_events_menu_two(window, event, menu, ret) == 1)
            return (1);
        if (option[1] == true && sfMouse_isButtonPressed(sfMouseLeft) == true)
            return (5);
        music_menu_pause(menu, event, click_position);
    }
    return (ret);
}

int button_is_clicked_menu_one(scene_t *menu, sfVector2i click_position)
{
    sfVector2f pos[2];
    sfVector2f size[2];
    sfVector2f pos_max[2];

    for (int i = 0; i != 2; i++) {
        pos[i] = sfRectangleShape_getPosition(menu[i + 6].buttons->rect);
        size[i] = sfRectangleShape_getSize(menu[i + 6].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(menu[i + 6].buttons, menu[i + 13].texts, 700) == 1)
                return (i + 1);
        }
        else
            put_button_back(menu[i + 6].buttons, menu[i + 13].texts, 685);
    }
    return (button_is_clicked_option(menu, click_position));
}

int button_is_clicked_menu_two(scene_t *menu, sfVector2i click_position)
{
    sfVector2f pos[3];
    sfVector2f size[3];
    sfVector2f pos_max[3];
    int ret = 0;
    for (int i = 0; i != 3; i++) {
        pos[i] = sfRectangleShape_getPosition(menu[i + 9].buttons->rect);
        size[i] = sfRectangleShape_getSize(menu[i + 9].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            ret = verif_option(menu, i);
            if (three_states_button(menu[i + 9].buttons, menu[i + 16].texts, 650) == 1) {
                sfText_setString(menu[12].texts->text, "");
                sfSound_play(menu[3].sounds->sound);
                return (i + 4);
            }
        } else
            put_button_back(menu[i + 9].buttons, menu[i + 16].texts, 635);
    } if (ret != 0)
          return (ret);
    return (button_is_clicked_option(menu, click_position));
}

int button_is_clicked_option(scene_t *menu, sfVector2i click_position)
{
    sfVector2f pos = sfRectangleShape_getPosition(menu[8].buttons->rect);
    sfVector2f size = sfRectangleShape_getSize(menu[8].buttons->rect);
    sfVector2f pos_max  = create_v2f(pos.x + size.x, pos.y + size.y);

    if (pos.x <= click_position.x && pos_max.x >= click_position.x &&
        pos.y <= click_position.y && pos_max.y >= click_position.y) {
        if (three_states_button(menu[8].buttons, menu[15].texts, 825) == 1) {
            sfSound_play(menu[3].sounds->sound);
            return (3);
        }
    }
    else
        put_button_back(menu[8].buttons, menu[15].texts, 810);
}
