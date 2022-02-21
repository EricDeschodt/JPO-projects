##
## EPITECH PROJECT, 2020
## my_screensaver
## File description:
## Lib Makefile
##

NAME	=	libmy.a

SRC		=	lib/my_putstr.c						\
			lib/my_strlen.c						\
			lib/my_putnbr.c						\
			lib/my_putchar.c					\
			lib/my_strcmp.c						\
			lib/my_compute_factorial_rec.c		\
			lib/my_compute_power_rec.c			\
			my_cos.c							\
			my_sin.c							\

OBJ		=	$(SRC:.c=.o)

E_OBJ	=	$(SRC:.c=.o)

.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

.PHONY:		clean
clean:
			rm -f $(OBJ)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
