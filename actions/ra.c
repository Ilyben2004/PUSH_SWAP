/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:36:48 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:36:49 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)

{
	int		size;
	t_stack	*second_one;
	t_stack	*first_one;

	size = stack_size(*a);
	if (size >= 2)
	{
		second_one = (*a)->next;
		first_one = *a;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = first_one;
		first_one->next = NULL;
		*a = second_one;
	}
}
