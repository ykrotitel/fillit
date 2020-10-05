/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:17:20 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/06 19:17:21 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	zapoln(t_lst lst, int ***matrix, int mas[4][2], int x)
{
	lst.i = -1;
	while (++(lst.i) < lst.len)
	{
		lst.k = -1;
		while (++(lst.k) < lst.a * lst.a + lst.kol)
			(*matrix)[lst.i][lst.k] = 0;
	}
	lst.i = -1;
	while (++(lst.i) < lst.len)
	{
		lst.k = -1;
		while (++(lst.k) < 4)
			(*matrix)[lst.i][(mas[lst.k][1] + lst.p_y)
				* lst.a + mas[lst.k][0] + lst.p_x] = 1;
		lst.go = lst.a * lst.a - 1;
		while (++(lst.go) < lst.a * lst.a + lst.kol)
			(*matrix)[lst.i][lst.go] = 2;
		lst.p_x++;
		if (lst.p_x == x)
			lst.p_y++;
		if (lst.p_x == x)
			lst.p_x = 0;
	}
	(*matrix)[lst.i][0] = 3;
}

int		prov(int kol, int **(*matrix)[kol], int a, int f)
{
	t_lst lst;

	f++;
	lst.f_0 = f;
	lst.i = -1;
	while ((*matrix)[f][++(lst.i)][0] != 3)
	{
		lst.good = 0;
		lst.k = a * a - 1;
		while (++(lst.k) < a * a + kol)
			if ((*matrix)[f][lst.i][lst.k] != 2)
				(lst.good)++;
		if (lst.good == 0 && f == lst.f_0)
			lst.tmp = lst.i;
		if (lst.good == 0 && f < kol - 1)
		{
			f++;
			lst.i = -1;
		}
		if (lst.i != -1 && lst.good == 0 && f == kol - 1)
			break ;
	}
	if (lst.good == 0 && f == kol - 1)
		return (lst.tmp);
	return (-1);
}

void	find(t_lst lst, int **(*matrix)[lst.kol], int f, int n)
{
	int i;
	int f_0;

	f_0 = f;
	while (++f < lst.kol)
	{
		i = -1;
		while ((*matrix)[f][++i][0] != 3)
		{
			if ((*matrix)[f][i][lst.k] == 1)
				(*matrix)[f][i][lst.a * lst.a + f_0] = n;
		}
	}
}

int		last(int **matrix, int a, int kol)
{
	int k;

	k = a * a - 1;
	while (++k < a * a + kol)
		if ((*matrix)[k] == -2)
			return (0);
	return (1);
}

int		resh(t_lst lst, int **(*matrix)[lst.kol],
int (*bukv)[lst.kol], int f)
{
	lst.i = -1;
	while ((*matrix)[f][++(lst.i)][0] != 3)
	{
		if (last(&(*matrix)[f][lst.i], lst.a, lst.kol))
		{
			lst.k = -1;
			while (++(lst.k) < lst.a * lst.a)
				if ((*matrix)[f][lst.i][lst.k] == 1)
					find(lst, matrix, f, -2);
			(*bukv)[f] = lst.i;
			if (prov(lst.kol, matrix, lst.a, f) >= 0 && f == lst.kol - 2)
			{
				(*bukv)[lst.kol - 1] = prov(lst.kol, matrix, lst.a, f);
				return (1);
			}
			if (prov(lst.kol, matrix, lst.a, f) >= 0 &&
			f < lst.kol - 1 && resh(lst, matrix, bukv, f + 1))
				return (1);
			lst.k = -1;
			while (++(lst.k) < lst.a * lst.a)
				if ((*matrix)[f][lst.i][lst.k] == 1)
					find(lst, matrix, f, 2);
		}
	}
	return (0);
}
