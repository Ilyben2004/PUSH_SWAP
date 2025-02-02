#include "../push_swap.h"

void	pb(stack_t **a, stack_t **b)
{
	int size_a;
	stack_t *helper;

	size_a = stack_size(*a);

	if (size_a > 0)
	{
		helper = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = helper;
	}
}