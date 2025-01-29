#include "push_swap.h"

int is_sorted(stack_t *a)
{
    while(a)
    {
        if (a->next)
        {
            if (a->value > a->next)
                return (0);
        }
        a = a->next;
    }
    return (1);
}

void sort_three(stack_t **a , stack_t **b)
{
    int pos;
    int min_value;
    int i;
    stack_t * helper;

    min_value = (*a)->value;
    pos = 0;
    i = 1;
    helper = (*a)->next;
    while(helper)
    {
        if (helper->value < min_value)
        {
            min_value = helper->value;
            pos = i;
        }
        i++;
    }
    if(pos == 0)
    {
        pb(a,b);
        ra(a);
        pa(a,b);
    }
    else if (pos == 1)
    {
        ra(a);
        pb(a,b);
        if(is_sorted(a))
            pa(a,b);
        else 
        {
            ra(a);
            pa(a,b);
        }

    }
    else if (pos == 2)
    {
        rra(a);
        pa(a,b);
        if(is_sorted(a))
            pa(a,b);
        else 
        {
            ra(a);
            pa(a,b);
        }

    }
    print_stack(a);
}
