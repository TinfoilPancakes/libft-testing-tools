/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:44:00 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 15:53:05 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct	{
	char	find;
	char	*s;
}			t_testcase;

t_testcase	g_tests[] = {
	{'b', "aaaaaabaabaaaa"},
	{0, "aaaaaa"},
	{'a', "aaaaa"},
	{'a', ""},
	{0, ""},
	{'\157', "aaaa\157aaa\157aaa"},
};

int			main(void)
{
	int		i;
	char	*ret;
	char	*lib;

	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		lib = strchr(g_tests[i].s, g_tests[i].find);
		ret = ft_strchr(g_tests[i].s, g_tests[i].find);
		if (lib != ret)
			printf("FAIL strchr %d\n", i);
		lib = strrchr(g_tests[i].s, g_tests[i].find);
		ret = ft_strrchr(g_tests[i].s, g_tests[i].find);
		if (lib != ret)
			printf("FAIL strrchr %d\n", i);
		i++;
	}
	printf("Done\n");
}
