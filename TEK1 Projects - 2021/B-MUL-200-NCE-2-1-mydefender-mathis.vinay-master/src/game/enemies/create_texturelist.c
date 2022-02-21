/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** creates a list of textures
*/

#include "../../../include/game/main_game.h"

void init_enemies(sfTexture **texture_list)
{
    texture_list[0] = texture_create("assets/enemies/weak_enemy.png",
    false, false);
    texture_list[1] = texture_create("assets/enemies/normal_enemy.png",
    false, false);
    texture_list[2] = texture_create("assets/enemies/strong_enemy.png",
    false, false);
    texture_list[3] = texture_create("assets/enemies/hard_enemy.png",
    false, false);
    texture_list[4] = texture_create("assets/enemies/weak_tank.png",
    false, false);
    texture_list[5] = texture_create("assets/enemies/strong_tank.png",
    false, false);
}

void init_turrets(sfTexture **texture_list)
{
    texture_list[6] = texture_create("assets/turrets/g1.png", false, false);
    texture_list[7] = texture_create("assets/turrets/g2.png", false, false);
    texture_list[8] = texture_create("assets/turrets/m1.png", false, false);
    texture_list[9] = texture_create("assets/turrets/s1.png", false, false);
    texture_list[10] = texture_create("assets/turrets/bul.png", false, false);
    texture_list[11] = texture_create("assets/turrets/bul2.png", false, false);
    texture_list[12] = texture_create("assets/turrets/mis2.png", false, false);
    texture_list[13] = texture_create("assets/turrets/fire.png", false, false);
}

void init_life(sfTexture **texture_list)
{
    texture_list[14] = texture_create("assets/enemies/lifebar_back.png", false,
    false);
    texture_list[15] = texture_create("assets/enemies/lifebar_front.png", false,
    false);

}

sfTexture **create_texturelist(void)
{
    sfTexture **texture_list = malloc(sizeof(sfTexture * ) * 17);
    init_enemies(texture_list);
    init_turrets(texture_list);
    init_life(texture_list);
    texture_list[16] = NULL;
    return texture_list;
}