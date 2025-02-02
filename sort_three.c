/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:34:58 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:59 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->next)
		{
			if (a->value > a->next->value)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

static int	get_max_min_pos(t_stack *a, int max)
{
	int		max_min_value;
	int		i;
	t_stack	*helper;
	int		pos;

	max_min_value = a->value;
	pos = 0;
	i = 1;
	helper = a->next;
	while (helper)
	{
		if (max && helper->value > max_min_value)
		{
			max_min_value = helper->value;
			pos = i;
		}
		else if (!max && helper->value < max_min_value)
		{
			max_min_value = helper->value;
			pos = i;
		}
		i++;
		helper = helper->next;
	}
	return (pos);
}

void	sort_three(t_stack **a)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = get_max_min_pos(*a, 1);
	if (size == 3)
	{
		if (pos == 0)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
		if (pos == 1)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	if ((*a)->value > (*a)->next->value)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
}

static void	sort_five_helper(t_stack **a, int ops)
{
	while (ops != 0)
	{
		if (ops > 0)
		{
			ra(a);
			write(1, "ra\n", 3);
			ops--;
		}
		else
		{
			rra(a);
			write(1, "rra\n", 4);
			ops++;
		}
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	ops;

	while (stack_size(*a) > 3)
	{
		pos = get_max_min_pos(*a, 0);
		if (pos > stack_size(*a) / 2)
			ops = pos - stack_size(*a);
		else
			ops = pos;
		sort_five_helper(a, ops);
		pb(a, b);
		write(1, "pb\n", 3);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	write(1, "pa\npa\n", 6);
}
