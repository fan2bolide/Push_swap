/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:14:16 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/18 22:56:02 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lib.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_list	*curr_a;
	t_list	*curr_b;

	curr_a = stack->a;
	curr_b = stack->b;
	ft_printf("\n");
	while (curr_a && curr_b)
	{
		ft_printf("\t %d\t", *(int *)curr_a->content);
		ft_printf("\t %d\n", *(int *)curr_b->content);
		curr_a = curr_a->next;
		curr_b = curr_b->next;
	}
	while (curr_a)
	{
		ft_printf("\t %d\n", *(int *)curr_a->content);
		curr_a = curr_a->next;
	}
	while (curr_b)
	{
		ft_printf("\t\t\t %d\n", *(int *)curr_b->content);
		curr_b = curr_b->next;
	}
	ft_printf("\t___ \t\t___ \n");
	ft_printf("\t a\t\t b\n");
}
