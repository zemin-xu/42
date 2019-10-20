#include <stdio.h>
#include <string.h>
#include "libft.h"

// scripts with potential problems : 
// strmapi


void	check_memset(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	char	str3[3] = "op";
	char	str4[3] = "op";
	char	str5[1] = "";
	char	str6[1] = "";
	char	str7[1] = "";

	char	*str8;
	char	*str9;

	str8 = (char *)malloc(sizeof(char) * 5);
	str9 = (char *)malloc(sizeof(char) * 5);

	printf("[+] MEMSET [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcd || size : 4 : compare : %d[-]\n",
			ft_memset(str1, '$', 4), memset(str2, '$', 4), strncmp(str1, str2, 4));
	printf("[-] mine: %s || origin: %s || ex : op || size : 2 : compare : %d[-]\n",
			ft_memset(str3, '$', 2), memset(str4, '$', 2), strncmp(str3, str4, 2));

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || origin: %s || ex : 0 || size : 1 : compare : %d[-]\n",
			ft_memset(str5, '$', 1), memset(str6, '$', 1), strncmp(str5, str6, 1));
	printf("[-] mine: %s || res : $ || ex : 0 || size : 1 : compare %d[-]\n",
			ft_memset(str7, '$', 3), strncmp(str7, "$", 1));
	printf("[-] mine: %s || origin: %s || ex : 0 || size : 5 : compare : %d[-]\n",
			ft_memset(str8, '$', 5), memset(str9, '$', 5), strncmp(str8, str9, 5));
	printf("[+] END OF MEMSET [+]\n\n");
}

void	check_bzero(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	char	str3[3] = "op";
	char	str4[3] = "op";
	char	str5[1] = "";
	char	str6[1] = "";
	char	str7[1] = "";

	char	*str8;
	char	*str9;

	str8 = (char *)malloc(sizeof(char) * 5);
	str9 = (char *)malloc(sizeof(char) * 5);

	ft_bzero(str1, 4);
	bzero(str2, 4);
	ft_bzero(str3, 2);
	bzero(str4, 2);
	ft_bzero(str5, 1);
	bzero(str6, 1);
	ft_bzero(str7, 3);
	ft_bzero(str8, 5);
	bzero(str9, 5);

	printf("[+] BZERO [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcd || size : 4 : compare : %d[-]\n",
			str1, str2, strncmp(str1, str2, 4));
	printf("[-] mine: %s || origin: %s || ex : op || size : 2 : compare : %d[-]\n",
			str3, str4, strncmp(str3, str4, 2));
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || origin: %s || ex : 0 || size : 1 : compare : %d[-]\n",
			str5, str6, strncmp(str5, str6, 1));
	printf("[-] mine: %s || res :  || ex : 0 || size : 1 : compare %d[-]\n",
			str7, strncmp(str7, "", 1));
	printf("[-] mine: %s || origin: %s || ex : 0 || size : 5 : compare : %d[-]\n",
			str8, str9, strncmp(str8, str9, 5));
	printf("[+] END OF BZERO [+]\n\n");
}

void	check_memcpy(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	int		int1[2] = {21, 42};
	int		int2[2] = {21, 42};

	char	dst1[8] = "";
	char	dst2[8] = "";
	int		int3[2];
	int		int4[2];
	
	ft_memcpy(int3, int1, sizeof(int1));
	memcpy(int4, int2, sizeof(int2));

	printf("[+] MEMCPY [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcd || size : %lu : compare : %d[-]\n", ft_memcpy(dst1, str1, sizeof(str1)), memcpy(dst2, str2, sizeof(str2)), sizeof(str1), strncmp(dst1, dst2, sizeof(dst1)));

	printf("[-] Test with INT ARRAY [-]\n");
	printf("[-] mine: %d, %d || origin: %d, %d || ex : {%d, %d} || size of array : %lu[-]\n", int3[0], int3[1], int4[0], int4[1], int1[0], int1[1], sizeof(int1));
	printf("[+] END OF MEMCPY [+]\n\n");
}


