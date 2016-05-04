/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:13:07 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/04 14:16:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_pt
{
	int			x;
	int			y;
	int			dist;
	struct s_pt	*next;
}				t_pt;

typedef struct	s_game
{
	char		**map;
	char		**piece;
	int			*coordmap;
	int			*coordpiece;
	char		c;
	t_pt		*adv;
}				t_game;

int				opti_filler(char *p, t_game *filler, t_pt *all_pos);
t_pt			*lowest_len(t_pt *lst);
int				lst_len(t_pt *lst);
t_pt			*search_player(char c, char **map, int *coordmap);
int				*coord_map(char *line);
char			**init_map(int *tab);
char			init_char(char *str);
int				set_p(char *p, t_game *filler);
t_game			*get_data(char c, char *param);
int				w_p(char *p, int i, int j);
int				piece_ok(int i, int j, t_game *filler);
void			add_end_lst(t_pt **lst, t_pt *new);
t_pt			*new_pt(int x, int y);

#endif
