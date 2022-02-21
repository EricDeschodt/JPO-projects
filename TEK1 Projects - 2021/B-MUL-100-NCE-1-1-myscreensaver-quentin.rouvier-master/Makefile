##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## screensavers
##


NAME	=   my_screensaver

SRC	=   src/screensever.c	    \
	    src/draw.c		    \
	    src/framebuffer.c	    \
	    src/first_screen.c	    \
	    src/circle.c	    \
	    src/square.c	    \
	    src/second_screen.c	    \
	    src/third_screen.c	    \
	    src/fourth_screen.c	    \
	    src/fifth_screen.c	    \
	    src/main.c		    \
	    src/colors.c	    \
	    src/position.c

OBJ	=   $(SRC:.c=.o)

FFLAGS	=   -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

CFLAGS	=   -Wall -Wextra -g3

all:	$(NAME)

$(NAME):    $(OBJ) $(SRC)
	    gcc -o $(NAME) $(OBJ) $(FFLAGS)

clean:
	    rm -rf $(OBJ)

fclean:	    clean
	    rm -rf $(NAME)

re: fclean all
