/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:08:23 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 14:08:26 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow_check(t_coord pcross, t_coord lvector, t_scene *scene)
{
	t_list	*tmp;
	double	t;
	t_bord	bord;

	bord.xmax = 1;
	bord.xmin = 0.0000001;
	tmp = scene->obj;
	while (tmp)
	{
		if ((t = ray_pars(tmp->fig, pcross, lvector, bord)) > 0.0000001 &&
		t < 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
