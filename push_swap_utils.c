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

void push_to_b(stack_t **a , stack_t **b, int * sorted_array, cords_t cords)
{
    pb(a,b);
    printf("pb\n");
    if((*b)->value < sorted_array[cords.mid])
    {
        if(a && *a && !included_in_tab((*a)->value , sorted_array , cords.start , cords.end))
        {
            rr(a,b); 
            printf("rr\n");          
        }
        else
        {
            rb(b);
            printf("rb\n");
        }
    }
}

void biggest_interval(cords_t * cords)
{
    cords->start -= cords->offset;
    cords->end += cords->offset;
    if (cords->start <0)
        cords->start = 0;
    if (cords->end >= cords->size)
        cords->end = cords->size - 1;
}

void handle_a_rotate(stack_t **a, cords_t *cords , int * sorted_array)
{
    int i;
    int j;

    i = check_values_in_tab(*a,sorted_array , cords->start, cords->end);
    if ( i == -1)
        biggest_interval(cords);
    else
    {
        if (i != 0)
        {
            j = 0;
            while (j < i )
            {
                ra(a);
                printf("ra\n");
                j++;
            }
        }
    }
}


void sort_stack(stack_t **a , stack_t **b, int * sorted_array)
{
    cords_t cords;
    int i;
    int j;

    cords.div = 8;
    cords.size = stack_size(*a);
    cords.mid = (cords.size / 2) - 1;
    cords.offset = cords.size / cords.div ;
    cords.start = cords.mid - cords.offset;
    cords.end = cords.mid + cords.offset;
    while (*a)
    {
        if(included_in_tab((*a)->value , sorted_array , cords.start , cords.end))
            push_to_b(a,b,sorted_array,cords);
        else
            handle_a_rotate(a,&cords,sorted_array);
    }
    turn_it_back_to_a(a,b,sorted_array,cords.size);
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

int get_operation(stack_t *b ,int value)
{
    int size;
    int i;

    i = 0;
    size = stack_size(b);
    while (b)
    {
        if (b->value == value)
            break;
        i++;
        b = b->next;
    }
    if (i > size/2)
        return (i - size);
    return (i);

}
void handle_b_rortate(stack_t **b, int max)
{
    int i;

    i = get_operation(*b,max);
    if (i > 0)
    {
        while (i != 0)
        {
            rb(b);
            printf("rb\n");
            i--;
        }
    }
    else
        while (i != 0)
        {
            rrb(b);
            printf("rrb\n");
            i++;
        }

}
void turn_it_back_to_a(stack_t **a , stack_t **b ,int * tab, int size)
{
    int max;
    int i;

    i = 0;
    max = max_in_tab(tab,size);
    while (*b)
    {
        if ((*b)->value == max)
        {
            pa(a,b);
            printf("pa\n");
            max = max_less_than(max,tab,size);
        }
        else
            handle_b_rortate(b,max);
    }
}

void free_stacks_tab(stack_t * a, int * tab)
{
    stack_t * helper;
    while (a)
    {
        helper = a->next;
        free(a);
        a = helper;
    }
    free(tab);
}

long     ft_atoi(const char *str)
{
        long             sign;
        size_t  result;

        result = 0;
        sign = 1;
        while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
                        || *str == '\f' || *str == '\r'))
                str++;
        if (*str == '-' || *str == '+')
        {
                if (*str == '-')
                        sign = -1;
                str++;
        }
        while (ft_isdigit(*str))
        {
                result = result * 10 + (*str - '0');
                str++;
        }
        return (result * sign);
}

void free_splited(char ** splited)
{
    int i;

    i = 0;
    while (splited[i])
    {
        free(splited[i]);
        i++;
    }
    free(splited);
}
