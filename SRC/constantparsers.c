/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantparsers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:19:15 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 23:19:22 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*resol_parser(char *start, t_scene *scene)
{
	if (scene->res)
		rt_error();
	if (!(scene->res = (t_crd*)malloc(sizeof(t_crd))))
		malloc_error();
	if (*(++start) == ' ')
	{
		if ((scene->res->x = atoi_rt(&start)) > 0)
		{
			if ((scene->res->y = atoi_rt(&start)) > 0)
			{
				while (*start != '\0')
				{
					if (*start != ' ')
						rt_error();
					start++;
				}
				return (scene);
			}
		}
	}
	rt_error();
	return (scene);
}

t_scene		*light_parser(char *start, t_scene *scene)
{
	if (scene->amb)
		rt_error();
	if (!(scene->amb = (t_light*)malloc(sizeof(t_light))))
		malloc_error();
	if (*(++start) != ' ' || (scene->amb->ratio = rd_parser(&start)) ==
	-10000.0 || scene->amb->ratio < 0 || scene->amb->ratio > 1)
		rt_error();
	if (*(start++) == ' ')
	{
		if (!(scene->amb->rgb = (t_colour*)malloc(sizeof(t_colour))))
			malloc_error();
		*scene->amb->rgb = colour_parser(&start);
		return (scene);
	}
	rt_error();
	return (scene);
}
