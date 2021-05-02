/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circparsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:14:57 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:15:02 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene			*cylinder_parser(char *start, t_scene *scene)
{
	t_figure	fig;

	fig.id = "cy";
	if (*(++start) != ' ')
		rt_error();
	fig.point = coord_parser(&start);
	if (*(start++) != ' ')
		rt_error();
	fig.vector = coord_parser(&start);
	vectorvalidator(fig.vector);
	if (*(start++) != ' ')
		rt_error();
	if ((fig.size = atof_rt(&start)) < 0 || fig.size == FLT_MAX)
		rt_error();
	if (*(start++) != ' ')
		rt_error();
	if ((fig.height = atof_rt(&start)) < 0 || fig.height == FLT_MAX)
		rt_error();
	if (*(start++) != ' ')
		rt_error();
	fig.rgb = colour_parser(&start);
	scene->obj = ft_add_item(scene->obj, fig);
	return (scene);
}

t_scene			*sphere_parser(char *start, t_scene *scene)
{
	t_figure	fig;

	start++;
	fig.id = "sp";
	if (*(++start) != ' ')
		rt_error();
	fig.point = coord_parser(&start);
	if (*(++start) != ' ')
		rt_error();
	if ((fig.size = atof_rt(&start)) < 0 || fig.size == FLT_MAX)
		rt_error();
	if (*(++start) != ' ')
		rt_error();
	fig.rgb = colour_parser(&start);
	scene->obj = ft_add_item(scene->obj, fig);
	return (scene);
}