void	check_memccpy(void)
{
	char	str1[17] = "abcdef";
	char	str2[17] = "";
	char	str3[17] = "abcdef";
	char	str4[17] = "";
	
	printf("[+] MEMCCPY [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcdef || size : 6 : compare : %d[-]\n", ft_memccpy(str2, str1, 'c', 6), memccpy(str4, str3, 'c', 6), strncmp(str2, str4, 6));
	printf("[+] END OF MEMCCPY [+]\n\n");
}
void	check_memmove(void)
{
	char	str1[17] = "abcdef";
	char	str2[17] = "abcdef";
	char	str3[17] = "abcdef";
	char	str4[17] = "abcdef";
	int		int1[2] = {21, 42};
	int		int2[2] = {21, 42};

	int		int3[2];
	int		int4[2];
	
	ft_memmove(int3, int1, sizeof(int1));
	memmove(int4, int2, sizeof(int2));

	printf("[+] MEMMOVE [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcdef || size : 6 : compare : %d[-]\n", ft_memmove(str1 + 4, str1, 6), memmove(str2 + 4, str2, 6), strncmp(str1 + 4, str2 + 4, 6));

	printf("[-] Compare with MEMCPY [-]\n");
	printf("[-] mine: %s || origin: %s || ex : abcdef || size : 6 : compare : %d[-]\n", ft_memcpy(str3 + 4, str3, 6), memcpy(str4 + 4, str4, 6), strncmp(str3 + 4, str4 + 4, 6));

	printf("[-] Test with INT ARRAY [-]\n");
	printf("[-] mine: %d, %d || origin: %d, %d || ex : {%d, %d} || size of array : %lu[-]\n", int3[0], int3[1], int4[0], int4[1], int1[0], int1[1], sizeof(int1));
	printf("[+] END OF MEMMOVE [+]\n\n");
}

void	check_memchr(void)
{
	char	str1[5] = "abcd";
	char	str2[7] = "abac";
	char	str3[1] = "";

	printf("[+] MEMCHR [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcd || key : 'c' : compare : %d[-]\n", ft_memchr(str1, 'c', 5), memchr(str1, 'c', 5), 
			strncmp(ft_memchr(str1, 'c', 5), memchr(str1, 'c', 5), 3));
	printf("[-] mine: %s || origin: %s || ex : abac || key : 'a' : compare : %d[-]\n", ft_memchr(str2, 'a', 5), memchr(str2, 'a', 5), 
			strncmp(ft_memchr(str2, 'a', 5), memchr(str2, 'a', 5), 3));


	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || origin: %s || ex : 0 || key : ' ' [-]\n", ft_memchr(str3, ' ', 2), memchr(str3, ' ', 2)); 
	printf("[-] mine: %s || origin: %s || ex : 0 || key : 0 : compare : %d[-]\n", ft_memchr(str3, 0, 2), memchr(str3, 0, 2), 
			strncmp(ft_memchr(str3, 0, 2), memchr(str3, 0, 2), 2));
	printf("[+] END OF MEMCHR [+]\n\n");
}

void	check_memcmp(void)
{
	char	str1[17] = "abcdef";
	char	str2[17] = "abcdef";
	char	str3[17] = "abcdef";
	char	str4[17] = "abcdef";
	char	str5[1] = "";
	char	str6[1] = "";
	int		int1[2] = {21, 42};
	int		int2[2] = {21, 42};

	printf("[+] MEMCMP [+]\n");
	printf("[-] mine: %d || origin: %d || ex : abcdef && abcdef [-]\n",
			ft_memcmp(str1, str2, 7), memcmp(str1, str2, 7)); 
	printf("[-] mine: %d || origin: %d || ex : abcdef && abCdef [-]\n",
			ft_memcmp(str3, str4, 7), memcmp(str3, str4, 7)); 
	printf("[-] mine: %d || origin: %d || ex : {21,42} && {21,42} [-]\n",
			ft_memcmp(int1, int2, sizeof(int1)), memcmp(int1, int2, sizeof(int2))); 

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %d || origin: %d || ex : %s && %s [-]\n",
			ft_memcmp(str5, str6, 1), memcmp(str5, str6, 1), str5, str6); 
	printf("[+] END OF MEMCMP [+]\n\n");
}

char	check_strmap_inverse_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	check_strmapi_inverse_alpha(unsigned int i, char c)
{
	return (check_strmap_inverse_alpha(c) + i);
}


void	check_strmapi(void)
{
	char	str1[5] = "aBcD";
	char	str2[5] = "";
	char	(*func)(unsigned int, char) = check_strmapi_inverse_alpha;

	printf("[+] STRMAPI [+]\n");
	printf("[-] The function here will inverse the alphabet [-]\n");
	printf("[-] As well as adding its index value [-]\n");
	printf("[-] mine: %s || ex : %s [-]\n", ft_strmapi(str1, func), str1);
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || ex : %s [-]\n", ft_strmapi(str2, func), str2);
	printf("[+] END OF STRMAPI [+]\n\n");
}

