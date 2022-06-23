/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:47:30 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/23 14:55:57 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*gnl(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int	main(void)
{
	char	*s;
	int		fd;
	int		x;

	fd = open("nouveau_testament.txt", O_RDONLY);
	x = 0;
	while (x < 10)
	{
		s = gnl(fd);
		printf("%s", s);
		x++;
	}
}
