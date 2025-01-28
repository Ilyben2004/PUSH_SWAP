#include "push_swap.h"


static int check_args(char **argv)
{
    int i;

    
    i = 0;
    while (argv[++i])
    {
        if (!is_number(argv[i]))
        {
            printf("enter valid args :) \n");
            return (0);
        }
    }
    return 1;
}

stack_t * create_stack_a( stack_t **a, char **argv)
{
    stack_t *stack_a;
 
    int i;

    i = 1;
    stack_a = malloc(sizeof(stack_t));
    *a = stack_a;
    while (argv[i])
    {
        stack_a->value = ft_atoi(argv[i]);
        if (argv[i + 1] != NULL)
        {
            stack_a->next = malloc(sizeof(stack_t));
            stack_a = stack_a->next;
          
        }
        else
            stack_a->next = NULL;
          i++;
    }
    return(*a);
}

stack_t * create_stack_b( stack_t **b)
{

    *b = malloc(sizeof(stack_t));
    (*b)->next = NULL;
    return (*b);
}

static int *   create_sorted_array (stack_t *a, int size)
{
    int *sorted_array;
    int i;

    i = 0;
    sorted_array = malloc(size * sizeof(int));
    while (i < size)
    {
        sorted_array[i] = a->value;
        a = a->next;
        i++;
    }
    i = 0;
    return bubble_sort(sorted_array,size);
}
int main(int argc, char ** argv )
{
    stack_t *a;
    stack_t *b;
   // stack_t b;
    int size ;
    int *sorted_array;

    // a->next = NULL;
    b = NULL;
    if (argc <= 1 || !check_args(argv))
        return (0);
    if (!create_stack_a(&a,argv) && create_stack_b(&b))
        return 0;
    size = stack_size(a);
    sorted_array = create_sorted_array(a,size);
    sort_stack(a,b,sorted_array);
    free_stacks_tab(a,sorted_array);
}

