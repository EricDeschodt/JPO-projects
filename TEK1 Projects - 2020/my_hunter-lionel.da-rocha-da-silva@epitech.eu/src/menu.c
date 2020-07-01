/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "ducky.h"

void load_play_text(s_show *image)
{
    image->text.play_text = sfText_create();
    sfText_setString(image->text.play_text, "PRESS 'ENTER' TO PLAY");
    sfText_setFont(image->text.play_text, image->text.font);
    sfText_setColor(image->text.play_text, sfBlack);
    sfText_setCharacterSize(image->text.play_text, 50);
}

void load_exit(s_show *image)
{
    image->text.exit = sfText_create();
    sfText_setString(image->text.exit, "PRESS 'ESC' TO EXIT");
    sfText_setFont(image->text.exit, image->text.font);
    sfText_setColor(image->text.exit, sfBlack);
    sfText_setCharacterSize(image->text.exit, 50);
}

void display_menu(sfRenderWindow *window, s_show *image)
{
    image->cross.pos.x = sfMouse_getPositionRenderWindow(window).x;
    image->cross.pos.y = sfMouse_getPositionRenderWindow(window).y;
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_drawSprite(window, image->back.sprite, NULL);
    sfText_setPosition(image->text.play_text, (sfVector2f){600, 850});
    sfRenderWindow_drawText(window, image->text.play_text, NULL);
    sfText_setPosition(image->text.exit, (sfVector2f){640, 900});
    sfRenderWindow_drawText(window, image->text.exit, NULL);
    sfText_setPosition(image->text.best_score, (sfVector2f){730, 300});
    sfRenderWindow_drawText(window, image->text.best_score, NULL);
    sfText_setPosition(image->text.best_number, (sfVector2f){1050, 300});
    sfRenderWindow_drawText(window, image->text.best_number, NULL);
    check_dog(window, image);
    sfSprite_setPosition(image->cross.cross.sprite,
    (sfVector2f){image->cross.pos.x - 25, image->cross.pos.y - 25});
    sfRenderWindow_drawSprite(window, image->cross.cross.sprite, NULL);
    sfRenderWindow_display(window);
}

void game_loop(sfRenderWindow *window, s_show *image)
{
    if (image->life.lives > 0) {
        load_animations(image);
        display(window, image);
    }
    else{
        display_gameover(window, image);
        read_best_score(image);
        save_score(image);
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            image->life.lives = 5;
            image->text.number = "0";
            image->level = 1.0;
            image->duck.x = 0.0, image->duck.y = 50.0;
            image->duck_rev.x = 1920.0, image->duck_rev.y = 50.0;
            image->duck.time_move = sfClock_restart(image->duck.clock_move);
            image->duck_rev.time_move =
            sfClock_restart(image->duck_rev.clock_move);
        }
    }
}

void init_struct(s_show *image)
{
    image->duck.frame.height = 110, image->duck.frame.left = 0,
    image->duck.frame.top = 0, image->duck.frame.width = 148;
    image->duck_rev.frame.height = 110, image->duck_rev.frame.left = 0,
    image->duck_rev.frame.top = 0, image->duck_rev.frame.width = 148;
    image->dog.frame.height = 130, image->dog.frame.left = 0,
    image->dog.frame.top = 0, image->dog.frame.width = 162;
    image->dog_rev.frame.height = 130, image->dog_rev.frame.left = 648,
    image->dog_rev.frame.top = 0, image->dog_rev.frame.width = 162;
    image->duck.x = 0.0, image->duck.y = 50.0;
    image->duck_rev.x = 1920.0, image->duck_rev.y = 50.0;
    image->dog.x = -162.0, image->dog.y = 800.0;
    image->dog_rev.x = 1758.0, image->dog_rev.y = 800.0;
    image->dog_state = 0;
    init_params(image);
}
