##
## EPITECH PROJECT, 2021
## myDefender (Workspace)
## File description:
## Makefile
##

NAME	=	my_defender

CC		=	@gcc

RM		=	@rm -f

CP		=	@cp -f

HEADERS	=	$(wildcard src/includes/*.h)

SRC		=	$(wildcard src/*.c)						\
													\
			$(wildcard src/misc/*.c)				\
			$(wildcard src/misc/screen/*.c)			\
			$(wildcard src/misc/create/*.c)			\
			$(wildcard src/misc/destroy/*.c)		\
													\
			$(wildcard src/menu/*.c)				\
													\
			$(wildcard src/settings/*.c)			\
			$(wildcard src/settings/init/*.c)		\
			$(wildcard src/settings/buttons/*.c)	\
													\
			$(wildcard src/high_score/*.c)			\
													\
			$(wildcard src/exit/*.c)				\
													\
			$(wildcard src/game/*.c)				\
			$(wildcard src/game/init/*.c)			\
			$(wildcard src/game/add/*.c)			\
			$(wildcard src/game/check/*.c)			\
			$(wildcard src/game/bullets/*.c)			\
			$(wildcard src/game/update/*.c)			\
													\
			$(wildcard src/pause_menu/*.c)			\

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./src/includes/ -L./lib/ -lmy

LFLAGS	+=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

DFLAGS	+=	-O3 -W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C ./lib/
			$(CP) $(HEADERS) includes/
			$(CC) -o $(NAME) $(SRC) $(DFLAGS) $(CFLAGS) $(LFLAGS)

clean:
			$(RM) $(OBJ)
			make clean -C ./lib/
			$(RM) $(wildcard includes/*.h)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./lib/

re:			fclean all
			make re -C ./lib/

.PHONY:		all clean fclean re
