/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:44:35 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/05 23:18:31 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_radix_get_max_bits_number(t_list *stack)
{
	int		max;

	max = 0;
	while (stack)
	{
		while ((*(int *)stack->content >> max) != 0)
			max++;
		stack = stack->next;
	}
	return (max);
}

static void	stack_radix_sort(t_stack *stack, int sort_index)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(stack->a);
	while (i++ < size)
	{
		if (((*(int *)stack->a->content) >> sort_index) % 2 == 0)
			stack_push_b(stack);
		else
		{
			stack_rotate(&stack->a);
			ft_putstr("ra\n");
		}
	}
	while (stack->b)
		stack_push_a(stack);
}

void	push_swap_big(t_stack *stack)
{
	int	sort_index;
	int	max_index;

	stack = stack_index(stack);
	max_index = stack_radix_get_max_bits_number(stack->a);
	sort_index = 0;
	while (!stack_is_sorted(stack) && sort_index <= max_index)
		stack_radix_sort(stack, sort_index++);
	stack_destroy(stack);
}
