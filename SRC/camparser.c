/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:04:33 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:04:37 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		*cameramaker(void)
{
	t_camera	*cam;

	if (!(cam = (t_camera*)malloc(sizeof(t_camera))))
		malloc_error();
	if (!(cam->point = (t_coord*)malloc(sizeof(t_coord))))
		malloc_error();
	if (!(cam->vector = (t_coord*)malloc(sizeof(t_coord))))
		malloc_error();
	return (cam);
}

t_scene			*camera_parser(char *start, t_scene *scene)
{
	t_camera	*cam;

	cam = cameramaker();
	if (*(++start) != ' ')
		rt_error();
	*cam->point = coord_parser(&start);
	if (*start != ' ')
		rt_error();
	*cam->vector = coord_parser(&start);
	vectorvalidator(*cam->vector);
	if (*start != ' ' || (cam->fov = atoi_rt(&start)) < 0 || cam->fov > 180)
		rt_error();
	while (*start != '\0')
	{
		if (*start != ' ')
			rt_error();
		start++;
	}
	cam->ca_img = NULL;
	scene->cams = ft_add_item_circ(scene->cams, cam);
	return (scene);
}
