/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:14:49 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/08 23:04:37 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_made_of(char *str, char *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isset(str[i++], set))
			return (0);
	}
	return (1);
}

static int	ft_verif_args_one_argument(char **argv)
{
	int i;

	if (!str_is_made_of(argv[1], "0123456789 +-"))
		return (0);
	argv = ft_split(argv[1], ' ');
	i = 0;
	while (argv[i])
	{
		if ((ft_atoi(argv[i]) == 0 && ft_strcmp(argv[i], "0"))
			|| (ft_atoi(argv[i]) == -1 && ft_strncmp(argv[i], "-1", 2)))
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
		if ((ft_atoi(argv[i]) == 0 && ft_strcmp(argv[i], "0"))
			|| (ft_atoi(argv[i]) == -1 && ft_strncmp(argv[i], "-1", 2)))
			return (0);
		i++;
	}
	i = 1;
	while (i < argc - 1)
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
			return (write(1, "error\n", 6), -1);
		tab = parse_one_argument_push_swap(argv, &argc);
	}
	else
	{
		if (!ft_verif_args(argv, argc))
			return (write(1, "error\n", 6), -1);
		tab = parse_push_swap(argv, argc);
		
	}
	size = argc - 1;
	stack = stack_create_from(tab, size);
	free(tab);
	if (size < 10)
	{
		push_swap_little(stack);
		stack_destroy(stack);
	}
	else
		push_swap_big(stack);
	return (0);
}
