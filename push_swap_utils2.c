#include "push_swap.h"

int	max_in_tab(int *tab, int size)
{
	int	max;
	int	i;

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

int	max_less_than(int max, int *tab, int size)
{
	int	i;
	int	max_ret;

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

int	get_operation(stack_t *b, int value)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(b);
	while (b)
	{
		if (b->value == value)
			break ;
		i++;
		b = b->next;
	}
	if (i > size / 2)
		return (i - size);
	return (i);
}

void	free_stacks_tab(stack_t *a, int *tab)
{
	stack_t	*helper;

	while (a)
	{
		helper = a->next;
		free(a);
		a = helper;
	}
	if (tab)
		free(tab);
}

void	free_splited(char **splited)
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