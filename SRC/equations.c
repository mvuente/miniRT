/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:16:52 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 10:17:10 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_equat	*equation_cyl(t_figure fig, t_coord point, t_coord vpoint)
{
	t_equat	*coeff;

	if (!(coeff = (t_equat*)malloc(sizeof(t_equat))))
		return (NULL);
	if (!(coeff->k1 = ft_dot(linear(vpoint, fig.vector,
	-ft_dot(vpoint, fig.vector)), linear(vpoint, fig.vector,
	-ft_dot(vpoint, fig.vector)))))
		return (NULL);
	coeff->k2 = 2 * ft_dot(linear(vpoint, fig.vector, -ft_dot(vpoint,
	fig.vector)), linear(ft_vctr(fig.point, point),
	fig.vector, -ft_dot(fig.vector, ft_vctr(fig.point, point))));
	coeff->k3 = ft_dot(linear(ft_vctr(fig.point, point),
	fig.vector, -ft_dot(fig.vector, ft_vctr(fig.point, point))),
	linear(ft_vctr(fig.point, point), fig.vector, -ft_dot(fig.vector,
	ft_vctr(fig.point, point)))) - pow(fig.size / 2, 2);
	return (coeff);
}

t_equat	*equation_sp_cyl(t_figure fig, t_coord point, t_coord vpoint)
{
	t_equat	*coeff;

	if (ft_memcmp("sp", fig.id, 2))
		return (equation_cyl(fig, point, vpoint));
	if (!(coeff = (t_equat*)malloc(sizeof(t_equat))))
		return (NULL);
	if (!(coeff->k1 = ft_dot(vpoint, vpoint)))
		return (NULL);
	coeff->k2 = 2 * ft_dot(ft_vctr(fig.point, point),
	vpoint);
	coeff->k3 = ft_dot(ft_vctr(fig.point, point), ft_vctr(fig.point,
	point)) - pow(fig.size, 2) / 4;
	return (coeff);
}

double	c_eq_sp_cyl(t_figure fig, t_coord point, t_coord vpoint, t_bord bord)
{
	t_equat	*coeff;
	double	t1;
	double	t2;
	double	dscr;

	t1 = -1;
	t2 = -1;
	if (!(coeff = equation_sp_cyl(fig, point, vpoint)))
		return (bord.xmax);
	if ((dscr = pow(coeff->k2, 2) - 4 * coeff->k1 * coeff->k3) >= 0)
	{
		if ((t1 = (-coeff->k2 + sqrt(dscr)) / 2 / coeff->k1) >= bord.xmin && t1
		< bord.xmax)
			t1 = cross_cyl(fig, point, vpoint, t1);
		if ((t2 = (-coeff->k2 - sqrt(dscr)) / 2 / coeff->k1) >= bord.xmin && t2
		< bord.xmax)
			t2 = cross_cyl(fig, point, vpoint, t2);
	}
	free(coeff);
	return (ft_min_more_than_min(bord.xmin, bord.xmax, t1, t2));
}

double	c_eq_pl(t_figure fig, t_coord point, t_coord vpoint, t_bord bord)
{
	double	znam;
	double	chisl;
	double	tnew;

	chisl = ft_dot(ft_vctr(point, fig.point), fig.vector);
	if (!(znam = ft_dot(vpoint, fig.vector)))
		return (2147483647.0);
	if ((tnew = chisl / znam) >= bord.xmin && tnew < bord.xmax)
	{
		bord.xmax = tnew;
		if (!(ft_memcmp(fig.id, "pls", 3)))
			return (cross_pls(fig, point, vpoint, bord.xmax));
		else if (!(ft_memcmp(fig.id, "tr", 2)))
			return (cross_tri(fig, point, vpoint, bord.xmax));
	}
	return (bord.xmax);
}
