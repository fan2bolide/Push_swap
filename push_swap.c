/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:22:38 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 22:06:38 by bajeanno         ###   ########lyon.fr   */
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

int	push_swap(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;

	if (!ft_verif_args(argv, argc))
		return (-1);
	tab = parse_push_swap(argv, argc);
	size = argc - 1;
	stack = stack_create_from(tab, size);
	free(tab);
	print_stack(stack);
	
	//-------------------------------//
	char *input = get_next_line(0);
	while (input)
	{
		if (!ft_strcmp(ft_strtrim(input, "\n"), "pa"))
			stack_push_a(stack);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "pb"))
			stack_push_b(stack);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "stop"))
		{
			free(input);
			exit(0);
		}
		print_stack(stack);
		free(input);
		input = get_next_line(0);
	}
		
	
	
	return (0);

	//-------------------------------//
	// ft_stack_destroy(stack);
}

int main(int argc, char **argv)
{
	return(push_swap(argc, argv));
}
