/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:16 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 20:50:26 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix		*rotmatrixmaker(void)
{
	t_matrix	*rtr;

	if (!(rtr = (t_matrix*)malloc(sizeof(t_matrix))))
		malloc_error();
	if (!(rtr->row1 = (t_coord*)malloc(sizeof(t_coord))))
		malloc_error();
	if (!(rtr->row2 = (t_coord*)malloc(sizeof(t_coord))))
		malloc_error();
	if (!(rtr->row3 = (t_coord*)malloc(sizeof(t_coord))))
		malloc_error();
	return (rtr);
}

t_matrix		*rotmatrix(t_coord *vector)
{
	t_matrix	*rtr;
	double		calf;
	double		cbet;
	double		y;

	y = vector->y;
	if (vector->z < 0)
		y = -y;
	rtr = rotmatrixmaker();
	calf = sqrt(pow(vector->z, 2) + pow(vector->y, 2));
	if (vector->z < 0)
		calf = -calf;
	cbet = sqrt(pow(vector->x, 2) + pow(vector->z, 2));
	rtr->row1->x = calf;
	rtr->row2->y = cbet;
	rtr->row3->z = calf * cbet;
	rtr->row1->y = -y * vector->x;
	rtr->row1->z = -vector->x * cbet;
	rtr->row2->x = 0;
	rtr->row2->z = -y;
	rtr->row3->x = vector->x;
	rtr->row3->y = calf * y;
	return (rtr);
}

t_coord			rotation(t_matrix *rotor, t_coord a)
{
	t_coord		res;

	res.x = ft_dot(*rotor->row1, a);
	res.y = ft_dot(*rotor->row2, a);
	res.z = ft_dot(*rotor->row3, a);
	return (res);
}

t_figure		figrotor(t_matrix *rotor, t_figure fig, t_coord *point)
{
	fig.point = rotation(rotor, vector_sum(fig.point, minusvector(*point)));
	if (!ft_memcmp("pls", fig.id, 3))
	{
		fig.peaks.a = rotation(rotor, vector_sum(fig.peaks.a,
		minusvector(*point)));
		fig.peaks.b = rotation(rotor, vector_sum(fig.peaks.b,
		minusvector(*point)));
		fig.peaks.c = rotation(rotor, vector_sum(fig.peaks.c,
		minusvector(*point)));
		fig.peaks.d = rotation(rotor, vector_sum(fig.peaks.d,
		minusvector(*point)));
	}
	if (ft_memcmp("sp", fig.id, 2) && ft_memcmp("l", fig.id, 1))
		fig.vector = rotation(rotor, fig.vector);
	if (!ft_memcmp("tr", fig.id, 2))
	{
		fig.pt2 = rotation(rotor, vector_sum(fig.pt2, minusvector(*point)));
		fig.pt3 = rotation(rotor, vector_sum(fig.pt3, minusvector(*point)));
	}
	return (fig);
}

t_scene			*scenerotor(t_scene *scene)
{
	t_matrix	*rotor;
	t_list		*temp;

	rotor = rotmatrix(scene->current_ca->vector);
	temp = scene->obj;
	while (temp)
	{
		temp->fig = figrotor(rotor, temp->fig, scene->current_ca->point);
		temp = temp->next;
	}
	temp = scene->spo;
	while (temp)
	{
		temp->fig = figrotor(rotor, temp->fig, scene->current_ca->point);
		temp = temp->next;
	}
	free(rotor->row1);
	free(rotor->row2);
	free(rotor->row3);
	free(rotor);
	return (scene);
}
