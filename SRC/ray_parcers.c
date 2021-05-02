/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_parcers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:32 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 14:00:34 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ray_pars(t_figure fig, t_coord point, t_coord vpoint, t_bord bord)
{
	if (!(ft_memcmp("sp", fig.id, 2)) || !(ft_memcmp("cy", fig.id, 2)))
		return (c_eq_sp_cyl(fig, point, vpoint, bord));
	else if (!(ft_memcmp("pl", fig.id, 2)) || !(ft_memcmp("tr", fig.id, 2)))
		return (c_eq_pl(fig, point, vpoint, bord));
	return (0);
}

t_scene		*l_pars(t_figure fig, t_scene *scene, t_coord vpoint, double t)
{
	t_list	*tmp;
	t_coord	pcross;

	pcross = linear(*scene->current_ca->point, vpoint, t);
	if (!(ft_memcmp("sp", fig.id, 2)) || !(ft_memcmp("cy", fig.id, 2)))
	{
		tmp = scene->spo;
		while (tmp)
		{
			scene = pcomp_sp(fig, &tmp->fig, scene, pcross);
			tmp = tmp->next;
		}
	}
	else if (!(ft_memcmp("pl", fig.id, 2)) || !(ft_memcmp("tr", fig.id, 2)))
	{
		tmp = scene->spo;
		while (tmp)
		{
			scene = pcomp_pl(fig, &tmp->fig, scene, pcross);
			tmp = tmp->next;
		}
	}
	return (scene);
}
