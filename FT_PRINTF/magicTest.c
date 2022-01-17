/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magicTest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 06:20:32 by cben-bar          #+#    #+#             */
/*   Updated: 2022/01/17 17:16:12 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	main()
{
	char *str = "coucou";
	int ret1 = ft_printf("coucou %c %s %p %d %i %u %x %X %%\n", 'G', str, str, INT_MIN, INT_MAX, UINT_MAX, INT_MAX, UINT_MAX);
	int ret2 = printf("coucou %c %s %p %d %i %u %x %X %%\n", 'G', str, str, INT_MIN, INT_MAX, UINT_MAX, INT_MAX, UINT_MAX);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);
	
	printf("\ntest str null\n");
	str = 0;
	ret1 = ft_printf("coucou %c %s %d %i %u %x %X %%\n", 'G', str, 42, 0, 0, 0, 0);
	ret2 =	  printf("coucou %c %s %d %i %u %x %X %%\n", 'G', str, 42, 0, 0, 0, 0);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);
	
	printf("\ntest str 16-17- -1\n");
	ret1 = ft_printf("coucou %p\n", (char *)-1);
	ret2 = printf("coucou %p\n", (char *)-1);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);

	printf("\nsimple str\n");
	ret1 = ft_printf("coucou %d\n", 42111);
	ret2 = printf("coucou %d\n", 42111);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);

	printf("\nu x X %% tests\n");
	printf("ft_printf\n");
	ret1 = ft_printf("%u %x %X %%\n",INT_MAX, UINT_MAX, INT_MAX, UINT_MAX);
	printf("printf\n");
	ret2 = printf("%u %x %X %%\n",INT_MAX, UINT_MAX, INT_MAX, UINT_MAX);
	printf("ft_printf ret1 = %d\n", ret1);
	printf("   printf ret2 = %d\n", ret2);

	printf("\nu test\n");
	printf("ft_printf\n");
	ret1 = ft_printf("%u\n",INT_MIN);
	printf("printf\n");
	ret2 = printf("%u\n", INT_MIN);
	printf("ft_printf ret1 = %d\n", ret1);
	printf("   printf ret2 = %d\n", ret2);

	printf("\n\n x test\n");
	printf("ft_printf\n");
	ret1 = ft_printf("%x\n", INT_MAX);
	printf("printf\n");
	ret2 = printf("%x\n", INT_MAX);
	printf("ft_printf ret1 = %d\n", ret1);
	printf("   printf ret2 = %d\n", ret2);

	printf("\n\nX test\n");
	printf("ft_printf\n");
	ret1 = ft_printf("%X\n",UINT_MAX);
	printf("printf\n");
	ret2 = printf("%X\n", UINT_MAX);
	printf("ft_printf ret1 = %d\n", ret1);
	printf("   printf ret2 = %d\n", ret2);
}
