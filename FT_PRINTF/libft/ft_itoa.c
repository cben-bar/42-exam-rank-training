/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:38:52 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/15 22:47:06 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_malloc(long nb)
{
	size_t	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0 || count == 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

void	ft_add_str(char *str, int index, long nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		ft_add_str(str, index - 1, nb / 10);
	str[index] = base[nb % 10];
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	size;

	nb = (long)n;
	size = ft_size_malloc(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	ft_add_str(str, size - 1, nb);
	str[size] = '\0';
	return (str);
}
