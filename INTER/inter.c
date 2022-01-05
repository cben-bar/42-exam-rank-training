/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:28:52 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/05 03:49:54 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		tab[256] = {0};
	char	*s1;
	char	*s2;
	
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s2[i])
		{
			if (tab[(int)s2[i]] == 0)
				tab[(int)s2[i]] = 1;
			i++;
		}
		i = 0;
		while (s1[i])
		{
			if (tab[(int)s1[i]] == 1)
			{
				tab[(int)s1[i]] = 2;
				ft_putchar(s1[i]);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
