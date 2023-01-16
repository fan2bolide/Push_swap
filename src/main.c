/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:34:18 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/16 18:34:36 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*tab;

	if (argc == 2)
	{
		if (!ft_verif_args_one_argument(argv))
			return (write(1, "Error\n", 6), 1);
		tab = parse_one_argument_push_swap(argv, &argc);
	}
	else
	{
		if (!ft_verif_args(argv, argc))
			return (write(1, "Error\n", 6), 1);
		tab = parse_push_swap(argv, argc);
	}
	if (!tab)
		return (write(2, "Memory allocation failed, exiting program\n", 42), 1);
	if (!check_doubles(tab, argc - 1))
		return (free(tab), write(1, "Error\n", 6), 1);
	if (!start_sorting_program(tab, argc - 1))
		return (1);
	return (0);
}
