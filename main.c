/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:26 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/27 11:59:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	verif(char **map)
{
	int	i;
	int		fd;

	i = -1;
	fd = open("verif", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	while (map[++i])
	{
		write(fd, map[i], ft_strlen(map[i]));
		write(fd, "\n", 1);
	}
	close(fd);
}

int		main(void)
{
	char	*line;
	int		cont;
	int		i;
	int		*tab;
	char	**map;
	char	**piece;
	char	c;

	c = 'p';
	line = NULL;
	get_next_line(0, &line);
	if (line && !ft_strcmp(line, "$$$ exec p1 : [./filler]"))
		c = 'o';
	else
		c = 'x';
	cont = 1;
	while (cont)
	{
		get_next_line(0, &line);
		if (!ft_strncmp(line, "Plateau", 7))
		{
			tab = coord_map(line);
			get_next_line(0, &line);
			map = init_map(tab);
			get_next_line(0, &line);
			tab = coord_map(line);
			i = 0;
			piece = (char**)malloc(sizeof(char*) * (tab[0] + 1));
			while (i < tab[0])
				get_next_line(0, &piece[i++]);
			piece[tab[0]] = NULL;
			verif(piece);
		}
	}
	while (1)
	{
		write(1, "5 12\n", 5);
	}
	return (0);
}
