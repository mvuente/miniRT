/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:28:46 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 20:29:27 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ft_min_more_than_min(double min, double max, double y, double z)
{
	if (y < min)
		y = 2147483647.0;
	if (z < min)
		z = 2147483647.0;
	if (max < y)
	{
		if (max < z)
			return (max);
		return (z);
	}
	else
	{
		if (y < z)
			return (y);
		return (z);
	}
}

double		ft_gerone(t_coord a, t_coord b, t_coord c)
{
	double	p;

	p = (vector_mod(ft_vctr(a, b)) + vector_mod(ft_vctr(b, c)) +
	vector_mod(ft_vctr(a, c))) / 2;
	return (sqrt(p * (p - vector_mod(ft_vctr(a, b))) * (p -
	vector_mod(ft_vctr(b, c))) * (p - vector_mod(ft_vctr(a, c)))));
}

double		pnt_ln_dst_sq(t_coord cross, t_coord a, t_coord b, t_coord d)
{
	t_coord avector;
	t_coord lvector;
	double	x;
	double	y;

	avector = ft_vctr(b, a);
	lvector = vectormult(avector, ft_vctr(cross, a));
	x = vector_mod(lvector) / vector_mod(avector);
	lvector = vectormult(avector, ft_vctr(cross, d));
	y = vector_mod(lvector) / vector_mod(avector);
	return (x + y);
}