void	check_strtrim(void)
{
	printf("[+] STRTRIM [+]\n");
	printf("[+] END OF STRTRIM [+]\n\n");
}

void	check_strsplit(void)
{
	printf("[+] STRSPLIT [+]\n");
	printf("[+] END OF STRSPLIT [+]\n\n");
}

void	check_strsub()
{
	char str[] = "lorem ipsum dolor sit amet";
	char *strsub;
	char *test;

	strsub = ft_substr(str, 400, 20);

	if (strsub != NULL)
	{
		test = (char *)&strsub[30];
		test = "no sense";
	}
	
	printf("[+] STRSUB [+]\n");
	printf("[-] mine: %s [-]\n", (strsub == NULL) ? "NULL" : "NOT NULL");

	printf("[+] END OF STRSUB [+]\n\n");
}

void	check_itoa(void)
{
	int int1 = 107;
	int int2 = 0;
	int int3 = -2147483648;

	printf("[+] ITOA [+]\n");

	printf("[-] mine: %s || ex : %d [-]\n",
			ft_itoa(int1), int1);
	printf("[-] mine: %s || ex : %d [-]\n",
			ft_itoa(int2), int2);
	printf("[-] mine: %s || ex : %d [-]\n",
			ft_itoa(int3), int3);
	
	printf("[-] Test with EMPTY STRING [-]\n");

	printf("[+] END OF ITOA [+]\n\n");
}

void	check_strlen(void)
{
	char	str[5] = "abcd";
	char	str2[3] = "op";

	printf("[+] STRLEN [+]\n");
	printf("[-] %s, sized: %d || origin: %d [-]\n",
			str, (int)ft_strlen(str), (int)strlen(str));
	printf("[-] %s, sized: %d || origin: %d [-]\n",
			str2, (int)ft_strlen(str2), (int)strlen(str2));

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] sized: %d || origin: %d [-]\n",
			(int)strlen(""), (int)strlen(""));
	printf("[+] END OF STRLEN [+]\n\n");
}

