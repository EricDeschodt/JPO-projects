/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** main
*/

#include "my.h"

void first_init2(all_t *all)
{
    srand(time(NULL));
    sfSprite_setPosition(all->sprite.michael, all->pos.pos_michael);
    sfSprite_setTextureRect(all->sprite.michael, all->rect.rect_michael);
    sfSprite_setPosition(all->sprite.jump, all->pos.pos_michael);
    sfSprite_setTextureRect(all->sprite.jump, all->rect.rect_jump);
    sfSprite_setPosition(all->sprite.hit, all->pos.pos_michael);
    sfSprite_setTextureRect(all->sprite.hit, all->rect.rect_hit);
    sfSprite_setPosition(all->sprite.crouch, all->pos.pos_crouch);
    sfSprite_setTextureRect(all->sprite.crouch_hit, all->rect.rect_crouch_hit);
    sfSprite_setPosition(all->sprite.crouch_hit, all->pos.pos_crouch);
    sfSprite_setTextureRect(all->sprite.up_throw, all->rect.rect_up_throw);
    sfSprite_setPosition(all->sprite.up_throw, all->pos.pos_michael);
    sfSprite_setTextureRect(all->sprite.down_throw, all->rect.rect_down_throw);
    sfSprite_setPosition(all->sprite.down_throw, all->pos.pos_crouch);
    sfSprite_setPosition(all->sprite.hat, all->pos.pos_hat);
    init_button(all);
}

void first_init(all_t *all)
{
    char *map = load_file_in_mem("maps/menu");
    first_init2(all);
    list_fat_zombie1(all, map);
    all->music = sfMusic_createFromFile("sounds/thriller.ogg");
    sfMusic_setVolume(all->music, 70);
    sfMusic_play(all->music);
    all->color = sfColor_fromRGBA(255, 155, 255, all->my_int.alpha);
    sfSprite_setColor(all->background.background1_2, all->color);
    sfSprite_setColor(all->background2.background2_1_2, all->color);
    all->rectangle = sfRectangleShape_create();
    sfVector2f size;
    size.x = 1920, size.y = 1080;
    sfRectangleShape_setSize(all->rectangle, size);
    sfTexture *rect_text =
        sfTexture_createFromFile("background/layer7_2.png", NULL);
    sfRectangleShape_setTexture(all->rectangle, rect_text, sfTrue);
    sfRectangleShape_setFillColor(all->rectangle, all->color);
    sfMusic_setLoop(all->music, sfTrue);
}

void reset_menu(all_t *all)
{
    char *map = load_file_in_mem("maps/menu");
    all->mobs = clear_list(all->mobs);
    list_fat_zombie1(all, map);
    sfClock_restart(all->clock.clock_total);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        manual();
    else {
        sfEvent event;
        all_t all = init_regroup(&all);
        first_init(&all);
        while (sfRenderWindow_isOpen(all.window)) {
            clock_set(&all), analyse_events(event, &all), draw_background(&all);
            parallax_pos(&all);
            if (all.my_int.ia == 1 && all.my_int.menu != 5) auto_hit(&all);
            if (load_map(&all, av[1]) == 84)
                break;
        } all.mobs = clear_list(all.mobs), destroy_regroup(&all);
    } return (0);
}
