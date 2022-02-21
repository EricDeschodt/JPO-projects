/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** end
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int button_is_clicked_end(scene_t *end, sfVector2i click_position)
{
    sfVector2f pos[2];
    sfVector2f size[2];
    sfVector2f pos_max[2];
    for (int i = 0; i != 2; i++) {
        pos[i] = sfRectangleShape_getPosition(end[i + 3].buttons->rect);
        size[i] = sfRectangleShape_getSize(end[i + 3].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(end[i + 3].buttons, end[i + 11].texts, 900) == 1)
                return (i + 1);
        }
        else
            put_button_back(end[i + 3].buttons, end[i + 11].texts, 885);
    }
    return (0);
}

int analyse_event_end(sfRenderWindow *window, sfEvent event, scene_t *end)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        ret = button_is_clicked_end(end, click_pos);
        if (event.type == sfEvtClosed || ret == 2) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (ret == 1) {
            sfSound_play(end[2].sounds->sound);
            sfSound_stop(end[1].sounds->sound);
            create_menu_one(window);
            return (1);
        }
    }
    return (0);
}

int draw_end(sfRenderWindow *window, scene_t *end)
{
    sfEvent event;
    int ret = 6;

    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        if (analyse_event_end(window, event, end) == 1)
            return (1);
        time_increase(end[13].times);
        sfRenderWindow_drawSprite(window, end[0].objs->my_sprite, NULL);
        ret = anim_end(end);
        sfRenderWindow_drawText(window, end[5].texts->text, NULL);
        for (int i = 6; i != ret; i++)
            sfRenderWindow_drawText(window, end[i].texts->text, NULL);
        if (ret == 11) {
            for (int i = 3; i != 5; i++)
                sfRenderWindow_drawRectangleShape(window, end[i].buttons->rect, NULL);
            for (int i = 11; i != 13; i++)
                sfRenderWindow_drawText(window, end[i].texts->text, NULL);
        }
    }
}

void destroy_end(scene_t *end)
{
    destroy_object(end[0].objs->my_sprite, end[0].objs->my_texture);
    for (int i = 1; i != 3; i++)
        destroy_sound(end[i].sounds->sound, end[i].sounds->soundbuffer);
    for (int i = 3; i != 5; i++)
        sfRectangleShape_destroy(end[i].buttons->rect);
    for (int i = 5; i != 13; i++)
      destroy_text(end[i].texts->text, end[i].texts->font);
    sfClock_destroy(end[13].times->clock);
}

int end(sfRenderWindow *window)
{
    scene_t end[14];
    end[0].objs = create_object("sprite/end.png", create_v2f(0, 0),
                                create_rect_int(0, 0, 640, 360), create_v2f(3, 3));
    end[1].sounds = create_sound("sound/end.ogg", sfTrue);
    sfSound_play(end[1].sounds->sound);
    end[2].sounds = create_sound("sound/button.ogg", sfFalse);
    end[3].buttons = init_button(create_v2f(700, 900), create_v2f(250, 100));
    end[4].buttons = init_button(create_v2f(1100, 900), create_v2f(250, 100));
    end_credit(end);
    end[11].texts = create_text("MENU", create_v2f(750, 920), 50, sfCyan);
    end[12].texts = create_text("QUITTER", create_v2f(1120, 930), 40, sfCyan);
    end[13].times = create_time();
    if (draw_end(window, end) == 1) {
        destroy_end(end);
        return (1);
    }
    destroy_end(end);
    return (0);
}
