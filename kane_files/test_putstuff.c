/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:20:26 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 16:38:53 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define EXPECTED "Hello 42!!\n-100000\n"

int		main(void)
{
	int		fd;
	char	name[] = "/tmp/putstuff-temp.XXXXXX";
	char	buf[100];
	ssize_t	read_size;

	mktemp(name);
	fd = open(name, O_RDWR | O_CREAT | O_EXCL, 0600);
	if (fd == -1)
	{
		perror("FAIL ed to create temporary file");
		return (1);
	}
	unlink(name);

	ft_putchar_fd('H', fd);
	ft_putstr_fd("ello", fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(42, fd);
	ft_putendl_fd("!!", fd);
	ft_putnbr_fd(-100000, fd);
	ft_putendl_fd("", fd);

	printf("You  : ");
	fflush(0);
	ft_putchar('H');
	ft_putstr("ello");
	ft_putchar(' ');
	ft_putnbr(42);
	ft_putendl("!!");
	ft_putnbr(-100000);
	ft_putendl("");

	printf("Exp  : %s", EXPECTED);
	fflush(0);

	lseek(fd, 0, SEEK_SET);

	ft_bzero(buf, 100);
	read_size = read(fd, buf, 99);
	printf("YouFD: %s", buf);
	if (read_size != sizeof(EXPECTED) - 1)
		printf("FAIL: wrong # of bytes, got %ld\n", read_size);
	if (0 != ft_strcmp(EXPECTED, buf))
		printf("FAIL: wrong content, got: %s\n", buf);
	close(fd);
	printf("Done\n");
}
