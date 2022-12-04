/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:13:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/04 05:59:28 by bajeanno         ###   ########lyon.fr   */
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
	return (!stack->b && list_is_sorted(stack->a));
}

t_list *stack_get_min(t_list *list)
{
	t_list *min;
	
	min = list;
	while (list)
	{
		if(*(int *)list->content < *(int *)min->content)
		{
			min = list;
		}
		list = list->next;
	}
	return (min);
}

int	list_is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}