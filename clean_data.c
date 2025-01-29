#include "push_swap.h"

int check_args(char **argv)
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

int     ft_isdigit(int c)
{
        return ((c >= '0' && c <= '9'));
}

int check_duplicate(int * sorted_array , int size)
{
    int i;
    int j;

    i = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (sorted_array[i] == sorted_array[j])
            {
                write(1,"please enter numbers without duplucate\n",39);
                return(1);
            }
            j++;
        }
        i++;
    }
    return (1);
}