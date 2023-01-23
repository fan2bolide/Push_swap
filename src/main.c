/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:34:18 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/23 23:11:00 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*tab;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (!push_swap_verif_args_one_argument(argv))
			return (write(2, "Error\n", 6), 1);
		tab = parse_one_argument_push_swap(argv, &argc);
	}
	else
	{
		if (!push_swap_verif_args(argv, argc))
			return (write(2, "Error\n", 6), 1);
		tab = parse_push_swap(argv, argc);
	}
	if (!tab)
		return (write(2, "Memory allocation failed, exiting program\n", 42), 1);
	if (!push_swap_check_doubles(tab, argc - 1))
		return (free(tab), write(2, "Error\n", 6), 1);
	if (!push_swap_start_sorting_program(tab, argc - 1))
		return (1);
	return (0);
}
