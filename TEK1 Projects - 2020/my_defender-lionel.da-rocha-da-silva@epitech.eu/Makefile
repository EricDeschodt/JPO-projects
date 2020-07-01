##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	my_defender

SRC	=	src/towers/tower_instances.c \
		src/towers/tower_definition.c \
		src/towers/tower_functions.c \
		src/towers/tower_upgrade.c \
		src/towers/tower_menu.c \
		src/towers/slot_init.c \
		src/towers/tower_attack.c \
		src/main_menu/menu_functions.c \
		src/main_menu/menu_buttons.c \
		src/main_menu/menu_route.c \
		src/main_menu/my_menu.c \
		src/main_menu/free_ui.c \
		src/lib_functions/button_selectable.c \
		src/lib_functions/my_put_nbr.c \
		src/lib_functions/button.c \
		src/lib_functions/text.c \
		src/main_menu/menu_pages/page_settings_onclicks.c \
		src/main_menu/menu_pages/page_settings_volume.c \
		src/main_menu/menu_pages/page_guide_file.c \
		src/main_menu/menu_pages/page_functions.c \
		src/main_menu/menu_pages/page_settings.c \
		src/main_menu/menu_pages/page_levels.c \
		src/main_menu/menu_pages/page_score.c \
		src/main_menu/menu_pages/page_guide.c \
		src/pause_menu/pause_toggle.c \
		src/pause_menu/pause_utils.c \
		src/pause_menu/pause_menu.c \
		src/input/is_mouse_hovering.c \
		src/input/input_functions.c \
		src/input/input.c \
		utils/my_list_1.c \
		utils/my_list.c \
		utils/get_next_line.c \
		utils/my_string.c \
		src/move1.c \
		src/defender.c \
		src/my_game.c \
		src/castle.c \
		src/move.c \
		src/map.c \
		src/mob.c \
		src/gameover.c \
		src/update_attack.c \
		src/game_update.c \
		src/usage.c \

OBJ     =	$(SRC:.c=.o)

CFLAGS  +=	-Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -g3

CFLAGS  +=	-I./include

CFLAGS	+=	-l csfml-graphics

CFLAGS	+=	-l csfml-window

CFLAGS	+=	-l csfml-system

CFLAGS	+=	-l csfml-audio

CFLAGS	+=	-l m


all     :	$(NAME)

$(NAME) :	$(OBJ)
		@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re      :	fclean all
		rm -f $(OBJ)

.SILENT	:	all fclean clean re

.PHONY	:	all fclean clean re
