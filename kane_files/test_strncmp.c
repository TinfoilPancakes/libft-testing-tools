/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:04:56 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 16:33:10 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>

#define VERBOSE 0

typedef struct	s_testcase{
	char		*s1;
	char		*s2;
	int			len;
}				t_testcase;

t_testcase		g_testcases[] = {
	{"", "", 0},
	{"", "", 8},
	{"", "aaaaa", 8},
	{"aaaaa", "", 8},
	{"aaaaa", "", 0},
	{"", "aaaaa", 0},
	{"by", "bz", 1},
	{"bb", "bb", 1000},
	{"by", "az", 1},
	{"by", "cz", 1},
	{"by", "cz", 1000},
	{"short long string", "short", 10},
	{"short long string", "short", 5},
	{"short", "short long string", 6},
	{"The rain in Spain", "The rain in sPain", 0},
	{"The rain in Spain", "The rain in sPain", 12},
	{"The rain in Spain", "The rain in sPain", 13},
};

int				main(void)
{
	int i;
	int result;
	int stdlib;

	i = 0;
	while (i < (int)(sizeof(g_testcases) / sizeof(t_testcase)))
	{
		stdlib = strncmp(g_testcases[i].s1, g_testcases[i].s2,
				g_testcases[i].len);
		result = ft_strncmp(g_testcases[i].s1, g_testcases[i].s2,
				g_testcases[i].len);
		if (VERBOSE || stdlib != result)
		{
			printf("strncmp('%s', '%s', %d)\n", g_testcases[i].s1,
					g_testcases[i].s2, g_testcases[i].len);
			printf("Lib: %d\nYou: %d\n", stdlib, result);
		}
		if (stdlib != result)
			printf("FAIL\n");
		i++;
	}
	printf("Done\n");
	return (0);
}
