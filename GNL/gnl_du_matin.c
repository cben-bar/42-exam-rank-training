/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_du_matin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:06:39 by cben-bar          #+#    #+#             */
/*   Updated: 2022/06/28 09:12:04 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char	*get_next_line(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd,c , 1) > 0 && *c++ != '\n');
	return c > s ? (c = 0, s) : (free(s), NULL);
}

int	main(void)
{
	size_t	x;
	int		fd;
	char	*str;

	x = 0;
	fd = open("nouveau_testament.txt", O_RDONLY);
	while (x < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		x++;
	}
	return (0);
}
