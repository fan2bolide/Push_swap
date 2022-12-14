/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:22:02 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/05 22:46:24 by bajeanno         ###   ########lyon.fr   */
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

#endif
