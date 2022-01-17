/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnbr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:49:50 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 23:01:29 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

int	ft_printunsnbr(unsigned int nb, size_t printed)
{
	if (nb < 10)
		printed += ft_printc(nb + '0');
	else
	{
		printed = ft_printunsnbr((nb / 10), printed + 1);
		ft_printc((nb % 10) + '0');
	}
	return (printed);
}
