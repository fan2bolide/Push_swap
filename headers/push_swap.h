/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:23:59 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/15 21:41:01 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "stack_lib.h"

int		*parse_push_swap(char **argv, int argc);
int		*parse_one_argument_push_swap(char **argv, int *argc);
void	push_swap_big(t_stack *stack);
void	push_swap_little(t_stack *stack);
int		push_swap_viewer(int argc, char **argv);

#endif
