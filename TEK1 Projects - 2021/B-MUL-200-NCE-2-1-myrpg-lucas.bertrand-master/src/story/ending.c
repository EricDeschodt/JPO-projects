/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ending
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int button_is_clicked_ending(scene_t *ending, sfVector2i click_pos)
{
    if (460 <= click_pos.x && 660 >= click_pos.x &&
        450 <= click_pos.y && 525 >= click_pos.y) {
        if (three_states_button(ending[6].buttons, ending[8].texts, 460) == 1)
            return (2);
    }
    else
        put_button_back(ending[6].buttons, ending[8].texts, 475);
    return (0);
}

int analyse_event_ending(sfRenderWindow *window, sfEvent event,
                         scene_t *ending, int *i)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (i[0] != 19 && sfKeyboard_isKeyPressed(sfKeySpace) == true) {
            i[0]++;
            sfSleep(sfSeconds(0.2));
            ending_dialogue(ending, i[0]);
        }
        else if (i[0] != 19 && sfKeyboard_isKeyPressed(sfKeyEscape) == true)
            i[0] = 19;
        if (i[0] == 19 && ending[0].objs->rect.top == 0)
            return (button_is_clicked_ending(ending, click_pos));
    }
    return (0);
}

int draw_ending(sfRenderWindow *window, scene_t *ending)
{
    sfEvent event;
    int ret = 0;
    int i = -1;
    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        ret = analyse_event_ending(window, event, ending, &i);
        if (ret == 1)
            return (1);
        time_increase(ending[9].times);
        time_increase(ending[10].times);
        if (ret == 2 || ending[0].objs->rect.top > 0) {
            if (light(ending) == 1)
                break;
        }
        else
            player(ending);
        draw_ending_two(window, ending, i);
    }
    return (0);
}

void destroy_ending(scene_t *ending)
{
    for (int i = 0; i != 1; i++)
        destroy_object(ending[i].objs->my_sprite, ending[i].objs->my_texture);
    for (int i = 2; i != 5; i++)
        destroy_sound(ending[i].sounds->sound, ending[i].sounds->soundbuffer);
    for (int i = 5; i != 7; i++)
        sfRectangleShape_destroy(ending[i].buttons->rect);
    for (int i = 7; i != 9; i++)
        destroy_text(ending[i].texts->text, ending[i].texts->font);
    for (int i = 9; i !=11; i++)
        sfClock_destroy(ending[i].times->clock);
}

int create_ending(sfRenderWindow *window)
{
    scene_t ending[11];
    ending[0].objs = create_object("sprite/ending.png", create_v2f(0, 0),
                                  create_rect_int(0, 0, 1130, 636), create_v2f(1.7, 1.7));
    ending[1].objs = create_object("sprite/last_surprise.png", create_v2f(0, 0),
                                   create_rect_int(0, 0, 640, 365), create_v2f(3, 3));
    ending[2].sounds = create_sound("sound/ending.ogg", sfTrue);
    sfSound_play(ending[2].sounds->sound);
    ending[3].sounds = create_sound("sound/button.ogg", sfFalse);
    ending[4].sounds = create_sound("sound/light_blaster.ogg", sfFalse);
    ending[5].buttons =  init_button(create_v2f(485, 680), create_v2f(1000, 150));
    ending[6].buttons = init_button(create_v2f(460, 450), create_v2f(200, 75));
    ending[7].texts = create_text("Nous avons suffisamment joue toi et moi.", create_v2f(510, 695), 30, sfWhite);
    ending[8].texts = create_text("LUMIERE", create_v2f(485, 470), 30, sfWhite);
    ending[9].times = create_time();
    ending[10].times = create_time();
    if (draw_ending(window, ending) == 1) {
        destroy_ending(ending);
        return (1);
    }
    destroy_ending(ending);
}
