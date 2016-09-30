/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:14:26 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 11:43:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef	struct
{
	int a;
	int b;
	int c;
}				t_data;

void			deldata(void *ptr, size_t size)
{
	if (size != sizeof(t_data))
		abort();
	free(ptr);
}

int				cmpdata_const(void *ptr, int a, int b, int c)
{
	t_data	*d;

	d = (t_data*)ptr;
	if (d->a != a)
		return ((d->a < a) ? -1 : 1);
	if (d->b != b)
		return ((d->b < b) ? -1 : 1);
	if (d->c != c)
		return ((d->c < c) ? -1 : 1);
	return (0);
}

void			main1(void)
{
	t_data	d;
	t_list	*head;
	t_list	*tmphead;

	d = (t_data){1, 2, 3};
	head = ft_lstnew(&d, sizeof(d));
	d = (t_data){4, 3, 6};
	ft_lstadd(&head, ft_lstnew(&d, sizeof(d)));
	d = (t_data){6, 7, 8};
	ft_lstadd(&head, ft_lstnew(&d, sizeof(d)));
	tmphead = head;
	head = head->next;
	ft_lstdelone(&tmphead, deldata);
	if (tmphead)
		printf("FAIL lstdelone needs to set ptr to null\n");
	ft_lstdel(&head, deldata);
	if (head)
		printf("FAIL lstdel needs to set ptr to null\n");
}

void			main2(void)
{
#ifdef HAVE_KANE
	t_data	d;
	t_list	*head;

	d = (t_data){4, 3, 6};
	head = ft_lstnew(&d, sizeof(d));
	d = (t_data){6, 7, 8};
	ft_lstadd(&head, ft_lstnew(&d, sizeof(d)));
	ft_lstpop(&head, deldata);
	ft_lstpop(&head, deldata);
	if (head)
		printf("FAIL lstpop needs to set ptr to null, is %p\n", head);
#endif
}

void			validate_malloc(char *stage)
{
#ifdef HAVE_ALLOCWRAP
	if (g_alloc_count != 0)
		printf("FAIL - allocations left over from %s\n", stage);
#else
	(void)(stage);
#endif
}

int				main(void)
{
	main1();
	validate_malloc("lstdelone / lstdel");
	main2();
	validate_malloc("lstpop");
	return (0);
}