void	check_strlcat(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	char	str3[9] = "efgh";
	char	str4[9] = "efgh";
	int a1 = ft_strlcat(str3, str1, 9);
	int a2 = strlcat(str4, str2, 9);

	char	str5[5] = "abcd";
	char	str6[5] = "abcd";
	char	str7[9] = "efgh";
	char	str8[9] = "efgh";
	int a3 = ft_strlcat(str7, str5, 0);
	int a4 = strlcat(str8, str6, 0);

	char	str9[8] = "abcdaed";
	char	str10[8] = "abcdaed";
	char	str11[9] = "efgh";
	char	str12[9] = "efgh";
	int a5 = ft_strlcat(str11, str9, 1);
	int a6 = strlcat(str12, str10, 1);

	char	str13[6] = "abcde";
	char	str14[6] = "abcde";
	char	str15[9] = "";
	char	str16[9] = "";
	int a7 = ft_strlcat(str15, str13, 2);
	int a8 = strlcat(str16, str14, 2);

	char	str17[] = "lorem ipsum dolor sit amet";
	char	str18[] = "lorem ipsum dolor sit amet";
	char	str19[16] = "rrrrrrrrrrrrrrr";
	char	str20[16] = "rrrrrrrrrrrrrrr";
	int a9 = ft_strlcat(str19, str17, 5);
	int a10 = strlcat(str20, str18, 5);

	printf("[+] STRLCAT [+]\n");
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str3, str4, a1, a2, strncmp(str3, str4, 9), ((a1 == a2) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str7, str8, a3, a4, strncmp(str7, str8, 9), ((a3 == a4) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str11, str12, a5, a6, strncmp(str11, str12, 9), ((a5 == a6) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str15, str16, a7, a8, strncmp(str15, str16, 9), ((a7 == a8) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str19, str20, a9, a10, strncmp(str19, str20, 5), ((a9 == a10) ? "RIGHT" : "WRONG")); 
	
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[+] END OF STRLCAT [+]\n\n");
}

void	check_strlcpy(void)
{
	char	str1[6] = "lorem";
	char	str2[6] = "lorem";
	char	str3[14] = "sssssssssssss";
	char	str4[14] = "sssssssssssss";
	int a1 = ft_strlcpy(str3, str1, 6);
	int a2 = strlcpy(str4, str2, 6);

	char	str5[6] = "lorem";
	char	str6[6] = "lorem";
	char	str7[14] = "sssssssssssss";
	char	str8[14] = "sssssssssssss";
	int a3 = ft_strlcpy(str7, str5, 8);
	int a4 = strlcpy(str8, str6, 8);

	char	str9[1] = "";
	char	str10[1] = "";
	char	str11[14] = "sssssssssssss";
	char	str12[14] = "sssssssssssss";
	int a5 = ft_strlcpy(str11, str9, 3);
	int a6 = strlcpy(str12, str10, 3);

	char	str13[12] = "lorem ipsum";
	char	str14[12] = "lorem ipsum";
	char	str15[14] = "sssssssssssss";
	char	str16[14] = "sssssssssssss";
	int a7 = ft_strlcpy(str15, str13, 3);
	int a8 = strlcpy(str16, str14, 3);

	char	str17[27] = "lorem ipsum dolor sit amet";
	char	str18[27] = "lorem ipsum dolor sit amet";
	char	str19[16] = "sssssssssssssss";
	char	str20[16] = "sssssssssssssss";
	int a9 = ft_strlcpy(str19, str17, 0);
	int a10 = strlcpy(str20, str18, 0);

	printf("[+] STRLCPY [+]\n");
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str3, str4, a1, a2, strncmp(str3, str4, 6), ((a1 == a2) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str7, str8, a3, a4, strncmp(str7, str8, 8), ((a3 == a4) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str11, str12, a5, a6, strncmp(str11, str12, 3), ((a5 == a6) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str15, str16, a7, a8, strncmp(str15, str16, 3), ((a7 == a8) ? "RIGHT" : "WRONG")); 
	printf("[-] mine: %s || origin: %s || return : %d || %d || compare : %d %s[-]\n",
			str19, str20, a9, a10, strncmp(str19, str20, 0), ((a9 == a10) ? "RIGHT" : "WRONG")); 
			
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[+] END OF STRLCPY [+]\n\n");
}

void	check_strnstr(void)
{
	char	str1[5] = "abcd";
	char	str2[3] = "bc";
	char	str3[9] = "hehecett";
	char	str4[5] = "hece";
	char	str5[6] = "where";
	char	str6[5] = "erea";
	char	str7[7] = "lorem ";

	char	*str8 = (char *)malloc(sizeof(char) * 1);
	char	*str9 = (char *)malloc(sizeof(char) * 1);

	char	str11[27] = "lorem ipsum dolor sit amet";
	char	str12[6] = "dolor";
	char	str13[27] = "lorem ipsum dolor sit amet";
	char	str14[6] = "dol";

	printf("[+] STRNSTR [+]\n");
	printf("[-] mine: %s || origin: %s : s1: %s|| s2:%s || compare: %d[-]\n",
			ft_strnstr(str1, str2,4), strnstr(str1, str2,4), str1, str2,
			strcmp(ft_strnstr(str1, str2,4), strnstr(str1, str2,4)));
	printf("[-] mine: %s || origin: %s : s1: %s|| s2:%s || compare: %d[-]\n",
			ft_strnstr(str3, str4,8), strnstr(str3, str4,8), str3, str4,
			strcmp(ft_strnstr(str3, str4,8), strnstr(str3, str4,8)));

	printf("[-] s1: %s || s2: %s || size:5 || result : %s[-]\n",
			str5, str6, ((ft_strnstr(str5, str6,5) == NULL) ? "RIGHT" : "WRONG"));
	printf("[-] s1: %s || s2: %s || size:15 || result : %s[-]\n",
			str11, str12, ((ft_strnstr(str11, str12,15) == NULL) ? "RIGHT" : "WRONG"));
	printf("[-] s1: %s || s2: %s || size:15 || result : %s[-]\n",
			str13, str14, ((ft_strnstr(str13, str14,15) == NULL) ? "WRONG" : "RIGHT"));

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] s1: %s || s2: %s || size:6 || result : %s[-]\n",
			str7, "", ((ft_strnstr(str7, "", 6) == NULL) ? "WRONG" : "RIGHT"));
	printf("[-] s1: %s || s2: %s || size:1 || result : %s[-]\n",
			"", "", ((ft_strnstr("", "", 1) == NULL) ? "WRONG" : "RIGHT"));

	printf("[-] Test with NULL STRING [-]\n");
	printf("[-] s1: %s || s2: %s || size:1 || result : %s[-]\n",
			str8, "sf", ((ft_strnstr(str8,"sf",1) == NULL) ? "RIGHT" : "WRONG"));
	printf("[-] s1: %s || s2: %s || size:1 || result : %s[-]\n",
			str9, "", ((ft_strnstr(str9,"",1) == NULL) ? "WRONG" : "RIGHT"));
	printf("[-] s1: %s || s2: %s || size:1 || result : %s[-]\n",
			str8, str9,((ft_strnstr(str8,str9,1)== NULL) ? "WRONG" : "RIGHT"));
	printf("[+] END OF STRNSTR [+]\n");
}

void	check_strjoin(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	char	str3[9] = "efgh";
	char	str4[9] = "efgh";

	char	str5[] = "abcd";
	char	str6[] = "abcd";
	char	str7[] = "efgh";
	char	str8[] = "efgh";

	char	str13[6] = "abcde";
	char	str14[6] = "abcde";
	char	str15[9] = "";
	char	str16[9] = "";


	printf("[+] STRJOIN [+]\n");
	printf("[-] mine: %s || origin: abcdefgh || compare : %d[-]\n",
			ft_strjoin(str1, str3), strncmp(ft_strjoin(str2,str4), "abcdefgh", 9)); 
	printf("[-] mine: %s || origin: abcdefgh || compare : %d[-]\n",
			ft_strjoin(str5, str7), strncmp(ft_strjoin(str6,str8), "abcdefgh", 9)); 
	
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || origin: abcde || compare : %d[-]\n",
			ft_strjoin(str13, str15), strncmp(ft_strjoin(str14,str16), "abcde", 6)); 
	printf("[+] END OF STRJOIN [+]\n\n");
}

void	check_putnbr_fd(void)
{

	printf("[+] PUTNBR_FD [+]\n");
	printf("[-] num: 0 || fd: 1 [-]\n");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("[-] num: 10 || fd: 2 [-]\n");
	ft_putnbr_fd(10, 2);
	printf("\n");

	printf("[-] num: -5 || fd: 2 [-]\n");
	ft_putnbr_fd(-5, 2);
	printf("\n");

	printf("[-] num: -57 || fd: 2 [-]\n");
	ft_putnbr_fd(-57, 2);
	printf("\n");

	printf("[-] num: -987441 || fd: 1 [-]\n");
	ft_putnbr_fd(-987441, 1);
	printf("\n");

	printf("[-] num: -987441 || fd: 1 [-]\n");
	ft_putnbr_fd(-987441, 1);
	printf("\n");

	printf("[-] num: 2147483647 || fd: 1 [-]\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");

	printf("[-] num: -2147483648 || fd: 2 [-]\n");
	ft_putnbr_fd(-2147483648, 2);
	printf("\n");
	printf("[+] END OF PUTNBR_FD [+]\n");

}

void	check_strncmp(void)
{
	char	str[5] = "abcd";
	char	str2[3] = "op";

	printf("[+] STRNCMP [+]\n");
	printf("[-] mine: %d || origin: %d || size : 2 : s1: %s|| s2:%s[-]\n",
			ft_strncmp(str, str2, 2), strncmp(str, str2, 2), str, str2);
	printf("[-] mine: %d || origin: %d || size : 4 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("wher", "where", 4), strncmp("wher", "where", 4), 
			"wher", "where");
	printf("[-] mine: %d || origin: %d || size : 5 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("wher", "where", 5), strncmp("wher", "where", 5), 
			"wher", "where");
	printf("[-] mine: %d || origin: %d || size : 3 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("whke", "whre", 3), strncmp("whke", "whre", 3), 
			"whke", "whre");

	printf("[-] Test with HALF_EMPTY STRING [-]\n");
	printf("[-] mine: %d || origin: %d || size : 0 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("", "e", 0), strncmp("", "e", 0), "", "e");
	printf("[-] mine: %d || origin: %d || size : 0 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("e", "", 0), strncmp("e", "", 0), "e", "");
	printf("[-] mine: %d || origin: %d || size : 1 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("", "ed", 1), strncmp("", "ed", 1), "", "ed");

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %d || origin: %d || size : 0 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("", "", 0), strncmp("", "", 0), "", "");
	printf("[-] mine: %d || origin: %d || size : 1 : s1: %s|| s2:%s[-]\n",
			ft_strncmp("", "", 1), strncmp("", "", 1), "", "");
	printf("[+] END OF STRNCMP [+]\n");
}

void	check_toupper(void)
{
	printf("[+] TOUPPER [+]\n");
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper('t'), ft_toupper('t'), 't', 't');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper('B'), ft_toupper('B'), 'B', 'B');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper('~'), ft_toupper('~'), '~', '~');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper(' '), ft_toupper(' '), ' ', ' ');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper(0), ft_toupper(0), 0, 0);
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_toupper(-12), ft_toupper(-12), -12, -12);
	printf("[+] END OF TOUPPER [+]\n");
}

