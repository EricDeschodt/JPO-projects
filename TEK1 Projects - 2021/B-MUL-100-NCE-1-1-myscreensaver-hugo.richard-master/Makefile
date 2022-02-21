##
## EPITECH PROJECT, 2020
## MakeFile
## File description:
## Makefile
##

SRC	=	main.c				\
		lib/my_getnbr.c 	\
		lib/my_putchar.c	\
		lib/my_putstr.c 	\
		sc_function.c		\
		csfml_function.c 	\
		random.c 			\
		anim_1.c 			\
		anim_2.c 			\
		anim_3.c 			\
		anim_4.c 			\
		anim_5.c 			\

NAME	=	my_screensaver

FFLAGS = -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

all:	$(NAME)

$(NAME):
	@gcc $(SRC) -o $(NAME) $(FFLAGS)
	@rm -f *~
	@rm -f #*#

clean :
	@rm -f *~
	@rm -f #*#

fclean: clean
	@rm -f $(NAME)

re:	fclean all
