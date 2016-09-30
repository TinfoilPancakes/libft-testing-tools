/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:36:44 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 15:09:53 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdio.h>

int		main(void)
{
	char buf[20];
	char stdbuf[20];

	memset(buf, 'X', 20);
	memset(stdbuf, 'X', 20);
	buf[15] = 0;
	buf[0] = '_';
	stdbuf[15] = 0;
	stdbuf[0] = '_';
	ft_strcpy(buf + 1, "0123456789");
	strcpy(stdbuf + 1, "0123456789");
	if (0 != memcmp(buf, stdbuf, 20))
		printf("FAIL\n");
	printf("Done\n");
	return (0);
}
