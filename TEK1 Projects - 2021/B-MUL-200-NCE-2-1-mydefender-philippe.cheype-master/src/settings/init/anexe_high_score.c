/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** anexe_high_score.c
*/

#include <stdlib.h>
#include "defender.h"

int check_how_to_play(vars_t *va, play_t *py, button_t *btn, int j)
{
    sfVector2f c;

    c = GET_MOUSE_POS(va->window);
    for (int i = 0; i < 7; i++) {
        settings_button(btn, py, 0, i);

        if ((c.x > py->pos[i].x) && (c.x < py->pos[i].x + 600)  \
        && (c.y > py->pos[i].y) && (c.y < py->pos[i].y + 100)) {
            settings_button(btn, py, 1, i);
            if (sfMouse_isButtonPressed(0)) {
                return ((i == 6 ? 8 : i));
            }
        }
    }
    return (j);
}

button_t *high_score_btn(void)
{
    button_t *btn;

    sfFloatRect pos_size = {150, 125, 600, 100};
    sfTexture **texture = get_button_textures(7);
    char *string[] = {
        "", "Place building", "Upgrade / Remove",     \
        "Bonus items", "Defense items",               \
        "Soldier items", "Rules", "Return"            \
    };
    btn = create_button_ns(pos_size, string, texture, 7);
    return (btn);
}

play_t *create_py(void)
{
    play_t *py;
    int i = 0;
    sfTexture *temp;
    sfVector2f hash_t = {850, 200}, size_t = {870, 650};
    sfIntRect pos_size = {870, 0, 870, 650};
    sfFloatRect tempo = {300, 130, 1500, 800};

    py = malloc(sizeof(play_t));
    py->bg.pos_size = tempo;
    py->rect = malloc(sizeof(button_t) * 7);
    for (; i < 6; i++, pos_size.left += 870) {
        temp = sfTexture_createFromFile("assets/textures/how_to_play.jpg",  \
                                                                    &pos_size);
        py->rect[i].rect = create_rectangle(hash_t, size_t, temp, sfFalse);
    }
    pos_size.left = 0;
    temp = sfTexture_createFromFile("assets/textures/how_to_play.jpg",  \
                                                                &pos_size);
    py->rect[i].rect = create_rectangle(hash_t, size_t, temp, sfFalse);
    return (py);
}

play_t *init_py(button_t *btn)
{
    play_t *py;
    sfTexture *text = sfTexture_createFromFile("assets/textures/menu_bg.jpg",  \
                                                                        NULL);
    sfVector2f pos = {0, 0}, size = {1920, 1080}, btn_size = {600, 100};

    py = create_py();
    py->pos = malloc(sizeof(sfVector2f) * 7);
    py->pos_onclick = malloc(sizeof(sfVector2f) * 7);
    py->bg.rect = create_rectangle(pos, size, text, sfTrue);
    for (int i = 0; i < 7; i++) {
        py->pos[i] = sfRectangleShape_getPosition(btn[i].rect);
        py->pos_onclick[i] =  GET_POS_ON_CLICK(py->pos[i], btn_size, BTN_HOVER);
    }
    return (py);
}
