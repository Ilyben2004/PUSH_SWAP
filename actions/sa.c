#include "../push_swap.h"

void sa(stack_t **a)
{
    int size;
    stack_t * helper;
    stack_t * helper2;;


    size = stack_size(*a);
    if (size >= 2)
    {
        if (size == 2)
        {
            (*a)->next->next = *a;
            helper = (*a)->next;
            (*a)->next = NULL;
            *a = helper;
                
        }
        else
        {
            helper = (*a)->next->next;
            helper2 = (*a)->next;
            (*a)->next->next = *a;
            (*a)->next = helper;
            *a = helper2;
        }
    }
}