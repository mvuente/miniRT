/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:55:51 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 11:55:54 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*pcomp_sp(t_figure fig, t_figure *spot, t_scene *scene,
			t_coord pcross)
{
	t_coord	lvector;
	t_coord	nvector;
	double	chisl;

	lvector = ft_vctr(pcross, spot->point);
	if (!(ft_memcmp("sp", fig.id, 2)))
		nvector = normalizer(ft_vctr(fig.point, pcross));
	else
		nvector = normalizer(ft_vctr(linear(fig.point, fig.vector, fabs(
			ft_dot(fig.vector, ft_vctr(fig.point, pcross)))), pcross));
	if (ft_dot(nvector, minusvector(scene->vpoint)) < 0)
		nvector = minusvector(nvector);
	chisl = ft_dot(nvector, lvector);
	if (chisl < 0 || shadow_check(pcross, lvector, scene))
	{
		spot->height = 0;
		return (scene);
	}
	spot->height = chisl / (vector_mod(nvector) * vector_mod(lvector));
	return (scene);
}

t_scene		*pcomp_pl(t_figure fig, t_figure *spot, t_scene *scene,
t_coord pcross)
{
	t_coord	lvector;
	double	chisl;
	double	znam;

	lvector = ft_vctr(pcross, spot->point);
	if ((chisl = ft_dot(fig.vector, lvector)) < 0 || shadow_check(pcross,
	lvector, scene))
	{
		spot->height = 0;
		return (scene);
	}
	if (!(znam = vector_mod(lvector)))
		return (NULL);
	spot->height = chisl / znam;
	return (scene);
}
