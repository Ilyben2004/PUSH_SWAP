/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:42 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:38:59 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack **b)
{
	int		size;
	t_stack	*helper;
	t_stack	*helper2;

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
