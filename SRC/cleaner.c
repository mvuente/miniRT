/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:33:58 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/23 11:34:02 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	listcirccleaner(t_listcirc *list)
{
	t_listcirc	*tmp;
	t_listcirc	*todel;
	t_listcirc	*prev;

	todel = list;
	tmp = list;
	prev = list->nextb;
	if (prev)
		prev->nextf = NULL;
	while (tmp)
	{
		tmp = tmp->nextf;
		free(todel);
		todel = tmp;
	}
	return ;
}

void	listcleaner(t_list *list)
{
	t_list	*tmp;
	t_list	*todel;

	todel = list;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		free(todel);
		todel = tmp;
	}
	return ;
}

void	cleaner(t_scene *scene)
{
	free(scene->res);
	free(scene->current_ca);
	if (scene->amb)
		free(scene->amb);
	listcirccleaner(scene->cams);
	listcleaner(scene->spo);
	listcleaner(scene->spo_base);
	listcleaner(scene->obj);
	listcleaner(scene->obj_base);
	free(scene);
	return ;
}
