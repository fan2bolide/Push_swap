/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:14:49 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/08 04:49:47 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ft_verif_args(char **argv, int argc)
// {
// 	int	i;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		if ((ft_atoi(argv[i + 1]) == 0 && ft_strcmp(argv[i + 1], "0"))
// 			|| (ft_atoi(argv[i + 1]) == -1 && ft_strncmp(argv[i + 1], "-1", 2)))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;

	printf("%s\n", argv[1]);
	// if (!ft_verif_args(argv, argc))
	// 	return (-1);
	tab = parse_push_swap(argv, &argc);
	printf("fdsjakfas\n");
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
