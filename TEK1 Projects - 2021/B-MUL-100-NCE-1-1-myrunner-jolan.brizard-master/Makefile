##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compiles the code
##

SRC	=	lib/my/my_putchar.c		\
		lib/my/my_strcmp.c		\
		lib/my/my_strncat.c		\
		lib/my/my_strcpy.c		\
		lib/my/my_strncmp.c		\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_putstr.c		\
		lib/my/my_str_isalpha.c		\
		lib/my/my_strncpy.c		\
		lib/my/my_compute_square_root.c	\
		lib/my/my_revstr.c		\
		lib/my/my_str_islower.c		\
		lib/my/my_strstr.c		\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_showmem.c		\
		lib/my/my_str_isnum.c		\
		lib/my/my_strupcase.c		\
		lib/my/my_getnbr.c		\
		lib/my/my_showstr.c		\
		lib/my/my_str_isprintable.c	\
		lib/my/my_swap.c		\
		lib/my/my_sort_int_array.c	\
		lib/my/my_str_isupper.c		\
		lib/my/my_isneg.c		\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strlen.c		\
		lib/my/my_is_prime.c		\
		lib/my/my_strcat.c		\
		lib/my/my_put_nbr.c		\
		lib/my/my_strlowcase.c		\
		lib/my/my_strdup.c		\
		lib/my/hex_base.c		\
		lib/my/octal_base.c		\
		lib/my/my_printf.c      \
		lib/my/binary_base.c    \
		src/window.c			\
		src/draw.c				\
		src/sprite.c			\
		src/sprite_animation.c	\
		src/events.c			\
		src/error_handling.c	\
		src/parallax.c			\
		src/px_animation.c		\
		src/destroy.c			\
		src/score.c				\
		src/text.c				\
		src/map.c				\
		src/map_animation.c		\
		src/audio.c				\
		src/main.c

NAME	=	my_runner

OBJ	    =	$(SRC:.c=.o)

FFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

all:    $(NAME)
	rm -rf $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FFLAGS) -g3

clean:
	rm -rf $(OBJ)
	find -name "*~" -type f -delete -o -name "#*" -type f -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

cc:	all clean
