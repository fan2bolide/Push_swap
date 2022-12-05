/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:19 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/05 22:55:58 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push_a(t_stack *stack)
{
	t_list	*curr;

	if (!stack->b)
		return (0);
	curr = stack->b;
	stack->b = stack->b->next;
	curr->next = stack->a;
	stack->a = curr;
	ft_putstr("pa\n");
	return (1);
}

int	stack_push_b(t_stack *stack)
{
	t_list	*curr;

	if (!stack->a)
		return (0);
	curr = stack->a;
	stack->a = stack->a->next;
	curr->next = stack->b;
	stack->b = curr;
	ft_putstr("pb\n");
	return (1);
}

int	stack_swap(t_list **list)
{
	t_list	*curr;

	if (!list || !*list || !(*list)->next)
		return (0);
	curr = *list;
	*list = (*list)->next;
	curr->next = (*list)->next;
	(*list)->next = curr;
	return (1);
}

int	stack_rotate(t_list **list)
{
	t_list	*curr;

	if (!list || !*list || !(*list)->next)
		return (0);
	curr = *list;
	*list = (*list)->next;
	ft_lstlast(*list)->next = curr;
	curr->next = NULL;
	return (1);
}

int	stack_reverse_rotate(t_list **list)
{
	t_list	*curr;

	if (!list || !*list || !(*list)->next)
		return (0);
	curr = *list;
	while (curr && curr->next && curr->next->next)
		curr = curr->next;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return (1);
}
