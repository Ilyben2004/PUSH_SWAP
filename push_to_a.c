/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:31:40 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:31:48 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_b_rortate(t_stack **b, int max, int less_than_max,
		int less_than_max_pushed)
{
	int	tab[2];

	tab[0] = get_operation(*b, max);
	if (less_than_max_pushed == 0)
	{
		tab[1] = get_operation(*b, less_than_max);
		if (abs(tab[1]) < abs(tab[0]))
			tab[0] = tab[1];
	}
	if (tab[0] > 0)
	{
		while (tab[0]-- != 0)
		{
			rb(b);
			printf("rb\n");
		}
	}
	else
	{
		while (tab[0]++ != 0)
		{
			rrb(b);
			printf("rrb\n");
		}
	}
}

void	sa_and_newmax(t_stack **a, t_max *max_cords, int *tab, int size)
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

void	turn_it_back_to_a(t_stack **a, t_stack **b, int *tab, int size)
{
	t_max	max_cords;

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
