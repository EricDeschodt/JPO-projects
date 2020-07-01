##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## makefile
##

NAME	=	my_runner

SRCS	=	main.c \
		my_atoi.c \
		my_revstr.c \
		my_put_nbr.c \
		text_init.c \
		top_score.c \
		menu_event.c \
		menu_display.c \
		menu_display2.c \
		menu_display3.c \
		auto_play2.c \
		auto_play.c \
		load_file_in_mem.c \
		list_mobs.c \
		list_mobs2.c \
		hit_box5.c \
		hit_box4.c \
		hit_box3.c \
		hit_box2.c \
		hit_box1.c \
		my_list_utils6.c \
		my_list_utils5.c \
		my_list_utils4.c \
		my_list_utils3.c \
		my_list_utils2.c \
		my_list_utils1.c \
		michael_anim3.c \
		zombies_anim.c \
		my_strlen.c \
		destroy.c \
		michael_anim2.c \
		manual.c \
		sprite_texture_init.c \
		init_regroup.c \
		background_init.c \
		draw_sprite.c \
		my_putstr.c \
		my_putchar.c \
		event.c \
		parallax.c \
		pos_init.c \
		clock.c \
		rect_init.c \
		int_init.c \
		sound_init.c \
		michael_anim.c \

OBJS	=	$(SRCS:.c=.o)

FFLAGS =	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

CFLAGS =	-Wall -Werror -Wextra -g3 -O2

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		gcc -o $(NAME) $(OBJS) $(FFLAGS) $(CFLAGS)

clean:
		rm $(OBJS)

fclean:
		rm $(NAME)
		rm $(OBJS)

re: fclean all
