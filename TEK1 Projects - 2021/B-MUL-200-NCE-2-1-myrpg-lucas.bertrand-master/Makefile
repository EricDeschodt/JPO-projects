##
## EPITECH PROJECT, 2021
## my_runner
## File description:
## Makefile
##

SRCS	=	src/story/intro.c	\
			src/other/main.c		\
			src/other/lib.c			\
			src/other/my_strncmp.c		\
			src/other/my_str_to_word_array.c		\
			src/other/create.c		\
			src/other/object.c		\
			src/other/destroy.c		\
			src/menu/create_menu.c		\
			src/menu/draw_menu.c	\
			src/menu/menu_event.c	\
			src/menu/option.c	\
			src/other/buttons_state.c \
			src/other/music_pause.c	\
			src/other/open_save.c	\
			src/other/save.c		\
			src/area/create_area.c	\
			src/area/area_event.c	\
			src/area/draw_area.c	\
			src/area/move.c		\
			src/area/tile.c		\
			src/area/bordure.c	\
			src/inventory/inventory.c	\
			src/inventory/health_item.c	\
			src/inventory/magic_item.c	\
			src/inventory/attack_item.c	\
			src/inventory/chest.c	\
			src/inventory/get_item.c	\
			src/story/story.c	\
			src/other/time.c	\
			src/fight/init_fight.c	\
			src/fight/create_fight.c\
			src/fight/draw_fight.c	\
			src/fight/fight_event.c	\
			src/fight/verif_fight.c	\
			src/fight/attack.c		\
			src/fight/enemy_fight.c	\
			src/area/next_map.c		\
			src/story/dialogue.c	\
			src/story/boss_intro.c	\
			src/story/boss_dialogue.c	\
			src/story/after_boss.c	\
			src/story/after_boss_dialogue.c	\
			src/story/before_ultimate_boss.c	\
			src/boss/create_boss_fight.c \
			src/boss/draw_boss_fight.c	\
			src/boss/verif_boss.c	\
			src/boss/enemy_boss_fight.c \
			src/ultimate_fight/create_ultimate_fight.c	\
			src/ultimate_fight/draw_ultimate_fight.c	\
			src/ultimate_fight/animation.c	\
			src/ultimate_fight/ultimate_fight_event.c	\
			src/ultimate_fight/verif_ultimate_fight.c	\
			src/ultimate_fight/ultimate_enemy_fight.c	\
			src/fight/game_over.c	\
			src/story/ending.c	\
			src/story/anim_ending.c \
			src/story/end.c	\
			src/story/end_credit.c	\

OBJ		=	$(SRCS:.c=.o)

NAME	=	my_rpg

FLAGS	=	-W				\
			-Wextra			\
			-Werror			\
			-Wall			\
			-g3				\

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ) -lcsfml-system -lcsfml-window -lcsfml-audio -lcsfml-graphics

all:		$(NAME)

clean:
		rm -f *~
		rm -f src/menu/*.c~
		rm -f src/menu/*.o
		rm -f src/menu/#*#
		rm -f src/area/*.c~
		rm -f src/area/*.o
		rm -f src/area/#*#
		rm -f src/story/*.c~
		rm -f src/story/*.o
		rm -f src/story/#*#
		rm -f src/inventory/*.c~
		rm -f src/inventory/*.o
		rm -f src/inventory/#*#
		rm -f src/fight/*.c~
		rm -f src/fight/*.o
		rm -f src/fight/#*#
		rm -f src/boss/*.c~
		rm -f src/boss/*.o
		rm -f src/boss/#*#
		rm -f src/ultimate_fight/*.c~
		rm -f src/ultimate_fight/*.o
		rm -f src/ultimate_fight/#*#
		rm -f src/other/*.c~
		rm -f src/other/*.o
		rm -f src/other/#*#
		rm -f include/*.h~
		rm -f save/*~
		rm -f map/*~

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
