/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosspoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:09:48 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 10:09:54 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	cross_pls(t_figure fig, t_coord point, t_coord vpoint, double t)
{
	t_coord	cross;
	double	sum;

	cross = linear(point, vpoint, t);
	if ((sum = pnt_ln_dst_sq(cross, fig.peaks.a, fig.peaks.b,
	fig.peaks.d)) <= (fig.size + 0.0000001) && (sum = pnt_ln_dst_sq(cross,
	fig.peaks.b, fig.peaks.c, fig.peaks.a)) <= (fig.size + 0.0000001))
		return (t);
	return (FLT_MAX);
}

double	cross_tri(t_figure fig, t_coord point, t_coord vpoint, double t)
{
	t_coord	cross;
	double	sum;

	cross = linear(point, vpoint, t);
	if ((sum = (ft_gerone(cross, fig.point, fig.pt2) + ft_gerone(cross,
	fig.pt2, fig.pt3) + ft_gerone(cross, fig.pt3, fig.point))
	<= (ft_gerone(fig.point, fig.pt2, fig.pt3) + 0.0000001)))
		return (t);
	return (FLT_MAX);
}

double	cross_cyl(t_figure fig, t_coord point, t_coord vpoint, double t)
{
	t_coord	cross;
	t_coord	c1;
	double	sum;

	if (!ft_memcmp("sp", fig.id, 2))
		return (t);
	cross = linear(point, vpoint, t);
	c1 = linear(fig.point, fig.vector, fig.height);
	if ((sum = fabs(ft_dot(fig.vector, ft_vctr(fig.point, cross))) + fabs(
		ft_dot(minusvector(fig.vector), ft_vctr(c1, cross)))) <=
		fig.height + 0.0000001)
		return (t);
	return (FLT_MAX);
}
