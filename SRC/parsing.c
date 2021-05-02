/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:59:34 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:59:37 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*add_parser(char *start, t_scene *scene)
{
	if (*start == 'c' && *(start + 1) == 'y')
		return (cylinder_parser(start + 1, scene));
	else if (*start == 'c' && *(start + 1) == ' ')
		return (camera_parser(start, scene));
	else if (*start == 's' && *(start + 1) == 'p')
		return (sphere_parser(start, scene));
	else if (*start == 's' && *(start + 1) == 'q')
		return (square_parser(start + 1, scene));
	else
		rt_error();
	return (scene);
}

t_scene		*parser(char *start, t_scene *scene)
{
	if (*start == 'R')
		return (resol_parser(start, scene));
	else if (*start == 'A')
		return (light_parser(start, scene));
	else if (*start == 'l')
		return (spot_parser(start, scene));
	else if (*start == 'p')
		return (plain_parser(start, scene));
	else if (*start == 't')
		return (triangle_parser(start, scene));
	else if (*start == 'c' || *start == 's')
		return (add_parser(start, scene));
	else if (*start == '\0')
		return (scene);
	else
		rt_error();
	return (scene);
}
