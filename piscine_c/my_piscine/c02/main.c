#include <stdio.h>
#include <string.h>
void ft_swap(int *a, int *b);
void ft_putnbr(int nb);
void ft_ft(int *nb);
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_sort_int_tab(int *tab, int size);
unsigned int 	ft_strlcpy(char *dest, char *src, unsigned int size);
int main(void)
{
	char str1[] = "I abc";
	char str2[] = "I abc";
	
	char str3[] = "dsaffasgnaslkgnalkfnsalfasf";
	printf("%s\n", str1);
	printf("%s\n", str3);

	ft_strlcpy(str3,str2,10);

	for(int i = 0 ; i<10;i++)
	{
		printf("str1[%d] : %d\n",i,str1[i]);

		printf("str3[%d] : %d\n",i, str3[i]);
	}


	return 0;

}
