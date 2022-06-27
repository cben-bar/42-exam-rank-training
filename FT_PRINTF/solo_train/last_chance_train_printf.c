/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chance_train_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:28:26 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/27 22:45:40 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

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
	size_t	printed;

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
	if (nb < 0)
	{
		printed += ft_printc('-');
		nb *= -1;
		nb = (unsigned long)nb;
	}
	if (nb < 10)
		printed += ft_printc(nb + '0');
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
		printed = ft_printhexnb(nb / 10, printed + 1, base);
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

int main(void)
{
	char	*s;
	int		retft;
	int		retor;

	s = "Ad3l![]#@";

	printf("==TEST s===\n");
	retor = printf("retor = %s\n", s);
	retft = printf("retft = %s\n", s);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %s\n", "4242");
	retft = printf("retft = %s\n", "4242");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %s\n", "ouiOu8A1-+");
	retft = printf("retft = %s\n", "ouiOu8A1-+");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %s\n", "0");
	retft = printf("retft = %s\n", "0");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %s\n", "POUIK");
	retft = printf("retft = %s\n", "POUIK");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %s\n", "-- 09");
	retft = printf("retft = %s\n", "-- 09");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	printf("==TEST d===\n");

	retor = printf("retor = %d\n", 0);
	retft = printf("retft = %d\n", 0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", -0);
	retft = printf("retft = %d\n", -0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", INT_MIN);
	retft = printf("retft = %d\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", INT_MAX);
	retft = printf("retft = %d\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", 8);
	retft = printf("retft = %d\n", 8);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", 10);
	retft = printf("retft = %d\n", 10);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", -5);
	retft = printf("retft = %d\n", -5);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %d\n", -54);
	retft = printf("retft = %d\n", -54);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("==TEST x===\n");

	retor = printf("retor = %x\n", INT_MIN);
	retft = printf("retft = %x\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", INT_MAX);
	retft = printf("retft = %x\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", UINT_MAX);
	retft = printf("retft = %x\n", UINT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", 2147483647);
	retft = printf("retft = %x\n", 2147483647);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", 0);
	retft = printf("retft = %x\n", 0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", -0);
	retft = printf("retft = %x\n", -0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", 4242);
	retft = printf("retft = %x\n", 4242);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retor = printf("retor = %x\n", 101);
	retft = printf("retft = %x\n", 101);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("BINGO POUIK\n");
	return (0);
}
