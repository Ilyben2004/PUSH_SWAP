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
//*********** actions ****************//
void sa(stack_t **a);
void sb(stack_t **b);
void pa(stack_t **a, stack_t **b);
void pb(stack_t **a, stack_t **b);
void ss(stack_t **a, stack_t **b);
void ra(stack_t ** a);
void  rra (stack_t **a);
void rb(stack_t ** b);
void ra(stack_t ** a);
void  rrb (stack_t **b);
void rr(stack_t **a, stack_t **b);

// **********************************//
void sort_stack(stack_t *a , stack_t *b, int * sorted_array);
int check_values_in_tab(stack_t *a, int * tab, int start , int end);
int included_in_tab(int value, int * tab, int start , int end);
void print_stack(stack_t * a);
void turn_it_back_to_a(stack_t *a , stack_t *b ,int * tab, int size);
int max_less_than(int max, int * tab , int size);
int max_in_tab(int * tab , int size);
void free_stacks_tab(stack_t * a, int * tab);
#endif