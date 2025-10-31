# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 11:39:01 by zajaddou          #+#    #+#              #
#    Updated: 2025/10/30 19:49:58 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC =  \
	./global/global.c \
	./global/ft_free.c \
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
	./parsing/config.c \
	./parsing/algo.c \
	./parsing/files.c \
	./parsing/static.c \
	./parsing/parse.c \
	./parsing/map.c \
	./bonus/animation.c \
	./bonus/minimap.c \
	./bonus/mouse.c \
	./raycasting/window_init.c\
	./raycasting/raycasting_part.c\
	./raycasting/render_background.c\
	./raycasting/render_walls.c\
	./raycasting/mouvment_key.c\
	
	

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