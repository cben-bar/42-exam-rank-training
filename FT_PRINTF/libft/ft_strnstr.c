/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:44:01 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/11 17:33:30 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search(const char *hsk, const char *ndl, size_t i, size_t len)
{
	size_t	i_n;

	i_n = 0;
	if (ndl[i_n] && i < len)
	{
		while (ndl[i_n] == hsk[i] && i < len)
		{	
			if (ndl[i_n + 1] == '\0')
				return (1);
			i_n++;
			i++;
		}
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (i < len && haystack[i] != 0)
	{
		if (ft_search(haystack, needle, i, len))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
