/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training_de_la_death_gnl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:14:19 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/27 22:17:33 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int	main(void)
{
	size_t	x;
	char *str;
	int	fd;

	fd = open("nouveau_testament.txt", O_RDONLY);

	x = 0;
	while (x < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		x++;
	}
	return (0);
}
