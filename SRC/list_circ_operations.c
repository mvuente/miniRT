/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_circ_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:02:50 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:02:54 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_listcirc	*ft_create_item_circ(t_listcirc *fig, t_listcirc *tmp,
t_camera *data)
{
	t_listcirc	*item;

	if (!(item = (t_listcirc*)malloc(sizeof(t_listcirc))))
		return (NULL);
	if (!(fig))
	{
		item->nextf = NULL;
		item->nextb = NULL;
		item->cam = data;
	}
	else
	{
		item->nextf = fig;
		fig->nextb = item;
		item->nextb = tmp;
		item->cam = data;
	}
	return (item);
}

t_listcirc	*ft_add_item_circ(t_listcirc *fig, t_camera *data)
{
	t_listcirc	*tmp;
	t_listcirc	*debg;

	tmp = NULL;
	if (!fig)
		return (ft_create_item_circ(fig, fig, data));
	tmp = fig;
	while (tmp->nextf && tmp->nextf != fig)
		tmp = tmp->nextf;
	if (!(tmp->nextf = ft_create_item_circ(fig, tmp, data)))
		return (NULL);
	debg = fig->nextf;
	return (fig);
}

t_listcirc	*move_listcirc(t_listcirc *fig, int flag)
{
	if (!fig->nextf)
		return (fig);
	if (flag == 1)
		return (fig = fig->nextf);
	return (fig->nextb);
}
