/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:23:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/03 03:52:22 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "stack_lib.h"

int	*parse_push_swap(char **argv, int argc);
int stack_push_a(t_stack *stack);
int stack_push_b(t_stack *stack);
int	stack_swap(t_list **list);
int	stack_rotate(t_list **list);
int stack_reverse_rotate(t_list **list);

#endif
