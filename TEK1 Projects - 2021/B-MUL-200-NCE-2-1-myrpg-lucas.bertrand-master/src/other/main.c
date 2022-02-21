/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void int_to_str(char *s, int n, int size)
{
    unsigned int i = 1000;

    if (size == 2)
        i = 10;
    else if (size == 5)
        i = 10000;
    if (((signed)n) < 0 ) {
        *s++ = '-';
        n = 0 - n;
    }
    do
        *s++ = '0' + (((n - n % i) / i) % 10);
    while (i /= 10);
    *s = 0;
}

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Beyond Stars", sfDefaultStyle, NULL);
    return (window);
}

int main(int ac, char **av)
{
    sfRenderWindow *window = createMyWindow(1920, 1080);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("\nUSAGE: ./my_rpg\n\n");
            my_putstr("DESCRIPTION: a turn-based rpg\n\n");
            my_putstr("COMMANDS: Use the key arrows or 'zqsd' to move ");
            my_putstr("and the mouse in the menu or fight.\n\n");
    }
    else if (ac == 1) {
        create_menu_one(window);
        sfRenderWindow_destroy(window);
    }
    else {
        sfRenderWindow_destroy(window);
        return (84);
    }
    return (0);
}
