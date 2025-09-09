# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 11:39:01 by zajaddou          #+#    #+#              #
#    Updated: 2025/09/09 16:20:54 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC =  \
		./lib/ft_putstr_fd.c \
		./lib/ft_strlen.c \
		./src/parsing/files.c \
		./src/global.c \
		./src/more.c \
		./src/parsing/static.c \

OBJ_M = $(SRC:.c=.o)

all: $(NAME)

$(NAME): main.o $(OBJ_M)
	$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit

%.o: %.c includes/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf .vscode
	rm -f $(OBJ_M) main.o
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all
	clear

push: fclean
	@git add .
	@git commit -m "update"
	@git push
	@clear

run: all clean

.PHONY: all clean fclean re