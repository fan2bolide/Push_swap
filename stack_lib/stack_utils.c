/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:13:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/03 04:14:26 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_create_from(int *tab, size_t size)
{
	t_stack	*stack;
	int		i;
	int		*data;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	while (i < size)
	{
		data = malloc(sizeof(int));
		if (!data)
			return (NULL);
		*data = tab[i];
		ft_lstadd_back(&stack->a, ft_lstnew(data));
		i++;
	}
	return (stack);
}

int	stack_is_sorted(t_stack *stack)
{
	t_list	*curr;

	curr = stack->a;
	while (curr && curr->next)
	{
		if (*(int *)curr->content > *(int *)curr->next->content)
			return (0);
	}
	return (1);
}