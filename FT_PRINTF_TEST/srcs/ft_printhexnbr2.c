/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexnbr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:12:42 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 23:01:16 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

static int	ft_printhexnbr2(unsigned int nb, size_t printed, char *base)
{
	if (nb >= 16)
		printed = ft_printhexnbr2((nb / 16), printed + 1, base);
	ft_printc(base[nb % 16]);
	return (printed);
}

int	ft_printhexnbr(unsigned int nb)
{
	char	*lowbase;

	lowbase = "0123456789abcdef";
	return (ft_printhexnbr2(nb, 1, lowbase));
}
