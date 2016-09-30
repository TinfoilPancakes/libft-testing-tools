/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 18:57:16 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 19:13:57 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct	s_testcase
{
	char	*memory;
	int		find;
	size_t	len;
	size_t	off;
}				t_testcase;

t_testcase		g_tests[] =
{
	{"\x00\x01\x02\x42\x40\x43\xFF\nA\x93", 0x41, 10, 8},
	{"\x00\x01\x02\x42\x40\x43\xFF\nA\x93", 0x41, 9, 8},
	{"\x00\x01\x02\x42\x40\x43\xFF\nA\x93", 0x41, 8, -1},
	{"\x00\x01\x02\x42\x40\x43\xFF\nA\x93", 0x41, 7, -1},
	{"A\x01\x02\x42\x40\x43\xFF\nA\x93", 0x41, 10, 0},
	{"AAA", 0x41, 0, -1},
	{"BBB", 0x41, 3, -1},
	{"A\x93Z", 0x93, 3, 1},
};

int		main(void)
{
	int		i;
	void	*ret;
	void	*stdret;

	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		stdret = memchr(g_tests[i].memory, g_tests[i].find, g_tests[i].len);
		ret = ft_memchr(g_tests[i].memory, g_tests[i].find, g_tests[i].len);
		if (ret != stdret)
			printf("FAIL case %d\n", i);
		i++;
	}
	printf("Done\n");
	return (0);
}
