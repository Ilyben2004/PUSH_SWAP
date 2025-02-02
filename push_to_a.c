#include "push_swap.h"

void	handle_b_rortate(stack_t **b, int max, int less_than_max,
		int less_than_max_pushed)
{
	int	i;
	int	j;

	i = get_operation(*b, max);
	if (less_than_max_pushed == 0)
	{
		j = get_operation(*b, less_than_max);
		if (abs(j) < abs(i))
			i = j;
	}
	if (i > 0)
	{
		while (i-- != 0)
		{
			rb(b);
			printf("rb\n");
		}
	}
	else
		while (i++ != 0)
		{
			rrb(b);
			printf("rrb\n");
		}
}

void	sa_and_newmax(stack_t **a, max_t *max_cords, int *tab, int size)
{
	if ((*a)->value == max_cords->max)
	{
		if ((*a)->next && (*a)->value > (*a)->next->value)
		{
			sa(a);
			printf("sa\n");
		}
		if (max_cords->less_than_max_pushed == 1)
			max_cords->max = max_less_than(max_cords->less_than_max, tab, size);
		else
			max_cords->max = max_less_than(max_cords->max, tab, size);
		max_cords->less_than_max_pushed = 0;
		max_cords->less_than_max = max_less_than(max_cords->max, tab, size);
	}
}

void	turn_it_back_to_a(stack_t **a, stack_t **b, int *tab, int size)
{
	max_t	max_cords;

	max_cords.less_than_max_pushed = 0;
	max_cords.max = max_in_tab(tab, size);
	max_cords.less_than_max = max_less_than(max_cords.max, tab, size);
	while (*b)
	{
		if ((*b)->value == max_cords.max
			|| ((*b)->value == max_cords.less_than_max))
		{
			if ((*b)->value == max_cords.less_than_max)
				max_cords.less_than_max_pushed = 1;
			pa(a, b);
			printf("pa\n");
			sa_and_newmax(a, &max_cords, tab, size);
		}
		else
			handle_b_rortate(b, max_cords.max, max_cords.less_than_max,
				max_cords.less_than_max_pushed);
	}
}
