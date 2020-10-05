/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:43:21 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/05 21:43:25 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		output(int kol, int **(matrix)[kol], int bukv[kol], int a)
{
	t_lst	lst;
	int		r;
	int		k;
	char	c;

	lst.i = -1;
	lst.j = 0;
	while (++(lst.i) < a * a)
	{
		r = lst.j;
		k = -1;
		while (++k < kol)
			if (matrix[k][bukv[k]][lst.i] == 1)
			{
				(lst.j)++;
				c = 65 + k;
				write(1, &c, 1);
				break ;
			}
		if (r == lst.j)
			write(1, ".", 1);
		if ((lst.i + 1) % a == 0)
			write(1, "\n", 1);
	}
	return (kol);
}

int		algoritm_x(t_lst lst, int mas[lst.kol][4][2], int r)
{
	int		**matrix[lst.kol];
	int		bukv[lst.kol];
	int		i;

	lst.k = 0;
	while (1)
	{
		i = -1;
		while (++i < lst.kol)
			if (skolk(lst, &matrix, mas[i], i) == -1)
				return (error());
		if (lst.kol == 1)
			bukv[0] = 0;
		if (lst.kol == 1)
			break ;
		else
			r = resh(lst, &matrix, &bukv, 0);
		if (r)
			break ;
		else if (!r)
			fre(lst.kol, &matrix, lst.kol);
		lst.a++;
	}
	fre(output(lst.kol, matrix, bukv, lst.a), &matrix, lst.kol);
	return (1);
}

int		storona(int kol)
{
	int s;

	s = 2;
	while (1)
	{
		if (s * s >= kol * 4)
			return (s);
		s++;
	}
	return (s);
}

void	sdvig(int mas[4][2], int n)
{
	int i;

	i = -1;
	while (++i < 4)
		mas[i][n]--;
}

int		proof(int kol, int mas[kol][4][2])
{
	int		i;
	t_lst	lst;
	int		x;
	int		y;

	lst.a = 0;
	lst.kol = kol;
	i = -1;
	while (++i < kol)
		if (mas[i][0][0] != 0 && mas[i][1][0] != 0
		&& mas[i][2][0] != 0 && mas[i][3][0] != 0)
			sdvig(mas[i--], 0);
		else if (mas[i][0][1] != 0 && mas[i][1][1] != 0
		&& mas[i][2][1] != 0 && mas[i][3][1] != 0)
			sdvig(mas[i--], 1);
	lst.a = storona(kol);
	x = 0;
	y = 0;
	x_y(&x, &y, kol, mas);
	while (lst.a < x || lst.a < y)
		(lst.a)++;
	algoritm_x(lst, mas, 1);
	return (1);
}
