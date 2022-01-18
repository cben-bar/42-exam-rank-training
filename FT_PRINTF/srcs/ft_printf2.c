/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:47:27 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/18 12:54:04 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf2.h"

int	ft_check_format(va_list args, char c)
{
	if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'd')
		return (ft_printnbr(va_arg(args, int), 1)); 
	else if (c == 'x')
		return (ft_printhexnbr(va_arg(args, unsigned int), 1, "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			printed += write(1, &str[i], 1);
		if (str[i] == '%' && str[i + 1])
		{
			printed += ft_check_format(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
