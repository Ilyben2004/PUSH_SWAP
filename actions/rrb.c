#include "../push_swap.h"

void	rrb(stack_t **b)
{
	int size;
	stack_t *first_one;
	stack_t *before_last_one;

	size = stack_size(*b);
	first_one = *b;
	if (size >= 2)
	{
		while ((*b)->next)
		{
			if ((*b)->next->next == NULL)
				before_last_one = *b;
			*b = (*b)->next;
		}
		before_last_one->next = NULL;
		(*b)->next = first_one;
	}
}