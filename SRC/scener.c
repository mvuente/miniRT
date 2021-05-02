/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:58:10 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 20:58:23 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*initial(t_vars var)
{
	var.scene->res = NULL;
	var.scene->current_ca = NULL;
	var.scene->cams = NULL;
	var.scene->amb = NULL;
	var.scene->spo = NULL;
	var.scene->spo_base = NULL;
	var.scene->obj = NULL;
	var.scene->obj_base = NULL;
	var.scene->back = 0;
	var.scene->vpoint.z = 1;
	var.scene->vpoint.x = 0;
	var.scene->vpoint.y = 0;
	mlx_get_screen_size(var.mlx, &var.scene->res_sys.x, &var.scene->res_sys.y);
	return (var.scene);
}

t_scene		*scenemake(t_vars var, char *rt)
{
	char	*line;
	int		fd;
	int		bytes;

	var.scene = initial(var);
	fd = open(rt, O_RDONLY);
	while ((bytes = gnl(fd, &line)) >= 0)
	{
		var.scene = parser(line, var.scene);
		free(line);
		if (bytes == 0)
			break ;
	}
	close(fd);
	scenevalidator(var.scene);
	return (var.scene);
}

t_scene		*base_state_prep(t_scene *scene)
{
	t_list	*tmp;

	scene->obj_base = NULL;
	tmp = scene->obj;
	while (tmp)
	{
		if (!(scene->obj_base = ft_add_item(scene->obj_base, tmp->fig)))
			return (NULL);
		tmp = tmp->next;
	}
	scene->spo_base = NULL;
	tmp = scene->spo;
	while (tmp)
	{
		if (!(scene->spo_base = ft_add_item(scene->spo_base, tmp->fig)))
			return (NULL);
		tmp = tmp->next;
	}
	return (scene);
}

t_scene		*scenenormalizer(t_scene *scene)
{
	t_list	*tmp;

	if (!scene->obj)
		return (scene);
	tmp = scene->obj;
	while (tmp)
	{
		if (!(ft_memcmp("pl", tmp->fig.id, 2)) || !(ft_memcmp("cy",
			tmp->fig.id, 2)))
			tmp->fig.vector = normalizer(tmp->fig.vector);
		else if (!(ft_memcmp("tr", tmp->fig.id, 2)))
			tmp->fig.vector = normalizer(vectormult(ft_vctr(tmp->fig.point,
				tmp->fig.pt3), ft_vctr(tmp->fig.point, tmp->fig.pt2)));
		tmp = tmp->next;
	}
	return (scene);
}

t_vars		general_scene_prep(t_vars var, char *rt)
{
	var.scene = scenemake(var, rt);
	var.scene->obj = sqchecker(var.scene->obj);
	var.scene = scenenormalizer(var.scene);
	if (!(var.scene = base_state_prep(var.scene)))
		malloc_error();
	if (!(var.imgdet = (t_data*)malloc(sizeof(t_data))))
		malloc_error();
	return (var);
}
