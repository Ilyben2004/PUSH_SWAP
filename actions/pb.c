/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:36:31 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:36:32 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	int		size_a;
	t_stack	*helper;

	size_a = stack_size(*a);
	if (size_a > 0)
	{
		helper = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = helper;
	}
}
