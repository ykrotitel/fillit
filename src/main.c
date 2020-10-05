/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:48:39 by vabraham          #+#    #+#             */
/*   Updated: 2019/10/24 14:44:43 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_0(char ***line, int i)
{
	while (--i >= 0)
		free((*line)[i]);
	free(*line);
	return (error());
}

int		figure_0(t_lst *lst, int ch)
{
	if (!lst->per && ch != 4 && ch != 0)
		return (0);
	lst->per = 0;
	(lst->y)--;
	return (1);
}

int		figure(char **line, int i, int mas[4][2], int ch)
{
	t_lst lst;

	lst.per = 0;
	lst.n = -1;
	lst.y = 3;
	while (--i >= 0 && line[i][0])
	{
		lst.k = -1;
		while (line[i][++(lst.k)])
			if (line[i][lst.k] == '#')
			{
				if (ch++ > 4 || (lst.n >= 0 && mas[lst.n][1] == lst.y &&
				mas[lst.n][0] - lst.k != 1 && lst.k - mas[lst.n][0] != 1))
					return (0);
				if (i != 0 && line[i - 1][lst.k] == '#')
					lst.per = 1;
				mas[++(lst.n)][1] = lst.y;
				mas[lst.n][0] = lst.k;
			}
			else if (line[i][lst.k] != '.')
				return (0);
		if (!figure_0(&lst, ch))
			return (0);
	}
	return (ch != 4 ? 0 : 1);
}

int		check(int fd, char ***line, int kol, int i)
{
	int		st;
	int		res;
	int		ch;
	int		mas[kol][4][2];

	st = 0;
	ch = 0;
	while ((res = get_next_line(fd, &(*line)[++i])) >= 0)
	{
		if (res != 0 && ((ft_strlen((*line)[i]) != 4
			&& (*line)[i][0]) || st > 4))
			return (free_0(line, i));
		if (res != 0 && !(*line)[i][0] && (st != 4 ||
		(i > 0 && (*line)[i - 1][0] && !figure(*line, i, mas[ch++], 0))))
			return (free_0(line, i + 1));
		if (res != 0 && !(*line)[i][0])
			st = -1;
		if (res == 0 && (st != 4 || ((*line)[i - 1][0]
		&& !figure(*line, i, mas[ch++], 0))))
			return (free_0(line, i));
		if (res == 0)
			break ;
		st++;
	}
	return (proof(kol, mas));
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**line;
	char	*str;

	if (argc == 1)
		return (usage());
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
		return (error());
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		i++;
		if ((!*str && i == 1) || ft_strlen(str) > 4)
			return (free_str(&str));
		free(str);
	}
	if (i < 4 || i > 4 * 26 + 25 ||
	!*str || !(line = (char **)malloc(sizeof(char *) * (i + 1))))
		return (error());
	line[i] = NULL;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	return (!check_n(fd, argv[1], &line, i) ? error() : 0);
}
