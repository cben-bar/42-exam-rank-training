/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:10:25 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/18 12:53:25 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_check_format(va_list args, char c);
int	ft_printc(char c);
int	ft_printstr(char *str);
int	ft_printaddr(void *add, size_t printed);
int	ft_printnbr(int nb, size_t printed);
int	ft_printunsnbr(unsigned int nb, size_t printed);
int	ft_printhexnbr(unsigned int nb, size_t printed, char *base);

#endif
