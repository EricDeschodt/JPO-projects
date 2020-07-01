/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** map_editor
*/

#include "defender.h"
#include "utils.h"

void init_custom_maps(all_t *s_all)
{
    s_all->s_map_edit.map = adapt("maps/example");
    s_all->s_map_edit.head = parse_map(s_all->s_map_edit.map);
    s_all->s_map_edit.examples = NULL;
    s_all->s_map_edit.placed = NULL;
    s_all->s_map_edit.error1 = sfText_create();
    s_all->s_map_edit.error2 = sfText_create();
    s_all->s_map_edit.clock = sfClock_create();
    sfText_setString(s_all->s_map_edit.error1,
    "Not enough or more than one castle or spawner.");
    sfText_setString(s_all->s_map_edit.error2,
    "More than one possible path.");
    sfText_setPosition(s_all->s_map_edit.error1, (sfVector2f){1380, 991});
    sfText_setPosition(s_all->s_map_edit.error2, (sfVector2f){1380, 991});
    sfText_setFont(s_all->s_map_edit.error1, s_all->s_game.font);
    sfText_setFont(s_all->s_map_edit.error2, s_all->s_game.font);
    sfText_setCharacterSize(s_all->s_map_edit.error1, 18);
    sfText_setCharacterSize(s_all->s_map_edit.error2, 18);
    s_all->s_map_edit.error = 0;
    create_support_examples(s_all);
    init_creator_buttons(s_all);
}

void map_editor_click(all_t *s_all)
{
    if (s_all->s_game.scene == 2) {
        click_support(s_all);
        hitbox_slider_arrow(s_all);
        click_creator_button(s_all);
    }
}

void map_editor_release(all_t *s_all)
{
    if (s_all->s_game.scene == 2) {
        click_n_place(s_all);
        release_creator_buttons(s_all);
    }
}

void create_support_examples(all_t *s_all)
{
    sfVector2f pos = (sfVector2f){1745, 20};
    char *tab[4] = {"sprites/turret_support.png", "sprites/spawner.png",
    "sprites/castle.png", "sprites/ground.png"};
    char flags[4] = "OSCG";
    for (int i = 0; i != 4; i++) {
        s_all->s_map_edit.examples = fill_support(s_all->s_map_edit.examples,
        pos, tab[i], flags[i]);
        pos.y += 135;
    }
}

void display_support_examples(all_t *s_all)
{
    support_t *temp = s_all->s_map_edit.examples;
    while (temp != NULL) {
        if (temp->type == 'S') {
            rotate_spawner(temp, s_all);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->sprite_base, NULL);
            if (s_all->s_settings->shaders == 1)
                sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite_base, &s_all->s_game.state);
        } sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        if (temp->type != 'S' && s_all->s_settings->shaders == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite, &s_all->s_game.state);
        temp = temp->next;
    }
}