/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:13:18 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 15:50:35 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int		main(void)
{
	float	ary1[20];
	int		i;
	int		match;

	i = 0;
	while (i < 10)
	{
		ary1[i] = i + 10;
		i++;
	}
	ary1[10 + 3] = -42;
	ft_memmove(ary1 + 3, ary1 + 0, sizeof(float) * 10);
	i = 0;
	match = 1;
	while (i < 10)
	{
		if (ary1[i + 3] != i + 10)
			match = 0;
		i++;
	}
	if (!match)
	{
		printf("FAIL: copied incorrectly a\n");
		i = 0;
		while (i < 20)
		{
			printf("ary[%07d] = %07.0f\n", i, ary1[i]);
			i++;
		}
	}
	if (ary1[10 + 3] != -42)
		printf("FAIL: wrote past end\n");

	ary1[0] = -42;
	ft_memmove(ary1 + 1, ary1 + 3, sizeof(float) * 10);
	i = 0;
	match = 1;
	while (i < 10)
	{
		if (ary1[i + 1] != i + 10)
			match = 0;
		i++;
	}
	if (!match)
	{
		printf("FAIL: copied incorrectly b\n");
		i = 0;
		while (i < 20)
		{
			printf("ary[%07d] = %07.0f\n", i, ary1[i]);
			i++;
		}
	}
	if (ary1[0] != -42)
		printf("FAIL: wrote past end\n");

	printf("Done\n");
	return (0);
}
