NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       get_map.c \
       all_validation.c \
       additional_functions.c \
       mlx_setup.c \
       game_hooks.c \
       free_functions.c \
       print_error.c

GNL = get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

# -------- ft_printf --------
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# -------- MiniLibX (Linux) --------
MLX_DIR = minilibx-linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# -------- Rules --------
all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(MLX_DIR)/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

