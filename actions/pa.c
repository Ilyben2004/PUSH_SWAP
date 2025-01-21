#include "../push_swap.h"

void pa(stack_t **a, stack_t **b)
{
    int size_b;
    stack_t * helper;

    size_b = stack_size(*b);

    if (size_b > 0)
    {
        helper =  (*b)->next;
        (*b)->next = *a;
        *a = *b;
        *b = helper;
    }
}