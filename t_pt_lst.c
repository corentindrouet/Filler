/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 09:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/04 14:15:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pt	*new_pt(int x, int y)
{
	t_pt	*new;

	new = (t_pt*)malloc(sizeof(t_pt));
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void	add_end_lst(t_pt **lst, t_pt *new)
{
	t_pt	*tmp;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int		power(int nb, int p)
{
	int	tmp;

	tmp = nb;
	while (p-- > 1)
		nb *= tmp;
	return (nb);
}

int		recur_dist(t_pt *all_pos, t_game *filler)
{
	int	i;
	int	j;
	int	tmp;

	if (!all_pos)
		return (1);
	all_pos->dist = power(filler->adv->x - all_pos->x, 2) +
		power(filler->adv->y - all_pos->y, 2);
	i = -1;
	while (++i < filler->coordpiece[0])
	{
		j = -1;
		while (++j < filler->coordpiece[1])
		{
			tmp = power(filler->adv->x - (all_pos->x + i), 2) +
				power(filler->adv->y - (all_pos->y + j), 2);
			if (filler->piece[i][j] == '*' && tmp < all_pos->dist)
				all_pos->dist = tmp;
		}
	}
	return (recur_dist(all_pos->next, filler));
}

int		opti_filler(char *p, t_game *filler, t_pt *all_pos)
{
	t_pt	*ret;

	recur_dist(all_pos, filler);
	ret = lowest_len(all_pos);
	return (w_p(p, ret->x, ret->y));
}
