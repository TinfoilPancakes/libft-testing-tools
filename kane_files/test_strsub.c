/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:20:44 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 16:24:15 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	*s;

	s = ft_strsub("Hello, World!", 7, 5);
	printf("You: %s\nExp: World\n", s);
	if (0 != strcmp(s, "World"))
		printf("FAIL\n");
	ft_strdel(&s);
	s = ft_strsub("Hello, World!", 3, 0);
	printf("You: %s\nExp: \n", s);
	if (0 != strcmp(s, ""))
		printf("FAIL\n");
	ft_strdel(&s);
	s = ft_strsub("Hello, World!", 0, 6);
	printf("You: %s\nExp: Hello,\n", s);
	if (0 != strcmp(s, "Hello,"))
		printf("FAIL\n");
	ft_strdel(&s);
}
