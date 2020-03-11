# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 16:06:47 by gmachado          #+#    #+#              #
#    Updated: 2020/03/11 11:51:32 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

HEADER = \
	-I ./Includes/rtv1.h

FRAMEWORKS = \
	-I ./Frameworks/SDL2.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_image.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_ttf.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_mixer.framework/Versions/A/Headers \
	-F ./Frameworks/

ARCHIVE = \
	-L ./Includes/libft -l ft \

SRCS = \
	./srcs/rtv1.c \
	./srcs/make_2d.c \
	./srcs/initializing.c \


OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc -c $< -o $@ -ggdb3 -O0 --std=c99 -Wall `sdl2-config --libs --cflags`

all: $(NAME)

$(NAME): $(OBJS)
	@ echo Compiling...
	@ make -C ./Includes/libft
	@ gcc -ggdb3 -O0 --std=c99 -Wall `sdl2-config --libs --cflags` -o $(NAME) $(OBJS) $(ARCHIVE) $(FRAMEWORKS) -fsanitize=address
	@ echo Finished compiling! Run with ./RTv1 {display}

clean:
	@ make -C ./Includes/libft clean
	@ rm -f $(OBJS)

fclean: clean
	@ make -C ./Includes/libft fclean
	@ rm -f $(NAME)

re: fclean all