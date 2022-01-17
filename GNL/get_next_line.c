/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:53:17 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 01:41:29 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NET_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#endif

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[len] = '\0';
	return (joined);
}

char	*ft_strchr(const char *str, int x)
{
	unsigned char	x_char;

	x_char = (unsigned char)x;
	while (*str != x_char)
	{
		if (*str == 0)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy || !src)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strndup(const char *src, int n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy || !src)
		return (NULL);
	while (src[i] && i < (size_t)n)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_switch(char	**s, char *buffer)
{
	char	*tmp;

	if (*s)
	{
		tmp = *s;
		*s = ft_strjoin(tmp, buffer);
		free(tmp);
		return ;
	}
	*s = ft_strdup(buffer);
}

char	*ft_dispatch(char **s)
{
	char	*tmp;
	char	*displayed_line;

	tmp = *s;
	*s = ft_strdup(ft_strchr(tmp, '\n') + 1);
	displayed_line = ft_strndup(tmp, ft_strlen(tmp) - ft_strlen(*s));
	free(tmp);
	return (displayed_line);
}

	char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*s = NULL;
	int			rvr;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	rvr = 1;
	while (rvr > 0)
	{
		rvr = read(fd, buffer, BUFFER_SIZE);
		if ((rvr == -1) || (rvr == 0 && s == NULL))
			return (NULL);
		buffer[rvr] = '\0';
		ft_switch(&s, buffer);
		if (ft_strchr(s, '\n'))
			return (ft_dispatch(&s));
	}
	if (s && !s[0])
		tmp = NULL;
	else
		tmp = ft_strdup(s);
	free(s);
	s = NULL;
	return (tmp);
}

int	main(void)
{
	char	*gnlmoicabb;
	int		fd;
	int		x;

	fd = open("nouveau_testament.txt", O_RDONLY);
	x = 0;
	while (x < 10)
	{
		gnlmoicabb = get_next_line(fd);
		printf("%s", gnlmoicabb);
		free(gnlmoicabb);
		x++;
	}
}
