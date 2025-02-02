/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:33:51 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:33:52 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*create_stack_a_helper(t_stack **stack_a, t_stack **a, char **argv,
		int i)
{
	char	**splited;
	int		j;

	splited = ft_split(argv[i], ' ');
	if (!splited)
		return (free_stacks_tab(*a, NULL), NULL);
	j = -1;
	while (splited[++j])
	{
		(*stack_a)->value = ft_atoi(splited[j]);
		if (splited[j + 1] != NULL || argv[i + 1] != NULL)
		{
			(*stack_a)->next = malloc(sizeof(t_stack));
			(*stack_a) = (*stack_a)->next;
			if (!(*stack_a))
				return (free_splited(splited), free_stacks_tab(*a, NULL), NULL);
		}
		else
			(*stack_a)->next = NULL;
	}
	free_splited(splited);
	return ("valid");
}

static t_stack	*create_stack_a(t_stack **a, char **argv)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		if (!stack_a)
			return (NULL);
	*a = stack_a;
	while (argv[++i])
	{
		if (!create_stack_a_helper(&stack_a, a, argv, i))
			return (NULL);
	}
	return (*a);
}

static int	*create_sorted_array(t_stack *a, int size)
{
	int	*sorted_array;
	int	i;

	i = 0;
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
		return (NULL);
	while (i < size)
	{
		sorted_array[i] = a->value;
		a = a->next;
		i++;
	}
	i = 0;
	return (bubble_sort(sorted_array, size));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*sorted_array;

	b = NULL;
	if (argc <= 1 || !check_args(argv))
		return (EXIT_FAILURE);
	if (!create_stack_a(&a, argv))
		return (EXIT_FAILURE);
	size = stack_size(a);
	sorted_array = create_sorted_array(a, size);
	if (!sorted_array)
		return (free_stacks_tab(a, NULL), EXIT_FAILURE);
	if (check_duplicate(sorted_array, size))
		return (free_stacks_tab(a, sorted_array), EXIT_FAILURE);
	if (!is_sorted(a))
		sort_stack(&a, &b, sorted_array);
	free_stacks_tab(a, sorted_array);
	return (EXIT_SUCCESS);
}
