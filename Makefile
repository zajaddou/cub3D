# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 11:39:01 by zajaddou          #+#    #+#              #
#    Updated: 2025/09/11 12:17:11 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC =  \
	./global/global.c \
	./global/more.c \
	./lib/ft_atoi.c \
	./lib/ft_putstr_fd.c \
	./lib/ft_isdigit.c \
	./lib/ft_buffer.c \
	./lib/ft_search.c \
	./lib/ft_strjoin.c \
	./lib/ft_split.c \
	./lib/ft_strchr.c \
	./lib/ft_strncpy.c \
	./lib/ft_strdup.c \
	./lib/ft_simple.c \
	./lib/ft_strlen.c \
	./lib/get_next_line.c \
	./src/parsing/config.c \
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
	@./cub3D maps/map.cub


.PHONY: all clean fclean re