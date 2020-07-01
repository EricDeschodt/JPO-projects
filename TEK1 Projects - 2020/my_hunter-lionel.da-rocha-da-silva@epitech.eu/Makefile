##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	my_hunter

SRC	=	src/duck.c \
		src/analyse_events.c \
		src/score.c \
		src/crosshair.c \
		src/gameover.c \
		src/menu.c \
		src/animation.c \
		src/dog.c \
		src/anims.c \
		src/bird.c \
		src/init_params.c \
		utils/my_strcmp.c \
		utils/add.c \
		utils/sub.c \
		utils/add_calc.c \
		utils/sub_calc.c \
		utils/first_neg.c \
		utils/secnd_neg.c \
		utils/infin_add.c \
		utils/get_value.c \
		utils/comp.c \
		utils/infin_sub.c \
		utils/infin_mul.c \
		utils/mult.c \
		utils/my_strcpy.c \
		utils/my_strcat.c \
		utils/my_strlen.c \
		utils/my_revstr.c \

OBJ     =	$(SRC:.c=.o)

CFLAGS  +=	-Wall -Wextra -g3

CFLAGS  +=	-I./include

CFLAGS	+=	-l csfml-graphics

CFLAGS	+=	-l csfml-window

CFLAGS	+=	-l csfml-system

CFLAGS	+=	-l csfml-audio

all     :	$(NAME)

$(NAME) :	$(OBJ)
		@gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re      :	fclean all clean

.SILENT	:	all fclean clean re

.PHONY	:	all fclean clean re
