/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:13:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 02:13:14 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_create_from(int *tab, size_t size)
{
	t_stack	*stack;
	int		i;
	int		*data;

	stack = malloc(sizeof(t_stack *));
	stack->a = malloc(sizeof(t_list *));
	stack->b = NULL;
	i = 0;
	while (i < size)
	{
		data = malloc(sizeof(int));
		if (!data)
			return (NULL);
		*data = tab[i];
		ft_lstadd_back(&stack->a, ft_lstnew(data));
	}
	return (stack);
}
