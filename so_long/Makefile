NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC         = \
              main.c \
			  get_map.c \
			  input_validation.c \
			  map_validation.c \
			  free_functions.c \
			  print_error.c \
              ./get_next_line/get_next_line.c \
              ./get_next_line/get_next_line_utils.c

OBJ         = $(SRC:.c=.o)

INCLUDES    = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	
