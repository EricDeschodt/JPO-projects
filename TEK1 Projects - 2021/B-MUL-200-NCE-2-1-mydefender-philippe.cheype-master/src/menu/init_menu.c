/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** init_menu.c
*/

#include <stdlib.h>
#include "defender.h"
#include "my.h"

static void menu_init(menu_t *mn)
{
    mn->music = sfMusic_createFromFile("assets/sound/soundtrack_intro.ogg");
    mn->map = sfSprite_create();
    mn->pos_onclick = malloc(sizeof(sfVector2f) * 4);
    mn->pos = malloc(sizeof(sfVector2f) * 4);
    mn->button = malloc(sizeof(button_t) * 4);
    for (int i = 0; i < NB_BUTTON; i++)
        mn->button[i].rect = sfRectangleShape_create();
    mn->pos_onclick->x = 0;
    mn->pos_onclick->y = 0;
    mn->size.x = 600;
    mn->size.y = 100;
    mn->pos->x = 0;
    mn->pos->y = 0;
    mn->state = -1;
}

static void menu_texture(menu_t *mn)
{
    sfIntRect text[4] = { {0, 0, 500, 150}, {0, 150, 500, 150}, \
                        {0, 0, 500, 150}, {0, 150, 500, 150} };
    sfTexture *map_tx, *button_tx;

    map_tx = sfTexture_createFromFile("assets/textures/menu_bg.jpg", NULL);

    for (int i = 0; i < NB_BUTTON; i++) {
        button_tx = sfTexture_createFromFile("assets/textures/buttons.jpg",    \
                                                                &text[i]);
        sfRectangleShape_setTexture(mn->button[i].rect, button_tx, sfTrue);
    }
    sfSprite_setTexture(mn->map, map_tx, sfTrue);
}

static int create_menu_button(menu_t *mn)
{
    char *txts[4] = { "Play", "High Score", "Settings", "Exit" };
    int decal = 0, i = 0;

    for (i = 0; i < NB_BUTTON; i++, decal += 130) {
        sfVector2f pos = { 180, 500 + decal };
        sfVector2f text_p = { pos.x + 290 - 8 * my_strlen(txts[i]), pos.y + 18};
        mn->pos[i] = pos;
        mn->pos_onclick[i] = GET_POS_ON_CLICK(pos, mn->size, BTN_HOVER);
        mn->button[i].text = create_text(text_p, txts[i], 50, sfBlack);
        sfRectangleShape_setPosition(mn->button[i].rect, mn->pos[i]);
        sfRectangleShape_setSize(mn->button[i].rect, mn->size);
    }
    return (i);
}

static void menu_position(menu_t *mn)
{
    int i = 0;

    i = create_menu_button(mn);
    mn->pos_onclick[i].x = -1;
    mn->pos_onclick[i].y = -1;
    mn->pos[i].x = -1;
    mn->pos[i].y = -1;
}

menu_t *init_menu(void)
{
    menu_t *mn;

    mn = malloc(sizeof(menu_t));
    menu_init(mn);
    menu_texture(mn);
    menu_position(mn);
    sfMusic_setVolume(mn->music, 0.0);
    return (mn);
}
