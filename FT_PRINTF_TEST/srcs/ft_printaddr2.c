/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 06:31:48 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 22:59:22 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

static int	ft_printaddr2(unsigned long ptraddr, size_t printed, char *base)
{
	if (ptraddr >= 16)
		printed = ft_printaddr2((ptraddr / 16), printed + 1, base);
	ft_printc(base[ptraddr % 16]);
	return (printed);
}

int	ft_printaddr(void *add, size_t printed)
{
	unsigned long	ptraddr;
	char			*base;

	ptraddr = (unsigned long)add;
	base = "0123456789abcdef";
	printed += write(1, "0x", 2);
	printed += ft_printaddr2(ptraddr, 1, base);
	return (printed);
}
