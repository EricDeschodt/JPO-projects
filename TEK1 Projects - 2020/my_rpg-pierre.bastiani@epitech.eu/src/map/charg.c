/*
** EPITECH PROJECT, 2020
** charg
** File description:
** utils_loading
*/

#include "../../include/include.h"

void draw_charg(players *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprit_back, NULL);
    sfText_setString(player->charg,
    int_to_char(player->current*100/(player->max*2)));
    sfRenderWindow_drawText(window, player->charg, NULL);
    update(window);
}

void init_charg(players *player)
{
    player->charg = sfText_create();
    player->font = sfFont_createFromFile("assets/fonts.ttf");
    sfText_setColor(player->charg, (sfColor){214, 154, 78, 255});
    sfText_setCharacterSize(player->charg, 60);
    sfText_setScale(player->charg, (sfVector2f){3, 3});
    sfText_setFont(player->charg, player->font);
    sfSprite_setTexture(player->sprit_back, player->text_back, 0);
    sfText_setPosition(player->charg, (sfVector2f){920, 320});
}