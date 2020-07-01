/*
** EPITECH PROJECT, 2019
** duck
** File description:
** duck
*/

#include "ducky.h"

void load_background(s_show *image)
{
    image->back.texture =
    sfTexture_createFromFile("sprites/background.png", NULL);
    image->back.sprite = sfSprite_create();
    sfSprite_setTexture(image->back.sprite, image->back.texture, 0);

}

int render_window(sfRenderWindow *window, s_show image)
{
    load_fixed(&image);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &image.event)) {
                analyse_events(window, &image);
        }
        if (image.life.state == 0) {
            display_menu(window, &image);
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                image.life.state = 1;
                start_game(&image);
            }
        }
        if (image.life.state == 1)
            game_loop(window, &image);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            sfRenderWindow_close(window);
            }
    }
    destroy(window, &image);
    return (0);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset)
        rect->left += 148;
    else
        rect->left = 0;
}

void shoot_duck(sfRenderWindow *window, s_show *image)
{
    image->duck.hit.hitbox.height = 110, image->duck.hit.hitbox.left =
    image->duck.x,
    image->duck.hit.hitbox.top = image->duck.y, image->duck.hit.hitbox.width
    = 148;
    image->duck.hit.mouse.x = sfMouse_getPositionRenderWindow(window).x;
    image->duck.hit.mouse.y = sfMouse_getPositionRenderWindow(window).y;
    if (sfFloatRect_contains(&image->duck.hit.hitbox, image->duck.hit.mouse.x,
    image->duck.hit.mouse.y) == sfTrue) {
        image->dead.deadx = image->duck.hit.mouse.x;
        image->dead.deady = image->duck.hit.mouse.y;
        image->dead.dead_time.microseconds = 200;
        image->text.number = inf_add(image->text.number, "1");
        image->duck.x = 0;
        image->duck.y = rand() % 500;
        image->level += 0.1;
        image->func = rand() % 2;
        image->duck_rev.time_move = sfClock_restart(image->duck_rev.clock_move);
    }
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    s_show image;
    sfVideoMode mode = {1920, 1080, 32};

    write_help_msg(ac, av);

    if (ac == 1) {
        window = sfRenderWindow_create(mode, "Ducky", sfResize | sfClose, NULL);
            if (!window)
                return EXIT_FAILURE;
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        init_struct(&image);
        srand(time(NULL));
        render_window(window, image);
    }
    return (0);
}
