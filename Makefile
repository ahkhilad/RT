# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 14:38:16 by ahkhilad          #+#    #+#              #
#    Updated: 2020/06/18 02:55:31 by ahkhilad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

LFT = libft/libft.a

LINALG = linearlib/linear_alg.a

SRCS = ./srcs/main.c ./srcs/parser.c ./srcs/launch.c ./srcs/primitives.c \
		./srcs/objects.c ./srcs/parse_objects.c ./srcs/parse_utils.c \
		./srcs/utils.c ./srcs/lights.c ./srcs/camera.c ./srcs/parse_camera.c

INC = rtv1.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -lXext -lX11 -lm -lbsd

EXEC = gcc $(CFLAGS) #$(MLXFLAGS) #-lmlx -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(OBJ): $(SRCS)
	@echo "\033[2;33m"
	gcc -c $(SRCS)
	mv *.o ./srcs/
	@echo "\033[0m"

$(LFT):
	@echo "\033[2;33m"
	make -C libft
	@echo "\033[0m"

$(LINALG):
	@echo "\033[2;33m"
	make -C linearlib
	@echo "\033[0m"

$(NAME): $(OBJ) $(LFT) $(LINALG)
	@echo "\033[2;33m"
	$(EXEC) $^ -o $@ $(MLXFLAGS)
	@echo "\033[0m"
	@echo "\033[32;3mAll Set !\n\033[0m"

clean:
	@echo "\033[2;31m"
	make -C libft clean
	make -C linearlib clean
	rm -rf $(OBJ)
	@echo "\033[0m"
	@echo "\033[4;31mObject Files Deleted\033[0m"

fclean: clean
	@echo "\033[2;31m"
	make -C libft fclean
	make -C linearlib fclean
	rm -rf $(NAME)
	@echo "\033[0m"
	@echo "\033[4;31mBinary File Deleted\n\033[0m"

re: fclean all
