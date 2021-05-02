/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:03:48 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 15:03:51 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vectorvalidator(t_coord point)
{
	if (point.x < -1 || point.x > 1 || point.y < -1 || point.y > 1 ||
		point.z < -1 || point.z > 1)
		rt_error();
	return ;
}

void	scenevalidator(t_scene *scene)
{
	if (!scene->res || !scene->cams)
		rt_error();
	if (!scene->amb)
	{
		if (!(scene->amb = (t_light*)malloc(sizeof(t_light))))
			malloc_error();
		scene->amb->ratio = 0;
		if (!(scene->amb->rgb = (t_colour*)malloc(sizeof(t_colour))))
			malloc_error();
		scene->amb->rgb->red = 0;
		scene->amb->rgb->green = 0;
		scene->amb->rgb->blue = 0;
	}
	if (scene->res->x > scene->res_sys.x)
		scene->res->x = scene->res_sys.x;
	if (scene->res->y > scene->res_sys.y)
		scene->res->y = scene->res_sys.y;
	return ;
}
