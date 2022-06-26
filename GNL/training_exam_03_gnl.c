/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training_exam_03_gnl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:52:51 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/26 15:58:59 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*gnl(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int	main(void)
{
	size_t	i;
	int		fd;
	char	*s;

	i = 0;
	fd = open("nouveau_testament.txt", O_RDONLY);
	while (i < 10)
	{
		s = gnl(fd);
		printf("%s", s);
		i++;
	}
	return (0);
}
