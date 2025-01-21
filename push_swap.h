#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct stack_s {
    int value;             
    struct stack_s *next;   
} stack_t;

int * bubble_sort(int * tab, int size);
int is_number(char *number);
int stack_size(stack_t *a);
void sa(stack_t **a);
void sb(stack_t **b);
void pa(stack_t **a, stack_t **b);

#endif