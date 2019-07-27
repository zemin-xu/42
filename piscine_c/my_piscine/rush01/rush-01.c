/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibouroi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:48:56 by mibouroi          #+#    #+#             */
/*   Updated: 2019/06/16 21:03:37 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int tab_all[24][4] = {{1,2,3,4},{1,2,4,3},{1,3,4,2},{2,3,4,1},{2,1,3,4},{2,3,1,4},{1,3,2,4},{1,4,2,3}, {1,4,3,2}, {2,1,4,3},{2,4,1,3},{2,4,3,1},{3,1,2,4},{3,1,4,2},{3,2,1,4},{3,2,4,1},{3,4,1,2},{3,4,2,1},{4,1,2,3},{4,1,3,2},{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1}};

int	*p_lib = &tab_all[0][0];
int		show_possibility(int nb)
{
	if(nb == 4)
		return (1);
	else if (nb == 3)
		return (6);
	else if (nb == 2)
		return (11);
	else if (nb == 1)
		return (6);
	else
		return (0);
}
int		position(int param)
{
	if(param == 4)
		return (1);
	if(param == 3)
		return (2);
	if(param == 2)
		return (8);
	if(param == 1)
		return (19);
	else
		return (0);
}
int		*show_one_line(int *tab, int index)
{
	return (tab + (index - 1) * 4);
}

int		all_solution(int *tab_params, int *p_lib, int *all)
{
	int i,j,k,l;
	int total = 0;
	i = j = k = l = 0;
	int	max = 14641;

	int *buffer;
	buffer = (int*)malloc (max*16* sizeof(int));
	while(i < show_possibility(*(tab_params+0)))
	{
		while(j < show_possibility(*(tab_params+1)))
		{
			while(k < show_possibility(*(tab_params+2)))
			{
				while(l < show_possibility(*(tab_params+3)))
				{
					for(int m = 0; m<4; m++)
						*(buffer + total*16 + m) = *(show_one_line((p_lib + 4 * position(*(tab_params + 0))), i) + m);
					for(int m = 4; m<8; m++)
						*(buffer + total*16 + m) = *(show_one_line((p_lib + 4 * position(*(tab_params + 1))), j) + m -4);
					for(int m = 8; m<12; m++)
						*(buffer + total*16 + m) = *(show_one_line((p_lib + 4 * position(*(tab_params + 2))), k) + m - 8);
					for(int m = 12; m<16; m++)
						*(buffer + total*16 + m) = *(show_one_line((p_lib + 4 * position(*(tab_params + 3))), l) + m - 12);
					total++;
					l++;
				}
				k++;
				l = 0;
			}
			j++;
			k = 0;
			l = 0;
		}	
		i++;
		j = 0;
		k = 0;
		l = 0;
	}
	for(int q = 0; q < total; q++)
	{
		for(int r = 0; r< 16; r++)
		{
			*(all + q * 16 + r) = *(buffer + q * 16 + r);
		}
	}
	return (total);
}
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	has_sorted;

	while(1)
	{
		has_sorted = 0;
		i = 0;
		while (i < size - 1)
		{
			if(*(tab + i) > *(tab + i + 1))
			{

				ft_swap((tab + i), (tab + i +1));
				has_sorted = 1;
			}
			i++;
		}
		if (has_sorted == 0)
			break;
	}
}
int		total_is_1234(int *src, int count, int *res)
{
	int *buffer = (int*)malloc(count * 4 * 4 * sizeof(int));
	int counter = 0;	
	int flag;
	for(int m = 0; m < count; m++)
	{
		flag = 0;
		for(int i = 0; i < 4; i++)
		{
			*(buffer + m * 16 + 4 * i + 0) = *(src + m * 16 + 4 * i+ 0);	
			*(buffer + m * 16 + 4 * i + 1) = *(src + m* 16 + 4 * i+ 1);	
			*(buffer + m * 16 + 4 * i + 2) = *(src + m* 16 + 4 * i+ 2);	
			*(buffer + m * 16 + 4 * i + 3) = *(src + m* 16 + 4 * i+ 3);	
			ft_sort_int_tab((buffer + m* 16 + 4 * i), 4);
			if( *(buffer + m* 16 + 4 * i) == 1 && *(buffer + m* 16 + 4 * i + 1) == 2
					&& *(buffer + m* 16 + 4 * i + 2) == 3 && *(buffer + m* 16 + 4 * i + 3) == 4)	
			{
				flag++;
			}
		}
		if(flag == 4)
		{
			for(int j = 0; j < 16; j++)
			{
				*(res + counter * 16 + j) = *(src + m * 16 + j);
			}
			counter++;
		}
	}
	return (counter);
}

int			selection_left(int *all, int count, int *lib, int * tab_params)
{
	int *buffer = (int*)malloc(count*16* sizeof(int)); 

	for(int i = 0; i<count; i++)
	{
		int counter = 0;
		for(int j = 0; j< 13; j+= 4,counter++)
			*(buffer + i * 16 + counter) = *(all + i * 16 + j);			

		for(int j = 1; j< 14; j+= 4,counter++)
			*(buffer + i * 16 + counter) = *(all + i * 16 + j);			

		for(int j = 2; j< 15; j+= 4,counter++)
			*(buffer + i * 16 + counter) = *(all + i * 16 + j);			

		for(int j = 3; j< 16; j+= 4,counter++)
			*(buffer + i * 16 + counter) = *(all + i * 16 + j);			
	}

	int *new = (int*)malloc(count * 16 * sizeof(int));
	int	new_count = total_is_1234(buffer, count, new);

	for(int i = 0; i< new_count; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			*(all + i * 16 + j) = *(new + i * 16 + j);
		}
	}
	return (new_count);
}

void		*str_transform(char *str, int *tab)
{
	int	i;
	int	flag;

	flag = 0;	
	i = 0;
	while (str[i])
	{
		if (flag == 1 && str[i] <= '4' && str[i] >= '1')
		{
			*(tab + i) = (int)(str[i] - '0');
			flag = 0;		
		}	
		else if(str[i]== ' ')
		{
			flag = 1;
		}
		i++;
	}	

	return (tab);
}
int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '+' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		{
			if (str[i] == '-')
				sign *= -1;
			else if (str[i] >= '0' && str[i] <= '9')
				result = result * 10 + str[i] - '0';
			else
				return (result * sign);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{

	(void)argc;
	int i;

	i = 1;
	int tab_params[argc - 1];
	while (argv[i])
	{
		tab_params[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	int count;
	int *all = (int *)malloc(14641* 16 * sizeof(int));
	count = all_solution(tab_params, p_lib,all);

	for(int q = 0; q < count; q++)
	{
		for(int r = 0; r< 16; r++)
		{
			printf(" %d  ", *(all+ q* 16 +r));
		}
		printf("\nchange line : %d\n" ,q);
	}
	printf("total : %d\n", count);


	free(all);
	return 0;


}
