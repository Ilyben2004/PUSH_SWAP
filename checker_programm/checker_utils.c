/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:40:19 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:40:20 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	execute_action(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		return (pa(a, b), 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		return (pb(a, b), 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		return (ra(a), 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		return (rb(b), 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		return (rr(a, b), 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		return (rra(a), 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (rrb(b), 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (rrr(a, b), 1);
	else if (!ft_strncmp(line, "sa\n", 3))
		return (sa(a), 1);
	else if (!ft_strncmp(line, "sb\n", 3))
		return (sb(b), 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		return (ss(a, b), 1);
	return (0);
}
