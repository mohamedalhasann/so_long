NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       get_map.c \
       all_validation.c \
	   additional_functions.c \
       init_mlx.c \
       free_functions.c \
       print_error.c

GNL = get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

MLX_FLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
