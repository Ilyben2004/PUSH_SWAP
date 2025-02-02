/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:23 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:38:39 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	int		size;
	t_stack	*helper;
	t_stack	*helper2;

	size = stack_size(*a);
	if (size >= 2)
	{
		if (size == 2)
		{
			(*a)->next->next = *a;
			helper = (*a)->next;
			(*a)->next = NULL;
			*a = helper;
		}
		else
		{
			helper = (*a)->next->next;
			helper2 = (*a)->next;
			(*a)->next->next = *a;
			(*a)->next = helper;
			*a = helper2;
		}
	}
}
