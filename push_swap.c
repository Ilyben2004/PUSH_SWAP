#include "push_swap.h"




static stack_t * create_stack_a( stack_t **a, char **argv)
{
    stack_t *stack_a;
    int i;
    char **splited;
    int j;


    i = 1;
    stack_a = malloc(sizeof(stack_t));
    *a = stack_a;
    while (argv[i])
    {
        splited = ft_split(argv[i],' ');
        j = 0;
        while (splited[j])
        {
            stack_a->value = ft_atoi(splited[j]);
            if (splited[j + 1] != NULL || argv[i + 1] != NULL)
            {
                stack_a->next = malloc(sizeof(stack_t));
                stack_a = stack_a->next; 
            }
            else
                stack_a->next = NULL;
            j++;
        }
        free_splited(splited);
        i++;
    }
    return(*a);
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
int main(int argc, char ** argv)
{
    stack_t *a;
    stack_t *b;
    int size ;
    int *sorted_array;

    b = NULL;
    if (argc <= 1 || !check_args(argv))
        return (0);
    if (!create_stack_a(&a,argv))
        return 0;
    size = stack_size(a);
    sorted_array = create_sorted_array(a,size);
    // if(check_duplicate(sorted_array, size))
    //     return(free_stacks_tab(a,sorted_array),0);
    sort_stack(&a,&b,sorted_array);
    free_stacks_tab(a,sorted_array);
}

