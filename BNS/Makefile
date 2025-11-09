# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 11:39:01 by zajaddou          #+#    #+#              #
#    Updated: 2025/11/08 19:45:04 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address

SRC = ./main.c\
	./global/global.c \
	./global/ft_free.c \
	./lib/ft_atoi.c \
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
	./lib/ft_itoa.c \
	./lib/ft_strlcpy.c \
	./lib/get_next_line.c \
	./parsing/config.c \
	./parsing/config_.c \
	./parsing/algo.c \
	./parsing/read.c \
	./parsing/static.c \
	./parsing/parse.c \
	./parsing/map.c \
	./parsing/format.c \
	./parsing/textures.c \
	./parsing/is.c \
	./raycasting/window_init.c \
	./raycasting/raycasting_part.c\
	./raycasting/render_background.c\
	./raycasting/mouvment_key.c\
	./raycasting/cast_hor_ver.c\
	./raycasting/textures.c\
	./bonus/animation.c \
	./bonus/minimap.c \
	./bonus/mouse.c \
	./bonus/doors.c \

OBJ_M = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M)
	@$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit

%.o: %.c includes/cub3d.h includes/env.h includes/structs.h
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

test: clean
	@clear
	@./cub3D maps/map.cub

.PHONY: all clean fclean re