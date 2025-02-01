CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
NAME = push_swap
CHECKER = checker

MAIN = push_swap.c
SRCS = push_swap_utils.c push_swap_utils2.c push_to_a.c push_to_b.c clean_data.c sort_three.c ft_split.c libft.c \
       actions/sa.c actions/sb.c actions/ss.c actions/pa.c actions/pb.c actions/ra.c actions/rra.c actions/rb.c actions/rrb.c actions/rr.c
OSRCS = $(SRCS:.c=.o)

BSRCS = actions/sa.c actions/sb.c actions/ss.c actions/pa.c actions/pb.c actions/ra.c actions/rra.c actions/rb.c actions/rrb.c actions/rr.c \
        checker/get_next_line/get_next_line.c checker/get_next_line/get_next_line_utils.c push_swap_utils.c push_swap_utils2.c clean_data.c libft.c
BOSRCS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OSRCS) $(MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(OSRCS) $(MAIN)

bonus: $(CHECKER)

$(CHECKER): $(BOSRCS)
	cd checker
	$(CC) $(CFLAGS) -o checker $(BOSRCS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OSRCS) $(BOSRCS)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

re: fclean all
