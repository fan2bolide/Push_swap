/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:14:49 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/18 04:01:37 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] == tab[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	str_is_made_of(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isset(str[i++], set))
			return (0);
	return (1);
}

static int	ft_verif_args_one_argument(char **argv)
{
	int	i;

	if (!str_is_made_of(argv[1], "0123456789 +-"))
		return (0);
	argv = ft_split(argv[1], ' ');
	i = 0;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
			return (free(argv), 0);
		i++;
	}
	return (1);
}

static int	ft_verif_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (!str_is_made_of(argv[i++], "0123456789 +-"))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;

	if (argc == 2)
	{
		if (!ft_verif_args_one_argument(argv))
			return (write(1, "Error\n", 6), -1);
		tab = parse_one_argument_push_swap(argv, &argc);
	}
	else
	{
		if (!ft_verif_args(argv, argc))
			return (write(1, "Error\n", 6), -1);
		tab = parse_push_swap(argv, argc);
	}
	size = argc - 1;
	if (!check_doubles(tab, size))
		return (free(tab), write(1, "Error\n", 6), 1);
	stack = stack_create_from(tab, size);
	if (size <= 50)
		push_swap_little(stack);
	else
		push_swap_big(stack);
	return (0);
}
