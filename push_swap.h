/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:19:44 by ibennaje          #+#    #+#             */
/*   Updated: 2025/02/02 18:19:50 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct stack_s
{
	int				value;
	struct stack_s	*next;
}					t_stack;

typedef struct cords_s
{
	int				div;
	int				size;
	int				mid;
	int				offset;
	int				start;
	int				end;
}					t_cords;

typedef struct max_s
{
	int				max;
	int				less_than_max;
	int				less_than_max_pushed;
}					t_max;

int					*bubble_sort(int *tab, int size);
int					is_number(char *number);
int					stack_size(t_stack *a);
//*********** actions ****************//
void				sa(t_stack **a);
void				sb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				rb(t_stack **b);
void				ra(t_stack **a);
void				rrb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// **********************************//
void				sort_stack(t_stack **a, t_stack **b, int *sorted_array);
int					check_values_in_tab(t_stack *a, int *tab, int start,
						int end);
int					included_in_tab(int value, int *tab, int start, int end);
void				turn_it_back_to_a(t_stack **a, t_stack **b, int *tab,
						int size);
int					max_less_than(int max, int *tab, int size);
int					max_in_tab(int *tab, int size);
void				free_stacks_tab(t_stack *a, int *tab);
int					ft_isdigit(int c);
int					is_number(char *number);
int					check_args(char **argv);
int					check_duplicate(int *sorted_array, int size);
void				sort_three(t_stack **a);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
void				free_splited(char **splited);
void				sort_five(t_stack **a, t_stack **b);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
int					is_sorted(t_stack *a);
int					get_operation(t_stack *b, int value);

#endif
