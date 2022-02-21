##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compiles the code
##

SRC	=	lib/print/src/my_putchar.c	\
		lib/print/src/my_put_nbr.c	\
		lib/print/src/my_putstr.c	\
		lib/print/src/my_put_bool.c	\
		lib/print/src/my_put_nstrm.c	\
		lib/print/src/my_showmem.c	\
		lib/print/src/my_showstr.c	\
		lib/print/src/my_printf/core.c	\
		lib/print/src/my_printf/main.c	\
		lib/print/src/my_printf/formats/char.c	\
		lib/print/src/my_printf/formats/core.c	\
		lib/print/src/my_printf/formats/long.c	\
		lib/print/src/my_printf/formats/nbr.c	\
		lib/print/src/my_printf/formats/pointer_adress.c	\
		lib/print/src/my_printf/formats/simple_str.c	\
		lib/print/src/my_printf/formats/str_w_oct.c	\
		lib/print/src/my_printf/formats/unsigned_bin.c	\
		lib/print/src/my_printf/formats/unsigned_hexadecimal.c	\
		lib/print/src/my_printf/formats/unsigned_int.c	\
		lib/print/src/my_printf/formats/unsigned_maj_hexadecimal.c	\
		lib/print/src/my_printf/formats/unsigned_octal.c	\
		lib/converts/src/my_getnbr.c	\
		lib/converts/src/my_str_to_word_array.c	\
		lib/ints/src/my_compute_power_rec.c	\
		lib/ints/src/my_compute_square_root.c	\
		lib/ints/src/my_find_prime_sup.c	\
		lib/ints/src/my_isneg.c	\
		lib/ints/src/my_is_prime.c	\
		lib/ints/src/my_sort_int_array.c	\
		lib/ints/src/my_swap.c	\
		lib/strings/src/edits/my_revstr.c	\
		lib/strings/src/edits/my_strcapitalize.c	\
		lib/strings/src/edits/my_strcat.c	\
		lib/strings/src/edits/my_strcpy.c	\
		lib/strings/src/edits/my_strdup.c	\
		lib/strings/src/edits/my_strlowcase.c	\
		lib/strings/src/edits/my_strncat.c	\
		lib/strings/src/edits/my_strncpy.c	\
		lib/strings/src/edits/my_strnncpy.c	\
		lib/strings/src/edits/my_strstr.c	\
		lib/strings/src/edits/my_strupcase.c	\
		lib/strings/src/tests/my_count.c	\
		lib/strings/src/tests/my_index.c	\
		lib/strings/src/tests/my_is_char_in_str.c	\
		lib/strings/src/tests/my_strcmp.c	\
		lib/strings/src/tests/my_str_isalpha.c	\
		lib/strings/src/tests/my_str_isint.c	\
		lib/strings/src/tests/my_str_islower.c	\
		lib/strings/src/tests/my_str_isnum.c	\
		lib/strings/src/tests/my_str_isprintable.c	\
		lib/strings/src/tests/my_str_isupper.c	\
		lib/strings/src/tests/my_strlen.c	\
		lib/strings/src/tests/my_strncmp.c	\
		lib/files/src/my_get_file_ctn.c	\
		lib/files/src/my_is_file_valid.c	\
		lib/tabs/src/tab_create.c	\
		lib/tabs/src/tab_free.c	\
		lib/tabs/src/tab_print.c	\
		lib/tabs/src/tab_stat.c	\
		lib/graphical/src/sprites/sprite_create.c	\
		lib/graphical/src/sprites/sprite_edit.c	\
		lib/graphical/src/sprites/sprite_display.c	\
		lib/graphical/src/sprites/sprite_destroy.c	\
		lib/graphical/src/sprites/sprite_edit_texturerect.c	\
		lib/graphical/src/buttons/button_create.c	\
		lib/graphical/src/buttons/button_display.c	\
		lib/graphical/src/buttons/button_tests.c	\
		lib/graphical/src/window/window_create.c    \
		lib/graphical/src/events/events.c    \
		lib/graphical/src/textures/texture_create.c	\
		lib/graphical/src/text/text_create.c        \
		lib/graphical/src/text/text_edit.c        \
		lib/graphical/src/text/text_display.c        \
		lib/graphical/src/text/text_destroy.c        \
		lib/graphical/src/text/text_converts.c          \
		lib/graphical/src/radio_buttons/radio_buttons.c	\
		lib/graphical/src/radio_buttons/radio_buttons_tests.c	\
		lib/graphical/src/audio/sound_create.c \
		lib/graphical/src/audio/music_create.c \
		lib/linked_lists/src/linked_list_edit.c	\
		lib/linked_lists/src/linked_list_free.c	\
		lib/linked_lists/src/linked_list_print.c	\
		lib/linked_lists/src/linked_list_tests.c	\
		lib/flags/src/core.c	\
		lib/flags/src/help.c	\
		src/level_menu/level_menu.c    \
		src/level_menu/levels.c        \
		src/level_menu/level_menu_events.c \
		src/game/main_game_create.c	    \
		src/game/main_game.c	    \
		src/game/draw_map.c     \
		src/game/sidebar/sidebar_create.c	\
		src/game/sidebar/sidebar.c  \
		src/game/sidebar/sidebar_extend.c  \
		src/game/sidebar/upgrade_events.c   \
		src/game/sidebar/upgrade_update.c   \
		src/game/enemies/get_start.c     \
		src/game/enemies/spawn_enemies.c    \
		src/game/enemies/create_enemy.c \
		src/game/enemies/init_enemies.c  \
		src/game/enemies/enemies_test.c	\
		src/game/enemies/create_texturelist.c       \
		src/game/enemies/pathfinding/move_angle.c   \
		src/game/enemies/pathfinding/move_basic.c   \
		src/game/enemies/pathfinding/move_start.c   \
		src/game/enemies/pathfinding/pathfinder.c   \
		src/game/enemies/pathfinding/get_index_sprite.c \
		src/game/turrets/turrets.c  \
		src/game/turrets/turret_setpos.c  \
		src/game/turrets/turret_create.c  \
		src/game/turrets/turret_trigger.c  \
		src/game/turrets/turret_angle.c  \
		src/game/turrets/turret_fire.c  \
		src/game/turrets/turret_place.c  \
		src/game/turrets/bullets/bullet.c  \
		src/game/turrets/bullets/bullet_create.c  \
		src/game/game_menu_events.c      \
		src/end_menu/end_menu.c      \
		src/end_menu/end_menu_events.c      \
		src/pause_menu/pause_menu.c    \
		src/pause_menu/pause_menu_events.c    \
		src/main_menu/main_menu.c	    \
		src/main_menu/main_menu_events.c	    \
		src/scoreboard/scoreboard.c    \
		src/scoreboard/scoreboard_events.c    \
		src/scoreboard/scoreboard_load.c   \
		src/scoreboard/scoreboard_add.c    \
		src/how_to_play_menu/how_to_play.c  \
		src/how_to_play_menu/how_to_play_events.c  \
		src/how_to_play_menu/manual.c  \
		src/how_to_play_menu/manual_events.c  \
		src/settings_menu/settings_create.c	\
		src/settings_menu/settings.c    \
		src/settings_menu/settings_menu_events.c    \
		src/settings_menu/setting_update.c    \
		src/settings_menu/setting_update_game.c    \
		src/time.c	        \
		src/sounds.c	\
		src/elements.c	    \
		src/elements_extend.c   \
		src/mouse_events.c  \
		src/background.c    \
		src/main.c          \

NAME	=	my_defender

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)
		rm -rf $(OBJ)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l \
		csfml-system -l csfml-audio -lm

setflag:
		$(eval CFLAGS	=	-g3)

debug: setflag $(OBJ)
		gcc -o $(NAME) $(OBJ) -g3 -l csfml-graphics -l csfml-window -l \
		csfml-system -l csfml-audio -lm
		rm -rf $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

cc:	all clean
