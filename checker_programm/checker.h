/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:40:14 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:40:44 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

int	execute_action(t_stack **a, t_stack **b, char *line);
int	ft_strncmp(const char *s1, const char *s2, int n);

#endif
