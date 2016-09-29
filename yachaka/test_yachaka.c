/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:08:24 by ihermell          #+#    #+#             */
/*   Updated: 2016/09/23 20:49:19 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void	test_memalloc()
{
	int		i;
	unsigned char	*tmp;

	dprintf(1, "Memalloc 		");
	tmp = (unsigned char*)ft_memalloc(15);
	i = -1;
	while (++i < 15)
	{
		if (tmp[i] != 0) {
			dprintf(1, "\x1b[31mFail\x1b[0m La memoire n'a pas ete initialisee a 0.i\n");
			return;
		}
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_memdel()
{
	void	*tmp = malloc(50);

	dprintf(1, "Memdel			");
	ft_memdel(&tmp);
	if (tmp != NULL) {
		dprintf(1, "\x1b[31mFail\x1b[0m Le pointeur n'a pas ete mis a NULL.");
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strnew()
{
	int		i;
	char	*tmp;

	dprintf(1, "Strnew	 		");
	tmp = ft_strnew(15);
	i = -1;
	while (++i < 15)
	{
		if (tmp[i] != '\0') {
			dprintf(1, "\x1b[31mFail\x1b[0m La chaine n'a pas ete initialisee a \\0.\n");
			return;
		}
	}
	if (tmp[i] != '\0') {
		dprintf(1, "\x1b[31mFail\x1b[0m Le \\0 de fin n'a pas ete ajoute.\n");
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strdel()
{
	char	*tmp = malloc(50);

	dprintf(1, "Strdel			");
	ft_strdel(&tmp);
	if (tmp != NULL) {
		dprintf(1, "\x1b[31mFail\x1b[0m Le pointeur n'a pas ete mis a NULL.");
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strclr()
{
	char	*tmp = (char*)malloc(13);
	int		i = -1;

	dprintf(1, "Strclr			");
	strcpy(tmp, "Motherfucker");
	ft_strclr(tmp);
	while (++i < 13) {
		if (tmp[i] != '\0') {
			dprintf(1, "\x1b[31mFail\x1b[0m Les caracteres de la chaine n'ont pas ete assignes a 0.\n");
			return;
		}
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	char_to_upper(char *c)
{
	*c = toupper(*c);
}

void	test_striter()
{
	char	tmp[] = "MotherFucker";

	dprintf(1, "Striter			");
	ft_striter(tmp, &char_to_upper);
	if (strcmp(tmp, "MOTHERFUCKER") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : MotherFucker\n		f : char_to_toupper(char *c)			*c = toupper(*c);\n\n		Valeur attendue : MOTHERFUCKER\n		Valeur obtenue : %s\n", tmp);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	char_to_index(unsigned int i, char *c)
{
	*c = i % 10 + 48;
}

void	test_striteri()
{
	char	tmp[] = "MotherFucker";

	dprintf(1, "Striteri		");
	ft_striteri(tmp, &char_to_index);
	if (strcmp(tmp, "012345678901") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : MotherFucker\n		f : char_to_index(unsigned int index, char *c)\n			*c = i modulo 10 + 48;\n\n				Valeur attendue : 012345678901\n		Valeur obtenue : %s\n", tmp);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

char	yolo(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	test_strmap()
{
	char	tmp[] = "MotherFucker";
	char	*dst;
	
	dprintf(1, "Strmap			");
	dst = ft_strmap(tmp, &yolo);
	if (strcmp(tmp, "MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m La chaine originale a ete modifiee ; une nouvelle chaine fresh doit etre cree.\n");
		return;
	}
	if (strcmp(dst, "MOTHERFUCKER") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : MotherFucker\n		f : man toupper\n\n		Valeur attendue : MOTHERFUCKER\n		Valeur obtenue : %s\n", dst);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

char	char_to_i(unsigned int i, char c)
{
	(void) c;
	return((int)i % 10 + 48);
}


void	test_strmapi()
{
	char	tmp[] = "MotherFucker";
	char	*dst;
	
	dprintf(1, "Strmapi			");
	dst = ft_strmapi(tmp, &char_to_i);
	if (strcmp(tmp, "MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m La chaine originale a ete modifiee ; une nouvelle chaine fresh doit etre cree.\n");
		return;
	}
	if (strcmp(dst, "012345678901") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : MotherFucker\n		f : char_to_index(unsigned int index, char c)\n				return (i modulo 10 + 48);\n\n		Valeur attendue : 012345678901\n		Valeur obtenue : %s\n", dst);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strequ()
{
	char	str[4][15] = {"", " ", "Hello", "Motherfucker"};
	int	i = -1;
	int	j = -1;
	
	dprintf(1, "Strequ			");
	while (++i < 4) {
		j = -1;
		while (++j < 4) {
			if (strcmp(str[i], str[j]) == 0 && ft_strequ(str[i], str[j]) != 1) {
				dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s1 : '%s'\n		s2 : '%s'\n\n		Valeur attendue : 1\n		Valeur obtenue : %d\n", str[i], str[j],ft_strequ(str[i], str[j]));
				return;
			}
			if (strcmp(str[i], str[j]) != 0 && ft_strequ(str[i], str[j]) != 0) {
				dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s1 : '%s'\n		s2 : '%s'\n\n		Valeur attendue : 0\n		Valeur obtenue : %d\n", str[i], str[j],ft_strequ(str[i], str[j]));
				return;
			}
		}
	}

	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strnequ()
{
	char	str[4][15] = {"", " ", "Hello", "Motherfucker"};
	int	i = -1;
	int	j;
	int k;
	
	dprintf(1, "Strnequ			");
	while (++i < 4) {
		j = -1;
		while (++j < 4) {
			k = -1;
			while (++k < 15) {
				if (strncmp(str[i], str[j], k) == 0 && ft_strnequ(str[i], str[j], k) != 1) {
					dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s1 : '%s'\n		s2 : '%s'\n		k : %d\n\n		Valeur attendue : 1\n		Valeur obtenue : %d\n", str[i], str[j],k,ft_strnequ(str[i], str[j], k));
					return;
				}
				if (strncmp(str[i], str[j], k) != 0 && ft_strnequ(str[i], str[j], k) != 0) {
					dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s1 : '%s'\n		s2 : '%s'\n		k : %d\n\n		Valeur attendue : 0\n		Valeur obtenue : %d\n", str[i], str[j],k,ft_strnequ(str[i], str[j], k));
					return;
				}
			}
		}
	}

	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strsub()
{
	char	tmp[] = "Hello MotherFucker";
	char	*dst;

	dprintf(1, "Strsub			");
	dst = ft_strsub(tmp, 6, 12);
	if (strcmp(tmp, "Hello MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m La chaine originale a ete modifiee ; vous devez retourne une copie fresh.\n");
		return;
	}
	if (strcmp(dst, "MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : Hello MotherFucker\n		start : 6\n		len : 12\n\n		Valeur attendue : MotherFucker\n		Valeur obtenue : %s\n", dst);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}
void	test_strjoin()
{
	char	*tmp = "Hello ";
	char	*tmp2 = "MotherFucker";
	char	*dst;

	dprintf(1, "Strjoin			");
	dst = ft_strjoin(tmp, tmp2);
	if (strcmp(dst, "Hello MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s1 : 'Hello '		s2 : 'MotherFucker'\n\n		Valeur attendue : Hello MotherFucker\n		Valeur obtenue : %s\n", dst);
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strtrim()
{
	char	*tmp = "\n\n\t\t   Hello\t\n MotherFucker \n\n  \t\t";
	char	*tmp2 = "Hello MotherFucker";

	dprintf(1, "Strtrim			");
	char 	*dst = ft_strtrim(tmp);
	char	*dst2 = ft_strtrim(tmp2);
	if (strcmp(dst, "Hello\t\n MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : \n\n\t\t   Hello\t\n MotherFucker \n\n \t\t\n\n		Valeur attendue : Hello\t\n MotherFucker\n		Valeur obtenue : %s\n", dst);
		return;	
	}
	if (strcmp(dst2, "Hello MotherFucker") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : Hello MotherFucker\n\n		Valeur attendue : Hello MotherFucker\n		Valeur obtenue : %s\n", dst2);
		return;	
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_strsplit()
{
	char *tmp = "*salut**les*koupins";
	char *tmp2 = "salut**les*koupins*";
	char **tab;
	char **tab2;

	dprintf(1, "Strsplit		");
	tab = ft_strsplit(tmp, '*');
	tab2 = ft_strsplit(tmp2, '*');
	if (strcmp(tab[0], "salut") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : *salut**les*koupins\n\n		Valeur attendue (1er element du tableau): salut		Valeur obtenue : %s\n", tab[0]);
		return;
	}
	if (strcmp(tab[1], "les") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : *salut**les*koupins\n\n		Valeur attendue (2er element du tableau): les		Valeur obtenue : %s\n", tab[1]);
		return;
	}

	if (strcmp(tab[2], "koupins") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : *salut**les*koupins\n\n		Valeur attendue (3er element du tableau): koupins		Valeur obtenue : %s\n", tab[2]);
		return;
	}

	if (tab[3] != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m Le tableau n'est pas termine par 0.n");
		return;
	}

	if (strcmp(tab2[0], "salut") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : salut**les*koupins*\n\n		Valeur attendue (1er element du tableau): salut		Valeur obtenue : %s\n", tab2[0]);
		return;
	}
	if (strcmp(tab2[1], "les") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : salut**les*koupins*\n\n		Valeur attendue (2er element du tableau): les		Valeur obtenue : %s\n", tab2[1]);
		return;
	}

	if (strcmp(tab2[2], "koupins") != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n		s : salut**les*koupins*\n\n		Valeur attendue (3er element du tableau): koupins		Valeur obtenue : %s\n", tab2[2]);
		return;
	}

	if (tab2[3] != 0) {
		dprintf(1, "\x1b[31mFail\x1b[0m Le tableau n'est pas termine par 0.n");
		return;
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

void	test_itoa()
{
	int		ints[4] = {0, -3, 256, -87459};
	char	str[4][10] = {"0", "-3", "256", "-87459"};
	int i = -1;
	char	*tmp;

	dprintf(1, "Itoa			");
	while (++i < 4) {
		tmp = ft_itoa(ints[i]);
		if (strcmp(tmp, str[i]) != 0) {
			dprintf(1, "\x1b[31mFail\x1b[0m\n	Params:\n	int : %d\n\n	Valeur attendue : %s\n	Valeur obtenue : %s\n", ints[i], str[i], tmp);
			return;
		}
	}
	dprintf(1, "\x1b[32mOK\x1b[0m\n");
}

int		main()
{
	test_memalloc();
	test_memdel();
	test_strnew();
	test_strdel();
	test_strclr();
	test_striter();
	test_striteri();
	test_strmap();
	test_strmapi();
	test_strequ();
	test_strnequ();
	test_strsub();
	test_strjoin();
	test_strtrim();
	test_strsplit();
	test_itoa();
	return (0);
}
