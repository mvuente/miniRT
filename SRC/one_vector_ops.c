/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_vector_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:52:29 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:52:33 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord		ft_vctr(t_coord a, t_coord b)
{
	t_coord res;

	res.x = b.x - a.x;
	res.y = b.y - a.y;
	res.z = b.z - a.z;
	return (res);
}

double		vector_mod(t_coord a)
{
	double	res;

	res = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
	return (res);
}

t_coord		normalizer(t_coord a)
{
	double	mod;

	if (!(mod = vector_mod(a)))
	{
		write(1, "divide by 0\n", 12);
		exit(1);
	}
	a.x = a.x / mod;
	a.y = a.y / mod;
	a.z = a.z / mod;
	return (a);
}

t_coord		minusvector(t_coord b)
{
	t_coord	a;

	a.x = -b.x;
	a.y = -b.y;
	a.z = -b.z;
	return (a);
}

t_coord		normalcrtr(t_coord vector)
{
	t_coord	normal;

	normal.x = 1;
	normal.y = 1;
	normal.z = 1;
	if (vector.x)
		normal.x = (-vector.y - vector.z) / vector.x;
	else if (vector.y)
		normal.y = (-vector.x - vector.z) / vector.y;
	else
		normal.z = (-vector.y - vector.x) / vector.z;
	return (normalizer(normal));
}
