/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaginarium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:49:21 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 11:49:25 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord		viewpoint(t_crd *spt, t_scene *scene)
{
	scene->vpoint.x = ((2 * spt->x - scene->res->x) * tan(
		M_PI * scene->current_ca->fov / 360) / scene->res->x);
	scene->vpoint.y = ((scene->res->y - 2 * spt->y) * tan(
		M_PI * scene->current_ca->fov / 360) / scene->res->x);
	return (scene->vpoint);
}

void		my_mlx_pixel_put(t_data *data, char *addr, t_crd *spt, int color)
{
	char	*dst;

	dst = addr + (spt->y * data->line_length + spt->x * (data->bits_per_pixel /
	8));
	*(unsigned int*)dst = color;
}

int			filler_img_by_pixels(t_vars var, t_img *new_img)
{
	t_crd	*spt;

	if (!(spt = (t_crd*)malloc(sizeof(t_crd))))
		malloc_error();
	spt->y = 0;
	while (spt->y++ < var.scene->res->y - 1)
	{
		spt->x = 0;
		while (spt->x++ < var.scene->res->x - 1)
		{
			my_mlx_pixel_put(var.imgdet, new_img->addr, spt, clrmaker(var.scene,
			viewpoint(spt, var.scene)));
		}
	}
	free(spt);
	return (0);
}

t_vars		new_img_crtr(int flag, t_vars var)
{
	t_img	*new_image;

	if (scene_newcam_prep(var.scene, flag))
		return (var);
	if (!(new_image = (t_img*)malloc(sizeof(t_img))))
		malloc_error();
	if (!(new_image->img = mlx_new_image(var.mlx, var.scene->res->x,
	var.scene->res->y)))
		mlx_error();
	new_image->addr = mlx_get_data_addr(new_image->img,
	&var.imgdet->bits_per_pixel, &var.imgdet->line_length,
	&var.imgdet->endian);
	if (!filler_img_by_pixels(var, new_image))
	{
		var.scene->current_ca->ca_img = new_image;
		var.scene->cams->cam = var.scene->current_ca;
	}
	return (var);
}
