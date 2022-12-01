/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:04 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/26 22:22:01 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(int nb)
{
	size_t	res;

	res = 0;
	if (nb == INT_MIN)
		return (ft_putstr("-2147483648"), 11);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		res++;
	}
	if (nb >= 10)
		res += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	res++;
	return (res);
}
