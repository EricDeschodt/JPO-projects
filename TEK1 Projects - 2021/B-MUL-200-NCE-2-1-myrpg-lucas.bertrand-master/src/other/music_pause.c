/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** music_pause
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void music_menu_pause(scene_t *menu, sfEvent event, sfVector2i click_position)
{
    if (event.type == sfEvtMouseButtonPressed &&
        0 <= click_position.x && 100 >= click_position.x &&
        0 <= click_position.y && 100 >= click_position.y) {
        if (menu[2].sounds->pause == false) {
            sfSound_play(menu[3].sounds->sound);
            menu[19].objs->rect.left = 200;
            sfSprite_setTextureRect(menu[19].objs->my_sprite, menu[19].objs->rect);
            sfSound_pause(menu[2].sounds->sound);
            menu[2].sounds->pause = true;
            return;
        }
        else {
            sfSound_play(menu[3].sounds->sound);
            menu[19].objs->rect.left = 0;
            sfSprite_setTextureRect(menu[19].objs->my_sprite, menu[19].objs->rect);
            sfSound_play(menu[2].sounds->sound);
            menu[2].sounds->pause = false;
            return;
        }
    }
}

void music_area_pause(scene_t *area, sfEvent event, sfVector2i click_position)
{
    if (event.type == sfEvtMouseButtonPressed &&
        0 <= click_position.x && 100 >= click_position.x &&
        0 <= click_position.y && 100 >= click_position.y) {
        if (area[6].sounds->pause == false) {
            sfSound_play(area[7].sounds->sound);
            area[22].objs->rect.left = 200;
            sfSprite_setTextureRect(area[22].objs->my_sprite, area[22].objs->rect);
            sfSound_pause(area[6].sounds->sound);
            area[6].sounds->pause = true;
            return;
        }
        else {
            sfSound_play(area[7].sounds->sound);
            area[22].objs->rect.left = 0;
            sfSprite_setTextureRect(area[22].objs->my_sprite, area[22].objs->rect);
            sfSound_play(area[6].sounds->sound);
            area[6].sounds->pause = false;
            return;
        }
    }
}
