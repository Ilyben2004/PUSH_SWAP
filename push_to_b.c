/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:34:53 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:54 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int *sorted_array, t_cords cords)
{
	pb(a, b);
	printf("pb\n");
	if ((*b)->value < sorted_array[cords.mid])
	{
		if (a && *a && !included_in_tab((*a)->value, sorted_array, cords.start,
				cords.end) && check_values_in_tab(*a, sorted_array, cords.start,
				cords.end) != -1)
		{
			rr(a, b);
			printf("rr\n");
		}
		else
		{
			rb(b);
			printf("rb\n");
		}
	}
}

void	biggest_interval(t_cords *cords)
{
	cords->start -= cords->offset;
	cords->end += cords->offset;
	if (cords->start < 0)
		cords->start = 0;
	if (cords->end >= cords->size)
		cords->end = cords->size - 1;
}

void	handle_a_rotate(t_stack **a, t_cords *cords, int *sorted_array)
{
	int	i;

	i = check_values_in_tab(*a, sorted_array, cords->start, cords->end);
	if (i == -1)
		biggest_interval(cords);
	else
	{
		if (i != 0)
		{
			while (i != 0)
			{
				ra(a);
				printf("ra\n");
				i--;
			}
		}
	}
}

void	init_cords(t_cords *cords, t_stack *a)
{
	cords->size = stack_size(a);
	if (cords->size > 100)
		cords->div = 18;
	else if (cords->size <= 100 && cords->size >= 10)
		cords->div = 8;
	else
		cords->div = 4;
	cords->mid = (cords->size / 2) - 1;
	cords->offset = cords->size / cords->div;
	cords->start = cords->mid - cords->offset;
	cords->end = cords->mid + cords->offset;
}

void	sort_stack(t_stack **a, t_stack **b, int *sorted_array)
{
	t_cords	cords;

	init_cords(&cords, *a);
	if (cords.size <= 5)
	{
		if (cords.size == 1)
			return ;
		else if (cords.size <= 3)
			sort_three(a);
		else
			sort_five(a, b);
		return ;
	}
	while (*a)
	{
		if (included_in_tab((*a)->value, sorted_array, cords.start, cords.end))
			push_to_b(a, b, sorted_array, cords);
		else
			handle_a_rotate(a, &cords, sorted_array);
	}
	turn_it_back_to_a(a, b, sorted_array, cords.size);
}
