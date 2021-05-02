/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorscalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:22:15 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:22:20 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	channelcalculator(t_scene *scene, int i)
{
	double		res;
	t_list		*tmp;

	res = scene->amb->ratio * *(&scene->amb->rgb->red + i) / 255;
	tmp = scene->spo;
	while (tmp)
	{
		res = res + tmp->fig.size * tmp->fig.height * *(&tmp->fig.rgb.red
		+ i) / 255;
		tmp = tmp->next;
	}
	if (res > 1)
		return (1);
	return (res);
}

int		clrtransf(t_colour *rgb, t_scene *scene)
{
	char		*c;
	int			colour;

	if (!(c = (char*)malloc(4)))
		malloc_error();
	c[2] = (unsigned char)(rgb->red * channelcalculator(scene, 0));
	c[1] = (unsigned char)(rgb->green * channelcalculator(scene, 1));
	c[0] = (unsigned char)(rgb->blue * channelcalculator(scene, 2));
	c[3] = 0;
	colour = *(int*)c;
	free(c);
	return (colour);
}

int		clrmaker(t_scene *scene, t_coord vpoint)
{
	t_bord		bord;
	double		t;
	t_list		*temp;
	t_figure	closest;
	char		flag;

	flag = 'n';
	bord.xmin = 1;
	bord.xmax = INT_MAX;
	temp = scene->obj;
	while (temp)
	{
		if (bord.xmax > (t = ray_pars(temp->fig, *scene->current_ca->point,
		vpoint, bord)))
		{
			bord.xmax = t;
			closest = temp->fig;
			flag = 'y';
		}
		temp = temp->next;
	}
	if (flag == 'n')
		return (scene->back);
	return (clrtransf(&closest.rgb, l_pars(closest, scene, vpoint, bord.xmax)));
}
