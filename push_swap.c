/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:14:49 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/04 07:47:46 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *stack, int logfile_fd)
{
	char	*log_message;
	t_list	*curr;
	t_list	*min;

	//verify is the stack is sorted, if it is no need to do anything.
	while (stack->a && !list_is_sorted(stack->a))
	{
		curr = stack->a;
		if (*(int *)curr->content > *(int *)curr->next->content)
		{
			stack_swap(&stack->a);
			log_message = "sa\n";
			write(logfile_fd, log_message, ft_strlen(log_message));
		}
		min = stack_get_min(stack->a);
		while (stack->a && stack->a != min)
		{
			stack_rotate(&stack->a);
			log_message = "ra\n";
			write(logfile_fd, log_message, ft_strlen(log_message));
		}
		stack_push_b(stack);
		log_message = "pb\n";
		write(logfile_fd, log_message, ft_strlen(log_message));
	}
	while (stack->b)
	{
		if (*(int *)ft_lstlast(stack->b)->content > *(int *)stack->b->content)
		{
			stack_reverse_rotate(&stack->b);
			log_message = "rrb\n";
			write(logfile_fd, log_message, ft_strlen(log_message));
		}
		stack_push_a(stack);
		log_message = "pa\n";
		write(logfile_fd, log_message, ft_strlen(log_message));
	}
}
