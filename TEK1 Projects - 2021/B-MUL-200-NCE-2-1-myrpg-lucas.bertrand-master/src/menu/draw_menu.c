/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_menu
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void draw_menu_two(sfRenderWindow *window, scene_t *menu, bool *option)
{   
    sfRenderWindow_drawSprite(window, menu[19].objs->my_sprite, NULL);
    if (option[0] == false) {
        sfText_setString(menu[15].texts->text, "OPTION");
        for (int i = 6; i != 9; i++)
            sfRenderWindow_drawRectangleShape(window, menu[i].buttons->rect, NULL);
        for (int i = 12; i != 16; i++)
            sfRenderWindow_drawText(window, menu[i].texts->text, NULL);
    }
    else if (option[0] == true) {
        sfText_setString(menu[15].texts->text, "RETOUR");
        for (int i = 8; i != 12; i++)
            sfRenderWindow_drawRectangleShape(window, menu[i].buttons->rect, NULL);
        for (int i = 15; i != 19; i++)
            sfRenderWindow_drawText(window, menu[i].texts->text, NULL);
    }
    if (my_strcmp(sfText_getString(menu[12].texts->text), "") != 0) {
        sfRenderWindow_drawRectangleShape(window, menu[5].buttons->rect, NULL);
        sfRenderWindow_drawText(window, menu[12].texts->text, NULL);
    } if (option[0] == true && option[1] == true)
        sfRenderWindow_drawSprite(window, menu[1].objs->my_sprite, NULL);
}

void draw_menu_one(sfRenderWindow *window, scene_t *menu)
{
    sfEvent event;
    bool *option = malloc(sizeof(bool) * 2);
    int ret = 0;
    option[0] = false;
    option[1] = false;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        ret = analyse_events_menu_one(window, event, menu, option);
        if (ret == 1)
            break;
        if (ret == 3) {
            option[0] = !option[0];
            option[1] = false;
        } if (ret == 5)
              option[1] = !option[1];
        sfRenderWindow_drawSprite(window, menu[0].objs->my_sprite, NULL);
        draw_menu_two(window, menu, option);
    }
}
