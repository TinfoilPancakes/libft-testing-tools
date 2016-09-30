/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:11:37 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 15:59:44 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	main2(void)
{
	char dest[12];
	char stddest[12];

	ft_memset(dest, '\0', 12);
	memset(stddest, '\0', 12);
	dest[10] = 'X';
	stddest[10] = 'X';
	ft_strncpy(dest, "strncpy..><is not NUL-terminated", 10);
	strncpy(stddest, "strncpy..><is not NUL-terminated", 10);
	printf("\nExp: strncpy..>X\nYou: %s\n", dest);
	printf("Lib: %s\n", stddest);
	if (0 != ft_memcmp(dest, stddest, 12))
		printf("FAIL\n");
	ft_memset(dest, 'X', 12);
	memset(stddest, 'X', 12);
	ft_strncpy(dest, "short", 10);
	strncpy(stddest, "short", 10);
	printf("\nExp: short\nYou: %s\nLib: %s\n", dest, stddest);
	if (0 != ft_memcmp(dest, stddest, 12))
		printf("FAIL\n");
	printf("\nExp: short[9] = %d; short[10] = %d\n", 0, 'X');
	printf("You: short[9] = %d; short[10] = %d\n", dest[9], dest[10]);
	printf("Lib: short[9] = %d; short[10] = %d\n", stddest[9], stddest[10]);
	if ((dest[9] != stddest[9]) || (dest[10] != stddest[10]))
		printf("FAIL\n");
}

int		main(void)
{
	char buf[20];
	char stdbuf[20];

	ft_memset(buf, 'X', 20);
	memset(stdbuf, 'X', 20);
	buf[15] = 0;
	buf[4] = 0;
	buf[0] = '_';
	stdbuf[15] = 0;
	stdbuf[4] = 0;
	stdbuf[0] = '_';
	ft_strncpy(buf + 1, "0123456789", 10);
	strncpy(stdbuf + 1, "0123456789", 10);
	if (0 != ft_memcmp(buf, stdbuf, 20))
		printf("FAIL\n");
	printf("You: %s\n", buf);
	printf("Lib: %s\n", stdbuf);
	ft_strncpy(buf + 1, "0123456789", 11);
	strncpy(stdbuf + 1, "0123456789", 11);
	if (0 != ft_memcmp(buf, stdbuf, 20))
		printf("FAIL\n");
	printf("You: %s\n", buf);
	printf("Lib: %s\n", stdbuf);
	printf("\n");
	main2();
	printf("Done\n");
}
