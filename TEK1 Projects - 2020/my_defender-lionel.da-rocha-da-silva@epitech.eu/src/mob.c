/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** mob
*/

#include "defender.h"

void create_mob_obj(char **filepath[], s_mob *obj, e_type type)
{
    sfText_setString(obj->text, my_itoa(obj->life));
    sfText_setScale(obj->text, (v2){0.5, 0.5});
    sfText_setColor(obj->text, sfRed);
    sfText_setPosition(obj->text, (v2){obj->pos.x - 30, obj->pos.y - 83});
    obj->attacked = sfFalse;
    for (int i = 0; i < 4; i++) {
        obj->textures[i] = sfTexture_createFromFile(filepath[type][i], NULL);
    }
    obj->sprite = sfSprite_create();
    obj->killed = sfFalse;
    obj->xp = sfFalse;
    sfSprite_setOrigin(obj->sprite, (sfVector2f){30, 71});
    sfSprite_setTexture(obj->sprite, obj->textures[3], sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    obj->atk_clock = sfClock_create();
    obj->color = sfSprite_getColor(obj->sprite);
    obj->blink = sfFalse;
    sfRectangleShape_setSize(obj->life_bar, (v2){40, 5});
    sfRectangleShape_setFillColor(obj->life_bar, sfRed);
}

s_mob *create_mob_object(char **filepath[], sfVector2f pos, e_type type)
{
    s_mob *obj = malloc(sizeof(*obj));
    obj->atk = 100 + type, obj->life = (1 + type) * 10 , obj->seconds = 1;
    obj->clock = sfClock_create();
    obj->time = sfClock_restart(obj->clock);
    obj->moveclock = sfClock_create();
    obj->movetime = sfClock_restart(obj->moveclock);
    obj->pos = pos, obj->moves = RIGHT, obj->dead = sfFalse;
    obj->x = 0, obj->y = 6, obj->state = STANDING;
    obj->type = type, obj->speed = (((float)type/10) + 0.1);
    obj->rect.height = 73, obj->rect.width = 60,
    obj->rect.top = 0, obj->rect.left = 0;
    obj->font = sfFont_createFromFile("res/fonts/pondesora.ttf");
    obj->text = sfText_create();
    obj->life_bar = sfRectangleShape_create();
    obj->t_life = obj->life;
    sfRectangleShape_setPosition(obj->life_bar,
    (v2){obj->pos.x - 30, obj->pos.y - 83});
    sfText_setFont(obj->text, obj->font);
    create_mob_obj(filepath, obj, type);
    return (obj);
}

void parse_wave(s_game *game, char *s)
{
    int i = 0, j = 0, k = 0;
    char *nb = malloc(5);
    while (s[i] != '\0') {
        for (; s[i] != ';'; i++, j++) {
            nb[j] = s[i];
        }
        nb[j] = '\0';
        game->wave_nbs[k] = my_atoi(nb);
        k++, i++, j = 0;
    }
}

s_wave *create_grid_struct(s_mob *mob, s_path **grid, int p)
{
    char *maps[] = {"maps/map1.txt", "maps/map2.txt", "maps/map3.txt",
    "maps/map4.txt", "maps/map5.txt"};
    int fd = open(maps[p], O_RDONLY), i = 0, x = 24, y = 24, n = 0, k = 0;
    char c;
    s_wave *wave = malloc(sizeof(*wave));
    wave->mob = mob;
    while (read(fd, &c, 1) > 0) {
        if (c == '\n') {
            x = 24, y += 48, n = 0, k++;
            continue;
        } i = find_flag(c);
        if (i < 9) {
        wave->grid[k][n].move = PREV, wave->grid[k][n].pos = (v2){x, y};
        } else if (i > 8 && i < 15){
            wave->grid[k][n].move = NEXT;
            wave->grid[k][n].pos = (v2){x, y};
        } x += 48, n++;
    }
    close(fd);
    return (wave);
}

void create_mob_e(s_game *game, int k, char ***path, int fd)
{
    char *s = NULL;
    for (int p = 0; p < 5; p++) {
        fd = open("maps/waves.txt", O_RDONLY), k = 0;
        s = get_next_line(fd);
        game->enemies[p] = malloc(sizeof(s_wave **) * 6);
        game->b_enemies[p] = malloc(sizeof(s_wave **) * 6);
        while (s != NULL) {
            parse_wave(game, s);
            game->enemies[p][k] =
            malloc(sizeof(s_wave *) * (game->wave_nbs[0] + 1));
            game->b_enemies[p][k] =
            malloc(sizeof(s_wave *) * (game->wave_nbs[0] + 1));
            create_wave(game, p, k, path);
            free(s);
            s = get_next_line(fd);
            k++;
        }
        free(s);
        close(fd);
    }
}