/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_du_matin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:13:19 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/28 09:35:49 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_printc(char c)
{
	size_t printed;

	printed = write(1, &c, 1);
	return (printed);
}

int	ft_printstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_printc(s[i]);
		i++;
	}
	return (ft_strlen(s));
}

int	ft_printnb(int nb, size_t printed)
{
	if (nb == -2147483648)
	{
		printed += ft_printc('-');
		printed += ft_printc('2');
		nb = 147483648;
	}
	if ( nb < 0)
	{
		printed += ft_printc('-');
		nb *= -1;
		nb = (unsigned long)nb;
	}
	if (nb < 10)
		ft_printc(nb + '0');
	if (nb >= 10)
	{
		printed = ft_printnb(nb / 10, printed + 1);
		ft_printc((nb % 10) + '0');
	}
	return (printed);
}

int	ft_printhexnb(unsigned int nb, size_t printed, char *base)
{
	if (nb >= 16)
		printed = ft_printhexnb(nb / 16, printed + 1, base);
	ft_printc(base[nb % 16]);
	return (printed);	
}

int	ft_check_format(va_list args, char c)
{
	if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (c == 'd')
		return (ft_printnb(va_arg(args, int), 1));
	if (c == 'x')
		return (ft_printhexnb(va_arg(args, unsigned int), 1, "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			printed += ft_printc(s[i]);
		if (s[i] == '%' && s[i + 1])
		{
			printed += ft_check_format(args, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}

int	main(void)
{
	char	*str = "ADEL";
	int		retft = 0;
	int 	retor = 0;

	printf("==test s==");

	printf("\n");
	retft = ft_printf("retft = %s\n", str);
	retor = printf("retor = %s\n", str);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %s\n", "adel");
	retor = printf("retor = %s\n", "adel");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %s %s\n", str, "adel%ADEL%%adel'!@[]");
	retor = printf("retor = %s %s\n", str, "adel%ADEL%%adel'!@[]");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %s\n", "4242");
	retor = printf("retor = %s\n", "4242");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %s\n", "//%%/%");
	retor = printf("retor = %s\n", "//%%/%");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %s\n", "0");
	retor = printf("retor = %s\n", "0");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	str = 0;

	printf("\n");
	retft = ft_printf("retft = %s\n", str);
	retor = printf("retor = %s\n", str);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	printf("==test d==");

	printf("\n");
	retft = ft_printf("retft = %d\n", 0);
	retor = printf("retor = %d\n", 0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", -5);
	retor = printf("retor = %d\n", -5);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", 42);
	retor = printf("retor = %d\n", 42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", INT_MAX);
	retor = printf("retor = %d\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", INT_MIN);
	retor = printf("retor = %d\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", INT_MAX);
	retor = printf("retor = %d\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %d\n", -0);
	retor = printf("retor = %d\n", -0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	printf("==test x==");

	printf("\n");
	retft = ft_printf("retft = %x\n", 2147483647);
	retor = printf("retor = %x\n", 2147483647);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %x\n", INT_MIN);
	retor = printf("retor = %x\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %x\n", INT_MAX);
	retor = printf("retor = %x\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %x\n", UINT_MAX);
	retor = printf("retor = %x\n", UINT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %x\n", -4);
	retor = printf("retor = %x\n", -4);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	retft = ft_printf("retft = %x\n", -42);
	retor = printf("retor = %x\n", -42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);
	printf("YOUPI\n");
}
