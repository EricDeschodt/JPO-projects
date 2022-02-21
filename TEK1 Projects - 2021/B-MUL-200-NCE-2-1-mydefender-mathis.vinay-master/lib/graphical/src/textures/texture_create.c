/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** allows the creation of a texture, ignoring errors
*/

#include "../../include/textures.h"

sfTexture *get_texture(char const *filepath)
{
    if (my_is_file_valid(filepath))
        return sfTexture_createFromFile(filepath, NULL);
    if (my_is_file_valid("lib/graphical/assets/no_asset.png"))
        return sfTexture_createFromFile("lib/graphical/assets/no_asset.png",
        NULL);
    return sfTexture_create(200, 200);
}

sfTexture *texture_create(char const *filepath, bool is_repeted, bool is_smooth)
{
    sfTexture *texture = get_texture(filepath);
    if (is_repeted)
        sfTexture_setRepeated(texture, sfTrue);
    if (is_smooth)
        sfTexture_setSmooth(texture, sfTrue);
    return texture;
}