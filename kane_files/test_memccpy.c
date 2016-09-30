/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:13:18 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 20:32:23 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	main2(void)
{
	int		ary1[20];
	int		ary2[20];
	void	*ret;
	int		i;

	i = 0;
	while (i < 10)
	{
		ary1[i + 1] = i + 10;
		i++;
	}
	i = 0;
	while (i < 20)
	{
		ary2[i++] = 0x41414141;
	}
	ary1[5] = 0x42414142;
	ary2[5] = 0x43454543;
	ret = ft_memccpy(ary2 + 1, ary1 + 1, 0x41, sizeof(float) * 10);
	if ((char*)ret != ((char*)(ary2 + 5) + 2))
		printf("FAIL return value\n");
	printf("ary2 stop: %x\n", ary2[5]);
	if (ary2[0] != 0x41414141)
		printf("FAIL: wrote elem 0\n");
	i = 1;
	while (i < 5)
	{
		if (ary2[i] != i - 1 + 10)
			printf("FAIL wrong normal values (%d)\n", i);
		i++;
	}
	if (ary2[5] != 0x43454142)
		printf("FAIL: wrong elem 5\n");
	if (ary2[6] != 0x41414141)
		printf("FAIL: wrote elem 6\n");
	i = 0;
	while (i < 20)
	{
		printf("ary1[%2d] = %8x | %8x = ary2[%2d]\n", i, ary1[i], ary2[i], i);
		i++;
	}
}

void	main3(void)
{
	char	buf3[100];
	char	buf2[100];
	char	buf1[100] = {"Hello\200there"};
	void	*ret;
	void	*ret2;

	ret = memccpy(buf2, buf1, 0, 0);
	printf("%p %p %p", ret, buf2, buf1);
	if (memccpy(buf2, buf1, 0, 0) != ft_memccpy(buf2, buf1, 0, 0))
		printf("FAIL wrong return value\n");
	ft_bzero(buf2, 50);
	ft_bzero(buf3, 50);
	ret = ft_memccpy(buf2, buf1, '\200', 10);
	ret2 = memccpy(buf3, buf1, '\200', 10);
	printf("You: %s\nLib: %s\n", buf2, buf3);
	if (0 != ft_memcmp(buf2, buf3, 10))
		printf("FAIL different buffer contents\n");
	if ((ret - (void*)buf2) != (ret2 - (void*)buf3))
		printf("FAIL wrong return value\n");
}

int		main(void)
{
	float	ary1[20];
	float	ary2[20];
	void	*ret;
	int		i;
	int		match;

	i = 0;
	while (i < 10)
	{
		ary1[i + 1] = i + 10 + 0.001;
		i++;
	}
	ary1[0] = 73.01;
	ary1[11] = 73.01;
	ary2[0] = -42.01;
	ary2[11] = -42.01;
	ret = ft_memccpy(ary2 + 1, ary1 + 1, 0x42, sizeof(float) * 10);
	if (ret != NULL)
		printf("FAIL return value\n");
	i = 0;
	match = 1;
	while (i < 10)
	{
		if (ary2[i + 1] != ary1[i + 1])
		{
			printf("bad value at %d\n", i);
			match = 0;
		}
		i++;
	}
	if (!match)
	{
		printf("FAIL: copied incorrectly\n");
		i = 0;
		while (i < 20)
		{
			printf("ary1[%2d] = %03.3f | %03.3f = ary2[%2d]\n", i, ary1[i], ary2[i], i);
			i++;
		}
	}
	else
		printf("Float copy OK\n");
	main2();
	main3();
	printf("Done\n");
	return (0);
}
