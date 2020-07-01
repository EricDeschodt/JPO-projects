/*
** EPITECH PROJECT, 2019
** gameover
** File description:
** gameover
*/

#include "ducky.h"

void analyse_gameover_events(sfRenderWindow *window, s_show *image)
{
    if (image->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (image->event.type == sfEvtMouseButtonPressed) {

        }
}

void load_gameover_text(s_show *image)
{
    image->text.gameover = sfText_create();
    sfText_setString(image->text.gameover, "GAME OVER");
    sfText_setFont(image->text.gameover, image->text.font);
    sfText_setColor(image->text.gameover, sfBlack);
    sfText_setCharacterSize(image->text.gameover, 100);
}

void display_gameover(sfRenderWindow *window, s_show *image)
{
    image->cross.pos.x = sfMouse_getPositionRenderWindow(window).x;
    image->cross.pos.y = sfMouse_getPositionRenderWindow(window).y;
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_drawSprite(window, image->back.sprite, NULL);
    display_text(window, image);
    sfSprite_setPosition(image->cross.cross.sprite,
    (sfVector2f){image->cross.pos.x - 25, image->cross.pos.y - 25});
    sfRenderWindow_drawSprite(window, image->cross.cross.sprite, NULL);
    sfRenderWindow_display(window);
}

void load_fixed(s_show *image)
{
    load_background(image);
    scoreboard(image);
    load_crosshair(image);
    load_gameover_text(image);
    load_play_text(image);
    load_restart_text(image);
    load_exit(image);
    read_best_score(image);
    load_best_score(image);
    update_best_score(image);


}

void load_duck_rev(s_show *image)
{
    image->duck_rev.duck.texture =
    sfTexture_createFromFile("sprites/duck_right.png", NULL);
    image->duck_rev.duck.sprite = sfSprite_create();
    sfSprite_setTexture(image->duck_rev.duck.sprite,
    image->duck_rev.duck.texture, 0);
    image->duck_rev.time = sfClock_getElapsedTime(image->duck_rev.clock);
    image->duck_rev.seconds = image->duck_rev.time.microseconds / 1000000.0;
    if (image->duck_rev.seconds > 0.1) {
        move_rev(&image->duck_rev.frame, 110, 330);
        sfClock_restart(image->duck_rev.clock);
    }
    image->duck_rev.time_move = sfClock_restart(image->duck_rev.clock_move);
    move_duck_rev(image);
    sfSprite_setTextureRect(image->duck_rev.duck.sprite,
    image->duck_rev.frame);
}
