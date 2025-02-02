#include "../push_swap.h"

void	rb(stack_t **b)

{
	int size;
	stack_t *second_one;
	stack_t *first_one;

	size = stack_size(*b);
	if (size >= 2)
	{
		second_one = (*b)->next;
		first_one = *b;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = first_one;
		first_one->next = NULL;
		*b = second_one;
	}
}