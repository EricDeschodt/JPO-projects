/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** creator_buttons
*/

#include "defender.h"

map_button_t *fill_map_buttons(map_button_t *old, char *texture,
                            char *hover, sfVector2f pos)
{
    static int id = 0;
    map_button_t *new = malloc(sizeof(map_button_t));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(texture, NULL);
    new->hover = sfTexture_createFromFile(hover, NULL);
    new->pos = pos, new->id = id;
    id++;
    new->next = old;
    sfSprite_setTexture(new->sprite, new->hover, sfTrue);
    sfSprite_setPosition(new->sprite, pos);
    return (new);
}

void init_creator_buttons(all_t *s_all)
{
    char *tab[4] = {"sprites/buttons/undo.png", "sprites/buttons/reset.png",
    "sprites/buttons/save.png", "sprites/buttons/menu.png"};
    char *tab1[4] = {"sprites/buttons/undo1.png", "sprites/buttons/reset1.png",
    "sprites/buttons/save1.png", "sprites/buttons/menu1.png"};
    sfVector2f pos = (sfVector2f){1710, 610};
    s_all->s_map_buttons = NULL;
    for (int i = 0; i != 4; i++) {
        s_all->s_map_buttons =
        fill_map_buttons(s_all->s_map_buttons, tab[i], tab1[i], pos);
        pos.y += 100;
    }
}

int check_creator_button_hitbox(map_button_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x > temp->pos.x && mouse_pos.x < temp->pos.x + 224)
        && (mouse_pos.y > temp->pos.y && mouse_pos.y < temp->pos.y + 80))
        return (1);
    return (0);
}

void click_creator_button(all_t *s_all)
{
    map_button_t *temp = s_all->s_map_buttons;
    while (temp != NULL) {
        sfSprite_setTexture(temp->sprite, temp->hover, sfTrue);
        if (check_creator_button_hitbox(temp, s_all)) {
            sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        }
        temp = temp->next;
    }
}

void display_creator_buttons(all_t *s_all)
{
    map_button_t *temp = s_all->s_map_buttons;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}