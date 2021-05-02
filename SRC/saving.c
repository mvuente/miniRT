/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:03:28 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 14:03:30 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			writer(void *smth, int count)
{
	int		fd;

	if ((fd = open("the_scene.bmp", O_RDWR | O_CREAT | O_APPEND, S_IRWXU))
	== -1)
		oc_error();
	write(fd, smth, count);
	if (close(fd) == -1)
		oc_error();
	return (1);
}

void		color_to_take(t_img *img, t_data *data, t_crd *size)
{
	int		x;
	int		y;
	int		clr;

	y = size->y-1;
	while (y >= 0)
	{
		x = 0;
		while (x < size->x)
		{
			clr = *(unsigned int*)(img->addr + (y * data->line_length +
				x * (data->bits_per_pixel / 8)));
			writer(&clr, 4);
			x++;	
		}
		y--;	
	}
	return ;
}

void		headersaver(t_crd *size)
{
	int		i_field;
	short	s_field;

	s_field = 0x4D42;
	writer(&s_field, 2);
	i_field = 14 + 40 + 4 * (size->y) * (size->x);
	writer(&i_field, 4);
	i_field = 0x00000000;
	writer(&i_field, 4);
	i_field = 14 + 40;
	writer(&i_field, 4);
	return ;
}

int			scsaver(t_img *img, t_data *data, t_crd *size)
{
	int		i_field;
	short	s_field;
	int		i;

	i = 6;
	headersaver(size);
	i_field = 40;
	writer(&i_field, 4);
	i_field = size->x;
	writer(&i_field, 4);
	i_field = size->y;
	writer(&i_field, 4);
	s_field = 0x0001;
	writer(&s_field, 2);
	s_field = 0x0020;
	writer(&s_field, 2);
	i_field = 0;
	
	while (i-- >= 0)
		writer(&i_field, 4);
	
	color_to_take(img, data, size);
	return (1);
}
