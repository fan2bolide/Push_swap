/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:34:39 by bajeanno          #+#    #+#             */
/*   Updated: 2023/01/16 18:49:24 by bajeanno         ###   ########lyon.fr   */
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
	i = 0;
	while (++i < argc)
		tab[i - 1] = ft_atoi(argv[i]);
	return (tab);
}

int	*parse_one_argument_push_swap(char **argv, int *argc)
{
	int	i;
	int	*tab;

	i = 0;
	argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	while (argv[i])
		i++;
	*argc = i + 1;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (ft_split_destroy(argv), NULL);
	i = 0;
	while (argv[i])
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	return (ft_split_destroy(argv), tab);
}
