/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:13:59 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/06 07:55:17 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lib.h"

t_stack	*stack_create_from(int *tab, size_t size)
{
	t_stack	*stack;
	size_t	i;
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
			return (ft_lstclear(&stack->a, free), NULL);
		*data = tab[i];
		ft_lstadd_back(&stack->a, ft_lstnew(data));
		i++;
	}
	return (free(tab), stack);
}

t_list	*stack_get_min(t_list *list)
{
	t_list	*min;

	min = list;
	while (list)
	{
		if (*(int *)list->content < *(int *)min->content)
			min = list;
		list = list->next;
	}
	return (min);
}

int	stack_is_sorted(t_stack *stack)
{
	return (!stack->b && list_is_sorted(stack->a));
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

void	stack_destroy(t_stack *stack)
{
	ft_lstclear(&stack->a, free);
	ft_lstclear(&stack->b, free);
	free(stack);
}
