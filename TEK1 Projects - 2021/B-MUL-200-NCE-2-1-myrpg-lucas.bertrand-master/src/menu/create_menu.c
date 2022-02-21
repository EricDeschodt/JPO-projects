/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create_menu
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void destroy_menu(scene_t *menu)
{
    for (int i = 0; i != 2; i++)
        destroy_object(menu[i].objs->my_sprite, menu[i].objs->my_texture);
    for (int i = 2; i != 5; i++)
        destroy_sound(menu[i].sounds->sound, menu[i].sounds->soundbuffer);
    for (int i = 5; i != 12; i++)
        sfRectangleShape_destroy(menu[i].buttons->rect);
    for (int i = 12; i != 19; i++)
        destroy_text(menu[i].texts->text, menu[i].texts->font);
    destroy_object(menu[19].objs->my_sprite, menu[19].objs->my_texture);
}

void create_menu_two(scene_t *menu)
{
    menu[12].texts = create_text("", create_v2f(517, 460), 30, sfCyan);
    menu[13].texts = create_text("JOUER", create_v2f(480, 730), 65, sfCyan);
    menu[14].texts = create_text("QUITTER", create_v2f(1170, 740), 50, sfCyan);
    menu[15].texts = create_text("OPTION", create_v2f(820, 850), 60, sfCyan);
    menu[16].texts = create_text("ERIC", create_v2f(450, 675), 70, sfCyan);
    menu[17].texts = create_text("AIDE", create_v2f(850, 675), 70, sfCyan);
    menu[18].texts = create_text("EFFACER", create_v2f(1220, 685), 50, sfRed);
    menu[19].objs = create_object("sprite/mute.png", create_v2f(0, 0),
                                  create_rect_int(0, 0, 200, 200), create_v2f(0.5, 0.5));
}

void create_menu_one(sfRenderWindow *window)
{
    scene_t menu[20];

    menu[0].objs = create_object("sprite/menu.png", create_v2f(0, 0),
                                 create_rect_int(0, 0, 1920, 1080), create_v2f(1, 1));
    menu[1].objs = create_object("sprite/how_to_play.png", create_v2f(400, 50),
                                 create_rect_int(0, 0, 1200, 850), create_v2f(1, 1));
    menu[2].sounds = create_sound("sound/menu_theme.ogg", sfTrue);
    sfSound_play(menu[2].sounds->sound);
    menu[3].sounds = create_sound("sound/button.ogg", sfFalse);
    menu[4].sounds = create_sound("sound/start.ogg", sfFalse);
    menu[5].buttons = init_button(create_v2f(500, 450), create_v2f(1000, 150));
    menu[6].buttons = init_button(create_v2f(450, 700), create_v2f(300, 125));
    menu[7].buttons = init_button(create_v2f(1150, 700), create_v2f(300, 125));
    menu[8].buttons = init_button(create_v2f(800, 825), create_v2f(300, 125));
    menu[9].buttons = init_button(create_v2f(400, 650), create_v2f(300, 125));
    menu[10].buttons = init_button(create_v2f(800, 650), create_v2f(300, 125));
    menu[11].buttons = init_button(create_v2f(1200, 650), create_v2f(300, 125));
    create_menu_two(menu);
    draw_menu_one(window, menu);
    destroy_menu(menu);
}
