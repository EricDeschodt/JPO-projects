/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level_selector
*/

#include "defender.h"
#include "utils.h"

levels_t *fill_levels(levels_t *old, char *filepath, char **text,
    sfVector2f pos)
{
    static int id = 1, nb1 = 0, nb2 = 8;
    levels_t *new = malloc(sizeof(levels_t));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(text[nb1], NULL);
    new->click = sfTexture_createFromFile(text[nb2], NULL);
    new->clock = sfClock_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->scale = 1, new->pos = pos, new->id = id;
    new->filepath = filepath, id++, nb1++, nb2++;
    sfSprite_setPosition(new->sprite, pos);
    sfSprite_setOrigin(new->sprite, (sfVector2f){200, 117});
    new->next = old;
    return (new);
}

void init_level_buttons(all_t *s_all)
{
    s_all->s_levels = NULL;
    char *tab[9] = {"maps/map1", "maps/map2", "maps/map3", "maps/map4",
    "maps/map5", "maps/map6", "maps/map7", "maps/map8"};
    char *tab2[18] = {"sprites/buttons/map1_iddle.png",
    "sprites/buttons/map2_iddle.png", "sprites/buttons/map3_iddle.png",
    "sprites/buttons/map4_iddle.png", "sprites/buttons/map5_iddle.png",
    "sprites/buttons/map6_iddle.png", "sprites/buttons/map7_iddle.png",
    "sprites/buttons/map8_iddle.png", "sprites/buttons/map1_select.png",
    "sprites/buttons/map2_select.png", "sprites/buttons/map3_select.png",
    "sprites/buttons/map4_select.png", "sprites/buttons/map5_select.png",
    "sprites/buttons/map6_select.png", "sprites/buttons/map7_select.png",
    "sprites/buttons/map8_select.png"};
    sfVector2f pos = (sfVector2f){290, 185};
    for (int i = 0; i != 8; i++) {
        if (i == 4) pos.y += 270, pos.x = 290;
        s_all->s_levels = fill_levels(s_all->s_levels, tab[i], tab2, pos);
        pos.x += 450;
    } init_level_buttons2(s_all);
}

void select_map(all_t *s_all, levels_t *temp)
{
    s_all->s_wave_c.round = free_mobs(s_all->s_wave_c.round);
    s_all->s_wave_c.square = free_mobs(s_all->s_wave_c.square);
    s_all->s_wave_c.triangle = free_mobs(s_all->s_wave_c.triangle);
    s_all->s_wave_c.go = 0, s_all->s_wave_c.min = 0, s_all->s_wave_c.start = 0;
    s_all->s_wave_c.strwave = strnbr(s_all->s_wave_c.min);
    parse_wave(s_all), update_player(s_all);
    s_all->s_wave_c.strwave = strnbr(0);
    my_strcat(s_all->s_wave_c.strwave, s_all->s_wave_c.base);
    sfText_setString(s_all->s_wave_c.text, s_all->s_wave_c.strwave);
    s_all->s_tuto = free_mobs(s_all->s_tuto);
    s_all->s_turret = free_turret(s_all->s_turret);
    s_all->s_map.map = adapt(temp->filepath);
    s_all->s_map.s_support = free_support(s_all->s_map.s_support);
    s_all->s_map.s_support = parse_map(s_all->s_map.map);
    s_all->s_map.castle_pos = get_castle_position(s_all);
    s_all->s_map.spawner_pos = get_spawner_position(s_all);
    generate_round_mobs(s_all);
    s_all->s_game.lost_anim = 0, s_all->s_game.transition = 1;
    if (s_all->s_settings->sound == 1)
        sfSound_play(s_all->s_sounds.button);
}

void map_selector_release(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    levels_t *temp = s_all->s_levels;
    if (s_all->s_game.scene != -1)
        return;
    while (temp != NULL) {
        if ((mouse_pos.x > temp->pos.x - (200 * temp->scale)
        && mouse_pos.x < temp->pos.x + (200 * temp->scale))
        && (mouse_pos.y > temp->pos.y - (117 * temp->scale)
        && mouse_pos.y < temp->pos.y + (117 * temp->scale))) {
            select_map(s_all, temp);
            s_all->s_stats.started += 1;
            temp->scale = 1;
            sfSprite_setScale(temp->sprite,
                (sfVector2f){temp->scale, temp->scale});
        } sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        temp = temp->next;
    }
}

void display_level_selector(all_t *s_all)
{
    levels_t *temp = s_all->s_levels;
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_menu.line, NULL);
    while (temp != NULL) {
        menu_level_hitbox(temp, s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}