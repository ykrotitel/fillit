/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:38:13 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/10 19:38:21 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_line(char ***line, int i)
{
	while (--i >= 0)
		free((*line)[i]);
	free(*line);
	return (0);
}

int		check_n(int fd, char *str, char ***line, int i)
{
	char c;
	char s;

	while (read(fd, &c, 1) > 0)
		s = c;
	if (s != '\n')
	{
		free(*line);
		return (0);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (check(fd, line, (i - 4) / 5 + 1, -1))
		free_line(line, i + 1);
	close(fd);
	return (1);
}

int		fre_dop(t_lst lst, int **(*matrix)[lst.kol], int i, int k)
{
	(lst.len)++;
	while (++k < lst.len)
		free((*matrix)[i][k]);
	return (fre(lst.kol, matrix, i + 1));
}

int		free_str(char **str)
{
	free(*str);
	return (error());
}

int		usage(void)
{
	write(1, "usage: ./fillit <filename>\n", 27);
	return (-1);
}
