# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 14:38:16 by ahkhilad          #+#    #+#              #
#    Updated: 2019/10/24 19:21:59 by ahkhilad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

LFT = libft/libft.a

LINALG = linearlib/linear_alg.a

SRCS = ./srcs/main.c ./srcs/parser.c ./srcs/launch.c ./srcs/primitives.c \
		./srcs/objects.c ./srcs/parse_objects.c ./srcs/parse_utils.c \
		./srcs/utils.c srcs/lights.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

EXEC = gcc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(OBJ): $(SRCS)
	@echo "\033[2;33m"
	gcc -g -c $(SRCS) -I rtv1.h
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
	$(EXEC) $^ -o $@
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
