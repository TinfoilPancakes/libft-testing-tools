/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:23:48 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 20:14:23 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct	{
	char	*hay;
	char	*ned;
	size_t	n;
}			t_testcase;

t_testcase	g_tests[] = {
	{"Beginning of string", "Begin", 30},
	{"Beginning of string", "Begin", 5},
	{"Beginning of string", "Begin", 6},
	{"End of string\0a", "ing\0b", 14},
	{"End of string_a", "ing_b", 13},
	{"End of string_a", "ing_b", 14},
	{"End of string_a", "ing_b", 15},
	{"Matches twice twice", "twice", 100},
	{"Matches twice twice", "twice", 13},
	{"Matches twice twice", "twice", 12},
	{"Empty search", "", 10},
	{"Empty search", "", 0},
	{"Not found", "pineapple", 100},
	{"Not found", "pineapple", 2},
	{"worl hahahahoha", "haho", 100},
	{"", "", 0},
};

void		test_strstr(void)
{
	int		i;
	char	*result;
	char	*stdlib;

	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		result = ft_strstr(g_tests[i].hay, g_tests[i].ned);
		stdlib = strstr(g_tests[i].hay, g_tests[i].ned);
		if (stdlib && result)
		{
			if (strcmp(stdlib, result))
			{
				printf("strstr('%s', '%s')\n", g_tests[i].hay,
						g_tests[i].ned);
				printf("Lib: %s\nYou: %s\n", stdlib, result);
				printf("FAIL\n");
			}
		}
		else if ((!!stdlib) ^ (!!result))
		{
			printf("strstr('%s', '%s')\n", g_tests[i].hay,
					g_tests[i].ned);
			printf("Lib: %s\nYou: %s\n", stdlib, result);
			printf("FAIL\n");
		}
		i++;
	}
}

void		test_strnstr(void)
{
	int		i;
	char	*result;
	char	*stdlib;

	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		result = ft_strnstr(g_tests[i].hay, g_tests[i].ned, g_tests[i].n);
		stdlib = strnstr(g_tests[i].hay, g_tests[i].ned, g_tests[i].n);
		if (stdlib && result)
		{
			if (strcmp(stdlib, result))
			{
				printf("strnstr('%s', '%s', %ld)\n", g_tests[i].hay,
						g_tests[i].ned, g_tests[i].n);
				printf("Lib: %s\nYou: %s\n", stdlib, result);
				printf("FAIL\n");
			}
		}
		else if ((!!stdlib) ^ (!!result))
		{
			printf("strnstr('%s', '%s', %ld)\n", g_tests[i].hay,
					g_tests[i].ned, g_tests[i].n);
			printf("Lib: %s\nYou: %s\n", stdlib, result);
			printf("FAIL\n");
		}
		i++;
	}
}

int			main(void)
{
	test_strstr();
	test_strnstr();
	printf("Done\n");
	return (0);
}
