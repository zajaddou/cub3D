
NAME    = cub3D
NAME_B  = cub3D_bonus
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
MLX     = -lmlx -framework OpenGL -framework AppKit

MND_P   = ./MND
BNS_P   = ./BNS

SRC = $(MND_P)/main.c \
      $(MND_P)/global/global.c \
      $(MND_P)/global/ft_free.c \
      $(MND_P)/lib/ft_atoi.c \
      $(MND_P)/lib/ft_isdigit.c \
      $(MND_P)/lib/ft_buffer.c \
      $(MND_P)/lib/ft_search.c \
      $(MND_P)/lib/ft_strjoin.c \
      $(MND_P)/lib/ft_split.c \
      $(MND_P)/lib/ft_strchr.c \
      $(MND_P)/lib/ft_strncpy.c \
      $(MND_P)/lib/ft_strdup.c \
      $(MND_P)/lib/ft_simple.c \
      $(MND_P)/lib/ft_strlen.c \
      $(MND_P)/lib/get_next_line.c \
      $(MND_P)/parsing/config.c \
      $(MND_P)/parsing/config_.c \
      $(MND_P)/parsing/algo.c \
      $(MND_P)/parsing/read.c \
      $(MND_P)/parsing/static.c \
      $(MND_P)/parsing/parse.c \
      $(MND_P)/parsing/map.c \
      $(MND_P)/parsing/format.c \
      $(MND_P)/parsing/textures.c \
      $(MND_P)/parsing/is.c \
      $(MND_P)/raycasting/window_init.c \
      $(MND_P)/raycasting/raycasting_part.c \
      $(MND_P)/raycasting/render_background.c \
      $(MND_P)/raycasting/mouvment_key.c \
      $(MND_P)/raycasting/cast_hor_ver.c \
      $(MND_P)/raycasting/textures.c

OBJ_M = $(SRC:.c=.o)

SRC_BNS = $(BNS_P)/main.c \
          $(BNS_P)/global/global.c \
          $(BNS_P)/global/ft_free.c \
          $(BNS_P)/lib/ft_atoi.c \
          $(BNS_P)/lib/ft_isdigit.c \
          $(BNS_P)/lib/ft_buffer.c \
          $(BNS_P)/lib/ft_search.c \
          $(BNS_P)/lib/ft_strjoin.c \
          $(BNS_P)/lib/ft_split.c \
          $(BNS_P)/lib/ft_strchr.c \
          $(BNS_P)/lib/ft_strncpy.c \
          $(BNS_P)/lib/ft_strdup.c \
          $(BNS_P)/lib/ft_simple.c \
          $(BNS_P)/lib/ft_strlen.c \
          $(BNS_P)/lib/ft_itoa.c \
          $(BNS_P)/lib/ft_strlcpy.c \
          $(BNS_P)/lib/get_next_line.c \
          $(BNS_P)/parsing/config.c \
          $(BNS_P)/parsing/config_.c \
          $(BNS_P)/parsing/algo.c \
          $(BNS_P)/parsing/read.c \
          $(BNS_P)/parsing/static.c \
          $(BNS_P)/parsing/parse.c \
          $(BNS_P)/parsing/map.c \
          $(BNS_P)/parsing/format.c \
          $(BNS_P)/parsing/textures.c \
          $(BNS_P)/parsing/is.c \
          $(BNS_P)/raycasting/window_init.c \
          $(BNS_P)/raycasting/raycasting_part.c \
          $(BNS_P)/raycasting/render_background.c \
          $(BNS_P)/raycasting/mouvment_key.c \
          $(BNS_P)/raycasting/cast_hor_ver.c \
          $(BNS_P)/raycasting/textures.c \
          $(BNS_P)/bonus/animation.c \
          $(BNS_P)/bonus/minimap.c \
          $(BNS_P)/bonus/mouse.c \
          $(BNS_P)/bonus/doors.c

OBJ_B = $(SRC_BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) -o $@ $(MLX)
	@echo "✅ Mandatory cub3D built"

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $@ $(MLX)
	@echo "✨ Bonus cub3D built"

$(MND_P)/%.o: $(MND_P)/%.c $(MND_P)/includes/cub3d.h $(MND_P)/includes/env.h $(MND_P)/includes/structs.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BNS_P)/%.o: $(BNS_P)/%.c $(BNS_P)/includes/cub3d.h $(BNS_P)/includes/env.h $(BNS_P)/includes/structs.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_M)
	@rm -f $(OBJ_B)
	@echo "🧹 Objects removed"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)

re: fclean all
	@echo "🔄 Rebuilt everything"

.PHONY: all clean fclean re bonus
