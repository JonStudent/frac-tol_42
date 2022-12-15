
NAME = fractol

SRC = src/main.c src/win/mlx.c src/display/coords.c src/win/settings.c \
	  src/aux/numbers.c src/display/color.c src/win/hooked.c src/sets/mandelbrot.c \
	  src/sets/julia.c src/sets/burning_ship.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs $(NAME)

REMOVE = rm -f

LIBFT_DIR = libft

MLX_LIB_DIR = mlx_linux

INCLUDE = -I$(MLX_LIB_DIR) -I$(LIBFT_DIR)

LIBFT_FLGS = -L$(LIBFT_DIR) -lft

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux

FLAGS = $(LIBFT_FLGS) $(MLX_FLAGS) -L/usr/lib -lXext -lX11 -lm -lz

GRN = \e[1;32m

RST = \e[m

all: $(NAME)

$(NAME): $(OBJ)
	@printf '%s$(GRN)' "Config Mlx_Lib... "
	@make -s -C $(MLX_LIB_DIR) > /dev/null 2>&1
	@printf '%s\n$(RST)%s$(GRN)' "Done" "Compiling Libft... "
	@make -s -C $(LIBFT_DIR)
	@printf '%s\n$(RST)%s$(GRN)%s$(RST)\n' "Done" "Compiling Frac-tol... " "All Done"
	@$(CC) $(^) $(FLAGS) -o $(@)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -O3 -c $(^) -o $(@)

bonus: all

clean:
	@make clean -s -C libft
	@$(REMOVE) $(OBJ) libft/libft.a

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
