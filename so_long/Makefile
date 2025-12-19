NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       get_map.c \
       all_validation.c \
       additional_functions.c \
       init_mlx.c \
       game_hooks.c \
       free_functions.c \
       print_error.c

GNL = get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

MLX_DIR = minilibx-linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
