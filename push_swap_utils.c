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

void push_to_b(stack_t **a , stack_t **b, int * sorted_array, cords_t cords)
{

    pb(a,b);
    printf("pb\n");
    if((*b)->value < sorted_array[cords.mid])
    {
        if(a && *a && !included_in_tab((*a)->value , sorted_array , cords.start , cords.end) && check_values_in_tab(*a,sorted_array , cords.start, cords.end) != -1)
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

    i = check_values_in_tab(*a,sorted_array , cords->start, cords->end);
    if ( i == -1)
        biggest_interval(cords);
    else
    {
        if (i != 0)
        {

            while (i != 0)
            {
                ra(a);
                printf("ra\n");
                i--;
            }
        }
     }
}

void init_cords(cords_t * cords , stack_t *a)
{
    cords->size = stack_size(a);
    if (cords->size > 100)
        cords->div = 18;
    else if (cords->size <= 100 &&  cords->size >= 10)
        cords->div = 8;
    else 
        cords->div = 4;
    cords->mid = (cords->size / 2) - 1;
    cords->offset = cords->size / cords->div ;
    cords->start = cords->mid - cords->offset;
    cords->end = cords->mid + cords->offset;
}
void sort_stack(stack_t **a , stack_t **b, int * sorted_array)
{
    cords_t cords;

    init_cords(&cords , *a);
    if(cords.size <= 5)
    {
        if (cords.size == 1)
            return;
        else if (cords.size <= 3)
            sort_three(a);
        else 
            sort_five(a,b);
        return;
    }
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
int abs(int a)
{
    if (a >= 0)
        return (a);
    return(-a);
}
void handle_b_rortate(stack_t **b, int max,int less_than_max , int  less_than_max_pushed)
{
    int i;
    int j;

    i = get_operation(*b,max);
    if (less_than_max_pushed == 0)
    {
        j = get_operation(*b, less_than_max);
        if (abs(j) < abs(i))
            i = j;
    }
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
    int less_than_max;
    int less_than_max_pushed;


    i = 0;
    less_than_max_pushed = 0;
    max = max_in_tab(tab,size);
    less_than_max = max_less_than(max , tab , size);
    while (*b)
    {
           
        if ((*b)->value == max || ((*b)->value == less_than_max))
        {
            if ((*b)->value == less_than_max)
                less_than_max_pushed = 1;
            pa(a,b);
            printf("pa\n");
            if((*a)->value == max)
            {
                if ( (*a)->next && (*a)->value > (*a)->next->value )
                {   sa(a);
                    printf("sa\n");
                }
                if (less_than_max_pushed == 1)
                    max = max_less_than(less_than_max,tab,size);
                else
                    max = max_less_than(max,tab,size);
                less_than_max_pushed = 0;
                less_than_max =  max_less_than(max ,tab,size );
            }
        }
        else
        {
            handle_b_rortate(b,max,less_than_max,less_than_max_pushed);
        }
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
    if(tab)
        free(tab);
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
