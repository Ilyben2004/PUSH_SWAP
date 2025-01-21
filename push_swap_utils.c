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
int is_number(char *number)
{
    if (*number == 0)
        return 0;
    if (*number == '+' || *number == '-')
        number++;
    if (*number == 0)
        return (0);
    while (*number)
    {
        if (!ft_isdigit(*number))
            return (0);
        number++;
    }
    return (1);
}

int stack_size(stack_t *a)
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