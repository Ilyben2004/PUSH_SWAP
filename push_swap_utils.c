#include "push_swap.h"

int * bubble_sort(int * tab, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
    return (tab);
}


int included_in_tab(int value, int * tab, int start , int end)
{
    while (start <= end)
    {
        if(tab[start] == value)
            return (1);
        start++;
    }
    return (0);
}
int check_values_in_tab(stack_t *a, int * tab, int start , int end)
{
    int i;

    i = 0;
    while (a)
    {
            if (included_in_tab(a->value , tab , start , end))
                return (i);
            a = a->next;
            i++;
    }
    return (-1);

}


int included_in_stack (int value, stack_t *a)
{
    while (a)
    {
        if (a->value == value)
            return (1);
        a = a->next;
    }
    return (0);
}

int abs(int a)
{
    if (a >= 0)
        return (a);
    return(-a);
}
