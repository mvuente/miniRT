/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsparsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:02:19 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 15:02:22 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			rd_parser(char **start)
{
	double		res;

	while (**start == ' ')
		(*start)++;
	res = atof_rt(start);
	if (**start != ' ')
		return (FLT_MIN);
	else
		return (res);
}

t_coord			coord_parser(char **ptr)
{
	t_coord		point;

	while (**ptr == ' ')
		(*ptr)++;
	if ((point.x = atof_rt(ptr)) == FLT_MIN || **ptr != ',')
		rt_error();
	(*ptr)++;
	if ((point.y = atof_rt(ptr)) == FLT_MIN || **ptr != ',')
		rt_error();
	(*ptr)++;
	if ((point.z = atof_rt(ptr)) == FLT_MIN)
		rt_error();
	return (point);
}

t_colour		colour_parser(char **start)
{
	t_colour	rgb;
	int			res;

	while (**start != '\0' && **start == ' ')
		(*start)++;
	if ((res = atoi_clr(start)) == -1 || **start != ',')
		rt_error();
	rgb.red = (unsigned char)res;
	(*start)++;
	if ((res = atoi_clr(start)) == -1 || **start != ',')
		rt_error();
	rgb.green = (unsigned char)res;
	(*start)++;
	if ((res = atoi_clr(start)) == -1)
		rt_error();
	rgb.blue = (unsigned char)res;
	while (**start != '\0')
	{
		if (**start != ' ')
			rt_error();
		(*start)++;
	}
	return (rgb);
}
