/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:04:56 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 19:27:49 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*g_testcases[][2] = {
	{"", ""},
	{"aaaaaaa", ""},
	{"", "aaaaaaa"},
	{"b", "b"},
	{"b", "a"},
	{"b", "c"},
	{"é", "É"},
	{"é", "e"},
	{"e", "é"},
	{"e", "\254"},
	{"long string", "short"},
	{"short", "long string"},
	{"The rain in Spain", "The rain in sPain"},
};

int		main(void)
{
	int i;
	int result;
	int stdlib;

	i = 0;
	while (i < (int)(sizeof(g_testcases) / sizeof(*g_testcases)))
	{
		stdlib = strlen(g_testcases[i][0]);
		result = ft_strlen(g_testcases[i][0]);
		if (stdlib != result)
			printf("FAIL strlen\n");
		i++;
	}
	printf("Done\n");
	return (0);
}
