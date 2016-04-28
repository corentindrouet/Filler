/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:26 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/28 13:41:35 by cdrouet          ###   ########.fr       */
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

void	free_filler(t_game **filler)
{
	t_game	*tmp;
	int		i;

	tmp = *filler;
	i = -1;
	while (tmp->map[++i])
		free(tmp->map[i]);
	free(tmp->map);
	i = -1;
	while (tmp->piece[++i])
		free(tmp->piece[i]);
	free(tmp->piece);
	free(tmp->coordmap);
	free(tmp->coordpiece);
	free(tmp);
	(*filler) = NULL;
}

int		main(void)
{
	char	*line;
	char	p[10];
	char	c;
	char	*co;
	int fd;
	t_game	*filler;

	fd = open("verif", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	c = 'p';
	line = NULL;
	get_next_line(0, &co);
	c = init_char(co);
	ft_strcpy(p, "5 11\n");
	while (get_next_line(0, &line))
	{
		if (ft_strlen(line) > 0)
		{
			filler = get_data(c, line, fd);
			free_filler(&filler);
			set_p(p, filler);
			write(1, p, ft_strlen(p));
//			while (get_next_line(0, &line))
		}
	}
	close(fd);
	return (0);
}
