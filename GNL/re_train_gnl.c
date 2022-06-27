/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_train_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:03:43 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/27 14:07:50 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*gnl(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (c = 0, s) : (free(s), NULL);
}

int main(void)
{
	int		x;
	char	*str;
	int fd;

	x = 0;
	fd = open("nouveau_testament.txt", O_RDONLY);
	while (x < 15)
	{
		str = gnl(fd);
		printf("%s", str);
		x++;
	}
	return (0);
}
