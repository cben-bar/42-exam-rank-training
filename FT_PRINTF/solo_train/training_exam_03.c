/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training_exam_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:07:52 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/26 15:07:57 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
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
		printed = ft_printnbr(nb / 10, printed + 1);
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
		return (ft_printnbr(va_arg(args, int), 1));
	if (c == 'x')
		return (ft_printhexnb(va_arg(args, unsigned int), 1, "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t 	i;
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
	char	*s;
	int		retft;
	int		retor;

	s = "Ädel";
	retft = 0;
	retor = 0;

	printf("====TEST s ====\n");
	retft = ft_printf("retf = %s\n", s);
	retor = printf("retf = %s\n", s);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "Ad3l\n");
	retor = printf("retf = %s\n", "Ad3l\n");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "Ad%3[]!@l");
	retor = printf("retf = %s\n", "Ad%3[]!@l");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "4242");
	retor = printf("retf = %s\n", "4242");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "///%//%%/");
	retor = printf("retf = %s\n", "///%//%%/");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "0");
	retor = printf("retf = %s\n", "0");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %s\n", "LUluciLLe");
	retor = printf("retf = %s\n", "LUluciLLe");
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	printf("====TEST d ====\n");
	retft = ft_printf("retf = %d\n", 0);
	retor = printf("retf = %d\n", 0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", -5);
	retor = printf("retf = %d\n", -5);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", 42);
	retor = printf("retf = %d\n", 42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", INT_MIN);
	retor = printf("retf = %d\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", INT_MAX);
	retor = printf("retf = %d\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", -0);
	retor = printf("retf = %d\n", -0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", 214784364);
	retor = printf("retf = %d\n", 214748364);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", -214748348);
	retor = printf("retf = %d\n", -214748348);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", -4);
	retor = printf("retf = %d\n", -4);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	retft = ft_printf("retf = %d\n", -42);
	retor = printf("retf = %d\n", -42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");

	printf("====TEST x ====\n");
	retft = ft_printf("retf = %x\n", -42);
	retor = printf("retf = %x\n", -42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", UINT_MAX);
	retor = printf("retf = %x\n", UINT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", INT_MIN);
	retor = printf("retf = %x\n", INT_MIN);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", INT_MAX);
	retor = printf("retf = %x\n", INT_MAX);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", -42);
	retor = printf("retf = %x\n", -42);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", -4);
	retor = printf("retf = %x\n", -4);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);


	printf("\n");
	
	retft = ft_printf("retf = %x\n", -0);
	retor = printf("retf = %x\n", -0);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);

	printf("\n");
	
	retft = ft_printf("retf = %x\n", 1);
	retor = printf("retf = %x\n", 1);
	printf("retft = %d\n", retft);
	printf("retor = %d\n", retor);
	return (0);
}
