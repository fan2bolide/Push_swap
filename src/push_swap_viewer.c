/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_viewer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:22:38 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/12 08:24:33 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <fcntl.h>

static int	ft_verif_args(char **argv, int argc)
{
	int	i;

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

static void	stack_viewer_apply_instruction2(char *instruction,
											t_stack *stack)
{
	if (!ft_strncmp(instruction, "rr\n", 2))
	{
		stack_rotate(&stack->b);
		stack_rotate(&stack->a);
	}
	else if (!ft_strncmp(instruction, "rrb\n", 3))
		stack_reverse_rotate(&stack->b);
	else if (!ft_strncmp(instruction, "rra\n", 3))
		stack_reverse_rotate(&stack->a);
	else if (!ft_strncmp(instruction, "rrr\n", 3))
	{
		stack_reverse_rotate(&stack->b);
		stack_reverse_rotate(&stack->a);
	}
}

static void	stack_viewer_apply_instruction(char *instruction, t_stack *stack)
{
	if (!ft_strncmp(instruction, "pa\n", 2))
		stack_push_a(stack);
	else if (!ft_strncmp(instruction, "pb\n", 2))
		stack_push_b(stack);
	else if (!ft_strncmp(instruction, "sb\n", 2))
		stack_swap(&stack->b);
	else if (!ft_strncmp(instruction, "sa\n", 2))
		stack_swap(&stack->a);
	else if (!ft_strncmp(instruction, "ra\n", 2))
		stack_rotate(&stack->a);
	else if (!ft_strncmp(instruction, "rb\n", 2))
		stack_rotate(&stack->b);
	else if (!ft_strncmp(instruction, "rra\n", 2))
		stack_reverse_rotate(&stack->a);
	else if (!ft_strncmp(instruction, "rrb\n", 2))
		stack_reverse_rotate(&stack->b);
	else
		stack_viewer_apply_instruction2(instruction, stack);
}

static int	push_swap_visualuser_input_verifier(t_stack *stack)
{
	char	*input;
	int		fd;

	fd = open("logfile", O_RDONLY);
	input = get_next_line(fd);
	while (input)
	{
		stack_viewer_apply_instruction(input, stack);
		if (stack_is_sorted(stack))
		{
			print_stack(stack);
			ft_printf("Sorted !\n");
			free(input);
			break ;
		}
		print_stack(stack);
		free(input);
		input = get_next_line(fd);
	}
	if (!stack_is_sorted(stack))
		ft_printf("???????????????????????????????\n");
	else
		ft_printf("Bien ouej\n");
	stack_destroy(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*tab;
	size_t	size;
	t_stack	*stack;

	if (!ft_verif_args(argv, argc))
		return (-1);
	tab = parse_push_swap(argv, argc);
	size = argc - 1;
	stack = stack_create_from(tab, size);
	print_stack(stack);
	return (push_swap_visualuser_input_verifier(stack));
}
