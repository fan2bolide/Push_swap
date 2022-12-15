/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:22:02 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/15 21:40:58 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LIB_H
# define STACK_LIB_H
# include "libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;

t_stack		*stack_create_from(int *tab, size_t size);
void		stack_destroy(t_stack *stack);
void		print_stack(t_stack *stack);
int			stack_is_sorted(t_stack *stack);
int			list_is_sorted(t_list *list);
t_stack		*stack_index(t_stack *stack);
int			stack_push_a(t_stack *stack);
int			stack_push_b(t_stack *stack);
int			stack_swap(t_list **list);
int			stack_rotate(t_list **list);
int			stack_reverse_rotate(t_list **list);
t_list		*stack_get_min(t_list *list);
int			stack_count_under(t_stack *stack, int data);

#endif
