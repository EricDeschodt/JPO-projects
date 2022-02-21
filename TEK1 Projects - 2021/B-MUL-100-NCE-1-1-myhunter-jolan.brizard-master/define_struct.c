/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** define the structures
*/

#include "my_hunter.h"

sfIntRect *define_crow_area(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 1600/4;
    rect->height = 350;
    return rect;
}

sfIntRect *define_heart_area(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 777 / 4;
    rect->height = 177;
    return rect;
}

t_window *define_window(t_window *windw)
{
    windw->window = create_window(1920, 1080, 32, "Hunter");
    windw->clock = sfClock_create();
    windw->start = false;
    windw->framerate_limit = 30;
    return (windw);
}

t_sprite *define_sprite(t_sprite *sprite,
                            sfIntRect *crow_rect, sfIntRect *heart_rect)
{
    sprite->crow_texture = sfTexture_createFromFile("./img/crow.png", NULL);
    sprite->crow = sfSprite_create();
    sprite->b_texture = sfTexture_createFromFile("./img/mystic.jpg", NULL);
    sprite->background = sfSprite_create();
    sprite->heart_texture = sfTexture_createFromFile("./img/heart.png", NULL);
    sprite->heart = sfSprite_create();
    sprite->crow_rect = *crow_rect;
    sprite->heart_rect = *heart_rect;
    sprite->text_texture = sfTexture_createFromFile("./img/texte.png", NULL);
    sprite->text = sfSprite_create();
    sprite->life = 3;
    sprite->cursor_texture =
            sfTexture_createFromFile("./img/cursor.png", NULL);
    sprite->cursor = sfSprite_create();
    return sprite;
}

t_audio *define_audio(t_audio *audio)
{
    audio->intro_buf = sfSoundBuffer_createFromFile("./sound/epic.wav");
    audio->intro = sfSound_create();
    audio->epic_buf = sfSoundBuffer_createFromFile("./sound/epic.wav");
    audio->epic = sfSound_create();
    return audio;
}