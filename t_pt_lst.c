/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pt_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 09:59:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/29 14:04:50 by cdrouet          ###   ########.fr       */
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
