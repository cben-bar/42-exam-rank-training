/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:36:19 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/05 04:45:56 by cben-bar         ###   ########lyon.fr   */
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
	char	*s1;
	char	*s2;
	int		tab[256] = {0};

	i = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i])
		{
			if (tab[s1[i]] == 0)
			{
				ft_putchar(s1[i]);
				tab[s1[i]] = 1;
			}
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (tab[(int)s2[i]] == 0)
			{
				ft_putchar(s2[i]);
				tab[s2[i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
