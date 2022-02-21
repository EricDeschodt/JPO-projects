/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utils for screensaver
*/

#include "include/my.h"

void print_help(int index)
{
    if (index == 0) {
        my_putstr("USAGE:\n");
        my_putstr("\t./my_screensaver \tanimation_id\n");
        my_putstr("\tanimation_id\tthe animation number between 1 and 5\n");
        my_putstr("\tnumber and description of animations by typing -d\n");
        exit(0);
    }
    if (index == 1) {
        my_putstr("Animation 1 : \n");
        my_putstr("Animation 2 : \n");
        my_putstr("Animation 3 : \n");
        my_putstr("Animation 4 : \n");
        my_putstr("Animation 5 : \n");
        exit(0);
    }
}

int error_gestion(int ac, char **av)
{
    int i = 0;
    int index = 3;
    if (ac != 2) {
        my_putstr("invalid number of arguments\n");
        return (1);
    }
    if (av[1][0] == '-') {
        av[1][1] == 'h' ? index = 0 : (void) i;
        av[1][1] == 'd' ? index = 1 : (void) i;
        print_help(index);
        return (0);
    if (av[1][1] != 'h' && av[1][1] != 'd') {
            my_putstr("Error unknown argument\n");
            return (1);
        }
    }
}

void which_anim(int anim)
{
    int i = 0;
    anim == 1 ? anim_1() : (void) i;
    anim == 2 ? anim_2() : (void) i;
    anim == 3 ? anim_3() : (void) i;
    anim == 4 ? anim_4() : (void) i;
    anim == 5 ? anim_5() : (void) i;
}

void init_struct(screen *anim, char *name, sfVideoMode mode)
{
    anim->window = sfRenderWindow_create(mode, name,
                                    sfResize | sfClose, NULL);
    anim->event;
    anim->texture = sfTexture_create(800, 600);
    anim->sprite = sfSprite_create();
    anim->framebuffer = framebuffer_create(800, 600);
}

void sf_destroy(screen *anim)
{
    framebuffer_destroy(anim->framebuffer);
    sfSprite_destroy(anim->sprite);
    sfTexture_destroy(anim->texture);
    sfRenderWindow_destroy(anim->window);
}