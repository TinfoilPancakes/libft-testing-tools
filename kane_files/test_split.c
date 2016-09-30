/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:42:43 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 12:31:22 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void		ft_destroy_tab(char **tab)
{
	char **t;

	t = tab;
	while (t && *t)
		free(*t++);
	free(tab);
}

int			main(void)
{
	char	**tab;

	tab = ft_strsplit("*hello*fellow***students", '*');
	if (tab == 0)
		printf("FAIL returned null table\n");
	else
	{
		printf("%p\n", tab[0]);
		if (0 != ft_strcmp(tab[0], "hello"))
			printf("FAIL\n");
		if (0 != ft_strcmp(tab[1], "fellow"))
			printf("FAIL\n");
		if (0 != ft_strcmp(tab[2], "students"))
			printf("FAIL\n");
	}
	ft_destroy_tab(tab);

#ifdef HAVE_ALLOCWRAP
	g_malloc_inject = 7;
	tab = ft_strsplit("a_b_c_d_e_f_g_h_i_j_k_", '_');
	if (tab)
		printf("FAIL\n");
	ft_destroy_tab(tab);
#endif

	printf("Done\n");
}
