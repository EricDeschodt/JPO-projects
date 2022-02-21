/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates a music
*/

#include "../../include/audio.h"

sfMusic *music_create(char *path, bool loop, float volume)
{
    if (!my_is_file_valid(path)) return NULL;
    sfMusic *music = sfMusic_createFromFile(path);
    if (loop) sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, volume);
    return music;
}

void music_set_status(sfMusic *music, char *status)
{
    if (!music) return;
    if (my_str_is_equal(status, "play")
        && sfMusic_getStatus(music) != sfPlaying) {
        sfMusic_play(music);
        return;
    } if (my_str_is_equal(status, "pause")) {
        sfMusic_pause(music);
        return;
    } if (my_str_is_equal(status, "stop")) {
        sfMusic_stop(music);
        return;
    } if (my_str_is_equal(status, "replay")) {
        sfMusic_play(music);
        return;
    }
}

void music_set_volume(sfMusic *music, float volume)
{
    if (!music) return;
    if (volume < 0) {
        sfMusic_setVolume(music, 0);
        return;
    }
    sfMusic_setVolume(music, volume);
}

void music_destroy(sfMusic *music)
{
    if (!music) return;
    sfMusic_stop(music);
    sfMusic_destroy(music);
}