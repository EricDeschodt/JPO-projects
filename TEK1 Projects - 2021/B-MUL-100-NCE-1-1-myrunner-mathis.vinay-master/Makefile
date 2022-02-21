##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compiles the code
##

SRC	=	lib/my/my_putchar.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_strncat.c			\
		lib/my/my_strcpy.c			\
		lib/my/my_strncmp.c			\
		lib/my/my_compute_power_rec.c		\
		lib/my/my_putstr.c			\
		lib/my/my_str_isalpha.c			\
		lib/my/my_strncpy.c			\
		lib/my/my_compute_square_root.c		\
		lib/my/my_revstr.c			\
		lib/my/my_str_islower.c			\
		lib/my/my_strstr.c			\
		lib/my/my_find_prime_sup.c		\
		lib/my/my_showmem.c			\
		lib/my/my_str_isnum.c			\
		lib/my/my_strupcase.c			\
		lib/my/my_getnbr.c			\
		lib/my/my_showstr.c			\
		lib/my/my_str_isprintable.c		\
		lib/my/my_swap.c			\
		lib/my/my_sort_int_array.c		\
		lib/my/my_str_isupper.c			\
		lib/my/my_isneg.c			\
		lib/my/my_strcapitalize.c		\
		lib/my/my_strlen.c			\
		lib/my/my_is_prime.c			\
		lib/my/my_strcat.c			\
		lib/my/my_put_nbr.c			\
		lib/my/my_strlowcase.c			\
		lib/my/my_str_isint.c			\
		lib/my/my_strdup.c			\
		lib/my/my_is_char_in_str.c		\
		lib/my/my_get_nb_char_in_str.c		\
		lib/my/my_put_bool.c			\
		lib/my/my_put_nstrm.c	\
		lib/my/my_is_file_valid.c	\
		lib/my/my_get_file_ctn.c	\
		lib/my/my_index.c	\
		lib/my/my_printf/sources/printf_functions/printf_functions_core.c	\
		lib/my/my_printf/sources/printf_functions/char.c	\
		lib/my/my_printf/sources/printf_functions/nbr.c	\
		lib/my/my_printf/sources/printf_functions/long.c	\
		lib/my/my_printf/sources/printf_functions/pointer_adress.c	\
		lib/my/my_printf/sources/printf_functions/simple_str.c	\
		lib/my/my_printf/sources/printf_functions/str_w_oct.c	\
		lib/my/my_printf/sources/printf_functions/unsigned_bin.c	\
		lib/my/my_printf/sources/printf_functions/unsigned_hexadecimal.c	\
		lib/my/my_printf/sources/printf_functions/unsigned_int.c	\
		lib/my/my_printf/sources/printf_functions/unsigned_maj_hexadecimal.c \
		lib/my/my_printf/sources/printf_functions/unsigned_octal.c	\
		lib/my/my_printf/sources/printf_core.c		\
		lib/my/my_printf/sources/main.c		\
		source/graphical_funcs.c			\
		source/menus.c	\
		source/interface.c	\
		source/map.c	\
		source/audio.c	\
		source/character.c					\
		source/character_interactions.c	\
		source/time.c				\
		source/backgrounds.c	\
		source/score.c	\
		source/elements.c	\
		source/main.c					\

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)
		rm -rf $(OBJ)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l \
		csfml-system -l csfml-audio

clean:
	rm -rf $(OBJ)
	find -name "*~" -type f -delete -o -name "#*" -type f -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

cc:	all clean
