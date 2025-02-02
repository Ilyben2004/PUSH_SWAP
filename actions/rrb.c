/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:16 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:39:21 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_stack **b)
{
	int		size;
	t_stack	*first_one;
	t_stack	*before_last_one;

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
