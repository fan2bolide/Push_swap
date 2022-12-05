/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_little.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:07 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/05 23:12:24 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_little(t_stack *stack)
{
	t_list	*min;

	while (stack->a && !list_is_sorted(stack->a))
	{
		if (*(int *)stack->a->content > *(int *)stack->a->next->content)
		{
			stack_swap(&stack->a);
			ft_putstr("sa\n");
		}
		min = stack_get_min(stack->a);
		while (stack->a && stack->a != min)
		{
			stack_rotate(&stack->a);
			ft_putstr("ra\n");
		}
		if (!list_is_sorted(stack->a))
			stack_push_b(stack);
	}
	while (stack->b)
		stack_push_a(stack);
}
