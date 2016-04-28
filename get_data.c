/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 08:46:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/28 15:28:45 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game	*get_data(char c, char *param)
{
	char	*line;
	int		i;
	t_game	*filler;

	line = NULL;
	filler = (t_game*)malloc(sizeof(t_game));
	filler->coordmap = coord_map(param);
	get_next_line(0, &line);
	filler->map = init_map(filler->coordmap);
	get_next_line(0, &line);
	filler->coordpiece = coord_map(line);
	i = -1;
	filler->piece = (char**)malloc(sizeof(char*) * (filler->coordpiece[0] + 1));
	while (++i < filler->coordpiece[0])
	{
		get_next_line(0, &line);
		filler->piece[i] = ft_strjoin(line, "");
	}
	filler->piece[i] = NULL;
	filler->c = c;
	return (filler);
}

char	ncar(char c)
{
	return ((c == 'o') ? 'x': 'o');
}

int		piece_ok(int i, int j, t_game *filler)
{
	int nb_superpose;
	int	k;
	int	l;

	nb_superpose = 0;
	l = -1;
	while (++l < filler->coordpiece[0])
	{
		k = -1;
		while (++k < filler->coordpiece[1])
		{
			if (filler->piece[l][k] == '*')
			{
				if ((l + i) < 0 || (k + j) < 0
					|| (l + i) >= filler->coordmap[0]
						|| (k + j) >= filler->coordmap[1]
							|| ft_tolower(filler->map[l + i][k + j]) == ncar(filler->c))
					return (0);
				else if (ft_tolower(filler->map[l + i][k + j]) == filler->c)
					if (++nb_superpose > 1)
						return (0);
			}
		}
	}
	if (nb_superpose == 1)
		return (1);
	return (0);
}

int		w_p(char *p, int i, int j)
{
	int	k;

	k = -1;
	while (p[++k])
		p[k] = '\0';
	ft_strcpy(p, ft_itoa(i));
	ft_strcat(p, " ");
	ft_strcat(p, ft_itoa(j));
	ft_strcat(p, "\n");
	return (1);
}

int		set_p(char *p, t_game *filler)
{
	int	i;
	int	j;

	i = filler->coordpiece[0] * -1;
	while (++i < filler->coordmap[0])
	{
		j = filler->coordpiece[1] * -1;
		while (++j < filler->coordmap[1])
		{
			if (piece_ok(i, j, filler))
				return (w_p(p, i, j));
		}
	}
	ft_strcpy(p, "0 0\n");
	return (0);
}
