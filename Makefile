# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 11:39:01 by zajaddou          #+#    #+#              #
#    Updated: 2025/09/10 14:08:07 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror 

SRC =  \
		./global/global.c \
		./global/more.c \
		./lib/ft_putstr_fd.c \
		./lib/buffer.c \
		./lib/ft_strjoin.c \
		./lib/ft_strchr.c \
		./lib/ft_strncpy.c \
		./lib/ft_strdup.c \
		./lib/ft_simple.c \
		./lib/ft_strlen.c \
		./lib/get_next_line.c \
		./src/parsing/files.c \
		./src/parsing/static.c \
		./src/parsing/parse.c \



OBJ_M = $(SRC:.c=.o)

all: $(NAME)

$(NAME): main.o $(OBJ_M)
	@$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit

%.o: %.c includes/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf .vscode
	@rm -f $(OBJ_M) main.o
	@clear

fclean: clean
	@rm -f $(NAME)
	@clear

re: fclean all
	@clear

push: fclean
	@git add .
	@git commit -m "update"
	@git push
	@clear

run: all clean

.PHONY: all clean fclean re