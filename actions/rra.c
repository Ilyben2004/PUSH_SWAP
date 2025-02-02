/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:08 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:38:21 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	int		size;
	t_stack	*first_one;
	t_stack	*before_last_one;

	size = stack_size(*a);
	first_one = *a;
	if (size >= 2)
	{
		while ((*a)->next)
		{
			if ((*a)->next->next == NULL)
				before_last_one = *a;
			*a = (*a)->next;
		}
		before_last_one->next = NULL;
		(*a)->next = first_one;
	}
}
