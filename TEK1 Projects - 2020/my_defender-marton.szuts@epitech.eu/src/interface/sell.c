/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** sell
*/

#include "defender.h"
#include "utils.h"

void init_sell_button(all_t *s_all)
{
    s_all->s_sell.sprite = sfSprite_create();
    s_all->s_sell.texture =
    sfTexture_createFromFile("sprites/buttons/sell2.png", NULL);
    s_all->s_sell.clicked =
    sfTexture_createFromFile("sprites/buttons/sell1.png", NULL);
    sfSprite_setTexture(s_all->s_sell.sprite, s_all->s_sell.texture, sfTrue);
    s_all->s_sell.pos = (sfVector2f){2240, 925};
    sfSprite_setScale(s_all->s_sell.sprite, (sfVector2f){0.80, 0.80});
    sfSprite_setPosition(s_all->s_sell.sprite, s_all->s_sell.pos);
    s_all->s_sell.clic = 0;
}

int check_sell_hitbox(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x > s_all->s_sell.pos.x &&
        mouse_pos.x < s_all->s_sell.pos.x + 224)
        && (mouse_pos.y > s_all->s_sell.pos.y &&
        mouse_pos.y < s_all->s_sell.pos.y + 80)) {
            return (1);
        }
    return (0);
}

void click_sell_button(all_t *s_all)
{
    if (check_sell_hitbox(s_all) && s_all->s_side_menu.slide == 1 &&
    s_all->s_selected.sel->type == 'O' && s_all->s_side_menu.draw == 1 &&
    s_all->s_game.scene == 1) {
        sfSprite_setTexture(s_all->s_sell.sprite,
        s_all->s_sell.clicked, sfTrue);
        s_all->s_sell.clic = 1;
    }
}

void release_sell_button(all_t *s_all)
{
    turret_t *tmp = s_all->s_selected.tur, *temp = s_all->s_turret;
    if (tmp == NULL) return;
    while (temp != NULL) {
        if (temp->next == tmp) break;
        if (temp == tmp) break;
        temp = temp->next;
    } if (s_all->s_side_menu.slide == 1 && s_all->s_sell.clic == 1) {
        if (s_all->s_settings->sound == 1) sfSound_play(s_all->s_sounds.sell);
        sfSprite_setTexture(s_all->s_sell.sprite,
        s_all->s_sell.texture, sfTrue), s_all->s_selected.sel->on = 0;
        sfSprite_setTexture(s_all->s_side_menu.sprite,
        s_all->s_side_menu.texture2, sfTrue), s_all->s_stats.sold += 1;
        sfSprite_destroy(tmp->sprite_c), sfTexture_destroy(tmp->text_bullet);
        s_all->s_player.money += tmp->sell;
        s_all->s_player.strmoney = strnbr(s_all->s_player.money);
        sfText_setString(s_all->s_player.txt_money, s_all->s_player.strmoney);
        if (temp == tmp) s_all->s_turret = tmp->next, free(tmp);
        else temp->next = tmp->next, free(tmp);
        s_all->s_sell.clic = 0, s_all->s_selected.tur = NULL;
    }
}

void display_sell_button(all_t *s_all)
{
    if (s_all->s_selected.tur != NULL && s_all->s_selected.sel->on == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_sell.sprite, NULL);
}