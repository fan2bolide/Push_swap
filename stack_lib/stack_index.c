/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:41:18 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/05 23:15:40 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lib.h"

static int	stack_index_get_index(t_stack *stack, int data)
{
	int		count;
	t_list	*curr;

	count = 0;
	curr = stack->a;
	while (curr)
	{
		if (*(int *)curr->content < data)
			count++;
		curr = curr->next;
	}
	return (count);
}

t_stack	*stack_index(t_stack *stack)
{
	t_list	*curr;
	t_stack	*new_stack;
	int		*tab;
	int		i;

	curr = stack->a;
	tab = malloc(sizeof(int) * ft_lstsize(stack->a));
	i = 0;
	while (curr)
	{
		tab[i] = stack_index_get_index(stack, *(int *)curr->content);
		curr = curr->next;
		i++;
	}
	new_stack = stack_create_from(tab, ft_lstsize(stack->a));
	free(tab);
	stack_destroy(stack);
	return (new_stack);
}
