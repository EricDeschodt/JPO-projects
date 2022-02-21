/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_button_texture
*/

#include <stdlib.h>
#include "defender.h"

sfTexture **get_button_textures(int i)
{
    sfIntRect area[] = { {0, 0, 500, 150}, {0, 150, 500, 150} };
    char *path = "assets/textures/buttons.jpg";
    sfTexture **textures;
    int iter = 0;

    textures = malloc(sizeof(sfTexture *) * i);
    for (int j = 0; j < i; j++, iter++) {
        iter = (iter > 1 ? 0 : iter);
        textures[j] = sfTexture_createFromFile(path, &area[iter]);
    }
    return (textures);
}