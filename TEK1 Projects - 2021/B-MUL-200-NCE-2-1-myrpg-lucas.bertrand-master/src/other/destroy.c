/*
** EPITECH PROJECT, 2021
** graphical
** File description:
** destroy
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void destroy_sound(sfSound *sound, sfSoundBuffer *buffer)
{
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(buffer);
}

void destroy_text(sfText *text, sfFont *font)
{
    sfText_destroy(text);
    sfFont_destroy(font);
}
