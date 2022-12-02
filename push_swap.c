/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:22:38 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 05:27:15 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_verif_args(char **argv, int argc)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		if ((ft_atoi(argv[i + 1]) == 0 && ft_strcmp(argv[i + 1], "0"))
			|| (ft_atoi(argv[i + 1]) == -1 && ft_strncmp(argv[i + 1], "-1", 2)))
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;

	if (!ft_verif_args(argv, argc))
		return (-1);
	tab = ft_parse_push_swap(argv, argc);
	size = argc - 1;
	stack = ft_stack_create_from(tab, size);
	ft_print_stack(stack);
}

int main(int argc, char **argv)
{
	push_swap(argc, argv);
	return(0);
}
