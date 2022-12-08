/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:34:39 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/08 04:54:03 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_splits(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		i++;
	}
	return (i);
}
#include <stdio.h>
int	*parse_push_swap(char **argv, int *argc)
{
	int	*tab;
	int	i;
	int free_tab;

	free_tab = 0;
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_tab = 1;
		*argc = count_splits(argv) + 1;
	}
	tab = malloc(sizeof (int) * (*argc - 1));
	if (!tab)
		return (NULL);
	i = 0;
	if (free_tab)
		i--;
	printf("%d\n\n", *argc);
	while (++i < *argc)
		tab[i - (!free_tab)] = ft_atoi(argv[i]);
	if (free_tab)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	return (tab);
}
