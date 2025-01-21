#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct stack_s {
    int value;             
    struct stack_s *next;   
} stack_t;


#endif