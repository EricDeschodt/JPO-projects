##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

CC	=	gcc -g3

RM	=	rm -f

SRC	=	main.c \
		src/map/door.c \
		src/event/inventory.c \
		src/event/init_inventory.c \
		src/event/utils_fight.c \
		src/animation/utils_anim.c \
		src/utils_nb_util.c \
		src/map/sprit_player.c \
		src/event/utils_cine.c \
		src/event/utils_mob.c \
		src/event/utils_pnj.c \
		src/map/utils_colli.c \
		src/map/utils_player.c \
		src/game.c \
		src/statment.c \
		src/life/life.c \
		src/map/map.c \
		src/map/utils_state.c \
		src/map/utils_map.c \
		src/sprite/sprite.c \
		src/sprite/game_sprite.c \
		src/sprite/init_sprite.c \
		src/sprite/init_sprite2.c \
		src/sprite/init_sprite3.c \
		src/utils/get_next_line.c \
		src/utils/my_putstr.c \
		src/utils/int_to_char.c \
		src/utils/my_strcmp.c \
		src/utils/utils_csfml.c \
		src/event/pnj_spawn/spawn_pnj.c	\
		src/event/pnj_spawn/spawn_pnj2.c	\
		src/event/pnj_spawn/spawn_pnj3.c	\
		src/event/pnj_spawn/spawn_pnj4.c	\
		src/event/pnj_spawn/spawn_ange.c	\
		src/event/pnj_spawn/spawn_ange2.c	\
		src/event/pnj_spawn_enemy/spawn_enemy.c	\
		src/event/pnj_spawn_enemy/spawn_enemy2.c \
		src/event/pnj_spawn_enemy/utils_spawn_enne.c	\
		src/map/nb_text.c	\
		src/map/charg.c	\
		src/fight.c	\
		src/end_fight.c	\
		src/fight2.c	\
		src/event/pnj_spawn/utils_spawn_pnj.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

LDFLAGS	=	-l csfml-graphics \
			-l csfml-audio \
			-l csfml-system \
			-l csfml-window \

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -g3

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		all