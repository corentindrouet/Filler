/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:14:26 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/27 10:01:58 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		main(void)
{
	char	*line;
//	int		fd;
	char	c;

	c = 'p';
	line = NULL;
//	fd = open("verif", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	get_next_line(0, &line);
	if (line && !ft_strcmp(line, "$$$ exec p1 : [./filler]"))
		c = 'o';
	else
		c = 'x';
//	write(fd, &c, 1);
	write(1, "5 12", 4);
	return (0);
}
