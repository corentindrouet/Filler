/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_recur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:19:13 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/27 15:54:19 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill(t_game *filler, char *line, int fd)
{
	int		i;
	char	**tmp;

	if (!line)
		return (0);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	free(line);
	i = -1;
	while (++i < filler->coordmap[0])
	{
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
//		write(fd, filler->map[i], ft_strlen(filler->map[i]));
//		write(fd, "|-|", 3);
//		write(fd, tmp[1], ft_strlen(tmp[1]));
//		write(fd, "\n", 1);
		ft_strcpy(filler->map[i], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		free(line);
	}
	i = -1;
	while (++i < filler->coordpiece[0])
		free(filler->piece[i]);
	free(filler->piece);
	get_next_line(0, &line);
	free(filler->coordpiece);
	filler->coordpiece = coord_map(line);
	free(line);
	filler->piece = (char**)malloc(sizeof(char*) * (filler->coordpiece[0] + 1));
	i = -1;
	while (++i < filler->coordpiece[0])
		get_next_line(0, &(filler->piece[i]));
	filler->piece[filler->coordpiece[0]] = NULL;
	write(1, "5 13\n", 5);
	return (fill(filler, line, fd));
}
