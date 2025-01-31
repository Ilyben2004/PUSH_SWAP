CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
NAME = push_swap

MAIN = push_swap.c
SRCS = push_swap_utils.c clean_data.c sort_three.c ft_split.c libft.c actions/sa.c actions/sb.c actions/ss.c actions/pa.c actions/pb.c actions/ra.c actions/rra.c actions/rb.c actions/rrb.c actions/rr.c

BSRCS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):  $(MAIN) $(BSRCS)
	$(CC) $(MAIN)   -o $(NAME) $(BSRCS)



clean:
		rm -rf $(BSRCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

