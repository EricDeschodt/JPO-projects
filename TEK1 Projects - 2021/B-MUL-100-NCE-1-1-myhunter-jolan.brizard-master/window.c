/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** Handle window things
*/

#include "my_hunter.h"

sfRenderWindow *create_window(unsigned int x, unsigned int y,
                                unsigned int bpp, char *window_title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, window_title, sfClose, NULL));
}

bool make_conditions(t_window *windw, t_sprite *sprite)
{
    if (sfSprite_getPosition(sprite->crow).x >= 1920) {
        sprite->heart_rect = move_rect(sprite->heart_rect, 800 / 4, 777);
        sfSprite_setTexture(sprite->heart, sprite->heart_texture, sfTrue);
        sfSprite_setTextureRect(sprite->heart, sprite->heart_rect);
        sfRenderWindow_drawSprite(windw->window, sprite->heart, NULL);
        sfRenderWindow_display(windw->window);
        sprite->life -= 1;
        sprites_coord(sprite);
    }
    if (sprite->life == 0) {
        windw->start = false;
        sprite->life = 3;
        sprite->heart_rect.left = 0;
        return false;
    }
    return true;
}

void play_music(t_audio *audio)
{
    sfSound_setBuffer(audio->intro, audio->intro_buf);
    sfSound_play(audio->intro);
}

void set_cursor(t_window *windw, t_sprite *sprite)
{
    sfVector2f scale_cursor = {0.1, 0.1};
    sfSprite_setScale(sprite->cursor, scale_cursor);
    sprite->cursor_pos.x =
            (float)sfMouse_getPositionRenderWindow(windw->window).x
            - (500 / 2 * 0.1);
    sprite->cursor_pos.y =
            (float)sfMouse_getPositionRenderWindow(windw->window).y
            - (500 / 2 * 0.1);
    sfSprite_setPosition(sprite->cursor, sprite->cursor_pos);
}

void draw_cursor(t_window *windw, t_sprite *sprite)
{
    set_cursor(windw, sprite);
    sfSprite_setTexture(sprite->cursor, sprite->cursor_texture, sfTrue);
    sfRenderWindow_drawSprite(windw->window, sprite->cursor, NULL);
}