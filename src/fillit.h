/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:43:49 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/10 18:49:03 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../includes/libft/get_next_line.h"
# include <stdio.h>

typedef struct		s_lst
{
	int				per;
	int				n;
	int				y;
	int				len;
	int				kol;
	int				a;
	int				k;
	int				i;
	int				p_x;
	int				p_y;
	int				go;
	int				j;
	int				good;
	int				f_0;
	int				tmp;
}					t_lst;
int					proof(int kol, int mas[kol][4][2]);
int					mod(int a, int b);
void				zapoln(t_lst lst, int ***matrix, int mas[4][2], int x);
int					resh(t_lst lst, int **(*matrix)[lst.kol],
	int (*bukv)[lst.kol], int f);
void				vivod(int kol, int **matrix[kol], int a);
int					error(void);
int					skolk(t_lst lst, int **(*matrix)[lst.kol],
	int mas[4][2], int i);
int					fre(int kol, int **(*matrix)[kol], int k);
int					fre_dop(t_lst lst,
	int **(*matrix)[lst.kol], int k, int len);
int					check(int fd, char ***line, int kol, int i);
int					check_n(int fd, char *str, char ***line, int i);
int					free_str(char **str);
int					usage(void);
int					razm(int mas[4][2], int n);
void				x_y(int *x, int *y, int kol, int mas[kol][4][2]);

#endif
