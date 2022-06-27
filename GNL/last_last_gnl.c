/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_last_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:44:03 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/26 23:08:51 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *gnl(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int main(void)
{
	size_t	x;
	int		fd;
	char *s;

	x = 0;
	fd = open("nouveau_testament.txt", O_RDONLY);
	while (x < 10)
	{
		s = gnl(fd);
		printf("%s", s);
		x++;
	}
	return (0);
}
