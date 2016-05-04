/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:55:03 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/04 14:13:31 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		lst_len(t_pt *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_pt	*lowest_len(t_pt *lst)
{
	t_pt	*ret;

	ret = lst;
	lst = lst->next;
	while (lst)
	{
		if (ret->dist > lst->dist)
			ret = lst;
		lst = lst->next;
	}
	return (ret);
}
