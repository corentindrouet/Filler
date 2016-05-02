/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:57:22 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/02 13:42:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	init_char(char *str)
{
	return ((str && !ft_strcmp(str, "$$$ exec p1 : [./filler]")) ? 'o' : 'x');
}

int		*coord_map(char *line)
{
	int		*tab;
	char	**split;
	int		i;

	tab = (int*)malloc(sizeof(int) * 2);
	split = ft_strsplit(line, ' ');
	tab[0] = ft_atoi(split[1]);
	tab[1] = ft_atoi(split[2]);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (tab);
}

char	**init_map(int *tab)
{
	char	**map;
	char	*line;
	char	**split;
	int		i;

	map = (char**)malloc(sizeof(char*) * (tab[0] + 1));
	i = 0;
	while (i < tab[0])
		map[i++] = ft_strnew(tab[1] + 1);
	map[i] = NULL;
	i = -1;
	while (++i < tab[0])
	{
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		ft_strcpy(map[i], split[1]);
		free(split[0]);
		free(split[1]);
		free(split);
		free(line);
	}
	return (map);
}

t_pt	*search_player(char c, char **map, int *coordmap)
{
	int		i;
	int		j;
	t_pt	*coo;

	coo = (t_pt*)malloc(sizeof(t_pt));
	i = -1;
	while (++i < coordmap[0])
	{
		j = -1;
		while (++j < coordmap[1])
			if (map[i][j] == c)
			{
				coo->x = i;
				coo->y = j;
				coo->next = NULL;
			}
	}
	return (NULL);
}
