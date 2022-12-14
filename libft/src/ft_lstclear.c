/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:45:28 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/21 14:47:15 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*delete;

	if (!lst)
		return ;
	delete = *lst;
	while (delete)
	{
		curr = delete->next;
		del(delete->content);
		free(delete);
		delete = curr;
	}
	*lst = NULL;
}
