/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chance_train_gnl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:47:04 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/27 22:51:20 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

int	main(void)
{
	size_t	x;
	char	*str;
	int		fd;

	x  = 0;
	fd = open("nouveau_testament.txt", O_RDONLY);
	while (x < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		x++;
	}
	return (0);
}
