#include <stdio.h>
#include "libft.h"

// scripts with potential problems : 
// strlcat
// strstr
// strnstr
//
void	check_create_elem(void)
{
	int		data1 = 42;
	char	*data2 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;

	t_list	*new_list1 = ft_create_elem(p_data1);
	t_list	*new_list2 = ft_create_elem(p_data2);
	printf("[+] CREATE_ELEM [+]\n");
	printf("[-] mine: %d || origin: %d [-]\n",
			*((int *)new_list1->data), data1);
	printf("[-] mine: %s || origin: %s [-]\n",
			*((char	**)new_list2->data), data2);
	printf("[+] END OF CREATE_ELEM [+]\n\n");
}

void	check_list_push_front(void)
{
	int		data1 = 42;
	int		data2 = 84;
	char	*data3 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);

	t_list	*head3 = NULL;
	ft_list_push_front(&head3, p_data3);

	printf("[+] LIST_PUSH_FRONT [+]\n");
	printf("[-] mine: %d || origin: %d [-]\n",
			*((int *)head->data), data2);
	printf("[-] Test with NULL LIST [-]\n");
	printf("[-] mine: %s || origin: %s [-]\n",
			*((char	**)head3->data), data3);
	printf("[+] END OF LIST_PUSH_FRONT [+]\n\n");
}

void	check_list_push_back(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_back(&head, p_data3);

	t_list	*head4 = NULL;
	ft_list_push_back(&head4, p_data4);

	printf("[+] LIST_PUSH_BACK [+]\n");
	printf("[-] mine: %d || origin: %d [-]\n",
			*((int *)head->next->next->data), data3);
	printf("[-] Test with NULL LIST [-]\n");
	printf("[-] mine: %s || origin: %s [-]\n",
			*((char	**)head4->data), data4);
	printf("[+] END OF LIST_PUSH_BACK [+]\n\n");
}

void	check_list_size(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_back(&head, p_data3);

	t_list	*head4 = NULL;
	ft_list_push_back(&head4, p_data4);

	t_list	*head5 = NULL;

	printf("[+] LIST_SIZE [+]\n");
	printf("[-] mine: %d || origin: 3 [-]\n",
			ft_list_size(head));
	printf("[-] mine: %d || origin: 1 [-]\n",
			ft_list_size(head4));
	printf("[-] Test with NULL LIST [-]\n");
	printf("[-] mine: %d || origin: 0 [-]\n",
			ft_list_size(head5));
	printf("[+] END OF LIST_SIZE [+]\n\n");
}

void	check_list_at(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_front(&head, p_data3);

	t_list	*head4 = NULL;
	ft_list_push_back(&head4, p_data4);

	t_list	*head5 = NULL;

	printf("[+] LIST_AT [+]\n");
	printf("[-] mine: %d || origin: 42 [-]\n",
			*(int *)(ft_list_at(head, 2)->data));
	printf("[-] mine: %d || origin: 84 [-]\n",
			*(int *)(ft_list_at(head, 1)->data));
	printf("[-] mine: %d || origin: 27 [-]\n",
			*(int *)(ft_list_at(head, 0)->data));
	printf("[-] Test with NULL LIST [-]\n");
	printf("[+] END OF LIST_AT [+]\n\n");
}

void	check_list_remove_front(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_front(&head, p_data3);

	t_list	*head4 = NULL;
	ft_list_push_front(&head4, p_data4);

	t_list	*head5 = NULL;

	printf("[+] LIST_REMOVE_FRONT [+]\n");
	ft_list_remove_front(&head);
	printf("[-] mine: %d || origin: 84 [-]\n", *(int *)(head->data));
	ft_list_remove_front(&head);
	printf("[-] mine: %d || origin: 42 [-]\n", *(int *)(head->data));

	printf("[-] Test expected to be NULL [-]\n");
	ft_list_remove_front(&head);
	printf("[-] result : %s [-]\n", ((head == NULL) ? "NULL" : "NOT NULL"));
	ft_list_remove_front(&head5);
	printf("[-] result : %s [-]\n", ((head5 == NULL) ? "NULL" : "NOT NULL"));
	printf("[+] END OF LIST_REMOVE_FRONT [+]\n\n");
}

void	check_list_rotate(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_front(&head, p_data3);

	t_list	*head4 = ft_create_elem(p_data4);

	t_list	*head5 = NULL;

	printf("[+] LIST_ROTATE [+]\n");
	printf("[-] mine: %d || origin: 27 [-]\n", *(int *)(head->data));
	ft_list_rotate(&head);
	printf("[-] mine: %d || origin: 84 [-]\n", *(int *)(head->data));
	ft_list_rotate(&head);
	printf("[-] mine: %d || origin: 42 [-]\n", *(int *)(head->data));

	printf("[-] mine: %c || origin: h [-]\n", *(char *)(head4->data));
	ft_list_rotate(&head4);
	printf("[-] mine: %c || origin: h [-]\n", *(char *)(head4->data));

	printf("[-] Test expected to be NULL [-]\n");
	ft_list_rotate(&head5);
	printf("[-] result : %s [-]\n", ((head5 == NULL) ? "NULL" : "NOT NULL"));
	printf("[+] END OF LIST_ROTATE [+]\n\n");
}

