/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates and handles the main menu
*/

#include "../../include/end_menu.h"

void endgame_add_your_score(end_game_t *endGame, int score)
{
    char *str = malloc(sizeof(char) * 999);
    endGame->your_score_str = "Your Score: ";
    endGame->your_score_str = my_strcat(endGame->your_score_str,
    int_to_str(str, score));
    sfText_setString(endGame->your_score_text->text, endGame->your_score_str);
    free(str);
}

void end_game_set_texts(end_game_t *end_game)
{
    end_game->your_score_text = text_create("No Score Registered",
                                            "C", sfWhite, false);
    text_set_pos(end_game->your_score_text, 960, 300, 50);
}

end_game_t *end_game_create(void)
{
    end_game_t *end_game = malloc(sizeof(end_game_t));
    end_game->replay_button =
    button_create("assets/gui/replay_button.png", "C");
    end_game->exit_button =
    button_create("assets/gui/exit_button.png", "C");
    end_game->main_menu_button =
    button_create("assets/gui/menu_button.png", "C");
    end_game->score_button =
    button_create("assets/gui/scoreboard.png", "C");
    end_game->htp_button = button_create("assets/gui/help_button.png", "C");
    sprite_set_pos(end_game->replay_button, 960, 600, 1);
    sprite_set_pos(end_game->htp_button, 420, 850, 1);
    sprite_set_pos(end_game->main_menu_button, 960, 725, 1);
    sprite_set_pos(end_game->exit_button, 960, 850, 1);
    sprite_set_pos(end_game->score_button, 1500, 850, 1);
    end_game->your_score_str = NULL;
    end_game_set_texts(end_game);
    return end_game;
}

void end_game_display(end_game_t *end_game, sfRenderWindow *win)
{
    button_display(end_game->exit_button, win, true);
    button_display(end_game->main_menu_button, win, true);
    button_display(end_game->score_button, win, true);
    button_display(end_game->htp_button, win, true);
    button_display(end_game->replay_button, win, true);
    text_display(end_game->your_score_text, win);
}

void end_game_destroy(end_game_t *end_game)
{
    sprite_destroy(end_game->htp_button);
    sprite_destroy(end_game->exit_button);
    sprite_destroy(end_game->main_menu_button);
    sprite_destroy(end_game->score_button);
    sprite_destroy(end_game->replay_button);
    free(end_game->your_score_str);
    text_destroy(end_game->your_score_text);
    free(end_game);
}
