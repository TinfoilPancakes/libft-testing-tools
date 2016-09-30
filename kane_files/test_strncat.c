/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:22:57 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 16:52:04 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct	s_testcase {
	char		*s;
	int			n;
}				t_testcase;

t_testcase		g_tests[] = {
	{"The quick brown foxXXXX", 19},
	{" jumps over the lazy dog", 100000},
	{"", 1},
	{".\n", 2},
};

int				main(void)
{
	char	buf[100];
	char	stdbuf[100];
	char	*result;
	char	*stdret;
	int		i;

	ft_memset(buf, 0, 100);
	memset(stdbuf, 0, 100);
	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		result = ft_strncat(buf, g_tests[i].s, g_tests[i].n);
		stdret = strncat(stdbuf, g_tests[i].s, g_tests[i].n);
		if ((result - buf) != (stdret - stdbuf))
			printf("FAIL %d %d\n", i, __LINE__);
		if (strcmp(result, stdret))
			printf("FAIL %d %d\n", i, __LINE__);
		if (memcmp(buf, stdbuf, 100))
			printf("FAIL %d %d\n", i, __LINE__);
		i++;
	}
	printf("You: %sLib: %s", buf, stdbuf);
	printf("Done\n");
}
