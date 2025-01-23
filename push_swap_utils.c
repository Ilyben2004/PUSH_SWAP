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

void sort_stack(stack_t *a , stack_t *b, int * sorted_array)
{
    int div = 8; 
    int size = stack_size(a);
    int mid = (size / 2) - 1;
    int offset = size / 8;
    int start = mid - offset;
    int end = mid + offset;
    int i;
    int j = 0;

   
    while (a)
    {
        if(included_in_tab(a->value , sorted_array , start , end))
        {
        
           
            pb(&a,&b);
            printf("pb\n");
            if(b->value < sorted_array[mid])
            {  
                rb(&b);
                printf("rb\n");

            }

        }
        else
        {
            i = check_values_in_tab(a,sorted_array , start, end);
            if ( i == -1)
            {
                start -= offset;
                end += offset;
                if (start <0)
                    start = 0;
                if (end >= size)
                    end = size - 1;
            }
            else
            {
                if (i != 0)
                {
                    j = 0;
                    while (j < i )
                    {
                        ra(&a);
                        printf("ra\n");
                        j++;
                    }
                }
            }


        }
    }
    turn_it_back_to_a(a,b,sorted_array,size);
}

void print_stack(stack_t * a)
{
    while (a)
    {
        printf("%d\n",a->value);
        a = a->next;
    }

}
int max_in_tab(int * tab , int size)
{
    int max;
    int i;

    i = 1;
    max = tab[0];
    while (i < size)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

int max_less_than(int max, int * tab , int size)
{
    int i;
    int max_ret;

    i = 1;
    max_ret = tab[0];
    while (i < size)
    {
        if (tab[i] > max_ret && tab[i] < max)
            max_ret = tab[i];
        i++;
    }
        return (max_ret);
}

void turn_it_back_to_a(stack_t *a , stack_t *b ,int * tab, int size)
{
    int max;
    int how_many_rrb;

    how_many_rrb = 0;
    max = max_in_tab(tab,size);
    while (b)
    {
     
        if (b->value == max)
        {
            pa(&a,&b);
            printf("pa\n");
            max = max_less_than(max , tab , size);
            while(how_many_rrb >0)
            {
                rrb(&b);
                how_many_rrb--;
                printf("rrb\n");
            }
        }
        else
        {
            while (b->value != max)
            {
                rb(&b);
                how_many_rrb++;
                printf("rb\n");
            }
        }
    }
    // printf("stack a is : \n");
    // print_stack(a);
}