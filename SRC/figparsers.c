/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figparsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:45:25 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 11:45:30 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene			*spot_parser(char *start, t_scene *scene)
{
	t_figure	spot;

	spot.id = "l";
	if (*(++start) != ' ')
		rt_error();
	spot.point = coord_parser(&start);
	if (*start != ' ' || (spot.size = rd_parser(&start)) < 0 || spot.size > 1)
		rt_error();
	spot.rgb = colour_parser(&start);
	scene->spo = ft_add_item(scene->spo, spot);
	return (scene);
}

t_scene			*plain_parser(char *start, t_scene *scene)
{
	t_figure	fig;

	fig.id = "pl";
	start++;
	if (*(++start) != ' ')
		rt_error();
	fig.point = coord_parser(&start);
	if (*(start++) != ' ')
		rt_error();
	fig.vector = coord_parser(&start);
	vectorvalidator(fig.vector);
	if (*(start++) != ' ')
		rt_error();
	fig.rgb = colour_parser(&start);
	scene->obj = ft_add_item(scene->obj, fig);
	return (scene);
}

t_scene			*triangle_parser(char *start, t_scene *scene)
{
	t_figure	fig;

	fig.id = "tr";
	start++;
	if (*(++start) != ' ')
		rt_error();
	fig.point = coord_parser(&start);
	if (*(start++) != ' ')
		rt_error();
	fig.pt2 = coord_parser(&start);
	if (*(start++) != ' ')
		rt_error();
	fig.pt3 = coord_parser(&start);
	if (*(start++) != ' ')
		rt_error();
	fig.rgb = colour_parser(&start);
	scene->obj = ft_add_item(scene->obj, fig);
	return (scene);
}

t_scene			*square_parser(char *start, t_scene *scene)
{
	t_figure	fig;

	fig.id = "pls";
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
	fig.rgb = colour_parser(&start);
	scene->obj = ft_add_item(scene->obj, fig);
	return (scene);
}
