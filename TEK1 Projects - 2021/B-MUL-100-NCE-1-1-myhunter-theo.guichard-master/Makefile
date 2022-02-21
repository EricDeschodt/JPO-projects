##
## EPITECH PROJECT, 2020
## my_hunter
## File description:
## Makefile
##

NAME	=	my_hunter

SRC		=	src/main.c					\
			src/framebuffer.c			\
			src/destroyer.c				\
			src/game_loop.c				\
			src/struct_init.c		    \
			src/analyse_events.c		\
			src/animation_tools.c       \
			src/anim_dog_duck.c			\
			src/random_nbr.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

all:		$(NAME) clean

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all