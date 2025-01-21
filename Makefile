CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MAIN = push_swap.c

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN)
	$(CC) $(MAIN) $(CFLAGS)  -o $(NAME) $(LIBFT)

$(LIBFT):
		cd $(LIBFT_DIR) && make

clean:
		cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all
