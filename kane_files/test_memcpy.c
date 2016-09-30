/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:54 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 16:25:57 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int		main(void)
{
	float src;
	float dst;

	src = 3.14159;
	ft_memcpy(&dst, &src, sizeof(float));
	printf("%f %f\n", src, dst);
	if (src != dst)
		printf("FAIL\n");
	printf("Done\n");
}
