NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC =  \
		./lib/ft_putstr_fd.c \
		./lib/ft_strlen.c \
		./src/error.c \

OBJ_M = $(SRC:.c=.o)

all: $(NAME)

$(NAME): main.o $(OBJ_M)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c includes/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
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

.PHONY: all clean fclean re