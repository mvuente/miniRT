/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_vector_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:11:47 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 14:11:49 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ft_dot(t_coord a, t_coord b)
{
	double		res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

t_coord		vector_sum(t_coord a, t_coord b)
{
	t_coord		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_coord		linear(t_coord o, t_coord v, double t)
{
	t_coord		res;

	res.x = o.x + t * v.x;
	res.y = o.y + t * v.y;
	res.z = o.z + t * v.z;
	return (res);
}

t_coord		vectormult(t_coord a, t_coord b)
{
	t_coord		mult;

	mult.x = a.y * b.z - a.z * b.y;
	mult.y = a.z * b.x - a.x * b.z;
	mult.z = a.x * b.y - a.y * b.x;
	return (mult);
}