void	check_list_rotate_reverse(void)
{
	int		data1 = 42;
	int		data2 = 84;
	int		data3 = 27;
	char	*data4 = "hello";
	void	*p_data1 = (void *)&data1;
	void	*p_data2 = (void *)&data2;
	void	*p_data3 = (void *)&data3;
	void	*p_data4 = (void *)&data4;

	t_list	*head = ft_create_elem(p_data1);
	ft_list_push_front(&head, p_data2);
	ft_list_push_front(&head, p_data3);

	t_list	*head4 = ft_create_elem(p_data4);

	t_list	*head5 = NULL;

	printf("[+] LIST_ROTATE_REVERSE [+]\n");
	printf("[-] mine: %d || origin: 27 [-]\n", *(int *)(head->data));
	ft_list_rotate_reverse(&head);
	printf("[-] mine: %d || origin: 42 [-]\n", *(int *)(head->data));
	ft_list_rotate_reverse(&head);
	printf("[-] mine: %d || origin: 84 [-]\n", *(int *)(head->data));

	printf("[-] mine: %c || origin: h [-]\n", *(char *)(head4->data));
	ft_list_rotate_reverse(&head4);
	printf("[-] mine: %c || origin: h [-]\n", *(char *)(head4->data));

	printf("[-] Test expected to be NULL [-]\n");
	ft_list_rotate_reverse(&head5);
	printf("[-] result : %s [-]\n", ((head5 == NULL) ? "NULL" : "NOT NULL"));
	printf("[+] END OF LIST_REVERSE_ROTATE [+]\n\n");
}

void	check_memset(void)
{
	char	str1[5] = "abcd";
	char	str2[5] = "abcd";
	char	str3[3] = "op";
	char	str4[3] = "op";
	char	str5[1] = "";
	char	str6[1] = "";

	printf("[+] MEMSET [+]\n");
	printf("[-] mine: %s || origin: %s || ex : abcd || size : 5 : compare : %d[-]\n",
			ft_memset(str1, '$', 5), memset(str2, '$', 5), strncmp(str1, str2, 5));
	printf("[-] mine: %s || origin: %s || ex : op || size : 2 : compare : %d[-]\n",
			ft_memset(str3, '$', 2), memset(str4, '$', 2), strncmp(str3, str4, 2));

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || origin: %s || ex : 0 || size : 1 : compare : %d[-]\n",
			ft_memset(str5, '$', 1), memset(str6, '$', 1), strncmp(str5, str6, 1));
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

	printf("[+] BZERO [+]\n");
	ft_bzero(str1, 5);
	bzero(str2, 5);
	printf("[-] mine: %s || origin: %s || ex : abcd || size : 5 : compare : %d[-]\n", str1, str2, strncmp(str1, str2, 5));

	ft_bzero(str3, 2);
	bzero(str4, 2);
	printf("[-] mine: %s || origin: %s || ex : op || size : 2 : compare : %d[-]\n", str3, str4, strncmp(str3, str4, 2));

	printf("[-] Test with EMPTY STRING [-]\n");
	ft_bzero(str5, 1);
	bzero(str6, 1);
	printf("[-] mine: %s || origin: %s || ex : op || size : 1 : compare : %d[-]\n", str5, str6, strncmp(str5, str6, 1));

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
	
	int		int1[2] = {21, 42};
	int		int2[2] = {21, 42};

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

	char	dst1[8] = "";
	char	dst2[8] = "";
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

void	check_strmap(void)
{
	char	str1[5] = "aBcD";
	char	str2[5] = "";
	char	(*func)(char) = check_strmap_inverse_alpha;

	printf("[+] STRMAP [+]\n");
	printf("[-] The function here will inverse the alphabet [-]\n");
	printf("[-] mine: %s || ex : %s [-]\n", ft_strmap(str1, func), str1);
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || ex : %s [-]\n", ft_strmap(str2, func), str2);
	printf("[+] END OF STRMAP [+]\n\n");
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

void	check_strequ(void)
{
	char	str1[5] = "ABCD";
	char	str2[5] = "ABCD";
	char	str3[5] = "ABCD";
	char	str4[5] = "abcd";
	char	str5[5] = "abc";
	char	str6[5] = "abcd";
	char	str7[5] = "";
	char	str8[5] = "";

	printf("[+] STREQU [+]\n");

	printf("[-] mine: %d || ex : %s || %s || compare : %d[-]\n",
			ft_strequ(str1, str2), str1, str2, strncmp(str1, str2, 5));
	printf("[-] mine: %d || ex : %s || %s || compare : %d[-]\n",
			ft_strequ(str3, str4), str3, str4, strncmp(str3, str4, 5));
	printf("[-] mine: %d || ex : %s || %s || compare : %d[-]\n",
			ft_strequ(str5, str6), str5, str6, strncmp(str5, str6, 5));
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %d || ex : %s || %s || compare : %d[-]\n",
			ft_strequ(str7, str8), str7, str8, strncmp(str7, str8, 1));

	printf("[+] END OF STREQU [+]\n\n");
}

