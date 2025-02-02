#include "push_swap.h"

int	is_all_space(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int	check_args(char **argv)
{
	int		i;
	char	**splited;
	int		j;

	i = 0;
	while (argv[++i])
	{
		if (!*argv[i] || is_all_space(argv[i]))
			return (write(1, "Error\n", 6), 0);
		j = -1;
		splited = ft_split(argv[i], ' ');
		if (!splited)
			return (0);
		while (splited[++j])
		{
			if (!is_number(splited[j]))
				return (write(1, "Error\n", 6), free_splited(splited), 0);
			else if (is_number(splited[j]))
				if (ft_atoi(splited[j]) > INT_MAX
					|| ft_atoi(splited[j]) < INT_MIN)
					return (write(1, "Error\n", 6), free_splited(splited), 0);
		}
		free_splited(splited);
	}
	return (1);
}
int	is_number(char *number)
{
	if (*number == 0)
		return (0);
	if (*number == '+' || *number == '-')
		number++;
	if (*number == 0)
		return (0);
	while (*number)
	{
		if (!ft_isdigit(*number))
			return (0);
		number++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	check_duplicate(int *sorted_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_array[i] == sorted_array[j])
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
