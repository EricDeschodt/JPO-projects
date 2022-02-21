/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_over
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int button_is_clicked_game_over(scene_t *game_over, sfVector2i click_position)
{
    sfVector2f pos[2];
    sfVector2f size[2];
    sfVector2f pos_max[2];
    for (int i = 1; i != 3; i++) {
        pos[i] = sfRectangleShape_getPosition(game_over[i].buttons->rect);
        size[i] = sfRectangleShape_getSize(game_over[i].buttons->rect);
        pos_max[i] = create_v2f(pos[i].x + size[i].x, pos[i].y + size[i].y);
        if (pos[i].x <= click_position.x && pos_max[i].x >= click_position.x &&
            pos[i].y <= click_position.y && pos_max[i].y >= click_position.y) {
            if (three_states_button(game_over[i].buttons, game_over[i + 2].texts, 700) == 1)
                return (i);
        }
        else
            put_button_back(game_over[i].buttons, game_over[i + 2].texts, 685);
    }
    return (0);
}

int analyse_events_game_over(sfRenderWindow *window, sfEvent event,
                        scene_t *game_over)
{
    sfVector2i click_position = sfMouse_getPositionRenderWindow(window);
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        ret = button_is_clicked_game_over(game_over, click_position);
        if (event.type == sfEvtClosed || ret == 2) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (ret == 1) {
            sfSound_pause(game_over[5].sounds->sound);
            open_save(window);
            return (1);
        }
    }
    return (0);
}

void game_over_draw(sfRenderWindow *window, scene_t *game_over)
{
    sfEvent event;
    sfSound_play(game_over[5].sounds->sound);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (1) {
        sfRenderWindow_display(window);
        if (analyse_events_game_over(window, event, game_over) == 1)
            break;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game_over[0].objs->my_sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, game_over[1].buttons->rect, NULL);
        sfRenderWindow_drawRectangleShape(window, game_over[2].buttons->rect, NULL);
        sfRenderWindow_drawText(window, game_over[3].texts->text, NULL);
        sfRenderWindow_drawText(window, game_over[4].texts->text, NULL);
    }
}

void destroy_game_over(scene_t *game_over)
{
    destroy_object(game_over[0].objs->my_sprite, game_over[0].objs->my_texture);
    sfRectangleShape_destroy(game_over[1].buttons->rect);
    sfRectangleShape_destroy(game_over[2].buttons->rect);
    destroy_text(game_over[3].texts->text, game_over[3].texts->font);
    destroy_text(game_over[4].texts->text, game_over[4].texts->font);
    destroy_sound(game_over[5].sounds->sound, game_over[5].sounds->soundbuffer);
}

void game_over(sfRenderWindow *window)
{
    scene_t game_over[6];
    sfRenderWindow_clear(window, sfBlack);
    game_over[0].objs = create_object("sprite/game_over.png", create_v2f(0, 0),
    create_rect_int(0, 0, 1920, 1080), create_v2f(3, 3));
    game_over[1].buttons = init_button(create_v2f(500, 700), create_v2f(400, 125));
    game_over[2].buttons = init_button(create_v2f(1150, 700), create_v2f(300, 125));
    game_over[3].texts = create_text("RECOMMENCER", create_v2f(540, 740), 40, sfRed);
    game_over[4].texts = create_text("QUITTER", create_v2f(1170, 740), 50, sfRed);
    game_over[5].sounds = create_sound("sound/game_over.ogg", sfTrue);
    game_over_draw(window, game_over);
    destroy_game_over(game_over);
}
