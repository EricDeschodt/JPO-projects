/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** handle_enemies
*/

#include "defender.h"
#include "elements.h"

static void prepare_zombie(sfVector2f *size, sfIntRect *texture)
{
    if (get_random_pos(0, 4).y == 1) {
        sfVector2f big_zombie_size = {128, 122};
        (*texture).left = get_random_pos(0, 3).y * 512;
        if ((*texture).left >= 1024) {
            (*texture).left -= 1024;
            big_zombie_size.y = 128;
            (*texture).top = 195;
            (*texture).height = 122;
        } else {
            (*texture).top = 68;
            (*texture).height = 128;
        }
        (*texture).width = 128;
        *size = big_zombie_size;
    } else {
        (*texture).left = get_random_pos(0, 4).y * 144;
        (*texture).height = 65;
        (*texture).width = 48;
        (*texture).top = 0;
    }
}

static obj_t *choose_zombie(sfVector2f *pos,    \
                sfVector2f *size, sfIntRect *texture_area)
{
    sfIntRect texture;
    obj_t *enemy;

    prepare_zombie(size, &texture);
    *pos = center_pos(get_random_pos(373, 821));
    enemy = init_object(*pos, *size, NULL);
    if (texture.width >= 100)
        enemy->stats.speed = 0.3;
    else
        enemy->stats.speed = 0.5;
    enemy->stats.row = (*pos).y;
    enemy->stats.max_range = 634;
    enemy->stats.is_slowed = 0;
    enemy->random_texture = texture;
    (*texture_area) = texture;
    return (enemy);
}

static void new_enemies_sett(obj_t *enemy, sfVector2f size_b, sfVector2f pos_a)
{
    if (enemy->pos_size.width > 50) {
        enemy->stats.damage = 3;
        size_b.x += 64;
        enemy->health = *handle_health_bar(pos_a, size_b);
    } else {
        enemy->stats.damage = 1;
        enemy->health = *handle_health_bar(pos_a, size_b);
    }
    enemy->frame = 0;
    enemy->stop = 0;
    enemy->next = NULL;
}

void new_enemies(game_t *gm)
{
    char path[] = "assets/textures/enemies_ss.png";
    sfVector2f size = {48, 65}, size_b = {64, 64};
    sfIntRect texture_area = {0, 0, 48, 65};
    sfTexture *texture;
    sfVector2f pos, pos_a;
    obj_t *enemy;

    if (!gm->en->head) return;
    enemy = choose_zombie(&pos, &size, &texture_area);
    texture = sfTexture_createFromFile(path, &texture_area);
    enemy->body.rect = create_rectangle(pos, size, texture, sfFalse);
    enemy->frame_clock = sfClock_create();
    pos_a = sfRectangleShape_getPosition(enemy->body.rect);
    new_enemies_sett(enemy, size_b, pos_a);
    enemy->head = gm->en->head;
    sfMusic_play(gm->sound[2]);
    sfMusic_setVolume(gm->sound[2], 2.0);
    for (gm->en = gm->en->head; gm->en->next; gm->en = gm->en->next);
    gm->en->next = enemy;
}
