/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:14:16 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 22:14:05 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lib.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_list	*curr_a;
	t_list	*curr_b;
	static int i = 0;

	curr_a = stack->a;
	curr_b = stack->b;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	while (curr_a && curr_b)
	{
		printf("\t %d\t", *(int *)curr_a->content);
		printf("\t%d\n", *(int *)curr_b->content);
		curr_a = curr_a->next;
		curr_b = curr_b->next;
	}
	while (curr_a)
	{
		printf("\t %d\n", *(int *)curr_a->content);
		curr_a = curr_a->next;
	}
	while (curr_b)
	{
		printf("\t\t\t%d\n", *(int *)curr_b->content);
		curr_b = curr_b->next;
	}
	printf("\t___ \t\t___ \n");
	printf("\t a\t\t b\n");
}
