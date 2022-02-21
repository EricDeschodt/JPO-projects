/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** paralax background fnc
*/

#include <stdlib.h>
#include "../include/backgrounds.h"

backgrounds_t *create_backgrounds(void)
{
    backgrounds_t *b = malloc(sizeof(backgrounds_t));
    b->vitesse = 10;
    b->t_background = sfTexture_createFromFile
        ("assets/backgrounds/0.png", NULL);
    b->background = create_background(b->t_background);
    b->t_distantground = sfTexture_createFromFile
        ("assets/backgrounds/1.png", NULL);
    b->distantground = create_background(b->t_distantground);
    b->t_middleground = sfTexture_createFromFile
        ("assets/backgrounds/2.png", NULL);
    b->middleground = create_background(b->t_middleground);
    b->t_foreground = sfTexture_createFromFile
        ("assets/backgrounds/3.png", NULL);
    b->foreground = create_background(b->t_foreground);
    return b;
}

backgrounds_t *animate_backgrounds(backgrounds_t *b, int v)
{
    animate_background(b->background, (int)(v * (1.0 / 5)));
    animate_background(b->distantground, (int)(v * (2.0 / 5)));
    animate_background(b->middleground, (int)(v * (3.0 / 5)));
    animate_background(b->foreground, (int)(v * (4.0 / 5)));
    return b;
}

backgrounds_t *display_backgrounds(sfRenderWindow *window, backgrounds_t *b)
{
    sfRenderWindow_drawSprite(window, b->background, NULL);
    sfRenderWindow_drawSprite(window, b->distantground, NULL);
    sfRenderWindow_drawSprite(window, b->middleground, NULL);
    sfRenderWindow_drawSprite(window, b->foreground, NULL);
    return b;
}

void destroy_backgrounds(backgrounds_t *b)
{
    sfTexture_destroy(b->t_background);
    sfTexture_destroy(b->t_distantground);
    sfTexture_destroy(b->t_middleground);
    sfTexture_destroy(b->t_foreground);
    sfSprite_destroy(b->background);
    sfSprite_destroy(b->distantground);
    sfSprite_destroy(b->middleground);
    sfSprite_destroy(b->foreground);
    free(b);
}