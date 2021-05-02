/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:10:01 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:10:04 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int		win_close(t_vars *var)
{
	cleaner(var->scene);
	exit(0);
}

int		win_manager(int keycode, t_vars *var)
{
	t_vars		temp;

	temp = *var;
	if (keycode == 53)
	{
		cleaner(var->scene);
		exit(0);
	}
	else if (keycode == 124)
	{
		temp = new_img_crtr(1, temp);
		mlx_put_image_to_window(var->mlx, var->win,
		var->scene->current_ca->ca_img->img, 0, 0);
	}
	else if (keycode == 123)
	{
		temp = new_img_crtr(2, temp);
		mlx_put_image_to_window(var->mlx, var->win,
		var->scene->current_ca->ca_img->img, 0, 0);
	}
	return (0);
}

void	raytracer(char *filename, char flag)
{
	t_vars		var;

	if (!(var.mlx = mlx_init()))
		mlx_error();
	if (!(var.scene = (t_scene*)malloc(sizeof(t_scene))))
		malloc_error();
	var = general_scene_prep(var, filename);
	if (!(var.win = mlx_new_window(var.mlx, var.scene->res->x,
	var.scene->res->y, "The first")))
		mlx_error();
	var = new_img_crtr(0, var);
	if (flag == 's')
	{
		if (!(scsaver(var.scene->current_ca->ca_img, var.imgdet,
		var.scene->res)))
			save_error();
		exit(0);
	}
	mlx_hook(var.win, 17, 0, win_close, &var);
	mlx_hook(var.win, 2, 1L << 0, win_manager, &var);
	mlx_put_image_to_window(var.mlx, var.win,
	var.scene->current_ca->ca_img->img, 0, 0);
	mlx_loop(var.mlx);
	return ;
}

int		main(int argc, char **argv)
{
	int			length;
	char		flag_save;

	if (argc != 2 && argc != 3)
		com_error();
	length = ft_strlen(argv[1]);
	if (ft_memcmp(".rt", argv[1] + length - 3, 4))
		com_error();
	flag_save = 'n';
	if (argv[2])
	{
		if (!(ft_memcmp("--save", argv[2], 7)))
			flag_save = 's';
		else
			com_error();
	}
	raytracer(argv[1], flag_save);
	return (0);
}
