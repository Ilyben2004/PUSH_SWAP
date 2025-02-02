/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:36:59 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:38:07 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack **b)

{
	int		size;
	t_stack	*second_one;
	t_stack	*first_one;

	size = stack_size(*b);
	if (size >= 2)
	{
		second_one = (*b)->next;
		first_one = *b;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = first_one;
		first_one->next = NULL;
		*b = second_one;
	}
}
