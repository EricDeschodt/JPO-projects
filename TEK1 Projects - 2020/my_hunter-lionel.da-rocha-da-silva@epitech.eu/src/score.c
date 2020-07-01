/*
** EPITECH PROJECT, 2019
** score
** File description:
** score
*/

#include "ducky.h"

int scoreboard(s_show *image)
{
    image->text.font = sfFont_createFromFile("sprites/Retro.ttf");
    if (!image->text.font)
        return EXIT_FAILURE;
    image->text.text = sfText_create();
    sfText_setString(image->text.text, "SCORE: ");
    sfText_setFont(image->text.text, image->text.font);
    sfText_setColor(image->text.text, sfBlack);
    sfText_setCharacterSize(image->text.text, 40);
    return (0);
}

void dead_duck(s_show *image)
{
    image->dead.dead_duck.texture =
    sfTexture_createFromFile("sprites/dead_duck.png", NULL);
    image->dead.dead_duck.sprite = sfSprite_create();
    sfSprite_setTexture(image->dead.dead_duck.sprite,
    image->dead.dead_duck.texture, 0);
}

void update_score(s_show *image)
{
    image->text.score = sfText_create();
    sfText_setString(image->text.score, image->text.number);
    sfText_setFont(image->text.score, image->text.font);
    sfText_setColor(image->text.score, sfBlack);
    sfText_setCharacterSize(image->text.score, 40);
}

void draw_dead(sfRenderWindow *window, s_show *image)
{
    if (sfFloatRect_contains(&image->duck.hit.hitbox, image->duck.hit.mouse.x,
    image->duck.hit.mouse.y) == sfTrue) {
        if (image->dead.dead_time.microseconds > 0) {
            sfSprite_setPosition(image->dead.dead_duck.sprite,
            (sfVector2f){image->dead.deadx, image->dead.deady});
            sfRenderWindow_drawSprite(window, image->dead.dead_duck.sprite,
            NULL);
            image->dead.dead_time.microseconds -= 1.0;
        }
    }
}

int load_sound(s_show *image)
{
    image->sound = sfMusic_createFromFile("sounds/beretta.ogg");
    if (!image->sound)
        return EXIT_FAILURE;
    sfMusic_play(image->sound);
    return (0);
}
