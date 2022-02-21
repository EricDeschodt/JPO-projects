/*
** EPITECH PROJECT, 2020
** bootstrap graphique lourd
** File description:
** the main of my runner
*/

#include "../include/elements.h"
#include "../include/menus.h"

void event_loop(elements_t *e)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(e->window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(e->window);
        if (event.key.code == sfKeySpace && e->menu == 1 && (get_crn_blk
        (e->map, e->chr, 2, 1)
        == 1 || get_crn_blk(e->map, e->chr, 3, 1) == 1)) {
            e->chr->is_jumping = true;
            sfSound_play(e->audio->jump);
        }
        if (event.type == sfEvtMouseButtonReleased && e->menu != 1 &&
        is_sprite_on_hover(e->interface->play, e->window))
            switch_menu(e, 1);
    }
}

bool window_loop(char *filename)
{
    elements_t *e = create_elements(filename);
    if (!e)
        return false;
    while (sfRenderWindow_isOpen(e->window)) {
        event_loop(e);
        bool res = true;
        res = animate_elements(e);
        display_elements(e);
        if (e->menu && (!res || e->map->rang >= e->map->x))
            switch_menu(e, 0);
    }
    sfRenderWindow_close(e->window);
    destroy_elements(e);
    return true;
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n\t./my_runner [map] [flags]\nDESCRIPTION\n\t"
        "You're playing a character which goal is to run as far as "
        "possible.\nOPTIONS\n\tmap : adress of a file, "
        "containing a valid map for the game.\n\t"
        "flags (optionnal) :\n\t\t-h : display this screen"
        "\nCONTROLS\n\tUse the space bar to jump and avoid obstacles."
        " Use the mouse for navigate threw menus\n");
        return 0;
    }
    else if (argc != 2)
        return 84;
    if (!window_loop(argv[1]))
        return 84;
}

//TODO: améliorer error handling
//TODO: améliorer menu
//TODO: améliorer animation de saut