/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** main2
*/

#include "my.h"

void main_pause_draw(all_t *all, sfEvent event)
{
    sfRenderWindow_drawSprite(all->window, all->sprite.background, NULL);
    regroup_if_choice(all, event);
    sfRenderWindow_drawSprite(all->window, all->sprite2.laugh_dog, NULL);
    sfRenderWindow_drawText(all->window, all->write.text2, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite.foreground, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.overlay2, NULL);
    sfRenderWindow_drawText(all->window, all->write.text5, NULL);
    sfRenderWindow_drawSprite(all->window, all->sprite2.ammo, NULL);
    sfRenderWindow_drawText(all->window, all->write.text6, NULL);
    draw_cursor(all);
}

void main_pause_dog(all_t *all)
{
    all->mouse_position = sfMouse_getPositionRenderWindow(all->window);
    if ((all->mouse_position.x >= all->pos.pos_menu_dog_pause.x + 10
        && all->mouse_position.x <= all->pos.pos_menu_dog_pause.x + 70)
        && (all->mouse_position.y >= all->pos.pos_menu_dog_pause.y + 10
        && all->mouse_position.y <= all->pos.pos_menu_dog_pause.y + 85)) {
        all->pos.pos_menu_dog_pause.x = rand() % 625;
        all->pos.pos_menu_dog_pause.y = 500;
    }
    if (all->pos.pos_menu_dog_pause.y > 364)
        all->pos.pos_menu_dog_pause.y -= 10;
}

void main_pause(all_t *all, sfEvent event)
{
    if (all->my_int.main_menu == 2) {
        main_pause_dog(all);
        all->my_int.menu_dog++;
        if (all->my_int.menu_dog > 8) {
            all->rect.laugh_dog.left = move_laugh_dog(all->rect.laugh_dog).left;
            all->my_int.menu_dog = 0;
        }
            analyse_events(event, all);
            sfSprite_setTextureRect(all->sprite2.laugh_dog,
                all->rect.laugh_dog);
            sfSprite_setPosition(all->sprite2.laugh_dog,
                all->pos.pos_menu_dog_pause);
            sfText_setPosition(all->write.text2, all->pos.pos_menu_pause_text);
            main_pause_draw(all, event);
            sfRenderWindow_display(all->window);
        }
}

void main_new_round(all_t *all, sfEvent event)
{
    if (all->my_int.main_menu == 3) {
        sfSprite_setPosition(all->sprite.dog, all->pos.pos_dog);
        sfSprite_setTextureRect(all->sprite.dog, all->rect.dog);
        if (all->my_int.state == 0) {
            clock_init(&all->clock);
            all->my_int.state++;
        }
        clock_set(all);
        main_walking(all, event);
        draw_cursor(all);
        sfRenderWindow_display(all->window);
    }
}

void main_render_game(sfEvent event)
{
    all_t all = init_regroup(&all);
    main_init(&all);
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.my_int.round_count >= 10) {
            all.pos.pos_round_nb.x = 174;
            sfText_setPosition(all.write.text5, all.pos.pos_round_nb);
        }
        main_game(event, &all);
        main_menu(event, &all);
        main_pause(&all, event);
        main_new_round(&all, event);
    }
    free(all.write.score);
    free(all.write.top_score);
    free(all.write.round_count_text);
    destroy_regroup(&all);
}