void	check_strnequ(void)
{
	char	str1[5] = "ABCD";
	char	str2[5] = "ABCD";
	char	str3[5] = "ABCD";
	char	str4[5] = "abcd";
	char	str5[5] = "abc";
	char	str6[5] = "abcd";
	char	str7[5] = "";
	char	str8[5] = " ";
	char	str9[5] = "";
	char	str10[5] = "";

	printf("[+] STRNEQU [+]\n");

	printf("[-] mine: %d || ex : %s || %s || size : 5 || compare : %d[-]\n",
			ft_strnequ(str1, str2, 5), str1, str2, strncmp(str1, str2, 5));
	printf("[-] mine: %d || ex : %s || %s || size : 1 || compare : %d[-]\n",
			ft_strnequ(str3, str4, 1), str3, str4, strncmp(str3, str4, 1));
	printf("[-] mine: %d || ex : %s || %s || size : 3 || compare : %d[-]\n",
			ft_strnequ(str5, str6, 3), str5, str6, strncmp(str5, str6, 3));
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %d || ex : %s || %s || size : 0 || compare : %d[-]\n",
			ft_strnequ(str7, str8, 0), str7, str8, strncmp(str7, str8, 0));
	printf("[-] mine: %d || ex : %s || %s || size : 1 || compare : %d[-]\n",
			ft_strnequ(str9, str10, 1), str9, str10, strncmp(str9, str10, 1));

	printf("[+] END OF STRNEQU [+]\n\n");
}

void	check_strtrim(void)
{
	char	str1[7] = "  ABCD";
	char	str2[7] = "ABCD  ";
	char	str3[5] = "ABCD";
	char	str4[8] = " ab cd ";
	char	str5[1] = "";
	char	str6[3] = "  ";

	printf("[+] STRTRIM [+]\n");

	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str1), str1, strcmp(ft_strtrim(str1), "ABCD"));
	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str2), str2, strcmp(ft_strtrim(str2), "ABCD"));
	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str3), str3, strcmp(ft_strtrim(str3), "ABCD"));
	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str4), str4, strcmp(ft_strtrim(str4), "ab cd"));
	
	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str5), str5, strcmp(ft_strtrim(str5), ""));
	printf("[-] mine: %s || ex : %s || compare : %d[-]\n",
			ft_strtrim(str6), str6, strcmp(ft_strtrim(str6), ""));

	printf("[+] END OF STRTRIM [+]\n\n");
}

void	check_itoa(void)
{
	int int1 = 107;
	int int2 = 0;
	int int3 = -2147483648;
	int int4 = -5;


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

void	check_strstr(void)
{
	char	str1[5] = "abcd";
	char	str2[3] = "bc";
	char	str3[9] = "hehecett";
	char	str4[5] = "hece";
	char	str5[6] = "where";
	char	str6[5] = "erea";

	printf("[+] STRSTR [+]\n");
	printf("[-] mine: %s || origin: %s : s1: %s|| s2:%s || compare: %d[-]\n",
			ft_strstr(str1, str2), strstr(str1, str2), str1, str2,
			strcmp(ft_strstr(str1, str2), strstr(str1, str2)));
	printf("[-] mine: %s || origin: %s : s1: %s|| s2:%s || compare: %d[-]\n",
			ft_strstr(str3, str4), strstr(str3, str4), str3, str4,
			strcmp(ft_strstr(str3, str4), strstr(str3, str4)));
	printf("[-] origin:  : s1: %s || s2: %s || result : %s[-]\n",
			str5, str6, ((ft_strstr(str5, str6) == NULL) ? "NULL" : "NOT NULL"));

	printf("[-] Test with EMPTY STRING [-]\n");
	printf("[-] origin:  : s1: %s || s2: %s || result : %s[-]\n",
			"", "", ((ft_strstr("", "") == NULL) ? "NULL" : "NOT NULL"));
	printf("[+] END OF STRSTR [+]\n");
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
int     main(int argc, char **argv)
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

	check_memset();
	check_bzero();
	check_memcpy();
	check_memccpy();
	check_memmove();
	check_memchr();
	check_memcmp();
	check_toupper();
	check_tolower();
	check_strmap();
	check_strmapi();
	check_strequ();
	check_strnequ();
	check_strtrim();
	check_itoa();
*/
	check_memccpy();
}
