/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:05:26 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 23:13:44 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

int	ft_printnbr(int nb, size_t printed)
{
	if (nb == -2147483648)
	{
		printed += ft_printc('-');
		printed += ft_printc('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		printed += ft_printc('-');
		nb *= -1;
		nb = (unsigned long)nb;
	}
	if (nb < 10)
		ft_printc(nb + '0');
	if (nb >= 10)
	{
		printed = ft_printnbr((nb / 10), printed + 1);
		ft_printc(nb % 10 + '0');
	}
	return (printed);
}
