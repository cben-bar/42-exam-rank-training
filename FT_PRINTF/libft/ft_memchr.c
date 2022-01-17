/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:39:04 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/10 22:52:14 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		if (*s1 == (char)c)
			return ((void *)s1);
		i++;
		s1++;
	}
	return (0);
}
