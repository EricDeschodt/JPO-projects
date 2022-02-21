/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** high_score.c
*/

#include "defender.h"

static sfText *check_return(vars_t *va, sfText *text,   \
                        int *return_code, sfColor color)
{
    sfVector2f mouse_pos = GET_MOUSE_POS(va->window);
    sfVector2f temp = sfText_getPosition(text);

    if (mouse_pos.x > temp.x && mouse_pos.x < temp.x + 150  \
    && mouse_pos.y > temp.y && mouse_pos.y < temp.x + 10) {
        color.a = 255;
        if (sfMouse_isButtonPressed(0)) *return_code = 1;
    }
    sfText_setColor(text, color);
    return (text);
}

static void render_elements(vars_t *va, sfSprite* hs,         \
                        sfText *text, sfRectangleShape *filter)
{
    sfRenderWindow_drawRectangleShape(va->window, filter, NULL);
    sfRenderWindow_drawSprite(va->window, hs, NULL);
    sfRenderWindow_drawText(va->window, text, sfFalse);
}

static sfRectangleShape *create_high_score_menu(sfVector2f pos[4],  \
                                        sfColor color, sfSprite **hs)
{
    sfRectangleShape *filter;
    sfTexture *texture;

    texture = sfTexture_createFromFile("assets/textures/high_score.png", NULL);
    *hs = sfSprite_create();
    sfSprite_setTexture(*hs, texture, sfFalse);
    sfSprite_setPosition(*hs, pos[1]);
    filter = create_rectangle(pos[0], pos[3], NULL, sfTrue);
    sfRectangleShape_setFillColor(filter, color);
    WAIT_FOR_BUTTON_RELEASE;
    return (filter);
}

void high_score(framebuffer_t *fb, vars_t *va, menu_t *mn)
{
    sfVector2f pos[] = { {0, 0}, {660, 140}, {886, 850}, {1920, 1080} };
    sfColor colors[] = { {0, 0, 0, 100}, {0, 0, 0, 200} };
    sfRectangleShape *filter;
    int return_code = 0;
    sfSprite *hs = NULL;
    sfText *text;

    filter = create_high_score_menu(pos, colors[1], &hs);
    text = create_text(pos[2], "RETURN", 48, colors[0]);
    while (return_code < 1 && sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            if (va->event.type == sfEvtClosed) sfRenderWindow_close(va->window);
        sfRenderWindow_clear(va->window, sfBlack);
        sfRenderWindow_drawSprite(va->window, mn->map, NULL);
        text = check_return(va, text, &return_code, colors[0]);
        render_elements(va, hs, text, filter);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
}
