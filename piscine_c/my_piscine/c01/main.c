void ft_swap(int *a, int *b);
void ft_putnbr(int nb);
void ft_ft(int *nb);
void ft_putchar(char c);
void ft_ultimate_ft(int *********nbr);
void ft_putstr(char *str);
void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int x = 10;
	int *p1;
	int **p2;
	int ***p3;
	int ****p4;
	int *****p5;
	int ******p6;
	int *******p7;
	int ********p8;
	int *********p9;
	p1 = &x;
	p2 = &p1;
	p3 = &p2;
p4 = &p3;	

p5 = &p4;
	p6 = &p5;
	p7 = &p6;	

	p8 = &p7;
	p9 = &p8;	
	
	ft_ultimate_ft(p9);	
	ft_putnbr(x);
/*
	char string[23] = "i am not your king!!";
	ft_putstr(string);
*
*
*
*
*/ 





	return 0;

}
