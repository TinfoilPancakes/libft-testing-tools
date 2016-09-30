/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isfoo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:55:30 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 11:32:44 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int		main(void)
{
	int		i;
	int		c;

	i = -1;
	while (i <= 256)
	{
		c = i;
		if (isalpha(c) != ft_isalpha(c))
			printf("FAIL isalpha(%d)\n", i);
		if (isdigit(c) != ft_isdigit(c))
			printf("FAIL isdigit(%d)\n", i);
		if (isalnum(c) != ft_isalnum(c))
			printf("FAIL isalnum(%d)\n", i);
		if (isascii(c) != ft_isascii(c))
			printf("FAIL isascii(%d)\n", i);
		if (isprint(c) != ft_isprint(c))
			printf("FAIL isprint(%d)\n", i);
		if (toupper(c) != ft_toupper(c))
			printf("FAIL toupper(%d)\n", i);
		if (tolower(c) != ft_tolower(c))
			printf("FAIL tolower(%d)\n", i);
		i++;
	}
	printf("Done\n");
}
