/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:19 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 06:50:07 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_push_a(t_stack *stack)
{
	t_list *move;

	move = stack->b;
	stack->b = stack->b->next;
	move->next = NULL;
	ft_lstadd_back(&stack->a, move);
}

void stack_push_b(t_stack *stack)
{
	ft_lstadd_back(&stack->b, stack->a->content);
	stack->a->content = NULL;
	ft_lstpop_back(&stack->a, free);
}
