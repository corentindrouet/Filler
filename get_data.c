/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 08:46:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/28 13:34:56 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game	*get_data(char c, char *param, int fd)
{
	char	*line;
	int		i;
	t_game	*filler;

	line = NULL;
	(void)fd;
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

void	set_p(char *p, t_game *filler)
{
	(void)filler;
	p[3]++;
}
