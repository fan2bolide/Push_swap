/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:14:49 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/17 15:30:09 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_check_doubles(int *tab, size_t size)
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

int	push_swap_str_is_made_of(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isset(str[i++], set))
			return (0);
	return (1);
}

int	push_swap_verif_args_one_argument(char **argv)
{
	int	i;

	if (!push_swap_str_is_made_of(argv[1], "0123456789 +-"))
		return (0);
	argv = ft_split(argv[1], ' ');
	if (!argv)
		return (ft_split_destroy(argv), 0);
	i = 0;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
			return (ft_split_destroy(argv), 0);
		i++;
	}
	return (ft_split_destroy(argv), 1);
}

int	push_swap_verif_args(char **argv, int argc)
{
	int	i;

	if (argc < 2)
		return (0);
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
		if (!push_swap_str_is_made_of(argv[i++], "0123456789 +-"))
			return (0);
	}
	return (1);
}

int	push_swap_start_sorting_program(int *tab, int size)
{
	t_stack	*stack;

	stack = stack_create_from(tab, size);
	if (!stack)
		return (write(2, "Memory allocation failed, exiting program\n", 42),
			free(tab), 0);
	if (size <= 50)
		push_swap_little(stack);
	else
		push_swap_big(stack);
	return (1);
}
