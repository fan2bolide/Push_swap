/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_little.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:07 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/16 14:56:01 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_list *list, t_list *node)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		if (list == node)
			return (i);
		list = list->next;
		i++;
	}
	return (0);
}

static void	push_swap_little_rotate(t_stack *stack, t_list *min)
{
	if (get_index(stack->a, min) <= ft_lstsize(stack->a) / 2)
	{
		while (stack->a && stack->a != min)
		{
			stack_rotate(&stack->a);
			ft_putstr("ra\n");
		}
	}	
	else
	{
		while (stack->a && stack->a != min)
		{
			stack_reverse_rotate(&stack->a);
			ft_putstr("rra\n");
		}
	}
}

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
		push_swap_little_rotate(stack, min);
		if (!list_is_sorted(stack->a))
			stack_push_b(stack);
	}
	while (stack->b)
		stack_push_a(stack);
	stack_destroy(stack);
}
