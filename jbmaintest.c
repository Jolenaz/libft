/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:01:38 by jbelless          #+#    #+#             */
/*   Updated: 2015/12/03 11:18:12 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test_striter(char *str)
{
	ft_putchar(*str);
}

void	test_striteri(unsigned int i, char *str)
{
	if (i % 2)
		ft_putchar(*str);
}

char	test_strmap(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	test_strmapi(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z' && i % 2)
		return (c - 32);
	return (c);
}
int	main(void)
{
	//Test putchar, putstr, ptendl
	ft_putchar ('T');
	ft_putstr("est ft_putchar, ft_putstr");
	ft_putendl(", ft_putendl OK\n");

	///test putnbr
	ft_putstr("test ft_putnbr :\n");
	ft_putnbr(-1236);
	ft_putstr(" = -1236 \n");
	ft_putnbr(0);
	ft_putstr(" = 0 \n");
	ft_putnbr(10);
	ft_putstr(" = 10 \n");
	ft_putnbr(2147483648);
	ft_putstr(" = 2147483648 \n\n");

	//Test putchar_fd, putstr_fd, putendl_fd
	ft_putchar_fd('T', 1);
	ft_putstr_fd("est ft_putchar_fd, ft_putstr_fd", 1);
	ft_putendl_fd(", ft_putendl_fd OK\n", 1);

	///test putnbr_fd
	ft_putstr_fd("test ft_putnbr_fd :\n", 1);
	ft_putnbr_fd(-1236, 1);
	ft_putstr_fd(" = -1236 \n", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd(" = 0 \n", 1);
	ft_putnbr_fd(10, 1);
	ft_putstr_fd(" = 10 \n", 1);
	ft_putnbr_fd(1000, 1);
	ft_putstr_fd(" = 1000 \n\n", 1);

	//test itoa
	ft_putstr("test ft_itoa :\n");
	if (strcmp(ft_itoa(-1236), "-1236") == 0)
		ft_putstr("test1 ok\n");
	else 
		ft_putstr("test1 not ok\n");
	if (strcmp(ft_itoa(0), "0") == 0)
		ft_putstr("test2 ok\n");
	else 
		ft_putstr("test2 not ok\n");
	if (strcmp(ft_itoa(10), "10") == 0)
		ft_putstr("test3 ok\n");
	else 
		ft_putstr("test3 not ok\n");
	if (strcmp(ft_itoa(-1000), "-1000") == 0)
		ft_putstr("test4 ok\n");
	else 
		ft_putstr("test4 not ok\n");
	if (strcmp(ft_itoa(1234560000), "1234560000") == 0)
		ft_putstr("test5 ok\n");
	else 
		ft_putstr("test5 not ok\n");
	if (strcmp(ft_itoa(-2147483647), "-2147483647") == 0)
		ft_putstr("test6 ok\n");
	else
		ft_putstr("\ntest6 not ok\n");

	//test memset
	ft_putstr("\ntest ft_memeset :\n");
	char str1[7] = {'l','a','l','a','l','a',0};
	ft_putstr(ft_memset(str1, 49, 3));
	ft_putstr(" = 111ala\n\n");

	//test bzero
	ft_putstr("test ft_bzero :\n");
	int i = 0;
	char str2[7] = {'l','a','l','a','l','a',0};
	ft_bzero(str2, 3);
	while (i < 7)
	{
		ft_putchar(str2[i]);
		i++;
	}
	ft_putstr(" = ^@^@^@ala^@\n\n");

	//test memcpy
	ft_putstr("test ft_memcpy :\n");
	char str3[7] = {'l','a','l','a','l','a',0};
	char str4[7] = {'m','i','m','i','m','i',0};
	ft_memcpy(str3, str4, 3);
	ft_putstr(str3);
	ft_putstr(" = mimala\n\n");




	//test memalloc byJonas
	ft_putstr("\ntest ft_memalloc :\n");
	void	*tab;
	tab = ft_memalloc(5);
	i = 0;
	while (i < 5)
	{
		ft_putchar(((char*)tab)[i]);
		i++;
	}
	ft_putstr(" = ^@^@^@^@^@\n");

	//test memmove
	ft_putstr("\ntest ft_memmove :\n");
	char str10[7] = {'a','b','c','d','e','f',0};
	char *str11 = str10 + 4;
	ft_memmove(str11, str10, 7);
	ft_putstr(str11);
	ft_putstr(" = abcdef\n\n");

	//test memdel
	void *str7;
	str7 = malloc(10);
	ft_memdel(&str7);
	printf("\ntest ft_memdel :\n %p = %p\n", str7, NULL);	

	//test strnew
	ft_putstr("\ntest ft_strnew :\n");
	char	*str8;
	str8 = ft_strnew(5);
	i = 0;
	while (i < 5)
	{
		ft_putchar(str8[i]);
		i++;
	}
	ft_putstr(" = ^@^@^@^@^@\n");

	//test strdel
	ft_strdel(&str8);
	printf("\ntest ft_strdel :\n %p = %p\n", str8, NULL);	

	//test strclr
	ft_putstr("\ntest ft_strclr :\n");
	char	str9[] = "12345";
	ft_strclr(str9);
	i = 0;
	while (i < 5)
	{
		ft_putchar(str9[i]);
		i++;
	}
	ft_putstr(" = ^@^@^@^@^@\n");

	//test memchr
	char *str12 = "abcdefghi";
	printf("\ntest ft_memchr : \n%p = %p\n %p = %p\n %p = %p\n", ft_memchr(str12, 100, 6),
			str12 + 3, ft_memchr(str12, 100, 1), NULL, ft_memchr(str12, 48, 15), NULL);



	//test strlen
	ft_putstr("\ntest ft_strlen :\ncette phrase a ");
	ft_putnbr(ft_strlen("cette phrase a 23 chars"));
	ft_putstr(" chars\n");

	//test strdup

	//test isalpha isdigit isalnum
	if (ft_isalpha('a') && ft_isalpha('z') && ft_isalpha('A') && ft_isalpha('Z') 
			&& !ft_isalpha('5') && !ft_isalpha('#') && !ft_isalpha(' '))
		ft_putendl("\nft_isalpha OK");
	else
		ft_putendl("\nft_isalpha NOT OK");
	if (ft_isalnum('a') && ft_isalpha('z') && ft_isalnum('A') && ft_isalnum('Z') 
			&& ft_isalnum('0') && ft_isalnum('9') 
			&& !ft_isalnum('#') && !ft_isalnum(' '))
		ft_putendl("\nft_isalnum OK");
	else
		ft_putendl("\nft_isalnum NOT OK");
	if (!ft_isdigit('a') && !ft_isdigit('z') && !ft_isdigit('A') 
			&& !ft_isdigit('Z') && ft_isdigit('0') && ft_isdigit('9') 
			&& !ft_isdigit('#') && !ft_isdigit(' '))
		ft_putendl("\nft_isdigit OK");
	else
		ft_putendl("\nft_isdigit NOT OK");

	//test toupper
	char str15[] = "ft_toupper OK: si phrase 1* en  majuscule";
	size_t j = 0;
	while (j < ft_strlen(str15))
	{
		str15[j] = ft_toupper(str15[j]);
		j++;
	}
	ft_putendl(str15);

	//test tolower
	char str16[] = "ft_TOLOWER OK: si PHRASE 1* en minuscule";
	j = 0;
	while (j < ft_strlen(str16))
	{
		str16[j] = ft_tolower(str16[j]);
		j++;
	}
	ft_putendl(str16);

	//test strdup
	char *str17 = "\nft_strdup OK si cette phrase s'affiche.";
	char *str18;
	str18 = ft_strdup(str17);
	ft_putendl(str18);

	//test strcpy
	char *str19 = "\nft_strcpy OK si cette phrase s'affiche.";
	char str20[] = "ft_strcpy NOT OK!!!!";
	ft_strcpy(str20, str19);
	ft_putendl(str20);

	//test strncpy
	ft_putendl("\ntest ft_strncpy:");
	char *str21 = "abcdef";
	char str22[] = "0123456789";
	char str23[] = "0123456789";
	char str24[] = "0123";
	ft_strncpy(str22, str21, 3);
	ft_strncpy(str23, str21, 9);
	ft_strncpy(str24, str21, 5);
	ft_putstr(str22);
	ft_putstr(" = abc3456789\n");
	i = 0;
	while (i < 11)
	{
		ft_putchar(str23[i]);
		i++;
	}
	ft_putendl(" = abcdef^@^@^@9^@");
	i = 0;
	while (i < 6)
	{
		ft_putchar(str24[i]);
		i++;
	}
	ft_putendl(" = abcde?");

	//test strcat
	ft_putendl("\ntest ft_strcat:");
	char str25[6] = "abc";
	char str26[] = "def";
	ft_strcat(str25, str26);
	ft_putstr(str25);
	ft_putendl(" = abcdef");

	//test strncat
	ft_putendl("\ntest ft_strncat:");
	char str27[10] = "abc";
	char str28[] = "def";
	ft_strncat(str27, str28, 2);
	ft_putstr(str27);
	ft_putendl(" = abcde");

	//test strlcat
	ft_putstr("\n_________________________________\n");
	ft_putendl("\ntest ft_strlcat:");
	char str29[15] = "abcde";
	char str30[] = "fgh";
	ft_putnbr(sizeof(str29));
	ft_putchar('\n');
	ft_putnbr(ft_strlcat(str29, str30, 11));
	ft_putstr(str29);
	ft_putstr("\n_________________________________\n");

	//test strchr
	if (ft_strchr("abcad",'a') == strchr("abcad",'a') 
			&& ft_strchr("abcad",0) == strchr("abcad",0) 
			&& ft_strchr("abcad",'k') == strchr("abcad",'k'))
		ft_putstr("\n ft_strchr OK\n");
	else
		ft_putstr("\n ft_strchri NOT OK\n");

	//test strrchr
	if (ft_strrchr("abcad",'a') == strrchr("abcad",'a') 
			&& ft_strrchr("abcad",0) == strrchr("abcad",0) 
			&& ft_strrchr("abcad",'k') == strrchr("abcad",'k'))
		ft_putstr("\n ft_strrchr OK\n");
	else
		ft_putstr("\n ft_strrchri NOT OK\n");

	//test strstr
	ft_putstr("\ntest ft_strstr\n");
	char *str31 = "phrase test";
	char *str32 = "phra";
	char *str33 = "zase";
	char *str34 = "aser";
	char *str35 = "est";
	char *str36 = "opha";
	char *str37 = "est0";
	char *str38 = "";

	if (ft_strstr(str31, str32) == strstr(str31, str32))
		ft_putstr("32 ok\n");
	else 
		ft_putstr("32 not ok\n");
	if (ft_strstr(str31, str33) == strstr(str31, str33))
		ft_putstr("33 ok\n");
	else 
		ft_putstr("33 not ok\n");
	if (ft_strstr(str31, str34) == strstr(str31, str34))
		ft_putstr("34 ok\n");
	else 
		ft_putstr("34 not ok\n");
	if (ft_strstr(str31, str35) == strstr(str31, str35))
		ft_putstr("35 ok\n");
	else 
		ft_putstr("35 not ok\n");
	if (ft_strstr(str31, str36) == strstr(str31, str36))
		ft_putstr("36 ok\n");
	else 
		ft_putstr("36 not ok\n");
	if (ft_strstr(str31, str37) == strstr(str31, str37))
		ft_putstr("37 ok\n");
	else 
		ft_putstr("37 not ok\n"); 
	if (ft_strstr(str31, str38) == strstr(str31, str38))
		ft_putstr("38 ok\n");
	else 
		ft_putstr("38 not ok\n"); 

	//test memccpy
	ft_putstr("\ntest ft_memccpy :\n");
	char str39[] = "abcdef";
	char str40[200];
	void *p1, *p2;
	p1 = ft_memccpy(str40, str39, 'b', 4);
	p2 = memccpy(str40, str39, 'b', 4);
	if (p1 == p2)
		ft_putstr("test1 ok\n");
	else 
		ft_putstr("test1 not OK\n");
	char str41[] = "abcdef";
	char str42[200];
	void *p3, *p4;
	p3 = ft_memccpy(str42, str41, 'v', 4);
	p4 = memccpy(str42, str41, 'v', 4);
	if (p3 == p4)
		ft_putstr("test2 ok\n");
	else 
		ft_putstr("test2 not OK\n");


	//test memcmp
	char *str13 = "ab7de";
	char *str14 = "abcee";
	printf("\ntest ft_memcmp : \n %d = %d\n %d = %d \n", ft_memcmp(str13, str14, 2), memcmp(str13, str14, 2), ft_memcmp(str13, str13, 6), memcmp(str13, str13, 6) );

	//test strnstr
	ft_putstr("\ntest ft_strnstr\n");
	char *str43 = "phrase test";
	char *str44 = "phra";
	char *str45 = "zase";
	char *str46 = "aser";
	char *str47 = "est";
	char *str48 = "opha";
	char *str49 = "est0";
	char *str50 = "";

	if (ft_strnstr(str43, str44, 15) == strnstr(str43, str44, 15))
		ft_putstr("44 ok\n");
	else 
		ft_putstr("44 not ok\n");
	if (ft_strnstr(str43, str45, 15) == strnstr(str43, str45, 15))
		ft_putstr("45 ok\n");
	else 
		ft_putstr("45 not ok\n");
	if (ft_strnstr(str43, str46, 15) == strnstr(str43, str46, 15))
		ft_putstr("46 ok\n");
	else 
		ft_putstr("46 not ok\n");
	if (ft_strnstr(str43, str47, 3) == strnstr(str43, str47, 3))
		ft_putstr("47 ok\n");
	else 
		ft_putstr("47 not ok\n");
	if (ft_strnstr(str43, str48, 3) == strnstr(str43, str48, 3))
		ft_putstr("48 ok\n");
	else 
		ft_putstr("48 not ok\n");
	if (ft_strnstr(str43, str49, 15) == strnstr(str43, str49, 15))
		ft_putstr("49 ok\n");
	else 
		ft_putstr("49 not ok\n"); 
	if (ft_strnstr(str43, str50, 15)  == strnstr(str43, str50, 15))
		ft_putstr("50 ok\n");
	else 
		ft_putstr("50 not ok\n"); 


	//test strcmp
	ft_putstr("\n test ft_strcmp :\n");
	char	str51[] = "abcdef";
	char	str52[] = "abcdef";
	char	str53[] = "abc";
	char	str54[] = "abce";

	if (ft_strcmp (str51, str52) == strcmp(str51, str52))
		ft_putstr("test1 ok\n");
	else
		ft_putstr("test1 not ok\n");
	if (ft_strcmp (str51, str53) == strcmp(str51, str53))
		ft_putstr("test2 ok\n");
	else
		ft_putstr("test2 not ok\n");
	if (ft_strcmp (str51, str54) == strcmp(str51, str54))
		ft_putstr("test3 ok\n");
	else
		ft_putstr("test3 not ok\n");


	//test strncmp
	ft_putstr("\n test ft_strncmp :\n");
	char	str55[] = "abcdef";
	char	str56[] = "abcdef";
	char	str57[] = "abc";
	char	str58[] = "abce";

	if (ft_strncmp (str55, str56, 4) == strncmp(str55, str56, 4))
		ft_putstr("test1 ok\n");
	else
		ft_putstr("test1 not ok\n");
	if (ft_strncmp (str55, str57, 4) == strncmp(str55, str57, 4))
		ft_putstr("test2 ok\n");
	else
		ft_putstr("test2 not ok\n");
	if (ft_strncmp (str55, str58, 4) == strncmp(str55, str58, 4))
		ft_putstr("test3 ok\n");
	else
		ft_putstr("test3 not ok\n");

	//test atoi
	ft_putstr("\ntest atoi ;\n");
	ft_putnbr(ft_atoi("1")); ft_putstr(" = "); ft_putnbr(atoi("1")); ft_putstr("\n");
	ft_putnbr(ft_atoi("-1")); ft_putstr(" = "); ft_putnbr(atoi("-1")); ft_putstr("\n");
	ft_putnbr(ft_atoi(" -1")); ft_putstr(" = "); ft_putnbr(atoi(" -1")); ft_putstr("\n");
	ft_putnbr(ft_atoi("	-1")); ft_putstr(" = "); ft_putnbr(atoi("	-1")); ft_putstr("\n");
	ft_putnbr(ft_atoi("-0")); ft_putstr(" = "); ft_putnbr(atoi("-0")); ft_putstr("\n");
	ft_putnbr(ft_atoi("-10")); ft_putstr(" = "); ft_putnbr(atoi("-10")); ft_putstr("\n");
	ft_putnbr(ft_atoi("10")); ft_putstr(" = "); ft_putnbr(atoi("10")); ft_putstr("\n");
	ft_putnbr(ft_atoi("153")); ft_putstr(" = "); ft_putnbr(atoi("153")); ft_putstr("\n");
	ft_putnbr(ft_atoi("-153")); ft_putstr(" = "); ft_putnbr(atoi("-153")); ft_putstr("\n");
	ft_putnbr(ft_atoi("- 153")); ft_putstr(" = "); ft_putnbr(atoi("- 153")); ft_putstr("\n");
	ft_putnbr(ft_atoi("a15")); ft_putstr(" = "); ft_putnbr(atoi("a15")); ft_putstr("\n");
	ft_putnbr(ft_atoi("15a")); ft_putstr(" = "); ft_putnbr(atoi("15a")); ft_putstr("\n");
	ft_putnbr(ft_atoi("\n15")); ft_putstr(" = "); ft_putnbr(atoi("\n15")); ft_putstr("\n");
	ft_putnbr(ft_atoi("+15")); ft_putstr(" = "); ft_putnbr(atoi("+15")); ft_putstr("\n");
	ft_putnbr(ft_atoi("-+42")); ft_putstr(" = "); ft_putnbr(atoi("-+42")); ft_putstr("\n");
	ft_putnbr(ft_atoi("+-42")); ft_putstr(" = "); ft_putnbr(atoi("+-42")); ft_putstr("\n");
	ft_putnbr(ft_atoi("  \t\n  \r\r\v\f-889")); ft_putstr(" = "); ft_putnbr(atoi("  \t\n  \r\r\v\f-889")); ft_putstr("\n");

	// test ft_striter
	ft_putstr("\ntest ft_striter :\n ft_striter not OK");
	char str59[] = " a moins que cette phrase s'affiche\n";
	ft_striter(str59, &test_striter);

	// test ft_striteri
	ft_putstr("\ntest ft_striteri :\n ft_striteri not OK");
	char str60[] = "1 1a1 1m1o1i1n1s1 1q1u1e1 1c1e1t1t1e1 1p1h1r1a1s1e1 1s1'1a1f1f1i1c1h1e1\n";
	ft_striteri(str60, &test_striteri);

	// test ft_strmap
	ft_putstr("\ntest ft_strmap :\n");
	char str61[] = "ft_strmap ok si cette prhase en majuscule\n";
	ft_putstr(ft_strmap(str61, &test_strmap));

	// test ft_strmapi
	ft_putstr("\ntest ft_strmapi :\n");
	char str62[] = "ft_strmapi ok si cette prhase 1/2 en majuscule\n";
	ft_putstr(ft_strmapi(str62, &test_strmapi));

	//test ft_strequ
	ft_putstr("\ntest strequ :\n");
	if (ft_strequ("",""))
		ft_putstr("test1 OK\n");
	else
		ft_putstr("test1 not OK\n");
	if (ft_strequ("abc","abc"))
		ft_putstr("test2 OK\n");
	else
		ft_putstr("test2 not OK\n");
	if (!ft_strequ("A,l","A b"))
		ft_putstr("test3 OK\n");
	else
		ft_putstr("test3 not OK\n");
	if (!ft_strequ("aBc","abc"))
		ft_putstr("test4 OK\n");
	else
		ft_putstr("test4 not OK\n");
	if (!ft_strequ(" de","de"))
		ft_putstr("test5 OK\n");
	else
		ft_putstr("test5 not OK\n");

	//test ft_strnequ
	ft_putstr("\ntest strnequ :\n");
	if (ft_strnequ("","",10))
		ft_putstr("test1 OK\n");
	else
		ft_putstr("test1 not OK\n");
	if (ft_strnequ("abc","abc",10))
		ft_putstr("test2 OK\n");
	else
		ft_putstr("test2 not OK\n");
	if (ft_strnequ("A,l","A b", 1))
		ft_putstr("test3 OK\n");
	else
		ft_putstr("test3 not OK\n");
	if (!ft_strnequ("aBc","abc",2))
		ft_putstr("test4 OK\n");
	else
		ft_putstr("test4 not OK\n");
	if (!ft_strnequ(" de","de",3))
		ft_putstr("test5 OK\n");
	else
		ft_putstr("test5 not OK\n");
	if (ft_strnequ("ABCDE","ABCD256+",4))
		ft_putstr("test6 OK\n");
	else
		ft_putstr("test6 not OK\n");

	//test ft_strsub
	ft_putstr("\ntest ft_strsub :\n");
	ft_putstr(ft_strsub("test1 OK\n", 0, 9));
	ft_putstr(ft_strsub("XXXtest2 OK\n", 3, 9));
	ft_putstr(ft_strsub("test3 OK\nXXX", 0, 9));
	ft_putstr(ft_strsub("XXXtest4 OK\nXXX", 3, 9));

	//test ft_strjoin
	ft_putstr("\n test ft_strjoin :\n");
	ft_putstr(ft_strjoin("tes1", " ok\n"));

	//test ft_strtrim
	ft_putstr("\n test ft_strtrim :\n");
	ft_putstr("___________________\n");
	ft_putstr(ft_strtrim("  \n\ttes1 ok\n  \n\t"));
	ft_putstr("\n___________________\n");
	ft_putstr(ft_strtrim("  \n\t\n  \n\t"));
	ft_putstr("\n___________________\n");

	//test ft_strsplit
	ft_putstr("\ntest ft_strsplit :\n");
	char **tab_str;
	tab_str = ft_strsplit(" phrase   de  test", ' ');
	ft_putstr(tab_str[0]);
	ft_putstr("\n");
	ft_putstr(tab_str[1]);
	ft_putstr("\n");
	ft_putstr(tab_str[2]);
	ft_putstr("\n");
	if (tab_str[3] == NULL)
		ft_putstr("NULL");
	ft_putstr("\n");

	//test ft_lstaddback
	ft_putstr("\n test lstaddback ;\n");
	int v = 1;
	int w = 2;
	int x = 3;
	t_list *tmp;

	t_list	*lst1 = ft_lstnew(&v, sizeof(int));
	t_list	*lst2 = ft_lstnew(&w, sizeof(int));
	t_list	*lst3 = ft_lstnew(&x, sizeof(int));
	ft_lstadd(&lst2, lst1);
	ft_lstaddback(&lst1, lst3);
	tmp = lst1;
	while (tmp)
	{
		ft_putnbr(*(int*)(tmp->content));
		ft_putchar('\n');
		tmp = tmp->next;
	}

	//test ft_lstlen
	ft_putstr("\ntest lstlen :\n");
	ft_putnbr(ft_lstlen(lst1));
	ft_putstr(" = 3\n");















	return (0);

}
