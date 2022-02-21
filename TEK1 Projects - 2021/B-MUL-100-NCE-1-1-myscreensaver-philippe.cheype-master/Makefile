##
## EPITECH PROJECT, 2020
## my_screensaver
## File description:
## Makefile
##

NAME	=	my_screensaver

SRC		=	main.c							\
			src/framebuffer_create.c		\
			src/framebuffer_destroy.c		\
			src/my_put_pixel.c				\
			src/my_draw_square.c			\
			src/my_draw_circle.c			\
			src/my_rand_color.c				\
			src/clean_window.c				\
			src/screensaver_end.c			\
			src/bad_params.c				\
			src/help_menu.c					\
			src/list_menu.c					\
			src/vars_create.c				\
			src/utils_create.c				\
			src/effect_index.c				\
			src/effects/random_squares.c	\
			src/effects/random_circles.c	\
			src/effects/moving_circle.c		\
			src/effects/moving_square.c

OBJ		=	$(SRC:.c=.o)

LIBS	=	include/

CFLAGS	+=	-L./src/ -lmy -I./$(LIBS) -lcsfml-graphics -lcsfml-system

DFLAGS	+=	-W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./src/ all
			cp -f src/*.h $(LIBS)
			gcc -o $(NAME) $(SRC) $(CFLAGS) $(DFLAGS)

clean:
			rm -f $(OBJ)
			make -C ./src/ clean
			rm -f $(LIBS)*.h
			rm -f *.vgcore
			rm -f *.gcno
			rm -f *.gcda

fclean:		clean
			rm -f $(NAME)
			make -C ./src/ fclean

re:			fclean all
			make -C ./src/ re

.PHONY:		all clean fclean re
