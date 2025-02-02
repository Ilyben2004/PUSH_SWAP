#include "../push_swap.h"

void	sb(stack_t **b)
{
	int size;
	stack_t *helper;
	stack_t *helper2;
	;

	size = stack_size(*b);
	if (size >= 2)
	{
		if (size == 2)
		{
			(*b)->next->next = *b;
			helper = (*b)->next;
			(*b)->next = NULL;
			*b = helper;
		}
		else
		{
			helper = (*b)->next->next;
			helper2 = (*b)->next;
			(*b)->next->next = *b;
			(*b)->next = helper;
			*b = helper2;
		}
	}
}