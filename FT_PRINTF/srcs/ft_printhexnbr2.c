/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexnbr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:12:42 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/18 12:56:25 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

int	ft_printhexnbr(unsigned int nb, size_t printed, char *base)
{
	if (nb >= 16)
		printed = ft_printhexnbr((nb / 16), printed + 1, base);
	ft_printc(base[nb % 16]);
	return (printed);
}
