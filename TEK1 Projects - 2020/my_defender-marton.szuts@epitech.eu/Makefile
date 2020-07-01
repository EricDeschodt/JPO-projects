##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_defender

CC	=	gcc

SRC	=	src/core/start.c \
		src/core/event_controll.c \
		src/core/message.c \
		src/core/display.c \
		src/core/game_loop.c \
		src/core/clock.c \
		src/core/init_all.c \
		src/core/init_all2.c \
		src/core/destroy.c \
		src/core/sounds.c \
		src/core/free_link.c \
		src/core/clocks2.c \
		src/core/destroy_sounds.c \
		src/core/destroy2.c \
		src/core/destroy_mobs.c \
		src/game/display_annex.c \
		src/game/custom_level_selector.c \
		src/game/settings.c \
		src/game/settings2.c \
		src/game/custom_level_selector2.c \
		src/game/wave2.c \
		src/game/move.c \
		src/game/turret_support.c \
		src/game/pathfinding.c \
		src/game/turret.c \
		src/game/upgrade.c \
		src/game/level_selector.c \
		src/game/level_selector2.c \
		src/game/mobs.c \
		src/game/wave.c \
		src/game/generate_custom_map.c \
		src/game/map_editor.c \
		src/math/turret_shooting.c \
		src/math/turret_rotate.c \
		src/math/turret_shooting2.c \
		src/math/turret_aoe.c \
		src/math/turret_slow.c \
		src/math/turret_shooting3.c \
		src/interface/wave_button.c \
		src/interface/slider.c \
		src/interface/slider_arrow.c \
		src/interface/targetting2.c \
		src/interface/pause.c \
		src/interface/transition.c \
		src/interface/menu3.c \
		src/interface/transition2.c \
		src/interface/statistics2.c \
		src/interface/turret_abilities.c \
		src/interface/init_turret_abilities.c \
		src/interface/turret2.c \
		src/interface/slider3.c \
		src/interface/turret_abilities2.c \
		src/interface/turret_abilities3.c \
		src/interface/turret_abilities4.c \
		src/interface/upgrade_button.c \
		src/interface/menu.c \
		src/interface/menu2.c \
		src/interface/count_wave_button.c \
		src/interface/player2.c \
		src/interface/tuto.c \
		src/interface/targetting.c \
		src/interface/button_init.c \
		src/interface/selected_turret.c \
		src/interface/selected2.c \
		src/interface/info_text.c \
		src/interface/player.c \
		src/interface/slider2.c \
		src/interface/sell.c \
		src/interface/creator_buttons.c \
		src/interface/creator_buttons2.c \
		src/interface/stats.c \
		src/interface/turret_select.c \
		src/interface/selected.c \
		src/interface/statistics.c \
		src/interface/side_menu.c \
		src/interface/turret_area.c \
		utils/my_strlen.c \
		utils/save_map.c \
		utils/my_ptr_len.c \
		utils/list_utils_targetting.c \
		utils/my_strdup.c \
		utils/my_put_strnbr.c \
		utils/list_utils_buttons.c \
		utils/get_next_line.c \
		utils/my_atoi.c \
		utils/list_utils_buttons2.c \
		utils/get_file.c \
		utils/randomize.c \
		utils/map_error_handling.c \
		utils/get_int.c \
		utils/list_utils_settings.c \
		utils/parse_map.c \
		utils/list_utils_targetting2.c \
		utils/my_strcat.c \
		utils/wave_parsor.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS  +=	-lm

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
