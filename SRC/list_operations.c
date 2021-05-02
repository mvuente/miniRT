/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:06:40 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:06:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*ft_create_item(t_figure data)
{
	t_list	*item;

	if (!(item = (t_list*)malloc(sizeof(t_list))))
		malloc_error();
	item->next = NULL;
	item->fig = data;
	return (item);
}

t_list	*ft_add_item(t_list *fig, t_figure data)
{
	t_list	*tmp;

	if (!fig)
		return (ft_create_item(data));
	tmp = fig;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_item(data);
	return (fig);
}

void	ft_add_item_front(t_list **current, t_list *new)
{
	new->next = *current;
	*current = new;
}

void	listmove(t_list *dst, t_list *src)
{
	t_list	*tmpd;
	t_list	*tmps;

	tmpd = dst;
	tmps = src;
	while (tmpd)
	{
		ft_memmove(&tmpd->fig, &tmps->fig, sizeof(t_figure));
		tmpd = tmpd->next;
		tmps = tmps->next;
	}
	return ;
}