void	check_tolower(void)
{
	printf("[+] TOLOWER [+]\n");
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower('t'), ft_tolower('t'), 't', 't');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower('F'), ft_tolower('F'), 'F', 'F');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower('~'), ft_tolower('~'), '~', '~');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower(' '), ft_tolower(' '), ' ', ' ');
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower(0), ft_tolower(0), 0, 0);
	printf("[-] mine: %c || %d || origin: %c || %d [-]\n",
			ft_tolower(-12), ft_tolower(-12), -12, -12);
	printf("[+] END OF TOLOWER [+]\n");
}

void	check_split(void)
{
	
	char ori1[] = "@@abcde@@fg@@hijk@";
	char **res1;

	char ori2[] = "123@abc";
	char **res2;

	char ori3[] = "@@@abc@@@";
	char **res3;
	
	char ori4[] = "@@@@@@";
	char **res4;

	char ori5[] = "";
	char **res5;

	char ori6[] = "@@or@@@@sit@ametl,@@@@@@@@@consectetur@@@adipiscing@elit.@ed@non@risus.@@@@";
	char **res6;

	printf("[+] SPLIT [+]\n");
	printf("[-] origin: %s || sep: %c [-]\n", ori1, '@' );  
	res1 = ft_split(ori1, '@');
	for(int i = 0; i < 3; i++)
		printf("%s\n", res1[i]);

	printf("[-] ------------------------------------- [-]\n" );  

	printf("[-] origin: %s || sep: %c [-]\n", ori2, '@' );  
	res2 = ft_split(ori2, '@');
	for(int i = 0; i < 3; i++)
		printf("%s\n", res2[i]);

	printf("[-] ------------------------------------- [-]\n" );  
	
	printf("[-] origin: %s || sep: %c [-]\n", ori3, '@' );  
	res3 = ft_split(ori3, '@');
	for(int i = 0; i < 1; i++)
		printf("%s\n", res3[i]);

	printf("[-] ------------------------------------- [-]\n" );  
	
	printf("[-] origin: %s || sep: %c [-]\n", ori4, '@' );  
	res4 = ft_split(ori4, '@');
	for(int i = 0; i < 1; i++)
		printf("%s\n", res4[i]);

	printf("[-] ------------------------------------- [-]\n" );  
	
	printf("[-] origin: %s || sep: %c [-]\n", ori5, '@' );  
	res5 = ft_split(ori5, '@');
	for(int i = 0; i < 1; i++)
		printf("%s\n", res5[i]);

	printf("[-] ------------------------------------- [-]\n" );  
	
	printf("[-] origin: %s || sep: %c [-]\n", ori6, '@');  
	res6 = ft_split(ori6, '@');
	for(int i = 0; i < 10; i++)
		printf("%s~~~%d\n", res6[i], i);

	printf("[+] END OF SPLIT [+]\n");
}

int     main(void)
{

	/*
	check_create_elem();
	check_list_push_front();
	check_list_push_back();
	check_list_at();
	check_list_remove_front();
	check_list_rotate();
	check_list_rotate_reverse();

	check_strlen();
	check_strncmp();
	check_strstr();
	check_strnstr();

	check_memset();
	check_bzero();
	check_memcpy();
	check_memccpy();
	check_memmove();
	check_strlcat();
	check_memchr();
	check_memcmp();
	check_toupper();
	check_tolower();
	check_strmap();
	check_strmapi();
	check_strequ();
	check_strtrim();
	check_strjoin();
	check_itoa();
	check_memccpy();
	check_split();
	check_putnbr_fd();
*/
	check_strsub();

}
