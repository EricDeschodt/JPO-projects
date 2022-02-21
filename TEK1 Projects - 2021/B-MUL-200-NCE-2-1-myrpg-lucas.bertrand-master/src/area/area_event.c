/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** area_event
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int verif_fight(scene_t *area, char **map)
{
    int r = 0;
    int seed = rand () % 100;

    if (area[5].player->steps >= 100) {
        r = rand() % 3;
        srand(seed);
        area[5].player->steps = 0;
        if (map[0][0] != 'f' && r == 1 &&
            my_strcmp(sfText_getString(area[15].texts->text), "") == 0) {
            area[4].objs->rect.left += 640;
            sfSprite_setTextureRect(area[4].objs->my_sprite,
                                    area[4].objs->rect);
            return (1);
        }
    }
    return (0);
}

void menu_pause(scene_t *area, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == true
        && my_strcmp(sfText_getString(area[15].texts->text), "") == 0) {
        area[21].times->pause =! area[21].times->pause;
        sfSound_play(area[7].sounds->sound);
        sfSleep(sfSeconds(0.2));
    }
}

int analyse_events_area(sfRenderWindow *window, sfEvent event,
                         scene_t *area, char **map)
{
    sfKeyCode tab_1[5] = {sfKeyUp, sfKeyRight, sfKeyDown, sfKeyLeft,
                          sfKeySpace};
    sfKeyCode tab_2[5] = {sfKeyZ, sfKeyD, sfKeyS, sfKeyQ, sfKeySpace};
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (area[21].times->pause == true &&
            event.type == sfEvtMouseButtonPressed)
            return (button_is_clicked_pause(window, event, area, map));
        menu_pause(area, event);
        if (area[21].times->pause == false) {
            for (int i = 0; i != 5; i++)
                if (sfKeyboard_isKeyPressed(tab_1[i]) == true ||
                    sfKeyboard_isKeyPressed(tab_2[i]) == true)
                    return (i + 2);
        }
    }
    return (0);
}

int button_is_clicked_inventory(scene_t *area, sfVector2i click_pos)
{
    sfVector2i pos = {745, 270};
    sfVector2i pos_max = {1100, 320};

    for (int i = 0; area[5].player->item[i] != ' '; i++) {
        if (pos.x <= click_pos.x && pos_max.x >= click_pos.x
            && pos.y <= click_pos.y && pos_max.y >= click_pos.y)
            return (choose_object(area, i));
        pos.y += 75;
        pos_max.y += 75;
        if (i == 4) {
            pos.y = 270;
            pos_max.y = 320;
            pos.x = 1110;
            pos_max.x = 1460;
        }
    }
    return (0);
}

int button_is_clicked_pause(sfRenderWindow *window, sfEvent event,
                            scene_t * area, char **map)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    button_is_clicked_inventory(area, click_pos);
    music_area_pause(area, event, click_pos);
    if (click_pos.y >= 660 && click_pos.y <= 785) {
        if (click_pos.x >= 505 && click_pos.x <= 825) {
            save(area[5].player, map, map[0][0]);
            time_restart(area[21].times);
            sfText_setString(area[16].texts->text, "Sauvegarde effectuee.");
            sfSound_play(area[8].sounds->sound);
            return (0);
        }
        if (click_pos.x >= 830 && click_pos.x <= 1145) {
            sfSound_pause(area[6].sounds->sound);
            sfSound_play(area[7].sounds->sound);
            create_menu_one(window);
            return (1);
        } if (click_pos.x >= 1150 && click_pos.x <= 1470)
            return (1);
    }
    return (0);
}
