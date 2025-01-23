#include "../push_swap.h"

void  rra (stack_t **a)
{
    int size;
    stack_t *first_one;
    stack_t *before_last_one;

    size = stack_size(*a);
    first_one = *a;
    if (size >= 2)
    {
        while ((*a)->next)
        {
            if ((*a)->next->next == NULL)
                before_last_one = *a;
            *a = (*a)->next;
        }
        before_last_one->next = NULL;
        (*a)->next = first_one;
    }
}