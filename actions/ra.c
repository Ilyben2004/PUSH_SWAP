#include "../push_swap.h"

void ra(stack_t ** a)

{
    int size;  
    stack_t *second_one;
    stack_t *first_one;

    size = stack_size(*a);
    if(size >= 2)
    {
        second_one = (*a)->next;
        first_one = *a;
        while((*a)->next)
            *a = (*a)->next;
        (*a)->next = first_one;
        first_one->next = NULL;
        *a = second_one;
    }
}