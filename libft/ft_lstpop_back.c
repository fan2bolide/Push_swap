/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:04:01 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 05:25:21 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop_back(t_list** list, void(*del)(void *))
{
	t_list*	curr;
	t_list*	remove;

	remove = *list;
	while (remove && remove->next)
	{
		curr = remove;
		remove = remove->next;
	}
	ft_lstdelone(remove, del);
	curr->next = NULL;
}
