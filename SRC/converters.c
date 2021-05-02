/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:23:50 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 23:23:56 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list		*sqchecker(t_list *obj)
{
	t_list		*tmp;
	t_list		*newlist;

	tmp = obj;
	newlist = obj;
	while (tmp)
	{
		if (!ft_memcmp(tmp->fig.id, "pls", 3))
		{
			tmp->fig.vector = normalizer(tmp->fig.vector);
			tmp->fig.peaks = point_to_peak(&tmp->fig);
		}
		tmp = tmp->next;
	}
	return (newlist);
}

t_peak		point_to_peak(t_figure *fig)
{
	t_coord		diagonal1;
	t_coord		diagonal2;
	t_peak		peaks;

	diagonal1 = normalcrtr(fig->vector);
	diagonal2 = vectormult(fig->vector, diagonal1);
	diagonal2 = normalizer(diagonal2);
	peaks.a = linear(fig->point, diagonal1, fig->size / sqrt(2));
	peaks.c = linear(fig->point, diagonal1, -fig->size / sqrt(2));
	peaks.b = linear(fig->point, diagonal2, fig->size / sqrt(2));
	peaks.d = linear(fig->point, diagonal2, -fig->size / sqrt(2));
	return (peaks);
}
