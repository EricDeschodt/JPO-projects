/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** Gère ce qu'il se passe à l'écran
*/

#include "my_hunter.h"

void draw_heart(t_window *windw, t_sprite *sprite)
{
    sfSprite_setTexture(sprite->heart, sprite->heart_texture, sfTrue);
    sfSprite_setTextureRect(sprite->heart, sprite->heart_rect);
    sfRenderWindow_drawSprite(windw->window, sprite->heart, NULL);
}

void draw_background(t_window *windw, t_sprite *sprite)
{
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {1., 1.2};
    sfSprite_setScale(sprite->background, scale);
    sfSprite_setPosition(sprite->background, my_pos);
    sfSprite_setTexture(sprite->background, sprite->b_texture, sfFalse);
    sfRenderWindow_drawSprite(windw->window, sprite->background, NULL);
}

void draw_text(t_window *windw, t_sprite *sprite)
{
    sfVector2f text_pos = {620, 440};
    sfSprite_setPosition(sprite->text, text_pos);
    sfSprite_setTexture(sprite->text, sprite->text_texture, sfFalse);
    sfRenderWindow_drawSprite(windw->window, sprite->text, NULL);
}

void draw_crow(t_window *windw, t_sprite *sprite)
{
    sfSprite_setTexture(sprite->crow, sprite->crow_texture, sfFalse);
    sfRenderWindow_drawSprite(windw->window, sprite->crow, NULL);
}

void draw_all(t_window *windw, t_sprite *sprite)
{
    if (windw->start && make_conditions(windw, sprite)) {
        sfRenderWindow_clear(windw->window, sfBlack);
        draw_background(windw, sprite);
        draw_heart(windw, sprite);
        crow_animation(windw, sprite);
        draw_cursor(windw, sprite);
        sfRenderWindow_display(windw->window);
    } else {
        sfRenderWindow_clear(windw->window, sfBlack);
        draw_background(windw, sprite);
        draw_text(windw, sprite);
        draw_cursor(windw, sprite);
        sfRenderWindow_display(windw->window);
    }
}