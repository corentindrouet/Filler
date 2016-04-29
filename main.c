/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:26 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/29 11:12:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_filler(t_game **filler)
{
	t_game	*tmp;
	int		i;

	tmp = *filler;
	i = -1;
	while (++i < tmp->coordmap[0])
		free(tmp->map[i]);
	free(tmp->map);
	i = -1;
	while (++i < tmp->coordpiece[0])
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
	char	p[20];
	char	c;
	char	*co;
	t_game	*filler;

	c = 'p';
	line = NULL;
	get_next_line(0, &co);
	c = init_char(co);
	ft_strcpy(p, "5 11\n");
	while (get_next_line(0, &line))
		if (ft_strlen(line) > 0)
		{
			filler = get_data(c, line);
			set_p(p, filler);
			free_filler(&filler);
			write(1, p, ft_strlen(p));
		}
	return (0);
}
