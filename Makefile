
NAME = fractol

SRC = src/main.c src/aux/mlx.c src/aux/coords.c src/sets/mandelbrot.c src/aux/color.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs $(NAME)

REMOVE = rm -f

MLX_LIB_DIR = mlx_linux/

MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_LIB_DIR) > /dev/null 2>&1
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c
	@$(CC) $(CFLAGS) $(MLX_INCLUDE) -O3 -c $(^) -o $(@)

bonus: all

clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
