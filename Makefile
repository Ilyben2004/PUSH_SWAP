CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
NAME = push_swap

MAIN = push_swap.c
SRC = push_swap_utils.c clean_data.c
ACTIONS = actions/sa.c actions/sb.c actions/ss.c actions/pa.c actions/pb.c actions/ra.c actions/rra.c actions/rb.c actions/rrb.c actions/rr.c

all: $(NAME)

$(NAME):  $(MAIN) $(ACTIONS) $(SRC)
	$(CC) $(MAIN)   -o $(NAME) $(LIBFT) $(SRC) $(ACTIONS)



clean:
		cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all
