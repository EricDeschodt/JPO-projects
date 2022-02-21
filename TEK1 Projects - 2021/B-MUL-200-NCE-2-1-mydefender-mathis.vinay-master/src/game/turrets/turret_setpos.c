/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Set Position and scale for a turret
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

void turret_set(main_game_t *g, turret_t *turret, sfVector2f pos)
{
    sfVector2u size = sfTexture_getSize(g->texture_list[9]);
    sfVector2f origin = {(float) size.x / 2, (float) size.y / 2};
    sfSprite_setOrigin(turret->turret, origin);
    sfVector2f scale = {(float)((1080.0 / (double)(get_len_array(g->map)))
    / 128), (float)((1080.0 / (double)(get_len_array(g->map))) / 128)};
    sfSprite_setScale(turret->turret, scale);
    sfSprite_setPosition(turret->turret, pos);
}