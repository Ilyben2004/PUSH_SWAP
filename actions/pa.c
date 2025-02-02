/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:36:14 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:36:15 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	int		size_b;
	t_stack	*helper;

	size_b = stack_size(*b);
	if (size_b > 0)
	{
		helper = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = helper;
	}
}
