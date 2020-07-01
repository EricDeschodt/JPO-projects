/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** custom_level_selector
*/

#include "defender.h"
#include "utils.h"

void restart_level(all_t *s_all)
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
    s_all->s_map.s_support = free_support(s_all->s_map.s_support);
    s_all->s_map.s_support = parse_map(s_all->s_map.map);
    s_all->s_map.castle_pos = get_castle_position(s_all);
    s_all->s_map.spawner_pos = get_spawner_position(s_all);
    generate_round_mobs(s_all);
    s_all->s_game.pause = 0, s_all->s_game.lost_anim = 0;
    s_all->s_game.transition = 1, s_all->s_hard_arrow.stat = 1;
    s_all->s_selected.on = 0, s_all->s_side_menu.draw = 0;
}

levels_t *fill_custom(levels_t *old, int id, sfVector2f pos, all_t *s_all)
{
    levels_t *new = malloc(sizeof(levels_t));
    char *name = malloc(sizeof(char) * 15), *strid = strnbr(id);
    name[0] = '\0', my_strcat(name, "custom_map_");
    my_strcat(name, strid), new->name = sfText_create();
    new->filepath = malloc(sizeof(char) * 100), new->filepath[0] = '\0';
    my_strcat(new->filepath, "custom_maps/"), my_strcat(new->filepath, name);
    sfText_setString(new->name, name);
    sfText_setPosition(new->name, (sfVector2f){pos.x - 82, pos.y - 93});
    sfText_setFont(new->name, s_all->s_game.font);
    new->sprite = sfSprite_create(), new->clock = sfClock_create();
    new->texture = sfTexture_createFromFile("sprites/buttons/custom_iddle.png",
    NULL);
    new->click = sfTexture_createFromFile("sprites/buttons/custom_select.png",
    NULL), new->scale = 1;
    new->pos = pos, sfSprite_setPosition(new->sprite, pos);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfText_setCharacterSize(new->name, 23);
    sfSprite_setOrigin(new->sprite, (sfVector2f){100, 59});
    new->next = old;
    return (new);
}

void init_custom_level_buttons(all_t *s_all)
{
    DIR *dirp = opendir("custom_maps");
    struct dirent *my_dirent;
    s_all->s_custom = NULL;
    int i = 0;
    sfVector2f pos = (sfVector2f){130, 750};
    for (; (my_dirent = readdir(dirp)) != NULL;) {
        if (my_dirent->d_name[0] != '.') i++;
    } closedir(dirp);
    for (int y = 1; y != i + 1; y++) {
        if (y == 9) pos = (sfVector2f){130, 930};
        s_all->s_custom = fill_custom(s_all->s_custom, y, pos, s_all);
        pos.x += 230;
    }
}

void custom_map_selector_release(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    levels_t *temp = s_all->s_custom;
    if (s_all->s_game.scene != -1)
        return;
    while (temp != NULL) {
        if ((mouse_pos.x > temp->pos.x - (100 * temp->scale)
        && mouse_pos.x < temp->pos.x + (100 * temp->scale))
        && (mouse_pos.y > temp->pos.y - (59 * temp->scale)
        && mouse_pos.y < temp->pos.y + (59 * temp->scale))) {
            select_map(s_all, temp);
            temp->scale = 1;
            sfSprite_setScale(temp->sprite,
                (sfVector2f){temp->scale, temp->scale});
        } sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        temp = temp->next;
    }
}

void display_custom_buttons(all_t *s_all)
{
    levels_t *temp = s_all->s_custom;
    while (temp != NULL) {
        custom_menu_level_hitbox(temp, s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        sfRenderWindow_drawText(s_all->s_game.window, temp->name, NULL);
        temp = temp->next;
    }
}