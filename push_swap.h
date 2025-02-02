#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct stack_s {
    int value;             
    struct stack_s *next;   
} stack_t;


typedef struct cords_s
{
    int div;
    int size;
    int mid;
    int offset;
    int start;
    int end;
} cords_t;

typedef struct  max_s
{
    int max;
    int less_than_max;
    int less_than_max_pushed;
} max_t;

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
void  rrr (stack_t **a,stack_t **b);

// **********************************//
void sort_stack(stack_t **a , stack_t **b, int * sorted_array);
int check_values_in_tab(stack_t *a, int * tab, int start , int end);
int included_in_tab(int value, int * tab, int start , int end);
void turn_it_back_to_a(stack_t **a , stack_t **b ,int * tab, int size);
int max_less_than(int max, int * tab , int size);
int max_in_tab(int * tab , int size);
void free_stacks_tab(stack_t * a, int * tab);
int     ft_isdigit(int c);
int is_number(char *number);
int check_args(char **argv);
int check_duplicate(int * sorted_array , int size);
void sort_three(stack_t **a);
char    **ft_split(char const *s, char c);
long     ft_atoi(const char *str);
void free_splited(char ** splited);
void sort_five(stack_t **a , stack_t **b);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
int is_sorted(stack_t *a);
int get_operation(stack_t *b ,int value);

#endif