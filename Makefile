CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MAIN = push_swap.c
SRC = push_swap_utils.c
ACTIONS = actions/sa.c actions/sb.c actions/ss.c actions/pa.c actions/pb.c actions/ra.c actions/rra.c actions/rb.c actions/rrb.c

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN) $(ACTIONS) $(SRC)
	$(CC) $(MAIN)   -o $(NAME) $(LIBFT) $(SRC) $(ACTIONS)

$(LIBFT):
		cd $(LIBFT_DIR) && make

clean:
		cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all
