/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:09:31 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/10 18:09:33 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mod(int a, int b)
{
	if (a >= b)
		return (a - b + 1);
	else
		return (b - a + 1);
}

int		error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		razm(int mas[4][2], int n)
{
	int x;
	int i;
	int k;

	x = 1;
	i = 4;
	while ((k = --i) > 0)
		while (--k >= 0)
			if (mod(mas[k][n], mas[i][n]) > x)
				x = mod(mas[k][n], mas[i][n]);
	return (x);
}

int		skolk(t_lst lst, int **(*matrix)[lst.kol], int mas[4][2], int i)
{
	int x;
	int y;
	int k;

	x = razm(mas, 0);
	y = razm(mas, 1);
	k = (lst.a - x + 1) * (lst.a - y + 1) + 1;
	if (!((*matrix)[i] = (int **)malloc(sizeof(int *) * k)))
		return (fre(lst.kol, matrix, i + 1));
	lst.len = k - 1;
	while (--k >= 0)
		if (!((*matrix)[i][k] = (int *)malloc(sizeof(int) *
			(lst.a * lst.a + lst.kol))))
			return (fre_dop(lst, matrix, i, k));
	lst.p_x = 0;
	lst.p_y = 0;
	zapoln(lst, &(*matrix)[i], mas, lst.a - x + 1);
	return (1);
}

int		fre(int kol, int **(*matrix)[kol], int k)
{
	int i;
	int f;
	int b;

	f = -1;
	while (++f < k)
	{
		i = -1;
		b = 0;
		while (1)
		{
			if ((*matrix)[f][++i][0] == 3)
				b = 1;
			free((*matrix)[f][i]);
			if (b)
				break ;
		}
		free((*matrix)[f]);
	}
	return (-1);
}
