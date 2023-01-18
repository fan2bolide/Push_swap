/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:23:59 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/18 21:57:55 by bajeanno         ###   ########lyon.fr   */
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
int		push_swap_check_doubles(int *tab, size_t size);
int		push_swap_start_sorting_program(int *tab, int size);
int		push_swap_verif_args(char **argv, int argc);
int		push_swap_verif_args_one_argument(char **argv);
int		push_swap_str_is_made_of(char *str, char *set);

#endif
