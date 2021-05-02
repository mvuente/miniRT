/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:03:33 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:03:37 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_installer(t_scene *scene, int flag)
{
	if (flag)
		scene->cams = move_listcirc(scene->cams, flag);
	return (scene->cams->cam);
}

int			scene_newcam_prep(t_scene *scene, int flag)
{
	scene->current_ca = camera_installer(scene, flag);
	if (scene->current_ca->ca_img)
		return (1);
	*scene->current_ca->vector = normalizer(*scene->current_ca->vector);
	listmove(scene->obj, scene->obj_base);
	listmove(scene->spo, scene->spo_base);
	scene = scenerotor(scene);
	scene->current_ca->point->x = 0;
	scene->current_ca->point->y = 0;
	scene->current_ca->point->z = 0;
	return (0);
}
