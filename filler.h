/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:13:07 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/28 13:35:04 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_game
{
	char		**map;
	char		**piece;
	int			*coordmap;
	int			*coordpiece;
	char		c;
}				t_game;

int		*coord_map(char *line);
char	**init_map(int *tab);
char	init_char(char *str);
void	set_p(char *p, t_game *filler);
t_game	*get_data(char c, char *param, int fd);

#endif
