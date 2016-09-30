/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:10:39 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 16:12:25 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char *r1;
	char *r2;

	r1 = ft_strjoin("Hello", ", ");
	r2 = ft_strjoin(r1, "World!");
	if (0 != ft_strcmp(r2, "Hello, World!"))
		printf("FAIL\n");
	ft_strdel(&r1);
	ft_strdel(&r2);
	printf("Done\n");
}
