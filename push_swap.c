#include "push_swap.h"

static void print_stack(stack_t * a)
{
    while (a)
    {
        printf("%d\n",a->value);
        a = a->next;
    }

}
static int check_args(char **argv)
{
    int i;
    int j;
    
    i = 1;
    while (argv[i])
    {
        j = -1;
        if(argv[i][0] == 0)
            {
                printf("you entred a empty number");
                return 0;
            }
        while (argv[i][++j])
        {
            if (!ft_isdigit(argv[i][j]))
                return(printf("please enter just numbers"),0);
        }
        i++;
        
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
static int stack_size(stack_t *a)
{
    int i;
    
    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return (i);

}
static int *   create_sorted_array (stack_t *a)
{
    int size;
    int *sorted_array;
    int i;
    int j;

    i = 0;
    size = stack_size(a);
    sorted_array = malloc(size * sizeof(int));
    while (i < size)
    {
        sorted_array[i] = a->value;
        a = a->value;
        i++;
    }
    i = 0;
    while (i < size)
    {
        if(sorted_array[i] > size)
        {
            
        }
    }

    
}
int main(int argc, char ** argv )
{
    stack_t *a;
   // stack_t b;
    if (argc <= 1 || !check_args(argv))
        return (0);
    if (!create_stack_a(&a,argv))
        return 0;
    print_stack(a);
    create_sorted_array(*a);



}

