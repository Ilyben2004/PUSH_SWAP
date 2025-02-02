#include "checker.h"

static void	*create_stack_a_helper(stack_t **stack_a, stack_t **a, char **argv,
		int i)
{
	char	**splited;
	int		j;

	splited = ft_split(argv[i], ' ');
	if (!splited)
		return (free_stacks_tab(*a, NULL), NULL);
	j = -1;
	while (splited[++j])
	{
		(*stack_a)->value = ft_atoi(splited[j]);
		if (splited[j + 1] != NULL || argv[i + 1] != NULL)
		{
			(*stack_a)->next = malloc(sizeof(stack_t));
			(*stack_a) = (*stack_a)->next;
			if (!(*stack_a))
				return (free_splited(splited), free_stacks_tab(*a, NULL), NULL);
		}
		else
			(*stack_a)->next = NULL;
	}
	free_splited(splited);
	return ("valid");
}

static stack_t	*create_stack_a(stack_t **a, char **argv)
{
	stack_t	*stack_a;
	int		i;

	i = 0;
	stack_a = malloc(sizeof(stack_t));
	if (!stack_a)
		if (!stack_a)
			return (NULL);
	*a = stack_a;
	while (argv[++i])
	{
		if (!create_stack_a_helper(&stack_a, a, argv, i))
			return (NULL);
	}
	return (*a);
}

static int	*create_sorted_array(stack_t *a, int size)
{
	int	*sorted_array;
	int	i;

	i = 0;
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
		return (NULL);
	while (i < size)
	{
		sorted_array[i] = a->value;
		a = a->next;
		i++;
	}
	i = 0;
	return (bubble_sort(sorted_array, size));
}
static int	finish_it(stack_t *a, int *sorted_array)
{
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks_tab(a, sorted_array);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	stack_t	*a;
	stack_t	*b;
	int		*sorted_array;
	char	*line;

	b = NULL;
	if (argc <= 1 || !check_args(argv))
		return (EXIT_FAILURE);
	if (!create_stack_a(&a, argv))
		return (EXIT_FAILURE);
	sorted_array = create_sorted_array(a, stack_size(a));
	if (!sorted_array)
		return (free_stacks_tab(a, NULL), EXIT_FAILURE);
	if (check_duplicate(sorted_array, stack_size(a)))
		return (free_stacks_tab(a, sorted_array), EXIT_FAILURE);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (execute_action(&a, &b, line) == 0)
			return (free_stacks_tab(a, sorted_array), write(2, "Error\n", 6),
				free(line), 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (finish_it(a, sorted_array));
}
