NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iminilibx-linux

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

MLX_DIR  = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(MLX_LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
