/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:01:07 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 11:36:32 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			main(void)
{
	char	*s;

	s = ft_strtrim("  \tHello, World!\n");
	if (0 != ft_strcmp(s, "Hello, World!"))
	{
		ft_putstr("FAIL ");
		ft_putstr(s);
		ft_putstr("\n");
	}
	free(s);
	s = ft_strtrim("at edge");
	if (0 != ft_strcmp(s, "at edge"))
	{
		ft_putstr("FAIL ");
		ft_putstr(s);
		ft_putstr("\n");
	}
	free(s);

#ifdef HAVE_ALLOCWRAP
	g_malloc_inject = 0;
	s = ft_strtrim("foo");
	if (s)
		ft_putstr("FAIL\n");
#endif

	ft_putstr("Done\n");
}
