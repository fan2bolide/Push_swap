/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_visualiser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:22:38 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/04 06:12:32 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <fcntl.h>

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

int	push_swap_visualiser(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;
	t_stack	*stack_copy;
	char *input;

	if (!ft_verif_args(argv, argc))
		return (-1);
	tab = parse_push_swap(argv, argc);
	size = argc - 1;
	stack = stack_create_from(tab, size);
	stack_copy = stack_create_from(tab, size);
	free(tab);
	print_stack(stack);
	printf("Start sorting\n");
	int fd = open("./log_file.log", O_WRONLY | O_CREAT, 0644);
	push_swap(stack_copy, fd);
	close(fd);
	fd = open("./log_file.log", O_RDONLY);
	input = get_next_line(fd);
	while (input)
	{
		if (!ft_strcmp(ft_strtrim(input, "\n"), "pa"))
			stack_push_a(stack);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "pb"))
			stack_push_b(stack);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "sb"))
			stack_swap(&stack->b);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "sa"))
			stack_swap(&stack->a);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "ra"))
			stack_rotate(&stack->a);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "rb"))
			stack_rotate(&stack->b);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "rr"))
		{
			stack_rotate(&stack->b);
			stack_rotate(&stack->a);	
		}
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "rrb"))
			stack_reverse_rotate(&stack->b);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "rra"))
			stack_reverse_rotate(&stack->a);
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "rrr"))
		{
			stack_reverse_rotate(&stack->b);
			stack_reverse_rotate(&stack->a);
		}
		else if (!ft_strcmp(ft_strtrim(input, "\n"), "stop"))
			return (free(input), 0);
		if (stack_is_sorted(stack))
		{
			print_stack(stack);
			printf("Sorted !\n");
			close(fd);
			return (0);
		}
		print_stack(stack);
		free(input);
		input = get_next_line(fd);
	}
	printf("???\n");
	return (0);

	//-------------------------------//
	// ft_stack_destroy(stack);
}

int main(int argc, char **argv)
{
	return(push_swap_visualiser(argc, argv));
}
