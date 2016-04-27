/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:26 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/27 15:54:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	int		i;
	int		fd;
	t_game	filler;

	filler.c = 'p';
	line = NULL;
	get_next_line(0, &line);
	filler.c = init_char(line);
	get_next_line(0, &line);
	filler.coordmap = coord_map(line);
	get_next_line(0, &line);
	filler.map = init_map(filler.coordmap);
	get_next_line(0, &line);
	filler.coordpiece = coord_map(line);
	i = 0;
	filler.piece = (char**)malloc(sizeof(char*) * (filler.coordpiece[0] + 1));
	while (i < filler.coordpiece[0])
		get_next_line(0, &(filler.piece[i++]));
	filler.piece[i] = NULL;
	write(1, "5 12\n", 5);
	fd = open("iverif", O_RDWR /*| O_TRUNC */| O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	fill(&filler, line, fd);
	close(fd);
	return (0);
}
