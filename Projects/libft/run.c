/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:11:05 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/31 13:07:22 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//a supprimer
//#include <bsd/string.h>

static int	read_line_cmp(int fd, char *str)
{
	char	c;

	while (*str)
	{
		read(fd, &c, 1);
		if (*str != c)
			return (1);
		str++;
	}
	read(fd, &c, 1);
	if (c != '\n')
		return (1);
	return (0);
}

void	ft_putnbr_fd_test(void)
{
	int		fd;
	int		error = 0;

	fd = open("tmp", O_WRONLY | O_CREAT, 0666);
	if (!fd)
		return ;
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("tmp", O_RDONLY);
	if (!fd)
		return ;
	error += read_line_cmp(fd, "-2147483648");
	error += read_line_cmp(fd, "2147483647");
	error += read_line_cmp(fd, "0");
	close(fd);
	printf("ft_putnbr_fd\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_putendl_fd_test(void)
{
	int		fd;
	int		error = 0;

	fd = open("tmp", O_WRONLY | O_CREAT, 0666);
	if (!fd)
		return ;
	ft_putendl_fd(NULL, fd);
	ft_putendl_fd("", fd);
	ft_putendl_fd("Bonjour !", fd);
	close(fd);
	fd = open("tmp", O_RDONLY);
	if (!fd)
		return ;
	error += read_line_cmp(fd, "");
	error += read_line_cmp(fd, "Bonjour !");
	close(fd);
	printf("ft_putendl_fd\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_putstr_fd_test(void)
{
	int		fd;
	int		error = 0;

	fd = open("tmp", O_WRONLY | O_CREAT, 0666);
	if (!fd)
		return ;
	ft_putstr_fd(NULL, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("", fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Bonjour", fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("tmp", O_RDONLY);
	if (!fd)
		return ;
	error += read_line_cmp(fd, "");
	error += read_line_cmp(fd, "");
	error += read_line_cmp(fd, "Bonjour");
	close(fd);
	printf("ft_putstr_fd\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_putchar_fd_test(void)
{
	int		fd;
	int		error = 0;

	fd = open("tmp", O_WRONLY | O_CREAT, 0666);
	if (!fd)
		return ;
	ft_putchar_fd('$', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("tmp", O_RDONLY);
	if (!fd)
		return ;
	error += read_line_cmp(fd, "$");
	close(fd);
	printf("ft_putchar_fd\t:\t%s\n", error ? "KO" : "OK");
}

static char		up(unsigned int i, char c)
{
	(void)i;
	return (c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c);
}

void			ft_strmapi_test(void)
{
	char	str[] = "Bonjour tout le monde !";
	char	*ret;
	int		error = 0;

	ret = ft_strmapi(str, up);
	error += !!strcmp(ret, "BONJOUR TOUT LE MONDE !");
	error += ret == str;
	ret = ft_strmapi("", up);
	error += !!strcmp(ret, "");
	error += ret == str;
	ret = ft_strmapi(NULL, up);
	error += ret != NULL;
	ret = ft_strmapi(str, NULL);
	error += ret != NULL;
	ret = ft_strmapi(NULL, NULL);
	error += ret != NULL;
	printf("ft_strmapi\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_itoa_test(void)
{
	int		error = 0;

	error += !!strcmp(ft_itoa(0), "0");
	error += !!strcmp(ft_itoa(-999), "-999");
	error += !!strcmp(ft_itoa(999), "999");
	error += !!strcmp(ft_itoa(2147483647), "2147483647");
	error += !!strcmp(ft_itoa(-2147483648), "-2147483648");
	printf("ft_itoa\t\t:\t%s\n", error ? "KO" : "OK");
}

static int		test_array(char **array, char **rep)
{
	while (*array || *rep)
	{
		if (strcmp(*array, *rep))
			return (1);
		array++;
		rep++;
	}
	return (0);
}

void			ft_split_test(void)
{
	char	s1[] = "   Bonjour les   enfants    je m'appelle Pascal !   ";
	char	s2[] = "Bonjour les   enfants    je m'appelle Pascal !   ";
	char	s3[] = "   Bonjour les   enfants    je m'appelle Pascal !";
	char	*r[] = { "Bonjour", "les", "enfants", "je", "m'appelle", "Pascal", "!", NULL };
	char	*r2[] = { NULL };
	char	*r3[] = { "Bonjour", NULL };
	char	*r4[] = { "  ", " ", "B", "onj", "our", " a ", "tous !", " ", NULL };
	char	s4[] = "   ";
	char	s5[] = "Bonjour";
	char	s6[] = "";
	char	s7[] = "  |||||| |B|||onj|our| a |||||tous !||| |";
	int		error = 0;
	
	error += ft_split(NULL, ' ') != NULL;
	error += test_array(ft_split(s1, ' '), r);
	error += test_array(ft_split(s2, ' '), r);
	error += test_array(ft_split(s3, ' '), r);
	error += test_array(ft_split(s4, ' '), r2);
	error += test_array(ft_split(s5, ' '), r3);
	error += test_array(ft_split(s6, ' '), r2);
	error += test_array(ft_split(s7, '|'), r4);
	printf("ft_split\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strtrim_test(void)
{
	char	s1[] = " (\"Bonjour\") ";	
	char	s2[] = "    Bonjour     ";	
	char	s3[] = "Bonjour     ";	
	char	s4[] = "     Bonjour";	
	char	s5[] = "";	
	char	s6[] = "            ";	
	char	s7[] = " A   ";	
	char	s8[] = "A";	
	char	s9[] = "......la.lou.li.....";	
	int		error = 0;

	error += ft_strtrim(NULL, " ") != NULL;
	error += ft_strtrim("Bonjour", NULL) != NULL;
	/*
	error += ft_strtrim(NULL, NULL) != NULL;
	error += !!strcmp(ft_strtrim(s1, "  "), "(\"Bonjour\")");
	error += !!strcmp(ft_strtrim(s2, "  "), "Bonjour");
	error += !!strcmp(ft_strtrim(s3, " "), "Bonjour");
	error += !!strcmp(ft_strtrim(s4, " "), "Bonjour");
	error += !!strcmp(ft_strtrim(s4, ""), "     Bonjour");
	error += !!strcmp(ft_strtrim(s5, "$$"), "");
	error += !!strcmp(ft_strtrim(s5, ""), "");
	error += !!strcmp(ft_strtrim(s6, " "), "");
	error += !!strcmp(ft_strtrim(s1, " ()\""), "Bonjour");
	error += !!strcmp(ft_strtrim(s3, "Bo"), "njour     ");
	error += !!strcmp(ft_strtrim(s7, " "), "A");
	error += !!strcmp(ft_strtrim(s8, " "), "A");
	error += !!strcmp(ft_strtrim(s9, "."), "la.lou.li");
	*/
	printf("ft_strtrim_test\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strjoin_test(void)
{
	char	s1[] = "";
	char	s2[] = "Bonjour ";
	char	s3[] = "les enfants !";
	int		error = 0;

	error += !!ft_strjoin(NULL, s2);
	error += !!ft_strjoin(s1, NULL);
	error += !!ft_strjoin(NULL, NULL);
	error += !!strcmp(ft_strjoin(s1, s2), "Bonjour ");
	error += !!strcmp(ft_strjoin(s2, s1), "Bonjour ");
	error += !!strcmp(ft_strjoin(s2, s3), "Bonjour les enfants !");
	printf("ft_strjoin\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_substr_test(void)
{
	char	str[] = "Bonjour tout le monde !";
	int		error = 0;

	error += ft_substr(NULL, 10, 10) != NULL; 
	error += !!strcmp(ft_substr(str, 8, 8), "tout le ");
	error += !!strcmp(ft_substr(str, 0, 7), "Bonjour");
	error += !!strcmp(ft_substr(str, 8, 100), "tout le monde !");
	error += !!strcmp(ft_substr(str, 0, 100), "Bonjour tout le monde !");
	error += !!strcmp(ft_substr(str, 8, 0), "");
	error += !!strcmp(ft_substr(str, 22, 100), "!");
	error += !!strcmp(ft_substr(str, 23, 100), "");
	printf("ft_substr\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strdup_test(void)
{
	char	str1[] = "Bonjour";
	char	*cp1;
	char	*cp1b;
	char	str2[] = "";
	char	*cp2;
	char	*cp2b;
	int		error = 0;

	cp1 = strdup(str1);
	cp1b = ft_strdup(str1);
	error += !!strcmp(cp1, cp1b);
	error += cp1 == cp1b;
	cp2 = strdup(str2);
	cp2b = ft_strdup(str2);
	error += !!strcmp(cp2, cp2b);
	error += cp2 == cp2b;
	printf("ft_strdup\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_calloc_test(void)
{
	void	*mem_1;
	void	*mem_2;
	int		error = 0;

	mem_1 = calloc(4, 4);
	mem_2 = ft_calloc(4, 4);
	error += !!memcmp(mem_1, mem_2, 16);	
	free(mem_1);
	free(mem_2);
	printf("ft_calloc\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_atoi_test(void)
{
	char	nb_1[] = "0";
	char	nb_2[] = "12";
	char	nb_3[] = "-11";
	char	nb_4[] = "+23888";
	char	nb_5[] = "--600";
	char	nb_6[] = ".600";
	char	nb_7[] = "666.";
	char	nb_8[] = "95.1";
	char	nb_9[] = "";
	char	nb_10[] = "&";
	char	nb_11[] = "  -234";
	char	nb_12[] = "   +234";
	char	nb_13[] = "   234";
	char	nb_14[] = "   &934";
	char	nb_15[] = " 934";
	char	nb_16[] = "0934";
	char	nb_17[] = "001934";
	char	nb_18[] = "99999999999999999999999";
	char	nb_19[] = "-99999999999999999999999";
	char	nb_20[] = "2147483647";
	char	nb_21[] = "-2147483648";
	char	nb_22[] = "2147483648";
	char	nb_23[] = "-2147483649";
	char	nb_24[] = "9223372036854775807";
	char	nb_25[] = "-9223372036854775808";
	char	nb_26[] = "9223372036854775808";
	char	nb_27[] = "-9223372036854775809";
	int		error = 0;

	error += atoi(nb_1) != ft_atoi(nb_1);
	error += atoi(nb_2) != ft_atoi(nb_2);
	error += atoi(nb_3) != ft_atoi(nb_3);
	error += atoi(nb_4) != ft_atoi(nb_4);
	error += atoi(nb_5) != ft_atoi(nb_5);
	error += atoi(nb_6) != ft_atoi(nb_6);
	error += atoi(nb_7) != ft_atoi(nb_7);
	error += atoi(nb_8) != ft_atoi(nb_8);
	error += atoi(nb_9) != ft_atoi(nb_9);
	error += atoi(nb_10) != ft_atoi(nb_10);
	error += atoi(nb_11) != ft_atoi(nb_11);
	error += atoi(nb_12) != ft_atoi(nb_12);
	error += atoi(nb_13) != ft_atoi(nb_13);
	error += atoi(nb_14) != ft_atoi(nb_14);
	error += atoi(nb_15) != ft_atoi(nb_15);
	error += atoi(nb_16) != ft_atoi(nb_16);
	error += atoi(nb_17) != ft_atoi(nb_17);
	error += atoi(nb_18) != ft_atoi(nb_18);
	error += atoi(nb_19) != ft_atoi(nb_19);
	error += atoi(nb_20) != ft_atoi(nb_20);
	error += atoi(nb_21) != ft_atoi(nb_21);
	error += atoi(nb_22) != ft_atoi(nb_22);
	error += atoi(nb_23) != ft_atoi(nb_23);
	error += atoi(nb_24) != ft_atoi(nb_24);
	error += atoi(nb_25) != ft_atoi(nb_25);
	error += atoi(nb_26) != ft_atoi(nb_26);
	error += atoi(nb_27) != ft_atoi(nb_27);
	printf("ft_atoi\t\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strnstr_test(void)
{
	char	big_a[] = "Bonjour les amis je m'appelle Pascal";
	char	big_b[] = "";
	char	lit_a[] = "Bon";
	char	lit_b[] = "les";
	char	lit_c[] = "cal";
	char	lit_d[] = "Bonjour les amis je m'appelle Pascal";
	char	lit_e[] = "amisje";
	char	lit_f[] = "";
	char	lit_g[] = "jour les amis je m'appelle Pascal";
	int		error = 0;

	error += !!strcmp(strnstr(big_a, lit_a, 40), ft_strnstr(big_a, lit_a, 40));
	error += !!strcmp(strnstr(big_a, lit_b, 40), ft_strnstr(big_a, lit_b, 40));
	error += !!strcmp(strnstr(big_a, lit_c, 40), ft_strnstr(big_a, lit_c, 40));
	error += strnstr(big_a, lit_c, 30) != ft_strnstr(big_a, lit_c, 30);
	error += !!strcmp(strnstr(big_a, lit_d, 40), ft_strnstr(big_a, lit_d, 40));
	error += strnstr(big_a, lit_d, 30) != ft_strnstr(big_a, lit_d, 30);
	error += strnstr(big_a, lit_e, 40) != ft_strnstr(big_a, lit_e, 40);
	error += strnstr(big_b, lit_a, 40) != ft_strnstr(big_b, lit_a, 40);
	error += !!strcmp(strnstr(big_b, lit_f, 40), ft_strnstr(big_b, lit_f, 40));
	error += !!strcmp(strnstr(big_a, lit_f, 40), ft_strnstr(big_a, lit_f, 40));
	error += !!strcmp(strnstr(big_a, lit_g, 40), ft_strnstr(big_a, lit_g, 40));
	error += strnstr(big_a, lit_g, 35) != ft_strnstr(big_a, lit_g, 35);
	printf("ft_strnstr\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strlcat_test(void)
{
	char	src[] = "les gens !";
	char	dst_a[25] = "Bonjour ";
	char	dst_a2[25] = "Bonjour ";
	char	dst_b[25] = "Bonjour ";
	char	dst_b2[25] = "Bonjour ";
	char	dst_c[25] = "Bonjour ";
	char	dst_c2[25] = "Bonjour ";
	char	dst_d[25] = "Bonjour ";
	char	dst_d2[25] = "Bonjour ";
	char	dst_e[25] = "Bonjour ";
	char	dst_e2[25] = "Bonjour ";
	char	dst_f[25] = "Bonjour ";
	char	dst_f2[25] = "Bonjour ";
	char	dst_g[25] = "Bonjour ";
	char	dst_g2[25] = "Bonjour ";
	char	dst_h[25] = "";
	char	dst_h2[25] = "";
	int		error = 0;

	error += strlcat(dst_b, src, 15) != ft_strlcat(dst_b2, src, 15);
	error += !!memcmp(dst_b, dst_b2, 25);
	error += strlcat(dst_f, src, 10) != ft_strlcat(dst_f2, src, 10);
	error += !!memcmp(dst_f, dst_f2, 25);
	error += strlcat(dst_c, src, 9) != ft_strlcat(dst_c2, src, 9);
	error += !!memcmp(dst_c, dst_c2, 25);
	error += strlcat(dst_d, src, 8) != ft_strlcat(dst_d2, src, 8);
	error += !!memcmp(dst_d, dst_d2, 25);
	error += strlcat(dst_g, src, 5) != ft_strlcat(dst_g2, src, 5);
	error += !!memcmp(dst_g, dst_g2, 25);
	error += strlcat(dst_e, src, 0) != ft_strlcat(dst_e2, src, 0);
	error += !!memcmp(dst_e, dst_e2, 25);
	error += strlcat(dst_h, src, 5) != ft_strlcat(dst_h2, src, 5);
	error += !!memcmp(dst_h, dst_h2, 25);
	printf("ft_strlcat\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strlcpy_test(void)
{
	char	src[] = "Bonjour !, Bonjour !";
	char	dst_a[] = "Hello world ! Hello world !";
	char	dst_a2[] = "Hello world ! Hello world !";
	char	dst_b[] = "Hello world ! Hello world !";
	char	dst_b2[] = "Hello world ! Hello world !";
	char	dst_c[] = "Hello world ! Hello world !";
	char	dst_c2[] = "Hello world ! Hello world !";
	int		error = 0;
	
	error += strlcpy(dst_a, src, 10) != ft_strlcpy(dst_a2, src, 10);
	error += !!strcmp(dst_a, dst_a2);
	error += strlcpy(dst_c, src, 0) != ft_strlcpy(dst_c2, src, 0);
	error += !!strcmp(dst_c, dst_c2);
	printf("ft_strlcpy\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strncmp_test(void)
{
	char	*str_a = "Bonjour !";
	char	*str_b = "Bonsoir !";
	char	*str_c = "Bonjour !";
	char	*str_d = "Bon\200jour !";
	int		error = 0;
	
	error += strncmp(NULL, NULL, 0) != ft_strncmp(NULL, NULL, 0);
	error += strncmp(str_c, str_d, 6) != ft_strncmp(str_c, str_d, 6);
	error += strncmp(str_a, str_b, 4) != ft_strncmp(str_a, str_b, 4);
	error += strncmp(str_a, str_b, 3) != ft_strncmp(str_a, str_b, 3);
	error += strncmp(str_a, str_b, 0) != ft_strncmp(str_a, str_b, 0);
	error += strncmp(str_a, str_c, 9) != ft_strncmp(str_a, str_c, 9);
	error += strncmp(str_a, str_c, 20) != ft_strncmp(str_a, str_c, 20);
	printf("ft_strncmp\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strrchr_test(void)
{
	char	*str = "Bonjour !";
	int		error = 0;

	error += !!strcmp(strrchr("", '\0'), ft_strrchr("", '\0'));	
	error += strrchr("", 'a') != ft_strrchr("", 'a');
	error += !!strcmp(strrchr(str, 'B'), ft_strrchr(str, 'B'));	
	error += !!strcmp(strrchr(str, 'j'), ft_strrchr(str, 'j'));	
	error += !!strcmp(strrchr(str, '\0'), ft_strrchr(str, '\0'));	
	error += strrchr(str, 's') != ft_strrchr(str, 's');	
	error += !!strcmp(strrchr(str, 'o'), ft_strrchr(str, 'o'));	
	printf("ft_strrchr\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_strchr_test(void)
{
	char	*str = "Bonjour !";
	int		error = 0;

	error += !!strcmp(strchr("", '\0'), ft_strchr("", '\0'));	
	error += strchr("", 'a') != ft_strchr("", 'a');
	error += !!strcmp(strchr(str, 'B'), ft_strchr(str, 'B'));	
	error += !!strcmp(strchr(str, 'j'), ft_strchr(str, 'j'));	
	error += !!strcmp(strchr(str, '\0'), ft_strchr(str, '\0'));	
	error += strchr(str, 's') != ft_strchr(str, 's');	
	printf("ft_strchr\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_tolower_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (tolower(c) != ft_tolower(c))
		{
			printf("ft_tolower\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_tolower\t:\tOK\n");
}

void	ft_toupper_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (toupper(c) != ft_toupper(c))
		{
			printf("ft_toupper\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_toupper\t:\tOK\n");
}

void	ft_isprint_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (!!isprint(c) != !!ft_isprint(c))
		{
			printf("ft_isprint\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_isprint\t:\tOK\n");
}

void	ft_isascii_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (!!isascii(c) != !!ft_isascii(c))
		{
			printf("ft_isascii\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_isascii\t:\tOK\n");
}

void	ft_isalnum_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (!!isalnum(c) != !!ft_isalnum(c))
		{
			printf("ft_isalnum\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_isalnum\t:\tOK\n");
}

void	ft_isdigit_test(void)
{
	int		c;

	c = -530;
	while (c < 530)
	{
		if (!!isdigit(c) != !!ft_isdigit(c))
		{
			printf("ft_isdigit\t:\tKO\n");
			return ;
		}
		c++;
	}
	printf("ft_isdigit\t:\tOK\n");
}

void	ft_isalpha_test(void)
{
	int		c;

	c = -520;
	while (c < 530)
	{
		if (!!isalpha(c) != !!ft_isalpha(c))
		{
			printf("ft_isalpha\t:\tKO\n");	
			return ;
		}
		c++;
	}
	printf("ft_isalpha\t:\tOK\n");	
}

void	ft_strlen_test(void)
{
	char	*str_a = "Bonjour";
	char	*str_b = "";
	int		error;

	error = 0;
	error += strlen(str_a) != ft_strlen(str_a);
	error += strlen(str_b) != ft_strlen(str_b);
	printf("ft_strlen\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_memcmp_test(void)
{
	char	*s1_a = "Bonjour";
	char	*s1_b = "Bonkour";
	char	*s2_a = "Bonjour";
	char	*s2_b = "Boniour";
	char	*s3_a = "Bonjour";
	char	*s3_b = "Aonfour";
	int		error;

	error = 0;
	error += memcmp(s1_a, s1_b, 4) != ft_memcmp(s1_a, s1_b, 4);
	error += memcmp(s1_a, s1_b, 3) != ft_memcmp(s1_a, s1_b, 3);
	error += memcmp(s2_a, s2_b, 4) != ft_memcmp(s2_a, s2_b, 4);
	error += memcmp(s3_a, s3_b, 0) != ft_memcmp(s3_a, s3_b, 0);
	error += memcmp(s3_a, s3_b, 1) != ft_memcmp(s3_a, s3_b, 1);
	printf("ft_memcmp\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_memchr_test(void)
{
	char	*haystack = "Hays\200tack...";
	int		error;

	error = 0;
	error += (char *)memchr(haystack, 's', 0) != (char *)ft_memchr(haystack, 's', 0);
	error += !!strcmp((char *)memchr(haystack, 's', 4), (char *)ft_memchr(haystack, 's', 4));
	error += (char *)memchr(haystack, 's', 3) != (char *)ft_memchr(haystack, 's', 3);
	error += (char *)memchr(haystack, '\200', 10) != (char *)ft_memchr(haystack, '\200', 10);
	printf("ft_memchr\t:\t%s\n", error ? "KO" : "OK");
}

void	ft_memmove_test(void)
{
	char	str_left_a[100] = "Bonjour !";
	char	str_left_b[100] = "Bonjour !";
	char	str_right_a[100] = "Bonjour !";
	char	str_right_b[100] = "Bonjour !";
	char	*ret1;
	char	*ret2;
	char	*ret3;
	char	*ret4;
	int		error;

	error = 0;	
	ret1 = memmove(str_left_a + 3, str_left_a, 5);
	ret2 = ft_memmove(str_left_b + 3, str_left_b, 5);
	error += !!strcmp(str_left_a, str_left_b);
	error += !!strcmp(ret1, ret2);
	ret3 = memmove(str_right_a + 1, str_right_a + 3, 5);
	ret4 = ft_memmove(str_right_b + 1, str_right_b + 3, 5);
	error += !!strcmp(str_right_a, str_right_b);
	error += !!strcmp(ret3, ret4);
	error += memmove(NULL, NULL, 5) != ft_memmove(NULL, NULL, 5);
	printf("ft_memmove\t:\t%s\n", error ? "KO" : "OK");
}

void		ft_memccpy_test(void)
{
	char	src[] = "soi$";
	char	src2[] = "la\200tin";
	char	dst_a[] = "Bonjour !";
	char	dst_b[] = "Bonjour !";
	char	dst_2a[] = "Bonjour !";
	char	dst_2b[] = "Bonjour !";
	char	dst_3a[] = "Bonjour !";
	char	dst_3b[] = "Bonjour !";
	char	*ret1;
	char	*ret2;
	char	*ret3;
	char	*ret4;
	char	*ret5;
	char	*ret6;
	int		error;

	error = 0;
	ret1 = memccpy(dst_a + 3, src, 'i', 4);
	ret2 = ft_memccpy(dst_b + 3, src, 'i', 4);
	error += !!strcmp(dst_a, dst_b);
	error += !!strcmp(ret1, ret2);

	ret3 = memccpy(dst_2a, src2, '\200', 6);
	ret4 = ft_memccpy(dst_2b, src2, '\200', 6);
	error += !!strcmp(dst_2a, dst_2b);
	error += !!strcmp(ret3, ret4);

	ret5 = memccpy(dst_3a + 3, src, 'i', 2);
	ret6 = ft_memccpy(dst_3b + 3, src, 'i', 2);
	error += !!strcmp(dst_3a, dst_3b);
	error += ret5 != ret6;

	printf("ft_memccpy\t:\t%s\n", error ? "KO" : "OK");
}

void		ft_memcpy_test(void)
{
	char	src[4] = "soi";
	char	dst_a[10] = "Bonjour !";
	char	dst_b[10] = "Bonjour !";
	char	dst_c[10] = "Bonjour !";
	char	dst_d[10] = "Bonjour !";
	char	*ret_a;
	char	*ret_b;
	char	*ret_c;
	char	*ret_d;
	int		error;

	error = 0;
	error += memcpy(NULL, NULL, 3) != ft_memcpy(NULL, NULL, 3);
	ret_a = memcpy(dst_a + 3, src, 3);
	ret_b = ft_memcpy(dst_b + 3, src, 3);
	ret_c = memcpy(dst_c + 3, src, 0);
	ret_d = ft_memcpy(dst_d + 3, src, 0);
	error += !!strcmp(dst_a, dst_b);
	error += !!strcmp(ret_a, ret_b);
	error += !!strcmp(dst_c, dst_d);
	error += !!strcmp(ret_c, ret_d);
	printf("ft_memcpy\t:\t%s\n", error ? "KO" : "OK");
}

void		ft_bzero_test(void)
{
	char	str_a[10] = "Bonjour !";
	char	str_b[10] = "Bonjour !";
	char	str_c[10] = "Bonjour !";
	char	str_d[10] = "Bonjour !";

	bzero(str_a, 5);
	ft_bzero(str_b, 5);
	bzero(str_c, 0);
	ft_bzero(str_d, 0);
	printf("ft_bzero\t:\t%s\n", !!strcmp(str_a, str_b) || !!strcmp(str_c, str_d) ? "KO" : "OK");
}

void		ft_memset_test(void)
{
	char	str_a[10] = "Bonjour !";
	char	str_b[10] = "Bonjour !";
	char	*ret1;
	char	*ret2;
	char	str_c[10] = "Bonjour !";
	char	str_d[10] = "Bonjour !";
	char	*ret3;
	char	*ret4;
	char	error;

	error = 0;
	ret1 = memset(str_a + 1, -99999, 4);
	ret2 = ft_memset(str_b + 1, -99999, 4);
	error += !!strcmp(ret1, ret2) || !!strcmp(str_a, str_b);
	ret3 = memset(str_c, 99999, 0);
	ret4 = ft_memset(str_d, 99999, 0);
	error += !!strcmp(ret3, ret4) || !!strcmp(str_c, str_d);
	printf("ft_memset\t:\t%s", error ? "KO\n" : "OK\n");
}

int		main(void)
{
	printf("---------Part one---------\n");
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memccpy_test();
	ft_memmove_test();
	ft_memchr_test();
	ft_memcmp_test();
	ft_strlen_test();
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isascii_test();
	ft_isprint_test();
	ft_toupper_test();
	ft_tolower_test();
	ft_strchr_test();
	ft_strrchr_test();
	ft_strncmp_test();
	ft_strlcpy_test();
	ft_strlcat_test();
	ft_strnstr_test();
	ft_atoi_test();
	ft_calloc_test();
	ft_strdup_test();
	printf("---------Part two---------\n");
	ft_substr_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_split_test();
	ft_itoa_test();
	ft_strmapi_test();
	ft_putchar_fd_test();
	ft_putstr_fd_test();
	ft_putendl_fd_test();
	ft_putnbr_fd_test();
	return (0);
}
