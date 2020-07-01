##
## EPITECH PROJECT, 2019
## myhunter
## File description:
## makefile
##

NAME	=	my_hunter

SRCS	=	main.c \
		my_atoi.c \
		move_rect2.c \
		top_score.c \
		main_init.c \
		if_ducks_overlap.c \
		dog_reset.c \
		my_putchar.c \
		manual.c \
		my_revstr.c \
		my_put_nbr.c \
		my_putstr.c \
		my_strlen.c \
		main2.c \
		event2.c \
		dog_1duck.c \
		dog_animation_round.c \
		dog_2duck.c \
		sprite_texture_init3.c \
		dog_laugh.c \
		move_rect.c \
		sprite_texture_init.c \
		rect_init.c \
		init_regroup.c \
		pos_init.c \
		event.c \
		int_init.c \
		main_if.c \
		if_choice.c \
		if_choice2.c \
		draw_sprite.c \
		dog_animation.c \
		sound_init.c \
		destroy.c \
		duck_animation.c \
		clock.c \
		if_choice_rev.c \
		if_choice_bot.c \
		if_choice_rev2.c \
		if_choice_bot2.c \
		duck_animation2.c \
		duck_animation3.c \
		sprite_texture_init2.c \
		if_dead.c \
		if_dead2.c \

OBJS	=	$(SRCS:.c=.o)

FFLAGS =	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

CFLAGS =	-Wall -Werror -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		gcc -o $(NAME) $(OBJS) $(FFLAGS) $(CFLAGS)

clean:
		rm $(OBJS)

fclean:
		rm $(NAME)
		rm $(OBJS)

re: fclean all
