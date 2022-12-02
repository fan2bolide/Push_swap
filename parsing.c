/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:34:39 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 06:16:20 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_push_swap(char **argv, int argc)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof (int) * (argc - 1));
	if (!tab)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}
