/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** All functions related to levels management
*/

#include "../../include/levels.h"

levels_t *levels_create(void)
{
    levels_t *lvl = malloc(sizeof(levels_t));
    if (!my_is_file_valid("maps/list_maps.txt"))
        return NULL;
    char *buffer = my_get_file_ctn("maps/list_maps.txt");
    lvl->list_lvl = tab_create(buffer);
    lvl->list_index = 0;
    char *tmp_sprite = my_strcat(lvl->list_lvl[lvl->list_index], "/logo.png");
    lvl->lvl_image = sprite_create(tmp_sprite, "C", false, false);
    sprite_set_pos(lvl->lvl_image, 960, 300, (float) 0.5);
    lvl->lvl_title_text = text_create(&lvl->list_lvl[lvl->list_index][5],
                                        "C", sfWhite, false);
    text_set_outline(lvl->lvl_title_text, sfBlack, 3);
    text_set_pos(lvl->lvl_title_text, 960, 525, 70);
    text_set_origin(lvl->lvl_title_text, "C");
    free(tmp_sprite);
    free(buffer);
    return lvl;
}

void levels_update(levels_t *lvl)
{
    if (lvl->list_index < 0) lvl->list_index = 0;
    if (lvl->list_index > 2) lvl->list_index = 2;
    char *tmp_sprite = my_strcat(lvl->list_lvl[lvl->list_index], "/logo.png");
    sfTexture_destroy(lvl->lvl_image->texture);
    lvl->lvl_image->texture = sfTexture_createFromFile(tmp_sprite, NULL);
    sfSprite_setTexture(lvl->lvl_image->sprite,
    lvl->lvl_image->texture, sfFalse);
    sfText_setString(lvl->lvl_title_text->text,
    &lvl->list_lvl[lvl->list_index][5]);
    text_set_origin(lvl->lvl_title_text, "C");
    free(tmp_sprite);
}

void levels_display(levels_t *lvl, sfRenderWindow *win)
{
    text_display(lvl->lvl_title_text, win);
    sprite_display(lvl->lvl_image, win);
}

void levels_destroy(levels_t *lvl)
{
    if (!lvl) return;
    if (!lvl->lvl_image) return;
    sprite_destroy(lvl->lvl_image);
    text_destroy(lvl->lvl_title_text);
    tab_free(lvl->list_lvl);
    free(lvl);
}