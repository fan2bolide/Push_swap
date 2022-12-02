/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:13:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 00:25:13 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_create_from(int *tab, size_t size)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack *));
	stack->a = malloc(sizeof(t_list *));
	stack->b = NULL;
	i = 0;
	while (i < size)
	{
		
	}
}
